#include "monty.h"

/**
 * op_addnode - add node to the head stack
 * @stack_head: head of the stack
 * @number: new value
 * Return: Nothing
*/
void op_addnode(stack_t **stack_head, int number)
{

	stack_t *new_node, *temp_p;

	temp_p = *stack_head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (temp_p)
		temp_p->prev = new_node;
	new_node->n = number;
	new_node->next = *stack_head;
	new_node->prev = NULL;
	*stack_head = new_node;
}
