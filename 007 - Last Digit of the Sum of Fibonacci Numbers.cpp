#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int get_fibonacci_last_digit_fast(long long n) {
    if (n <= 1)
        return n;

    int f1 = 0;
    int f2 = 1;
    int f_sum;

    for (int i=0; i<n-1; i++) {
        f_sum = (f1+f2)%10;
        f1 = f2;
        f2 = f_sum;
    }

    return f_sum % 10;
}

int fibonacci_sum_fast(long long n) {
    int new_n = (n + 2) % 60;
    int new_last_digit = get_fibonacci_last_digit_fast(new_n);

    if (new_last_digit == 0)
        return 9;
    else
        return new_last_digit - 1;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
