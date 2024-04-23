#include "simple_shell.h"

/**
 * split_string - Function that splits a string into an array of arguments.
 * @line: the input string to be split.
 *
 * Return: an array of strings containing the arguments.
 */
char **split_string(char *line)
{
	int index = 0;
	char *tmp_line = malloc(strlen(line) + 1);
	char *token;
	char **args_array = malloc(sizeof(char *) * MAX_ARGS);

	if (tmp_line == NULL || args_array == NULL)
	{
		perror("Error on malloc");
		exit(EXIT_FAILURE);
	}
	strcpy(tmp_line, line);
	token = strtok(line, " \t\n");
	while (token)
	{
		args_array[index] = malloc(strlen(token) + 1);
		if (args_array[index] == NULL)
			perror("Error on malloc"), exit(EXIT_FAILURE);

		strcpy(args_array[index], token);
		token = strtok(NULL, " \t\n");
		index++;
	}
	args_array[index] = NULL;
	free(tmp_line);
	return (args_array);
}
