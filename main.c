#include "monty.h"
comm_info_st cis = {NULL, NULL, NULL, 0};

/**
* main - main function for monty code interpreter
* @argc: no of arguments
* @argv: location of the monty file
* Return: If success return 0
*/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int count = 0;
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	cis.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		cis.content = content;
		count++;
		if (read_line > 0)
		{
			execute(content, &stack, count, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
