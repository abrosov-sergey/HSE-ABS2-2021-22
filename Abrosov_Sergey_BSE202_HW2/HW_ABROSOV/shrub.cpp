//
// Created by Сергей Абросов on 26.10.2021.
//
#include "shrub.h"
#include <cstring>
#include "rnd.h"

Shrub::Shrub(const char *name, Shrub::TYPE type1) : Plants(name), type(type1) {}

Shrub *Shrub::in(FILE *ifst) {
    char name[256];
    if (fscanf(ifst, "%s", name) == EOF)
        return nullptr;

    char shrub_type[10];
    if (fscanf(ifst, "%s", shrub_type) == EOF)
        return nullptr;

    Shrub::TYPE new_type;
    if (strcmp(shrub_type, "JANUARY") == 0) {
        new_type = JANUARY;
    } else if (strcmp(shrub_type, "FEBRARY") == 0) {
        new_type = FEBRARY;
    } else if (strcmp(shrub_type, "MARCH") == 0) {
        new_type = MARCH;
    } else if (strcmp(shrub_type, "APRIL") == 0) {
        new_type = APRIL;
    } else if (strcmp(shrub_type, "MAY") == 0) {
        new_type = MAY;
    } else if (strcmp(shrub_type, "JUNE") == 0) {
        new_type = JUNE;
    } else if (strcmp(shrub_type, "JULY") == 0) {
        new_type = JULY;
    } else if (strcmp(shrub_type, "AUGUST") == 0) {
        new_type = AUGUST;
    } else if (strcmp(shrub_type, "SEPTEMBER") == 0) {
        new_type = SEPTEMBER;
    } else if (strcmp(shrub_type, "NOVEMBER") == 0) {
        new_type = NOVEMBER;
    } else if (strcmp(shrub_type, "DECEMBER") == 0) {
        new_type = DECEMBER;
    } else {
        return nullptr;
    }

    return new Shrub(name, new_type);
}

Shrub *Shrub::inRnd() {
    char name[256];
    Random::RandomString(name, 11);

    int type_num = Random::RandomRange(0, 2);
    TYPE new_type = static_cast<TYPE>(type_num);

    return new Shrub(name, new_type);
}

void Shrub::out(FILE *ofst) {
    const char* new_type;

    if (type == JANUARY) {
        new_type = "JANUARY";
    } else if (type == FEBRARY) {
        new_type = "FEBRARY";
    } else if (type == MARCH) {
        new_type = "MARCH";
    } else if (type == APRIL) {
        new_type = "APRIL";
    } else if (type == MAY) {
        new_type = "MAY";
    } else if (type == JUNE) {
        new_type = "JUNE";
    } else if (type == JULY) {
        new_type = "JULY";
    } else if (type == AUGUST) {
        new_type = "AUGUST";
    } else if (type == SEPTEMBER) {
        new_type = "SEPTEMBER";
    } else if (type == NOVEMBER) {
        new_type = "NOVEMBER";
    } else if (type == DECEMBER) {
        new_type = "DECEMBER";
    }

    fprintf(ofst, "It is Shrub: type = %s.", new_type);
    Plants::out(ofst);
}