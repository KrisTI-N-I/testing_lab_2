#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)


/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);


void mpweb(text txt);

/**

 * Сохраняем содержимое в указанный файл
 */
void save(text txt, std::string filename);


/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);


void showunderscores(text txt);


#endif
