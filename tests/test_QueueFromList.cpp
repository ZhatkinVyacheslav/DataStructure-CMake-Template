#include <gtest.h>
#include "../lib_QueueFromList/QueueFromList.h"

TEST(test_lib_QueueOnList, can_create_queue) {
	ASSERT_NO_THROW(LQueue<int>s1());
}

TEST(test_lib_QueueOnList, can_do_funk_top)
{
	LQueue<int>s1;
	s1.Push(3);
	int res = s1.Top();
	EXPECT_EQ(res, 3);
	EXPECT_FALSE(s1.isEmpty());
}

TEST(test_lib_QueueOnList, can_do_funk_pop)
{
	LQueue<int>s1;
	s1.Push(2);
	s1.Pop();
	EXPECT_TRUE(s1.isEmpty());
}

TEST(test_lib_QueueOnList, can_get_top) {
	LQueue<int>s1;
	s1.Push(2);
	int res = s1.Top();
	EXPECT_EQ(res, 2);
	ASSERT_NO_THROW(s1.Top());
}

TEST(test_lib_QueueOnList, cant_get_top_when_stack_is_Empty)
{
	LQueue<int>s1;
	ASSERT_ANY_THROW(s1.Top());
}

TEST(test_lib_QueueOnList, can_get_pop) {
	LQueue<int>s1;
	s1.Push(5);
	ASSERT_NO_THROW(s1.Pop());
}

TEST(test_lib_QueueOnList, cant_get_pop_when_stack_is_Empty)
{
	LQueue<int>s1;
	ASSERT_ANY_THROW(s1.Pop());
}

TEST(test_lib_QueueOnList, can_get_end) {
	LQueue<int>s1;
	s1.Push(2);
	int res = s1.End();
	EXPECT_EQ(res, 2);
	ASSERT_NO_THROW(s1.End());
}

TEST(test_lib_QueueOnList, cant_get_end_when_stack_is_Empty)
{
	LQueue<int>s1;
	ASSERT_ANY_THROW(s1.End());
}

TEST(test_lib_QueueOnList, True_is_Empty)
{
	LQueue<int>s1;
	EXPECT_TRUE(s1.isEmpty());
}

TEST(test_lib_QueueOnList, False_is_Empty)
{
	LQueue<int>s1;
	s1.Push(1);
	EXPECT_FALSE(s1.isEmpty());
}
