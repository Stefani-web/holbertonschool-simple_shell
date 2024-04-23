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
	char *path = _getenv("PATH"); /* Get the PATH environment variable */
	char *token, *complete_path;
	char *tmp_path = strdup(path); /* Duplicate the PATH string to tokenize */

	if (input_line == NULL)
		exit(EXIT_FAILURE);

	token = strtok(tmp_path, ":"); /* Tokenize the PATH string */
	while (token)
	{
		complete_path = malloc(strlen(token) + strlen(input_line) + 2);
		if (complete_path == NULL) /* Check if memory allocation for file_path failed */
		{
			perror("Malloc failed");
			free(tmp_path); /* Free the memory allocated for tmp_path */
			return (NULL); /* Return NULL if memory allocation failed */
		}
		strcpy(complete_path, token); /* Copy the token to file_path */
		strcat(complete_path, "/"); /* Concatenate a slash to the file_path */
		strcat(complete_path, input_line); /* Concat the input_line to the file_path */

		if (access(complete_path, F_OK) != -1)
		{
			free(tmp_path);
			return (complete_path);
		}
		free(complete_path);
		token = strtok(NULL, ":"); /* Move to the next token */
	}
	return (NULL); /* Return NULL if the file is not found */
}
