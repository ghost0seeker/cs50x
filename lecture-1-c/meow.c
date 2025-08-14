#include <stdio.h>
#include <cs50.h>


void meow(int n);

int get_positive_int(void);

int main(void) {

    int times = get_positive_int();
    meow(times);
}

void meow(int times) {
    
    for (int i = 0; i < times; i++) {

        printf("meow\n");

    }
}

int get_positive_int(void) {
    int n;
    do {
        n = get_int("Pet n times ");
    }
    while (n < 1);
    return n;

}