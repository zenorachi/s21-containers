#ifndef CPP2_S21_CONTAINERS_SRC_LIST_LIST_H_
#define CPP2_S21_CONTAINERS_SRC_LIST_LIST_H_

#include <iostream>
#include <limits>

namespace s21 {
template <typename T>
class list {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  // CONSTRUCTORS
  list() noexcept;
  explicit list(size_type n);
  list(std::initializer_list<value_type> const& items) noexcept;
  list(const list& other) noexcept;
  list(list&& other) noexcept;

  // DESTRUCTOR
  ~list();
  // BASIC METHODS
  void push_front(const_reference data) noexcept;
  void push_back(const_reference data) noexcept;
  void pop_front() noexcept;
  void pop_back() noexcept;
  const_reference front() const noexcept;
  const_reference back() const noexcept;
  void swap(list& other) noexcept;
  void sort() noexcept;
  void merge(list& other) noexcept;
  void reverse() noexcept;
  void unique() noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  bool empty() const noexcept;
  void clear() noexcept;

  // OVERLOAD OPERATORS
  list<T>& operator=(const list<T>& other) noexcept;
  list<T>& operator=(list<T>&& other) noexcept;

 private:
  typedef struct Node_ {
    value_type value_;
    Node_* ptr_next_;
    Node_* ptr_prev_;
    explicit Node_(value_type value) noexcept
        : value_(value), ptr_next_(nullptr), ptr_prev_(nullptr) {}
  } Node_;

  Node_* head_;
  Node_* tail_;
  Node_* fake_;
  size_type size_;

  void InitFake_() noexcept;
  void MergeSort_(list<T>& left, list<T>& right, list<T>& result) noexcept;

  class ConstIterator {
   public:
    ConstIterator() noexcept { ptr_ = nullptr; };
    explicit ConstIterator(list::Node_* node) noexcept { ptr_ = node; };
    ConstIterator(const ConstIterator& other) noexcept { ptr_ = other.ptr_; };
    ~ConstIterator() = default;

    bool operator!=(const ConstIterator& other) const noexcept {
      return ptr_ != other.ptr_;
    }

    bool operator==(const ConstIterator& other) const noexcept {
      return ptr_ == other.ptr_;
    }

    ConstIterator& operator=(const ConstIterator& other) noexcept {
      if (this != &other) ptr_ = other.ptr_;
      return *this;
    }

    const_reference operator*() noexcept { return ptr_->value_; }

    ConstIterator operator++(int) noexcept {
      ConstIterator tmp(*this);
      Operation_(true);
      return tmp;
    }

    ConstIterator& operator++() noexcept {
      Operation_(true);
      return *this;
    }

    ConstIterator operator--(int) noexcept {
      ConstIterator tmp(*this);
      Operation_(false);
      return tmp;
    }

    ConstIterator& operator--() noexcept {
      Operation_(false);
      return *this;
    }

    ConstIterator operator+(size_type n) noexcept {
      auto it_tmp = *this;
      while (n-- > 0) it_tmp.Operation_(true);
      return it_tmp;
    }

    ConstIterator operator-(size_type n) noexcept {
      auto it_tmp = *this;
      while (n-- > 0) it_tmp.Operation_(false);
      return it_tmp;
    }

    ConstIterator& operator+=(size_type n) noexcept {
      while (n-- > 0) Operation_(true);
      return *this;
    }

    ConstIterator& operator-=(size_type n) noexcept {
      while (n-- > 0) Operation_(false);
      return *this;
    }

    Node_* GetNode_() const noexcept { return ptr_; }

   protected:
    Node_* ptr_;
    void Operation_(bool isPlus) noexcept {
      if (isPlus)
        ptr_ = ptr_->ptr_next_;
      else
        ptr_ = ptr_->ptr_prev_;
    }
  };

  class Iterator : public ConstIterator {
   public:
    Iterator() noexcept : ConstIterator(){};
    explicit Iterator(Node_* node) noexcept : ConstIterator(node){};
    Iterator(const Iterator& other) noexcept : ConstIterator(other){};
    ~Iterator() = default;

    Iterator& operator=(const Iterator& other) noexcept {
      if (this != &other) this->ptr_ = other.ptr_;
      return *this;
    }

    reference operator*() noexcept { return (reference)this->ptr_->value_; }
  };

 public:
  using iterator = Iterator;
  using const_iterator = ConstIterator;

  iterator begin() const noexcept { return Iterator(head_ ? head_ : fake_); }
  iterator end() const noexcept { return Iterator(fake_); }
  iterator insert(iterator pos, const_reference value) noexcept;

  template <typename... Args>
  iterator emplace(const_iterator pos, Args&&... args) {
    Node_* pos_node = GetIteratorNode_(pos);
    Iterator it(pos_node);
    for (auto elem : {std::forward<Args>(args)...}) {
      insert(it, elem);
    }
    --it;
    return it;
  }

  template <typename... Args>
  void emplace_back(Args&&... args) {
    const_iterator it = end();
    emplace(it, std::forward<Args>(args)...);
  }
  template <typename... Args>
  void emplace_front(Args&&... args) {
    for (auto elem : {std::forward<Args>(args)...}) {
      push_front(elem);
    }
  }

  void erase(iterator pos) noexcept;
  void splice(iterator pos, list& other) noexcept;

 private:
  Node_* GetIteratorNode_(const_iterator iter) const noexcept {
    return iter.GetNode_();
  }
};

template <typename T>
inline list<T>::list() noexcept : head_(nullptr), tail_(nullptr), size_(0) {
  InitFake_();
}

template <typename T>
inline list<T>::list(list::size_type n)
    : head_(nullptr), tail_(nullptr), size_(0) {
  if (n <= 0) throw std::out_of_range("Index out of range");
  InitFake_();
  while (n-- > 0) push_back(T());
}

template <typename T>
inline list<T>::list(std::initializer_list<value_type> const& items) noexcept
    : head_(nullptr), tail_(nullptr), size_(0) {
  InitFake_();
  for (value_type i : items) {
    push_back(i);
  }
}

template <typename T>
inline list<T>::list(const list& other) noexcept
    : head_(nullptr), tail_(nullptr), size_(0) {
  InitFake_();
  *this = other;
}

template <typename T>
inline list<T>::list(list&& other) noexcept {
  if (this != &other) {
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;
    fake_ = other.fake_;
    other.size_ = 0;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.fake_ = nullptr;
    /*
    ORIGINAL LIST WORKS LIKE THIS
    */
    other.InitFake_();
  }
}

template <typename T>
inline list<T>::~list() {
  clear();
  delete fake_;
}

template <typename T>
inline void list<T>::push_front(const_reference data) noexcept {
  auto* new_ptr = new Node_(data);
  if (!head_) {
    head_ = new_ptr;
    head_->ptr_prev_ = fake_;
    head_->ptr_next_ = fake_;
    fake_->ptr_next_ = head_;
    fake_->ptr_prev_ = head_;
  } else if (!tail_) {
    tail_ = head_;
    tail_->ptr_next_ = fake_;
    tail_->ptr_prev_ = new_ptr;
    fake_->ptr_prev_ = tail_;
    fake_->ptr_next_ = new_ptr;
    new_ptr->ptr_next_ = tail_;
    head_ = new_ptr;
  } else {
    new_ptr->ptr_next_ = head_;
    head_ = new_ptr;
    fake_->ptr_next_ = head_;
    head_->ptr_prev_ = fake_;
  }
  ++size_;
  fake_->value_ = size_;
}

template <typename T>
inline void list<T>::push_back(const_reference data) noexcept {
  auto* new_ptr = new Node_(data);
  if (!head_) {
    head_ = new_ptr;
    head_->ptr_next_ = fake_;
    head_->ptr_prev_ = fake_;
    fake_->ptr_prev_ = head_;
    fake_->ptr_next_ = head_;
  } else if (!tail_) {
    tail_ = new_ptr;
    tail_->ptr_next_ = fake_;
    tail_->ptr_prev_ = head_;
    fake_->ptr_prev_ = tail_;
    head_->ptr_next_ = tail_;
  } else {
    new_ptr->ptr_prev_ = tail_;
    tail_->ptr_next_ = new_ptr;
    tail_ = new_ptr;
    fake_->ptr_prev_ = tail_;
    tail_->ptr_next_ = fake_;
  }
  ++size_;
  fake_->value_ = size_;
}

template <typename T>
inline void list<T>::pop_front() noexcept {
  if (head_) {
    Node_* head_rm = head_;
    if (head_->ptr_next_ != fake_) {
      head_ = head_->ptr_next_;
    } else {
      head_ = nullptr;
    }

    if (head_rm->ptr_next_) delete head_rm;

    if (size_ == 2) {
      head_ = tail_;
      fake_->ptr_next_ = head_;
      fake_->ptr_prev_ = head_;
      head_->ptr_next_ = fake_;
      head_->ptr_prev_ = fake_;
      tail_ = nullptr;
    }
    --size_;
    fake_->value_ = size_;
  }
}

template <typename T>
inline void list<T>::pop_back() noexcept {
  if (tail_) {
    Node_* tail_rm = tail_;
    if (tail_->ptr_prev_ != fake_) {
      tail_ = tail_->ptr_prev_;
    } else {
      tail_ = nullptr;
    }

    if (tail_rm->ptr_prev_) delete tail_rm;

    if (size_ == 2) {
      fake_->ptr_next_ = head_;
      fake_->ptr_prev_ = head_;
      head_->ptr_next_ = fake_;
      head_->ptr_prev_ = fake_;
      tail_ = nullptr;
    }
    --size_;
    fake_->value_ = size_;
  }
}

template <typename T>
inline typename list<T>::const_reference list<T>::front() const noexcept {
  return head_ ? head_->value_ : fake_->value_;
}

template <typename T>
inline typename list<T>::const_reference list<T>::back() const noexcept {
  return tail_ ? tail_->value_ : front();
}

template <typename T>
inline void list<T>::swap(list& other) noexcept {
  Node_* tmp_head = head_;
  Node_* tmp_tail = tail_;
  Node_* tmp_fake = fake_;
  size_t tmp_size = other.size_;
  if (other.head_ || head_) {
    head_ = other.head_;
    other.head_ = tmp_head;
  }
  if (other.tail_ || tail_) {
    tail_ = other.tail_;
    other.tail_ = tmp_tail;
  }
  fake_ = other.fake_;
  other.fake_ = tmp_fake;
  other.size_ = size_;
  size_ = tmp_size;
}

template <typename T>
inline void list<T>::sort() noexcept {
  if (size_ <= 1) return;

  list<T> left, right;
  int n = size_ / 2;

  for (int i = 0; i < n; i++) {
    auto left_iter = begin() + i;
    left.push_back(*left_iter);
  }
  for (int j = n; j < (int)size_; j++) {
    auto right_iter = begin() + j;
    right.push_back(*right_iter);
  }

  left.sort();
  right.sort();

  MergeSort_(left, right, *this);
}

template <typename T>
inline void list<T>::merge(list& other) noexcept {
  if (this != &other) {
    list<T> tmp;
    tmp = *this;
    MergeSort_(tmp, other, *this);
    other.clear();
  }
}

template <typename T>
inline void list<T>::reverse() noexcept {
  /*
  NEED TO CHECK FAKE NODE
  */
  if (size_ > 1) {
    Node_ tmp_head = *head_;
    Node_ tmp_tail = *tail_;
    Node_* head_ptr = head_;
    Node_* tail_ptr = tail_;
    for (size_t i = 0; i < size_ / 2; i++) {
      head_ptr->value_ = tmp_tail.value_;
      tail_ptr->value_ = tmp_head.value_;
      head_ptr = head_ptr->ptr_next_;
      tail_ptr = tail_ptr->ptr_prev_;
      tmp_head = *head_ptr;
      tmp_tail = *tail_ptr;
    }
  }
}

template <typename T>
void list<T>::unique() noexcept {
  if (size_ == 0 || size_ == 1) return;
  auto it = begin();
  auto it_next = it + 1;
  list<T> tmp_lst;
  while (it != end()) {
    if (*it == *it_next) {
      ++it;
      ++it_next;
      continue;
    } else
      tmp_lst.push_back(*it);
    ++it_next;
    ++it;
  }
  *this = std::move(tmp_lst);
}

template <typename T>
inline typename list<T>::size_type list<T>::size() const noexcept {
  return size_;
}

template <typename T>
inline typename list<T>::size_type list<T>::max_size() const noexcept {
  return (std::numeric_limits<std::size_t>::max() / sizeof(Node_) / 2);
}

template <typename T>
inline bool list<T>::empty() const noexcept {
  return size_ == 0;
}

template <typename T>
inline void list<T>::clear() noexcept {
  while (size_ != 0) {
    pop_front();
  }
}

template <typename T>
inline typename list<T>::iterator list<T>::insert(
    list::iterator pos, const_reference value) noexcept {
  Node_* cur_node = GetIteratorNode_(pos);
  auto* new_node_ = new Node_(value);
  if (size_ <= 1) {
    if (cur_node == fake_)
      push_back(value);
    else if (cur_node == head_)
      push_front(value);
    delete new_node_;
    new_node_ = nullptr;
    return Iterator(head_);
  } else {
    Node_* prev_node = cur_node->ptr_prev_;
    new_node_->ptr_prev_ = prev_node;
    new_node_->ptr_next_ = cur_node;
    cur_node->ptr_prev_ = new_node_;
    prev_node->ptr_next_ = new_node_;
    if (cur_node == fake_)
      tail_ = new_node_;
    else if (cur_node == head_)
      head_ = new_node_;
    ++size_;
  }
  return Iterator(new_node_);
}

template <typename T>
inline void list<T>::erase(list::iterator pos) noexcept {
  Node_* ptr = GetIteratorNode_(pos);
  if (ptr == fake_) return;
  if (ptr == head_) {
    pop_front();
  } else if (ptr == tail_) {
    pop_back();
  } else {
    Node_* prev = ptr->ptr_prev_;
    Node_* next = ptr->ptr_next_;
    prev->ptr_next_ = next;
    next->ptr_prev_ = prev;
    delete ptr;
    --size_;
  }
}

template <typename T>
inline void list<T>::splice(list::iterator pos, list& other) noexcept {
  if (this != &other) {
    for (auto itr = other.begin(); itr != other.end(); ++itr) insert(pos, *itr);
    other.clear();
  }
}

template <typename T>
inline list<T>& list<T>::operator=(const list<T>& other) noexcept {
  if (this != &other) {
    clear();
    if (!fake_) InitFake_();
    Node_* tmp_node = other.head_;
    if (tmp_node) {
      while (tmp_node != other.fake_) {
        push_back(tmp_node->value_);
        tmp_node = tmp_node->ptr_next_;
      }
    }
  }
  return *this;
}

template <typename T>
inline list<T>& list<T>::operator=(list<T>&& other) noexcept {
  if (this != &other) {
    list<T> tmp_lst(std::move(other));
    *this = tmp_lst;
  }
  return *this;
}

template <typename T>
inline void list<T>::InitFake_() noexcept {
  fake_ = new Node_(T());
  fake_->ptr_next_ = nullptr;
  fake_->ptr_prev_ = nullptr;
}

template <typename T>
inline void list<T>::MergeSort_(list<T>& left, list<T>& right,
                                list<T>& result) noexcept {
  list<T> merged;
  int left_index = 0, right_index = 0;
  s21::list<T>::const_iterator left_iter = left.begin();
  s21::list<T>::const_iterator right_iter = right.begin();

  while ((left_index < (int)left.size_) && (right_index < (int)right.size_)) {
    left_iter = left.begin() + left_index;
    right_iter = right.begin() + right_index;
    if (*left_iter <= *right_iter) {
      merged.push_back(*left_iter);
      ++left_index;
    } else {
      merged.push_back(*right_iter);
      ++right_index;
    }
  }

  while (left_index < (int)left.size_) {
    merged.push_back(*left_iter);
    ++left_iter;
    ++left_index;
  }

  while (right_index < (int)right.size_) {
    merged.push_back(*right_iter);
    ++right_iter;
    ++right_index;
  }

  result = merged;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_LIST_LIST_H_
