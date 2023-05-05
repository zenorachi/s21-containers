#include "s21_stack.hpp"
#include <stack>
#include <gtest/gtest.h>

TEST(STACK, Undefined_1) {
    S21::Stack<int> st;
    st.Push(10);
    st.Push(2);
    st.Pop();
    st.Pop();
    st.Push(7);
    st.Pop();
    st.Push(9);
    st.Push(14);
    st.Push(10);
    st.Push(10);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Pop();
    st.Pop();
    st.Pop();
    st.Push(9);
    st.Push(3);
    // TEST
    EXPECT_EQ(st.Top(), 3);
    // TEST
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    st.Push(10);
    st.Push(2);
    st.Pop();
    st.Pop();
    st.Push(7);
    st.Pop();
    st.Pop();
    st.Push(9);
    st.Push(14);
    st.Pop();
    st.Pop();
    st.Push(10);
    st.Push(10);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Pop();
    st.Pop();
    st.Pop();
    st.Push(3);
    st.Push(9);
    // TEST
    EXPECT_EQ(st.Top(), 9);
    // TEST
    st.Pop();
    st.Pop();
    st.Push(2);
    st.Pop();
    st.Pop();
    st.Push(7);
    st.Pop();
    st.Pop();
    st.Push(9);
    st.Push(14);
    st.Pop();
    st.Push(10);
    st.Push(10);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Pop();
    st.Push(14);
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    st.Push(10);
    st.Push(10);
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(10);
    st.Push(534543534);
    // TEST
    EXPECT_EQ(st.Top(), 534543534);
    // TEST
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop();
}

TEST(STACK, Constructors_2) {
    int n = 1e4;
    S21::Stack<int> st = {};
    std::stack<int> orig_st = {};
    for (int i = 0; i < n; i++) {
        st.Push(i);
        orig_st.push(i);
    }
    EXPECT_EQ(st.Size(), orig_st.size());
    st.Pop();
    st.Pop();
    orig_st.pop();
    orig_st.pop();
    EXPECT_EQ(st.Size(), orig_st.size());
    int top = st.Top();
    int orig_top = orig_st.top();
    EXPECT_EQ(top, orig_top);
}
//
//TEST(STACK, Constructors_3) {
//    S21::Stack<double> st = {1.032, 2.320, 3.0, 4.0, 5.0, 6.0, 7.000043, 8.324, 9.343, 10.0};
//    EXPECT_EQ(st.Size(), 10);
//    double front = st.Front();
//    EXPECT_DOUBLE_EQ(front, 1.032);
//    st.Pop();
//    double new_front = st.Front();
//    EXPECT_DOUBLE_EQ(new_front, 2.320);
//    st.Pop();
//    double back = st.Back();
//    EXPECT_DOUBLE_EQ(back, 9.343);
//    EXPECT_EQ(st.Size(), 8);
//    st.Clear();
//    EXPECT_EQ(st.Size(), 0);
//}
//
//TEST(STACK, Constructors_4) {
//    S21::Stack<double> st = {1.032, 2.32, 3.0, 4.0, 5.0, 6.0, 7.000043, 8.324, 9.343, 10.0};
//    S21::Stack<double> st_cpy(st);
//    EXPECT_EQ(st_cpy.Size(), 10);
//    double front = st_cpy.Front();
//    EXPECT_DOUBLE_EQ(front, 1.032);
//    st_cpy.Pop();
//    double new_front = st_cpy.Front();
//    EXPECT_DOUBLE_EQ(new_front, 2.320);
//    double back = st_cpy.Back();
//    EXPECT_DOUBLE_EQ(back, 10.0);
//    st_cpy.Pop();
//    back = st_cpy.Back();
//    EXPECT_DOUBLE_EQ(back, 9.343);
//    EXPECT_EQ(st_cpy.Size(), 8);
//}
//
//TEST(STACK, Constructors_5) {
//    S21::Stack<double> st = {1.032, 2.32, 3.0, 4.0, 5.0, 6.0, 7.000043, 8.324, 9.343, 10.0};
//    S21::Stack<double> st_cpy(std::move(st));
//    EXPECT_EQ(st_cpy.Size(), 10);
//    double front = st_cpy.Front();
//    EXPECT_DOUBLE_EQ(front, 1.032);
//    st_cpy.Pop();
//    double new_front = st_cpy.Front();
//    EXPECT_DOUBLE_EQ(new_front, 2.320);
//    double back = st_cpy.Back();
//    EXPECT_DOUBLE_EQ(back, 10.0);
//    st_cpy.Pop();
//    back = st_cpy.Back();
//    EXPECT_DOUBLE_EQ(back, 9.343);
//    EXPECT_EQ(st_cpy.Size(), 8);
//    EXPECT_EQ(st.Size(), 0);
//}
//
//TEST(STACK, Empty_List1) {
//    std::list<int>orig_list = {};
//    S21::Stack<int>st = {};
//    auto orig_itr_end = orig_list.end();
//    auto itr_end = st.End();
//    EXPECT_EQ(*orig_itr_end, *itr_end);
//}
//
//TEST(STACK, Empty_List2) {
//    std::list<int>orig_list;
//    S21::Stack<int>st;
//    auto orig_itr = orig_list.end();
//    auto itr = st.End();
//    EXPECT_EQ(*orig_itr, *itr);
//}
//
//TEST(STACK, Front) {
//    S21::Stack<char> lol = {'l', 'o', 'l'};
//    std::list<char> lol_orig = {'l', 'o', 'l'};
//    EXPECT_EQ(lol.Front(), lol_orig.front());
//}
//
//TEST(STACK, FrontEmpty) {
//    S21::Stack<int> lol;
//    std::list<int> lol_orig;
//    EXPECT_EQ(lol.Front(), lol_orig.front());
//}
//
//TEST(STACK, BackEmpty) {
//    S21::Stack<int> lol;
//    std::list<int> lol_orig;
//    EXPECT_EQ(lol.Back(), lol_orig.back());
//}
//
//TEST(STACK, Pop) {
//    S21::Stack<int> lol = {1, 2, 10, 3, 4, 6, 43};
//    std::list<int> lol_orig = {1, 2, 10, 3, 4, 6, 43};
//    lol.Pop();
//    lol_orig.pop_front();
//    auto itr_orig = lol_orig.begin();
//    for (auto itr = lol.Begin(); itr != lol.End(); itr++) {
//    EXPECT_EQ(*itr, *itr_orig);
//    itr_orig++;
//    }
//}
//
//TEST(STACK, EmptyList3) {
//    std::list<int>orig_list(5);
//    S21::Stack<int>st(5);
//    auto orig_itr = orig_list.end();
//    auto itr = st.End();
//    EXPECT_EQ(*orig_itr, *itr);
//}
//
//TEST(STACK, MoveCase) {
//    S21::Stack<int> a = {43, 43, 43, 5};
//    S21::Stack<int> b = {1};
//    a = std::move(b);
//}
