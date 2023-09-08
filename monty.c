#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 100

typedef struct Stack
{
    int items[STACK_SIZE];
    int top;
} Stack;

Stack stack;

void initializeStack()
{
    stack.top = -1;
}

void push(int line_number, char *arg)
{
    if (arg)
    {
        char *numeric_arg = strtok(arg, "$");

        int value;
        if (sscanf(numeric_arg, "%d", &value) == 1)
        {
            if (stack.top >= STACK_SIZE - 1)
            {
                fprintf(stderr, "L%d: can't push, stack overflow\n", line_number);
                exit(EXIT_FAILURE);
            }
            stack.items[++stack.top] = value;
        }
        else
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
}

void pall()
{
    if (stack.top == -1)
    {
        return;
    }

    for (int i = stack.top; i >= 0; i--)
    {
        printf("%d\n", stack.items[i]);
    }
}

int main(int argc, char *argv[])
{
    initializeStack();

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char line[256];
    int line_number = 0;

    while (fgets(line, sizeof(line), file))
    {
        line_number++;

        char *newline = strchr(line, '\n');
        if (newline)
        {
            *newline = '\0';
        }

        char *opcode = strtok(line, " \t");
        if (!opcode)
        {
            continue;
        }

        if (strcmp(opcode, "push") == 0)
        {
            char *arg = strtok(NULL, " \t");
            push(line_number, arg);
        }
        else if (strcmp(opcode, "pall") == 0 || strcmp(opcode, "pall$") == 0)
        {
            pall();
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return 0;
}
