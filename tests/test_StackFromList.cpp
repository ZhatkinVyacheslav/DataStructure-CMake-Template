#include <gtest.h>
#include "../lib_StackFromList/StackFromList.h"

TEST(test_lib_StackFromList, can_create_stack) {
	ASSERT_NO_THROW(StackFromList s1(10));
}

TEST(test_lib_StackFromList, can_do_funk_top)
{
	StackFromList s1(5);
	s1.Push(3);
	int res = s1.Top();
	EXPECT_EQ(res, 3);
	EXPECT_FALSE(s1.isEmpty());
}

TEST(test_lib_StackFromList, can_do_funk_pop)
{
	StackFromList s1;
	s1.Push(3);
	int res = s1.Pop();
	EXPECT_EQ(res, 3);
	EXPECT_TRUE(s1.isEmpty());
}

TEST(test_lib_StackFromList, can_get_top) {
	StackFromList s1(5);
	s1.Push(2);
	ASSERT_NO_THROW(s1.Top());
}

TEST(test_lib_StackFromList, cant_get_top_when_stack_is_Empty)
{
	StackFromList s1;
	ASSERT_ANY_THROW(s1.Top());
}

TEST(test_lib_StackFromList, can_get_pop) {
	StackFromList s1(5);
	s1.Push(2);
	ASSERT_NO_THROW(s1.Pop());
}

TEST(test_lib_StackFromList, cant_get_pop_when_stack_is_Empty)
{
	StackFromList s1(5);
	ASSERT_ANY_THROW(s1.Pop());
}

TEST(test_lib_StackFromList, True_is_Empty)
{
	StackFromList s1;
	EXPECT_TRUE(s1.isEmpty());
}

TEST(test_lib_StackFromList, False_is_Empty)
{
	StackFromList s1(1);
	s1.Push(1);
	EXPECT_FALSE(s1.isEmpty());
}

