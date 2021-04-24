#ifndef RN_TEST_H
#define RN_TEST_H

#include "tests.h"

TEST(rn_test, usual)
{
    std::string output_text = "|";
    text txt = create_text();

    for (int i = 0;   i < loop; i++) {
        append_line(txt, "qwerty ");
        if (i != 1) {
            output_text += "qwerty \n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    rn(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(rn_test, last_string)
{
    std::string output_text = "";
    text txt = create_text();

    for (int i = 0;   i < loop; i++) {
        append_line(txt, "qwerty ");
        if (i != 9) {
            output_text += "qwerty \n";
        } else {
            output_text += "|qwerty \n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 9, 0);
    rn(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(rn_test, before_last_string)
{
    std::string output_text = "";
    text txt = create_text();

    for (int i = 0;   i < loop; i++) {
        append_line(txt, "qwerty ");
        if (i != 8 && i != 9) {
            output_text += "qwerty \n";
        } else if (i != 9) {
            output_text += "|qwerty \n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 8, 0);
    rn(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

#endif // RN_TEST_H
