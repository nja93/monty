#include "monty.h"

/**
 * is_int - fn that checks if string has an int
 * @str: ...
 * by Lorna
 * Return: 0 if not an int and 1 if it is
 */

int is_int(const char *str)
{
/*check if string is NULL or if pointer points to a null terminator */

	if (str == NULL || *str == '\0')
		return (0);
/*check if the first values are - or + if as signed int*/
	if (str[0] == '-' || str[0] == '+')
		str++; /*skip the - & + and point tho the nextxtr in the string*/

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
