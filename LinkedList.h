//
// Created by Blood on 13.12.2020.
//

#ifndef COMMANDSYSTEM_LINKEDLIST_H
#define COMMANDSYSTEM_LINKEDLIST_H


template <class T> class LinkedList {
private:
    class Node {
    public:
        Node(T object) {
            this->object = object;
            next = nullptr;
        }
        T object;
        Node* next;
    };
    Node* first;
    Node* iterator = nullptr;
    int size;
public:
    LinkedList() {
        first = nullptr;
        size = 0;
    }
    void add(T object) {
        size++;
        if (first == nullptr) {
            first = new Node(object);
            return;
        }
        Node* per_next = first;
        Node* next = first->next;
        while (true) {
            if (next == nullptr) {
                next = new Node(object);
                per_next->next = next;
                break;
            }
            per_next = next;
            next = next->next;

        }
    }
    void remove(T object) {
        if (first->object == object) {
            if (first->next == nullptr) {
                delete first;
                first = nullptr;
            }
            else {
                Node* node = first->next;
                delete first;
                first = node;
            }
            size--;
            return;
        }
        Node* per_next = first;
        Node* next = first->next;
        while (true) {
            if (next == nullptr) {
                return;
            }
            if (next->object == object) {
                if (next->next == nullptr) {
                    delete next;
                    per_next->next = nullptr;
                }else {
                    Node* node = next->next;
                    delete next;
                    per_next->next = node;
                }
                size--;
                return;
            }
            per_next = next;
            next = per_next->next;
        }
    }
    T operator [] (int index) {
        if (index >= size || index < 0) throw "Illegal argument into linked list";
        Node* node = first;
        for (int i = 0; i < size; i++) {
            if (i == index) return node->object;
            node = node->next;
        }
    }
    int getSize() {
        return size;
    }
    bool empty() {
        return first == nullptr;
    }
    void set(int index, T object) {
        if (index < 0 || index > size) throw "illegalg argument exception";
        if (index == 0) {
            Node* node = new Node(object);
            node->next = first;
            first = node;
            size++;
            return;
        }
        Node* prev = first;
        Node* next = first->next;
        for (int i = 1; i < size; i++) {
            if (i == index) {
                Node* node = new Node(object);
                node->next = next;
                prev->next = node;
                size++;
                return;
            }
            prev = next;
            next = prev->next;
        }
    }
    void updateIterator() {
        iterator = first;
    }
    bool hasNext() {
        return iterator == nullptr;
    }
    T next() {
        T object = iterator->object;
        iterator = iterator->next;
        return object;
    }
};



#endif //COMMANDSYSTEM_LINKEDLIST_H
