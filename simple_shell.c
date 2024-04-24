#include "simple_shell.h"

/**
 * main - Entry point of the simple shell program
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	int command_count = 0; /* Counter for number of commands entered by user */
	char *input_line = NULL; /* Pointer to store the input command line */
	char **command_args; /* Pointer to store command and its arguments */
	size_t length_input = 0; /* Length of the input line */
	ssize_t bytes_read; /* Number of bytes read by getline() */
	int should_continue = 1; /* Flag to continue the loop */

	while (should_continue) /* Loop to run the shell program */
	{
		if (isatty(STDIN_FILENO)) /* Check if the shell is in interactive mode */
			printf("HolbitesHell$ "); /* Print the prompt */
		/* Read the input line */
		bytes_read = getline(&input_line, &length_input, stdin);

		if (bytes_read == -1) /* Check if getline() failed */
		{
			if (feof(stdin))
			{
				if (isatty(STDIN_FILENO))
					printf("\n");
				fflush(stdout);
				break;
			}
			free(input_line);
			continue;
		}
		else
		{
			/* Split the input line into command and arguments */
			command_args = split_string(input_line);
			if (command_args[0] == NULL) /* Check if the command is empty */
			{
				free_args(command_args); /* Free the command arguments */
				continue;
			}
		}
		/* Check if the user entered "exit" */
		if (strcmp(input_line, "exit") == 0)
			break;

		execute_command(command_args, ++command_count); /* Execute the command */
		free_args(command_args); /* Free the command arguments */
	}
	free(input_line); /* Free the input line */
	return (0); /* Return 0 on success */
}
