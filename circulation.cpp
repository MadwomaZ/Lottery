#include "circulation.h"

Circulation::Circulation(unsigned int number, const std::vector<unsigned int> &numbers, unsigned int superprize) :
    number(number), numbers(numbers), superprize (superprize)
{
    calc_sum_numbers();
    calc_amount_odd_and_even_numbers();
}

void Circulation::calc_sum_numbers()
{
    for (int i = 0; i < numbers.size(); i++)
    {
        sum_numbers += numbers[i];
    }
}

void Circulation::calc_amount_odd_and_even_numbers()
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] % 2 == 0)
        {
            amount_of_even_numbers++;
        }
        else
        {
            amount_of_odd_numbers++;
        }
    }
}

void Circulation::calc_expected_value()
{
    //(сумма выигрыша по ставке x вероятность выигрыша) – (сумма проигрыша по ставке x вероятность проигрыша)
}
