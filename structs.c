

typedef struct {

    char variable_name[20];

    long int value;

}   int_variable;


typedef struct {

    char variable_name[20];

    float value;

}   float_variable;

#define MAX_STRING_LENGTH 1000

typedef struct {

    char variable_name[20];

    char value[MAX_STRING_LENGTH];

}   string_variable;

typedef char word[100];
typedef word sentence[30]; 
