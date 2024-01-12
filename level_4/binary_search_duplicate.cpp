#include <iostream>
#include <vector>
#include <cmath>

long long bi_search_dupli(long long n, std::vector<long long> v_order, long long number)
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

    long long direction = -1;
    long long index = -1;
    long long tmp = -1;

    while (right >= left)
    {
        middle = static_cast<int>(std::ceil(static_cast<double>(left + right) / 2));
        //std::cout << middle << " " << std::endl;
        if (v_order[middle] == number)
        {
            if (v_order[middle - 1] == number)
            {
                tmp = middle;
                right = middle - 1;
                //direction = 0; //left
                /*for (int i = middle - 1; i > -1; i--)
                {
                    if (v_order[i] != number)
                    {
                        return i + 1;
                    }
                    else if (i == 0)
                    {
                        return i;
                    }
                }*/
            }
            /*else if (v_order[middle + 1] == number && direction != 0)
            {
                left = middle + 1;
                tmp = middle;
                direction = 1; //right
            }*/
            else
            {
                return middle;
            }
            /*if (direction == -1 || direction == 0)
            {
                right = middle + 1;
            }
            else
            {
                left = middle + 1;
            }
            if (index == middle)
            {
                return index;
            }
            if (middle == v_order.size()-1)
            {
                return middle;
            }
            index = middle;*/
        }
        else if (v_order[middle] < number)
        {
            left = middle + 1;
            if (tmp != -1)
            {
                return tmp;
            }
            //direction = 1; //right
        }
        else if (v_order[middle] > number)
        {
            right = middle - 1;
            if (tmp != -1)
            {
                return tmp;
            }
            //direction = 0; //left
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
        std::cout << bi_search_dupli(n, v_order, v_find[i]);
    }

    return 0;
}
