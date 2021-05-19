/*
** EPITECH PROJECT, 2021
** eval expr #1
** File description:
** test 1 for the mouli to pass
*/

#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <math.h>
#include "my_sfml.h"

void destroy(sfRenderWindow *window, sfTexture **texture, sfSprite **sprite)
{
    for (int i = 0; i < 20; i++) {
        sfTexture_destroy(texture[i]);
        sfSprite_destroy(sprite[i]);
    }
    sfRenderWindow_destroy(window);
}

void background(sfRenderWindow *window, sfTexture **textures, sfSprite **sprites, sfClock *clock)
{
    sfVector2f scale = {0.75, 0.75};
    int width = 1920;
    static float v[4] = {0, 0, 0, 0};
    static int life = 1;
    sfTexture **life_t = life_textures();
    sfSprite **life_s = life_sprites();
    
    if (state != 0) {
        for (int i = 1; i <= 4; i++) {
            if (v[i - 1] >= -1920)
                v[i - 1] -= i * 1.5;
            else
                v[i - 1] = 0;
        }
    }
    for (int i = 0; i < 20; i++) {
        sfSprite_setScale(sprites[i], scale);
        if ((i >= 6 && i < 20) || (i >= 2 && i <= 3))
            (i % 2 == 0) ? sfSprite_setPosition(sprites[i], (sfVector2f) {v[i / 5], 0}) : sfSprite_setPosition(sprites[i], (sfVector2f) {width + v[i / 5], 0});
        else
            sfSprite_setPosition(sprites[i], (sfVector2f) {0, 0});
        sfSprite_setTexture(sprites[i], textures[i], sfTrue);
        sfRenderWindow_drawSprite(window, sprites[i], NULL);
    }
    clouds(window);
    if (spikes(window) == 200 && jumping(window, clock) >= 680) {
        life++;
        if (life == 8)
            state = 4;
    }
    sfSprite_setPosition(life_s[life], (sfVector2f) {30, 20});
    sfSprite_setScale(life_s[life], (sfVector2f) {2.5, 2.5});
    sfSprite_setTexture(life_s[life], life_t[life], sfTrue);
    sfRenderWindow_drawSprite(window, life_s[life], NULL);
    sfSprite_destroy(life_s[life]);
    sfTexture_destroy(life_t[life]);
}

void event(sfRenderWindow *window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
            sfRenderWindow_close(window);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            state = 2;
        if (sfKeyboard_isKeyPressed(sfKeyEnter))
            state = 3;
    }
}