#include <iostream>
#include <iterator>

#include "LinkedList.h"

int main()
{
    LinkedList<int> l;
    for(int i = 1; i <= 10; ++i)
    {
        l.push_back(i);
    }

    std::cout << l << std::endl;


    LinkedList<int>::iterator iter = l.begin();
    std::cout << "First elem: " << *iter << " will be deleted!" << std::endl;

    // изтриване на първия елемент
    iter = l.erase(iter);

    std::cout << "First element after deleted one: " << *iter << std::endl;
    std::cout << l << std::endl;

    // преместваме итератора с 5 позиции напред
    for(int i = 1; i <= 5; ++i)
    {
        ++iter;
    }

    // изтриване на елемент от произволна позиция
    std::cout << "Iterator at element: " << *iter << std::endl;
    iter = l.erase(iter);

    std::cout << "First element after deleted one: " << *iter << std::endl;
    std::cout << l << std::endl;

    // изтриване на последния елемент
    iter = l.end();
    std::cout << "Iterator at last element: " << *iter << " It will be deleted!\n";
    iter = l.erase(iter);

    std::cout << "After deletion, iterator at element: " << *iter << std::endl;
    std::cout << l << std::endl;

    // добавяне на елемент преди края
    l.insert(iter, 10);
    std::cout << "Insert element before last one\n";
    std::cout << l << std::endl;

    // добавяне на елемент в началото на списъка
    iter = l.begin();
    l.insert(iter, 1);

    std::cout << "Insert element before the first one\n";
    std::cout << l << std::endl;

    std::cout << "Merging sorted lists...\n";

    LinkedList<int> leftList, rightList;
    for(int i = 1; i <= 10; ++i)
    {
        if(i % 2 == 0)
        {
            leftList.push_back(i);
        }
        else
        {
            rightList.push_back(i);
        }
    }

    std::cout << "First: " << leftList << std::endl;
    std::cout << "Second: " << rightList << std::endl;

    LinkedList<int> result = leftList.merge(rightList);
    std::cout << "Result: " << result << std::endl;
}
