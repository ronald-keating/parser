/*
    Programming Assignment #1
    Ronald Keating
    CS270
    2-13-19
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>                             //strncpy
#include "parser.h"                             //header file

int main()
{
    const int MAX_SIZE = 1024;                  //max size of user input
    int argc, i;
    char **args, str[MAX_SIZE];                 //matrix and string
    fgets(str, MAX_SIZE, stdin);                //get user input
    argc = makearg(str, &args);                 //call to makearg function
    printf("argc: %d\nargs:\n", argc);          //prints args
    for(i = 0; i < argc; i++)                   //gcc doesn't like variables
        printf("%s\n", args[i]);                //initiated in for loop
    free(*args);                                //free memory
    return 0;   
}

int makearg(char *s, char ***args)
{
    int argc = words(s);                        //set args to num of words
    int length;                                 //length of words
    if(argc == 0)                               //if fails
        return -1;
    *args = malloc(argc*sizeof(char*));         //allocate number of words
    argc = 0;                                   //set back to zero(already allocated)
    while(1)                                    //only false if endline
    {
        if(*s == '\n')                          //if endline
            break;
        else{
            while(*s == ' ')                    //while space
                s++;
            length = strLength(s);              //sets length to char count
            if(length == 0)                     //check if space at end of input
                return argc;
            (*args)[argc] = malloc(length + 1); //allocate word length
            strncpy((*args)[argc], s, length);  //copies from s to args
            (*args)[argc][length] = '\0';       //end of word with NULL
            argc++;                             //increment word
            s += length;                        //return to other end of word
        }
    }
    return argc;
}
