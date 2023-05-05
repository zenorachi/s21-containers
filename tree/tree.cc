#include "s21_tree_node.h"
#include <map>
#include <set>

int main() {
    S21::Tree<int, int> tr;
//    tr.Kek();
    std::pair<int, int> sorry;
    sorry.first = 86;
    sorry.second = 86;
    tr.Insert(sorry);
    tr.Kek();
//
    sorry.first = 50;
    sorry.second = 50;
    tr.Insert(sorry);
    tr.Kek();
//
    sorry.first = 100;
    sorry.second = 100;
    tr.Insert(sorry);
    tr.Kek();

    sorry.first = 90;
    sorry.second = 90;
    tr.Insert(sorry);
    tr.Kek();

    sorry.first = 30;
    sorry.second = 30;
    tr.Insert(sorry);
    tr.Kek();

    sorry.first = 120;
    sorry.second = 120;
    tr.Insert(sorry);
    tr.Kek();

    sorry.first = 95;
    sorry.second = 95;
    tr.Insert(sorry);
    tr.Kek();

    sorry.first = 60;
    sorry.second = 60;
    tr.Insert(sorry);
    tr.Kek();

    sorry.first = 115;
    sorry.second = 115;
    tr.Insert(sorry);
    tr.Kek();

    sorry.first = 130;
    sorry.second = 130;
    tr.Insert(sorry);
    tr.Kek();

    sorry.first = 93;
    sorry.second = 93;
    tr.Insert(sorry);
    tr.Kek();

//    std::map<int, int> m;
//    std::pair<int, int> elem;
//    elem.first = 1;
//    elem.second = 2;
//    m.insert(elem);
//
//    for (auto it : m)
//        std::cout << "Key: " << it.first << " Value: " << it.second << std::endl;
//
//    std::pair<int, int> elem2;
//    elem2.first = 1;
//    elem2.second = 2;
//    m.insert(elem2);
//
//    for (auto it : m)
//        std::cout << "Key: " << it.first << " Value: " << it.second << std::endl;
    return 0;
}
