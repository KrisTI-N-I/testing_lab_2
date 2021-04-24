#ifndef M_TEST_H
#define M_TEST_H

#include "tests.h"

TEST(m_test, begin)
{
    std::string output_text = "|";

    text txt = create_text();
    for (int i = 0;    i < loop; i++) {
        append_line(txt, "m_test ");
        output_text += "m_test \n";
    }

    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m_test, center)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0;    i < loop; i++) {
        append_line(txt, "m_test ");

        if (i == 4) {
            output_text += "m_t|est \n";
        } else {
            output_text += "m_test \n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 4, 3);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m_test, out_of_str)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0;    i < loop; i++) {
        append_line(txt, "m_test ");

        if (i == 5) {
            output_text += "m_test |\n";
        } else {
            output_text += "m_test \n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 5, 50);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m_test, minus_str)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0;    i < loop; i++) {
        append_line(txt, "m_test ");
        output_text += "m_test \n";
    }

    testing::internal::CaptureStdout();

    m(txt, -6, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m_test, more_str)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0;    i < loop; i++) {
        append_line(txt, "m_test "  );
        output_text += "m_test \n";
    }

    testing::internal::CaptureStdout();

    m(txt, 100, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m_test, minus_pos)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0;    i < loop; i++) {
        append_line(txt, "m_test "  );
        output_text += "m_test \n";
    }

    testing::internal::CaptureStdout();

    m(txt, 6, -1);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m_test, empty_str)
{
    std::string output_text = "";

    text txt = create_text();
    for (int i = 0;    i < loop; i++) {
        append_line(txt, "");

        if (i == 6) {
            output_text += "|\n";
        } else {
            output_text += "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 6, 100);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m_test, one_str)
{
    std::string output_text = "|\n";
    text txt = create_text();
    append_line(txt, "");

    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

TEST(m_test, nothing)
{
    std::string output_text = "";
    text txt = create_text();

    testing::internal::CaptureStdout();

    m(txt, 6, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);
}

#endif // M_TEST_H
