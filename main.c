#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stack_t **stack = NULL;
unsigned int line_number = 0;

int main(int argc, char **argv)
{
    char *line = NULL;
    size_t len = 0;
    char *read;
    char *token = NULL;
    char *opcode = NULL;
     FILE *file = fopen(argv[1], "r");

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    while ((read = fgets(line, len, file)) != NULL)

    {
        line_number++;
        token = strtok(line, " \t\n");
        if (!token)
            continue;

        opcode = token;
        if (strcmp(opcode, "push") == 0)
            push(stack, line_number);
        else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
        else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
        else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
        else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
        else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
        else if (strcmp(opcode, "nop") == 0)
		nop();
        else
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    }

    free(line);
    fclose(file);

    return (EXIT_SUCCESS);
}
