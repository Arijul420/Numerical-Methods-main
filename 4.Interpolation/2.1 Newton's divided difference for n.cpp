#include<stdio.h>
#define Max 100

using namespace std;

int main()
{
    double x[Max],fx[Max],sum = 0.0 , xp,lf;
    double a[Max],div[Max][Max];
    int n;
    printf("Enter the number of set : ");
    scanf("%d",&n);
    printf("Enter Data point and the function value of that point : \n\n");
    for(int i = 1 ; i <= n ;i++)
    {
        printf("x[%d] = ",i);
        scanf("%lf",&x[i]);
    }
    for(int i = 1 ; i <= n ;i++)
    {
        printf("fx[%d] = ",i);
        scanf("%lf",&fx[i]);
    }

    printf("Enter the value at which interpolation is required : ");
    scanf("%lf",&xp);
    for(int i = 1 ; i <= n ;i++)
        div[i][1] = fx[i];
    ///make divided table
    for(int j = 2 ; j <= n ; j++)
    {
        for(int i = 1 ; i <= n-j+1 ; i++)
        {
            div[i][j] = (div[i+1][j-1]-div[i][j-1])/(x[i+j-1]-x[i]);
        }
    }
    for(int i = 1 ; i <= n ; i++)
        a[i] = div[1][i];
        sum = a[1];
    for(int i = 2 ; i <= n ; i++)
    {
        lf = 1.0;
        for(int j = 1 ; j <= i-1 ; j++)
        {
            lf *= (xp - x[j]);
        }
        sum += lf*a[i];
    }
    printf("\n\nNEWTON INTERPOLATION \n\n");
    printf("Interpolated value \n");
    printf("at x = %lf is %lf \n",xp,sum);
    return 0;
}

/*
5
5 150
7 392
11 1452
13 2366
21 9702
6
*/
