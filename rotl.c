#include "monty.h"

/**
  *op_rotl- function that rotates the stack to the top
  *@stack_head: stack head
  *@count: line_number
  *Return: Nothing
 */
void op_rotl(stack_t **stack_head,  __attribute__((unused)) unsigned int count)
{
	stack_t *temp_p1 = *stack_head, *temp_p2;

	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		return;
	}
	temp_p2 = (*stack_head)->next;
	temp_p2->prev = NULL;
	while (temp_p1->next != NULL)
	{
		temp_p1 = temp_p1->next;
	}
	temp_p1->next = *stack_head;
	(*stack_head)->next = NULL;
	(*stack_head)->prev = temp_p1;
	(*stack_head) = temp_p2;
}
