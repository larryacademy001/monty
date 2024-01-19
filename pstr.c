#include "monty.h"

/**
 * op_pstr - function that prints the string starting
 * at the top of the stack, followed by a new
 * @stack_head: stack head
 * @count: line_number
 * Return: Nothing
*/
void op_pstr(stack_t **stack_head, unsigned int count)
{
	stack_t *head;
	(void)count;

	head = *stack_head;
	while (head)
	{
		if (head->n > 127 || head->n <= 0)
		{
			break;
		}
		printf("%c", head->n);
		head = head->next;
	}
	printf("\n");
}
