#include <iostream>
#include <random>

int64_t gcd_naive(int64_t a, int64_t b)
{
  int64_t current_gcd = 1;
  for (int64_t d = 2; d <= a && d <= b; d++)
  {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int64_t gcd_fast(int64_t a, int64_t b)
{
  if (a == 0 or b ==0)
    return 1;

  int64_t remainder = 1;

  while (remainder != 0){
    remainder = a % b;
    a = b;
    b = remainder;
  }

  return a;
}

int main() {

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int64_t> get_rnd(1000, 1000000);
  bool flag = false;
  while (flag == true)
  {
    int a = get_rnd(gen);
    int b = get_rnd(gen);
    std::cout << a << " " << b << std::endl;
    if (gcd_naive(a, b) != gcd_fast(a, b))
    {
      std::cout << "ERROR" << std::endl;
      return 1;
    }
  }

  int64_t a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
