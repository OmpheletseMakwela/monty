#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 1;
    stack_t *stack = NULL;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while ((read = getline(&line, &len, file)) != -1) {
        char *token = strtok(line, " \n");
        if (token != NULL) {
            if (strcmp(token, "push") == 0) {
                char *argument = strtok(NULL, " \n");
                 int value = atoi(argument);
                if (argument == NULL) {
                    fprintf(stderr, "L%u: usage: push integer\n", line_number);
                    fclose(file);
                    free(line);
                    return EXIT_FAILURE;
               }
                push_node(&stack, value);
            } else if (strcmp(token, "pall") == 0) {
                pall(&stack, line_number);
            }else if (strcmp(token, "pint") == 0) {
		    pint(&stack, line_number);
            }else if (strcmp(token, "pop") == 0){
                    pop(&stack, line_number);
            }else if (strcmp(token, "swap") == 0){
		    swap(&stack, line_number);
	    }else if (strcmp(token, "add") == 0){
                    add(&stack, line_number);
            }else if (strcmp(token, "nop") == 0){
                    nop(&stack, line_number);
	    }


            else {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
                fclose(file);
                free(line);
                return EXIT_FAILURE;
            }
        }
        line_number++;
    }

    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}
