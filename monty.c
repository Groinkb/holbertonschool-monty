#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

typedef struct Stack {
    int items[STACK_SIZE];
    int top;
} Stack;

Stack stack;

void push(int value, int line_number) {
    if (stack.top >= STACK_SIZE - 1) {
        printf("L%d: can't push, stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack.items[++stack.top] = value;
}

void pall() {
    for (int i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.items[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char line[256];
    int line_number = 0;
    int pall_triggered = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;

        char *trimmed_line = strtok(line, "\t\n");
        if (!trimmed_line) {
            continue;
        }

        if (trimmed_line[0] == '#') {
            continue;
        }

        char *opcode = strtok(trimmed_line, " ");

        if (!opcode)
            continue;

        if (strcmp(opcode, "push") == 0) {
            char *arg = strtok(NULL, " \t\n");
            if (arg) {
                int arg_length = strlen(arg);
                if (arg_length > 0 && arg[arg_length - 1] == '$') {
                    arg[arg_length - 1] = '\0';
                }
                push(atoi(arg), line_number);
            } else {
                printf("L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(opcode, "pall$") == 0) {
            if (!pall_triggered) {
                pall();
                pall_triggered = 1;
            }
        } else {
            printf("L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    if (!pall_triggered) {
        pall();
    }

    fclose(file);
    return EXIT_SUCCESS;
}
