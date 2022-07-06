#ifndef _MAIN_H_
#define _MAIN_H_

/* libraries */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* structs */

/**
 * struct print - structure for printing various types
 * @spec: to print
 * @f: print function
 */

typedef struct print
{
	char *spec;
	int (*f)(va_list);
} specifier;


/* prototypes */

int _printf(const char *format, ...);
int print_char(va_list c);
int print_string(va_list s);
int print_int(va_list i);

#endif /* _MAIN_H_ */
