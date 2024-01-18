#include "monty.h"

/**
 * op_push - function to add node to the stack
 * @stack_head: stack head
 * @count: line_number
 * Return: nothing
*/
void op_push(stack_t **stack_head, unsigned int count)
{
	int n, j = 0, flag = 0;

	if (cis.arg)
	{
		if (cis.arg[0] == '-')
			j++;
		for (; cis.arg[j] != '\0'; j++)
		{
			if (cis.arg[j] > 57 || cis.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(cis.file);
			free(cis.content);
			free_stack(*stack_head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(cis.file);
		free(cis.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE); }
	n = atoi(cis.arg);
	if (cis.op_flag == 0)
		addnode(stack_head, n);
	else
		addqueue(stack_head, n);
}
