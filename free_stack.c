#include "monty.h"
/**
* free_the_stack - function to free the
* double linked list
* @stack_head: head of the stack
*/
void free_the_stack(stack_t *stack_head)
{
	stack_t *temp_p;

	temp_p = stack_head;
	while (stack_head)
	{
		temp_p = stack_head->next;
		free(stack_head);
		stack_head = temp_p;
	}
}
