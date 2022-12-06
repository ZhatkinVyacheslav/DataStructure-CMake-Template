#include <gtest.h>
#include "../lib_queue/queue.h"

TEST(test_lib_queue, can_create_queue) {
	ASSERT_NO_THROW(CQueue<int>s1(10));
}

TEST(test_lib_queue, can_create_queue_with_neg_size) {
	ASSERT_ANY_THROW(CQueue<int>s1(-1));
}

TEST(test_lib_queue, can_do_funk_top)
{
	CQueue<int>s1(5);
	s1.push(3);
	int res = s1.Top();
	EXPECT_EQ(res, 3);
	EXPECT_FALSE(s1.isEmpty());
}

TEST(test_lib_queue, can_do_funk_pop)
{
	CQueue<int>s1(5);
	s1.push(3);
	int res = s1.Pop();
	EXPECT_EQ(res, 3);
	EXPECT_TRUE(s1.isEmpty());
}

TEST(test_lib_queue, can_get_top) {
	CQueue<int>s1(5);
	s1.push(2);
	int res = s1.Top();
	EXPECT_EQ(res, 2);
	ASSERT_NO_THROW(s1.Top());
}

TEST(test_lib_queue, cant_get_top_when_stack_is_Empty)
{
	CQueue<int>s1(5);
	ASSERT_ANY_THROW(s1.Top());
}

TEST(test_lib_queue, can_get_pop) {
	CQueue<int>s1(5);
	s1.push(2);
	ASSERT_NO_THROW(s1.Pop());
}

TEST(test_lib_queue, cant_get_pop_when_stack_is_Empty)
{
	CQueue<int>s1(5);
	ASSERT_ANY_THROW(s1.Pop());
}

TEST(test_lib_queue, can_get_end) {
	CQueue<int>s1(5);
	s1.push(2);
	int res = s1.End();
	EXPECT_EQ(res, 2);
	ASSERT_NO_THROW(s1.End());
}

TEST(test_lib_queue, cant_get_end_when_stack_is_Empty)
{
	CQueue<int>s1(5);
	ASSERT_ANY_THROW(s1.End());
}

TEST(test_lib_queue, True_is_Empty)
{
	CQueue<int>s1(5);
	EXPECT_TRUE(s1.isEmpty());
}

TEST(test_lib_queue, False_is_Empty)
{
	CQueue<int>s1(1);
	s1.push(1);
	EXPECT_FALSE(s1.isEmpty());
}

TEST(test_lib_queue, True_is_Full)
{
	CQueue<int>s1(1);
	s1.push(1);
	EXPECT_TRUE(s1.isFull());
}

TEST(test_lib_queue, False_is_Full)
{
	CQueue<int>s1(5);
	EXPECT_FALSE(s1.isFull());
}
