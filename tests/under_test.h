#ifndef UNDER_TEST_H
#define UNDER_TEST_H

#include "tests.h"

TEST(under_test, usual)
{
    std::string output_text = "";
    text txt = create_text();

    for (int i = 0; i < loop; i++) {
        append_line(txt, " a a ");
        output_text += "_a_a_\n";
    }

    testing::internal::CaptureStdout();

    showunderscores(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(under_test, no_spaces)
{
    std::string output_text = "";
    text txt = create_text();

    for (int i = 0; i < loop; i++) {
        append_line(txt, "aaa" );
        output_text += "aaa\n";
    }

    testing::internal::CaptureStdout();

    showunderscores(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(under_test, only_spaces)
{
    std::string output_text = "";
    text txt = create_text();

    for (int i = 0;    i < loop; i++) {
        append_line(txt, "   " );
        output_text += "___\n";
    }

    testing::internal::CaptureStdout();

    showunderscores(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(under_test, nothing)
{
    std::string output_text = "";
    text txt = create_text();

    testing::internal::CaptureStdout();

    showunderscores(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

#endif

// UNDER_TEST_H
