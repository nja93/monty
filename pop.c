#include "monty.h"

/**
 * pop - function that removes the top element in a stack
 * @stack: pointer to the stack in a linked list
 * by Lorna
 * @line_number: line position that is being executed
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp; /*temporary variable assigned*/

	if (*stack == NULL) /*checks if stack is empty*/
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*temp = *stack;/*assigns temp the value of the top element of stack*/
	/*stack ptr updated to point to the next stack on the list*/
	*stack = (*stack)->next;
	if (*stack != NULL) /* set ptr to NULL if there is a new top element*/
	(*stack)->prev = NULL;

	free(temp);
}
