#ifndef LOTTERY_H
#define LOTTERY_H

#include "circulation.h"
#include "html.h"
#include <algorithm>    // std::sort
#define STOLOTO_URL "http://www.stoloto.ru/"

class Lottery
{
    unsigned int max_number = 0; //49
    unsigned int min_amount_of_numbers_in_combination = 0; //3
    unsigned int max_amount_of_numbers_in_combination = 0; //6
    unsigned int max_sum = 0;
    unsigned int min_sum = 0;
    unsigned int max_amount_of_odd_numbers = 0;
    unsigned int min_amount_of_odd_numbers = 0;
    unsigned int max_amount_of_even_numbers = 0;
    unsigned int min_amount_of_even_numbers = 0;
    std::string name_lottery;
    std::string url_lottery;
    std::vector <Circulation> circulations;
    std::vector <unsigned int> often_falling_numbers;
    std::vector <unsigned int> rarely_falling_numbers;
public:
    Lottery(unsigned int max_number, unsigned int min_amount, unsigned int max_amount);
    void get_info();
    void set_name();
    void load_history();
    void set_max_and_min_sum_numbers();
    void set_max_and_min_amount_of_even_numbers();
    void set_max_and_min_amount_of_odd_numbers();
    void set_often_and_rarely_falling_numbers();
};

#endif // LOTTERY_H
