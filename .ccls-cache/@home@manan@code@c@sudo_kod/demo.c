#include <string.h>
#include <stdio.h>
int main() {
  char x[1000][1000] = {"X=3", "x=3"};

  printf("%s\n", x[0]);
  char* k = strtok(x[0], "=");
  char* v = strtok(NULL, "");
  printf("%s : %s\n", k, v);

}
