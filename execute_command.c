#include "simple_shell.h"

/**
 * execute_command - Function that executes a command with given arguments.
 * @command_args: Array containing the command and its arguments.
 * @command_number: Number of the command typed by the user.
 */
void execute_command(char **command_args, int command_count)
{
	/* Process ID for the child process */
	pid_t pid;
	/* Path of the command to be executed */
	char *command_path;

	/* Fork a new process */
	pid = fork();
	/* Check if fork failed */
	if (pid < 0)
	{
		perror("Error on fork");
		exit(EXIT_FAILURE);
	}
	/* Child process */
	else if (pid == 0)
	{
		/* Get the path of the command to be executed */
		command_path = get_path(command_args[0]);
		/* Check if command not found */
		if (command_path == NULL)
		{
			/* Print error message */
			fprintf(stderr, "./shell: %d: %s: not found\n",
					command_count, command_args[0]);
			/* Free the memory allocated and exit */
			free_args(command_args);
			exit(EXIT_FAILURE);
		}
		if (execve(command_path, command_args, NULL) == -1)
		{
			/* Print error message and exit if execve fails */
			perror("Error on execve");
			free_args(command_args);
			exit(EXIT_FAILURE);
		}
	}
	/* Parent process */
	else
		wait(0); /* Wait for the child process to finish */
}
