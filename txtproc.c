#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int NBASCII = 128;
const char *INPUT_FILE1 = "text1.txt";
const char *INPUT_FILE2 = "text2.txt";

static int *countChars(const char *filename) {
  int c;
  int *retArr;

  FILE *file;
  file = fopen(filename, "r");

  if (file == NULL) {
    printf("Error, couldn't open file!");
    exit(EXIT_FAILURE);
  }

  retArr = malloc(128 * sizeof(int));
  if (retArr == NULL) {
    printf("Memory allocation error!");
    exit(EXIT_FAILURE);
  }

  while ((c = getc(file)) != EOF) {
    retArr[c]++;
  }

  fclose(file);

  return retArr;
}

static float getPercentage(int *input1_arr, int *input2_arr) {
  int counter = 0, length = 0;
  float result;

  for (int i = 0; i < NBASCII; i++) {
    if ((input1_arr[i] && input2_arr[i]) != 0) {
      counter += input1_arr[i];
    }
    length += input1_arr[i];
  }

  return result = (float)counter / length * 100;
}

int main() {
  int *text1arr = countChars(INPUT_FILE1);
  int *text2arr = countChars(INPUT_FILE2);

  float result = getPercentage(text1arr, text2arr);

  printf("%.2f percents", result);
}
