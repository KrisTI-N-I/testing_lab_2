TEMPLATE = lib
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt


QMAKE_CFLAGS += -Wall -Wextra -Werror

SOURCES += \
    append_line.cpp \
    create_text.cpp \
    m.cpp \
    mpweb.cpp \
    process_forward.cpp \
    remove_all.cpp \
    rn.cpp

HEADERS += \
    text.h \
    _text.h

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
