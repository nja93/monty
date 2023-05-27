#include "monty.h"
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
