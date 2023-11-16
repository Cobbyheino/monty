#include "monty.h"

/**
 * str_err - error code prints error msg.
 * @error_code: The error codes to print:
 *
 * (10) ~> The number not in ASCII bounds.
 * (11) ~> empty.
 */

void str_err(int error_code, ...)
{
	int i;
	va_list ag;
/*prints out errors with strings features using switch case*/
/*error msgs were provided*/
	va_start(ag, error_code);
	i = va_arg(ag, int);

	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", i);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", i);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}


/**
 * err1 - error code prints error msg.
 * @error_code: The error codes to print:
 *
 * (1) => no file from user.
 * (2) => file cannot be opened or read.
 * (3) => invalid instruction.
 * (4) => failure to malloc more memory.
 * (5) => when "push" is not an int.
 * (6) => stack empty for pint.
 * (7) => stack it for pop.
 * (8) => stack short for operation.
 */

void err1(int error_code, ...)
{
	int x;
	va_list ag;
	char *op;
/*prints out more errors msgs relating to files features using switch case*/
/*error msgs were provided*/
	va_start(ag, error_code);

	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			x = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", x, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * err2 - error code prints error msg.
 * @error_code: The error codes to print:
 *
 * (6) => When stack is empty for pint.
 * (7) => When stack is empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Div by zero.
 */

void err2(int error_code, ...)
{
	int x;
	va_list ag;
	char *op;

	va_start(ag, error_code);
/*prints out errors msgs relating to stacks using switch case*/
/*error msgs were provided*/

	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			x = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", x, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

