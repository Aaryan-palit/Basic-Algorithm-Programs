#include <iostream>

int gcd_naive(int a, int b) {
  // this a naive algorithm to find gcd of two number a,b
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_Euclid(int a, int b) {
  // this a good algorithm to find gcd of two number a,b by Euclid's Algo
  // Euclid algo is: 1) GCD(a,b)=GCD(a,a%b) and 2) GCD(a,0)=a
  if (b==0){
    return a;
  }
  else{
    int r= (a%b);
    return gcd_Euclid(b,r);
  }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  // std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_Euclid(a, b) << std::endl;
  return 0;
}
