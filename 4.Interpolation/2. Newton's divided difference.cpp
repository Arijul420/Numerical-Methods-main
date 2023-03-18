#include <bits/stdc++.h>
using namespace std;

float proterm(int i, float value, float x[])
{
    float pro = 1;
    for (int j = 0; j < i; j++) {
        pro = pro * (value - x[j]);
    }
    return pro;
}

void dividedDiffTable(float x[], float y[][10], int n)
{
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
        }
    }
}

float applyFormula(float value, float x[],float y[][10], int n)
{
    float sum = y[0][0];

    for (int i = 1; i < n; i++) {
      sum = sum + (proterm(i, value, x) * y[0][i]);
    }
    return sum;
}

void printDiffTable(float y[][10],int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << setprecision(4) <<y[i][j] << "\t ";
        }
        cout << "\n";
    }
}


int main()
{
    int n = 5;
    float value, sum, y[10][10];
    float x[] = { 5, 7, 11, 13, 21 };

    y[0][0] = 150;
    y[1][0] = 392;
    y[2][0] = 1452;
    y[3][0] = 2366;
    y[4][0] = 9702;
    dividedDiffTable(x, y, n);
    printDiffTable(y,n);
    value = 6;
    cout << "\nValue at " << value << " is "<< applyFormula(value, x, y, n) << endl;
    return 0;
}
