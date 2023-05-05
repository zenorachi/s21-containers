#include <iostream>

namespace S21 {
    template<typename T>
    class Stack {
        public:
            using value_type = T;
            using reference = T &;
            using const_reference = const T &;
            using size_type = size_t;

            // CONSTRUCTORS
            Stack() noexcept;
            Stack(std::initializer_list<value_type> const &items) noexcept;
            Stack(const Stack& other);
            Stack(Stack&& other) noexcept;

            // DESTRUCTOR
            ~Stack();

            // BASIC METHODS
            const_reference Top() const;
            bool Empty() const noexcept;
            size_type Size() const noexcept;
            void Push(const_reference value) noexcept;
            void Pop();
            void Swap(Stack& other) noexcept;

            // OVERLOAD OPERATORS
            Stack& operator=(const Stack& other) noexcept;
            Stack& operator=(Stack&& other) noexcept;

        private:
            typedef struct Node_ {
                value_type value_;
                Node_* ptr_prev_;
                explicit Node_(value_type value) noexcept : value_(value), ptr_prev_(nullptr) {}
            } Node_;

            Node_* tail_;
            size_type size_;

            void Clear_();
            value_type At_(int i) const;
    };

    template <typename T>
    inline Stack<T>::Stack() noexcept : tail_(nullptr), size_(0) {}

    template <typename T>
    inline Stack<T>::Stack(const std::initializer_list<value_type> &items) noexcept : tail_(nullptr), size_(0) {
        for (value_type i : items) {
            Push(i);
        }
    }

    template <typename T>
    inline Stack<T>::Stack(const Stack<T> &other) : tail_(nullptr), size_(0) { *this = other; }

    template <typename T>
    inline Stack<T>::Stack(Stack<T> &&other) noexcept : tail_(nullptr), size_(0) { *this = std::move(other); }

    template <typename T>
    inline Stack<T>::~Stack() { Clear_(); }

    template <typename T>
    inline Stack<T> &Stack<T>::operator=(const Stack<T> &other) noexcept {
        if (this != &other) {
            Clear_();
            int i = other.size_ - 1;
            while (i >= 0)
                Push(other.At_(i--));
        }
        return *this;
    }

    template <typename T>
    inline Stack<T> &Stack<T>::operator=(Stack<T> &&other) noexcept {
        if (this != &other) {
            Clear_();
            tail_ = other.tail_;
            size_ = other.size_;
            other.tail_ = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    template <typename T>
    inline bool Stack<T>::Empty() const noexcept { return size_ == 0; }

    template <typename T>
    inline typename Stack<T>::size_type Stack<T>::Size() const noexcept { return size_; }

    template <typename T>
    inline typename Stack<T>::const_reference Stack<T>::Top() const {
        if (!tail_)
            throw std::logic_error("Stack is empty");
        return tail_->value_;
    }

    template <typename T>
    inline void Stack<T>::Push(const_reference value) noexcept {
        Node_ *new_node = new Node_(value);
        if (!tail_) {
            tail_ = new_node;
        } else {
            new_node->ptr_prev_ = tail_;
            tail_ = new_node;
        }
        ++size_;
    }

    template <typename T>
    inline void Stack<T>::Pop() {
        if (!tail_)
            throw std::logic_error("Stack is empty");
        Node_* prev_node = tail_->ptr_prev_;
        delete tail_;
        tail_ = prev_node;
        --size_;
    }

    template <typename T>
    inline void Stack<T>::Swap(Stack<T> &other) noexcept {
        if (this != &other) {
            Node_ *tmp_tail = tail_;
            tail_ = other.tail_;
            other.tail_ = tmp_tail;
            size_type tmp_size = size_;
            size_ = other.size_;
            other.size_ = tmp_size;
        }
    }

    template <typename T>
    inline void Stack<T>::Clear_() {
        while (tail_)
            Pop();
    }

    template <typename T>
    inline typename Stack<T>::value_type Stack<T>::At_(int i) const {
        if (i < 0 || i >= (int) size_)
            throw std::out_of_range("Index out of range");
        value_type result = T();
        Node_ *tmp_tail = tail_;
        int j = 0;
        while ((j++) != i)
            tmp_tail = tmp_tail->ptr_prev_;
        result = tmp_tail->value_;
        return result;
    }
    
}
