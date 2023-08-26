#include "main.h"

/**
 * get_command - Exucte the command using execve
 *
 * Description: 'excute the command'
 * @command: Command
 * @size: Size of the command
 *
 * Return: Always 0.
 */

void get_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print_to_std_out("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_to_std_out("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
