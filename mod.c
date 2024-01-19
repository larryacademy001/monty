#include "monty.h"

/**
 * op_mod - fuctions that computes the rest of the
 * division of the second top element of the stack
 * by the top element of the stack
 * @stack_head: stack head
 * @count: line_number
 * Return: Nothing
*/
void op_mod(stack_t **stack_head, unsigned int count)
{
	stack_t *head;
	int no_of_elements = 0, temp_p;

	head = *stack_head;
	while (head)
	{
		head = head->next;
		no_of_elements++;
	}
	if (no_of_elements < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(cis.file);
		free(cis.content);
		free_the_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	head = *stack_head;
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(cis.file);
		free(cis.content);
		free_the_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	temp_p = head->next->n % head->n;
	head->next->n = temp_p;
	*stack_head = head->next;
	free(head);
}
