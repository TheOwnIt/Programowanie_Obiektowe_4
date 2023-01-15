#include <iostream>
#include <stdexcept>

using namespace std;

class NegativeNumberException : public std::exception {
 public:
  const char* what() const throw() {
    return "Funkcja silni nie moze byc wywolana dla liczby ujemnej";
  }
};

unsigned long long factorial(int n) {
  if (n < 0) {
    throw NegativeNumberException();
  }
  unsigned long long result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

int main() {
  try {
    int n;
    cout << "Podaj liczbe: ";
    cin >> n;
    cout << "Silnia z " << n << " to " << factorial(n) << endl;
  } catch (const NegativeNumberException& e) {
    cerr << e.what() << endl;
  }
	system("pause");
  return 0;
}
