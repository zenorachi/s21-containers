#include "s21_list.hpp"
#include <stack>
#include <list>

int main() {
//    S21::List<double> lst = {3, 4, 43, 34, 43, 43, 43};
////    S21::List<double> lst;
//    lst.PushBack(1);
//    lst.PushBack(2);
//    lst.PushBack(3);
//    lst.PushBack(4);
//    lst.PushBack(5);
//
//     lst.PopFront();
//     lst.PopFront();
//    lst.PushFront(7);
//     lst.PopFront();
//     lst.PopFront();
//     lst.PushFront(9);
//     lst.PushFront(14);
//     lst.PopBack();
//     lst.PopBack();
//    lst.PopFront();
//    lst.PopBack();
//     lst.PopFront();
//     lst.PopFront();
//     lst.PushBack(10);
//     lst.PushBack(10);
//     lst.PushBack(1);
//     lst.PushBack(2);
//     lst.PushBack(3);
//     lst.PushBack(4);
//     lst.PushBack(10);
//     lst.PushBack(10);
//     lst.PushBack(10);
//     lst.PushBack(10);
//     lst.PushBack(10);
//     lst.PushBack(10);
//     lst.PushBack(10);
//     lst.PushFront(10);
//     lst.PushFront(10);
//     lst.PopFront();
//     lst.PopFront();
//     lst.PopFront();
//     lst.PushFront(9);
//     lst.PushFront(3);
//     std::cout << lst.Front() << std::endl;
//     lst.PopFront();
//     lst.PopFront();
//     lst.PopFront();
//     lst.PopFront();
//     lst.PopFront();
//     lst.PopFront();
//    lst.PushFront(10);
//    lst.PushFront(2);
//    lst.PopFront();
//    lst.PopFront();
//    lst.PushFront(7);
//    lst.PopFront();
//    lst.PopFront();
//    lst.PushFront(9);
//    lst.PushFront(14);
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(1);
//    lst.PushBack(2);
//    lst.PushBack(3);
//    lst.PushBack(4);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushFront(10);
//    lst.PushFront(10);
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PushFront(3);
//    lst.PushFront(9);
//    std::cout << lst.Front() << std::endl;
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PushFront(2);
//    lst.PopFront();
//    lst.PopFront();
//    lst.PushFront(7);
//    lst.PopFront();
//    lst.PopFront();
//    lst.PushFront(9);
//    lst.PushFront(14);
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(1);
//    lst.PushBack(2);
//    lst.PushBack(3);
//    lst.PushBack(4);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PopFront();
//    lst.PushFront(14);
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(1);
//    lst.PushBack(2);
//    lst.PushBack(3);
//    lst.PushBack(4);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushBack(10);
//    lst.PushFront(10);
//    lst.PushFront(10);
//    lst.PushFront(534543534);
//    std::cout << "FDD: " << lst.Front() << std::endl;
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopBack();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopFront();
//    lst.PopBack();
//    lst.PopBack();
//    std::cout << "FDD: " << lst.Front() << std::endl;
//    lst.PopBack();
//    std::cout << "FDD: " << lst.Front() << std::endl;
//
//    S21::List<std::string> lst2(3);
//    std::cout << "FdfdfdDD: " << lst2.Front() << std::endl;
//    lst2.PushBack("penis");
//    std::cout << lst2.Back() << std::endl;
//    lst2.PushFront("vag");
//    std::cout << lst2.Front() << std::endl;
//    lst2.PopBack();
//    lst2.PopBack();
//    lst2.PopBack();
//    lst2.PopBack();
//    std::cout << lst2.Back() << std::endl;
//    lst2.PopBack();
//    lst2.PopBack();
//    lst2.PopBack();
//    lst2.PopFront();
//    lst2.PopFront();
//    lst2.PopFront();
//    lst2.PopFront();
//    std::cout << lst2.Front() << std::endl;
//    std::cout << lst2.Back() << std::endl;
//
//    std::cout << "\n\n\n\n\nSWAP\n";
//    S21::List<int> a = {1, 2, 3, 4, 5};
//    std::cout << "a Front: " << a.Front() << std::endl;
//    std::cout << "a Back:  " << a.Back() << std::endl;
//    S21::List<int> b = {5, 4, 3, 2, 1, 4398, 4398, 32};
//    std::cout << "b Front: " << b.Front() << std::endl;
//    std::cout << "b Back:  " << b.Back() << std::endl;
//    a.Swap(b);
//    std::cout << "a Front: " << a.Front() << std::endl;
//    std::cout << "a Back:  " << a.Back() << std::endl;
//    a.PopFront();
//    std::cout << "a Front (4): " << a.Front() << std::endl;
//    a.PopFront();
//    a.PopFront();
//    a.PopFront();
//    std::cout << "a Front (1): " << a.Front() << std::endl;
//    std::cout << "b Front: " << b.Front() << std::endl;
//    std::cout << "b Back:  " << b.Back() << std::endl;
//    S21::List<std::string> c = {"hello"};
//    S21::List<std::string> d = {};
//    c.Swap(d);
//    std::cout << d.Size() << std::endl;
//    std::cout << d.Front();
//    std::cout << std::endl;
//    std::cout << d.Back();
//    std::cout << std::endl;
//    std::cout << "f" << c.Front();
//    std::cout << std::endl;
//    std::cout << "f" << c.Back();
//    std::cout << std::endl;
//    d.Clear();
//    std::cout << d.Size() << std::endl;
//    std::cout << "f" << c.Front();
//    std::cout << std::endl;
//    std::cout << "f" << c.Back();
//
//    std::cout << "\n\n\n\n\nEUQAL\n";
//    S21::List<std::string> kek = {"34, 34, 2,", "hi", "s21"};
//    const S21::List<std::string>& lol = kek;
//    std::cout << "kek front: " << kek.Front() << std::endl;
//    std::cout << "kek back: " << kek.Back() << std::endl;
//    std::cout << "kek size: " << kek.Size() << std::endl;
//    std::cout << "lol front: " << lol.Front() << std::endl;
//    std::cout << "lol back: " << lol.Back() << std::endl;
//    std::cout << "lol size: " << lol.Size() << std::endl;
//
//    S21::List<std::string> meme = {};
//    S21::List<std::string> meme_cpy(meme);
//    std::cout << "meme cpy size: " << meme_cpy.Size() << std::endl;
//    std::cout << meme_cpy.Front() << meme.Front() << std::endl;
//    std::cout << meme_cpy.Back() << meme.Back() << std::endl;
//    S21::List<std::string> pil = {"ha1", "ha2", "ha3"};
//    meme_cpy = pil;
//    meme = pil;
//    std::cout << "meme cpy size: " << meme_cpy.Size() << std::endl;
//    std::cout << meme_cpy.Front() << meme.Front() << std::endl;
//    std::cout << meme_cpy.Back() << meme.Back() << std::endl;
//
//    S21::List<std::string> kekes(std::move(meme));
//    std::cout << kekes.Back() << " " << kekes.Front() << " " << kekes.Size() << std::endl;
////    meme.PushBack("kdf");
//    std::cout << "MEME MOVE: " << meme.Back() << " " << meme.Front() << " " << meme.Size() << std::endl;
//    std::list<int> orig = {1, 3, 3, 4, 4, 3};
//    std::list<int> orig_move(std::move(orig));
//    std::cout << orig.front() << orig.back() << orig.size();
//    orig.push_back(1);
//    std::cout << orig.front() << orig.back() << orig.size();

    // REVERSE
//    S21::List<int> lst_reverse = {4, 3, 2};
//    std::cout << lst_reverse.Front() << " " << lst_reverse.Back() << std::endl;
//    lst_reverse.Reverse();
//    std::cout << lst_reverse.Front() << " " << lst_reverse.Back() << std::endl;
//
//    // CONST_ITERATOR
    S21::List<double> lst_dbl = {1.3498, 43.4393, 4398.34892, 0.03499};
//    S21::List<double>::iterator c_it = lst_dbl.Begin();
//    while (c_it != lst_dbl.End()) {
//        std::cout << *c_it << " ";
//        ++c_it;
//    }
//    c_it += 3;
//    std::cout << *c_it << " ";
//    S21::List<int>::const_iterator shit = lst_reverse.Begin();
//    std::cout << std::endl;
//    std::cout << "fff: " << *shit << std::endl;
//    S21::List<int>::iterator uuu = lst_reverse.Begin();
//    std::cout << "fff: " << *uuu << std::endl;
//    ++uuu;
//    ++uuu;
//    std::cout << "fff: " << *uuu << std::endl;
//    ++uuu;
//    std::cout << "fff: " << *uuu << std::endl;
//    ++uuu;
//    std::cout << "fff: " << *uuu << std::endl;
//    *uuu = 4343134;
//    std::cout << lst_reverse.Front();
//    std::cout << lst_reverse.GetIteratorValue_(uuu) << std::endl;
//    *shit = 4;
//    shit = lst_reverse.Begin();
//    shit = lst_reverse.Begin();
//    std::cout << *c_it << " ";
//    std::cout << std::endl;
//    auto it = lst_dbl.Begin();
//    std::cout << *it << std::endl;
//    auto it_increse = it + 2;
//    std::cout << *it_increse << std::endl;
//    auto kek = it_increse - 4;
//    std::cout << *kek << std::endl;
//    std::cout << *it_increse << std::endl;
//    it_increse += 4;
//    std::cout << *it_increse << std::endl;
//
    S21::List<double>::const_iterator m;
//    lst_dbl.Clear();
    m = lst_dbl.Begin();
//    std::cout << *m << std::endl;

    auto kek = lst_dbl.Begin() + 3;
    kek = lst_dbl.End();
    S21::List<double>::iterator meui;
    meui = lst_dbl.End();
    meui = lst_dbl.Begin();
    meui += 10;
    // MERGE
//    S21::List<int> mer = {1, 2};
//    S21::List<int> ge = {4, 5, 6, 7, 8, 9, 10};
//    mer.Merge(ge);
//    auto kek = mer.Begin();
//    while (kek != mer.End()) {
//        std::cout << *kek << " ";
//        ++kek;
//    }
//    std::cout << std::endl << *kek << std::endl;
//    ++kek;
//    std::cout << *kek << std::endl;
//    ++kek;
//    std::cout << std::endl << *kek << std::endl;
//    std::cout << std::endl;
//
//    // SORT
    S21::List<double> list_1 = {1.01, 0.00656, 43.4, 999.99, -1};
//    list_1.Sort();
//    auto it_list_1 = list_1.Begin();
//    while (it_list_1 != list_1.End()) {
//        std::cout << *it_list_1 << " ";
//        ++it_list_1;
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << std::endl;
//    S21::List<double> puk = {1.0, 2.0, 3.0};
//    list_1.Merge(puk);
//    auto ittttt = list_1.Begin();
//    while (ittttt != list_1.End()) {
//        std::cout << *ittttt << std::endl;
//        ++ittttt;
//    }
//    std::cout << std::endl;
    auto it = list_1.Begin();
//    std::cout << std::endl;
//    std::cout << *it << std::endl;
//    std::cout << std::endl;
    list_1.Clear();
    list_1.PushBack(34.4);
//    list_1.Insert(it, 0.5);
////    auto i = list_1.Begin();
////    while (i != list_1.End()) {
////        std::cout << *i << std::endl;
////        ++i;
////    }
////    ++it;
//    auto memblin = list_1.Begin();
//    while (memblin != list_1.End()) {
//        std::cout << *memblin << std::endl;
//        ++memblin;
//    }
//    list_1.PushBack(0.439);
//    std::cout << std::endl;
//    it++;
//    std::cout << *it << std::endl;
    auto me = list_1.Begin();
    me++;

    auto itera = list_1.Insert(me, 0.0001);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << *itera << std::endl;
//    auto iterator = list_1.Begin();
//    iterator += 3;
//    list_1.Insert(iterator, 0.000001);
//    auto blin = list_1.Begin();
//    while (blin != list_1.End()) {
//        std::cout << *blin << " ";
//        ++blin;
//    }
//    std::cout << std::endl;
//    std::list<int> a = {4342};
//    auto a_it = a.begin();
////    a_it;
//    std::cout << *a_it << std::endl;
//    a.erase(a_it);
//    std::cout << *a_it << std::endl;
//    ++a_it;
//    std::cout << *a_it << std::endl;
//    ++a_it;
//    std::cout << *a_it << std::endl;
//    ++a_it;
//    std::cout << *a_it << std::endl;

    // ERASE
    S21::List<std::string> lst_str = {"hi", "s21"};
    S21::List<std::string>::iterator it_str = lst_str.Begin();
    it_str += 1;
    std::cout << *it_str << std::endl;
    lst_str.Erase(it_str);
//    ++it_str;
//    std::cout << *it_str << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    auto it2 = lst_str.Begin();
    while (it2 != lst_str.End()) {
        std::cout << *it2 << " ";
        ++it2;
    }
    std::cout << std::endl;
//    std::list<int> klist = {1, 2, 3};
//    std::list<int> blist = {4, 5, 6};
//    auto kit = ++klist.begin();
//    blist.splice(kit, blist);
//    std::cout << *kit << std::endl;

//    std::cout << std::endl;
//    std::cout << std::endl;
//    std::cout << std::endl;
//    auto vv = blist.begin();
//    while (vv != blist.end()) {
//        std::cout << *vv << std::endl;
//        ++vv;
//    }
//    std::cout << std::endl;

    // SPLICE
    S21::List<int> alist = {1, 1, 1};
    S21::List<int> blist = {1, 1, 1, 1};
    auto ia = alist.Begin();
    ++ia;
    ++ia;
    ++ia;
//    ++ia;
    alist.Splice(ia, blist);
    ia = alist.Begin();
    while (ia != alist.End()) {
        std::cout << *ia << " ";
        ++ia;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << *ia << std::endl;
    ++ia;
    std::cout << *ia << std::endl;
    ++ia;
    std::cout << *ia << std::endl;
    ++ia;
    std::cout << *ia << std::endl;
    ++ia;
    std::cout << *ia << std::endl;
    while (ia != alist.End()) {
        std::cout << *ia << " ";
        ++ia;
    }
    std::cout << std::endl;
    alist.Sort();
    ia = alist.Begin();
    while (ia != alist.End()) {
        std::cout << *ia << " ";
        ++ia;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    alist.Unique();
    ia = alist.Begin();
    while (ia != alist.End()) {
        std::cout << *ia << " ";
        ++ia;
    }
//    std::cout << *blist.Begin() << std::endl;
    std::list<int> dkfj;
//    dkfj.pop_back();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}
