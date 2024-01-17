#include <stdio.h>
#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *top;
    int sum;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    sum = top->n + top->next->n;
    top->next->n = sum;
    *stack = top->next;
    free(top);
}
