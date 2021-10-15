#include <iostream>
#include <string>
#include<fstream>
#include<iomanip>
#include <algorithm> 
#include<vector>
using namespace std;

template<class T>
class List {
private:

	template<class T>
	class Node {
	public:
		Node(T data = T(), Node* pnext = nullptr) {
			this->data = data;
			this->pnext = pnext;
		}
		T data;
		Node* pnext;
	};
	int Size;
	Node<T>* head;
public:
	List();
	~List();
	void push_back(T);
	void push_front(T);
	void insert(T, int);
	void pop_front();
	void pop_back();
	void removeAt(int);
	void clear();
	Node<T>* begin() { return head; }
	int getSize() { return Size; }
	T& operator[](int);
	
	class Iterrator {
		Node<T>* ptr;
	public:
		Iterrator(Node<T>* ptr = nullptr){
			this->ptr = ptr;
		}
		Node<T>* operator++(int) {
			ptr = ptr->pnext;
			return	ptr;
		}
		Node<T>* operator++() {
			ptr = ptr->pnext;
			return	ptr;
		}
		T& operator*() {
			
			return	ptr->data;
		}
	};

};
template<class T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}
template<class T>
List<T>::~List()
{
	while (Size) {
		this->pop_front();
	}
}

template<class T>
void List<T>::push_back(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pnext != nullptr) {
			current = current->pnext;
		}
		current->pnext = new Node<T>(data);
	}
	this->Size++;
}

template<class T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<class T>
void List<T>::insert(T data, int index)
{
	if (index > Size)throw "Error";

	if (index == 0) {
		this->push_front(data);
	}
	if (index == Size) {
		this->push_back(data);
	}
	else {
		Node<T>* current = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->pnext;
		}

		current->pnext = new Node<T>(data, current->pnext);
		this->Size++;
	}
}

template<class T>
void List<T>::pop_front()
{
	if (this->head != nullptr) {
		Node<T>* poped = this->head;
		this->head = this->head->pnext;
		Size--;
		delete poped;
	}
	else {
		cout << "there is no else" << endl;
	}
}

template<class T>
void List<T>::pop_back()
{
	if (Size > 0) {
		Node<T>* current = this->head;
		Node<T>* current1 = this->head;

		while (current->pnext != nullptr) {
			current1 = current;
			current = current->pnext;
		}
		delete current->pnext;
		current1->pnext = nullptr;

		Size--;
	}
	else {
		cout << "there is no else" << endl;
	}
}

template<class T>
void List<T>::removeAt(int index)
{
	if (index >= Size)throw "ERROR";
	else if (index == 0)this->pop_front();
	else if (index == Size - 1)this->pop_back();
	else {
		Node<T>* current = this->head;
		Node<T>* current1 = this->head;
		int i = 0;
		while (i <= index) {
			if (i == index - 1)break;
			current = current->pnext;
			i++;
		}
		current1 = current->pnext;
		current->pnext = current->pnext->pnext;
		delete current1;
		Size--;
	}
}

template<class T>
void List<T>::clear()
{
	while (Size) {
		this->pop_front();
	}
}

template<class T>
T& List<T>::operator[](int a) {
	if (a >= this->Size)throw "Error";
	Node<T>* current = this->head;
	int i = 0;
	while (current->pnext != nullptr) {
		if (i == a)break;
		current = current->pnext;
		i++;
	}
	return current->data;
}
