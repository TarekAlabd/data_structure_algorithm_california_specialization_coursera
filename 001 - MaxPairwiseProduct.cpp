#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(vector<int>& numbers) {
    int n = numbers.size();

    int maxIndex1 = -1;
    for (int i=0; i<n; ++i)
        if ((maxIndex1 == -1) || (numbers[i] > numbers[maxIndex1]))
            maxIndex1 = i;


    int maxIndex2 = -1;
    for (int j=0; j<n; ++j)
        if ((j != maxIndex1) && ((maxIndex2 == -1) || (numbers[j] > numbers[maxIndex2])))
            maxIndex2 = j;

    return (((long long)(numbers[maxIndex1])) * (numbers[maxIndex2]));
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
