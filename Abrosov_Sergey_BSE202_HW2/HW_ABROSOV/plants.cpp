//
// Created by Сергей Абросов on 26.10.2021.
//
#include <cstdio>
#include <cstring>
#include "plants.h"
#include "flower.h"
#include "shrub.h"
#include "tree.h"
#include "rnd.h"

Plants::Plants(const char *name) {
    strcpy(name_, name);
}

const char *Plants::getName() const {
    return name_;
}

Plants *Plants::in(FILE *ifst) {
    int k;
    if (fscanf(ifst, "%d", &k) == EOF)
        return nullptr;

    switch (k) {
        case 1:
            return Flower::in(ifst);
        case 2:
            return Tree::in(ifst);
        case 3:
            return Shrub::in(ifst);
        default:
            return nullptr;
    }
}

Plants *Plants::inRnd() {
    int k = Random::RandomRange(1, 3);
    switch (k) {
        case 1:
            return Flower::inRnd();
        case 2:
            return Tree::inRnd();
        case 3:
            return Shrub::inRnd();
        default:
            return nullptr;
    }
}

void Plants::out(FILE *ofst) {
    fprintf(ofst, " Name = %s. Task result: %f\n", name_, func_result());
}

double Plants::func_result() const {
    double cnt_glas = 1.0;

    if (sizeof(name_) > 256) {
        return sizeof(name_);
    }

    char glas[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    for (int i = 0; i < sizeof(name_); i++)
    {
        bool check = false;

        for (int j = 0; j < 6; i++) {
            if (glas[j] == name_[i]) {
                check = true;
                break;
            }
        }

        if (check) {
            cnt_glas += 1.0;
        }
    }

    return sizeof(name_) / cnt_glas;
}