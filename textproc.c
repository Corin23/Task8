#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MSIZE = 1000;

const char *readFile(const char *filename) {
  int c, length = 0;
  char *buffer = 0;
  
  FILE *file1;
  file1 = fopen(filename, "r");

  if (file1 == NULL) {
    printf("Error, couldn't open file!");
    exit(EXIT_FAILURE);
  }

  if (file1) {
    fseek(file1, 0, SEEK_END);
    length = ftell(file1);

    fseek(file1, 0, SEEK_SET);
    buffer = malloc(length);

    if (buffer) {
      fread(buffer, 1, length, file1);
    }

    fclose(file1);
  }

  return buffer;
}

float wpercent(const char *text1, const char *text2) {
  int counter = 0, length = 0;
  float result;

  size_t size1 = strlen(text1);
  size_t size2 = strlen(text2);

  for (int i = 0; i < size1; i++) {
    if ((isalnum(text1[i]) || ispunct(text1[i])) &&
        strchr(text2, text1[i]) != NULL) {
      counter++;
    }
  }

  for (int i = 0; i < size1; i++) {
    if (isalnum(text1[i]) || ispunct(text1[i]))
      length++;
  }

  return result = (float)counter / length * 100;
}

int main() {

  const char *t1 = readFile("text1.txt");
  const char *t2 = "abcdefghijklmnopqrstuvwxyz";

  float result = wpercent(t1, t2);
  printf("%.2f percents", result);
}
