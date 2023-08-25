#include "main.h"

/**
 * print_to_std_out - print text to std output
 *
 * Description: 'print text to std output'
 * @text: text to print
 *
 * Return: Always 0.
 */

void print_to_std_out(const char *text)
{
	write(STDIN_FILENO, text, strlen(text));
}
