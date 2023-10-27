#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>
#include <cassert>

template <typename T>
class LinkedList
{
    private:

        struct Node
        {
            T data;
            Node* next;

            Node(const T& theData)
                : data(theData), next(NULL)
            {}
        };

    public:
        // вграден клас Итератор (капсулира указател към елемент на списъка)
        template<typename Container = LinkedList<T>, typename NodeType = Node, typename ValueType = T>
        class Iterator
        {
            friend class LinkedList<T>;

            private:
            // кой е списъкът, който ще се обхожда
            Container* owner;
            NodeType* current;

            // private конструктор, така не може да се създаде обект,
            // освен през приятелския клас
            Iterator(Container* list, NodeType* position = NULL)
                : owner(list), current(position)
            {}

            NodeType* operator->()
            {
               return current;
            }

            public:

                // префиксен ++
                Iterator& operator ++ ()
                {
                    if(current)
                    {
                        current = current->next;
                    }

                    return *this;
                }
                // постфиксен ++
                Iterator operator ++(int)
                {
                    Iterator oldValue = *this;
                    ++ (*this);
                    return oldValue;
                }

                // извличане на стойност
                ValueType& operator*()
                {
                    assert(current);
                    return current->data;
                }

                const ValueType& operator*() const
                {
                    assert(current);
                    return current->data;
                }

                // преобразуване към bool
                operator bool () const
                {
                    return current != NULL;
                }

                // предефинирана операция за сравнение ==
                bool operator == (const Iterator& right) const
                {
                    return owner == right.owner && current == right.current;
                }
                // предефинирана операция за сравнение !=
                bool operator != (const Iterator& right) const
                {
                    return !(*this == right);
                }
        };

        typedef Iterator< LinkedList<T>, Node, T> iterator;
        typedef Iterator< const LinkedList<T>, const Node, const T> const_iterator;

    public:

        LinkedList()
            : first(NULL), last(NULL)
        {}

        LinkedList(const LinkedList<T>& other)
        {
            copyList(other);
        }

        LinkedList<T>& operator = (const LinkedList<T>&);
        ~LinkedList()
        {
            deleteList();
        }

        // итератор към началото на списъка
        iterator begin() // const, ако се дефинира const_iterator
        {
            return iterator(this, first);
        }

        const_iterator begin() const
        {
            return const_iterator(this, first);
        }

        // итератор към края на списъка
        iterator end() // const, ако се дефинира const_iterator
        {
            return iterator(this, last);
        }

        const_iterator end() const
        {
            return const_iterator(this, last);
        }

        bool isEmpty() const
        {
            return first == NULL;
        }

        // добавяне на елемент в края на списъка
        void push_back(const T&);
        // добавяне на елемент преди определена позиция
        void insert(iterator, const T&);

        // изтриване на елемент на определена позиция
        // връща като резултат итератор към позицията след изтрития елемент
        iterator erase(iterator);

        // предефинирана операция за изход
        friend std::ostream& operator << (std::ostream& out, const LinkedList<T>& l)
        {
            for(const_iterator iter = l.begin(); iter; ++iter)
            {
                out << *iter << ' ';
            }

            return out;
        }

        // сливане на два сортирани списъка
        LinkedList<T> merge(const LinkedList<T>&) const;

    private:
        // Указатели към първия и последния елемент в списъка
        Node *first, *last;

        // помощни функции, които се използват в copy ctor, op = , dtor
        void copyList(const LinkedList<T>& other);
        void deleteList();

        // връща итератор към предходната позиция
        iterator getPrevious(iterator);
        // добавяне на елемент след определена позиция
        void insertAfter(iterator, const T&);
};

template <typename T>
inline void LinkedList<T>::copyList(const LinkedList<T>& other)
{
    for(const_iterator iter = other.begin(); iter; ++iter)
    {
        this->push_back(*iter);
    }
}

template <typename T>
inline void LinkedList<T>::deleteList()
{
    Node* current = first;
    while(first)
    {
        first = first->next;
        delete current;
        current = first;
    }

    last = NULL;
}

template <typename T>
inline LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& right)
{
    if(this != &right)
    {
        deleteList();
        copyList(right);
    }

    return *this;
}

// връща итератор към предходната позиция
template <typename T>
inline
typename LinkedList<T>::iterator LinkedList<T>::getPrevious(iterator position)
{
    iterator previous = begin(), next = previous;
    ++next;

    while(next && next != position)
    {
        previous = next;
        ++next;
    }

    return previous;
}
// добавяне на елемент след определена позиция
template <typename T>
inline
void LinkedList<T>::insertAfter(iterator position, const T& newElem)
{
    if(!isEmpty()&& !position) return;

    Node* newNode = new Node(newElem);
    if(isEmpty())
    {
        first = last = newNode;
    }
    else
    {
        newNode->next = position->next;
        position->next = newNode;

        if(position.current == last)
        {
            last = newNode;
        }
    }
}

// добавяне на елемент в края на списъка
template <typename T>
inline
void LinkedList<T>::push_back(const T& newElem)
{
    Node* newNode = new Node(newElem);
    if(first == NULL)
    {
        first = newNode;
    }
    else
    {
        last->next = newNode;
    }

    last = newNode;
}

// добавяне на елемент преди определена позиция
template <typename T>
void LinkedList<T>::insert(iterator position, const T& newElem)
{
    assert(this == position.owner);

    if(!position)
    {
        push_back(newElem);
        return;
    }

    if(position == begin())
    {
        Node* newNode = new Node(newElem);
        newNode->next = first;
        first = newNode;

        if(!last)
        {
            last = newNode;
        }
    }
    else
    {
        iterator previous = getPrevious(position);
        insertAfter(previous, newElem);
    }
}

// изтриване на елемент на определена позиция
// връщаме итератор към първата позиция след изтритата
template <typename T>
inline
typename LinkedList<T>::iterator LinkedList<T>::erase(iterator position)
{
    assert(this == position.owner);
    assert(position);

    iterator next = position;
    ++next;

    if(position == begin())
    {
        first = first->next;
        if(first == NULL)
            last = NULL;
    }
    else
    {
        iterator previous = getPrevious(position);
        previous->next = position->next;

        if(position == end())
        {
            last = previous.current;
            // ако изтрием последния елемент в списъка,
            // връщаме итератор към новия последен
            next = end();
        }
    }

    delete position.current;
    position.current = NULL;

    return next;
}

// Дефиниране на методите на итератора извън декларацията на класа
//template <typename T>
//template <typename Container, typename NodeType, typename ValueType>
//typename LinkedList<T>::template Iterator<Container, NodeType, ValueType>& LinkedList<T>::Iterator<Container, NodeType, ValueType>::operator ++()
//{
//    if(current)
//    {
//        current = current->next;
//    }
//
//    return *this;
//}

// сливане на два сортирани във възходящ ред списъка
template <typename T>
inline
LinkedList<T> LinkedList<T>::merge(const LinkedList<T>& other) const
{
    LinkedList<T> result;

    const_iterator iter = begin(), otherIter = other.begin();

    while(iter && otherIter)
    {
        if(*iter < *otherIter)
        {
            result.push_back(*iter);
            ++iter;
        }
        else
        {
            result.push_back(*otherIter);
            ++otherIter;
        }
    }

    while(iter)
    {
        result.push_back(*iter);
        ++iter;
    }

    while(otherIter)
    {
        result.push_back(*otherIter);
        ++otherIter;
    }

    return result;
}

#endif // LINKEDLIST_H
