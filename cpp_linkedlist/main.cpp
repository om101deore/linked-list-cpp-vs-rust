#include <iostream>
#include "ll.h"

int main(int argc, char* argv[]) {
    LinkedList<int> ll;

    ll.push(10);
    ll.push(11);
    ll.push(12);

    ll.traverse();

    try {
        std::cout << "Popped value: " << ll.pop() << std::endl;
        std::cout << "Popped value: " << ll.pop() << std::endl;
        std::cout << "Popped value: " << ll.pop() << std::endl;
        std::cout << "Popped value: " << ll.pop() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught an error" << e.what() <<"\n";
    }

    ll.traverse();

    return 0;
}
