#include <iostream>
#include <stdio.h>
#include <string.h>
void
test1(){
    char input[] = "asdf|123|hi||321|123.222|asdf|";
    
    char * p = input;
    char * last;

    int token_count = 0;
    char * token = strtok_r(input, "|", &last);
    while ( token != NULL )
    {
        printf("STEP [%02d][%s]\n", token_count, token);
        token = strtok_r(NULL, "|", &last);
        token_count++;
    }

}


int main(int argc, char * argv[]){
    test1();
}