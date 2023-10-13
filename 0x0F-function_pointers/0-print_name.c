/**
 * print_name - a function that prints name.
 * @name: name to be printed (a pointer).
 * @f: a pointer to a funtion.
*/
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
