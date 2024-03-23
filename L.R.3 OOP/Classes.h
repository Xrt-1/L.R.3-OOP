#pragma once
#include <iostream>

class Object {
public:
	virtual std::string Name(){
		return "Object";
	}
	virtual bool isA(std::string who) {
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
	const int GetInt() {
		return intgr;
	}
	std::string Name() override {
		return "integer";
	}
	bool isA(std::string who) override {
		return (who == "integer");
	}
};

class point : public Object {
protected:
	integer x, y;
public:
	point() {
		(this->x).SetInt(0);
		(this->y).SetInt(0);
	}
	point(int x, int y) {
		(this->x).SetInt(x);
		(this->y).SetInt(y);
	}
	void GetCoords(int& x, int& y) {
		x = (this->x).GetInt();
		y = (this->y).GetInt();
	}
	void SetCoords(const int x, const int y) {
		(this->x) = x;
		(this->y) = y;
	}
	std::string Name() override {
		return "point";
	}
	bool isA(std::string who) override {
		return (who == "point");
	}
};

class line: public Object {
protected:
	point p1, p2;
public:
	line() {
		p1.SetCoords(0,0);
		p2.SetCoords(0,0);
	}
	line(point P1, point P2) {
		p1 = P1;
		p2 = P2;
	}
	line(int x, int y, int x2, int y2) {
		p1.SetCoords(x, y);
		p2.SetCoords(x2, y2);
	}
	void GetCoords(int& x, int& y, int& x2, int& y2) {
		p1.GetCoords(x, y);
		p2.GetCoords(x2, y2);
	}
	std::string Name() override {
		return "line";
	}
	bool isA(std::string who) override {
		return (who == "line");
	}
};