#include "monty.h"

/**
 * rotl - Rotates the 1st node of the stack to down.
 * @stack: Ptr to a ptr pointing to top node of stack.
 * @ln: Int represent the line num of the opcode.
 *
 * Return: null
 */

void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;
/*this rotates the 1st tothe last*/
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
/*rotaes from 1st tolast*/
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Ptr to a ptr pointing to top node of stack.
 * @ln: Int represent the line num of the opcode.
 *
 * Return: null
 */

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;
/* this rotates the last tothe first node*/
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
/*rotates it from last to 1st*/
	(*stack)->prev = temp;
	(*stack) = temp;
}

