#include <iostream>

int get_change(int m) {
  int count = 0;
  while (m>=1) {
    if (m==1){
        m -= 1;
    }
    if (m>=10) {
        count++;
        m -= 10;
    } else if (m>=5) {
        count++;
        m -= 5;
    } else {
        count ++;
        m -= 1;
    }
  }
  return count;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
