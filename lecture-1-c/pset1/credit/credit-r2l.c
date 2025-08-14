#include <stdio.h>
#include <cs50.h>

bool luhns_algorithm(long credit_card);
void check_provider(long credit_card);

int main(void)
{
    long credit_card = get_long("Enter credit card number: \n");

    if (luhns_algorithm(credit_card)) 
    {
        check_provider(credit_card);
    }
    else
    {
        printf("INVALID\n");
    }

}

bool luhns_algorithm(long credit_card)
{
    long modulo = 0;

    int double_digit_sum = 0;
    int regular_digit_sum = 0;

    int double_digit = 0;

    bool doubler = false;

    while (credit_card > 0)
    {
        modulo = credit_card % 10;

        if (doubler)
        {
            double_digit = 2*modulo;

            if (double_digit < 10)
            {
                double_digit_sum = double_digit_sum + double_digit;
            }
            else
            {
                int twos_place = double_digit / 10;
                int ones_place = double_digit % 10;
                double_digit_sum = double_digit_sum + twos_place + ones_place; 
            }
        }
        else
        {
            regular_digit_sum = regular_digit_sum + modulo;
        }

        credit_card = credit_card / 10;
        doubler = !doubler;
    }

    int final_sum =  double_digit_sum + regular_digit_sum;
    printf("doubled sum = %i | regular sum = %i | total sum = %i\n", double_digit_sum, regular_digit_sum, final_sum);
    
    if (final_sum%10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void check_provider(long credit_card)
{
    long count_number = credit_card;
    int no_of_digits = 0;
    while (count_number > 0)
    {
        count_number = count_number / 10;
        no_of_digits++; 
    }

    long hundreds = 10;
    for (int i = 0; i < no_of_digits - 2; i++)
    {
        hundreds = hundreds * 10;
    }

    int first_digit = credit_card / hundreds;

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

long power_of_ten(int no_of_digits)
{
    long hundreds = 10;
    for (int i = 0; i < no_of_digits - 2; i++)
    {
        hundreds = hundreds * 10;
    }
    return hundreds;
}

