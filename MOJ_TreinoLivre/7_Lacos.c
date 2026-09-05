#include <stdio.h>

double soma=0, N=0;

double pg3(double N)
{
    int an = 3 + ((N/3)-1) * 3;
    return (3+an) * (N/3) / 2;
}
double pg5(double N)
{
    int an = 5 + ((N/5)-1) * 5;
    return (5+an) * (N/5) / 2;
}
double pg15(double N)
{
    if (N >= 15){
        int an = 15 + ((N/15)-1) * 3;
        return (3+an) * (N/3) / 2;
    } else {
        return 0;
    }
}
double total (int N)
{
    return pg3(N) + pg5(N) - pg15(N);
}

int main(void)
{
    fscanf(stdin, "%lf\n", &N);
    soma = total(N);
    fprintf(stdout, "%d\n", (int) soma);  
    return 0;
}
