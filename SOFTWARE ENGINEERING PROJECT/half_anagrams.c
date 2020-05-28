//
// Created by Jemima Adjenughure on 24/02/2020.
//
#include "sizes.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "half_anagrams.h"
#include <stdio.h>
#include <stdlib.h>

//this function shortens the length of the strings being compared by a certain amount(n) calculated in another function
void shorten_string(char sentence[LINE_COUNT], int n)
{
    int count = 0;
    for (int i = 0; i < CHAR_COUNT; i++)
    {
        if (isalpha(sentence[i]))
        {
            count++;
        }

        if (count == n)
        {
            sentence[i + 1] = '\0';//so the ith + 1 position is assigned to a '\0' signify new end of string
            break;
        }
    }
}


//this function checks if the characters in the string are alphabets and keeps count of them
int letter_count(char sentence[CHAR_COUNT])
{
    int count = 0;
    for (int i=0; i<CHAR_COUNT; i++)
    {
        if (isalpha(sentence[i]))//checking that the character in question is a letter
        {
            count++;//incrementing the number of letters
        }
        if (sentence[i]== '\0')//ends when the null terminator is reached
        {
            break;
        }
    }

    return count;
}

void sentence_frequency(char sentence[CHAR_COUNT], int frequency[26])
//this function checks the frequency of letters in each line of the stirngs
{
    for (int i=0; i<26; i++)
        frequency[i] = 0;//setting frquency to zero at first

    for (int j =0; j < strlen(sentence); j++)
    {
        if (isalpha(sentence[j]))//checks that character is a letter
        {
            int position = tolower(sentence[j])-'a';
            frequency[position]++;
        }
    }
}

void missing_anagrams(char input_words[][CHAR_COUNT])
{
    //opening my output file that i want my missing anagrams printed into
    FILE *fp = fopen("output.txt","a+");
    if (fp == NULL)
    {
        perror("Error opening input.txt");
        exit(0);
    }
    fprintf(fp,"\n\n");

    char temp[CHAR_COUNT];//a temporary string array
    int frequency1[26];
    int frequency2[26];

    for (int i=0; i<LINE_COUNT; i++)
    {
        for (int j=0; j<LINE_COUNT; j++)
        {
            int len1 = letter_count(input_words[i]);//len1 is assigned the value of no of letters in input words[i]
            int len2 = letter_count(input_words[j]);//len1 is assigned the value of no of letters in input words[j]

            if(len1 <= len2)
                continue;

            strcpy(temp,input_words[i]);//copy the contents of input words to temporary array
            shorten_string(temp,len2);  //using our shorten string function to shorten our temp string by len2
            sentence_frequency(temp, frequency1);//counts character frequency of the  word or phrase in question
            sentence_frequency(input_words[j], frequency2);

            if (compare_frequency(frequency1, frequency2)) {
                fprintf(fp,"%s is an anagram of %s if %d characters are removed\n",input_words[i], input_words[j], len1-len2);
                //this over here is just printing into my output.txt file
            }
        }
    }
}

bool compare_frequency(int frequency1[26], int frequency2[26])
//this function checks the frequency of two different strings and returns true if they are equal
{
    for (int i=0; i<26; i++)
    {
        if (frequency1[i] != frequency2[i])
        {
            return false;
        }
    }

    return true;
}