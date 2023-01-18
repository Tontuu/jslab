#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate) {
    int sum = 0;
    int count = 0;
    if (candidate == 0) return 1;
    int candidate_temp = candidate;

    while (candidate_temp > 0) {
        candidate_temp = candidate_temp / 10;
        count++;
    }

    if (count == 1) return 1;

    candidate_temp = candidate;

    int algarisms[count];

    for (int i = count-1; i >= 0; --i) {
        algarisms[i] = candidate_temp % 10;
        candidate_temp = candidate_temp / 10;
    }


    for (int i = 0; i < count; ++i) {
        sum += pow(algarisms[i], count);
    }
    return (sum == candidate);
}
