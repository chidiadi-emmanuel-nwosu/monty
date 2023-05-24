/*
 * File: main.c
 * Author: Chidiadi E. Nwosu
 */

#include "monty.h"

/**
 * free_args - frees a 2 dimensional allocated memories
 * @args: args input
 */
void free_args(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}



/**
 * free_stack - frees the stack.
 * @stack: pointer to the head node of the stack
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp = NULL;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
