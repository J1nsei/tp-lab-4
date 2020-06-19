#include <iostream>
#include "Automata.h"

using namespace std;

int main()
{
	Automata test;
	test.on();
	test.printMenu();
	test.choice("Hot water");
	test.coin(55);
	test.choice("Tea");
	test.off();
	return 0;
}