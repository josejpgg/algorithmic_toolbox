#include <iostream>
#include <vector>
#include <algorithm>

int optimal_sequence(int n)
{
    std::vector<int> sequence;
    std::vector<int> count(n + 1, 1);

    count[1] = 0;
    count[2] = 1;
    count[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        count[i] = count[i - 1] + 1;
        if (i % 2 == 0)
        {
            count[i] = std::min(count[i / 2] + 1, count[i]);
        }
        if (i % 3 == 0)
        {
            count[i] = std::min(count[i / 3] + 1, count[i]);
        }
    }

    /*for (size_t i = 0; i < count.size(); i++)
    {
        std::cout << count[i] << " ";
    }
    std::cout << std::endl;*/

    return count[n];
}

int main()
{
    int64_t money = 0;
    std::cin >> money;
    int64_t change = 0;

    int sequence = optimal_sequence(money);
    std::cout << sequence << std::endl;
  
    return 0;
}