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
		for(int i=0;i<10;i++)
			s.push((ValType)((3*i+1)/2));
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
TYPED_TEST(StackTest, can_get_top)
{

}
TYPED_TEST(StackTest, can_get_number_of_elements)
{

}
TYPED_TEST(StackTest, can_clean_stack)
{

}
TYPED_TEST(StackTest, memory_allocation_if_stack_is_full)
{

}