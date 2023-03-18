#include<bits/stdc++.h>
using namespace std;


double determinantOfMatrix(double mat[3][3]){
    double ans;
    ans = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2])
          - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
          + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    return ans;
}


void findSolution(double coeff[3][4]) {
    // Matrix d using coeff as given in cramer's rule
    double d[3][3] = {
        { coeff[0][0], coeff[0][1], coeff[0][2] },
        { coeff[1][0], coeff[1][1], coeff[1][2] },
        { coeff[2][0], coeff[2][1], coeff[2][2] },
    };
    // Matrix d1 using coeff as given in cramer's rule
    double d1[3][3] = {
        { coeff[0][3], coeff[0][1], coeff[0][2] },
        { coeff[1][3], coeff[1][1], coeff[1][2] },
        { coeff[2][3], coeff[2][1], coeff[2][2] },
    };
    // Matrix d2 using coeff as given in cramer's rule
    double d2[3][3] = {
        { coeff[0][0], coeff[0][3], coeff[0][2] },
        { coeff[1][0], coeff[1][3], coeff[1][2] },
        { coeff[2][0], coeff[2][3], coeff[2][2] },
    };
    // Matrix d3 using coeff as given in cramer's rule
    double d3[3][3] = {
        { coeff[0][0], coeff[0][1], coeff[0][3] },
        { coeff[1][0], coeff[1][1], coeff[1][3] },
        { coeff[2][0], coeff[2][1], coeff[2][3] },
    };

    // Calculating Determinant of Matrices d, d1, d2, d3
    double D = determinantOfMatrix(d);
    double D1 = determinantOfMatrix(d1);
    double D2 = determinantOfMatrix(d2);
    double D3 = determinantOfMatrix(d3);
    printf("\nSolving using Cramer's rule :");
    printf("\n\nD is : %lf \n", D);
    printf("Dx is : %lf \n", D1);
    printf("Dy is : %lf \n", D2);
    printf("Dz is : %lf \n", D3);


    if (D != 0) {
        // Coeff have a unique solution. Apply Cramer's Rule
        double x = D1 / D;
        double y = D2 / D;
        double z = D3 / D; // calculating z using cramer's rule
        printf("\nValue of a1 (Dx / D) : %lf\n", x);
        printf("Value of a2 (Dy / D) : %lf\n", y);
        printf("Value of a3 (Dz / D) : %lf\n", z);

        cout<<"\n\nThe equation is y = "<<x<<" + "<<y<<" x + "<<z<<" x2 "<<endl;
    }
    else {
        if (D1 == 0 && D2 == 0 && D3 == 0)
            printf("Infinite solutions\n");
        else if (D1 != 0 || D2 != 0 || D3 != 0)
            printf("No solutions\n");
    }
}

int main(){

    cout.precision(4);
    cout.setf(ios::fixed);
    int i,n;
    double value,sum;

    cout<<"Enter how many values you want for(x,y): ";
    cin>>n;

    double x[n],y[n],x2[n],x3[n],x4[n],xy[n],yx2[n];
    double sum_x=0,sum_y=0,sum_x2=0,sum_x3=0,sum_x4=0,sum_xy=0,sum_yx2=0;

    cout<<"\nEnter value for x: ";
    for(i=1;i<=n;i++){
        cin>>x[i];
    }

    cout<<"\nEnter value for y: ";
    for(i=1;i<=n;i++){
        cin>>y[i];
    }

    cout<<"\n        xi\tyi\t  xi2\t    xi3\t      xi4\t    yx\t    yx2"<<endl;
    cout<<"----------------------------------------"<<endl;

    for(i=1;i<=n;i++){
        x2[i]=x[i]*x[i];
        x3[i]=x[i]*x[i]*x[i];
        x4[i]=x[i]*x[i]*x[i]*x[i];
        xy[i]=x[i]*y[i];
        yx2[i]=y[i]*x2[i];

        cout<<"      "<<x[i]<<"    "<<y[i]<<"    "<<x2[i]<<"    "<<x3[i]<<"    "<<x4[i]<<"    "<<xy[i]<<"    "<<yx2[i]<<endl;
    }

    cout<<"----------------------------------------"<<endl;
    for(i=1;i<=n;i++){
        sum_x=sum_x+x[i];
        sum_y=sum_y+y[i];
        sum_x2=sum_x2+x2[i];
        sum_x3=sum_x3+x3[i];
        sum_x4=sum_x4+x4[i];
        sum_xy=sum_xy+xy[i];
        sum_yx2=sum_yx2+yx2[i];
    }

    cout<<"Sum = "<<sum_x<<"   "<<sum_y<<"    "<<sum_x2<<"    "<<sum_x3<<"   "<<sum_x4<<"   "<<sum_xy<<"     "<<sum_yx2<<endl;

    cout<<"\nSubstituting these values ,we get:\n\n";

    cout<<n<<" a1 + "<<sum_x<<" a2 + "<<sum_x2<<" a3 = "<<sum_y<<endl;

    cout<<sum_x<<" a1 + "<<sum_x2<<" a2 + "<<sum_x3<<" a3 = "<<sum_xy<<endl;

    cout<<sum_x2<<" a1 + "<<sum_x3<<" a2 + "<<sum_x4<<" a3 = "<<sum_yx2<<endl;


    double coeff[3][4] = {
        { n, sum_x, sum_x2, sum_y },
        { sum_x, sum_x2, sum_x3, sum_xy },
        { sum_x2, sum_x3, sum_x4, sum_yx2 },
    };

    findSolution(coeff);


    return 0;

}
