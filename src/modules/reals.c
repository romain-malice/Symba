#include "reals.h"

struct RealValue_t {
    float value;
};

void realAdd(RealValue *a, RealValue *b, RealValue *result) {
    result->value = a->value + b->value;
    return;
}

void realSub(RealValue *a, RealValue *b, RealValue *result) {
    result->value = a->value - b->value;
    return;
}

void realMul(RealValue *a, RealValue *b, RealValue *result) {
    result->value = a->value * b->value;
    return;
}

void realDiv(RealValue *a, RealValue *b, RealValue *result) {
    result->value = a->value/b->value;
    return;
}
