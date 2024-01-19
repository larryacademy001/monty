#include "monty.h"

/**
  * op_sub - function to subtracts the top element
  * of the stack from the second top element
  * of the stack.
  * @stack_head: stack head
  * @count: line_number
  * Return: Nothing
 */
void op_sub(stack_t **stack_head, unsigned int count)
{
	stack_t *temp_p;
	int sub_result, no_of_elements;

	temp_p = *stack_head;
	for (no_of_elements = 0; temp_p != NULL; no_of_elements++)
		temp_p = temp_p->next;
	if (no_of_elements < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(cis.file);
		free(cis.content);
		free_the_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	temp_p = *stack_head;
	sub_result = temp_p->next->n - temp_p->n;
	temp_p->next->n = sub_result;
	*stack_head = temp_p->next;
	free(temp_p);
}
