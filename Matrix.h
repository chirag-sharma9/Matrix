
#ifndef MATRIX_H
#define MATRIX_H

#include <cstdlib>
#include <iostream>

typedef unsigned int uint;

using namespace std;

class Matrix {
  
private:
  
  uint rows;
  uint cols;
  double** matrixVal;
  
public:
  
  Matrix(uint rows, uint cols);                   // constructor (all elements initialized to 0)
  Matrix(double** values, int w, int h);          // constructor (must make a copy of the passed in array)
  Matrix(const Matrix & m);                       // copy constructor
  ~Matrix();                                      // destructor
  
  Matrix add(double s) const;                     // add scalar to this matrix
  Matrix add(const Matrix & m) const;             // add this matrix and another matrix
  
  Matrix subtract(double s) const;                // subtract scalar from this matrix
  Matrix subtract(const Matrix & m) const;        // subtract another matrix from this matrix
  
  Matrix multiply(double s) const;                // multiply this matrix by a scalar
  Matrix multiply(const Matrix & m) const;        // multiply this matrix by another matrix
  
  Matrix divide(double s) const;                  // divide this matrix by a scalar
  Matrix t() const;                               // transpose of this matrix
  
  const uint numRows() const;                     // returns the number of rows
  const uint numCols() const;                     // returns the number of cols
  
  double & at(uint row, uint col);                // get/set element at row,col
  const double & at(uint row, uint col) const;    // get element at row,col (when using a const object)

  double& operator()(uint row, uint col);         // Overloaded function call operator to get/set element at row,col

  Matrix& operator=(const Matrix & m);            // Overloaded copy assignment operator

};

Matrix operator+(const Matrix& m, double d);             // Overloaded addition operator to add scalar on RHS to matrix
Matrix operator+(double d, const Matrix& m);             // Overloaded addition operator to add scalar on LHS to matrix
Matrix operator+(const Matrix & m1, const Matrix & m2);  // Overloaded addition operator to add 2 matrices

Matrix operator-(const Matrix& m, double d);             // Overloaded subtraction operator to subtract scalar on RHS from matrix
Matrix operator-(double d, const Matrix& m);             // Overloaded subtraction operatot to subtract matrix from scalar on LHS
Matrix operator-(const Matrix & m1, const Matrix & m2);  // Overloaded subtraction operator to subtract one matrix from another

Matrix operator*(const Matrix & m, double d);            // Overloaded multiplication operator to multiply scalar on RHS to matrix
Matrix operator*(double d, const Matrix& m);             // Overloaded multiplication operator to multiply scalar on LHS to matrix
Matrix operator*(const Matrix & m1, const Matrix & m2);  // Overloaded multiplication operator to multiply 2 matrices

Matrix operator/(const Matrix & m, double d);            // Overloaded division operator to divide scalar on RHS from matrix
Matrix operator/(double d, const Matrix& m);             // Overloaded division operator to divide matrix from scalar on LHS

ostream& operator<<(ostream& os, const Matrix & m);      // Overloaded stream insertion operator

#endif
