#include "simple_shell.h"

/**
 * free_args - Function that frees the memory allocated
 * for an array of strings.
 * @strings_array: array of strings to free.
 */
void free_args(char **strings_array)
{
	int index;

	if (strings_array == NULL)
		return;
	/* Iterate through the array of strings */
	for (index = 0; strings_array[index] != NULL; index++)
		free(strings_array[index]); /* Free the memory allocated for each string */
	/* Free the memory allocated for the array of strings itself */
	free(strings_array);
}
