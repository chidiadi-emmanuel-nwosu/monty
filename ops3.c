/*
 * File: ops3.c
 * Author: Chidiadi E. Nwosu
 */
#include "monty.h"

/**
 * op_mod - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
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

		res = (*stack)->next->n % (*stack)->n;
		*stack = (*stack)->next;
		(*stack)->n = res;
		(*stack)->prev = NULL;
		free(tmp);
	}
}



/**
 * op_pchar - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		int res = (*stack)->n;

		if (res < 0 || res > 127)
		{
			fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
			free_args(var.args);
			free_stack(var.stack);
			exit(EXIT_FAILURE);
		}
		fprintf(stdout, "%c\n", res);
	}
}



/**
 * op_pstr - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	for (; tmp && tmp->n > 0 && tmp->n <= 127; tmp = tmp->next)
		fprintf(stdout, "%c", tmp->n);
	fprintf(stdout, "\n");
	(void)line_number;
}



/**
 * op_rotl - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		return;
	}
	else
	{
		stack_t *tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		add_dnodeint_end(stack, tmp->n);
		free(tmp);
	}
	(void)line_number;
}



/**
 * op_rotr - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		return;
	}
	else
	{
		stack_t *tmp1, *tmp2;

		tmp1 = *stack;
		while (tmp1->next->next)
			tmp1 = tmp1->next;
		tmp2 = tmp1->next;
		tmp1->next = NULL;
		add_dnodeint(stack, tmp2->n);
		free(tmp2);
	}
	(void)line_number;
}
