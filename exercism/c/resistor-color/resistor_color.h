#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

typedef enum {
    BLACK = 0,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE,
    END
} resistor_band_t;

int color_code(resistor_band_t Color);

int* colors();

int ARRAY_LENGTH(int* arr);

#endif
