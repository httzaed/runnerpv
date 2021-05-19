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

sfTexture **bg_textures(void)
{
    char **str_tab = malloc(sizeof(char*) * 30);
    sfTexture **res = malloc(sizeof(sfTexture*) * 20);
    char str[25] = "assets/bg/1.png";

    for (int i = 0; i < 10; i++) {
        str_tab[i] = malloc(sizeof(char) * 14);
        if (i < 9) {
            str[10] = i + 49;
            str_tab[i] = my_strdup(str);
        }
        else {
            str_tab[i] = my_strdup("assets/bg/10.png");
        }
    }
    for (int i = 0; i < 20; i++) {
        res[i] = sfTexture_createFromFile(str_tab[i/2], NULL);
    }
    return res;
}

sfSprite **bg_sprites(void)
{
    sfSprite **res = malloc(sizeof(sfSprite*) * 21);

    for (int i = 0; i < 20; i++)
        res[i] = sfSprite_create();
    return res;
}

sfTexture **life_textures(void)
{
    char **str_tab = malloc(sizeof(char*) * 18);
    sfTexture **res = malloc(sizeof(sfTexture*) * 10);
    char str[18] = "assets/life/1.png";

    for (int i = 0; i < 9; i++) {
        str_tab[i] = malloc(sizeof(char) * 40);
        str[12] = i + 49;
        str_tab[i] = my_strdup(str);
    }
    for (int i = 0; i < 9; i++) {
        res[i] = sfTexture_createFromFile(str_tab[i], NULL);
    }
    return res;
}

sfSprite **life_sprites(void)
{
    sfSprite **res = malloc(sizeof(sfSprite*) * 10);

    for (int i = 0; i < 10; i++)
        res[i] = sfSprite_create();
    return res;
}

sfTexture **floor_textures(void)
{
    sfTexture **res = malloc(sizeof(sfTexture*) * 4);

    res[0] = sfTexture_createFromFile("assets/cloud.png", NULL);
    res[1] = sfTexture_createFromFile("assets/cloud2.png", NULL);
    res[2] = sfTexture_createFromFile("assets/cloud.png", NULL);
    res[3] = sfTexture_createFromFile("assets/cloud2.png", NULL);
    return res;
}

sfSprite **floor_sprites(void)
{
    sfSprite **res = malloc(sizeof(sfSprite*) * 4);

    for (int i = 0; i <= 3; i++)
        res[i] = sfSprite_create();
    return res;
}