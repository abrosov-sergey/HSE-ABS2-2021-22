//
// Created by Сергей Абросов on 26.10.2021.
//
#ifndef HW_ABROSOV_RND_H
#define HW_ABROSOV_RND_H

#include <stdlib.h>

class Random {
public:
    static int RandomRange(int min, int max);

    static char *RandomString(char *str, size_t size);
};

#endif //HW_ABROSOV_RND_H