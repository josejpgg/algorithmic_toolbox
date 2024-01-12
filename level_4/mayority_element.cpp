#include <iostream>
#include <vector>
#include <algorithm>

int mayority_element(long long n, std::vector<long long> v_element)
{
    std::sort(v_element.begin(), v_element.end());

    long long left = 0;
    long long right = n - 1;
    long long middle = (left + right) / 2;
    long long count = 1;
    long long last_count = 0;

    for (long long i = 0; i < n - 1; i++)
    {
        //std::cout << v_element[i] << " " << v_element[i + 1] << std::endl;
        if (v_element[i] == v_element[i + 1])
        {
            count++;
            //std::cout << count << std::endl;
        }
        else
        {
            if (count > last_count)
            {
                last_count = count;
            }
            count = 1;
        }
        if (count > n/2 | last_count > n/2)
        {
            return 1;
        }
    }
    if (count > last_count)
    {
        last_count = count;
    }
    //std::cout << last_count << " " << count << std::endl;
    if (last_count > n / 2)
    {
        return 1;
    }
    else {
        return 0;
    }

    /*for (int elem: v_element)
    {
        std::cout << elem << std::endl;
    }*/
}

int main()
{
    long long n = 0;
    std::cin >> n;

    std::vector<long long> v_element;
    long long order_i = 0;
    for (long long i = 0; i < n; i++)
    {
        std::cin >> order_i;
        v_element.push_back(order_i);
    }

    std::cout << mayority_element(n, v_element);

    return 0;
}