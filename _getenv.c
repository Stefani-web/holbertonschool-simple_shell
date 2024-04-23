#include "simple_shell.h"

/**
 * _getenv - Function that gets the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *name)
{
	char **current_env_var;
	size_t name_length = strlen(name);

	/* Check if the name and environ are not NULL */
	if (name == NULL || environ == NULL)
		return (NULL);

	/* Iterate through the environment variables */
	for (current_env_var = environ; *current_env_var != NULL; current_env_var++)
	{
		/* Check if the name matches the current environment variable */
		if (strncmp(*current_env_var, name, name_length) == 0 &&
			(*current_env_var)[name_length] == '=')
		/* Return the value of the env variable */
			return (*current_env_var + name_length + 1);
	}
	return (NULL); /* Return NULL if the env variable is not found */
}
