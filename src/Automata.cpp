#include "Automata.h"
#include <iostream>

using namespace std;

Automata::Automata()
{
	cash = 0;
	state = OFF;
}

void Automata::on()
{
	if (state == OFF)
	{
		state = WAIT;
		cout << "Waiting for order" << endl;
	}
}

void Automata::off()
{
	if (state == WAIT)
	{
		state = OFF;
		cout << "Power off" << endl;
	}
}

int Automata::coin(int money)
{
	cout << "Enter your money" << endl;
	if (state == WAIT || state == ACCEPT)
	{
		state = ACCEPT;
		cash += money;
		cout << "Your balance: " << cash << " rub" << endl;
	}
	return cash;
}

void Automata::printMenu()
{
	cout << "Menu:" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << Menu[i] << " - " << prices[i] << "rubles" << endl;
	}
}

void Automata::printState()
{
	if (state == OFF)
		cout << "Current state - OFF" << endl;
	if (state == WAIT)
		cout << "Current state - WAIT" << endl;
	if (state == ACCEPT)
		cout << "Current state - ACCEPT" << endl;
	if (state == CHECK)
		cout << "Current state - CHECK" << endl;
	if (state == COOK)
		cout << "Current state - COOK" << endl;
}

void Automata::choice(string product)
{
	if (state = ACCEPT)
	{
		for (int i = 0; i < 7; i++)
		{
			if (product == Menu[i])
			{
				state = CHECK;
				check(i);
			}
		}
	}
}

void Automata::check(int product_num)
{	
	state = CHECK;
	if (cash >= prices[product_num])
	{
		cout << "starting to cook" << endl;
		cook();
	}
	else
	{
		state = WAIT;
		cout << "Not enough money" << endl;
	}
}

void Automata::cancel()
{
	if (state == ACCEPT || state == CHECK)
	{
		state = WAIT;
		cout << "*Returns money*" << endl;
		cash = 0;
	}
}

void Automata::cook()
{
	if (state == CHECK)
	{
		state = COOK;
		cout << "Please wait, your drink is preparing" << endl;
		finish();
	}
}

void Automata::finish()
{
	if (state == COOK)
	{
		state = WAIT;
	}
}