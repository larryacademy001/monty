#include "monty.h"


/**
 * push - add node to the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
 */

void push(stack_t **stack, unsigned int line_number)
{
	int n = 0;
	char *endptr;

	if (bus.arg == NULL || bus.arg[0] == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = strtol(bus.arg, &endptr, 10);
	if (endptr == bus.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	addnode(stack, n);
}
