#include "monty.h"
/**
* free_mem - fn that frees mem for the stack, line
* @file: pointer to the fiel
* @stack: double ptr to the top node of the stack
* @line: ..
 */
void free_mem(FILE *file, char *line, stack_t **stack)
{
	free(line);
	fclose(file);
	stack_t *current = *stack;

	while (current != NULL)
	{
		stack_t *next = current->next;

		free(current);
		current = next;
	}
}
