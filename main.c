#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * exec_opcodes - A function that executes opcodes
 * @file: Pointer to a file
 * @stack: Double pointer to a stack_t structure
 * Return- nothing
 */
void exec_opcodes(FILE *file, stack_t **stack) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 1;

    while ((read = getline(&line, &len, file)) != -1) {
        char *token = strtok(line, " \n");

        while (token != NULL) {
            opcode_process(stack, token, line_number);
            token = strtok(NULL, " \n");
        }
        line_number++;
    }
    free(line);
    fclose(file);
}


/**
 * main - main function
 * @argc: first argument of a function
 * @argv: Pointer to character
 * Return- EXIT SUCCESS
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	exec_opcodes(file, &stack);
	fclose(file);
	return (EXIT_SUCCESS);
}

