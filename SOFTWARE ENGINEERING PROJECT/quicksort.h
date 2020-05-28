//
// Created by Jemima Adjenughure on 19/02/2020.
//

#ifndef SOFTWARE_ENGINEERING_PROJECT_QUICKSORT_H
#define SOFTWARE_ENGINEERING_PROJECT_QUICKSORT_H

#include "sizes.h"

void quicksort(char input_words[][CHAR_COUNT], int first, int last);
int partition(char input_words[][CHAR_COUNT], int first, int last);
void  swap(char array [][CHAR_COUNT], int i, int j);
void convert_lowercase(char *input_string);
void print_sort(char input_words[][CHAR_COUNT]);
//void store_sort(char input_words[][CHAR_COUNT], char stored_sort[][CHAR_COUNT]);

#endif //SOFTWARE_ENGINEERING_PROJECT_QUICKSORT_H
