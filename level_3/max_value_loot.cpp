#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

double MaxValueLoot(double compound, double capacity, std::vector<double> &cost, std::vector<double> &weight)
{
    if (capacity == 0 || compound == 0)
    {
        return 0;
    }
    int index_max = 0;
    if (compound == 1)
    {
        index_max = 0;
    }
    else
    {
        double before = 0;
        double after = 0;
        for (int i = 0; i < compound; i++)
        {
            before = cost[index_max] / weight[index_max];
            after = cost[i] / weight[i];
            if (before < after)
            {
                index_max = i;
            }
        }
    }
    double amount = 0;

    if (weight[index_max] < capacity)
    {
        amount = weight[index_max];
    }
    else
    {
        amount = capacity;
    }

    double value = 0;
    double divide = (amount / weight[index_max]);

    value = cost[index_max] * divide;
    cost.erase(cost.begin() + index_max);
    weight.erase(weight.begin() + index_max);
    
    capacity = capacity - amount;
    compound = compound - 1;
    return value +
           MaxValueLoot(compound, capacity, cost, weight);
}

int main()
{
    double compound = 0;
    double capacity = 0;

    std::cin >> compound >> capacity;

    std::vector<double> v_cost;
    std::vector<double> v_weight;
    double cost = 0;
    double weight = 0;
    for (int i = 0; i < compound; i++)
    {
        std::cin >> cost >> weight;
        v_cost.push_back(cost);
        v_weight.push_back(weight);
    }
    double result = MaxValueLoot(compound, capacity, v_cost, v_weight);
    std::cout << std::fixed << std::setprecision(4) << result;
    return 0;
}