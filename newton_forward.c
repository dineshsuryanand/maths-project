#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int n,i,j;
    float  x[12],y[12],h,p,X,f[12][12],s=0,u=1;
    printf("\n made by -DINESH SURYANAND- \n");
    printf("\n This programe is used to find missing term in table by using 'NEWTON_FORWARD' interpolation method\n");
    printf( "\n enter no.of elements in the table(no.of entries) :\n");
    scanf("%d",&n);               //takes the no.of values(entries) in the table
    printf("\n enter x and y values");
    for (i=0;i<n;i++)         //creation of table
    {
       printf("\n");
       scanf("%f %f", &x[i] ,&y[i]);

    }
    printf("enter X(value to find) value :");
    scanf("%f",&X);

    h = x[1]-x[0];
    printf("\nintervel length 'h' = %f\t" ,h );//value of h
    p=(X-x[0])/h;
    printf("\t the value of 'p' is :%f\n", p);//value of p
   printf("\n-----------------------------------------------------------------\n");

     //fill up the first column of matrix
    for(i=0;i<=n;i++)
        f[0][i] = y[i];

    //Now calculate the forward differences.
    for(i=1;i<=n;i++)
    {
        {for(j=0;j<=n-i;j++)
            f[i][j] = f[i-1][j+1]-f[i-1][j];
        }
    }
   for(i=0;i<n;i++) // print the values of d0y,d1y,d2y...dny
    {
       printf("\n");
       printf("d%dy= %f",i,f[i][0]);
    }
   printf("\n-----------------------------------------------------------------\n");

    s= f[0][0]; // s=y0

    //***code for calculating and summing all the remaining terms.***
    for(i=1;i<n;i++)
    {
        u = u * (p-i+1) / i;
        s = s + (u * f[i][0]);

    }

    //print out the result.
    printf("\n Result : y[%f] = %f \n",X,s);

    return 0;

     }



