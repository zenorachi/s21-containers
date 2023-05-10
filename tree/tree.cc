#include "s21_tree.h"
#include <map>
#include <set>

int main() {
    S21::Tree<int, int> tr;
    std::pair<int, int> sorry;

//
//    sorry.first = 10;
//    sorry.second = 10;
//    tr.Insert(sorry);
////
//    sorry.first = 5;
//    sorry.second = 5;
//    tr.Insert(sorry);
//
//    sorry.first = 20;
//    sorry.second = 20;
//    tr.Insert(sorry);
//
//    sorry.first = 15;
//    sorry.second = 15;
//    tr.Insert(sorry);
//
//    sorry.first = 30;
//    sorry.second = 30;
//    tr.Insert(sorry);
//
////    tr.Erase(30);
//
//    sorry.first = 1543;
//    sorry.second = 1543;
//    tr.Insert(sorry);
////
//////    tr.Erase(1543);
////
//    sorry.first = 154343;
//    sorry.second = 154343;
//    tr.Insert(sorry);
//

    // INCORRECT WORK WITH PARENTS
    sorry.first = 10;
    sorry.second = 10;
    tr.Insert(sorry);

    sorry.first = 5;
    sorry.second = 5;
    tr.Insert(sorry);

    sorry.first = 4;
    sorry.second = 4;
    tr.Insert(sorry);

    // OK

    sorry.first = 15;
    sorry.second = 15;
    tr.Insert(sorry);

    sorry.first = 13;
    sorry.second = 13;
    tr.Insert(sorry);

    // OK

    sorry.first = 18;
    sorry.second = 18;
    tr.Insert(sorry);
//     NOT OK

    sorry.first = 16;
    sorry.second = 16;
    tr.Insert(sorry);

    auto it = tr.Begin();
    ++it;
    ++it;
    ++it;
    std::cout << "it: " << it->first << std::endl;
    tr.Erase(it);
    it  = tr.Begin();
    ++it;
    std::cout << "it: " << it->first << std::endl;
    tr.Erase(it);
    S21::Tree<int, int>::const_iterator kek = tr.Begin();
    kek += 2;
    std::cout << "kek: " << kek->first << std::endl;
    S21::Tree<int, int>::iterator lol = tr.Begin();
    lol += 2;
    tr.Erase(lol);
    lol = tr.Begin();
    tr.Erase(lol);
    lol = tr.Begin();
    tr.Erase(lol);
    lol = tr.Begin();
    tr.Erase(lol);
    lol = tr.Begin();
    tr.Erase(lol);

    std::cout << tr.Empty() << std::endl;

    tr.Insert(sorry);
    sorry.first = 18;
    sorry.second = 18;
    tr.Insert(sorry);

    auto mem = tr.Begin();
    mem++;
    std::cout << mem->first << std::endl;

    S21::Tree<int, int> aue;
    sorry.first = 18;
    sorry.second = 18;
    aue.Insert(sorry);
    sorry.first = 81;
    sorry.second = 81;
    aue.Insert(sorry);

    S21::Tree<int, int> aue_swap;
    sorry.first = 10;
    sorry.second = 10;
    aue_swap.Insert(sorry);
    sorry.first = 29;
    sorry.second = 29;
    aue_swap.Insert(sorry);
    sorry.first = 2;
    sorry.second = 2;
    aue_swap.Insert(sorry);
    sorry.first = 1;
    sorry.second = 1;
    auto test = aue_swap.Insert(sorry);
    std::cout << "is_inserted: " << test.second << std::endl;

//    test = aue_swap.Insert(sorry);
//    std::cout << "is_inserted: " << test.second << std::endl;
    aue.Swap(aue_swap);




//    std::cout << tr.Empty() << std::endl;
//
//    std::map<int, int> m;
//    S21::Tree<int, int> my_m;
//    std::cout << m.max_size() << std::endl;
//    std::cout << my_m.MaxSize() << std::endl;


    /*
    REMOVE TEST

    sorry.first = 10;
    sorry.second = 10;
    tr.Insert(sorry);

    sorry.first = 5;
    sorry.second = 5;
    tr.Insert(sorry);

    sorry.first = 15;
    sorry.second = 15;
    tr.Insert(sorry);

    sorry.first = 4;
    sorry.second = 4;
    tr.Insert(sorry);

    sorry.first = 18;
    sorry.second = 18;
    tr.Insert(sorry);

    sorry.first = 13;
    sorry.second = 13;
    tr.Insert(sorry);

    sorry.first = 16;
    sorry.second = 16;
    tr.Insert(sorry);

    auto it = tr.Begin();
    std::cout << "Begin: " << it->first << std::endl;
    ++it;
    ++it;
    ++it;
    ++it;
    std::cout << "Begin: " << it->first << std::endl;
    std::cout << "Size: " << tr.Size() << std::endl;
    tr.Erase(it);
    std::cout << "Size: " << tr.Size() << std::endl;
    it = tr.Begin();
    ++it;
    std::cout << "Begin: " << it->first << std::endl;
    tr.Erase(it);
    std::cout << "Size: " << tr.Size() << std::endl;
    it = tr.Begin();
    ++it;
    std::cout << "Begin: " << it->first << std::endl;
    ++it;
    std::cout << "Begin: " << it->first << std::endl;
    ++it;
    std::cout << "Begin: " << it->first << std::endl;
    tr.Erase(it);
    std::cout << "Size: " << tr.Size() << std::endl;
    it = tr.Begin();
    ++it;
    std::cout << "Begin: " << it->first << std::endl;
    tr.Erase(it);
    std::cout << "Size: " << tr.Size() << std::endl;
    it = tr.Begin();
    ++it;
    tr.Erase(it);
    it = tr.Begin();
    tr.Erase(it);
    it = tr.Begin();
    tr.Erase(it);
    std::cout << "Size: " << tr.Size() << std::endl;

    REMOVE TEST
    */





//    tr.Erase(it);
////    ++it;
////    std::cout << "Begin: " << it->first << std::endl;
//    std::cout << "Size: " << tr.Size() << std::endl;
//    it = tr.Begin();
//    std::cout << "Begin: " << it->first << std::endl;
//    tr.Erase(it);
//    std::cout << "Size: " << tr.Size() << std::endl;
//    it = tr.Begin();
//    ++it;
//    tr.Erase(it);
//    it = tr.Begin();
//    tr.Erase(it);
////    std::cout << std::endl << "REMOVE" << std::endl << std::endl;
////    tr.Erase(it);
//    std::cout << "Size: " << tr.Size() << std::endl;
//    auto it2 = tr.Begin();
//    ++it2;
//    std::cout << "Begin: " << it2->first << std::endl;
//    tr.Erase(it2);
//    std::cout << std::endl << "REMOVE" << std::endl << std::endl;
//    std::cout << "Size: " << tr.Size() << std::endl;
//    it2 = tr.Begin();
//    ++it2;
//    tr.Erase(it2);
//    std::cout << std::endl << "REMOVE" << std::endl << std::endl;
//    std::cout << "Size: " << tr.Size() << std::endl;
//    it2 = tr.Begin();
//    std::cout << "Begin: " << it2->first << std::endl;
//    tr.Erase(it2);
//    std::cout << std::endl << "REMOVE" << std::endl << std::endl;
//    std::cout << "Size: " << tr.Size() << std::endl;

    return 0;
}
