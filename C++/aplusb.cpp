#include<stdio.h>
int main()
{
 float a,b;
 FILE *f;

  f=fopen("aplusb.in","r");
  fscanf(f,"%f%f",&a,&b);
  fclose(f);

  f=fopen("aplusb.out","wb");
  fprintf(f,"%0.0lf",a+b,"\n");
  fclose(f);
  return 0;
}