#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
int _putchar(char c);
typedef struct binary
{
	unsigned long int exp;
	struct binary *next;
} b;
unsigned int binary_to_uint(const char *b);
void print_binary(unsigned long int n);
void add_node_end(b **head, unsigned long int exp);

#endif
