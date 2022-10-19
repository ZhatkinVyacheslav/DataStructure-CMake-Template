// Copyright 2022 Marina Usova

#include <gtest.h>
#include "../lib_example/example.h"

#define EPSILON 0.000001

TEST(test_lib, can_div_test) {
  // Arrange
  int x = 10;
  int y = 2;

  // Act & Assert
  ASSERT_NO_THROW(division(x, y));
}

TEST(test_lib, throw_when_try_div_by_zero_test) {
  // Arrange
  int x = 10;
  int y = 0;

  // Act & Assert
  ASSERT_ANY_THROW(division(x, y));
}

TEST(test_lib, can_div_correctly_test) {
  // Arrange
  int x = 6;
  int y = 2;

  // Act
  int result = division(x, y);

  // Assert
  int expected_result = 3;
  EXPECT_EQ(expected_result, result);
}

TEST(test_lib, can_div_correctly_with_remainder_test) {
  // Arrange
  int x = 5;
  int y = 4;

  // Act
  float result = division(x, y);

  // Assert
  float expected_result = 1.25;
  EXPECT_NEAR(expected_result, result, EPSILON);
}
