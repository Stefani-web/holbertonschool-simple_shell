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
	if (input_line == NULL)
		exit(EXIT_FAILURE);
	/* If input_line not contains slashes, search for the file in PATH */
	if (strchr(input_line, '/') == NULL)
	{
		char *path = _getenv("PATH"); /* Get the PATH environment variable */
		char *token, *file_path;
		char *tmp_path = strdup(path); /* Duplicate the PATH string to tokenize */

		if (tmp_path == NULL)
		{
			perror("Error on malloc");
			exit(EXIT_FAILURE);
		}
		token = strtok(tmp_path, ":"); /* Tokenize the PATH string */
		while (token)
		{
			file_path = malloc(strlen(token) + strlen(input_line) + 2);
			if (file_path == NULL) /* Check if memory allocation for file_path failed */
			{
				free(tmp_path); /* Free the memory allocated for tmp_path */
				return (NULL); /* Return NULL if memory allocation failed */
			}
			strcpy(file_path, token); /* Copy the token to file_path */
			strcat(file_path, "/"); /* Concatenate a slash to the file_path */
			strcat(file_path, input_line); /* Concat the input_line to the file_path */

			if (access(file_path, F_OK) != -1)
			{
				free(tmp_path);
				return (file_path);
			}
			free(file_path);
			token = strtok(NULL, ":"); /* Move to the next token */
		}
		free(tmp_path);
		return (NULL); /* Return NULL if the file is not found */
	}
	return (input_line); /* If input contains /, it is already a full path */
}
