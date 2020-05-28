//
// Created by Jemima Adjenughure on 19/02/2020.
//THIS WAS THE QUICK SORT FROM THE LECTURE NOTES BY LILIANA I CHANGED IT TO CHHAR AND ADDED

#include "quicksort.h"
#include <stdio.h>
#include <strings.h>
#include "sizes.h"
#include <ctype.h>

void swap (char array [][CHAR_COUNT], int i, int j)
//this function swaps the array[i] to temp and array[j] is swapped to array[i]
//temp is swapped to swapped to array[j]
{
    if (i == j)
        return;
    char temp[100];
    strcpy(temp, array[i]);//copying array into another effectively swapping
    strcpy(array[i], array[j]);
    strcpy(array[j], temp);


}


int partition (char input_words[][CHAR_COUNT], int first, int last)
//this function basically splits up the array being sorted and makes sure all values
{
    swap(input_words, first, (first + last) / 2); // swap middle value into first pos
    char * pivot = input_words[first]; 	 // remember pivot
    char lowercase_pivot[CHAR_COUNT];
    strcpy(lowercase_pivot,pivot);
    convert_lowercase(lowercase_pivot);

    int index1 = first + 1; // index of first unknown value
    int index2 = last;    // index of last unknown value
    while (index1 <= index2) { // while some values still unknown
        char lowcase_index1 [CHAR_COUNT];//creating variable for the new indexes
        char lowcase_index2 [CHAR_COUNT];
        strcpy(lowcase_index1,input_words[index1]);//putting the character at index 1 position into my char index array
        strcpy(lowcase_index2,input_words[index2]);//putting the character at index 2 position into my char index array
        convert_lowercase(lowcase_index1);//converting to lowercase using  function i made
        convert_lowercase(lowcase_index2);

        if (strcmp(lowcase_index1, lowercase_pivot) < 0)//to check if strcmp returns a value less than 0
            index1++;//incrementing the index if it is
        else if (strcmp(lowcase_index2, lowercase_pivot) > 0)//checking if strcmp returns a value greater than 0
            index2--;//decrementing index if it is
        else {
            swap(input_words, index1, index2);//swap if the indexes are the same
            index1++;
            index2--;
        }

    }
    swap(input_words, first, index2); // put the pivot value between the two
    // partition thingy and return its index
    return index2;
}


void quicksort(char input_words[][CHAR_COUNT], int first, int last)
{

    //if the size of the array is equal to 0 or 1, the array is sorted by definition
    if(first < last){
        int pivotindex = partition(input_words, first, last);
        quicksort(input_words, first, pivotindex-1);
        quicksort(input_words, pivotindex+1, last);
    }

}

void convert_lowercase(char *input_string)
//didnt really need this but i kept it in just for show
{
    int i = 0;
    while(input_string[i]!= '\0')
    {
        input_string[i] = (char)tolower(input_string[i]);//assigning the string to the lowercase version
        i++;
    }

}

void print_sort(char input_words[][CHAR_COUNT])
//this function just prints to the output file
{
    FILE *fp = fopen("output.txt","w");
    if(fp == NULL){
        perror("Error opening input.txt");//ensuring file was properly opened
    }
    fprintf(fp,"The input file sorted aplhabetically :\n");

    for (int line = 0; line < LINE_COUNT; line++)//for loop to print sorted input file
    {
        fprintf(fp,"%s\n", input_words[line]);
    }

}


