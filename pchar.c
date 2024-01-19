#include "monty.h"

/**
 * op_pchar - function that prints the char at the top of the stack,
 * followed by a new line
 * @stack_head: stack head
 * @count: line_number
 * Return: Nothing
*/
void op_pchar(stack_t **stack_head, unsigned int count)
{
	stack_t *head;

	head = *stack_head;
	if (!head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(cis.file);
		free(cis.content);
		free_the_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	if (head->n > 127 || head->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(cis.file);
		free(cis.content);
		free_the_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", head->n);
}
