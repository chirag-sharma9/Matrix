#include <iostream>
#include "Matrix.h"

using namespace std;

void display(Matrix);

int main() {
  
  Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 1;
  a(1, 1) = 3;
  cout << a << endl;
  
  Matrix b(2, 2);
  b(0, 0) = 5;
  b(0, 1) = 3;
  b(1, 0) = 5;
  b(1, 1) = 6;
  cout << b << endl;
  
  Matrix c(1, 1);
  c(0, 0) = 5;
  cout << c(0,0) << endl;
  cout << endl;
  
  Matrix d = a;
  cout << d << endl;
  
  Matrix c0 = a + 5.2;
  cout << c0 << endl;
  
  Matrix c00 = 5.2 + a;
  cout << c00 << endl;
  
  Matrix c1 = a + a;
  cout << c1 << endl;
  
  Matrix c2 = a - 3.5;
  cout << c2 << endl;

  Matrix c22 = 3.5 - a;
  cout << c22 << endl;
  
  Matrix c3 = b - a;
  cout << c3 << endl;
  
  Matrix c4 = a * 2.1;
  cout << c4 << endl;
  
  Matrix c44 = 2.1 * a;
  cout << c44 << endl;
  
  Matrix c5 = a * b;
  cout << c5 << endl;
  
  Matrix c6 = a / 2.0;
  cout << c6 << endl;

  Matrix c66 = 5.0 / b;
  cout << c66 << endl;
  
  return 0;
  
}

void display (Matrix m) {
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      cout << m.at(i, j) << " ";
    }
    cout << endl;
  }
}
