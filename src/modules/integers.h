#ifndef _INTEGERS_H
#define _INTEGERS_H

typedef struct IntValue_t IntValue;

void intAdd(IntValue *a, IntValue *b, IntValue *result);
void intSub(IntValue *a, IntValue *b, IntValue *result);
void intMul(IntValue *a, IntValue *b, IntValue *result);
void intDiv(IntValue *a, IntValue *b, IntValue *result);

#endif
