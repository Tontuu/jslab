#include "isogram.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool is_isogram(const char phrase[]) {

    if (!phrase)
        return false;
    if (strlen(phrase) == 0)
        return true;

    size_t len = strlen(phrase);
    for (size_t i = 0; i < len-1; ++i) {
        for (size_t j = i+1; j < len; j++) {
            if (tolower(phrase[i]) == tolower(phrase[j])) {
                if (phrase[i] != '-' && phrase[i] != ' ')
                    return false;
            }
        }
    }

    return true;
}
