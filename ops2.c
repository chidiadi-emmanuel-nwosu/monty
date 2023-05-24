/*
 * File: ops2.c
 * Author: Chidiadi E. Nwosu
 */
#include "monty.h"

/**
 * op_add - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *tmp = *stack;
		int res;

		res = (*stack)->n + (*stack)->next->n;
		*stack = (*stack)->next;
		(*stack)->n = res;
		(*stack)->prev = NULL;
		free(tmp);
	}
}



/**
 * op_nop - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}



/**
 * op_sub - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *tmp = *stack;
		int res;

		res = (*stack)->next->n - (*stack)->n;
		*stack = (*stack)->next;
		(*stack)->n = res;
		(*stack)->prev = NULL;
		free(tmp);
	}
}



/**
 * op_div - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *tmp = *stack;
		int res;

		res = (*stack)->next->n / (*stack)->n;
		*stack = (*stack)->next;
		(*stack)->n = res;
		(*stack)->prev = NULL;
		free(tmp);
	}
}



/**
 * op_mul - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *tmp = *stack;
		int res;

		res = (*stack)->next->n * (*stack)->n;
		*stack = (*stack)->next;
		(*stack)->n = res;
		(*stack)->prev = NULL;
		free(tmp);
	}
}
