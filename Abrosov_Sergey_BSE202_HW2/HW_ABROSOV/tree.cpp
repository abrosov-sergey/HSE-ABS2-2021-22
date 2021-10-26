//
// Created by Сергей Абросов on 26.10.2021.
//
#include "tree.h"
#include <cstring>
#include "rnd.h"

Tree::Tree(const char *name, int number) : Plants(name), number_(number) {}

Tree *Tree::in(FILE *ifst) {
    char name[256];
    if (fscanf(ifst, "%s", name) == EOF)
        return nullptr;

    int number;
    if (fscanf(ifst, "%d", &number) == EOF)
        return nullptr;

    return new Tree(name, number);
}

Tree *Tree::inRnd() {
    int number = Random::RandomRange(30, 240);
    char name[256];
    Random::RandomString(name, 11);

    return new Tree(name, number);
}

void Tree::out(FILE *ofst) {
    int number;
    number = number_;
    fprintf(ofst, "It is tree: number = %d.", number);
    Plants::out(ofst);
}