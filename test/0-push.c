#include "monty.h"

/**
 * push - a function that pushes elements on stack
 *        * USAGE `push <int>`
 *        * where <int> is an integer
 * @stacks: the address of a pointer to a stack_t doubly linked list
 * @line_number: the line number where the opcode is located
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		/* TODO: Error at <line_number> */
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->n = n;
	new->prev = NULL;

	if (*stack == NULL)
	{
		*stack = new;
		return;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}
