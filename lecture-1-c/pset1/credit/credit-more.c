#include <stdio.h>
#include <cs50.h>

bool even_luhns_algorithm(long credit_card, long hundreds, int no_of_digits);
bool odd_luhns_algorithm(long credit_card, long hundreds, int no_of_digits);
long power_of_ten(int no_of_digits);
int count_credit_numbers(long credit_card);
void check_provider(int first_digit);

int main(void)
{
    long credit_card = get_long("Enter credit card number: ");

    int no_of_digits = count_credit_numbers(credit_card);
    printf("No of digits in CC: %i\n", no_of_digits);

    long hundreds = power_of_ten(no_of_digits);

    int first_digit = credit_card / hundreds;

    bool check;
    if (no_of_digits%2 == 0)
    {
        check = even_luhns_algorithm(credit_card, hundreds, no_of_digits);
    }
    else
    {
        check = odd_luhns_algorithm(credit_card, hundreds, no_of_digits);
    }

    if (check) 
    {
        check_provider(first_digit);
    }
    else
    {
        printf("INVALID\n");
    }
}

bool even_luhns_algorithm(long credit_card, long hundreds, int no_of_digits)
{
    int sum_digits_a = 0;
    int sum_digits_b = 0;

    for (int i=0; i < no_of_digits/2; i++)
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

bool odd_luhns_algorithm(long credit_card, long hundreds, int no_of_digits)
{
    int sum_digits_a = 0;
    int sum_digits_b = 0;
    int digit_a = 0;
    int digit_b = 0;

    for (int i=0; i < no_of_digits/2 + 1 ; i++)
    {
            if (hundreds !=0 )
            {
                digit_b = credit_card/hundreds;
            }
            else
            {
                break;
            }
            
            sum_digits_b = sum_digits_b + digit_b;
            credit_card = credit_card - digit_b * hundreds;
            hundreds /= 10;

            if (hundreds != 0 )
            {
                digit_a = credit_card/hundreds;
            }
            else
            {
                break;
            }
            
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

            credit_card = credit_card - digit_a * hundreds;
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

int count_credit_numbers(long credit_card)
{
    long count_number = credit_card;
    int no_of_digits = 0;
    while (count_number > 0)
    {
        count_number = count_number / 10;
        no_of_digits++; 
    }
    return no_of_digits;
}

long power_of_ten(int no_of_digits)
{
    long hundreds = 10;
    for (int i = 0; i < no_of_digits - 2; i++)
    {
        hundreds = hundreds * 10;
    }
    return hundreds;
}

void check_provider(int first_digit)
{
    if ( first_digit == 3 )
    {
        printf("AMEX\n");
    }
    else if ( first_digit == 4 )
    {
        printf("VISA\n");
    }
    else if ( first_digit == 5 || first_digit == 2)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}