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

int scsv_create();

typedef struct f_list {
    int state;
    int (*ft)(sfRenderWindow*, sfClock*);
}f_list;

extern int state;

sfTexture **life_textures(void);

sfSprite **life_sprites(void);

sfTexture **bg_textures(void);

sfSprite **bg_sprites(void);

sfTexture **floor_textures(void);

sfSprite **floor_sprites(void);

int my_strlen(char *str);

void my_putstr(char *str);

char *my_strdup(char *src);

int running(sfRenderWindow *window, sfClock *clock);

int attack1(sfRenderWindow *window, sfClock *clock);

int jumping(sfRenderWindow *window, sfClock *clock);

int idle(sfRenderWindow *window, sfClock *clock);

int spikes(sfRenderWindow *window);

void clouds(sfRenderWindow *window);

void destroy(sfRenderWindow *window, sfTexture **texture, sfSprite **sprite);

void background(sfRenderWindow *window, sfTexture **textures, sfSprite **sprites, sfClock *clock);

void event(sfRenderWindow *window);

int dying(sfRenderWindow *window, sfClock *clock);


/*
static const f_list f_tab[5] = {
    {0, idle},
    {1, running},
    {2, jumping},
    {3, attack1},
    {4, dying}
};*/