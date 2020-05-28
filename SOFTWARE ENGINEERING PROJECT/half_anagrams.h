//
// Created by Jemima Adjenughure on 24/02/2020.
//
#include "sizes.h"
#include <stdbool.h>
#ifndef SOFTWARE_ENGINEERING_PROJECT_HALF_ANAGRAMS_H
#define SOFTWARE_ENGINEERING_PROJECT_HALF_ANAGRAMS_H

void shorten_string(char sentence[LINE_COUNT], int n);
int letter_count(char sentence[CHAR_COUNT]);
void sentence_frequency(char sentence[CHAR_COUNT], int frequency[26]);
bool compare_frequency(int frequency1[26], int frequency2[26]);
void missing_anagrams(char input_words[][CHAR_COUNT]);
#endif //SOFTWARE_ENGINEERING_PROJECT_HALF_ANAGRAMS_H
