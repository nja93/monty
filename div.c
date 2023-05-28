#include "monty.h"
/**
 * quotient -fn that subtracts the top element from the next
 * @stack: ptr to the top node
 * @line_number: position of line
 */
void quotient(stack_t **stack, unsigned int line_number)
{
	int get_div; /*value will be stored in get_sub*/
	int top;
	int bottom;
	/*check if stack is has 2 elements*/

	if ((*stack == NULL) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = (*stack)->n;
	bottom = (*stack)->next->n;

	get_div = bottom / top;

	/*remove the top element using pop()*/
	pop(stack, line_number);
	(*stack)->n = get_div; /*reassign the value of top element*/


	if (get_div == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
}
