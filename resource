#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct stack_t
{
    int n;
    struct stack_t *next;
} stack_t;

stack_t *addnode(stack_t **head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    new_node->n = n;
    new_node->next = *head;
    *head = new_node;
    return (new_node);
}

void free_stack(stack_t *head)
{
    stack_t *current = head;
    stack_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

void addqueue(stack_t **head, int n)
{
    if (*head == NULL)
    {
        addnode(head, n);
    }
    else
    {
        stack_t *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        addnode(&(temp->next), n);
    }
}

void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0, flag = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            j++;
        for (; bus.arg[j] != '\0'; j++)
        {
            if (bus.arg[j] > 57 || bus.arg[j] < 48)
                flag = 1; }
        if (flag == 1)
        { fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE); }}
    else
    { fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE); }
    n = atoi(bus.arg);
    if (bus.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}
