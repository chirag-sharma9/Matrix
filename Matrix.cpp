#include <iostream>
#include "Matrix.h"

using namespace std;

//Constructor initilizes all indices of matrix 'val' to 0.
Matrix::Matrix(uint rows, uint cols) : rows(rows), cols(cols), matrixVal(new double * [rows]) {
  for (uint i = 0; i < rows; i++) {
    this->matrixVal[i] = new double[cols];
  }
}

//Constructor makes a copy of the passed array.
Matrix::Matrix(double** values, int w, int h) : Matrix::Matrix (w, h) {
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      matrixVal[i][j] = values[i][j];
    }
  }
}

//Copy constructor
Matrix::Matrix(const Matrix& m) : Matrix::Matrix(m.numRows(), m.numCols()) {
  for (uint i = 0; i < rows; i++) {
    for (uint j = 0; j < cols; j++) {
      matrixVal[i][j] = m.at(i, j);
    }
  }
}

//Destructor
Matrix::~Matrix() {
  for (uint i = 0; i < rows; i++) {
    delete[] matrixVal[i];
  }

  delete[] matrixVal;
}

//Adds a scalar to this matrix
Matrix Matrix::add(double s) const {
  Matrix temp(rows, cols);
  for (uint i = 0; i < rows; i++) {
    for (uint j = 0; j < cols; j++) {
      temp.at(i, j) = this->at(i, j) + s;
    }
  }
  return temp;
}

//Adds this matrix to another matrix only if their dimensions are the same.
Matrix Matrix::add(const Matrix& m) const {
  if (this-> rows == m.numRows() && this-> cols == m.numCols()) {
    Matrix addMatrix(rows, cols);
    for (uint i = 0; i < rows; i++) {
      for (uint j = 0; j < cols; j++) {
	addMatrix.at(i, j) = this->at(i, j) + m.at(i, j);
      }
    }
    return addMatrix;
  }
  else {
    cout << "The dimensions of the 2 matrices are not the same and hence couldnt be added" << endl;
    Matrix temp2 (0, 0);
    return temp2;
  }
}

//Subtracts a scalar from this matrix
Matrix Matrix::subtract(double s) const {
  Matrix temp (rows, cols);
  for (uint i = 0; i < rows; i++) {
    for (uint j = 0; j < cols; j++) {
      temp.at(i, j) = this->at(i, j) - s;
    }
  }
  return temp;
}

//Subtracts another matrix from this matrix only if their dimensions are the same
Matrix Matrix::subtract(const Matrix& m) const {
  if(this->rows == m.numRows() && this->cols == m.numCols()) {
    Matrix subtractMatrix(rows, cols);
    for(uint i = 0; i < rows; i++) {
      for(uint j = 0; j < cols; j++) {
	subtractMatrix.at(i,j) = this->at(i, j) - m.at(i, j);
      }
    }
    return subtractMatrix;
  }
  else {
    cout << "The dimensions of the 2 matrices are not the same and hence couldnt be subtracted" << endl;
    Matrix temp2 (0, 0);
    return temp2;
  }
}

//Multiplies this matrix by a scalar
Matrix Matrix::multiply (double s) const {
  Matrix temp (rows, cols);
  for (uint i = 0; i < rows; i++) {
    for (uint j = 0; j < cols; j++) {
      temp.at(i, j) = this->at(i, j) * s;
    }
  }
  return temp;
}

//Multiplies this matrix by another matrix only if the number of columns of the first matrix match the number of rows of the second matrix
Matrix Matrix::multiply (const Matrix& m) const {
  double dotProduct{0};
  if(this->cols == m.numRows()) {
    Matrix multiplyMatrix(rows, m.numCols());
    for (uint i = 0; i < rows; i++) {
      for (uint j = 0; j < m.numCols(); j++) {
	dotProduct = 0;
	for (uint p = 0; p < cols; p++) {
	  dotProduct += this->at(i, p) * m.at(p, j);
	}
	multiplyMatrix.at(i, j) = dotProduct;
      }
    }
    return multiplyMatrix;
  }
  else {
    cout << "These 2 matrices cannot be multiplied because the number of columns of the first matrix dont match the number of rows of the second matrix" << endl;
    Matrix temp2 (0, 0);
    return temp2;
  }
}

//Divides this matrix by a scalar
Matrix Matrix::divide (double s) const {
  Matrix temp (rows, cols);
  for (uint i = 0; i < rows; i++) {
    for (uint j = 0; j < cols; j++) {
      temp.at(i, j) = this->at(i, j) / s;
    }
  }
  return temp;
}

//Transposes this matrix (switches the row and column indices of this matrix)
Matrix Matrix::t() const {
  Matrix temp (cols, rows);
  for (uint i = 0; i < cols; i++) {
    for (uint j = 0; j < rows; j++) {
      temp.at(i, j) = this->at(j, i);
    }
  }
  return temp;
}

//Returns the number of rows
const uint Matrix::numRows() const {
  return this->rows;
}

//Returns the number of columns
const uint Matrix::numCols() const {
  return this->cols;
}

//Returns element at specified row, col
double& Matrix::at(uint row, uint col) {
  return this->matrixVal[row][col];
}

//Returns element at specified row, col (when using a const object) 
const double& Matrix::at(uint row, uint col) const {
  return this->matrixVal[row][col];
}

//Overload + operator with Scalar on the RHS
Matrix operator+(const Matrix & m, double d) {
  return m.add(d);
}

//Overload + operator with Scalar on the LHS
Matrix operator+(double d, const Matrix& m) {
  return m.add(d);
}

//Overload + operator to add Matrix m1 and Matrix m2 only if their dimensions are the same
Matrix operator+(const Matrix& m1, const Matrix& m2) {
  return m1.add(m2);
}

//Overload - operator with Scalar on the RHS
Matrix operator-(const Matrix& m, double d) {
  return m.subtract(d);
}

//Overload - operator with Scalar on the LHS
Matrix operator-(double d, const Matrix& m) {
  Matrix temp (m.numRows(), m.numCols());
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      temp.at(i, j) = d - m.at(i, j);
    }
  }
  return temp;
}

//Overload - operator to subtract Matrix m2 from Matrix m1 only if their dimensions are the same
Matrix operator-(const Matrix& m1, const Matrix& m2) {
  return m1.subtract(m2);
}

//Overload * operator with Scalar on the RHS
Matrix operator*(const Matrix& m, double d) {
  return m.multiply(d);
}

//Overload * operator with Scalar on the LHS
Matrix operator*(double d, const Matrix& m) {
  return m.multiply(d);
}

//Overload * operator to multiply Matrix m1 and Matrix m2 only if the number of columns of the first matrix (m1) match the number of rows of the second matrix (m2)
Matrix operator*(const Matrix& m1, const Matrix& m2) {
  return m1.multiply(m2);
}

//Overload / operator with Scalar on the RHS
Matrix operator/(const Matrix& m, double d) {
  return m.divide(d);
}

//Overload / operator with Scalar on the LHS
Matrix operator/(double d, const Matrix& m) {
  Matrix temp (m.numRows(), m.numCols());
  for (uint i = 0; i < m.numRows(); i++) {
    for (uint j = 0; j < m.numCols(); j++) {
      temp.at(i, j) = d / m.at(i, j);
    }
  }
  return temp;
}

//Overloaded stream insertion operator
ostream& operator<<(ostream& os, const Matrix& m) {
  for (uint i = 0; i < m.numRows(); i++) {
    os << "[ ";
    for (uint j = 0; j < m.numCols(); j++) {
      os << m.at(i, j);
      if (j < m.numCols() - 1) {
	os  << ", ";
      }
    }
    os << " ]" << "\n";
  }
  return os;
}

//Overloaded function call operator
double& Matrix::operator()(uint row, uint col) {
  return this->at(row, col);
}

//Overloaded copy assignment operator
Matrix& Matrix::operator=(const Matrix& m) {
  this->matrixVal = new double * [m.numRows()];
  for (uint i = 0; i < m.numRows(); i++) {
    this->matrixVal[i] = new double [m.numCols()];
    for (uint j = 0; j < m.numCols(); j++) {
      this->at(i, j) = m.at(i, j);
    }
  }
  return *this;
}
