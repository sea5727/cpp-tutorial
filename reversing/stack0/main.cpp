#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>



int main(){
    volatile int modified;
    char buffer[64];

    modified = 0;
    if(modified != 0) {
        printf("you have changed the 'modified' variable\n");
    } else {
        printf("Try again?\n");
    }

    return 0;
}