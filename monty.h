#ifndef MONTY_H
#define MONTY_H
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct comm_info - variables - arguments, file, line content
 * @argument: value
 * @file: Pointer to the monty file
 * @content: line content
 * @op_flag: flag to change between stack and queue
 * Description: global variables for keeping values throughout the program
 */
typedef struct comm_info
{
	char *argument;
	FILE *file;
	char *content;
	int op_flag;
}  comm_info_st;
extern comm_info_st cis;

/* Task Functions */
void op_push(stack_t **stack_head, unsigned int count);
void op_pall(stack_t **stack_head, unsigned int count);
void op_pint(stack_t **stack_head, unsigned int count);
void op_pop(stack_t **stack_head, unsigned int count);
void op_swap(stack_t **stack_head, unsigned int count);
void op_add(stack_t **stack_head, unsigned int count);
void op_nop(stack_t **stack_head, unsigned int count);
void op_sub(stack_t **stack_head, unsigned int count);
void op_div(stack_t **stack_head, unsigned int count);
void op_mul(stack_t **stack_head, unsigned int count);
void op_mod(stack_t **stack_head, unsigned int count);
void op_mod(stack_t **stack_head, unsigned int count);
void op_pchar(stack_t **stack_head, unsigned int count);
void op_pstr(stack_t **stack_head, unsigned int count);
void op_rotl(stack_t **stack_head, unsigned int count);
void op_rotr(stack_t **stack_head, __attribute__((unused)) unsigned int count);
void op_queue(stack_t **stack_head, unsigned int count);
void op_stack(stack_t **stack_head, unsigned int count);

/* Monty Functions */
int op_execute(char *content, stack_t **stack_head, unsigned int count, FILE *file);
void free_the_stack(stack_t *stack_head);
void op_addnode(stack_t **stack_head, int number);
void op_addqueue(stack_t **stack_head, int number);
#endif
>>>>>>> refs/remotes/origin/main
