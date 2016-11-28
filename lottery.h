#ifndef LOTTERY_H
#define LOTTERY_H

#include "circulation.h"
#include "html.h"
#define STOLOTO_URL "http://www.stoloto.ru/"

class Lottery
{
    unsigned int max_number = 0; //49
    unsigned int min_amount_of_numbers_in_combination = 0; //3
    unsigned int max_amount_of_numbers_in_combination = 0; //6
    std::string name_lottery;
    std::string url_lottery;
    std::vector <Circulation> circulations;
public:
    Lottery(unsigned int max_number, unsigned int min_amount, unsigned int max_amount);
    void get_info();
    void set_name();
    void load_history();
};

#endif // LOTTERY_H
