#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <Windows.h>
#include <math.h>
#include <cmath>
using namespace std;

int main()
{
    int A[3][3], C[3][3];
    cout<<"Input the matrix A:"<<endl;
    for(int i=0;i<3;i++)
    {
        std::cout<<std::endl;
        for(int j=0;j<3;j++)
        {
            cout<<"A["<<i<<"]"<<"["<<j<<"]";
            cin>>A[i][j];
        }

    }
    std::cout<<std::endl;

    std::cout<<std::endl;
    cout<<"Input the matrix C:"<<endl;
    for(int d=0;d<3;d++)
    { std::cout<<std::endl;
        for(int e=0;e<3;e++)
        {
            cout<<"C["<<d<<"]"<<"["<<e<<"]";
            cin>>C[d][e];
        }
    }
    Sleep(100);
    system("CLS");
    std::cout << "A=:" << std::endl;
        for(int i=0; i<3; i++) {std::cout<<std::endl;
         for(int j=0; j<3; j++) {


            std::cout << setw(11) << A[i][j];
        }
    }
std::cout<<std::endl;
std::cout<<"C= "<<std::endl;
         for(int i=0;i<3;i++)
         {
             std::cout<<std::endl;
             for(int j=0;j<3;j++)
             {
                 std::cout<<setw(11)<<C[i][j];
             }
         }

if((A[0][0]*A[1][1]*A[2][2]+A[1][0]*A[2][1]*A[0][2]+A[0][1]*A[1][2]*A[2][0]-A[0][2]*A[1][1]*A[2][0]-A[2][1]*A[1][2]*A[0][0]-A[1][0]*A[0][1]*A[2][2])==0)
{
    cout<<"The detA=0!"<<endl;//if detA=0 there is no solution/answer
    return 0;
}

int B[3][3];//B is the transposed matrix of A


for(int j=0;j<3;j++)
{

    for(int i=0;i<3;i++)
    {
        B[0][0]=A[0][0];
        B[0][1]=A[1][0];
        B[0][2]=A[2][0];
        B[1][0]=A[0][1];
        B[1][1]=A[1][1];
        B[1][2]=A[2][1];
        B[2][0]=A[0][2];
        B[2][1]=A[1][2];
        B[2][2]=A[2][2];

    }
}

int G[3][3]; //this is the number -3 multiplied  with the single matrix
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        G[0][0]=-3;G[0][1]=0;G[0][2]=0;
        G[1][0]=0;G[1][1]=-3;G[1][2]=0;
        G[2][0]=0;G[2][1]=0;G[2][2]=-3;

    }
}

int D[3][3];//this is the multiplication of the matrices G and B; use the rule for row and column

for(int i=0;i<3;i++)
{

    for(int j=0;j<3;j++)
    {
        D[0][0]=G[0][0]*B[0][0]+G[0][1]*B[1][0]+G[0][2]*B[2][0];
        D[0][1]=G[0][0]*B[0][1]+G[0][1]*B[1][1]+G[0][2]*B[2][1];
        D[0][2]=G[0][0]*B[0][2]+G[0][1]*B[1][2]+G[0][2]*B[2][2];
        D[1][0]=G[1][0]*B[0][0]+G[1][1]*B[1][0]+G[1][2]*B[2][0];
        D[1][1]=G[1][0]*B[0][1]+G[1][1]*B[1][1]+G[1][2]*B[2][1];
        D[1][2]=G[1][0]*B[0][2]+G[1][1]*B[1][2]+G[1][2]*B[2][2];
        D[2][0]=G[2][0]*B[0][0]+G[2][1]*B[1][0]+G[2][2]*B[2][0];
        D[2][1]=G[2][0]*B[0][1]+G[2][1]*B[1][1]+G[2][2]*B[2][1];
        D[2][2]=G[2][0]*B[0][2]+G[2][1]*B[1][2]+G[2][2]*B[2][2];


    }
}

int E[3][3];//The number 5 multiplied with the single matrix
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        E[0][0]=5;E[0][1]=0; E[0][2]=0;
        E[1][0]=0;E[1][1]=5;E[1][2]=0;
        E[2][0]=0;E[2][1]=0;E[2][2]=5;
    }
}
int F[3][3]; //The sum of matrices A and E

for(int i=0;i<3;i++)
{

    for(int j=0;j<3;j++)
    {
        F[i][j]=A[i][j]+E[i][j];

    }
}


int H[3][3]; //multiplication of D and C;use the rule for a row and a column

for(int i=0;i<3;i++)
{

    for(int j=0;j<3;j++)
    {


        H[0][0]=D[0][0]*C[0][0]+D[0][1]*C[1][0]+D[0][2]*C[2][0];
        H[0][1]=D[0][0]*C[0][1]+D[0][1]*C[1][1]+D[0][2]*C[2][1];
        H[0][2]=D[0][0]*C[0][2]+D[0][1]*C[1][2]+D[0][2]*C[2][2];
        H[1][0]=D[1][0]*C[0][0]+D[1][1]*C[1][0]+D[1][2]*C[2][0];
        H[1][1]=D[1][0]*C[0][1]+D[1][1]*C[1][1]+D[1][2]*C[2][1];
        H[1][2]=D[1][0]*C[0][2]+D[1][1]*C[1][2]+D[1][2]*C[2][2];
        H[2][0]=D[2][0]*C[0][0]+D[2][1]*C[1][0]+D[2][2]*C[2][0];
        H[2][1]=D[2][0]*C[0][1]+D[2][1]*C[1][1]+D[2][2]*C[2][1];
        H[2][2]=D[2][0]*C[0][2]+D[2][1]*C[1][2]+D[2][2]*C[2][2];


    }
}

int L[3][3];//L is the Adjusted matrix of A

for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        L[0][0]=(((F[1][1]*F[2][2])-(F[1][2]*F[2][1])));
        L[0][1]=((-1)*((F[1][0]*F[2][2])-(F[2][0]*F[1][2])));
        L[0][2]=((F[1][0]*F[2][1])-(F[2][0]*F[1][1]));
        L[1][0]=((-1)*((F[0][1]*F[2][2])-(F[2][1]*F[0][2])));
        L[1][1]=((F[0][0]*F[2][2])-(F[2][0]*F[0][2]));
        L[1][2]=((-1)*((F[0][0]*F[2][1])-(F[2][0]*F[0][1])));
        L[2][0]=((F[0][1]*F[1][2])-(F[1][1]*F[0][2]));
        L[2][1]=((-1)*((F[0][0]*F[1][2])-(F[1][0]*F[0][2])));
        L[2][2]=((F[0][0]*F[1][1])-(F[1][0]*F[0][1]));

    }
}
int detA=F[0][0]*F[1][1]*F[2][2]+F[1][0]*F[2][1]*F[0][2]+F[0][1]*F[1][2]*F[2][0]-F[0][2]*F[1][1]*F[2][0]-F[2][1]*F[1][2]*F[0][0]-F[1][0]*F[0][1]*F[2][2];
//determination of A; Use the Sarus' rule
int M[3][3];//A^(-1)

for(int i=0;i<3;i++)
{

    for(int j=0;j<3;j++)
    {

        M[0][0]=(1/detA)*L[0][0];
        M[0][1]=(1/detA)*L[0][1];
        M[0][2]=(1/detA)*L[0][2];
        M[1][0]=(1/detA)*L[1][0];
        M[1][1]=(1/detA)*L[1][1];
        M[1][2]=(1/detA)*L[1][2];
        M[2][0]=(1/detA)*L[2][0];
        M[2][1]=(1/detA)*L[2][1];
        M[2][2]=(1/detA)*L[2][2];

    }
}


std::cout<<std::endl;

int X[3][3];//The matrix which is searching
cout<<"X= "<<endl;
for(int i=0;i<3;i++)
{ std::cout<<std::endl;
    for(int j=0;j<3;j++)
    {
        X[0][0]=(H[0][0]*M[0][0]+H[0][1]*M[1][0]+H[0][2]*M[2][0]);
        X[0][1]=(H[0][0]*M[0][1]+H[0][1]*M[1][1]+H[0][2]*M[2][1]);
        X[0][2]=(H[0][0]*M[0][2]+H[0][1]*M[1][2]+H[0][2]*M[2][2]);
        X[1][0]=(H[1][0]*M[0][0]+H[1][1]*M[1][0]+H[1][2]*M[2][0]);
        X[1][1]=(H[1][0]*M[0][1]+H[1][1]*M[1][1]+H[1][2]*M[2][1]);
        X[1][2]=(H[1][0]*M[0][2]+H[1][1]*M[1][2]+H[1][2]*M[2][2]);
        X[2][0]=(H[2][0]*M[0][0]+H[2][1]*M[1][0]+H[2][2]*M[2][0]);
        X[2][1]=(H[2][0]*M[0][1]+H[2][1]*M[1][1]+H[2][2]*M[2][1]);
        X[2][2]=(H[2][0]*M[0][2]+H[2][1]*M[1][2]+H[2][2]*M[2][2]);
        cout<<setw(4)<<X[i][j]<<setw(4);
    }
}
    return 0;
}
