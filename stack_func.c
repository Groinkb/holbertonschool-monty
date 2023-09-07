#include "monty.h"

/**
 * _push - Pushes an integer onto the stack.
 * @stack: Pointer to the linked list representing the stack.
 * @line_number: Line number where the opcode occurs (unused).
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	/* Allocate memory for a new stack element */
	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Set the value of the new element to the pushed argument */
	top->n = var_global.push_arg;

	/* Update pointers to link the new element to the stack */
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * _pall - Prints all the elements in the stack.
 * @stack: Pointer to the linked list representing the stack.
 * @line_number: Line number where the opcode occurs (unused).
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * _pint - Prints the integer at the top of the stack.
 * @stack: Pointer to the linked list representing the stack.
 * @line_number: Line number where the opcode occurs.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * _pop - Removes the top element of the stack.
 * @stack: Pointer to the linked list representing the stack.
 * @line_number: Line number where the opcode occurs.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * free_dlistint - Frees a doubly linked list.
 * @head: Pointer to the first node of the list.
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
