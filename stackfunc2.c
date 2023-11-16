#include "monty.h"

/**
 * mul_nodes - sums top two elements of the stack.
 * @stack: Ptr to a ptr to top node of the stack.
 * @line_number: Int representing the line num of opcode.
 *
 * Return: null
 */

void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;
/*this sums the top two elements of the stack*/
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err2(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - sums top two elements of the stack.
 * @stack: Ptr to a ptr to top node of the stack.
 * @line_number: Int representing the line num of opcode.
 *
 * Return: null
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		err2(8, line_number, "mod");

	if ((*stack)->n == 0)
		err2(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * add_to_queue - sums a node to queue.
 * @new_node: ptr to the new node.
 * @ln: number line of the opcode.
 *
 * Return:null
 */

void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;

}

