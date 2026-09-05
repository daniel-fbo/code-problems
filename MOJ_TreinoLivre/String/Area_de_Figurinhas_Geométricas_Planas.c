#include <stdio.h>

int main(void) {
  char buff[20]; char ch[3]; double num[3];
  double sum = 0;
  
  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, " %c %c %c", ch, ch+1, ch+2);
  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, "%lf%lf%lf", num, num+1, num+2);
  for (int i=0; i<3; i++){
    switch (ch[i]){
      case 'A': sum += (num[0]*num[2])/2.0; break;
      case 'B': sum += (num[0]*num[2]); break;
      case 'C': sum += (num[0]*num[0]); break;
      case 'D': sum += ((num[0]+num[1])*num[2])/2.0; break;
    }
  }
  fprintf(stdout, "%.2f\n", sum);
  return 0;
}

