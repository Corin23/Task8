#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MSIZE = 100;
const int ASCH = 128;
const char *f1 = "text1.txt";
const char *f2 = "text2.txt";

typedef struct input{
  int *file1;
  int *file2;
}input;

struct input *readFile(const char *filename1, const char *filename2, int *fsize){
  int c, ch;
  struct input *retStruc;

  FILE *file1, *file2;
  file1 = fopen(filename1, "r");
  file2 = fopen(filename2, "r");

  if (file1 == NULL || file2 == NULL) {
    printf("Error, couldn't open file!");
    exit(EXIT_FAILURE);
  }

  retStruc = (struct input *) malloc(10 * sizeof(struct input));
  retStruc->file1 = malloc(ASCH * sizeof(int));
  retStruc->file2 = malloc(ASCH * sizeof(int));

  if(retStruc->file1 == NULL || retStruc->file2 == NULL){
    printf("Memory allocation failure!");
    exit(EXIT_FAILURE);
  }

  while((c = getc(file1)) != EOF){
    retStruc->file1[c]++;
    (*fsize)++;
    }

  while((ch = getc(file2)) != EOF){
    retStruc->file2[ch]++;
    (*fsize)++;
  }

    fclose(file1);
    fclose(file2);

  return retStruc;
}

float wpercent(int *text1, int *text2) {
  int counter = 0, length = 0;
  int txt2arr[128] = {0};
  float result;

  for (int i = 0; text2[i] != '\0'; i++){
    ++(txt2arr[(int)text2[i]]);
  }

  for(int i = 0; i< ASCH; i++){
    if((text1[i] && text2[i]) != 0)
    {
      counter += text1[i];
    }
  }

  for(int i = 0; i< ASCH; i++){
    length += text1[i];
  }

  return result = (float)counter / length * 100;
}

int main() {
  int sizef = 0;
  struct input *t1 = readFile(f1, f2, &sizef);
  
  float result = wpercent(t1->file1, t1->file2);

  printf("%.2f percents", result);
}
