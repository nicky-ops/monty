#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: Argument count
 * @argv: Argument vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    /* Check command line arguments */
    if (argc != 2)
    {
        /* Print usage message and exit with failure status */
        fprintf(stderr, "Usage: monty file\n");
        return EXIT_FAILURE;
    }
    
    /* Open the Monty byte code file */
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        /* Print error message and exit with failure status */
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    
    /* Initialize stack and line variables */
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    
    /* Read lines from the file */
    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        
        /* Parse the opcode and argument from the line */
        char *opcode = strtok(line, " \t\n");
        
        if (opcode != NULL)
        {
            if (strcmp(opcode, "push") == 0)
            {
                /* Extract and validate the argument */
                char *arg = strtok(NULL, " \t\n");
                if (arg != NULL)
                {
                    /* Convert the argument to an integer */
                    int value = atoi(arg);
                    /* Call the push function */
                    push(&stack, value);
                }
                else
                {
                    /* Print error message and exit with failure status */
                    fprintf(stderr, "L%u: usage: push integer\n", line_number);
                    fclose(file);
                    free(line);
                    /* Free allocated memory in the stack */
                    return EXIT_FAILURE;
                }
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                /* Call the pall function */
                pall(&stack);
            }
            else
            {
                /* Handle unknown instruction error */
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                fclose(file);
                free(line);
                /* Free allocated memory in the stack */
                return EXIT_FAILURE;
            }
        }
    }
    
    /* Close the file and free allocated memory */
    fclose(file);
    free(line);
    /* Free allocated memory in the stack */
    return EXIT_SUCCESS;
}
