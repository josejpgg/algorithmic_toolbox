#include <iostream>
#include <vector>
#include <algorithm>

void print_array_1d(std::vector<int> v_value)
{
    for (int i = 0; i < v_value.size(); i++)
    {
        std::cout << v_value[i] << " ";
    }
}

void printNonZeroCells(const std::vector<std::vector<std::vector<bool>>> &dp, int d1, int d2, int d3)
{
    for (int i = 0; i < d1; ++i)
    {
        for (int j = 0; j < d2; ++j)
        {
            for (int k = 0; k < d3; ++k)
            {
                if (dp[i][j][k] == true)
                {
                    std::cout << "Cell (" << i << ", " << j << ", " << k << ") = " << dp[i][j][k] << std::endl;
                }
            }
        }
    }
}

std::pair<bool, std::vector<std::vector<std::vector<int>>>> canPartition(const std::vector<int> &numbers, int n, int sum, int target, std::vector<std::vector<std::vector<int>>> &dp)
{
    if (sum == target && n == 0)
    {
        return {true, dp};
    }

    if (n == 0)
    {
        return {false, dp};
    }

    if (dp[n][sum][target] != -1)
    {
        return {dp[n][sum][target], dp};
    }

    bool includeCurrent = false;
    if (sum + numbers[n - 1] <= target)
    {
        auto result = canPartition(numbers, n - 1, sum + numbers[n - 1], target, dp);
        includeCurrent = result.first;
    }
    bool excludeCurrent;
    auto result = canPartition(numbers, n - 1, sum, target, dp);
    excludeCurrent = result.first;

    dp[n][sum][target] = (includeCurrent || excludeCurrent);

    std::cout << "Cell (" << n << ", " << sum << ", " << target << ") = " << dp[n][sum][target] << std::endl;

    return {dp[n][sum][target], dp};
}

bool splitIntoEqualSums(const std::vector<int> &numbers)
{
    int totalSum = 0;
    for (int num : numbers)
    {
        totalSum += num;
    }

    if (totalSum % 3 != 0)
    {
        return false;
    }

    int targetSum = totalSum / 3;

    std::vector<std::vector<std::vector<int>>> dp(numbers.size() + 1,
                                                  std::vector<std::vector<int>>(targetSum + 1,
                                                                                std::vector<int>(targetSum + 1, -1)));
    auto result = canPartition(numbers, numbers.size(), 0, targetSum, dp);
    dp = result.second;
    //std::cout << std::endl;
    //printNonZeroCells(dp);

    return result.first;
}

bool splitIntoEqualSums2(const std::vector<int> &numbers)
{
    int totalSum = 0;
    for (int num : numbers)
    {
        totalSum += num;
    }

    if (totalSum % 3 != 0)
    {
        return false;
    }

    int targetSum = totalSum / 3;
    int n = numbers.size();

    // Initialize a 3D dp table
    std::vector<std::vector<std::vector<bool>>> dp(n + 1, std::vector<std::vector<bool>>(targetSum + 1, std::vector<bool>(targetSum + 1, false)));

    // Base case: when the sum is 0, it's always possible (empty subset)
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0][0] = true;
    }

    // Fill the dp table using bottom-up approach
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= targetSum; ++j)
        {
            for (int k = 0; k <= targetSum; ++k)
            {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j >= numbers[i - 1])
                {
                    dp[i][j][k] = dp[i][j][k] || dp[i - 1][j - numbers[i - 1]][k];
                }
                if (k >= numbers[i - 1])
                {
                    dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][k - numbers[i - 1]];
                }
            }
        }
    }

    printNonZeroCells(dp, n + 1, targetSum + 1, targetSum + 1);

    return dp[n][targetSum][targetSum];
}

int main()
{
    int size;

    std::cin >> size;

    std::vector<int> v_number;
    long long number;
    for (long long i = 0; i < size; i++)
    {
        std::cin >> number;
        v_number.push_back(number);
    }

    //print_array_1d(v_number);

    //std::cout << max_gold(t_weight, v_b_weight) << std::endl;

    std::cout << (splitIntoEqualSums2(v_number) ? 1 : 0) << std::endl;

    //std::cout << split_pirate_loot(v_number) << std::endl;

    return 0;
}