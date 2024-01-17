#include <stdio.h>
#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *top;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    *stack = top->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(top);
}
