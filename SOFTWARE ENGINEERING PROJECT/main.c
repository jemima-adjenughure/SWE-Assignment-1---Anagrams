
#include "read_input.h"
#include "quicksort.h"
#include "sizes.h"
#include "count_characters.h"
#include "find_anagrams.h"
#include "half_anagrams.h"

int main(void)
{
    char input_words[LINE_COUNT][CHAR_COUNT];
    int charCount[CHAR_COUNT][CHAR_NUM];
    read_input(input_words);
    quicksort(input_words, 0, LINE_COUNT-1);
    print_sort(input_words);
    countCharacters(input_words, charCount);
    compare_char(charCount, input_words);
    missing_anagrams(input_words);

}
