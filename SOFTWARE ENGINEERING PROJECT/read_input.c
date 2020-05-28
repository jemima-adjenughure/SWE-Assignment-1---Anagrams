//
// Created by Jemima Adjenughure on 19/02/2020.
//

#include "read_input.h"
#include <stdio.h>
#include "sizes.h"


const char *TEXT_INPUT = "input-2.txt";
//this function reads the data from the input txt file
void read_input(char input_words[LINE_COUNT][CHAR_COUNT])
{
    int lineNum = 0;
    FILE *fp = fopen(TEXT_INPUT, "r+");
    if(fp == NULL)//checks to make sure file is sucessfully opened
    {
        perror("Error opening text input file");
    }
    else
        {
        //while loop to remove the '\n' in each line
        while (fgets(input_words[lineNum], sizeof(input_words[lineNum]), fp) != NULL)
        {
            removeNewline(input_words[lineNum]);
            lineNum++;
        }
    }

    fclose(fp);
}

//in this function i used a for loop to go through each of the lines
// and exchange where ever there was a '\n' to a '\0'
void removeNewline(char sentence[CHAR_COUNT])
{

    for (int i = 0; i < CHAR_COUNT ; i++)
    {
        if (sentence[i] == '\n')
        {
            sentence[i]= '\0';
            break;
        }
    }
}
