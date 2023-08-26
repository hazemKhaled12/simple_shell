#include "main.h"

/**
 * exit_program - Exit terminal
 *
 * Description: 'Exit terminal'
 * @command: Command
 * Return: Return void.
 */

void exit_program(const char *command)
{
  if (strcmp(command, "exit") == 0)
  {
    exit(0);
  }
}