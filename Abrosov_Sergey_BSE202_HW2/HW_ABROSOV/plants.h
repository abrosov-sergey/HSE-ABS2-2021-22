#ifndef HW_ABROSOV_PLANTS_H
#define HW_ABROSOV_PLANTS_H

#include <cstdio>

class Plants {
private:
    char name_[256];

public:
    Plants(const char *name);

    const char *getName() const;

    static Plants *in(FILE *ifst);

    static Plants *inRnd();

    virtual void out(FILE *ofst);

    double func_result() const;
};

#endif //HW_ABROSOV_PLANTS_H