#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXTENSION_NAME "jet"   // "jdkfa.j"

int extension_identifier( char* file_name, int file_name_length, char* extension_name, int ex_name_length ) {


    // start from end

    char * begin = file_name;
    char * end   = file_name + file_name_length - 1;

    char * current_char = end;
    char current_ex_name[ex_name_length];

    while ( *--current_char != '.' ) {

        if ( current_char == begin ) {
            printf("no extension name detected\n");
            return 0;
        }

    }

    ++current_char;

    memcpy( current_ex_name, current_char, sizeof(char) * ( end - current_char ) + 1);

    printf("ex_name: %s\n", current_ex_name);

    if ( strcmp(current_ex_name, extension_name) != 0 ) {
        printf("error: \"%s\" is not correct extension name\n", current_ex_name);
        return 0;
    }

    return 1;
}


int main(int argc, char* argv[])
{

    if ( argc < 2 ) {
        printf("no file input\n");
        return 0;
    }

    char* file_name = argv[1];

    if ( extension_identifier( file_name, strlen(file_name), EXTENSION_NAME, strlen(EXTENSION_NAME)) ) {

        FILE *fptr;
        fptr = fopen( file_name, "r");

        if ( fptr == NULL ) {
            printf("file didn't exist!\n");
            return 1;
        }


        char buf;
        int string_flag = 0;

        while ( (buf = fgetc(fptr)) != EOF ) {
            if ( buf == '\'' || buf == '\"' ) {
                if ( string_flag )
                    string_flag = 0;
                else
                    string_flag = 1;
            }

            if ( buf != ' ' || string_flag ) {
                printf("buf = %c\n", buf);
            }
        }


        printf("end of file\n");

        token(fptr);

    } else {

        printf("not correct file!\nfile extension name should be \"%s\"\n", EXTENSION_NAME);

    }
    

    return 0;

}
