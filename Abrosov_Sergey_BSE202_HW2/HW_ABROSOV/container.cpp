//
// Created by Сергей Абросов on 26.10.2021.
//
#include "container.h"

Container::Container() {
    cont = new Plants *[MAX_LEN];
}

Container::~Container() {
    for (int i = 0; i < len_; i++) {
        delete cont[i];
    }

    delete[] cont;
}

void Container::in(FILE *ifst) {
    Plants *newPlant;
    while ((newPlant = Plants::in(ifst)) != nullptr) {
        cont[len_] = newPlant;
        len_++;
    }
}

void Container::inRnd(int size) {
    while (len_ < size) {
        if ((cont[len_] = Plants::inRnd()) != nullptr) {
            len_++;
        }
    }
}

void Container::out(FILE *ofst) {
    fprintf(ofst, "Container contains %d elements.\n", len_);
    for (int i = 0; i < len_; i++) {
        fprintf(ofst, "%d: ", i);
        cont[i]->out(ofst);
    }
}

void Container::sortContainer() {
    for (int i = 0; i < len_; i++) {
        for (int j = 0; j < len_ - 1; j++) {
            if (cont[j] != nullptr && cont[j] != nullptr) {
                if (cont[j]->func_result() > cont[j + 1]->func_result()) {
                    Plants *temp = cont[j];
                    cont[j] = cont[j + 1];
                    cont[j + 1] = temp;
                }
            }
        }
    }
}