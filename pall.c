#include "monty.h"
/**
 * pall - displays the stack
 * @stack: current stack
 * @counter: line counter
 * Return: void
 */

void pall(stack_t **stack, unsigned int counter)
{
	stack_t *current = *stack;

	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
