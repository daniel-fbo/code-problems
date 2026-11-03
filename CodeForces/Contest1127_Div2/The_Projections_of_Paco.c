#include <stdio.h>
#define TAM_MAX 100001

static void reflexao(long long int *x, int an)
{
    if (*x < an)
    {
        *x += (an-(*x))*2; return;
    }
    if (*x > an)
    {
        *x -= ((*x)-an)*2; return;
    }
}
int main(){
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        long long int p = 0, x = 0;
        scanf("%d", &n);
        int inteiros[TAM_MAX];
        for(int i=0; i<n;i++)
        {
            scanf("%d", &inteiros[i]);
        }
        for(int i=n-1; i>=0;i--)
        {
            reflexao(&x,inteiros[i]);
        }
        p = x/2;
        printf("%lld\n", p);

    }
    return 0;
}