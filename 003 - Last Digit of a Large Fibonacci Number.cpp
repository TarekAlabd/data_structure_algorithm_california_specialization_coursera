#include <iostream>

using std::cin;
using std::cout;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int f1, f2, f_sum;
    f1 = 0;
    f2 = 1;
    for (int i=2; i<=n; i++) {
        f_sum = (f1 + f2)%10;
        f1 = f2%10;
        f2 = f_sum;
    }

    return f_sum;
}

int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    cout << c << '\n';
}
