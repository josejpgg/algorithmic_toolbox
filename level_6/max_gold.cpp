#include <iostream>
#include <vector>
#include <algorithm>

void print_array_2d(std::vector<std::vector<long long>> v_value, long long row, long long col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << v_value[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void print_array_1d(std::vector<long long> v_value)
{
    for (int i = 0; i < v_value.size(); i++)
    {
        std::cout << v_value[i] << " ";
    }
}

long long max_gold(long long t_weight, std::vector<long long> v_b_weight)
{
    std::vector<std::vector<long long>> v_work;
    v_work.resize(v_b_weight.size() + 1, std::vector<long long>(t_weight + 1, 0));

    for (int i = 1; i < v_b_weight.size() + 1; i++)
    {
        for (int j = 1; j < t_weight + 1; j++)
        {
            v_work[i][j] = 1;
        }
    }

    long long val;

    for (int i = 1; i < v_b_weight.size() + 1; i++)
    {
        for (int j = 1; j < t_weight + 1; j++)
        {
            v_work[i][j] = v_work[i-1][j];
            if (v_b_weight[i - 1] <= j)
            {
                val = v_work[i - 1][j - v_b_weight[i - 1]] + v_b_weight[i - 1];
                if (v_work[i][j] < val)
                {
                    v_work[i][j] = val;
                }
            }
        }
    }

    //print_array_2d(v_work, v_b_weight.size() + 1, t_weight + 1);
    //std::cout << std::endl;

    return v_work[v_b_weight.size()][t_weight];
}

int main()
{
    long long t_weight;
    int n_bar;

    std::cin >> t_weight;
    std::cin >> n_bar;

    std::vector<long long> v_b_weight;
    long long b_weight;
    for (long long i = 0; i < n_bar; i++)
    {
        std::cin >> b_weight;
        v_b_weight.push_back(b_weight);
    }

    /*for (int j = 0; j < v_b_weight.size(); j++)
    {
        std::cout << v_b_weight[j] << " ";
    }*/

    std::cout << max_gold(t_weight, v_b_weight) << std::endl;

    return 0;
}