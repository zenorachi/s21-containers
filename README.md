# S21-Containers

The "S21-Containers" project is a collection of container implementations similar to the containers in the C++ Standard Library. These containers provide convenient data structures for storing and managing collections of elements.

## Features

- The project includes the following containers:
  - [Vector](https://en.cppreference.com/w/cpp/container/vector), [Array](https://en.cppreference.com/w/cpp/container/array)
  - [List](https://en.cppreference.com/w/cpp/container/list)
  - [Queue](https://en.cppreference.com/w/cpp/container/queue), [Stack](https://en.cppreference.com/w/cpp/container/stack)
  - [Map](https://en.cppreference.com/w/cpp/container/map), [Set](https://en.cppreference.com/w/cpp/container/set), [Multiset](https://en.cppreference.com/w/cpp/container/multiset)

- The containers offer an interface similar to the C++ Standard Library, making it easy to adapt and understand the code.

## Installation and Usage

1. Clone the repository:
```sh
git clone https://github.com/zenorachi/s21-containers.git
 ```
2. Navigate to s21-containers:
```sh
cd s21-containers:
 ```
3. Use the `.h` files to include the containers in your code.

## Example Usage

```cpp
#include "s21_containers.h"

int main() {
 s21::vector<int> myVector;
 
 myVector.push_back(10);
 myVector.push_back(20);
 myVector.push_back(30);
 
 std::cout << myVector[0] << " ";
 
 return 0;
}
```
