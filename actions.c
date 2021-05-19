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

int running(sfRenderWindow *window, sfClock *clock)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/character.png", NULL);
    float time = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    static int x = 1;
    static int y = 6;
    static int p = 480;

    if (time > 100) {
        if ((y == 6 && x < 4) || (y == 7 && x < 3))
            x++;
        else {
            x = 1;
            if (y != 7)
                y++;
            else
                y = 6;
        }
        sfClock_restart(clock);
    }
    if (p >= 1440)
        p = 0;
    sfSprite_setPosition(sprite, (sfVector2f) {100, 780});
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {0.5, 0.5});
    sfSprite_setTextureRect(sprite, (sfIntRect) {p * x, 320 * y, 480, 320});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return 100;
}

int attack1(sfRenderWindow *window, sfClock *clock)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/character.png", NULL);
    float time = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    static int x = 1;
    static int y = 1;
    static int p = 480;

    if (time > 100) {
        if ((y == 1 && x < 4) || (y == 2 && x < 3))
            x++;
        else {
            x = 1;
            if (y != 2)
                y++;
            else
                y = 1;
        }
        sfClock_restart(clock);
    }
    if (p >= 1440)
        p = 0;
    if (x == 3 && y == 2)
        state = 1;
    sfSprite_setPosition(sprite, (sfVector2f) {100, 780});
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {0.5, 0.5});
    sfSprite_setTextureRect(sprite, (sfIntRect) {p * x, 320 * y, 480, 320});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return 1;
}

int jumping(sfRenderWindow *window, sfClock *clock)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/character.png", NULL);
    static int x = 3;
    static int y = 5;
    static int h = 780;
    static float vY = 30;
    float speed = -2.5;

    h -= vY;
    vY += speed;
    sfSprite_setPosition(sprite, (sfVector2f) {100, h});
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {0.5, 0.5});
    sfSprite_setTextureRect(sprite, (sfIntRect) {480 * x, 320 * y, 480, 320});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    if (vY < 0)
        x = 4;
    else
        x = 3;
    if (h >= 780) {
        h = 780;
        state = 1;
        vY = 30;
    }
    return h;
}

int idle(sfRenderWindow *window, sfClock *clock)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/character.png", NULL);
    float time = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    static int x = 1;
    static int y = 4;

    if (time > 200) {
        if ((x < 4 && y == 4) || (x < 3 == y == 5)) 
            x++;
        else {
            x = 1;
            if (y == 4)
                y++;
            else {
                x = 1;
                y = 4;
            }
        }
        sfClock_restart(clock);
    }
    sfSprite_setPosition(sprite, (sfVector2f) {100, 780});
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {0.5, 0.5});
    sfSprite_setTextureRect(sprite, (sfIntRect) {480 * x, 320 * y, 480, 320});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

int dying(sfRenderWindow *window, sfClock *clock)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/character.png", NULL);
    float time = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    static int x = 2;
    static int y = 3;

    sfSprite_setPosition(sprite, (sfVector2f) {100, 780});
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {0.5, 0.5});
    sfSprite_setTextureRect(sprite, (sfIntRect) {480 * x, 320 * y, 480, 320});
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    if (time > 200) {
        if (x >= 2 && x <= 5)
            x++;
        else
            x = 2;
        sfClock_restart(clock);
    }
}

int spikes(sfRenderWindow *window)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_create(1920, 1080);
    sfColor *pixels = malloc(sizeof(sfColor) * 1920 * 1080 * 32);
    static int p = 1920;

    if (p >= 0 && state != 0)
        p -= 10;
    else
        p = 1920;
    for (int x = 0; x < 50; x++)
        for (int y = 0; y < 150; y++)
            pixels[y * 1920 + x] = sfColor_fromRGBA(255, 0, 0, 255);
    sfSprite_setPosition(sprite, (sfVector2f) {p, 780});
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfTexture_updateFromPixels(texture, (sfUint8*) pixels, 1920, 1080, 0, 0);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    free(pixels);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return p;
}

void clouds(sfRenderWindow *window)
{
    sfTexture **floor_t = floor_textures();
    sfSprite **floor_s = floor_sprites();
    int tab[4][2] = {{0, 800}, {900, 750}, {1920, 800}, {2825, 750}};
    static int p = 0;

    if (state != 0) {
        if (p >= -1920)
            p -= 10;
        else
            p = 0;
    }
    for (int i = 0; i <= 3; i++) {
        sfSprite_setScale(floor_s[i], (sfVector2f) {2.5, 2});
        sfSprite_setPosition(floor_s[i], (sfVector2f) {tab[i][0]+p, tab[i][1]});
        sfSprite_setTexture(floor_s[i], floor_t[i], sfTrue);
        sfRenderWindow_drawSprite(window, floor_s[i], NULL);
    }
    for (int i = 0; i <= 3; i++) {
        sfTexture_destroy(floor_t[i]);
        sfSprite_destroy(floor_s[i]);
    }
}