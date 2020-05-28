cmake_minimum_required(VERSION 3.15)
project(SOFTWARE_ENGINEERING_PROJECT C)

set(CMAKE_C_STANDARD 11)

add_executable(SOFTWARE_ENGINEERING_PROJECT main.c quicksort.c quicksort.h read_input.c read_input.h sizes.h count_characters.c count_characters.h find_anagrams.c find_anagrams.h half_anagrams.c half_anagrams.h)