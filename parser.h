/*
    Programming Assignment #1 Header
    Ronald Keating
    CS270
    2-13-19
*/
#include <stdio.h>
#include <stdlib.h>

int makearg(char *s, char ***args);

int words(char *s)                              //finds total number of words (argc)
{
    int state = 0, argc = 0;                    //argc and state
    while(*s != '\n')                           //while not endline
    {
        if(*s == ' ')                           //if space
        {
            s++;                                //traverse string
            state = 0;                          //no longer a word, set back to zero
        }
        else if((*s != ' ') && (state == 0))
        {
            argc++;                             //increment word count
            s++;
            state = 1;                          //state to determine if still on chars
        }
        else
            s++;                                //also almost forgot this, debugged for a while
    }
    return argc;
}

int strLength(char *s)                          //finds word length of each word
{
    int length = 0;                             //increment length of words in function
    while(*s != ' ')
    {
        if(*s == '\n')                          //if endline
            break;
        else{
            length++;                           //increment chars
            s++;                                //forgot this and could not figure out
        }                                       //why my program wouldn't work
    }
    return length;
}
