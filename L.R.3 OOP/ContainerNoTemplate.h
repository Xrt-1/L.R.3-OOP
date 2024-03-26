//#pragma once
//#include <iostream>
//#include "Classes.h"
//
//class ContainerNT {
//private:
//	class Node {
//	public:
//		Object* value;
//		Node* NextObj;
//		Node(Object* val, Node* nxt = nullptr) {
//			value = val;
//			NextObj = nxt;
//		}
//	};
//	Node* firstobj;
//	int size;
//public:
//	ContainerNT(){
//		firstobj = nullptr;
//		size = 0;
//	}
//	ContainerNT(Object obj) {
//		firstobj = new Node(&obj);
//	}
//	void clear() {
//		Node* elem = firstobj;
//		Node* r;
//		while (elem != nullptr) {
//			r = elem->NextObj;
//			delete elem;
//			elem = r;
//		}
//	}
//	~ContainerNT(){
//		clear();
//	}
//	void push_back(Object obj) {
//		if (firstobj == nullptr) {
//			firstobj = new Node(&obj);
//		}
//		else {
//			Node* elem = firstobj;
//			while ((elem->NextObj) != nullptr) {
//				elem = (elem->NextObj);
//			}
//			(elem->NextObj) = new Node(&obj);
//		}
//		size++;
//	}
//	void pop_front() {
//		Node* newfirst = firstobj->NextObj;
//		delete firstobj;
//		firstobj = newfirst;
//	}
//	void push_forward(Object obj) {
//		if (firstobj == nullptr) {
//			firstobj = new Node(&obj);
//		}
//		else {
//			Node* newFirst = new Node(&obj);
//			newFirst->NextObj = firstobj;
//			firstobj = newFirst;
//		}
//		size++;
//	}
//
//	void push_inside(Object obj, int index) {
//		Node* elem = new Node(&obj);
//		Node* oldThis = firstobj;
//		Node* prev = nullptr;
//		int count = 0;
//		if (index == 0) {
//			firstobj = elem;
//			elem->NextObj = oldThis;
//			size++;
//		}
//		else if (index < size && index >= 0)
//		{
//			while (oldThis != nullptr) {
//				if (count == (index - 1)) {
//					prev = oldThis;
//				}
//				else if (count == index) {
//					prev->NextObj = elem;
//					elem->NextObj = oldThis;
//				}
//				oldThis = oldThis->NextObj;
//				count++;
//			}
//			size++;
//		}
//	}
//	Object& TakeObject(const int index) {//טחûלאוע מבתוךע
//		Node* elem = firstobj;
//		Node* taked = nullptr;
//		int count = 0;
//		Object* take;
//		if (index < size && index >= 0)
//		{
//			while (elem != nullptr) {
//				if (count == index - 1) {
//					Node* taked = elem->NextObj;
//					take = (elem->NextObj)->value;
//					elem->NextObj = (elem->NextObj)->NextObj;
//					delete taked;
//					size--;
//					return *take;
//				}
//				elem = elem->NextObj;
//				count++;
//			}
//		}
//	}
//	Object& operator [](const int index) {
//		Node* elem = firstobj;
//		int count = 0;
//		while (elem != nullptr) {
//			if (count == index) {
//				return *(elem->value);
//			}
//			elem = elem->NextObj;
//			count++;
//		}
//	}
//};