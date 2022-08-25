#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wpercent(const char *text1, const char *text2) {
  int counter = 0;
  int length = 0;
  float result;

  size_t size1 = strlen(text1);
  size_t size2 = strlen(text2);

  for (int i = 0; i < size1; i++)
    for (int j = 0; j < size2; j++) {
      if (isalnum(text1[i]) && isalnum(text2[j]) && text1[i] == text2[j]) {
        counter++;
      }
    }

  for (int i = 0; i < size1; i++) {
    if (isalnum(text1[i]))
      length++;
  }
  
  return result = (float)counter / length * 100;
}

int main() {

  const char *t1 = "abc   def";
  const char *t2 = "a c";
  float result;

  result = wpercent(t1, t2);
  printf("%f percents", result);
}
