#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void push_node(stack_t **stack, int value)
{
	stack_t *new_node =(stack_t*)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

void push(stack_t **stack, unsigned int line_number)
{
	 char *argument = strtok(NULL, " \n");
	 int value = atoi(argument);

    if (argument == NULL) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (value == 0 && strcmp(argument, "0") != 0) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    push_node(stack, value);
}
