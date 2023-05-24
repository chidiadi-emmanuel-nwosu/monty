/*
 * File: ops1.c
 * Author: Chidiadi E. Nwosu
 */
#include "monty.h"

/**
 * op_push - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	if (var.stack_queue == 0)
		add_dnodeint(stack, var.n);
	else
		add_dnodeint_end(stack, var.n);

	(void)line_number;
}



/**
 * op_pall - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	for (; tmp; tmp = tmp->next)
		fprintf(stdout, "%i\n", tmp->n);
	(void)line_number;
}



/**
 * op_pint - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stdout, "%i\n", (*stack)->n);
	}
}



/**
 * op_pop - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *tmp = *stack;

		*stack = (*stack)->next;
		free(tmp);
	}
}



/**
 * op_swap - pushes data into the stack or queue
 * @stack: pointer to the top of the stack
 * @line_number: instruction line number
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		free_args(var.args);
		free_stack(var.stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *tmp = *stack;

		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		tmp->prev = *stack;
		(*stack)->next = tmp;
		(*stack)->prev = NULL;
	}
}
