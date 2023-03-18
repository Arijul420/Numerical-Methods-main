#include<bits/stdc++.h>
using namespace std;
int n;
void printMatrix(double ar[100][100]);
int main()
{
    int stepCount=1;
    double ar[100][100],roots[100];
    printf("Enter number of equations:");
    scanf("%d",&n);
    printf("Enter coefficients of equations:");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            scanf("%lf",&ar[i][j]);
        }
    }
    printf("\nInitial matrix:");
    printMatrix(ar);
    for(int i=0; i<n; i++)
    {
        double x=ar[i][i];
        for(int j=0; j<n+1; j++)
        {
            ar[i][j]=ar[i][j]/x;
            printf("\nStep %d:",stepCount);
            stepCount++;
            printMatrix(ar);
        }

        for(int j=i+1; j<n; j++)
        {
            double x=ar[j][i];
            for(int k=0; k<n+1; k++)
            {
                ar[j][k]=ar[j][k]-x*ar[i][k];
                printf("\nStep %d:",stepCount);
                stepCount++;
                printMatrix(ar);
            }

        }
    }
    double root=ar[n-1][n]/ar[n-1][n-1];
    roots[n-1]=root;
    for(int i=n-2; i>=0; i--)
    {
        double sum=0;
        for(int j=i+1; j<n; j++)
        {
            sum+=ar[i][j]*roots[j];
        }
        roots[i]=(ar[i][n]-sum)/ar[i][i];
    }
    printf("\nSolution of given system:");
    for(int i=0; i<n; i++)
    {
        printf("\nx%d=%.0f",i+1,roots[i]);
    }
}
void printMatrix(double ar[100][100])
{
    printf("\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            if(ar[i][j]>0)
                printf("+%.0f ",ar[i][j]);
            else printf("%.0f ",ar[i][j]);
        }
        printf("\n");
    }
}
