#include "monty.h"

/**
  * op_rotr- rotates the stack to the bottom
  * @stack_head: stack head
  * @count: line_number
  * Return: Nothing
 */
void op_rotr(stack_t **stack_head, __attribute__((unused)) unsigned int count)
{
	stack_t *new_head;

	new_head = *stack_head;
	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		return;
	}
	while (new_head->next)
	{
		new_head = new_head->next;
	}
	new_head->next = *stack_head;
	new_head->prev->next = NULL;
	new_head->prev = NULL;
	(*stack_head)->prev = new_head;
	(*stack_head) = new_head;
}
