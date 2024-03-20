#pragma once
#include <iostream>

class Object {
public:
	virtual std::string Name(){
		return "Object";
	}
	virtual bool isA(std::string& who) {
		return (who == "Object");
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
	std::string Name() override {
		return "integer";
	}
	bool isA(std::string& who) override {
		return (who == "Integer" || Object::isA(who));
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
	std::string Name() override {
		return "Point";
	}
	bool isA(std::string& who) override {
		return (who == "Point" || Object::isA(who));
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
	std::string Name() override {
		return "line";
	}
	bool isA(std::string& who) override {
		return (who == "Line" || Object::isA(who));
	}
};