#include "monty.h"
stack_t *head = NULL;

/**
 * main - the entry point
 * @argc: arg count
 * @argv:  argument vector
 *
 * Return: always 0
 */

int main(int argc, char *argv[])
{
/*this checks if the no of commandline arg is not 2*/
	if (argc != 2)
	{
/*prints an error msg to standard error thnen exit*/
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
/*call the function to open the filr and execute then after u free thenode to*/
/*avoid menory lekage and alloacted menory*/
	open_file(argv[1]);
	free_nodes();
	return (0);
}

