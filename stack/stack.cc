#include "s21_stack.hpp"
#include <stack>

int main() {
    S21::Stack<int> b;
    b.Push(1);
    std::cout << b.Top() << std::endl;
    std::cout << "Size: " << b.Size() << std::endl;
    b.Push(2);
    std::cout << b.Top() << std::endl;
    std::cout << "Size: " << b.Size() << std::endl;
    b.Push(3);
    std::cout << b.Top() << std::endl;
    std::cout << "Size: " << b.Size() << std::endl;

    std::cout << std::endl;

    S21::Stack<int> a(b);
//    std::cout << "a Top: " << a.Top() << std::endl;
//    std::cout << "a Size: " << a.Size() << std::endl;
////    a.Pop();
//    std::cout << "a Top: " << a.Top() << std::endl;
//    std::cout << "a Size: " << a.Size() << std::endl;
////    a.Pop();
//    std::cout << "a Top: " << a.Top() << std::endl;
//    std::cout << "a Size: " << a.Size() << std::endl;
////    a.Pop();
//    std::cout << "b Top: " << b.Top() << std::endl;
//
    S21::Stack<int> c;
//    std::cout << "c Top: " << c.Top() << std::endl;

    a.Swap(c);
//    std::cout << "a: " << a.Top() << std::endl;
//    std::cout << "a Size: " << a.Size() << std::endl;
//    a.Pop();
//    std::cout << "a: " << a.Top() << std::endl;
//    std::cout << "a Size: " << a.Size() << std::endl;
//    a.Pop();
//    std::cout << "a: " << a.Top() << std::endl;
//    std::cout << "a Size: " << a.Size() << std::endl;
//    a.Pop();

    std::cout << "c: " << c.Top() << std::endl;
    a = c;
    std::cout << "a: " << a.Top() << std::endl;
    std::cout << "a Size: " << a.Size() << std::endl;

    S21::Stack<int> d(std::move(a));
    std::cout << d.Top() << std::endl;
    return 0;
}
