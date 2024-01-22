#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "Node.hpp"

template <class T>
class List : public Node<T>{
public:
    List<T>() : m_head(nullptr) {}
    ~List<T>() = default;

private:   
    Node<T>* m_head;

public:
    void add_node(T);
    void remove_node(T);
    void insert_after(int, T);
    void print_list();
};
template <class T>
void List<T>::add_node(T new_val)
{
    if(m_head == nullptr){
        Node<T>* new_node = new Node<T>(new_val);
        m_head = new_node;
    }else{
        Node<T>* new_node = new Node<T>(new_val);
        new_node->set_next(m_head);
        m_head = new_node;
    }
}

template <class T>
void List<T>::remove_node(T del_val) {
    if (m_head == nullptr) {
        std::cout << "Your list is empty." << std::endl;
        return;
    }

    Node<T>* current = m_head;
    Node<T>* prev = nullptr;

    while (current != nullptr) {
        if (del_val == current->get_val()) {
            if (current == m_head) {
                m_head = current->get_next();
            } else {
                prev->set_next(current->get_next());
            }

            delete current;
            return;
        }

        prev = current;
        current = current->get_next();
    }

    std::cout << "Node with that value was not found." << std::endl;
}

template <class T>
void List<T>::insert_after(int position, T value) {
    if (m_head == nullptr) {
        std::cout << "Your list is empty." << std::endl;
        return;
    }

    Node<T>* current = m_head;

    while (position > 1 && current != nullptr) {
        --position;
        current = current->get_next();
    }

    if (position > 1 || current == nullptr) {
        std::cout << "Position out of range." << std::endl;
        return;
    }
    
    Node<T>* new_node = new Node<T>(value);

    new_node->set_next(current->get_next());
    current->set_next(new_node);
}

template <class T>
void List<T>::print_list(){
    if(m_head == nullptr){
        std::cout << "Your list is empty: " << std::endl;
        return;
    }
    Node<T>* current = m_head;
    while(current != nullptr){
        std::cout << current->get_val() << " -> ";
        current = current->get_next();
    }
    std::cout << std::endl;
}
#endif // LIST_HPP