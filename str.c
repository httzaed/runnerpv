/*
** EPITECH PROJECT, 2021
** eval expr #1
** File description:
** test 1 for the mouli to pass
*/

#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include "my_sfml.h"

int my_strlen(char *str)
{
    int i = 0;
    
    for (; str[i]; i++);
    return i;
}

void my_putstr(char *str)
{
    write(1, &str, my_strlen(str));
}

char *my_strdup(char *src)
{
    int i = 0;
    int len = my_strlen(src);
    char *dest;

    if (!(dest = (char*)malloc(sizeof(src) * len + 1)))
        return (0);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}