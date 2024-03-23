#pragma once
#include <ctime>
#include "Classes.h"
#include "Container.h"


void randomFill(int count, Container<Object>& cont) {
	srand(time(NULL));
	for (int i = 0; i < count; i++) {
		int r = rand();
		if (r % 2 == 0) {
			int r1 = rand();
			if (r1 % 2 == 0) {
				integer a = integer(i);
				cont.push_back(a);
			}
			else {
				point a = point(i, i+1);
				cont.push_back(a);
			}
		}
		else {
			point p1(i, i+1), p2(i+2, i+3);
			line a = line(p1, p2);
			cont.push_back(a);
		}
	}
}
