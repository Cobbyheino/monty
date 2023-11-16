#include "monty.h"

/**
 * print_stack - Adds a node to the stack.
 * @stack: Ptr to a ptr pointing to top node of stack.
 * @line_number: num line of  the opcode.
 *
 * Return:null
 */

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
/*this function adds a node*/
	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Ptr to a ptr pointing to top node of stack..
 * @line_number: Int represent the line num of the opcode.
 *
 * Return: null
 */

void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		err2(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Ptr to a ptr pointing to top node of stack..
 * @line_number: Int represent the line num of the opcode.
 *
 * Return: null
 */

void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
/*this function swaps the top elements of stack*/
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err2(8, line_number, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}


/**
 * sub_nodes - sums the top two elements of the stack.
 * @stack: Ptr to a ptr pointing to top node of stack.
 * @line_number: Int represent the line num of the opcode.
 *
 * Return: null
 */

void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;
/*this function adds the twoelements of the slack*/
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		err2(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

