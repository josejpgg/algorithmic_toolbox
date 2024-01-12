#include <iostream>
#include <vector>

int bigger_change(std::vector<int> v_money, int money)
{
    if (v_money[0] < money)
    {
        return v_money[0];
    }
    int result = 0;
    for (int num : v_money)
    {
        if (num <= money)
        {
            result = num;
            break;
        }
    }
    return result;
}

int dp_change_money(int money)
{
    std::vector<int> v_money;
    v_money.push_back(4);
    v_money.push_back(3);
    v_money.push_back(1);

    std::vector<std::vector<int>> v_change;

    int flag = 0;
    int coin = 1;
    int change = -1;

    v_change.push_back({money - v_money[0], money - v_money[1], money - v_money[2]});

    if (v_change[0][0] == 0 || v_change[0][1] == 0 || v_change[0][2] == 0)
    {
        return coin;
    }

    while (flag < 3)
    {

        v_change[0][flag] = v_change[0][flag] - bigger_change(v_money, v_change[0][flag]);

        if (v_change[0][flag] == 0)
        {
            coin++;
            break;
        }
        flag++;
        if (flag == 3)
        {
            flag = 0;
            coin++;
        }
    }

    /*for (int64_t i = 0; i < v_change.size(); i++)
    {
        for (int64_t j = 0; j < v_change[i].size(); j++)
        {
            std::cout << v_change[i][j] << std::endl;
        }
    }*/
    return coin;
}

int main()
{
    int64_t money = 0;
    std::cin >> money;
    int64_t change = 0;

    change = dp_change_money(money);
    std::cout << change;
    return 0;
}