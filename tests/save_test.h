#ifndef SAVE_TEST_H
#define SAVE_TEST_H

#include "tests.h"

QString file_1 = "test_b";
QString file_2 = "test_a";

TEST(save_test, usual)
{
    text txt = create_text();
    for (int i = 0;    i < loop; i++) {
        append_line(txt, "string ");
        append_line(txt, "");
    }

    save(txt, file_1.toStdString());

    QFile file(file_1);
    bool result = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(result, true);

    QString line_file;
    std::list<std::string>::iterator line_text = txt->myList->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    QDir dir(".");
    dir.remove(file_1);
}

TEST(save_test, empty_strings)
{
    text txt = create_text();
    for (int i = 0;    i < loop; i++) {
        append_line(txt, "");
    }

    save(txt, file_1.toStdString());

    QFile file(file_1);
    bool result = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(result, true);

    QString line_file;
    std::list<std::string>::iterator line_text = txt->myList->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    QDir dir(".");
    dir.remove(file_1);
}

TEST(save_test, no_empty_strings)
{
    text txt = create_text();
    for (int i = 0;    i < loop; i++) {
        append_line(txt, "string " );
    }

    save(txt, file_1.toStdString());

    QFile file(file_1);
    bool result = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(result, true);

    QString line_file;
    std::list<std::string>::iterator line_text = txt->myList->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();
        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str());
        line_text++;
    }

    QDir dir(".");
    dir.remove(file_1);
}

TEST(save_test, one_string)
{
    text txt = create_text();
    append_line(txt, "");

    save(txt, file_1.toStdString());

    QFile file(file_1);
    bool result = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(result, true);

    QString line_file;
    std::list<std::string>::iterator line_text = txt->myList->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    QDir dir(".");
    dir.remove(file_1);
}

TEST(save_test, nothing)
{
    text txt = create_text();
    save(txt, file_1.toStdString());

    QFile file(file_1);
    bool result = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(result, true);

    QString line_file;
    std::list<std::string>::iterator line_text = txt->myList->begin();

    while (!file.atEnd()) {
        line_file = file.readLine();

        ASSERT_STREQ(line_file.toStdString().c_str(), (*line_text + "\n").c_str() );
        line_text++;
    }

    QDir dir(".");
    dir.remove(file_1);
}

#endif // SAVE_TEST_H
