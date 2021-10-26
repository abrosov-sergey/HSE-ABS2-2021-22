//
// Created by Сергей Абросов on 26.10.2021.
//
#ifndef HW_ABROSOV_SHRUB_H
#define HW_ABROSOV_SHRUB_H

#include "plants.h"

class Shrub : public Plants {
public:
    enum TYPE {
        JANUARY, FEBRARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
    };

    Shrub::TYPE type;

    Shrub(const char *name, TYPE type);

    static Shrub *in(FILE *ifst);

    static Shrub *inRnd();

    void out(FILE *ofst) override;
};

#endif //HW_ABROSOV_SHRUB_H