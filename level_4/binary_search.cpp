#include <iostream>
#include <vector>

long long binary_search(long long n, std::vector<long long> v_order, long long number)
{
    long long left = 0;
    long long right = n - 1;
    long long middle = 0;

    if (number > v_order[right])
    {
        return -1;
    }
    else if (number < v_order[left])
    {
        return -1;
    }
    long long tmp = -1;
    while (right >= left)
    {
        middle = (left + right) / 2;
        if (v_order[middle] == number)
        {
            return middle;
        }
        else if (v_order[middle] < number)
        {
            tmp = middle + 1;
            left = tmp;
        }
        else
        {
            tmp = middle - 1;
            right = tmp;
        }
    }
    return -1;
}

int main()
{
    long long n = 0;
    std::cin >> n;

    std::vector<long long> v_order;
    long long order_i = 0;
    for (long long i = 0; i < n; i++)
    {
        std::cin >> order_i;
        v_order.push_back(order_i);
    }

    long long m = 0;
    std::cin >> m;

    std::vector<long long> v_find;
    long long find_i = 0;
    for (long long i = 0; i < m; i++)
    {
        std::cin >> find_i;
        v_find.push_back(find_i);
    }

    for (long long i = 0; i < m; i++)
    {
        if (i > 0)
        {
            std::cout << " ";
        }
        std::cout << binary_search(n, v_order, v_find[i]);
    }

    return 0;
}