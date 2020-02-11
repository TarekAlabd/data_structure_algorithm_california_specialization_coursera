#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
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

long long get_pisano_period_length(long long m) {
    long long f1 = 0, f2 = 1, f_sum = f1 + f2;
    for (int i=0; i < m*m; i++) {
        f_sum = (f1 + f2)%m;
        f1 = f2;
        f2 = f_sum;
        if (f1 == 0 && f2 == 1) return i+1;
    }
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    long long rem = n % get_pisano_period_length(m);

    long long f1 = 0, f2 = 1, f_sum = rem;

    for (int i = 1; i < rem; i++) {
        f_sum = (f1+f2)%m;
        f1 = f2;
        f2 = f_sum;
    }

    return f_sum % m;
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
