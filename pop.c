#include "monty.h"
/**
 * op_pop - function that prints the top value
 * @stack_head: stack head
 * @count: the line_number
 * Return: Nothing
*/
void op_pop(stack_t **stack_head, unsigned int count)
{
	stack_t *temp_p;

	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(cis.file);
		free(cis.content);
		free_the_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	h = *stack_head;
	*stack_head = temp_p->next;
	free(temp_p);
}
