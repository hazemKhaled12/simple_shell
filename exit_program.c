#include "main.h"

void exit_program(const char *command)
{
  if (strcmp(command, "exit") == 0)
  {
    exit(0);
  }
}