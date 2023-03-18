#include<stdio.h>
#include<math.h>
#define E .001

float fx(float x){
    return x*x-3*x+2;
}

float dfx(float x){
    return 2*x-3;
}

void nr(float x0){
    float x1,x2,dfa,fa;
    x1=x0;
    do{
        x1=x2;
        fa=fx(x1);
        dfa=dfx(x1);
        x2=x1-(fa/dfa);


    }while(fabs((x2-x1)/x2)>E);
    printf("%lf",x2);

}


int main(){
    nr(0);
}
