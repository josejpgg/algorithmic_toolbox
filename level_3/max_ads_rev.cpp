#include <iostream>
#include <vector>
#include <algorithm>

long long max_ads_rev(std::vector<int> v_click, std::vector<int> v_price)
{
    long long result = 0;

    std::sort(v_click.begin(), v_click.end(), std::greater<int>());
    std::sort(v_price.begin(), v_price.end(), std::greater<int>());

    for (int i = 0; i < v_click.size(); i++)
    {
        result = result + ((long long)v_click[i] * (long long)v_price[i]);
    }

    return result;
}

int main()
{
    int n_element = 0;
    std::cin >> n_element;

    std::vector<int> v_click;
    int click;

    for (int i = 0; i < n_element; i++)
    {
        if (std::cin >> click)
        {
            v_click.push_back(click);
        }
    }
    
    std::vector<int> v_price;
    int price;

    for (int i = 0; i < n_element; i++)
    {
        if (std::cin >> price)
        {
            v_price.push_back(price);
        }
    }

    std::cout << max_ads_rev(v_click, v_price) << std::endl;
    return 0;
}