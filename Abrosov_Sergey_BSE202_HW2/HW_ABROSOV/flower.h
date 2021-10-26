//
// Created by Сергей Абросов on 26.10.2021.
//
#ifndef HW_ABROSOV_FLOWER_H
#define HW_ABROSOV_FLOWER_H

#include "plants.h"

class Flower : public Plants {
public:
    enum TYPE {
        DOMESTIC, GARDEN, WILD
    };

    Flower::TYPE type;

    Flower(const char *name, TYPE type);

    static Flower *in(FILE *ifst);

    static Flower *inRnd();

    void out(FILE *ofst) override;
};

#endif //HW_ABROSOV_FLOWER_H