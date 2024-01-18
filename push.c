#include "monty.h"

/**
 * op_push - function to add node to the stack
 * @head: stack head
 * @count: line_number
 * Return: nothing
*/
void op_push(stack_t **head, unsigned int count)
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
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(cis.file);
		free(cis.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(cis.arg);
	if (cis.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
