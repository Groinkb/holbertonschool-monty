#include "monty.h"
global_var var_global; /* Declare a global variable of type global_var */

/**
 * main - The main driver function for the monty program.
 * @ac: The number of command-line arguments.
 * @av: An array of strings containing the command-line arguments.
 * Return: 0 on successful execution, or an error code on failure.
 */
int main(int ac, char **av)
{
	stack_t *stack; /* Declare a pointer to a stack_t structure */

	stack = NULL; /* Initialize the stack pointer to NULL */

	/* Check if the number of command-line arguments is not 2 */
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"); /* Print an error message to stderr */
		exit(EXIT_FAILURE); /* Exit the program with a failure status code */
	}

	read_file(av[1], &stack); /* Call the read_file function to process the specified file */

	/* Remember to free memory */
	free_dlistint(stack); /* Call the free_dlistint function to free memory associated with the stack */

	return (0); /* Return 0 to indicate successful execution */
}

