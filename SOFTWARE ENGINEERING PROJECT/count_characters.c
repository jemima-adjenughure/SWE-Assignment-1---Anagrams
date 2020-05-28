//
// Created by Jemima Adjenughure on 20/02/2020.
//
#include <strings.h>
#include <ctype.h>
#include "sizes.h"

/*This function converts inputString in a string having all
  lowercase letters and copies the result in lowerString*/
void toLower(char input_words[], char lowerString[])
{
    for (int i = 0; i< strlen(input_words); i++)
    {
        // function to lower converts a character in its lower case version
        lowerString[i] = tolower(input_words[i]);
    }
}

/*This function counts the characters in the sentences stored in InputStrings
  and stores them in the 2D array charCount*/
void countCharacters(char input_words [][MAX_LEN], int charCount[][CHAR_NUM])
{
    char lowerString[MAX_LEN];

    //initialize charCount
    for (int i =0; i < STR_NUM; i++)
        for (int j =0;  j< 26; j++)
            charCount[i][j] = 0;

            for (int i =0; i< STR_NUM; i++){
            //converts a string into lower case letters
                toLower(input_words[i], lowerString);
                    for (int j =0; j < strlen(input_words[i]); j++){
                    //increments the cell in char count associated with the corresponding character

                         if(lowerString[j] >= 'a'&& lowerString[j] <= 'z')
                         {
                            int position = lowerString[j]-'a';
                            charCount[i][position]++;
            }

        }

    }

}

