#include "monty.h"

/**
 * main - Open a file to read
 * @argc: Program name
 * @argv: Filename is first argument
 * Return: 1 is success
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	read_bytecode_file(file);
	fclose(file);
	return (EXIT_SUCCESS);
}
