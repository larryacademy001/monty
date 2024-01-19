#include "monty.h"

/**
* op_execute - function to execute the opcode
* @file: poiner to monty file
* @content: line content
* @stack_head: head linked list - stack_head
* @count: line_count
* Return: Nothing
*/
int op_execute(char *content, stack_t **stack_head,
	unsigned int count, FILE *file)
{
	instruction_t opst[] = {{"push", op_push}, {"pall", op_pall},
	{"pint", op_pint},  {"pop", op_pop},  {"swap", op_swap},
	{"add", op_add}, {"nop", op_nop}, {NULL, NULL}};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	cis.argument = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack_head, count);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		free_the_stack(*stack_head);
		exit(EXIT_FAILURE); }
	return (1);
}
