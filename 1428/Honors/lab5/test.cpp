#include <iostream>

int main()
{
    float daily1 = 0, daily2 = 0, daily3 = 0;
    float test1 = 0, test2 = 0;
    float average;
    const int DAILY_QUANTITY = 3;
    const int TEST_QUANTITY = 2;
    const float DAILY_WEIGHT = 0.4;
    const float TEST_WEIGHT = 0.6;

    std::cout << "Please enter the three daily grades ";
    std::cin >> daily1 >> daily2 >> daily3;
    std::cout << std::endl << "Please enter the two test grades ";
    std::cin >> test1 >> test2;

    daily1 += daily2 + daily3;
    daily1 /= DAILY_QUANTITY;
    daily1 *= DAILY_WEIGHT;

    test1 += test2;
    test1 /= TEST_QUANTITY;
    test1 *= TEST_WEIGHT;

    average = test1 + daily1;

    std::cout << "Average is: " << average;
    return 0;

}
