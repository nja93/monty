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
