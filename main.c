/*
 * File: main.c
 * Author: Chidiadi E. Nwosu
 */

#include "monty.h"

global_t var = {0, 0, NULL, NULL, 0};

/**
 * main - entry point
 * @ac: number of commandline arguments
 * @av: array of commandline arguments
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	FILE *fd;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	process_input(fd);
	free_stack(var.stack);
	fclose(fd);
	return (0);
}



/**
 * remove_spaces - remove whitespaces in a string
 * @str: string input
 */
void remove_spaces(char *str)
{
	int i, j, check_space = 0;

	for (i = 0; str[i] != '\0' && isspace(str[i]); i++)
		;

	for (j = 0; str[i]; i++)
	{
		if (isspace(str[i]))
		{
			if (check_space == 0)
			{
				str[j++] = ' ';
				check_space = 1;
			}
		}
		else
		{
			str[j++] = str[i];
			check_space = 0;
		}
	}

	if (j > 0 && str[j - 1] == ' ')
		str[j - 1] = '\0';
	else
		str[j] = '\0';
}



/**
 * process_input - processes input
 * @fd: input stream
 */
void process_input(FILE *fd)
{
	char buffer[256];
	size_t count = 256;

	while (fgets(buffer, count, fd))
	{
		var.line_number++;
		remove_spaces(buffer);
		if (buffer[0] == '\0' || buffer[0] == '#')
			continue;

		if (!strncmp("stack", buffer, 5) && (buffer[5] == ' ' || buffer[5] == '\0'))
		{
			var.stack_queue = 0;
			continue;
		}
		else if (!strncmp("queue", buffer, 5) &&
				(buffer[5] == ' ' || buffer[5] == '\0'))
		{
			var.stack_queue = 1;
			continue;
		}
		var.args = parse_args(buffer, " \t\r\n");
		if (!instruct(var.args))
		{
			fprintf(stderr, "L%i: unknown instruction %s\n",
					var.line_number, var.args[0]);
			free_args(var.args);
			fclose(fd);
			exit(EXIT_FAILURE);
		}

		instruct(var.args)(&var.stack, var.line_number);
		free_args(var.args);
	}

}


/**
 * parse_args - split input into array of strings
 * @cmd: input
 * @delim: refrence delimeter
 *
 * Return: array of string on success, NULL on failure
 */
char **parse_args(char *cmd, const char *delim)
{
	char **args, *tok, *tmp;
	int i = 0;

	if (!cmd || !delim)
		return (NULL);

	tmp = _strdup(cmd);

	tok = strtok(tmp, delim);
	for (; tok; tok = strtok(NULL, delim))
		i++;
	free(tmp);

	args = malloc(sizeof(char *) * (i + 1));
	if (!args)
		return (NULL);

	tok = strtok(cmd, delim);
	for (i = 0; tok; tok = strtok(NULL, delim))
		args[i++] = _strdup(tok);

	args[i] = NULL;

	return (args);
}
