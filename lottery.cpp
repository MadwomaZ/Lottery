#include "lottery.h"
#include <iostream>
#include <sstream>

using namespace std;

Lottery::Lottery(unsigned int max_number, unsigned int min_amount, unsigned int max_amount) :
    max_number(max_number), min_amount_of_numbers_in_combination(min_amount),
    max_amount_of_numbers_in_combination(max_amount)
{
    set_name();
    load_history();
}

void Lottery::get_info()
{
    cout << "Lottery " << name_lottery << endl;
    cout << "URL: " << url_lottery << endl;
    cout << "Maximum sum: " << max_sum << endl;
    cout << "Minimum sum: " << min_sum << endl;
    cout << "Maximum amount of even numbers: " << max_amount_of_even_numbers << endl;
    cout << "Minimum amount of even numbers: " << min_amount_of_even_numbers << endl;
    cout << "Maximum amount of odd numbers: " << max_amount_of_odd_numbers << endl;
    cout << "Minimum amount of odd numbers: " << min_amount_of_odd_numbers << endl;
    cout << endl;
    cout << "Circulations:" << endl;
    for (size_t i = 0; i < circulations.size(); i++)
    {
        cout << "Number: " << circulations[i].get_number() << " Numbers: ";
        for (size_t n = 0; n < circulations[i].get_numbers().size(); n++)
        {
            cout << circulations[i].get_numbers()[n] << " ";
        }
        cout << " Even: " << circulations[i].get_amount_of_even_numbers()
                  << " Odd: " << circulations[i].get_amount_of_odd_numbers()
                  << " Sum: " << circulations[i].get_sum_numbers();
        cout << endl;
    }
}

void Lottery::set_name()
{
    stringstream ss;
    ss << max_amount_of_numbers_in_combination << 'x' << max_number;
    name_lottery = ss.str();
    url_lottery = STOLOTO_URL + name_lottery + "/archive/";
}

void Lottery::load_history()
{
    get_html_file(name_lottery, url_lottery);
    get_all_data(name_lottery);
    circulations = get_circulations(name_lottery, max_amount_of_numbers_in_combination);
    set_max_and_min_sum_numbers();
    set_max_and_min_amount_of_even_numbers();
    set_max_and_min_amount_of_odd_numbers();
    get_often_falling_numbers();
}

void Lottery::set_max_and_min_sum_numbers ()
{
    unsigned int max = circulations[0].get_sum_numbers();
    unsigned int min = max;
    unsigned int sum = 0;
    for (size_t i= 0; i < circulations.size(); i++)
    {
        sum = circulations[i].get_sum_numbers();
        if (sum > max)
        {
            max = sum;
        }
        if (sum < min)
        {
            min = sum;
        }
    }
    max_sum = max;
    min_sum = min;
}

void Lottery::set_max_and_min_amount_of_even_numbers ()
{
    unsigned int max = circulations[0].get_amount_of_even_numbers();
    unsigned int min = max;
    unsigned int amount = 0;
    for (size_t i= 0; i < circulations.size(); i++)
    {
        amount = circulations[i].get_amount_of_even_numbers();
        if (amount > max)
        {
            max = amount;
        }
        if (amount < min)
        {
            min = amount;
        }
    }
    max_amount_of_even_numbers = max;
    min_amount_of_even_numbers = min;
}

void Lottery::set_max_and_min_amount_of_odd_numbers ()
{
    unsigned int max = circulations[0].get_amount_of_odd_numbers();
    unsigned int min = max;
    unsigned int amount = 0;
    for (size_t i= 0; i < circulations.size(); i++)
    {
        amount = circulations[i].get_amount_of_odd_numbers();
        if (amount > max)
        {
            max = amount;
        }
        if (amount < min)
        {
            min = amount;
        }
    }
    max_amount_of_odd_numbers = max;
    min_amount_of_odd_numbers = min;
}

vector <unsigned int> Lottery::get_often_falling_numbers()
{
    vector<unsigned int> sums; //index=number value=sum
    sums.resize(max_number);
    vector <unsigned int> result;
    for (size_t i = 0; i < circulations.size(); i++)
    {
        vector <unsigned int> circ_numbers = circulations[i].get_numbers();
        for (size_t i = 0; i < circ_numbers.size(); i++)
        {
            sums[circ_numbers[i]-1] += 1;
        }
    }
    unsigned int idx_max = 0, max_value = 0;
    for (size_t i = 0; i < max_number; i++)
    {
        cout << i + 1 << " " << sums[i] << endl;
        if (sums[i] > max_value)
        {
            result.push_back(sums[i]);
            max_value = sums[i];
//            idx_max = i;
        }


    }
    cout << "max: ";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " "; //need 6 values
    }
    cout << endl;
    return result;
}
