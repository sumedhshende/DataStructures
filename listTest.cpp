#include "include\list.h"
#include <iostream>

int main(void) {
	list<int> _list;

	for(int i = 0; i<20; i++) {
		int num = rand() % 20;
		if(num%2 ==0)
			_list.pushFront(num);
		else
			_list.pushBack(num);
	}
	_list.print();
	_list.createCycle();
	std::cout << "Cycle found - Cycle deleted at : ";
	_list.detectCycle();
	_list.print();
	_list.sortList();
	_list.print();
	return 0;
}

