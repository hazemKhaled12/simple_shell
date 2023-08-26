#include "main.h"
#define COMMAND_SIZE 1024

/**
 * main - entry point
 *
 * Description: 'this is the description'
 * Return: Always 0.
 */

int main(void)
{
	char command_line[COMMAND_SIZE];

	while (1)
	{
		print_to_std_out("#HazemShell$ ");
		get_command(command_line, sizeof(command_line));
		exit_program(command_line);
		do_command(command_line);
	}

	return (0);
}
