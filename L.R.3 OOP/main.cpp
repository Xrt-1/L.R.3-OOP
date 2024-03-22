#include "Classes.h"
#include "Container.h"

int main() {
	setlocale(LC_ALL, "rus");
	/* проверка контейнера для типа int

	Container<int> x;
	x.push_back(1);
	x.push_forward(0);
	x.push_forward(-1);
	x.push_back(2);
	x.show_values();
	x.push_inside(3, 0);

	int c = x[2];
	x.show_values();
	std::cout << c;
	int f = x.TakeObject(2);
	x.show_values();*/

	/*integer x;
	integer y(1);
	integer z(2);
	x.Name();
	point p1;
	point p2(p1);
	Container<integer> cont(x);
	cont.push_back(y);
	cont.push_back(z);
	cont.DoSmthExclusive();*/
	
	/*point x;
	point y(1, 2);
	point z(1, 3);
	Container<point> cont(x);
	cont.push_back(y);
	cont.push_back(z);
	cont.DoSmthExclusive();
	*/
	line x(2,2,2,2);
	line y(1, 2,3,4);
	line z(1, 1, 1, 1);
	Container<line> cx(x);
	cx.push_back(y);
	cx.push_back(z);
	cx.DoSmthExclusive();
}