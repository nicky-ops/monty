#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

stack_t *stack = NULL; /* Global stack variable */

/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: Argument count
 * @argv: Array of argument strings
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
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

        char line[1024];
        unsigned int line_number = 0;
        while (fgets(line, sizeof(line), file))
        {
                line_number++;
                char opcode[100];
                int argument = 0;
                int parsed = sscanf(line, "%s %d", opcode, &argument);

                if (parsed < 1)
                {
                        continue;
                }

                if (strcmp(opcode, "push") == 0)
                {
                        if (parsed < 2 || !isdigit(argument))
                        {
                                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                                fclose(file);
                                return (EXIT_FAILURE);
                        }
                        push(&stack, line_number, argument);
                }
                else if (strcmp(opcode, "pall") == 0)
                {
                        pall(&stack, line_number);
                }
                else
                {
                        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                        fclose(file);
                        return (EXIT_FAILURE);
                }
        }

        fclose(file);
        return (EXIT_SUCCESS);
}
