#ifndef CPP2_S21_CONTAINERS_1_S21_CRINGE_H
#define CPP2_S21_CONTAINERS_1_S21_CRINGE_H

#include <iostream>
#include <utility>

namespace s21 {
    template<typename K, typename T>
    class Tree {
    public:
        using key_type = K;
        using mapped_type = T;
        using value_type = std::pair<key_type, mapped_type>;
        using reference = value_type &;
        using const_reference = const value_type &;
//        using iterator = MapIterator<K, T>; //or BinaryTree::iterator
//        using const_iterator = MapConstIterator<K, T>; //or BinaryTree::const_iterator
        using size_type = size_t;

//        value_type element_;
//        unsigned char height_;
//        Tree<K, T> *right_;
//        Tree<K, T> *left_;

        Tree() noexcept;
        Tree(key_type k, mapped_type m);
        Tree(Tree<K, T> &other) noexcept;
        Tree(Tree<K, T> &&other) noexcept;
        Tree &operator=(Tree<K, T> &&other) noexcept;

        // ~Tree();

        void Insert(const value_type& elem);
        void Balance();
        int HeightDifference();
        void RotateLeft();
        void RotateRight();
        void FixHeight();
        unsigned char Height(Tree* p);

    protected:
        value_type element_;
        unsigned char height_{};
        Tree<K, T> *right_;
        Tree<K, T> *left_;
    };

    template<typename K, typename T>
    inline Tree<K, T>::Tree(key_type k, mapped_type m)
    : element_(k, m), height_(1), left_(nullptr), right_(nullptr) {}

    // REFACTOR
    template<typename K, typename T>
    inline Tree<K, T>::Tree(Tree<K, T> &other) noexcept
    : height_(other.height_), element_(other.element_), left_(other.left_), right_(other.right_) {}

    // REFACTOR
    template<typename K, typename T>
    inline Tree<K, T>::Tree(Tree<K, T> &&other) noexcept : height_(other.height_), element_(other.element_) {
        left_ = other.left_;
        right_ = other.right_;
        other.left_ = nullptr;
        other.right_ = nullptr;
    }

    // REFACTOR
    template<typename K, typename T>
    inline Tree<K, T> &Tree<K, T>::operator=(Tree<K, T> &&other) noexcept {
        if (this != &other) {
            left_ = other.left_;
            right_ = other.right_;
            height_ = other.height_;
            element_ = other.element_;
            other.left_ = nullptr;
            other.right_ = nullptr;
            other.height_ = 0;
//            other.element_ = element_(K(), T());
        }
        return *this;
    }


    template<typename K, typename T>
    inline void Tree<K, T>::Insert(const value_type& elem) {
        if (height_ == 0) {
            Tree<K, T> new_element(elem.first, elem.second);
            *this = std::move(new_element);
            return;
        }

        if (elem.first < element_.first) {
            if (!left_)
                left_ = new Tree<K, T>(elem.first, elem.second);
            else
                left_->Insert(elem);
        } else if (elem.first > element_.first) {
            if (!right_)
                right_ = new Tree<K, T>(elem.first, elem.second);
            else
                right_->Insert(elem);
        }

        Balance();
    }

    template<typename K, typename T>
    inline void Tree<K, T>::Balance() {
        FixHeight();
        int balance = HeightDifference();
        if (balance == 2) {
            if (right_->HeightDifference() < 0) {
                right_->RotateRight();
            }
            RotateLeft();
        } else if (balance == -2) {
            if (left_->HeightDifference() > 0)
                left_->RotateLeft();
            RotateRight();
        }
    }

    template<typename K, typename T>
    inline int Tree<K, T>::HeightDifference() {
        return right_->height_ - left_->height_;
    }

    template<typename K, typename T>
    inline void Tree<K, T>::RotateLeft() {
        Tree* tmp_r = right_;
        right_ = tmp_r->left_;
        tmp_r->left_ = this;
        FixHeight();
        tmp_r->FixHeight();
        *this = tmp_r;
    }

    template<typename K, typename T>
    inline void Tree<K, T>::RotateRight() {
        Tree* tmp_l = left_;
        left_ = tmp_l->right_;
        tmp_l->right_ = this;
        FixHeight();
        tmp_l->FixHeight();
        *this = tmp_l;
    }

    template<typename K, typename T>
    inline unsigned char Tree<K, T>::Height(Tree* p) {
        return p ? p->height_ : 0;
    }

    template<typename K, typename T>
    inline void Tree<K, T>::FixHeight() {
        unsigned char hl = Height(left_);
        unsigned char hr = Height(right_);
        height_ = (hl > hr ? hl : hr) + 1;
    }

    template<typename K, typename T>
    Tree<K, T>::Tree() noexcept : left_(nullptr), right_(nullptr), height_(0), element_(K(), T()) {}

}


#endif  // CPP2_S21_CONTAINERS_1_S21_CRINGE_H
