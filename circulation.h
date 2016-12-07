#ifndef CIRCULATION_H
#define CIRCULATION_H
#include <vector>
#include "number.h"
class Number;
class Circulation
{
    unsigned int number;
    std::vector <Number> numbers;
    unsigned int superprize = 0;

    //for calc
    unsigned int sum_numbers = 0;
    unsigned int amount_of_even_numbers = 0;
    unsigned int amount_of_odd_numbers = 0;
    int expected_value = 0;
public:
    Circulation(unsigned int number, const std::vector <Number>& numbers, unsigned int superprize);
    Circulation(unsigned int number, const std::vector <Number>& numbers);
    unsigned int get_sum_numbers() { return sum_numbers; }
    unsigned int get_number() { return number; }
    std::vector <Number> get_numbers() { return numbers; }
    unsigned int get_amount_of_even_numbers() {return amount_of_even_numbers;}
    unsigned int get_amount_of_odd_numbers() {return amount_of_odd_numbers;}
    unsigned int get_expected_value() {return expected_value;}

    void calc_sum_numbers();
    void calc_amount_odd_and_even_numbers();
    void calc_expected_value();
};

#endif // CIRCULATION_H
