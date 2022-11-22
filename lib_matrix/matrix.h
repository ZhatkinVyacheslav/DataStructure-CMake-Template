// Copyright 2022 Marina Usova

#ifndef LIB_MATRIX_MATRIX_H_
#define LIB_MATRIX_MATRIX_H_

#include <iostream>
#include <algorithm>
#include <utility>

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

template<typename T>
class TDynamicVector {
 protected:
  size_t sz;
  T* pMem;

 public:
  explicit TDynamicVector(size_t size = 1) : sz(size) {
    if (sz == 0)
      throw std::out_of_range("Vector size should be greater than zero");
    pMem = new T[sz]();
  }

  TDynamicVector(T* arr, size_t s) : sz(s) {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }

  explicit TDynamicVector(const TDynamicVector& v) {
  }

  explicit TDynamicVector(TDynamicVector&& v) noexcept {
  }

  ~TDynamicVector() {
  }

  TDynamicVector& operator=(const TDynamicVector& v) {
    TDynamicVector temp;
    return temp;
  }

  TDynamicVector& operator=(TDynamicVector&& v) noexcept {
    TDynamicVector temp;
    return temp;
  }

  size_t size() const noexcept { return sz; }

  // indexing

  T& operator[](size_t ind) {
  }

  const T& operator[](size_t ind) const {
  }

  // indexing with control

  T& at(size_t ind) {
  }

  const T& at(size_t ind) const {
  }

  // comparisons

  bool operator==(const TDynamicVector& v) const noexcept {
  }

  bool operator!=(const TDynamicVector& v) const noexcept {
  }

  // scalar operations

  TDynamicVector operator+(T val) {
  }

  TDynamicVector operator-(double val) {
  }

  TDynamicVector operator*(double val) {
  }

  // vector operations

  TDynamicVector operator+(const TDynamicVector& v) {
  }

  TDynamicVector operator-(const TDynamicVector& v) {
  }

  T operator*(const TDynamicVector& v) noexcept(noexcept(T())) {
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // input / output


  friend std::istream& operator>>(std::istream& istr, TDynamicVector& v) {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i];
    return istr;
  }

  friend std::ostream& operator<<(std::ostream& ostr, const TDynamicVector& v) {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' ';
    return ostr;
  }
};

template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>> {
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;

 public:
  explicit TDynamicMatrix(size_t s = 1)
    : TDynamicVector<TDynamicVector<T>>(s) {
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  // comparison

  bool operator==(const TDynamicMatrix& m) const noexcept {
  }

  // matrix-scalar operations

  TDynamicVector<T> operator*(const T& val) {
  }

  // matrix-vector operations

  TDynamicVector<T> operator*(const TDynamicVector<T>& v) {
  }

  // matrix-matrix operations

  TDynamicMatrix operator+(const TDynamicMatrix& m) {
  }

  TDynamicMatrix operator-(const TDynamicMatrix& m) {
  }

  TDynamicMatrix operator*(const TDynamicMatrix& m) {
  }

  // input / output

  friend std::istream& operator>>(std::istream& istr, TDynamicMatrix& v) {
  }

  friend std::ostream& operator<<(std::ostream& ostr, const TDynamicMatrix& v) {
  }
};

#endif  // LIB_MATRIX_MATRIX_H_
