#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>


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
 * struct global_s - global variable
 * @n: stack input data
 * @line_number: line_number
 *
 * Description: struct holding line_number and stack
 * input data
 */
typedef struct global_s
{
        unsigned int line_number;
        int n;
	char **args;
	stack_t *stack;
	int stack_queue;
} global_t;


extern global_t var;


/**********main.c**********/
void remove_spaces(char *str);
void process_input(FILE *fd);
char **parse_args(char *cmd, const char *delim);
void free_args(char **args);
void free_stack(stack_t *stack);


/**********aux.c**********/
char *_strdup(char *str);
int _atoi(char **num);
void add_dnodeint(stack_t **stack, int n);
void add_dnodeint_end(stack_t **stack, int n);


/**********main.c**********/
void remove_spaces(char *str);
char **parse_args(char *cmd, const char *delim);


/**********instructions.c**********/
void (*instruct(char **s))(stack_t **, unsigned int);


/**********ops1.c**********/
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);



/**********ops2.c**********/
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);


/**********ops1.c**********/
void op_mod(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);
void op_rotl(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);


#endif
