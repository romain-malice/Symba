#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "parser.h"

Tree *parseExpr(char *exprStr) {
  Tree *exprTree = createTree();

  // Main loop
  size_t i = 0;
  int number;
  while (exprStr[i] != '\0') {
    if (exprStr[i] == ' ')
      i++;
    else if ((exprStr[i] >= 'a' && exprStr[i] <= 'A') ||
             (exprStr[i] >= 'z' && exprStr[i] <= 'Z')) {
    } else if (exprStr[i] >= '0' && exprStr[i] <= '9') {
    }
  }
  return NULL;
}
