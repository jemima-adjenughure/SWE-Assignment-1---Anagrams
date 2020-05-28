//
// Created by Jemima Adjenughure on 21/02/2020.
//
#include "sizes.h"
#include <stdio.h>
#include <stdbool.h>

void compare_char(int charCount[][CHAR_NUM], char input_words[][CHAR_COUNT])
{
    //opening the file i want my results printed into
    FILE *fp = fopen("output.txt","a+");
    if(fp == NULL){
        perror("Error opening input.txt");//opening the file i am printing to

    }

    fprintf(fp,"\n");
    int sentence_printed[LINE_COUNT];//checks when i have printed
    //variable to check if a sentence is printed
    for(int i=0;i<LINE_COUNT;i++)
    {
        sentence_printed[i] = false;
        //setting all values of sentence_printed to false
    }
    int count = 1; //Holds the number of anagrams found
    bool found;

    printf("\n\n");
    for(int i = 0; i < LINE_COUNT; i++)//using 4 nested loops to check each positon and compare
        // to see if the arrays being compared are the exact same
    {
        found = false;//setting all the values to false
        for(int j = i+1; j < LINE_COUNT; j++)//nested for loop that checks and compares
            // the different rows of char count matrix to see if they are the same
        {
            for(int k = 0; k < CHAR_NUM; k++)
            {
                 if (charCount[i][k] != charCount[j][k]) //if the two aren't the same exit the first nested loop that increment j
                 {
                     break;
                 }

                 if (k + 1 == CHAR_NUM && sentence_printed[j] == false)//checking if the anagram has been found yet
                 {
                     if (found == false)
                     {
                         found = true;
                         fprintf(fp,"Anagram %d: '%s'", count, input_words[i]);//printing to file
                         count++;
                     }

                     fprintf(fp,", '%s'", input_words[j]);
                     sentence_printed[j] = true;
                 }
            }
        }

                     if (found)
        {
                     fprintf(fp,"\n");
        }

    }
}




















