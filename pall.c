#include "monty.h"
/**
 * pall - prints the stack
 * @stack: stack head
 * @line_number: not used
*/

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    if (stack == NULL || *stack == NULL)
    {
        printf("L%u: can't pall, stack is empty\n", line_number);
        return;
    }

    current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
