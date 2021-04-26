#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, std::string contents, int cursor, void *data);


void showunderscores(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}


static void show_line(int index, std::string contents, int cursor, void *data)
{
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    int i=0;
    while (contents[i]!='\0') {

        if (contents[i]==' ') {
            printf("_");
        } else {
            printf("%c", contents[i]);
        }
        i++;
    }

    /* Выводим копию строки на экран */
    printf("\n");
}
