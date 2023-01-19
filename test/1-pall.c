#include "monty.h"

/**
 * pall - a function that prints all the values on stack, starting from the
 *        top of the stack
 *        * USAGE `pall`
 * @stack: the address of a pointer to the stack
 * @line_number: the line number where the opcode is located
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;
	if (*stack == NULL)
		return;  /* Don't do anything */
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
