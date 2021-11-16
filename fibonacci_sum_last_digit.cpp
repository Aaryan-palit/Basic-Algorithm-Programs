#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long Last_digit_fibonacci_fast(long long n) {
    //An good algoritm to print last digit of sum of ith fibonacci no. (Will not work for very very large numbers)

    long long a[n];
    a[0]=0;
    a[1]=1;
    for (int i = 2; i <= n; i++)
    {
        a[i]=(a[i-1]+a[i-2]);

    }

    return (a[n]-1)%10;
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

    return (r% m)-1; //returns last digit of the "sum"
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n);
    // std::cout <<Last_digit_fibonacci_fast(n+2);
    std::cout << fibonacci_huge_efficient(n,10); //We are trying to get (F(n+2)-1)%10=Last digit of Sum of n fibonacci no.
}
