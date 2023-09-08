
#include "monty.h"


/**
 * _rotl - Rotates the stack to the left.
 * @stack: Pointer to the linked list representing the stack.
 * @line_number: Line number where the opcode occurs.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;
	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	aux1 = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n
	}

	runner->n = aux1;
}

/**
 * _rotr - Rotates the stack to the right.
 * @stack: Pointer to the linked list representing the stack.
 * @line_number: Line number where the opcode occurs.
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;
	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
	runner = runner->next

	aux1 = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = aux1;
}
