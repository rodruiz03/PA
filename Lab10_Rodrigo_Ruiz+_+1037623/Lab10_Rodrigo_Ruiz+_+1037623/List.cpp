#include "List.h"

void List::Add(int item) {
    Node* newNode = new Node(item);
    if (!header) {
        header = newNode;
    }
    else {
        Node* current = header;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

void List::Clear() {
    while (header) {
        Node* temp = header;
        header = header->next;
        delete temp;
    }
    size = 0;
}

bool List::Contains(int item) {
    Node* current = header;
    while (current) {
        if (current->data == item) return true;
        current = current->next;
    }
    return false;
}

int List::IndexOf(int item) {
    Node* current = header;
    int index = 0;
    while (current) {
        if (current->data == item) return index;
        current = current->next;
        index++;
    }
    return -1;
}

void List::Insert(int index, int item) {
    if (index < 0 || index > size) throw std::out_of_range("Index out of range");
    Node* newNode = new Node(item);
    if (index == 0) {
        newNode->next = header;
        header = newNode;
    }
    else {
        Node* current = header;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
}

int List::GetItem(int index) {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    Node* current = header;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void List::SetItem(int index, int item) {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    Node* current = header;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = item;
}

int List::LastIndexOf(int item) {
    int lastIndex = -1;
    int index = 0;
    Node* current = header;
    while (current) {
        if (current->data == item) lastIndex = index;
        current = current->next;
        index++;
    }
    return lastIndex;
}

bool List::Remove(int item) {
    Node** current = &header;
    while (*current) {
        if ((*current)->data == item) {
            Node* temp = *current;
            *current = (*current)->next;
            delete temp;
            size--;
            return true;
        }
        current = &((*current)->next);
    }
    return false;
}

void List::RemoveAt(int index) {
    if (index < 0 || index >= size) throw std::out_of_range("Index out of range");
    Node** current = &header;
    for (int i = 0; i < index; i++) {
        current = &((*current)->next);
    }
    Node* temp = *current;
    *current = (*current)->next;
    delete temp;
    size--;
}

List::~List() {
    Clear();
}
