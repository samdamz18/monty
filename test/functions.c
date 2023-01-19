#include "monty.h"

/**
 * tokenize - a function that extracts tokens from a string
 * @s: a string to be converted to tokens
 * Return: an array of strings each containing tokens
 */
char **tokenize(char *s)
{
	char **command;
	char *separator = " ";
	char *parsed;
	int i = 0;

	command = malloc(sizeof(char *) * 8);
	if (command == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	parsed = strtok(s, separator);
	while (parsed != NULL)
	{
		command[i] = parsed;
		i++;
		parsed = strtok(NULL, separator);
	}
	command[i] = NULL;

	return (command);
}

/**
 * check_opcode - checks if a string is a valid opcode
 * @str: the string to be checked
 * Return: 1 if str is a valid opcode else -1
 */
int check_opcode(char *str, instruction_t **instruct)
{
	char *arr_opcodes[] = {"push", "pall"};
	void (*opcodes_func[2])(stack_t **, unsigned int) = {&push, pall};
	int i = 0;

	if (str == NULL || *str == '\0')
		return (-1);
	while (i < 2)
	{
		if (strcmp(str, arr_opcodes[i]) == 0)
		{
			*instruct = malloc(sizeof(instruction_t));
			if (!instruct)
			{
				dprintf(2, "Error: malloc failed");
				exit(EXIT_FAILURE);
			}
			(*instruct)->opcode = arr_opcodes[i];
			(*instruct)->f = opcodes_func[i];
			return (1);
		}
	}
	return (-1);
}


/**
 * _isdigit - a function that checks for a digit (0 through 9)
 * @c: argument passed
 * Return: 1 if c is a digit and 0 if otherwise.
 */
int _isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}
