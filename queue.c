#include "monty.h"
/**
 * op_queue - function to prints the top value FIFO
 * @stack_head: stack head
 * @count: line_number
 * Return: Nothing
*/
void op_queue(stack_t **stack_head, unsigned int count)
{
	(void)stack_head;
	(void)count;
	cis.op_flag = 1;
}

/**
 * op_addqueue - function to add node to the tail stack
 * @number: new_value
 * @head: head of the stack
 * Return: no return
*/
void op_addqueue(stack_t **stack_head, int number)
{
	stack_t *new_node, *temp_p;

	temp_p = *stack_head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = number;
	new_node->next = NULL;
	if (temp_p)
	{
		while (temp_p->next)
			temp_p = temp_p->next;
	}
	if (!temp_p)
	{
		*stack_head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp_p->next = new_node;
		new_node->prev = temp_p;
	}
}
