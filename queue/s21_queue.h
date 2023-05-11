#ifndef CPP2_S21_CONTAINERS_1_SRC_QUEUE_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_1_SRC_QUEUE_S21_QUEUE_H_

#include <iostream>

namespace s21 {
template <typename T>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  queue() noexcept;
  queue(std::initializer_list<value_type> const &items) noexcept;
  queue(const queue &other);
  queue(queue &&other) noexcept;

  ~queue();

  queue &operator=(const queue &other) noexcept;
  queue &operator=(queue &&other) noexcept;

  const_reference front();
  const_reference back();
  void pop();
  void push(const_reference value) noexcept;
  bool empty() const noexcept;
  size_type size() const noexcept;
  void swap(queue<T> &other) noexcept {
    Node_ *tmp_head = head_;
    Node_ *tmp_tail = tail_;
    size_t tmp_size = other.size_;
    if (head_ && other.head_) {
      head_ = other.head_;
      other.head_ = tmp_head;
    }
    if (tail_ && other.tail_) {
      tail_ = other.tail_;
      other.tail_ = tmp_tail;
    }
    other.size_ = size_;
    size_ = tmp_size;
  }

  template <typename... Args>
  void emplace_back(Args &&...args) {
    for (auto elem : {std::forward<Args>(args)...}) {
      push(elem);
    }
  }

 private:
  typedef struct Node_ {
    value_type value_;
    Node_ *ptr_prev_;

    explicit Node_(value_type value) noexcept
        : value_(value), ptr_prev_(nullptr) {}
  } Node_;

  Node_ *head_;
  Node_ *tail_;
  size_type size_;
  void Clear_();
  value_type At_(int i) const;
};

template <typename T>
inline queue<T>::queue() noexcept : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
inline queue<T>::queue(const std::initializer_list<value_type> &items) noexcept
    : head_(nullptr), tail_(nullptr), size_(0) {
  for (value_type i : items) {
    push(i);
  }
}

template <typename T>
inline queue<T>::queue(const queue<T> &other)
    : head_(nullptr), tail_(nullptr), size_(0) {
  *this = other;
}

template <typename T>
inline queue<T>::queue(queue<T> &&other) noexcept
    : head_(nullptr), tail_(nullptr), size_(0) {
  *this = std::move(other);
}

template <typename T>
inline queue<T>::~queue() {
  Clear_();
}

template <typename T>
inline queue<T> &queue<T>::operator=(const queue<T> &other) noexcept {
  if (this != &other) {
    Clear_();
    size_type i = 0;
    while (i < other.size_) {
      push(other.At_(i));
      i++;
    }
  }
  return *this;
}

template <typename T>
inline queue<T> &queue<T>::operator=(queue<T> &&other) noexcept {
  if (this != &other) {
    Clear_();
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;
    other.tail_ = nullptr;
    other.head_ = nullptr;
    other.size_ = 0;
  }
  return *this;
}

template <typename T>
inline void queue<T>::pop() {
  if (!head_) throw std::logic_error("queue is empty");
  Node_ *prev_node = head_->ptr_prev_;
  delete head_;
  head_ = prev_node;
  --size_;
}

template <typename T>
inline void queue<T>::push(const_reference value) noexcept {
  Node_ *new_node = new Node_(value);
  if (!head_) {
    head_ = new_node;
  } else if (!tail_) {
    head_->ptr_prev_ = new_node;
    tail_ = new_node;
  } else {
    tail_->ptr_prev_ = new_node;
    tail_ = new_node;
  }
  ++size_;
}

template <typename T>
inline bool queue<T>::empty() const noexcept {
  return size_ == 0;
}

template <typename T>
inline typename queue<T>::const_reference queue<T>::front() {
  if (!head_) throw std::logic_error("queue is empty");
  return head_->value_;
}

template <typename T>
inline typename queue<T>::const_reference queue<T>::back() {
  if (!tail_) throw std::logic_error("queue is empty");
  return tail_->value_;
}

template <typename T>
inline typename queue<T>::value_type queue<T>::At_(int i) const {
  if (i < 0 || i >= (int)size_) throw std::out_of_range("Index out of range");
  value_type result = T();
  Node_ *tmp_head = head_;
  for (int j = 0; j < i; j++) {
    tmp_head = tmp_head->ptr_prev_;
  }
  result = tmp_head->value_;
  return result;
}

template <typename T>
inline void queue<T>::Clear_() {
  while (head_) {
    pop();
  }
  if (tail_) tail_ = nullptr;
}

template <typename T>
inline typename queue<T>::size_type queue<T>::size() const noexcept {
  return size_;
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_QUEUE_S21_QUEUE_H_
