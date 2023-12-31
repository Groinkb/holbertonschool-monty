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

/**
 * struct global_variable - opération et sa fonction
 * @file: le fichier
 * @push_arg: fonction pour gérer l'opération
 * @buffer: pointeur vers
 * Description : opération et sa fonction
 * pour une pile, une file, LIFO, FIFO projet Holberton
 */
typedef struct global_variable
{
	FILE *file;
	char *buffer;
	int push_arg;
} global_var;

extern global_var var_global;

void read_file(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *str);

/* Fonctions Monty */
void _pall(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);

/* Fonctions chaînes ASCII */
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);

/* Fonctions mathématiques */
void _sub(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

/* Fonctions utilitaires */
void free_dlistint(stack_t *head);
void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);
int _isalpha(int c);
#endif
