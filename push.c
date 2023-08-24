#include "monty.h"
/**
 * push - push elements into a stack
 * @value: element to be pushed into a stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */

void push(stack_t **stack, int value, unsigned int line_number)
{
	if (value)
	{
		stack_t *new_node = malloc(sizeof(stack_t));

		if (!new_node)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		new_node->n = value;
		new_node->prev = NULL;
		new_node->next = *stack;

		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
}
