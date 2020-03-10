#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int Findingbase (double matrixa[][4], double matrixb[][4],  int& n1, int& m1,  double finalanswer[][4], int& num)
{
    double helping[m1][4];
    double arrB[4];
    double zeroes[4] = {0, 0, 0, 0};
    double meetB1 = 0;
    double meetB2 = 0;
    double meetresult = 0;
    int findb = 0;
    int counter = 0;

    for (int rool = 0; rool < m1; rool++)

        for (int column = 0; column < 4; column++)
        {
            helping[0][column] = matrixb[0][column];
            arrB[column] = matrixb[0][column];
        }

        for (int i = 0; i < 4; i++)
        {
            if (findb == 1)
            {
                findb = 0;
                break;
            }

            if (arrB[i] != 0)
            {
                findb++;
                meetB1 = arrB[i];
                int position = i;
                for (int rows = 0; rows <= m1-1; rows++)
                {
                    if (rows == m1-1)
                    {
                        for (int w = 0; w < m1; w++)
                        {
                            if (w != m1-1)
                            {
                                for (int h = 0; h < 4; h++)
                                {
                                    matrixb[w][h] = round(helping[w+1][h]*100000)/100000;
                                }
                            }
                            if (w == m1-1)
                            {
                                for (int col = 0; col < 4; col++)
                                {
                                    matrixb[w][col] = round(helping[w-(m1-1)][col]*100000)/100000;
                                }
                            }

                        }
                    }
                    if (rows != m1-1)
                    {
                        if (matrixb[rows+1][position] == 0)
                        {
                            for (int j = 0; j < 4; j++)
                            {
                                helping[rows+1][j] = matrixb[rows+1][j] + zeroes[j];
                            }
                        }
                        if (matrixb[rows+1][position] != 0)
                        {
                            meetB2 = matrixb[rows+1][position];
                            meetresult = meetB2/meetB1;
                            meetresult *= -1;
                            for (int j = 0; j < 4; j++)
                            {
                                helping[rows+1][j] = arrB[j]*meetresult + matrixb[rows+1][j];
                            }
                        }
                    }
                }
            }
            if (findb == 0 && i == 3)
            {
                counter ++;
                for (int rows = 0; rows <= m1-1; rows++)
                {
                    if (rows == m1-1)
                    {
                        for (int w = 0; w < m1; w++)
                        {
                            if (w != m1-1)
                            {
                                for (int h = 0; h < 4; h++)
                                {
                                    matrixb[w][h] = round(helping[w+1][h]*100000)/100000;
                                }
                            }
                            if (w == m1-1)
                            {
                                for (int col = 0; col < 4; col++)
                                {
                                    matrixb[w][col] = round(helping[w-(m1-1)][col]*100000)/100000;
                                }
                            }

                        }
                    }
                    if (rows != m1 - 1)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            helping[rows+1][j] = matrixb[rows+1][j] + zeroes[j];
                        }
                    }
                }
            }



    }

    double secondarrayb[4];
    double secondmatrixb[m1-counter][4];
    int secondfindb = 0;
    int secondpositionb = 0;
    for (int rool = 0; rool < m1; rool++)
    {
        for (int column = 0; column < 4; column++)
        {
            secondarrayb[column] = matrixb[rool][column];
        }

        for (int i = 0; i < 4; i++)
        {
            if (secondfindb == 1)
            {
                secondfindb = 0;
                secondpositionb++;
                break;
            }
            if (secondarrayb[i] != 0)
            {
                secondfindb++;
                for (int j = 0; j < 4; j++)
                {
                    secondmatrixb[secondpositionb][j] = secondarrayb[j];
                }
            }

        }

        if (secondpositionb == m1-counter)
        {
            break;
        }
    }
    double arrvectorsb[m1-counter][4];

    for (int rool = 0; rool < m1-counter; rool++)
    {
        for (int column = 0; column < 4; column++)
        {
            arrvectorsb[rool][column] = secondmatrixb[rool][column];
        }
    }

    double matrixvectorsb[m1-counter][4];
    double newarr[4];
    double zeroarr[4] = {0, 0, 0, 0};
    double save = 0;
    double parameter = 1;
    double sum = 0;
    if (m1-counter < 4)
    {
        int pos[4] = {0, 0, 0, 0};
        int savepositionb = 0;

        for (int rool = 0; rool < m1-counter; rool++)
        {
            for (int column = 0; column < 4; column++)
            {
                if (arrvectorsb[rool][column] != 0)
                {
                    pos[column] = column+1;
                    break;
                }
            }
        }

        for (int k = 0; k < 4; k++)
        {
            if (pos[k] == 0)
            {
                for (int rool = 0; rool < m1-counter; rool++)
                {
                    for (int column = 0; column < 4; column++)
                    {
                        newarr[column] = arrvectorsb[rool][column];
                    }
                    for (int i = 0; i < 4; i++)
                    {
                        if (newarr[i] != 0)
                        {
                            save = newarr[i];
                            for (int j = i; j < 3; j++)
                            {
                                sum += newarr[j+1];
                            }
                            newarr[i] = sum/save;
                            newarr[i] *= -1;
                            zeroarr[i] = newarr[i];
                            sum = 0;
                            break;
                        }
                    }
                }

                for (int p = 0; p < 4 - k; p++)
                {
                    if (pos[p+k] == zeroarr[p+k])
                    {
                        zeroarr[p+k] = parameter;
                    }
                }
                break;

            }
        }
        for (int q = 0; q < m1-counter; q++)
        {
            for (int z = 0; z < 4; z++)
            {
                matrixvectorsb[q][z] = zeroarr[z]*parameter;
                if (matrixvectorsb[q][z] == -0)
                {
                    matrixvectorsb[q][z] = 0;
                }
            }
            parameter++;
        }

    }
    if (m1-counter>=4)
    {
        for (int rool = 0; rool < m1-counter; rool++)
        {
            for (int column = 0; column < 4; column++)
            {
                matrixvectorsb[rool][column] = arrvectorsb[rool][column];
            }
        }
    }

    double matrix[n1+m1-counter][4];
    for (int rool = 0; rool < n1+m1-counter; rool++)
    {
        if (rool >=n1)
        {
            for (int column = 0; column < 4; column++)
            {
                matrix[rool][column] = matrixvectorsb[rool-n1][column];
            }
        }
        if (rool < n1)
        {
            for (int column = 0; column < 4; column++)
            {
                matrix[rool][column] = matrixa[rool][column];
            }
        }

    }

    double finalhelp[n1+m1-counter][4];
    double finalarr[4];
    int finalcounter = 0;
    int finalfind = 0;
    double one = 0;
    double two = 0;
    double number = 0;
    for (int rool = 0; rool < n1+m1-counter; rool++)
    {
        for (int column = 0; column < 4; column++)
        {
            finalhelp[0][column] = matrix[0][column];
            finalarr[column] = matrix[0][column];
        }
        for (int i = 0; i < 4; i++)
        {
            if (finalarr[i] != 0)
            {
                finalfind++;
                one = finalarr[i];
                int colslast = i;
                for (int rows = 0; rows <= n1+m1-counter-1; rows++)
                {
                    if (rows == n1+m1-counter-1)
                    {
                        for (int f = 0; f < n1+m1-counter; f++)
                        {
                            if (f == n1+m1-counter-1)
                            {
                                for (int col = 0; col < 4; col++)
                                {
                                    matrix[f][col] = round(finalhelp[f-(n1+m1-counter-1)][col]*100000)/100000;
                                }
                            }
                            if (f != n1+m1-counter-1)
                            {
                                for (int v = 0; v < 4; v++)
                                {
                                    matrix[f][v] = round(finalhelp[f+1][v]*100000)/100000;
                                }
                            }
                        }
                    }
                    if (rows!=n1+m1-counter-1)
                    {
                        if (matrix[rows+1][colslast] == 0)
                        {
                            for (int j = 0; j < 4; j++)
                            {
                                finalhelp[rows+1][j] = matrix[rows+1][j] + zeroes[j];
                            }
                        }
                        if(matrix[rows+1][colslast] != 0)
                        {
                            two = matrix[rows+1][colslast];
                            number = two/one;
                            number *= -1;
                            for (int j = 0; j < 4; j++)
                            {
                                finalhelp[rows+1][j] = finalarr[j]*number + matrix[rows+1][j];
                            }
                        }
                    }
                }
            }
            if (finalfind == 0 && i == 3)
            {
                finalcounter++;
                for (int rows = 0; rows <= n1+m1-counter-1; rows++)
                {
                    if (rows == n1+m1-counter-1)
                    {
                        for (int f = 0; f < n1+m1-counter; f++)
                        {
                            if (f == n1+m1-counter-1)
                            {
                                for (int col = 0; col < 4; col++)
                                {
                                    matrix[f][col] = round(finalhelp[f-(n1+m1-counter-1)][col]*100000)/10000;
                                }
                            }
                            if (f!=n1+m1-counter-1)
                            {
                                for (int v = 0; v < 4; v++)
                                {
                                    matrix[f][v] = round(finalhelp[f+1][v]*100000)/100000;
                                }
                            }
                        }
                    }
                    if (rows!=n1+m1-counter-1)
                    {
                        for (int j = 0; j < 4; j++)
                        {
                            finalhelp[rows+1][j] = matrix[rows+1][j] + zeroes[j];
                        }
                    }
                }
            }

            if (finalfind == 1)
            {
                finalfind = 0;
                break;
            }
        }
    }

    double lastarr[4];
    double lastmatrix[n1+m1-counter-finalcounter][4];
    int lastfind = 0;
    int lastplace = 0;
    for (int rool = 0; rool < n1+m1-counter; rool++)
    {
        for (int c = 0; c < 4; c++)
        {
            lastarr[c] = matrix[rool][c];
        }

        for (int i = 0; i < 4; i++)
        {
            if (lastarr[i] != 0)
            {
                lastfind++;
                for (int j = 0; j < 4; j++)
                {
                    lastmatrix[lastplace][j] = lastarr[j];
                }
            }
            if (lastfind== 1)
            {
                lastfind = 0;
                lastplace++;
                break;
            }
        }

        if (lastplace == n1+m1-counter-finalcounter)
        {
            break;
        }
    }

    double help = 0;
    int checking = 0;
    double experiment[4];

    for (int rool = 0; rool < n1+m1-counter-finalcounter; rool++)
    {
        for (int columns = 0; columns < 4; columns++)
        {
            experiment[columns] = lastmatrix[rool][columns];
        }
        for (int i = 0; i < 4; i++)
        {
            if (experiment[i] != 1 && experiment[i] != 0)
            {
                checking++;
                help = 1/(experiment[i]);
                for (int col = 0; col < 4; col++)
                {
                    lastmatrix[rool][col]*= help;
                }
            }
            if (checking == 1)
            {
                checking = 0;
                break;
            }
        }
    }
    num = n1+m1-counter-finalcounter;
    for (int rool = 0; rool < n1+m1-counter-finalcounter; rool++)
    {
        for (int c = 0; c < 4; c++)
        {
            finalanswer[rool][c] = lastmatrix[rool][c];
        }
    }


}


int main()
{
    int n ;
    int m ;
cout<<"Input n= ";
cin>>n;
std::cout<<std::endl;
cout<<"Input m= ";
cin>>m;
    double a[n][4];

for(int i=0;i<n;i++)
{std::cout<<std::endl;
    for(int j=0;j<4;j++)
    {
        cout<<"a["<<i<<"]["<<j<<"]=";
        cin>>a[i][j];
    }
}

    double b[m][4];
for(int i=0;i<m;i++)
{ std::cout<<std::endl;
    for(int j=0;j<4;j++)
    {
        cout<<"b["<<i<<"]["<<j<<"]=";
        cin>>b[i][j];
    }
}
 system("CLS");
    int num = 0;
    double base[n][4];
    cout << "A: " << endl;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            cout << a[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "B: " << endl;
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            cout << b[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
    Findingbase(a, b, n, m, base, num);
    cout<<setw(12) << "The Answer of the task is : " << endl;
    for (int r = 0; r < num; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            cout<<setw(12) << base[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

