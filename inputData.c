#include <stdio.h>
#include <stdlib.h>

#define RAW 100

void inputData(double data[][3]);
void dispData(double data[][3]);

int main(void)
{
  double data[RAW*2][3];

  inputData(data);

  dispData(data);

  return 0;
}

void inputData(double data[][3])
{
  int i;
  double val;
  FILE *fp;

  fp = fopen("ohsakoA.train", "r");
  if (fp==NULL) {
    printf("can't open file.\n");
    exit(1);
  }

  for (i=0; i<RAW; i++) {
    fscanf(fp, "%lf", &val);
    data[i][0] = val;

    fscanf(fp, "%lf", &val);
    data[i][1] = val;

    data[i][2] = 0.0;
  }
  fclose(fp);

  fp = fopen("ohsakoB.train", "r");
  if (fp==NULL) {
    printf("can't open file.\n");
    exit(1);
  }

  for (i=RAW; i<RAW*2; i++) {
    fscanf(fp, "%lf", &val);
    data[i][0] = val;

    fscanf(fp, "%lf", &val);
    data[i][1] = val;

    data[i][2] = 1.0;
  }
  fclose(fp);


}

void dispData(double data[][3])
{
  int i,j;

  for (i=0; i<RAW*2; i++) {
    for (j=0; j<3; j++) {
      printf("%f ", data[i][j]);
    }
    printf("\n");
  }

}
