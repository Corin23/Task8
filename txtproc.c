#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MSIZE = 100;
const int ASCH = 128;

const char *readFile(const char *filename) {
  int c, length = 0;
  long fsize = MSIZE;
  char *buffer;

  FILE *file1;
  file1 = fopen(filename, "r");

  if (file1 == NULL) {
    printf("Error, couldn't open file!");
    exit(EXIT_FAILURE);
  }

  buffer = malloc(fsize * sizeof(char));

  if (buffer == NULL) {
    printf("Memory not allocated!");
    exit(EXIT_FAILURE);
  }

  if (file1) {
    while ((c = getc(file1)) != EOF) {

      if (length > fsize) {
        fsize += MSIZE;
        buffer = (char *)realloc(buffer, fsize * sizeof(char));

        if (buffer == NULL) {
          printf("Couldn't reallocate memory!");
          exit(EXIT_FAILURE);
        }
      }

      buffer[length++] = c;
    }
    fclose(file1);
  }
  return buffer;
  
}

float wpercent(const char *text1, const char *text2) {
  int counter = 0, length = 0;
  int txt1arr[128] = {0}, txt2arr[128] = {0};
  float result;

  for (int i = 0; text1[i] != '\0'; i++) {
    ++(txt1arr[(int)text1[i]]);
  }
  for (int i = 0; text2[i] != '\0'; i++){
    ++(txt2arr[(int)text2[i]]);
  }
  for(int i = 0; i< ASCH; i++){
    if((txt1arr[i] && txt2arr[i]) != 0)
    {
      counter += txt1arr[i];
    }
  }

  for (int i = 0; text1[i] != '\0'; i++) {
    if (isalnum(text1[i]) || ispunct(text1[i]) || isspace(text1[i]))
      length++;
  }

  return result = (float)counter / length * 100;
}

int main() {

  const char *t1 = readFile("text1.txt");
  const char *t2 = "a b";
  float result = wpercent(t1, t2);
  printf("%.2f percents", result);
}
