#include <stdio.h>
#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;
	top->next = second->next;
	if (top->next != NULL)
		top->next->prev = top;
	second->next = top;
	second->prev = NULL;
	*stack = second;
}
