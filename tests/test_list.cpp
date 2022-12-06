#include <gtest.h>
#include "../lib_list/list.h"

TEST(test_lib_list, can_create_list) {
	ASSERT_NO_THROW(Clist<int> l1);
}

TEST(test_lib_list, can_do_funk_size_and_funk_push_front) {
	Clist<int> l1;
	l1.push_front(3);
	l1.push_front(4);
	int len = l1.size();
	int res = l1.GetFirstData()->get_data();
	EXPECT_EQ(len, 2);
	EXPECT_EQ(res, 4);
	EXPECT_FALSE(l1.isEmpty());
}

TEST(test_lib_list, can_do_funk_push_back) {
	Clist<int> l1;
	l1.push_back(5);
	l1.push_front(3);
	int res = l1.GetLastData()->get_data();
	EXPECT_EQ(res, 5);
	EXPECT_FALSE(l1.isEmpty());
}

//TEST(test_lib_list, can_do_funk_push_back) {
//	Clist<int> l1;
//
//}