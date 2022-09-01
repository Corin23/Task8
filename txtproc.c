#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int NBASCII = 128;
const char *INPUT_FILE1 = "text1.txt";
const char *INPUT_FILE2 = "text2.txt";

typedef struct input {
  int txt1_ascarr[128];
  int txt2_ascarr[128];
} input;

input readFilesAndCountOccurencies(const char *filename1, const char *filename2) {
  int c, ch;
  input retStruc = {.txt1_ascarr = {0}, .txt2_ascarr = {0}};

  FILE *file1, *file2;
  file1 = fopen(filename1, "r");
  file2 = fopen(filename2, "r");

  if (file1 == NULL || file2 == NULL) {
    printf("Error, couldn't open file!");
    exit(EXIT_FAILURE);
  }

  while ((c = getc(file1)) != EOF) {
    retStruc.txt1_ascarr[c]++;
  }

  while ((ch = getc(file2)) != EOF) {
    retStruc.txt2_ascarr[ch]++;
  }

  fclose(file1);
  fclose(file2);

  return retStruc;
}

float PossibleRepro(int *input1_arr, int *input2_arr) {
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
  input asciival = readFilesAndCountOccurencies(INPUT_FILE1, INPUT_FILE2);

  float result = PossibleRepro(asciival.txt1_ascarr, asciival.txt2_ascarr);

  printf("%.2f percents", result);
}
