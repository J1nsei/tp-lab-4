#include <string>
using namespace std;

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata
{
private:
	int cash;
	string Menu[7] = { "Classic Coffee", "Green tea", "Tea", "Latte", "Cappuccino", "Hot chocolate", "Hot water" };
	int prices[7] = { 70, 60, 55, 80, 90, 100, 30 };
	STATES state;
public:
	Automata();
	void on();
	void off();
	int coin(int money);
	void printMenu();
	void printState();
	void choice(string product);
	void check(int product_num);
	void cancel();
	void cook();
	void finish();
};