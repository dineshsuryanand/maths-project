#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,i,j=1 ;
    float x[10], y[10],X,y0,p[10],u=1,sum =0;
    printf("\nEnter the number of observations:\n");
    scanf("%d", &n);

    printf("\nEnter the different values of x and y:\n");
    for (i=1;i<=n;i++)
        {
            printf("\n");
            scanf("%f %f", &x[i],&y[i]);
        }

    y0=y[1];
    printf("\nEnter the value of 'X' in f(x) you want to evaluate:\n");
    scanf("%f", &X);

    do
    {
        for (i=1;i<=n-1;i++)
        {
            p[i] = ((y[i+1]-y[i])/(x[i+j]-x[i]));
            y[i]=p[i];
        }
        for(i=1;i<=j;i++)
            {
                u*=(X-x[i]);                                 // u= u*(X-x[i]
            }
        sum+=(y[1]*u);                                 // sum = sum +(y[1]*u)
        j++;
        n--;
    }

    while(n!=1);
    y0+=sum;                                                      // y0 = y0+sum
    printf("\nf(%f) = %f\n", X , y0);
    return 0;
}
