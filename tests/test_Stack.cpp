#include <gtest.h>
#include "../lib_stack/stack.h"

TEST(test_lib_stack, can_create_stack) {
	ASSERT_NO_THROW(Stack<int>s1(10));
}

TEST(test_lib_stack, can_create_stack_with_neg_size) {
	ASSERT_ANY_THROW(Stack<int>s1(-1));
}

TEST(test_lib_stack, can_do_funk_top)
{
	Stack<int>s1(5);
	s1.push(3);
	int res = s1.Top();
	EXPECT_EQ(res, 3);
	EXPECT_FALSE(s1.isEmpty());
}

TEST(test_lib_stack, can_do_funk_pop)
{
	Stack<int>s1(5);
	s1.push(3);
	int res = s1.Pop();
	EXPECT_EQ(res, 3);
	EXPECT_TRUE(s1.isEmpty());
}

TEST(test_lib_stack, can_get_top) {
	Stack<int>s1(5);
	s1.push(2);
	ASSERT_NO_THROW(s1.Top());
}

TEST(test_lib_stack, cant_get_top_when_stack_is_Empty)
{
	Stack<int>s1(5);
	ASSERT_ANY_THROW(s1.Top());
}

TEST(test_lib_stack, can_get_pop) {
	Stack<int>s1(5);
	s1.push(2);
	ASSERT_NO_THROW(s1.Pop());
}

TEST(test_lib_stack, cant_get_pop_when_stack_is_Empty)
{
	Stack<int>s1(5);
	ASSERT_ANY_THROW(s1.Pop());
}