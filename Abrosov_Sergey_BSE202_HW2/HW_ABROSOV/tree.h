//
// Created by Сергей Абросов on 26.10.2021.
//
#ifndef HW_ABROSOV_TREE_H
#define HW_ABROSOV_TREE_H

#include "plants.h"

class Tree : public Plants {
private:
    int number_;

public:
    Tree(const char *name, int number);

    static Tree *in(FILE *ifst);

    static Tree *inRnd();

    void out(FILE *ofst) override;
};

#endif //HW_ABROSOV_TREE_H
