#include <iostream>
#include <vector>
#include <algorithm>

int64_t car_fueling(int64_t distance, int64_t mile, std::vector<int> v_stop, int64_t begin)
{
    if (distance < mile)
    {
        return 0;
    }

    if (begin >= distance)
    {
        return 0;
    }

    if (begin == 0)
    {
        for (int i = 1; i < v_stop.size(); i++)
        {
            if (v_stop[i] - v_stop[i - 1] > (begin + mile))
            {
                return -1;
            }
        }
    }
    
    int index = 0;
    for (int i = 0; i < v_stop.size(); i++)
    {
        if (v_stop[i] > (begin + mile))
        {
            index = i - 1;
            break;
        }
    }
    if (index == 0)
    {
        return 0;
    }
    begin = v_stop[index];
    v_stop.erase(v_stop.begin() + index);

    return 1 +
           car_fueling(distance, mile, v_stop, begin);
}

int main()
{
    int64_t distance = 0;
    int64_t mile = 0;
    int64_t n_stop = 0;

    std::cin >> distance;
    std::cin >> mile;
    std::cin >> n_stop;

    std::vector<int> v_stop;
    int stop;
    int i = 1;

    v_stop.push_back(0);
    for (int i = 0; i < n_stop; ++i)
    {
        if (std::cin >> stop)
        {
            v_stop.push_back(stop);
        }
    }
    v_stop.push_back(distance);
    std::sort(v_stop.begin(), v_stop.end());
    int64_t result = car_fueling(distance, mile, v_stop, 0);
    std::cout << result << std::endl;
    return 0;
}
