#include "monty.h"

/**
 * parse_line - tokenizes lines to call function
 * @buffer: line in file
 * @line_number: line number
 *
 * @format: storage format
 *
 * Return: Returns 0
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *val;
	const char *delim = "\n ";
/*checks if buffer is NULL IF NOT TOKENISES BUFFER*/

	if (buffer == NULL)
		err1(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);
/*check if the opcode is stack or queue*/
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_funct(opcode, val, line_number, format);
	return (format);
}

/**
 * call_funct - Calls the function.
 * @func: Ptr to the function called.
 * @op: str representing the opcode.
 * @val: str representing a numeric value.
 *
 * @ln: line numeber for the instruction.
 * @format: Format specifier.
 *
 */
void call_funct(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int x;

	flag = 1;
/*check if the opcode is push to handle special cases*/
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err1(5, ln);
		for (x = 0; val[x] != '\0'; x++)
		{
			if (isdigit(val[x]) == 0)
				err1(5, ln);
		}
/*create a new node with its parsed value*/
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}

