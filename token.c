#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

void token(FILE * fptr);


void token(FILE * fptr) {

    char c;
    char current_word[30];
    char * p_in_word = current_word;

    int string_flag = 0;
    int word_begin = 0;
    int word_end = 0;

    while ( (c = fgetc(fptr)) != EOF ) {

        *(p_in_word++) = c;

        printf("current read char: \"");
        switch (c) {
            case '\n':
                if ( string_flag ) {
                    printf("\\n");
                } else {

                    if ( !word_end ) {
                        word_end = 1;
                        word_begin = 0;
                        memset(p_in_word - 1, 0, 1);
                        printf("none\n\n == a full sentense: \"%s\"\n\n", current_word);
                        memset(current_word, 0, 30); 
                        p_in_word = current_word;
                        // 30 is from the lenght of current_word
                    } 


                }
                break;

            case '\t':
                printf("\\t");
                break;

            case ' ':
                if ( string_flag ) {
                    printf(" ");
                } else {

                    if ( !word_end ) {
                        word_end = 1;
                        word_begin = 0;
                        memset(p_in_word - 1, 0, 1);
                        printf("none\n\n == a full sentense: \"%s\"\n\n", current_word);
                        memset(current_word, 0, 30); 
                        p_in_word = current_word;
                        // 30 is from the lenght of current_word
                    } 


                }
                break;

            case '\"':
            case '\'':

                if ( string_flag ) {
                    string_flag = 0;
                } else {
                    string_flag = 1;
                }

            default:
                if ( word_begin ) {
                    ;
                } else {
                    word_begin = 1;
                    word_end = 0;
                }
                printf("%c", c);

        }

        printf("\"\n");

    }
}
