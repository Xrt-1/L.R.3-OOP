#pragma once
#include <iostream>
template <typename T>

class Container {
private:
	int size;
	Node<T> *firstObj;
	class Node {
	public:
		T value;
		Node* NextObj;
		Node(T val, Node* next) {
			value = val;
			NextObj = next;
		}
		Container<T>() {
			firstObj = nullptr;
			size = 0;
		}
	};
public:
	Container() {
		number = 0;
	}
	

};