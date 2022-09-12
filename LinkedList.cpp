#include "LinkedList.hpp"

// template <typename T>
// LinkedList<T>::LinkedList(/* args */)
// {
// }

template <typename T>
void LinkedList<T>::push(T _data)
{
    if(this->head == nullptr)
    {    
        this->head = new Node<T>;
        this->head->data = _data;
        return;
    } 

    Node<T>* n = this->head;
    while(n->next!=nullptr)
    {
        n = n->next;
    }
    n->next = new Node<T>;
    n->next->data = _data;
}


template <typename T>
void LinkedList<T>::pop(size_t idx)
{
    Node<T>* n = this->head;
    for(size_t i =0; i<idx; i++)
    {
        n = n->next;
    }
    n->next = n->next->next;
}


//Get Total size of currently maintained LinkedList
template <typename T>
size_t LinkedList<T>::getTotalSize()
{
    if(this->head == nullptr)
        return 0;

    size_t size = 1;
    Node<T>* n = this->head;
    while(n->next!=nullptr)
    {
        n = n->next;
        size++;
    }
    return size;
}

//RETURNS a sorted LinkedList
template <typename T>
LinkedList<T> LinkedList<T>::sort()
{
    LinkedList<T> _sortedList;

    //TODO: Implement QuickSort here
    std::vector<T> _tVec;
    Node<T>* n = this->head;
    while(n->next!=nullptr)
    {
        _tVec.push_back(n->data);
        n = n->next;
    }
    _tVec.push_back(n->data);   //TODO: Check !!

    std::sort(_tVec.begin(), _tVec.end(), std::greater<T>());

    for(T _dataItem:_tVec)
    {

        _sortedList.push(_dataItem);
    } 

    return _sortedList;
}


template <typename T>
std::string LinkedList<T>::listToString()
{
    std::string _tString = "[";
    Node<T>* n = this->head;
    while(n->next!=nullptr)
    {
        _tString.append(n->data);
        _tString.append(", ");
        n = n->next;
    }
    _tString.append(n->data);   //TODO: Check !!
    _tString.append("]");

    return _tString;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    this->head = nullptr;
}
