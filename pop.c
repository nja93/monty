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
	temp = *stack;/*assigns temp the value of the top element of stack*/
	/*stack ptr updated to point to the next stack on the list*/
	*stack = (*stack)->next;
	if (*stack != NULL) /* set ptr to NULL if there is a new top element*/
	(*stack)->prev = NULL;

	free(temp);
}

/**
 * push - fn that adds elements to the stack
 * @stack: ptr to the linked list top node
 * @line_number: line being executed
 * @argument: int value of the node being added
 */
void push(stack_t **stack, unsigned int line_number, char *argument)
{
	/*initialize pointer to a node*/
	stack_t *newnode;
	int digit;

	/*check if value is a valid int, and if it exists*/
	if (argument == NULL || !is_integer(argument))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	digit = atoi(argument);
	newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*create a new node*/
	newnode->n = digit;
	/*assign prev to NULL*/
	newnode->next = NULL;
	newnode->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
	}
	newnode->next = *stack;
	*stack = newnode;
}

/**
 * swap - fn that swaps the top e elements of the stack
 * @stack: pter to the top
 * @line_number: position of line being executed
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next;
	stack_t *top;

	/*check if stack is empty else return error to stdout*/
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*pointer assigned to the top element*/
	top = *stack;
	/*assign value of the next element in stack*/
	next = (*stack)->next;
	/*updates prev pointer to the top of the stack*/
	top->prev = next;
	/*updates next ptr to point to element that comes after next*/
	top->next = next->next;
	/*set prev ptr of next elemnt to NULL*/
	next->prev = NULL;
	/*updates the next ptr back to top*/
	next->next = top;


	/*conditional statement to check if NULL else prev ptr back to top*/
	if (top->next != NULL)
		top->next->prev = top;
	/*stack ptr updated to point to nxt mking it the new top*/
	*stack = next;
}
/**
*pall - fn that prints all elements in a stakc
*@stack: ptr to a stack in a linked list
*/
void pall(stack_t **stack)
{
	/*declare pointer varable, current*/
	stack_t *current = *stack;

	/*loop continues as long as current pointer is not NULL*/

	while (current != NULL)
	{
		printf("%d\n", current->n);
	/*prints value  pointed to by current*/
		current = current->next;
	}
}
/**
 * pint - fn that prints value at the top of stack
 * @stack: ptr to the linked list of stack
 * @line_number: position of line being executed
 */

void pint(stack_t **stack, unsigned int line_number)
{
	/*check if stack is empty*/
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*if stack is not empty, print n of the top element*/
	printf("%d\n", (*stack)->n);
}



























