#include <iostream>
#include <lottery.h>


using namespace std;

int main()
{
    Circulation circ64(64, {2, 31, 8, 35, 20, 17});
    Circulation circ63(63, {5, 1, 33, 10, 22, 29});
    vector <Circulation> circs_for_lottery_3_of_36 = {circ63, circ64};
    Lottery loterry_6_of_36 (36, 2, 6, circs_for_lottery_3_of_36);
    loterry_6_of_36.get_info();
    return 0;
}
