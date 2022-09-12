#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

template <class T>
struct Node
{
    T data;
    Node<T> * next;
};

template <typename T>
class LinkedList
{
private:
    /* data */
    Node<T>* head;
    size_t getTotalSize();

public:
    //LinkedList(/* args */);
    ~LinkedList();

    void pop(size_t idx); //idx should start from 0
    void push(T _data);
    

    LinkedList<T> sort();
    std::string listToString();
    LinkedList<T> add(LinkedList<T>& l1, LinkedList<T>& l2); //sequentially add two linked lists

};

#endif