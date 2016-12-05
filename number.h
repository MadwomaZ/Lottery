#ifndef NUMBER_H
#define NUMBER_H
#include "circulation.h"

class Number
{
    unsigned int number;
    bool an_even;
    std::vector <Circulation> circulations_with_this_number;
    unsigned int frequency;
public:
    Number(unsigned int number);
    ~Number();
    void get_info();
    unsigned int get_number() { return number; }
    bool get_even_number() { return an_even; }
    std::vector <Circulation> get_circulations_with_this_number() { return circulations_with_this_number;}
    unsigned int get_frequency() { return frequency; }
    void set_circulations_with_this_number(std::vector <Circulation>& circulations);
};


#endif // NUMBER_H
