#include <iostream>

int64_t MoneyChange(int64_t money)
{
    return (money/10) + ((money%10)/5) + (money%5);
}

int main()
{
    int64_t money = 0;
    std::cin >> money;
    int64_t change = 0;

    change = MoneyChange(money);
    std::cout << change;
    return 0;
}