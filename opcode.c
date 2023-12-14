#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void opcode_process(stack_t **stack, char *opcode, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};
	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "Unknown opcode: %s\n", opcode);
	exit(EXIT_FAILURE);
}

