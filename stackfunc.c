#include "monty.h"

/**
 * nop - nothing.
 * @stack: stack head.
 * @line_number: line number.
 * Return: no return
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add_to_stack - Adds node to stack.
 * @new_node: ptr to a new node.
 * @ln: Int represent line number of the opcode.
 *
 * Return: null
 */

void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * pop - Addsnode to the stack.
 * @stack: Ptr to a ptr to top node of the stack.
 * @line_number: Int representing the line num of opcode.
 *
 * Return: null
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
/*this function adss nodes to a stack*/
	if (stack == NULL || *stack == NULL)
		err2(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
/*after free temp*/
	free(temp);
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Ptr to a ptr to top node of the stack..
 * @line_number: Int representing the line num of opcode.
 *
 * Return: null
 */

void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;
/*sums up the first two elem in stack*/
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err2(8, line_number, "add");
/*stack stack*/
	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Ptr to a ptr to top node of the stack.
 * @line_number: Int representing the line num of opcode
 *
 * Return: null
 */

void div_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err2(8, line_number, "div");

	if ((*stack)->n == 0)
		err2(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

