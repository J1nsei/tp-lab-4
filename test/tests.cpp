#include <gtest\gtest.h>
#include "../include/Automata.h"

TEST(lab4, task_1)
{
	Automata qwe;
	qwe.on();
	int money = qwe.coin(50);
	EXPECT_EQ(50, money);
}
