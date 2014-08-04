#include <iostream>

int main()
{
    float total = 0.0;
    float tip_percentage = 0.0;
    float tip_total = 0.0;

    std::cout << "Please enter the meal total ";
    std::cin >> total;
    std::cout << std::endl << "Please enter the desired tip percentage ";
    std::cin >> tip_percentage;

    tip_percentage /= 100;
    tip_total = total * tip_percentage;
    std::cout << std::endl << "You need to leave " << tip_total << " dollars";

    return 0;
}
