#include "monty.h"

int n;

/**
 * main - entry point of the program
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	char **token_array;
	int fd, stat, i, j, linum = 0;
	instruction_t *instruct;
	void (*function)(stack_t **, unsigned int);
	stack_t *stack = NULL;
	char buf[5120], temp[64];

	if (argc != 2)
	{
		printf("TODO: print to stderr\n");
		dprintf(2, "USAGE: monty file\n"); /* TODO: print to stderr */
		exit(EXIT_FAILURE);
	}
	
	/* open file <file> in read mode */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	read(fd, buf, 5119);
	close(fd);

	i = 0, j = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] != '\n' && temp[j] == '\n')
		{
			j = 0;
			++linum;
			/* 1. fetch tokens from the current line `temp` */
			token_array = tokenize(temp);

			/* 2. check if it is an opcode */
			stat = check_opcode(token_array[0], &instruct);
			if (stat < 0)
			{
				dprintf(2, "L%d: unknown instruction %s\n",\
					linum, token_array[0]);
				exit(EXIT_FAILURE);
			}

			/* 3a. check if the second token is integer or NULL */
			if (token_array[1] == NULL \
			    || !_isdigit(token_array[1][0]))
			{
				dprintf(2, "L%d: usage: push integer", linum);
				exit(EXIT_FAILURE);
			}
			/* 3b. convert the 2nd token from string to integer */
			n = atoi(token_array[1]);

			/* 4. if it is an opcode call the appropriate function
			   (Use 2D array) */
			function = instruct->f;
			function(&stack, linum);
		}
		temp[j] = buf[i];
		i++, j++;
	}

	
	/*  */
	return (0);
}
