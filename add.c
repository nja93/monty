#include "monty.h"

/**
 * add - fn that adds the top 2 elements of a stack
 * @stack: ptr to the top ....
 * by Lorna
 * @line_number: position of line to be executed
 */


void add(stack_t **stack, unsigned int line_number)
{
	int get_sum; /*value will be stored in get_sum*/
	int first;
	int second;

	/*check if stack is has 2 elements*/
	if ((*stack == NULL) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = (*stack)->n;
	second = (*stack)->next->n;

	get_sum = first + second;

	pop(stack, line_number); /*top element removed*/
	(*stack)->n = get_sum;
}

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

	if ((*stack)->next == NULL || (*stack == NULL))
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
