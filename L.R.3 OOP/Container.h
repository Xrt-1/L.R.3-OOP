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
		delete firstObj;
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
		size += 1;
	}
};