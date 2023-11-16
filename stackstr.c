#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @stack: Ptr to a ptr pointing to top node of stack
 * @line_number: Int represent the line num of the opcode.
 *
 * Return: null
 */

void print_char(stack_t **stack, unsigned int line_number)
{
	int x;
/* this function prints the ascii value*/
	if (stack == NULL || *stack == NULL)
		str_err(11, line_number);

	x = (*stack)->n;
	if (x < 0 || x > 127)
		str_err(10, line_number);
/*prints ascii value*/
	printf("%c\n", x);
}

/**
 * print_str - Prints a string.
 * @stack: Ptr to a ptr pointing to top node of stack
 * @ln: Int represent the line num of the opcode.
 *
 * Return:null
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int x;
	stack_t *temp;
/*this function str prints a string*/
	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		x = temp->n;
		if (x <= 0 || x > 127)
			break;
		printf("%c", x);
		temp = temp->next;
	}
/*prints a str*/
	printf("\n");
}

