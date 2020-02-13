#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous%10;
        previous = current;
        current = tmp_previous + current%10;
        sum += current * current;
    }

    return sum % 10;
}

long long get_fibonacci_fast(long long n) {
    if (n <= 1)
        return n;

    long long f1=0, f2=1, f_sum = 0;
    for (long i=2; i<=n; i++) {
        f_sum = f1 + f2;
        f1 = f2;
        f2 = f_sum;
    }
    return f_sum;
}

int fibonacci_sum_square_fast(long long n) {
    if (n <= 1)
        return n;

    long long current = get_fibonacci_fast(n % 60);
    long long next = get_fibonacci_fast((n+1) % 60);

    return ((current % 10) * (next % 10) % 10);
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_square_fast(n);
}
