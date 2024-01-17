#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include "monty.h"

/**
 * push - pushes an element to the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node = NULL;
    int arg = 0;
    char *token = NULL;

    token = strtok(NULL, " \t\n");
    if (!token)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        return (EXIT_FAILURE);
    }

    arg = atoi(token);
    if (arg == 0 && token[0] != '0')
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        return (EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return (EXIT_FAILURE);
    }

    new_node->n = arg;
    new_node->next = *stack;
    new_node->prev = NULL;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;

    return (EXIT_SUCCESS);
}
