#include "circulation.h"

Circulation::Circulation(unsigned int number, const std::vector<Number> &numbers, unsigned int superprize) :
    number(number), numbers(numbers), superprize (superprize)
{
    calc_sum_numbers();
    calc_amount_odd_and_even_numbers();
}

Circulation::Circulation(unsigned int number, const std::vector<Number> &numbers) :
    number(number), numbers(numbers)
{
    calc_sum_numbers();
    calc_amount_odd_and_even_numbers();
}

void Circulation::calc_sum_numbers()
{
    for (std::size_t i = 0; i < numbers.size(); i++)
    {
        sum_numbers += numbers[i].get_number();
    }
}

void Circulation::calc_amount_odd_and_even_numbers()
{
    for (std::size_t i = 0; i < numbers.size(); i++)
    {
        if (numbers[i].get_number() % 2 == 0)
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
