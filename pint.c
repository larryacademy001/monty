#include "monty.h"
/**
 * op_pint - function to prints the top of the stack
 * @stack_head: stack head
 * @count: line_number
 * Return: Nothing
*/
void op_pint(stack_t **stack_head, unsigned int count)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(cis.file);
		free(cis.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}
