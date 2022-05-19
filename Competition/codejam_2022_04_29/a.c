#include <stdio.h>


int main(void) {
    int value = 5;
    int * const ptr3 = &value;
    *ptr3 = 4;
    return 0;
}


