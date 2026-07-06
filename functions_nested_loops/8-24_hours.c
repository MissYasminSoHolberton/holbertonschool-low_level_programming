#include "main.h"

/**
 * jack_bauer - all the minuite of the day
 *
 * Return: always 0 (success)
 */
void jack_bauer(void)
{
int hour1;
int hour10;
int min1;
int min10;

for (hour10 = 0; hour10 <= 2; hour10++)
{
for (hour1 = 0; hour1 <= 4; hour1++)
{
for (min10 = 0; min10 <= 5; min10++)
{
for (min1 = 0; min1 <= 9; min1++)
{
_putchar(hour10 + '0');
_putchar(hour1 + '0');
_putchar(':');
_putchar(min10 + '0');
_putchar(min1 + '0');
_putchar('\n');
}
}
}
}
}
