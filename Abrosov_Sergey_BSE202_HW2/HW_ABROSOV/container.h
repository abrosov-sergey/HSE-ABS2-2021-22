//
// Created by Сергей Абросов on 26.10.2021.
//
#ifndef HW_ABROSOV_CONTAINER_H
#define HW_ABROSOV_CONTAINER_H

#include <cstdio>
#include "plants.h"

class Container {
private:
    const int MAX_LEN = 10000;
    int len_ = 0;
    Plants **cont;

public:
    Container();

    ~Container();

    void in(FILE *ifst);

    void inRnd(int size);

    void out(FILE *ofst);

    void sortContainer();
};

#endif //HW_ABROSOV_CONTAINER_H
