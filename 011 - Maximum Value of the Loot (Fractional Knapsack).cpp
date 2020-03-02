#include <iostream>
#include <vector>

using namespace std;

int get_max_index(vector<int> weights, vector<int> values) {
    int max_index = 0;
    double max_ratio = 0;
    for (int i=0; i<weights.size(); i++) {
        if (weights[i] != 0 && (double)values[i]/weights[i] > max_ratio) {
            max_index = i;
            max_ratio = (double)values[i] / weights[i];
        }
    }
    return max_index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  // write your code here
  for (int i=0; i<weights.size(); i++) {
    if (capacity == 0) return value;
    int index = get_max_index(weights, values);
    double a = min(capacity, weights[index]);
    value += a * (double)values[index] / weights[index];
    weights[index] -= a;
    capacity -= a;
  }

  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
