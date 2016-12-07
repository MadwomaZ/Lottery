#include "number.h"

Number::Number(unsigned int number) : number(number)
{
    if (number % 2 == 0)
    {
        an_even = true;
    }
    else
    {
        an_even = false;
    }
}

//void Number::set_circulations_with_this_number(std::vector<Circulation> &circulations)
//{
//    for (std::size_t i= 0; i < circulations.size(); i++)
//    {
//        std::vector <Number> circ_numbers = circulations[i].get_numbers();
//        for (std::size_t i = 0; i < circ_numbers.size(); i++)
//        {
//            if (circ_numbers[i] == number)
//            {
//                circulations_with_this_number.push_back(circulations[i]);
//                frequency++;
//                continue;
//            }
//        }
//    }

//}

void Number::get_info()
{

}
