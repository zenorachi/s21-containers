#ifndef CPP2_S21_CONTAINERS_1_S21_TREE_H
#define CPP2_S21_CONTAINERS_1_S21_TREE_H

#include <iostream>
#include <utility>

namespace S21 {
    template <typename K, typename V>
    class Tree {
    public:
        using key_type = K;
        using mapped_type = V;
        using value_type = std::pair<key_type, mapped_type>;
        using reference = value_type &;
        using const_reference = const value_type &;
//        using iterator = MapIterator<K, T>; //or BinaryTree::iterator
//        using const_iterator = MapConstIterator<K, T>; //or BinaryTree::const_iterator
        using size_type = size_t;

        // CONSTRUCTORS
        Tree() noexcept;
        Tree(key_type k, mapped_type m) noexcept;
//        Tree(const Tree &other) noexcept;
//        Tree(Tree &&other);

        // DESTRUCTOR
        ~Tree() = default;
        // REFACTOR
//        ~Tree();

        // BASIC METHODS
        void Kek() { std::cout << "Key: " << element_.first << " Value: " << element_.second << std::endl; };
        void Insert(const value_type& elem);

    protected:
//        typedef struct Node_ {
//            Node_* left_;
//            Node_* right_;
//            value_type value_;
//            unsigned char height_;
//            Node_() : left_(nullptr), right_(nullptr), value_(K(), V()), height_(1) {};
//        } Node_;

        Tree* left_;
        Tree* right_;
        value_type element_;
        unsigned char height_;
        size_type size_;

    private:
        unsigned char Height_(Tree* root_);
        int BalanceFactor_();
        void FixHeight_();
        void RotateLeft();
        void RotateRight();
        void ChangePointers(Tree* tmp);
        void Balance_();
    };

    template<typename K, typename V>
    Tree<K, V>::Tree() noexcept : left_(nullptr), right_(nullptr), element_(K(), V()), height_(0), size_(0) {}

    template<typename K, typename V>
    Tree<K, V>::Tree(key_type k, mapped_type m) noexcept : left_(nullptr), right_(nullptr), element_(k, m), height_(1), size_(0) {}

    template<typename K, typename V>
    inline unsigned char Tree<K, V>::Height_(Tree* root_) { return (root_ ? root_->height_ : 0); }

    template<typename K, typename V>
    inline int Tree<K, V>::BalanceFactor_() { return (Height_(right_) - Height_(left_)); }

    template<typename K, typename V>
    void Tree<K, V>::FixHeight_() { height_ = (Height_(left_) > Height_(right_) ? Height_(left_) : Height_(right_)) + 1; }

    template<typename K, typename V>
    void Tree<K, V>::RotateLeft() {
        Tree* tmp_right = right_;
        right_ = tmp_right->left_;
        tmp_right->left_ = this;
        FixHeight_();
        tmp_right->FixHeight_();
        ChangePointers(tmp_right);
    }

    template<typename K, typename V>
    void Tree<K, V>::RotateRight() {
        Tree* tmp_left = left_;
        left_ = tmp_left->right_;
        tmp_left->right_ = this;
        FixHeight_();
        tmp_left->FixHeight_();
        ChangePointers(tmp_left);
    }

    template<typename K, typename V>
    void Tree<K, V>::ChangePointers(Tree* tmp) {
        Tree* tmp_r = tmp->right_;
        Tree* tmp_l = tmp->left_;
        value_type tmp_v = element_;
        size_type tmp_s = size_;
        tmp->right_ = right_;
        right_ = tmp_r;
        tmp->left_ = left_;
        left_ = tmp_l;
        tmp->element_ = element_;
        element_ = tmp_v;
        tmp->size_ = size_;
        size_ = tmp_s;
    }

    template<typename K, typename V>
    void Tree<K, V>::Balance_() {
        FixHeight_();
        int balance = BalanceFactor_();
        if (balance == 2) {
            if (right_->BalanceFactor_() < 0) {
                right_->RotateRight();
            }
            RotateLeft();
        } else if (balance == -2) {
            if (left_->BalanceFactor_() > 0)
                left_->RotateLeft();
            RotateRight();
        }
    }

    template<typename K, typename V>
    void Tree<K, V>::Insert(const value_type& elem) {
        if (!left_ && !right_) {
            *this = Tree<K, V>(elem.first, elem.second);
            return;
        }

        if (elem.first < element_.first) {
            if (!left_)
                left_ = new Tree<K, V>(elem.first, elem.second);
            else
                left_->Insert(elem);
        } else if (elem.first > element_.first) {
            if (!right_)
                right_ = new Tree<K, V>(elem.first, elem.second);
            else
                right_->Insert(elem);
        }

        Balance_();
    }

}

#endif //CPP2_S21_CONTAINERS_1_S21_TREE_H
