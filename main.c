#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


/**
 * main - entry point
 * @argc: arguments count
 * @argv: argument vector
 * Return: 0 on success
 */


int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	content = (char *)malloc(100 * sizeof(char));
	while (fgets(content, 100, file) != NULL)
	{
		line_number++;
		instruction(content, &stack, line_number, file);
	}
	free(content);
	free_stack(stack);
	fclose(file);
	return (0);
}

