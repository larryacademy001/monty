#include "monty.h"
/**
 * op_swap - function that adds the top
 * two elements of the stack.
 * @stack_head: stack head
 * @count: line_number
 * Return: Nothing
*/
void op_swap(stack_t **stack_head, unsigned int count)
{
	stack_t *head;
	int len = 0, temp_p;

	h = *stack_head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	head = *stack_head;
	temp_p = head->n;
	head->n = head->next->n;
	head->next->n = temp_p;
}
