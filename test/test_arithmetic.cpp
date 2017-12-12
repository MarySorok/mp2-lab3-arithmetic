// тесты для вычисления арифметических выражений

#include <gtest.h>
#include <string>
#include <gtest.h>
#include "arithmetic.h"

class TestStr: public ::testing::TestWithParam<string>
{
protected:
	string S;

public:
	TestStr() : S(GetParam()) {}
	~TestStr() {}
};

TEST_P(TestStr, expect_error)
{
	Arithmetic Arr(S);
	EXPECT_EQ(0, Arr.check());
}

string val_test[] = { "(x-2)+5*)","(((x-2)*3)-1","2-*1.4","6*(3.2-1.25)-","(/3-1)*2","3-1 +2" };

INSTANTIATE_TEST_CASE_P(Instantiation1,
	TestStr,
	::testing::ValuesIn(val_test));

class TestStr2 : public TestStr {};

TEST_P(TestStr2, expect_no_error)
{
	Arithmetic Arr(S);
	EXPECT_EQ(1, Arr.check());
}

string val_test2[] = { "3+2","x+1","3.2+5.17","a[i]*(7-9)","-3/(5-2)","(-3)*10","tmp+2"};

INSTANTIATE_TEST_CASE_P(Instantiation2,
	TestStr2,
	::testing::ValuesIn(val_test2));

struct T
{
	string s;
	bool isCorrect;
	double res;

	T(string mys = "", bool f = true, double v = 0.0)
	{
		s = mys;
		isCorrect = f;
		res = v;
	}
};

class TestStr3 : public ::testing::TestWithParam<T>
{
protected:
	T testcase;
public:
	TestStr3() : testcase(GetParam()){}
	~TestStr3() {}
};

TEST_P(TestStr3, can_check_if_the_expression_correct_or_not)
{
	Arithmetic Res(GetParam().s);
	EXPECT_EQ(GetParam().isCorrect, Res.check());
}
TEST_P(TestStr3, can_calculate)
{
	string str;
	str = unary_minus(GetParam().s);
	Arithmetic Res(str);
	Res.Polish();
	EXPECT_EQ(GetParam().res, Res.calculate());
}

T arr[2] = { T("3+2*(3.5-1)",true,8),T("-2+6*3/9",true,0)};

INSTANTIATE_TEST_CASE_P(Instantiation3,
	TestStr3,
	::testing::ValuesIn(arr));