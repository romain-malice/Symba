#ifndef _REAL_H
#define _REAL_H

typedef struct RealValue_t RealValue;

void realAdd(RealValue *a, RealValue *b, RealValue *result);
void realSub(RealValue *a, RealValue *b, RealValue *result);
void realMul(RealValue *a, RealValue *b, RealValue *result);
void realDiv(RealValue *a, RealValue *b, RealValue *result);

#endif
