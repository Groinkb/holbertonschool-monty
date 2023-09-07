#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*--- Définitions des structures ---*/
extern int push_arg;

/**
 * struct stack_s - représentation d'une liste doublement chaînée pour une pile (ou une file)
 * @n: entier
 * @prev: pointe vers l'élément précédent de la pile (ou de la file)
 * @next: pointe vers l'élément suivant de la pile (ou de la file)
 * Description : structure de nœud de liste doublement chaînée
 * pour une pile, une file, LIFO, FIFO projet Holberton
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opération et sa fonction
 * @opcode: l'opération
 * @f: fonction pour gérer l'opération
 * Description : opération et sa fonction
 * pour une pile, une file, LIFO, FIFO projet Holberton
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

