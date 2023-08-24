#include "monty.h"
/**
 * pint - print the value at the top of the stack
 * @stack: stack
 * @line_number: counter
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
