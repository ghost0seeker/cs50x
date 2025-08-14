#include <stdio.h>
#include <cs50.h>

bool luhns_algorithm(long credit_card, long hundreds);

int main(void)
{
    long credit_card = get_long("Enter credit card number: ");
    
    long hundreds = 1000000000000000;

    int first_digit = credit_card/hundreds;

    if (luhns_algorithm(credit_card, hundreds)) 
    {
        
        if ( first_digit == 3 )
        {
            printf("AMEX\n");
        }
        else if ( first_digit == 4 )
        {
            printf("VISA\n");
        }
        else if ( first_digit == 5)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool luhns_algorithm(long credit_card, long hundreds)
{
    int sum_digits_a = 0;
    int sum_digits_b = 0;

    for (int i=0; i < 8; i++)
    {
        // calculating digits set a
        int digit_a = credit_card/hundreds;
        int double_digit_a = 2 * digit_a;
        if (double_digit_a < 10)
        {
            sum_digits_a = sum_digits_a + double_digit_a;
        }
        else 
        {
            int twos_place = double_digit_a / 10;
            int ones_place = double_digit_a - twos_place * 10;
            sum_digits_a = sum_digits_a + twos_place + ones_place;
        }
        // calculating digits set b
        credit_card = credit_card - digit_a * hundreds;
        hundreds /= 10;
        int digit_b = credit_card/hundreds;
        sum_digits_b = sum_digits_b + digit_b;
        credit_card = credit_card - digit_b * hundreds;
        hundreds /= 10;
    }

    int final_sum = sum_digits_a + sum_digits_b;
    if (final_sum%10 == 0)
    {
        // printf("Credit card is valid\n");
        return true;
    }
    else
    {
        // printf("Credit card is invalid\n");
        return false;
    }
}