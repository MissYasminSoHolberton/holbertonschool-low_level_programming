#include "main.h"

/**
 * _isalpha - prints 1 if char is lowercase otherwise 0
 * @c: character to check
 *
 * Return: if char is lowercase return 1 otherwise retutn 0
 */
int _isalpha(int c)
{
if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
{
return (1);
}
else
{
return (0);
}
}
