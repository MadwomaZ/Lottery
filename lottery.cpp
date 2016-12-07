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
    cout << "Range of the amount of numbers: " << min_sum << "-" << max_sum << endl;
    cout << "Range of amounts of even numbers: " << min_amount_of_even_numbers << "-"
         << max_amount_of_even_numbers << endl;
    cout << "Range of amounts of odd numbers: " << min_amount_of_odd_numbers << "-"
         << max_amount_of_odd_numbers << endl;
    cout << "Often falling numbers: ";
    for (size_t i = 0; i < often_falling_numbers.size(); i++)
    {
        cout << often_falling_numbers[i] << " ";
    }
    cout << endl;
    cout << "Rarely falling numbers: ";
    for (size_t i = 0; i < rarely_falling_numbers.size(); i++)
    {
        cout << rarely_falling_numbers[i] << " ";
    }
    cout << endl;
//    cout << "Circulations:" << endl;
//    for (size_t i = 0; i < circulations.size(); i++)
//    {
//        cout << "Number: " << circulations[i].get_number() << " Numbers: ";
//        for (size_t n = 0; n < circulations[i].get_numbers().size(); n++)
//        {
//            cout << circulations[i].get_numbers()[n] << " ";
//        }
//        cout << " Even: " << circulations[i].get_amount_of_even_numbers()
//                  << " Odd: " << circulations[i].get_amount_of_odd_numbers()
//                  << " Sum: " << circulations[i].get_sum_numbers();
//        cout << endl;
//    }
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
    set_often_and_rarely_falling_numbers();
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

void Lottery::set_often_and_rarely_falling_numbers()
{
    map<unsigned int, unsigned int> sums; //key=number value=sum
    for (size_t i = 0; i < circulations.size(); i++)
    {
        vector <Number> circ_numbers = circulations[i].get_numbers();
        for (size_t i = 0; i < circ_numbers.size(); i++)
        {
            try {
                sums.at(circ_numbers[i].get_number()) += 1;
            } catch(...)
            {
                sums[circ_numbers[i].get_number()] = 1;
            }
        }
    }
    multimap<unsigned int, unsigned int> reverse_sums; //key=sum value=number
    for(map<unsigned int, unsigned int>::iterator it = sums.begin(); it != sums.end(); ++it)
    {
        reverse_sums.insert(pair<unsigned int, unsigned int> (it->second, it->first));
    }
    cout << endl;
    size_t i = 0;
    for(multimap<unsigned int, unsigned int>::reverse_iterator it = reverse_sums.rbegin(); it != reverse_sums.rend(); ++it)
    {
//            cout << it->first << " "<< it->second << endl;
        if (i < 10) //Need 10 numbers as used on site
        {
            often_falling_numbers.push_back(it->second);
        }
        else if (i > reverse_sums.size() - 11)
        {
//            cout  << "min: " << it->first << " "<< it->second << endl;
            rarely_falling_numbers.push_back(it->second);
        }
        i++;
    }

//    cout << "Maximums: " << endl;
//    for (size_t i = 0; i < often_falling_numbers.size(); i++)
//    {
//        cout << often_falling_numbers[i] << " ";
//    }
//    cout << endl;

//    cout << "Minimums: " << endl;
//    for (size_t i = 0; i < rarely_falling_numbers.size(); i++)
//    {
//        cout << rarely_falling_numbers[i] << " ";
//    }
//    cout << endl;
}
