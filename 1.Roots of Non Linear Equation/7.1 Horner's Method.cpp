#include<stdio.h>
int a[100],n;
int Horner(int x,int pn);
int main()
{
    int x;
    printf("Enter degree:");
    scanf("%d",&n);

    for(int i=n; i>=0; i--)
    {
        printf("Enter coefficient a%d:",i);
        scanf("%d",&a[i]);
    }
    printf("Enter x=");
    scanf("%d",&x);
    int val;
    val=Horner(x,a[n]);
    printf("Value=%d",val);
    return 0;
}
int Horner(int x,int pn)
{
    int pj;
    pj=pn;
    for(int i=n; i>=0; i--)
    {
        pj=pj*x+a[i-1];
    }
    return pj;
}
