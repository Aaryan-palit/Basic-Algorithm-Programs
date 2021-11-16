#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
// A naive way to approach the problem which will affect the run time and memory (a very large number cannot even be computed with this)
    if (n <= 1)
        return n;
    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }
    return sum % 10;
}

long long find_pisano(long long m) {
    // function to find the pisano period of a number m
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long fibonacci_huge_efficient(long long n, long long m) {
    // to find the Fn mod m where Fn is the nth Fibonacci term which can be a huge number
    long long rem = n % find_pisano(m);

    long long x = 0;
    long long y = 1;

    long long r = rem;

    for (int i = 1; i < rem; i++) {
        r = (x + y) % m;
        x = y;
        y = r;
    }

    return r % m;
}

int main() {
    long long n,a,b,c;
    std::cin >> n;
    a= fibonacci_huge_efficient(n,10);
    b= fibonacci_huge_efficient(n+1,10);
    c= (a*b)%10;  //Since  ((F0)^2+(F!)^2+(F2)^2+.......+(Fn)^2)= F(n)*F(n+1). And we have to do modulo10 of it to find last digit
    // std::cout << fibonacci_sum_squares_naive(n);
    std::cout << c;
}
