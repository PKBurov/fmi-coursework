#include "DLList.h"

int main()
{
    DLList<int> l;
    for(size_t i = 1; i <=7; ++i)
        l.push_back(i);

    std::cout << l << std::endl;

    std::cout << "Forward to position 5....\n";

    DLList<int>::iterator iter = l.begin();
    for(size_t i = 1; i <= 5; ++i)
    {
        ++iter;
    }

    std::cout << "Element at position 5: " << *iter << std::endl;
    std::cout << "It will be deleted...\n";

    DLList<int>::iterator next = iter;
    ++next;

    l.erase(iter);

    std::cout << "Result: " << l << std::endl;

    int newElem = 13;
    std::cout << "Insert " << newElem << " after " << *next << std::endl;
    l.insert(next, newElem);

    std::cout << "Result: " << l << std::endl;

    return 0;
}
