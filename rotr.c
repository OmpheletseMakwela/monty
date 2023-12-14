#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void rotate(stack_t **stack, unsigned int line_number)
{
	stack_t *t = *stack;
	(void)line_number;

	if (!(*stack) || !((*stack)->next))
		return;
	for (; t->next; t = t->next)
		;
	t->prev->next = NULL;
	t->prev = NULL;
	t->next = *stack;
	(*stack)->prev = t;
	*stack = t;
}
