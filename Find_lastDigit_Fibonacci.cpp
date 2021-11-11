#include <iostream>
#include <cassert>

// Finding the last digit of any ith Fibonacci number (if input=7 then output=3, as 7th fibonacci number is 13. And if input=331 then output=9)

int get_fibonacci_last_digit_naive(int n) {
    // A naive algorithm to print last digit of an ith fibonacci no.
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int Last_digit_fibonacci_mediumfast(int n) {
    //An not so efficient algoritm to print last digit of an ith fibonacci no. (Will not work for larger numbers)

    int a[n];
    a[0]=0;
    a[1]=1;
    for (int i = 2; i <= n; i++)
    {
        a[i]=(a[i-1]+a[i-2]); //Storing the ith fibonscci term
    }

    return (a[n]%10);
}

int Last_digit_fibonacci_fast(int n) {
    //An efficient algoritm to print last digit of an ith fibonacci no. (Will work for larger numbers)

    int a[n];
    a[0]=0;
    a[1]=1;
    for (int i = 2; i <= n; i++)
    {
        a[i]=(a[i-1]+a[i-2])%10; //Storing just the last digit of the ith fibonscci term
    }

    return a[n];
}

void test_solution() {
    assert(Last_digit_fibonacci_fast(3) == 2);
    assert(Last_digit_fibonacci_fast(10) == 5);
    for (int n = 0; n < 20; ++n)
        assert((Last_digit_fibonacci_fast(n) == get_fibonacci_last_digit_naive(n)) && (Last_digit_fibonacci_fast(n) == Last_digit_fibonacci_mediumfast(n)));
}

int main() {
    int n;
    std::cin >> n;
    // test_solution();
    // // int c = get_fibonacci_last_digit_naive(n);
    int c = Last_digit_fibonacci_fast(n);
    std::cout << c << '\n';
    return 0;
}
