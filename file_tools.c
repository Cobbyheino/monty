#include "monty.h"

/**
 * open_file - this open a file
 * @file_name: file pathname
 *
 * Return: void
 */

void open_file(char *file_name)
{
/*declareandinitialize a file pointer*/
	FILE *fd = fopen(file_name, "r");
/*check if file pointer isnull*/
	if (file_name == NULL || fd == NULL)
		err1(2, file_name);
/*call function to read then close file*/
	read_file(fd);
	fclose(fd);
}


/**
 * read_file - this reads a file
 * @fd: pointer to file descriptor
 *
 * Return: void
 */

void read_file(FILE *fd)
{
/*declares and stores line and length*/

	int x, y = 0;
	char *buffer = NULL;
	size_t len = 0;
/*loop thru each line of the file using getline*/
	for (x = 1; getline(&buffer, &len, fd) != -1; x++)
	{
		y = parse_line(buffer, x, y);
	}
	free(buffer);
}


/**
 * find_funct - find function for the opcode
 * @opcode: the opcode
 *
 * @value: arg of opcode
 * @format:  storage format.
 * @ln: line num
 *
 * Return: void
 */

void find_funct(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;
/*this is an array of structs representing opcode-func pairs*/
	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
/*ignore lines starting with #*/
	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_funct(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
/*if n omatch found show error*/
	if (flag == 1)
		err1(3, ln, opcode);
}

