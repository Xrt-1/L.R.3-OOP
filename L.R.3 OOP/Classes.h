#pragma once
#include <iostream>

class Object {
public:
	virtual void Name(){
		std::cout << "Object\n";
	}
};

class integer : public Object {
protected:
	int intgr;
public:
	integer() {
		intgr = 0;
	}
	integer(int a) {
		intgr = a;
	}
	void SetInt(int a) {
		intgr = a;
	}
	int GetInt() {
		return intgr;
	}
	void Name() override {
		std::cout << "integer\n";
	}
};

class Point : public integer {
protected:
	integer x, y;
public:
	Point() {
		x.SetInt(0);
		y.SetInt(0);
	}
	Point(int x, int y) {
		(this->x).SetInt(x);
		(this->y).SetInt(y);
	}
	
	void GetCoords(int x, int y) {
		x = (this->x).GetInt();
		y = (this->y).GetInt();
	}
	void Name() override {
		std::cout << "Point\n";
	}
};

class line: public Object {
protected:
	Point p1, p2;
public:
	line(Point P1, Point P2) {
		Point p1(P1);
		Point p2(P2);
	}
	void Name() override {
		std::cout << "line\n";
	}
};