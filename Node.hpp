#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <class T>
class Node
{
public:
    Node<T>(T);
    Node<T>() = default;
    ~Node<T>() = default;

private:
    Node<T>* m_next;
    T m_val;

public:
    T get_val();
    void set_val(T);
    void set_next(Node*);
    Node<T>* get_next();
};

template <class T>
Node<T>::Node(T new_val) : m_val(new_val), m_next(nullptr){}

template <class T>
T Node<T>::get_val(){
    return m_val;
}

template <class T>
void Node<T>::set_val(T new_val){
    m_val = new_val;
}

template <class T>
void Node<T>::set_next(Node* new_next){
    m_next = new_next;
}

template <class T>
Node<T>* Node<T>::get_next(){
    return m_next;
}
#endif // NODE_HPP