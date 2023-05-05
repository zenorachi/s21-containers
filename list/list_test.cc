#include "s21_list.hpp"
#include <list>
#include <gtest/gtest.h>

TEST(LIST, List_1) {
    S21::List<int> lst;
    lst.PushFront(10);
    lst.PushFront(2);
    lst.PopFront();
    lst.PopFront();
    lst.PushFront(7);
    lst.PopFront();
    lst.PopFront();
    lst.PushFront(9);
    lst.PushFront(14);
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(1);
    lst.PushBack(2);
    lst.PushBack(3);
    lst.PushBack(4);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushFront(10);
    lst.PushFront(10);
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PushFront(9);
    lst.PushFront(3);
    // TEST
    EXPECT_EQ(lst.Front(), 3);
    // TEST
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PushFront(10);
    lst.PushFront(2);
    lst.PopFront();
    lst.PopFront();
    lst.PushFront(7);
    lst.PopFront();
    lst.PopFront();
    lst.PushFront(9);
    lst.PushFront(14);
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(1);
    lst.PushBack(2);
    lst.PushBack(3);
    lst.PushBack(4);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushFront(10);
    lst.PushFront(10);
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PushFront(3);
    lst.PushFront(9);
    // TEST
    EXPECT_EQ(lst.Front(), 9);
    // TEST
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PushFront(2);
    lst.PopFront();
    lst.PopFront();
    lst.PushFront(7);
    lst.PopFront();
    lst.PopFront();
    lst.PushFront(9);
    lst.PushFront(14);
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(1);
    lst.PushBack(2);
    lst.PushBack(3);
    lst.PushBack(4);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PopFront();
    lst.PushFront(14);
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(1);
    lst.PushBack(2);
    lst.PushBack(3);
    lst.PushBack(4);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushBack(10);
    lst.PushFront(10);
    lst.PushFront(10);
    lst.PushFront(534543534);
    // TEST
    EXPECT_EQ(lst.Front(), 534543534);
    // TEST
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopBack();
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopBack();
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopBack();
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopBack();
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopBack();
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopBack();
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopBack();
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopBack();
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopBack();
    lst.PopBack();
    lst.PopBack();
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopBack();
    lst.PopBack();
    lst.PopBack();
    lst.PopFront();
    lst.PopFront();
    lst.PopFront();
    lst.PopBack();
    lst.PopBack();
    lst.PopBack();
}

TEST(LIST, Constructors_2) {
    size_t n = 1e4;
    S21::List<int> lst(n);
    EXPECT_EQ(lst.Size(), n);
    EXPECT_TRUE(lst.MaxSize() != 0);
    lst.PopBack();
    lst.PopFront();
    EXPECT_EQ(lst.Size(), (n - 2));
    int back = lst.Back();
    int front = lst.Front();
    EXPECT_EQ(back, 0);
    EXPECT_EQ(front, 0);
}

TEST(LIST, Constructors_3) {
    S21::List<double> lst = {1.032, 2.320, 3.0, 4.0, 5.0, 6.0, 7.000043, 8.324, 9.343, 10.0};
    EXPECT_EQ(lst.Size(), 10);
    double front = lst.Front();
    EXPECT_DOUBLE_EQ(front, 1.032);
    lst.PopFront();
    double new_front = lst.Front();
    EXPECT_DOUBLE_EQ(new_front, 2.320);
    lst.PopBack();
    double back = lst.Back();
    EXPECT_DOUBLE_EQ(back, 9.343);
    EXPECT_EQ(lst.Size(), 8);
    lst.Clear();
    EXPECT_EQ(lst.Size(), 0);
}

TEST(LIST, Constructors_4) {
    S21::List<double> lst = {1.032, 2.32, 3.0, 4.0, 5.0, 6.0, 7.000043, 8.324, 9.343, 10.0};
    S21::List<double> lst_cpy(lst);
    EXPECT_EQ(lst_cpy.Size(), 10);
    double front = lst_cpy.Front();
    EXPECT_DOUBLE_EQ(front, 1.032);
    lst_cpy.PopFront();
    double new_front = lst_cpy.Front();
    EXPECT_DOUBLE_EQ(new_front, 2.320);
    double back = lst_cpy.Back();
    EXPECT_DOUBLE_EQ(back, 10.0);
    lst_cpy.PopBack();
    back = lst_cpy.Back();
    EXPECT_DOUBLE_EQ(back, 9.343);
    EXPECT_EQ(lst_cpy.Size(), 8);
}

TEST(LIST, Constructors_5) {
    S21::List<double> lst = {1.032, 2.32, 3.0, 4.0, 5.0, 6.0, 7.000043, 8.324, 9.343, 10.0};
    S21::List<double> lst_cpy(std::move(lst));
    EXPECT_EQ(lst_cpy.Size(), 10);
    double front = lst_cpy.Front();
    EXPECT_DOUBLE_EQ(front, 1.032);
    lst_cpy.PopFront();
    double new_front = lst_cpy.Front();
    EXPECT_DOUBLE_EQ(new_front, 2.320);
    double back = lst_cpy.Back();
    EXPECT_DOUBLE_EQ(back, 10.0);
    lst_cpy.PopBack();
    back = lst_cpy.Back();
    EXPECT_DOUBLE_EQ(back, 9.343);
    EXPECT_EQ(lst_cpy.Size(), 8);
    EXPECT_EQ(lst.Size(), 0);
}

TEST(LIST, Empty_List1) {
    std::list<int>orig_list = {};
    S21::List<int>lst = {};
    auto orig_itr_end = orig_list.end();
    auto itr_end = lst.End();
    EXPECT_EQ(*orig_itr_end, *itr_end);
}

TEST(LIST, Empty_List2) {
    std::list<int>orig_list;
    S21::List<int>lst;
    auto orig_itr = orig_list.end();
    auto itr = lst.End();
    EXPECT_EQ(*orig_itr, *itr);
}

TEST(LIST, Front) {
    S21::List<char> lol = {'l', 'o', 'l'};
    std::list<char> lol_orig = {'l', 'o', 'l'};
    EXPECT_EQ(lol.Front(), lol_orig.front());
}

TEST(LIST, FrontEmpty) {
    S21::List<int> lol;
    std::list<int> lol_orig;
    EXPECT_EQ(lol.Front(), lol_orig.front());
}

TEST(LIST, BackEmpty) {
    S21::List<int> lol;
    std::list<int> lol_orig;
    EXPECT_EQ(lol.Back(), lol_orig.back());
}

TEST(LIST, Iterator) {
    S21::List<int> lol = {1, 2, 3, 4, 6, 43};
    std::list<int> lol_orig = {1, 2, 3, 4, 6, 43};
    int n = lol.Size();
    int n_orig = lol_orig.size();
    EXPECT_EQ(n, n_orig);
    auto itr = lol.Begin();
    auto itr_orig = lol_orig.begin();
    auto end = lol.End();
    auto end_orig = lol_orig.end();
    while (itr != end && itr_orig != end_orig) {
        EXPECT_EQ(*itr, *itr_orig);
        itr++;
        itr_orig++;
    }
}

TEST(LIST, Insert) {
    S21::List<int> lol;
    std::list<int> lol_orig;
    auto itr = lol.Begin();
    auto itr_orig = lol_orig.begin();
    itr = lol.Insert(itr, 21);
    itr_orig = lol_orig.insert(itr_orig, 21);
    EXPECT_EQ(*itr, *itr_orig);

    S21::List<int> lol1 = {1, 2, 3, 4, 6, 43};
    std::list<int> lol_orig1 = {1, 2, 3, 4, 6, 43};
    auto itr1 = lol1.Begin();
    auto itr_orig1 = lol_orig1.begin();
    itr1 = lol1.Insert(itr1, 21);
    itr_orig1 = lol_orig1.insert(itr_orig1, 21);
    auto end1 = lol1.End();
    auto end_orig1 = lol_orig1.end();
    while (itr1 != end1 && itr_orig1 != end_orig1) {
        EXPECT_EQ(*itr1, *itr_orig1);
        itr1++;
        itr_orig1++;
    }

    S21::List<int> lol2 = {1, 2, 3, 4, 6, 44};
    std::list<int> lol_orig2 = {1, 2, 3, 4, 6, 44};
    auto itr2 = lol2.End();
    auto itr_orig2 = lol_orig2.end();
    itr2 = lol2.Insert(itr2, 21);
    itr_orig2 = lol_orig2.insert(itr_orig2, 21);
    while (itr2 != lol2.Begin() && itr_orig2 != lol_orig2.begin()) {
        EXPECT_EQ(*itr2, *itr_orig2);
        itr2--;
        itr_orig2--;
    }
}

TEST(LIST, PopFront) {
    S21::List<int> lol = {1, 2, 10, 3, 4, 6, 43};
    std::list<int> lol_orig = {1, 2, 10, 3, 4, 6, 43};
    lol.PopFront();
    lol_orig.pop_front();
    auto itr_orig = lol_orig.begin();
    for (auto itr = lol.Begin(); itr != lol.End(); itr++) {
        EXPECT_EQ(*itr, *itr_orig);
        itr_orig++;
    }
}

TEST(LIST, PushFront) {
    S21::List<int> lol = {1, 2, 10, 3, 4, 6, 43};
    std::list<int> lol_orig = {1, 2, 10, 3, 4, 6, 43};
    lol.PushFront(21);
    lol_orig.push_front(21);
    auto itr_orig = lol_orig.begin();
    for (auto itr = lol.Begin(); itr != lol.End(); itr++) {
     EXPECT_EQ(*itr, *itr_orig);
     itr_orig++;
    }

    S21::List<int> lol1;
    std::list<int> lol_orig1;
    lol1.PushFront(21);
    lol_orig1.push_front(21);
    auto itr_orig1 = lol_orig1.begin();
    for (auto itr1 = lol1.Begin(); itr1 != lol1.End(); itr1++) {
        EXPECT_EQ(*itr1, *itr_orig1);
        itr_orig1++;
    }
}

TEST(LIST, Merge) {
    S21::List<int> lol = {1, 2, 10, 3, 4, 6, 43};
    std::list<int> lol_orig = {1, 2, 10, 3, 4, 6, 43};
    S21::List<int> list_merge = {2, 5, 7, 9};
    std::list<int> list_merge_orig = {2, 5, 7, 9};
    lol.Sort();
    lol_orig.sort();
    lol.Merge(list_merge);
    lol_orig.merge(list_merge_orig);
    auto itr_orig = lol_orig.begin();
    for (auto itr = lol.Begin(); itr != lol.End(); itr++) {
      EXPECT_EQ(*itr, *itr_orig);
      itr_orig++;
    }
}

TEST(LIST, EmptyList3) {
    std::list<int>orig_list(5);
    S21::List<int>lst(5);
    auto orig_itr = orig_list.end();
    auto itr = lst.End();
    EXPECT_EQ(*orig_itr, *itr);
}

TEST(LIST, MoveCase) {
    S21::List<int> a = {43, 43, 43, 5};
    S21::List<int> b = {1};
    a = std::move(b);
    EXPECT_EQ(a.Back(), 1);
}

TEST(LIST, EmplaceBack) {
    S21::List<int> our = {1, 2, 7, 8, 9};
    our.EmplaceBack(4, 5, 6);
    EXPECT_EQ(our.Back(), 6);
}

TEST(LIST, EmplaceFront) {
    S21::List<int> our{1, 2, 7, 8, 9};
    our.EmplaceFront(4, 5, 6);
    EXPECT_EQ(our.Front(), 6);
}

TEST(LIST, EmplaceBackInEmpty) {
    S21::List<int> our;
    our.EmplaceBack(4, 5, 6);
    EXPECT_EQ(our.Back(), 6);
    EXPECT_EQ(our.Front(), 4);
}

TEST(LIST, EmplaceInEmpty) {
    S21::List<int> our;
    our.EmplaceFront(4, 5, 6);
    EXPECT_EQ(our.Front(), 6);
    EXPECT_EQ(our.Back(), 4);
}
