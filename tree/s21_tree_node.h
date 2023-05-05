#ifndef CPP2_S21_CONTAINERS_1_S21_TREE_NODE_H
#define CPP2_S21_CONTAINERS_1_S21_TREE_NODE_H

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
        explicit Tree(const value_type& elem) noexcept;
//        Tree(const Tree &other) noexcept;
//        Tree(Tree &&other);

        // DESTRUCTOR
        ~Tree() = default;
        // REFACTOR
//        ~Tree();

        // BASIC METHODS
        void Kek() { std::cout << "Key: " << root_->element_.first << " Value: " << root_->element_.second << std::endl; };
        void Insert(const value_type& elem);

        // OVERLOAD OPERATORS
        Tree& operator=(Tree&& other) noexcept;

    protected:
        typedef struct Node_ {
            value_type element_;
            unsigned char height_;
            explicit Node_(const value_type& elem) : element_(elem), height_(1) {};
        } Node_;

        Node_* root_;
        Tree *left_;
        Tree *right_;
        size_type size_{};

    private:
        unsigned char Height_(Tree* tr);
        int BalanceFactor_();
        void FixHeight_();
        void RotateLeft_();
        void RotateRight_();
        void ChangePointers_(Tree* tmp, bool is_left);
        void Balance_();
        void FindRightMin_();
    };

    template<typename K, typename V>
    Tree<K, V>::Tree() noexcept : root_(nullptr), left_(nullptr), right_(nullptr), size_(0) {}

    template<typename K, typename V>
    Tree<K, V>::Tree(const value_type& elem) noexcept : left_(nullptr), right_(nullptr) {
        root_ = new Node_(elem);
    }

    template<typename K, typename V>
    Tree<K, V> &Tree<K, V>::operator=(Tree &&other) noexcept {
        if (this != &other) {
            right_ = other.right_;
            left_ = other.left_;
            root_ = other.root_;
            other.right_ = nullptr;
            other.left_ = nullptr;
            other.root_ = nullptr;
        }
        return *this;
    }

    template<typename K, typename V>
    inline unsigned char Tree<K, V>::Height_(Tree* tr) { return (tr ? tr->root_ ? tr->root_->height_ : 0 : 0); }

    template<typename K, typename V>
    inline int Tree<K, V>::BalanceFactor_() { return (Height_(right_) - Height_(left_)); }

    template<typename K, typename V>
    void Tree<K, V>::FixHeight_() { root_->height_ = (Height_(left_) > Height_(right_) ? Height_(left_) : Height_(right_)) + 1; }

    template<typename K, typename V>
    void Tree<K, V>::RotateLeft_() {
        Tree* tmp_right = right_;
        right_ = tmp_right->left_;
        ChangePointers_(tmp_right, true);
        FixHeight_();
        tmp_right->FixHeight_();
        *this = std::move(*tmp_right);
    }

    template<typename K, typename V>
    void Tree<K, V>::RotateRight_() {
        Tree* tmp_left = left_;
        left_ = tmp_left->right_;
        ChangePointers_(tmp_left, false);
        FixHeight_();
        tmp_left->FixHeight_();
        *this = std::move(*tmp_left);
    }

    template<typename K, typename V>
    void Tree<K, V>::ChangePointers_(Tree* tmp, bool is_left) {
        auto* tmp_this = new Tree<K, V>();
        tmp_this->left_ = this->left_;
        tmp_this->right_ = this->right_;
        tmp_this->root_ = this->root_;
        if (is_left)
            tmp->left_ = tmp_this;
        else
            tmp->right_ = tmp_this;
    }

    template<typename K, typename V>
    void Tree<K, V>::Balance_() {
        FixHeight_();
        int balance = BalanceFactor_();
        if (balance == 2) {
            if (right_->BalanceFactor_() < 0) {
                right_->RotateRight_();
            }
            RotateLeft_();
        } else if (balance == -2) {
            if (left_->BalanceFactor_() > 0)
                left_->RotateLeft_();
            RotateRight_();
        }
    }

    template<typename K, typename V>
    void Tree<K, V>::Insert(const value_type& elem) {
        if (!root_) {
            root_ = new Node_(elem);
            return;
        }

        if (elem.first < root_->element_.first) {
            if (!left_)
                left_ = new Tree;
            left_->Insert(elem);
        } else if (elem.first > root_->element_.first) {
            if (!right_)
                right_ = new Tree;
            right_->Insert(elem);
        }

        Balance_();
    }

    template<typename K, typename V>
    void Tree<K, V>::FindRightMin_() {
        
    }

}

#endif  // CPP2_S21_CONTAINERS_1_S21_TREE_NODE_H
