#ifndef DLLIST_H
#define DLLIST_H

#include <cstdlib>
#include <iostream>
#include <cassert>

// списък с две връзки
template <typename T>
class DLList
{
    // структура, описваща елемент на списъка
    struct Node
    {
        T data;
        Node *prev, *next;

        Node(const T& newData)
            : data(newData), prev(NULL), next(NULL)
        {}
    };

    public:
        // итератор, bidirectional iterator
        template <typename Container = DLList<T>, typename NodeType = Node, typename ValueType = T>
        class Iterator
        {
            friend class DLList<T>;
            public:

            // извличане на стойност
            ValueType& operator *()
            {
                assert(position);
                return position->data;
            }
            // извличане на стойност през const_iterator
            const ValueType& operator *() const
            {
                assert(position);
                return position->data;
            }
            // преобразуване до bool
            operator bool() const
            {
                return position != NULL;
            }

            Iterator& operator++()
            {
                if(position)
                    position = position->next;

                return *this;
            }

            Iterator operator++(int)
            {
                Iterator old = *this;
                ++(*this);
                return old;
            }

            Iterator& operator--()
            {
                if(position)
                    position = position->prev;

                return *this;
            }

            Iterator operator--(int)
            {
                Iterator old = *this;
                --(*this);
                return old;
            }

            bool operator == (const Iterator& other)
            {
                return this->owner == other.owner && this->position == other.position;
            }

            bool operator != (const Iterator& other)
            {
                return !(*this == other);
            }

            private:
                NodeType* position;
                Container* owner;

                Iterator(NodeType* pos, Container* o)
                    : position(pos), owner(o)
                {}

                NodeType* operator->()
                {
                    return position;
                }
        };

        typedef Iterator<DLList<T>, Node, T> iterator;
        typedef Iterator<const DLList<T>, const Node, const T> const_iterator;

    public:
        DLList() : first(NULL), last(NULL)
        {}

        DLList(const DLList<T>& other)
        {
            copyList(other);
        }

        DLList<T>& operator = (const DLList<T>&);

        ~DLList()
        {
            deleteList();
        }

        // итератор към първия елемент в списъка
        iterator begin()
        {
            return iterator(first, this);
        }

        // константен итератор към първия елемент в списъка
        const_iterator begin() const
        {
            return const_iterator(first, this);
        }

        // итератор към последния елемент в списъка
        // !!! при обхождане, ако се използва iter != list.end() в условие,
        // последния елемент няма да бъде обработен
        iterator end()
        {
            return iterator(last, this);
        }

        // константен итератор към последния елемент в списъка
        const_iterator end() const
        {
            return const_iterator(last, this);
        }

        bool isEmpty() const
        {
            return first == NULL;
        }

        // добавяне на елемент в края на списъка
        void push_back(const T&);
        // добавяне на елемент след определена позиция
        void insert(iterator, const T&);

        // изтриване на елемент на определена позиция
        // итераторът става невалиден,
        // като резултат се връща итератор следващата позиция
        iterator erase(iterator&);

        // предефиниране на операцията за изход
        friend std::ostream& operator << (std::ostream& out, const DLList<T>& l)
        {
            for(const_iterator iter = l.begin(); iter; ++iter)
            {
                out << *iter << ' ';
            }

            return out;
        }

    private:
        Node *first, *last;

        void copyList(const DLList<T>&);
        void deleteList();
};

template<typename T>
inline void DLList<T>::deleteList()
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

template<typename T>
inline void DLList<T>::push_back(const T& newData)
{
    Node* newElem = new Node(newData);
    if(!first)
    {
        // празен списък
        first = newElem;
    }
    else
    {
        newElem->prev = last;
        last->next = newElem;
    }

    last = newElem;
}

template<typename T>
inline void DLList<T>::copyList(const DLList<T>& other)
{
    Node* current = other.first;
    while(current)
    {
        this->push_back(current->data);
        current = current->next;
    }
}

template<typename T>
inline DLList<T>& DLList<T>::operator = (const DLList<T>& right)
{
    if(this != &right)
    {
        deleteList();
        copyList(right);
    }

    return *this;
}

// добавяне след указан елемент
template<typename T>
inline void DLList<T>::insert(DLList<T>::iterator iter, const T& newElem)
{
    if(!iter && !isEmpty()) return;

    assert(iter && this == iter.owner);

    if(isEmpty() || iter.position == last)
    {
        push_back(newElem);
    }
    else
    {
        Node* newNode = new Node(newElem);

        newNode->next = iter->next;
        newNode->prev = iter.position;

        iter->next = newNode;
        Node* nextNode = iter->next;
        nextNode->prev = newNode;
    }
}

template<typename T>
inline
typename DLList<T>::iterator DLList<T>::erase(DLList<T>::iterator& iter)
{
    if(!iter) return iter;

    assert(this == iter.owner);

    iterator next = iter;
    ++next;

    Node* forDel = iter.position;
    if(forDel == first)
    {
        first = first->next;
        if(!first)
        {
            last = NULL;
        }
        else
        {
            first->prev = NULL;
        }
    }
    else
    {
        // при списък с една връзка, може елементът след iter
        // да бъде прехвърлен на iter и да се изтрие следващия
        Node* before = iter->prev, *after = iter->next;
        before->next = after;

        if(iter.position == last)
        {
            // after == NULL
            last = before;
            next = end();
        }
        else
        {
            after->prev = before;
        }
    }

    iter.position = NULL;
    delete forDel;

    return next;
}

#endif // DLLIST_H
