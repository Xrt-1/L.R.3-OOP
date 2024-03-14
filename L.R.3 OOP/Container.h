#pragma once
#include <iostream>


template <typename T>
class Container {
private:
	int size;
	template <typename T>
	class Node {
	public:
		T value;
		Node<T>* NextObj;
		Node<T>(T val = T(), Node* next = nullptr) {
			value = val;
			NextObj = next;
		}
	};
	Node<T>* firstObj;
public:
	Container<T>() {
		firstObj = nullptr;
		size = 0;
	}
	Container<T>(T object) {
		firstObj = new Node<T>(object);
		size = 1;
	}
	~Container<T>() {
		Node<T>* elem = firstObj;
		Node<T>* r;
		while (elem != nullptr) {
			r = elem->NextObj;
			delete elem;
			elem = r;
		}
	}
	void push_back (T value) {
		if (firstObj == nullptr) {
			firstObj = new Node<T> (value);
		}
		else {
			Node<T>* elem = firstObj;
			while ((elem->NextObj) != nullptr) {
				elem = (elem->NextObj);
			}
			(elem->NextObj)= new Node<T> (value);
		}
		size++;
	}
	void push_forward(T value) {
		if (firstObj == nullptr) {
			firstObj = new Node<T> (value);
		}
		else {
			Node<T>* newFirst = new Node<T> (value);
			newFirst->NextObj = firstObj;
			firstObj = newFirst;
		}
		size++;
	}
	void push_inside(T value, int index) {  //вставляет элемент на индекс index, передвигая тот, что был там
		Node<T>* elem = new Node<T>(value);
		Node<T>* oldThis = firstObj;
		Node<T>* prev = nullptr;
		int count = 0;
		if (index == 0) {
			firstObj = elem;
			elem->NextObj = oldThis;
			size++;
		}
		else if (index<size && index >= 0)
		{
			while (oldThis != nullptr) {
				if (count == (index - 1)) {
					prev = oldThis;
				}
				else if (count == index) {
					prev->NextObj = elem;
					elem->NextObj = oldThis;
				}
				oldThis = oldThis->NextObj;
				count++;
			}
			size++;
		}
		
	}

	void show_values() {
		Node<T>* elem = firstObj;
		std::cout << "contained elements: ";
		for (int i = 0; i < size;) {
			std::cout << elem->value << "; ";
			elem = elem->NextObj;
			i += 1;
		}
		std::cout << "\n";
	}

	T& operator [](const int index) {
		Node<T>* elem = firstObj;
		int count = 0;
		while (elem != nullptr) {
			if (count == index) {
				return elem->value;
			}
			elem = elem->NextObj; 
			count++;
		}
	}
};