#include "simple_shell.h"

/**
 * get_path - Function that gets the full path of a file in
 * the PATH environment variable.
 * @input_line: The name or path of the file to locate.
 *
 * Return: The full path of the file if found, otherwise NULL.
 */
char *get_path(char *input_line)
{
	char *path = getenv("PATH"); /* Get the PATH environment variable */
	char *token, *complete_path;
	char *tmp_path = strdup(path); /* Duplicate the PATH string to tokenize */

	if (input_line == NULL)
		exit(EXIT_FAILURE);
	/* Check if the file exists and is executable */
	if (access(input_line, F_OK | X_OK) == 0)
		return (input_line); /* Return the input_line if it is found */

	token = strtok(tmp_path, ":"); /* Tokenize the PATH string */
	while (token)
	{
		complete_path = malloc(strlen(token) + strlen(input_line) + 2);
		if (complete_path == NULL) /* Check if malloc failed */
		{
			free(tmp_path); /* Free the memory allocated for tmp_path */
			return (NULL); /* Return NULL if memory allocation failed */
		}
		/* Concatenate the token and input_line to get the complete path */
		sprintf(complete_path, "%s/%s", token, input_line);
		/* Check if the file exists and is executable */
		if (access(complete_path, F_OK | X_OK) == 0)
		{
			free(tmp_path);
			return (complete_path);
		}
		free(complete_path);
		token = strtok(NULL, ":"); /* Move to the next token */
	}
	return (NULL); /* Return NULL if the file is not found */
}
