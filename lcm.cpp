#include <iostream>
#include <cstdlib>

long long lcm_naive(int a, int b) {
  // naive solution to find GCD(a,b)
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_Euclid(long long a, long long b) {
  // To find the GCD(a,b)
  if (b==0){
    return a;
  }
  else{
    long long r= (a%b);
    return gcd_Euclid(b,r);
  }
}

long long lcm_efficient(long long a, long long b) {
  if (a==0 && b==0){
    return 0;
  }
  else{
    return (long long)(a/gcd_Euclid(a,b))*b;
  }
}
int main() {
  long long a, b;
  std::cin >> a >> b;
  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_efficient(a, b) << std::endl;
  return 0;
}
