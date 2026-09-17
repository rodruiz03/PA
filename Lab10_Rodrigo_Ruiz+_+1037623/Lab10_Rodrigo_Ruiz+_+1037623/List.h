#pragma once
#include "pch.h"
#include <stdexcept>

class List {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

private:
    Node* header = nullptr;
    int size = 0;

public:
    void Add(int item);
    void Clear();
    int Count() const { return size; }
    bool Contains(int item);
    int IndexOf(int item);
    void Insert(int index, int item);
    int GetItem(int index);
    void SetItem(int index, int item);
    int LastIndexOf(int item);
    bool Remove(int item);
    void RemoveAt(int index);
    ~List();
};

