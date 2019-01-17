#include <stdio.h>
#include <stdlib.h>

int main()
{
 int n,i,j;
 float  x[12],y[12],h,p,X,f[12][12],s,d[12],u=1;
    printf("\n made by -DINESH SURYANAND- \n");
    printf("\n This programe is used to find missing term in table by using 'NEWTON_BACKWORD' interpolation method\n");
    printf( "\n enter no.of elements in the table(no.of entries) :\n");
    scanf("%d",&n);                           //takes the no.of values(entries) in the table
    printf("\n x and y values");
    for (i=0;i<n;i++)                    //creation of table
    {
        printf("\n");
        scanf("%f %f", &x[i] ,&y[i]);
    }
    printf("enter X(value to find) value :");
    scanf("%f",&X);
    h = x[1]-x[0];
    printf("\n intervel difference 'h' = %f\t" ,h );               //value of h
    p=(X-x[n-1])/h;
    printf("\t the value of 'p' is :%f\n", p);                        //value of p
    printf("\n-----------------------------------------------------------------\n");

    for(i=0;i<=n;i++)                 //fill up the first column of matrix
       {
           f[0][i] = y[i];
       }
    for(i=1;i<=n;i++)                 // calculate the forward differences.
    {
        for(j=0;j<=n-i;j++)
            f[i][j] = f[i-1][j+1]-f[i-1][j];
    }

    for(i=1,j=n-2;j>=0;i++,j--) //we can write "i<=n-l"  // print the values of d0y,d1y,d2y...dny
    {
        printf("d%dy=%f\n",i,f[i][j]);
        d[i]=f[i][j];
    }
    printf("\n-----------------------------------------------------------------\n");


    s=f[0][n-1];

                //  *** code for calculating and summing terms ***

    for(i=1;i<n;i++)
    {
        u=u*(p+i-1)/i;
        s=s+(u*d[i]);
    }
    printf("\nResult : f[%f]=%f\n",X,s);



    return 0;
}
