//
// Created by Сергей Абросов on 26.10.2021.
//

#include "flower.h"
#include <cstring>
#include "rnd.h"

Flower::Flower(const char *name, Flower::TYPE type1) : Plants(name), type(type1) {}

Flower *Flower::in(FILE *ifst) {
    char name[256];
    if (fscanf(ifst, "%s", name) == EOF)
        return nullptr;

    char flower_type[10];
    if (fscanf(ifst, "%s", flower_type) == EOF)
        return nullptr;

    Flower::TYPE new_type;
    if (strcmp(flower_type, "DOMESTIC") == 0) {
        new_type = DOMESTIC;
    } else if (strcmp(flower_type, "GARDEN") == 0) {
        new_type = GARDEN;
    } else if (strcmp(flower_type, "WILD") == 0) {
        new_type = WILD;
    } else {
        new_type = WILD;
    }

    return new Flower(name, new_type);
}

Flower *Flower::inRnd() {
    char name[256];
    Random::RandomString(name, 11);

    int type_num = Random::RandomRange(0, 2);
    TYPE new_type = static_cast<TYPE>(type_num);

    return new Flower(name, new_type);
}

void Flower::out(FILE *ofst) {
    const char* new_type;
    if (type == DOMESTIC) {
        new_type = "DOMESTIC";
    } else if (type == GARDEN) {
        new_type = "GARDEN";
    } else if (type == WILD) {
        new_type = "WILD";
    } else {
        new_type = "UNKNOWN_TYPE";
    }

    fprintf(ofst, "It is flower: type = %s.", new_type);
    Plants::out(ofst);
}