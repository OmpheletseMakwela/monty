#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (current == NULL)
	{
		return;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
