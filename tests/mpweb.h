#ifndef MPWEB_H
#define MPWEB_H

#include "tests.h"

TEST(mpweb_test, usual)
{
    std::string output_text = "";
    text txt = create_text();

    for (int i = 0;    i < loop; i++) {
        append_line(txt, "qwerty a");
        if (i == 3) {
            output_text += "qwerty| a\n";
        } else {
            output_text += "qwerty a\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 3, 7);
    mpweb(txt);

    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mpweb_test, usual_2)
{
    std::string output_text = "";
    text txt = create_text();

    for (int i = 0;    i < loop; i++) {
        append_line(txt, "qwerty a" );
        if (i == 3) {
            output_text += "qwerty| a\n";
        } else {
            output_text += "qwerty a\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 3, 8);
    mpweb(txt);

    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mpweb_test, no_previous)
{
    std::string output_text = "";
    text txt = create_text();

    for (int i = 0;    i < loop; i++) {
        append_line(txt, "qwerty a" );
        if (i == 3) {
            output_text += "qwerty| a\n";
        } else {
            output_text += "qwerty a\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 3, 6);
    mpweb(txt);

    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

TEST(mpweb_test, one_space)
{
    std::string output_text = "| \n";
    text txt = create_text();
    append_line(txt, " ");

    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    mpweb(txt);

    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());
}

#endif // MPWEB_H
