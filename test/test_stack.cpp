// тесты для стека

#include "stack.h"
#include <gtest.h>
template <class ValType>
class StackTest : public testing::Test {
protected:
	Stack <ValType> s;
public:
	StackTest():s(100)
	{
		ValType a;
		for (int i = 0;i < 10;i++)
		{
			a = (ValType)(3 * i + 1);
			s.push(a);
		}
	}
	 virtual ~StackTest() {}
};
//--------------------------
typedef ::testing::Types<int, double, char> MyTypes;

TYPED_TEST_CASE(StackTest, MyTypes);

TYPED_TEST(StackTest, can_push)
{

}
TYPED_TEST(StackTest, can_pop)
{

}
TYPED_TEST(StackTest, cant_pop_element_if_stack_is_empty)
{
	s.clean();
    ASSERT_ANY_THROW (s.pop());
}
TYPED_TEST(StackTest, can_get_number_of_elements)
{
	EXPECT_EQ(10, s.getquantity());
}
TYPED_TEST(StackTest, can_clean_stack)
{
	s.clean();
	EXPECT_EQ( 0, s.getquantity());
}
TYPED_TEST(StackTest, memory_allocation_if_stack_is_full)
{

}