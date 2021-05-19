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

int state = 0;

void menu(sfRenderWindow *window)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_create(1920, 1080);
    sfColor *pixels = malloc(sizeof(sfColor) * 1920 * 1080 * 32);

    for (int x = 0; x < 1920; x++)
        for (int y = 0; y < 1080; y++)
            pixels[y * 1920 + x] = sfColor_fromRGBA(0, 0, 0, 150);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfTexture_updateFromPixels(texture, (sfUint8*) pixels, 1920, 1080, 0, 0);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    free(pixels);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

int scsv_create()
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32}, "MyRunner", sfClose | sfResize, NULL);
    sfTime time;
    sfClock *clock = sfClock_create();
    sfTexture **bg_t = bg_textures();
    sfSprite **bg_s = bg_sprites();

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_setFramerateLimit(window, 100);
        background(window, bg_t, bg_s, clock);
        if (state == 0) {
            idle(window, clock);
            menu(window);
        }
        else {
            if (state == 4)
                dying(window, clock);
            if (state == 3)
                attack1(window, clock);
            if (state == 2)
                jumping(window, clock);
            if (state == 1)
                running(window, clock);
        }
        event(window);
        sfRenderWindow_display(window);
    }    
    destroy(window, bg_t, bg_s);
    return 0;
}

int main()
{
    scsv_create();
    return 0;
}