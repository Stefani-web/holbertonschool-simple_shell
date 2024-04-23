#include "simple_shell.h"

/**
 * split_string - Function that splits a string into an array of arguments.
 * @line: the input string to be split.
 *
 * Return: an array of strings containing the arguments.
 */
char **split_string(char *line)
{
	int index = 0; /* Index for the array of arguments */
	char *tmp_line = malloc(strlen(line) + 1); /* Allocate memory for the temporary line */
	char *token; /* Pointer to store the token */

	char **args_array = malloc(sizeof(char *) * MAX_ARGS); /* Allocate memory for the array of arguments */

	if (tmp_line == NULL || args_array == NULL)
	{
		perror("Error on malloc");
		exit(EXIT_FAILURE);
	}
	strcpy(tmp_line, line);
	token = strtok(line, " \t\n");
	while (token)
	{
		args_array[index] = malloc(strlen(token) + 1); /* Allocate memory for the token */
		if (args_array[index] == NULL)
		{
			perror("Error on malloc");
			exit(EXIT_FAILURE);
		}
		strcpy(args_array[index], token); /* Copy the token to the array */
		token = strtok(NULL, " \t\n"); /* Move to the next token */
		index++; /* Increment the index */
	}
	args_array[index] = NULL; /* Set the last element of the array to NULL */
	free(tmp_line);	/* Free the temporary line */
	return (args_array); /* Return the array of arguments */
}
