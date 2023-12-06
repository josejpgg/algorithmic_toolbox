#include <iostream>
#include <vector>
#include <string>

//0,1,1,2,3,5,8,13,21

int64_t get_fibonacci_last_digit_naive(int64_t n)
{
    if (n <= 1)
        return n;

    int64_t previous = 0;
    int64_t current = 1;

    for (int64_t i = 0; i < n - 1; ++i)
    {
        int64_t tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    std::cout << current << std::endl;
    return current % 10;
}

int64_t get_fibonacci_last_digit_fast(int64_t n)
{
    std::vector<int64_t> numbers;

    numbers.push_back(0);
    numbers.push_back(1);

    if (n <= 1)
        return numbers[n];

    for (int64_t i = 2; i <= n; i++)
    {
        numbers.push_back((numbers[i - 1] + numbers[i - 2]) % 10);
    }

    std::string num_str = std::to_string(numbers[n]);

    return numbers[n];
}

int main() {
    int64_t n;
    std::cin >> n;

    //std::cout << get_fibonacci_last_digit_naive(n) << '\n';
    std::cout << get_fibonacci_last_digit_fast(n) << '\n';

    return 0;
}
