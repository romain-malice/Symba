#include "integers.h"

struct IntValue_t {
    int value;
};

void realAdd(IntValue *a, IntValue *b, IntValue *result) {
    result->value = a->value + b->value;
    return;
}

void realSub(IntValue *a, IntValue *b, IntValue *result) {
    result->value = a->value - b->value;
    return;
}

void realMul(IntValue *a, IntValue *b, IntValue *result) {
    result->value = a->value * b->value;
    return;
}

void realDiv(IntValue *a, IntValue *b, IntValue *result) {
    result->value = a->value/b->value;
    return;
}
