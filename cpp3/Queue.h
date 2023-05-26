#pragma once
#include <cstddef>

using namespace std;

template<class T>
class Queue
{

public:

	Queue();

	~Queue();

	// ���������� ���������� ��������� � ���������� queue.
	size_t size() const;

	// ���������� ������ �� ��������� � �������� ������� ����������� ������� � ����� queue.
	T& back();

	// ���������, ���� �� queue.
	bool empty() const;

	// ���������� ������ �� ������ ������� � ������ queue.
	T& front();

	// ������� ������� �� ������ queue.
	void pop();

	// ��������� ������� � ����� queue.
	void push(const T& val);

private:
	struct Node {
		T data;
		Node* next;
		Node(const T& val) : data(val), next(nullptr) {}
	};

	Node* head;
	Node* tail;
	size_t sz;
};


template<class T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), sz(0) {}

template<class T>
Queue<T>::~Queue() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template<class T>
size_t Queue<T>::size() const {
    return sz;
}

template<class T>
T& Queue<T>::back() {
    return tail->data;
}

template<class T>
bool Queue<T>::empty() const {
    return head == nullptr;
}

template<class T>
T& Queue<T>::front() {
    return head->data;
}

template<class T>
void Queue<T>::pop() {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    sz--;
}

template<class T>
void Queue<T>::push(const T& val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    sz++;
}