#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    // Bad way to approach the problem
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
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
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << fibonacci_huge_efficient(n, m) << '\n';
}
