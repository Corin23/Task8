#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int NBASCII = 128;
const char *INPUT_FILE1 = "text1.txt";
const char *INPUT_FILE2 = "text2.txt";

typedef struct input {
  int input_file1[128];
  int input_file2[128];
} input;

struct input *readFile(const char *filename1, const char *filename2,
                       int *fsize) {
  int c, ch;
  struct input *retStruc;

  FILE *file1, *file2;
  file1 = fopen(filename1, "r");
  file2 = fopen(filename2, "r");

  if (file1 == NULL || file2 == NULL) {
    printf("Error, couldn't open file!");
    exit(EXIT_FAILURE);
  }

  retStruc = (struct input *)malloc(10 * sizeof(struct input));

  if (retStruc->input_file1 == NULL || retStruc->input_file2 == NULL) {
    printf("Memory allocation failure!");
    exit(EXIT_FAILURE);
  }

  while ((c = getc(file1)) != EOF) {
    retStruc->input_file1[c]++;
    (*fsize)++;
  }

  while ((ch = getc(file2)) != EOF) {
    retStruc->input_file2[ch]++;
    (*fsize)++;
  }

  fclose(file1);
  fclose(file2);

  return retStruc;
}

float wpercent(int *input1_arr, int *input2_arr) {
  int counter = 0, length = 0;
  float result;

  for (int i = 0; i < NBASCII; i++) {
    if ((input1_arr[i] && input2_arr[i]) != 0) {
      counter += input1_arr[i];
    }
  }

  for (int i = 0; i < NBASCII; i++) {
    length += input1_arr[i];
  }

  return result = (float)counter / length * 100;
}

int main() {
  int sizef = 0;
  struct input *asciival = readFile(INPUT_FILE1, INPUT_FILE2, &sizef);

  float result = wpercent(asciival->input_file1, asciival->input_file2);

  printf("%.2f percents", result);
}
