#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * create_words - a function that creates a word and insert
 * it into an array.
 * @words: the array of strings.
 * @str: the string.
 * @start: the starting index of the word.
 * @end: the last index of the word.
 * @index: the index ot the array to insert the word.
*/
void create_words(char **words, char *str, int start, int end, int index)
{
	int i, j;

	i = end - start;
	words[index] = (char *)malloc(sizeof(char) * (i + 1));
	for (j = 0; start < end; start++, j++)
		words[index][j] = str[start];
	words[index][j] = '\0';
}

/**
 * util - a function that fetches words into array.
 * @words: the strings array.
 * @str: the string.
*/
void util(char **words, char *str)
{
	int i, j, start, flag;

	i = j = flag = 0;
	while (str[i])
	{
		if (flag == 0 && str[i] != ' ')
		{
			start = i;
			flag = 1;
		}
		if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
		{
			create_words(words, str, start, i, j);
			j++;
			flag = 0;
		}
		j++;
	}
	if (flag == 1)
		create_words(words, str, start, i, j);
}

/**
 * strtow - a function that splits string into words.
 * @str: string to be splitted.
 * Return: a pointer to an array of strings.
*/
char **strtow(char *str)
{
	int i, flag, len;
	char **words;

	if (str == NULL || str[0] == '\0' || (str[0] == ' ' && str[1] == '\0'))
		return (NULL);
	i = flag = len = 0;
	while (str[i])
	{
		if (flag == 0 && str[i] != ' ')
			flag = 1;
		if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
		{
			flag = 0;
			len++;
		}
		len++;
	}
	len += flag == 1 ? 1 : 0;
	if (len == 0)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (len + 1));
	if (words == NULL)
		return (NULL);
	util(words, str);
	words[len] = NULL;
	return (words);
}
