#include "simple_shell.h"

/**
 * main - Entry point of the simple shell program
 * @argc: number of arguments passed to the program
 * @argv: array of pointers to the arguments passed to the program
 * Return: Always 0 (success)
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	int command_count = 0; /* Counter for number of commands entered by user */
	char *input_line = NULL; /* Pointer to store the input command line */
	char **command_args = NULL; /* Pointer to store command and its arguments */
	size_t length = 0; /* Length of the input line */
	ssize_t bytes_read; /* Number of bytes read by getline() */

	while (1) /* Infinite loop to accept and execute commands until "exit" */
	{
		if (isatty(STDIN_FILENO)) /* Check if the shell is in interactive mode */
			printf("HolbitesHell$ "); /* Print the prompt */
		command_count++; /* Increment the command count */
		bytes_read = getline(&input_line, &length, stdin); /* Read the input line */
		if (bytes_read == -1) /* Check if getline() failed */
		{
			if (feof(stdin)) /* Check if EOF was reached */
			{
				if (isatty(STDIN_FILENO)) /* Check if the shell is in interactive mode */
					printf("\n");
				fflush(stdout);
				break;
			}
			perror(argv[0]);
			free(input_line);
			continue;
		}
		input_line[bytes_read - 1] = '\0'; /* Remove \n from end of input line */
		if (strcmp(input_line, "exit") == 0) /* Check if the user entered "exit" */
			break;
		/* Split the input line into command and arguments */
		command_args = split_string(input_line);
		if (command_args[0] == NULL) /* Check if the command is empty */
		{
			free_args(command_args), free(input_line); /* Free command args and input */
			input_line = NULL; /* Reset input_line to NULL */
			continue;
		}
		execute_command(command_args, command_count); /* Execute the command */
		free_args(command_args); /* Free the command arguments */
	}
	free(input_line); /* Free the input line */
	return (0); /* Return 0 on success */
}
