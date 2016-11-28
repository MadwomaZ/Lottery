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
}
