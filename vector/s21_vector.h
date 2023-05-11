#ifndef CPP2_S21_CONTAINERS_1_SRC_VECTOR_S21_VECTOR_H_
#define CPP2_S21_CONTAINERS_1_SRC_VECTOR_S21_VECTOR_H_

#include <iostream>
#include <limits>

namespace s21 {
template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  vector();
  explicit vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector<T> &v);
  vector(vector<T> &&v) noexcept;
  ~vector();
  vector<T> &operator=(vector<T> &&v) noexcept;

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  T *data() noexcept;

  iterator begin();
  iterator end();

  bool empty() const noexcept;
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other) noexcept;

  void bring_to_zero();
  void remove();

  template <typename... Args>
  iterator emplace(const_iterator pos, Args &&...args);
  template <typename... Args>
  void emplace_back(Args &&...args);

 private:
  value_type *arr_;
  size_type size_;
  size_type capacity_;
};

template <typename T>
inline vector<T>::vector() : arr_(nullptr), size_(0), capacity_(0) {}

template <typename T>
inline vector<T>::vector(size_type n)
    : arr_(new value_type[n]), size_(n), capacity_(n) {
  if (arr_ == nullptr) {
    throw std::bad_alloc();
  }
  for (size_type i = 0; i < n; ++i) {
    arr_[i] = T();
  }
}

template <typename T>
inline vector<T>::vector(std::initializer_list<value_type> const &items)
    : vector(items.size()) {
  for (size_type i = 0; i < size_; ++i) {
    arr_[i] = *(items.begin() + i);
  }
}

template <typename T>
inline vector<T>::vector(const vector<T> &v) : vector(v.size_) {
  for (size_type i = 0; i < size_; ++i) {
    arr_[i] = v.arr_[i];
  }
}

template <typename T>
inline vector<T>::vector(vector<T> &&v) noexcept {
  size_ = v.size_;
  v.size_ = 0;
  capacity_ = v.capacity_;
  v.capacity_ = 0;
  arr_ = v.arr_;
  v.arr_ = nullptr;
}

template <typename T>
inline vector<T>::~vector() {
  delete[] arr_;
  arr_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <typename T>
inline vector<T> &vector<T>::operator=(vector<T> &&v) noexcept {
  if (this != &v) {
    this->swap(v);
  }
  return *this;
}

template <typename T>
inline typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_ || size_ == 0) {
    throw std::out_of_range("Index out range");
  }
  return arr_[pos];
}

template <typename T>
inline typename vector<T>::reference vector<T>::operator[](size_type pos) {
  return *(arr_ + pos);
}

template <typename T>
inline typename vector<T>::const_reference vector<T>::front() {
  return *arr_;
}

template <typename T>
inline typename vector<T>::const_reference vector<T>::back() {
  return arr_[size_ - 1];
}

template <typename T>
inline typename vector<T>::iterator vector<T>::data() noexcept {
  return arr_;
}

template <typename T>
inline typename vector<T>::iterator vector<T>::begin() {
  return arr_;
}

template <typename T>
inline typename vector<T>::iterator vector<T>::end() {
  return arr_ + size_;
}

template <typename T>
inline bool vector<T>::empty() const noexcept {
  return arr_ == nullptr;
}

template <typename T>
inline typename vector<T>::size_type vector<T>::size() {
  return size_;
}

template <typename T>
inline typename vector<T>::size_type vector<T>::max_size() {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type) / 2;
}

template <typename T>
inline void vector<T>::reserve(size_type size) {
  if (size > max_size()) {
    throw std::length_error("Can't allocate memory of this size");
  }
  if (size >= size_) {
    vector<value_type> tmp(size);
    for (size_type i = 0; i < size_; ++i) {
      tmp.arr_[i] = arr_[i];
    }
    tmp.size_ = size_;
    *this = std::move(tmp);
  }
}

template <typename T>
inline typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
}

template <typename T>
inline void vector<T>::shrink_to_fit() {
  if (size_ != capacity_) {
    vector<value_type> tmp(size_);
    for (size_type i = 0; i < size_; ++i) {
      tmp.arr_[i] = arr_[i];
    }
    *this = std::move(tmp);
  }
}

template <typename T>
inline void vector<T>::clear() {
  delete[] arr_;
  arr_ = nullptr;
  size_ = 0;
}

template <typename T>
inline typename vector<T>::iterator vector<T>::insert(iterator pos,
                                                      const_reference value) {
  vector<value_type> tmp(size_ + 1);
  size_type j = 0, position = pos - this->begin();
  for (size_type i = 0; i < tmp.size_; ++i) {
    if (i == position) {
      tmp.arr_[i] = value;
    } else {
      tmp.arr_[i] = arr_[j++];
    }
  }
  *this = std::move(tmp);
  return arr_ + position;
}

template <typename T>
inline void vector<T>::erase(iterator pos) {
  vector<value_type> tmp(size_ - 1);
  size_type j = 0, position = pos - this->begin();
  for (size_type i = 0; i < size_; ++i) {
    if (i != position) {
      tmp.arr_[j++] = arr_[i];
    }
  }
  *this = std::move(tmp);
}

template <typename T>
inline void vector<T>::push_back(const_reference value) {
  if (capacity_ > size_) {
    arr_[size_] = value;
    size_ += 1;
  } else {
    vector<value_type> tmp(size_ + 1);
    for (size_type i = 0; i < size_; ++i) {
      tmp.arr_[i] = arr_[i];
    }
    tmp[size_] = value;
    *this = std::move(tmp);
  }
}

template <typename T>
inline void vector<T>::pop_back() {
  size_ -= 1;
}

template <typename T>
inline void vector<T>::swap(vector &other) noexcept {
  value_type *tmp_arr = arr_;
  size_type tmp_size = size_;
  size_type tmp_capacity = capacity_;
  arr_ = other.arr_;
  size_ = other.size_;
  capacity_ = other.capacity_;
  other.arr_ = tmp_arr;
  other.size_ = tmp_size;
  other.capacity_ = tmp_capacity;
}

template <typename T>
template <typename... Args>
inline typename vector<T>::iterator vector<T>::emplace(const_iterator pos,
                                                       Args &&...args) {
  s21::vector<value_type> tmp{args...};
  iterator position = (iterator)pos;
  for (size_t i = 0; i < tmp.size(); ++i) {
    position = insert(position, tmp[i]) + 1;
  }
  return position;
}

template <typename T>
template <typename... Args>
inline void vector<T>::emplace_back(Args &&...args) {
  emplace(this->end(), args...);
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_VECTOR_S21_VECTOR_H_
