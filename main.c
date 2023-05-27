#include "monty.h"
/**
 * main - fn that checks if file exist, entry point
 * @argc: number of arguments
 * @argv: Array, argument vector
 * Return: 0 if successful, else print error
 * by Lorna
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	execute_file(argv[1]);
	return (0);
}

/**
 * exe -  fn that executes opcode
 * @stack: ptr to stack in linked list
 * @line_number: position of the line being executed
 * @args: : int value passed to push fn
 * @opcode: opcode
 */
void exe(stack_t **stack, unsigned int line_number, char *opcode, char *args)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, args);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack, line_number);
	}
	else if (strcmp(opcode, "sub") == 0)
	{
		sub(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
/**
 * execute_file - fn that executes file
 * @filename: ptr to the file
 */


void execute_file(const char *filename)
{
	FILE *file;
	char *line;
	unsigned int line_number;
	char *opcode;
	char *argument;
	size_t length = 0;
	ssize_t read;
	stack_t *stack = NULL;

	file = fopen(filename, "r");
	/* Open  byte code file in read only*/
       /*else print error to stdout */
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &length, file)) != -1)
{
	/**execute the code line y line*/
	line_number++;
	opcode = strtok(line, " \t\n\r"); /*tokenize spaces, tabs etc*/

	if (opcode != NULL && opcode[0] != '#')
	{
	argument = strtok(NULL, " \t\n\r");
	exe(&stack, line_number, opcode, argument);
	}
}

	free_mem(file, line, &stack);
}
