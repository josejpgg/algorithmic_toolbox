#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l){
    if (l % a == 0 && l % b == 0){
      return l;
    }
  }

  return (long long) a * b;
}

long long lcm_fast(int a, int b)
{
  if (a + b == 1){
    return 0;
  }

  if (a == b)
  {
    return (long long)a;
  }

  long long mult = 0;
  if (a<b){
    mult = b;
    b = a;
    a = mult;
  }

  for (long l = 1; l <= a; ++l)
  {
    mult = a * l;
    if ((mult) % b == 0)
      return mult;
  }
  return 0;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
