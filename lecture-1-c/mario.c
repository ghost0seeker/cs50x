#include <stdio.h>
#include <cs50.h>

int get_positive_int(void);
void print_a_square(int rows, int columns);

int main(void) {

    printf("Enter no. of rows");
    int rows = get_positive_int();
    printf("Enter no. of columns");
    int columns = get_positive_int();

    print_a_square(rows, columns);

}

int get_positive_int(void) {
    int input;
    do {
        input = get_int(" ");
    }
    while (input < 1);
    printf("\n");
    return input;
}

void print_a_square(int rows, int columns) {
    
    
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < columns; j++) {
            printf("#");
        }
        printf("\n");
    }
}