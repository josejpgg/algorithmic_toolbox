#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int64_t MaxPairwiseProduct(const std::vector<int64_t> &numbers)
{
    int64_t max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

int64_t MaxPairwiseProductFast(const std::vector<int64_t> &numbers)
{
    int i_first = 0;
    for (int i = 0; i < numbers.size(); i++){
        if (numbers[i_first] < numbers[i]){
            i_first = i;
        }
    }

    int i_second = 0;
    if (i_first == 0)
    {
        i_second = 1;
    }
    for (int i = 0; i < numbers.size(); i++)
    {
        if (i_first != i && numbers[i_second] < numbers[i])
        {
            i_second = i;
        }
    }
    return numbers[i_first] * numbers[i_second];
}

int64_t MaxPairwiseProductSorting(const std::vector<int64_t> &numbers){
    std::vector<int64_t> sort_numbers = numbers;
    std::sort(sort_numbers.begin(), sort_numbers.end());

    return sort_numbers[sort_numbers.size() - 1] * sort_numbers[sort_numbers.size() - 2];
}

int main()
{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int64_t> get_rnd(2, 100);
    bool flag = false;
    while (flag == true)
    {
        int n = get_rnd(gen);
        std::vector<int64_t> numbers;
        for (int i = 0; i < n; i++){
            numbers.push_back(get_rnd(gen));
        }
        for (int i = 0; i < n; i++){
            std::cout << numbers[i] << " ";
        }
        std::cout << "\n";
        int64_t naive_result = MaxPairwiseProductSorting(numbers);
        int64_t fast_result = MaxPairwiseProductFast(numbers);

        std::cout << naive_result << "\n";
        std::cout << fast_result << "\n";

        if (naive_result == fast_result){
            std::cout << "OK\n";
        }
        else
        {
            std::cout << "ERROR\n";
            return 1;
        }
    }

    int n;
    std::cin >> n;
    std::vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductSorting(numbers) << "\n";
    return 0;
}
