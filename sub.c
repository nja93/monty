#include "monty.h"
/**
 * sub -fn that subtracts the top element from the next
 * @stack: ptr to the top node
 * @line_number: position of line
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int get_sub; /*value will be stored in get_sub*/
	int top;
	int bottom;
	/*check if stack is has 2 elements*/

	if ((*stack == NULL) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = (*stack)->n;
	bottom = (*stack)->next->n;

	get_sub = bottom - top;

	/*remove the top element using pop()*/
	pop(stack, line_number);
	(*stack)->n = get_sub; /*reassign the value of top element*/
}
