#include "Frankenstain_List.h"
#include <iostream>


template<typename T> 
Node<T>::Node(T value) 
{
    data = value;
    next = prev = sm = gt = nullptr;
}
 

template<typename T> 
FrankenstainList<T>::FrankenstainList()
{
    head = tail = nullptr;
    size = 0;
}


template<typename T>
FrankenstainList<T>::~FrankenstainList()
{
}


template<typename T>
void FrankenstainList<T>::push_front(T value)
{
    Node<T>* temp = new Node(value);
 
    if (head == nullptr)
        head = tail = temp;
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    size++;
    PutSorted(temp);
}


template<typename T>
void FrankenstainList<T>::push_back(T value)
{
    Node<T>* temp = new Node(value);
 
    if (tail == nullptr)
        head = tail = temp;
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    size++;
    PutSorted(temp);
}
 

template<typename T> 
int FrankenstainList<T>::delete_front()
{
    if (!is_empty())
    {
        Node<T>* temp = head;
        if (head == tail)
        {
            tail = nullptr;
        }
        int delValue = temp->data;
        head = head->next;
 
        delete temp;
 
        size--;
 
        return delValue;
 
    }
    return 0;
}


template<typename T>
int FrankenstainList<T>::delete_back()
{
    if (!is_empty())
    {
        Node<T>* temp = tail;
        if (head == tail)
        {
            head = nullptr;
        }
        int delValue = temp->data;
        tail->next = nullptr;
        tail = tail->prev;
 
        delete temp;
 
        size--;
 
        return delValue;
 
    }
    return 0;
}


template<typename T>
bool FrankenstainList<T>::is_empty()
{
    if (size <= 0)
    {
        return true;
    }
 
    return false;
}


template<typename T>
void FrankenstainList<T>::display()
{
    Node<T>* temp = head;
 
    std::cout << "Display in forward order\n";
    while (temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << " NULL";
}


template<typename T>
int FrankenstainList<T>::length()
{
    return size;
}
 

template<typename T> 
void FrankenstainList<T>::search(T value)
{
    if (!is_empty())
    {
        Node<T>* temp = head;
        while (temp)
        {
            if (temp->data == value)
            {
                std::cout << "YES! got it." << std::endl;
                break;
            }
            temp = temp->next;
        }
    }
    else
    {
        std::cout << "List is empty" << std::endl;
    }
}


template<typename T>
void FrankenstainList<T>::PutSorted(Node<T>* tmp)
{
    if(tmp != nullptr)
    return;


    if (greater != nullptr){
        greater = tmp;
        smaller = tmp;
        return;
    }

    Node<T>* current = head;
    while (current->data < tmp->data && current->gt == nullptr)
    {
        current = current->gt;
    }

    if(current->data < tmp->data)
    {
        tmp->gt = current->gt;
        current->gt = tmp;
        tmp->sm = current;

        if(tmp->gt != nullptr)
        {
            smaller = tmp;
        }
    }
    else
    {
    tmp->sm = current->sm;
    if (current->sm == nullptr)
    {
        current->sm->gt = tmp;
    }
    else
    {
        greater = tmp;
    }
        tmp->gt = current;
        current->sm = tmp;
    }
}
