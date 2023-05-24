#include "monty.h"

/**
 * instruct - selects the the correct function to perform
 *               the operation asked by the user.
 * @s: operator passed as argument to the program
 *
 * Return: the appropraite function or NULL if the operation
 *         does not exist.
 */
void (*instruct(char **s))(stack_t **, unsigned int)
{
	int i;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{NULL, NULL}
	};

	if (!strcmp(s[0], "push"))
		var.n = _atoi(s);

	for (i = 0; ops[i].opcode; i++)
		if (!strcmp(ops[i].opcode, s[0]))
			return (ops[i].f);

	return (NULL);
}
