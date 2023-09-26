#include "main.h"

/**
 * set_string - a function that sets the value of a pointer to a char.
 * @s:a double pointer.
 * @to: a pointer.
*/
void set_string(char **s, char *to)
{
	*s = to;
}
