#ifndef SQUAR_TEST_H
#define SQUAR_TEST_H

#include <gtest/gtest.h>

extern "C" {
    #include "squar_eq.h"
}

TEST(squar_eq, kol0) {

    eq sol = squar_equat(1, 1, 1);
    ASSERT_EQ(sol.sol_kol, 0);
}

TEST(squar_eq, kol1) {

    eq sol = squar_equat(1, 2, 1);
    ASSERT_EQ(sol.sol_kol, 1);
    EXPECT_NEAR(sol.sol_1, -1.0, 0.000001);
}

TEST(squar_eq, kol2) {

    eq sol = squar_equat(1, -4, 3);
    ASSERT_EQ(sol.sol_kol, 2);
    EXPECT_NEAR(sol.sol_1, 1, 0.000001);
    EXPECT_NEAR(sol.sol_2, 3, 0.000001);
}

TEST(squar_eq, infty) {

    eq sol = squar_equat(0, 0, 0);
    ASSERT_EQ(sol.sol_kol, 0);
}

TEST(squar_eq, no_sol) {

    eq sol = squar_equat(0, 0, 5);
    ASSERT_EQ(sol.sol_kol, 0);
}

TEST(squar_eq, double_sol) {

    eq sol = squar_equat(1, -0.45, 0.05);
    ASSERT_EQ(sol.sol_kol, 2);
    EXPECT_NEAR(sol.sol_1, 0.2, 0.000001);
    EXPECT_NEAR(sol.sol_2, 0.25, 0.000001);
}


#endif // SQUAR_TEST_H
