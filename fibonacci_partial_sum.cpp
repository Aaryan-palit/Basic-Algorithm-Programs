#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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
    long long rem = (n+2) % find_pisano(m);

    int x = 0;
    int y = 1;

    long long r = rem;

    for (int i = 1; i < rem; i++) {
        r = (x + y) % m;
        x = y;
        y = r;
    }
    if(r == 0){
        return 9;
    }

    return (r% m)-1; //returns returns the last digit of sum of nth fibonacci
}

int main() {
    long long n,m;
    std::cin >> m >>n;
    // std::cin >> m;
    // std::cout << fibonacci_sum_naive(n);
    // std::cout <<Last_digit_fibonacci_fast(n+2);
    long long a=fibonacci_huge_efficient(n,10);
    long long b=fibonacci_huge_efficient(m-1,10);
    // long long c=abs(a-b)%10;
    long long c=(a-b);
    c= ( c%10 + 10) %10;
    std::cout << c; //We are trying to get (F(n+2)-1)%10=Last digit of Sum of n fibonacci no.
}