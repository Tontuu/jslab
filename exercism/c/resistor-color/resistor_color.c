#include "resistor_color.h"

int arr[10] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};

int color_code(resistor_band_t Color) {
    return Color;
}

int* colors() {
    return &arr[0];
}
