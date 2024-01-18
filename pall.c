#include "monty.h"
/**
 * op_pall - function to prints the stack
 * @head: stack head
 * @count: variable not used
 * Return: nothing
*/
void op_pall(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
