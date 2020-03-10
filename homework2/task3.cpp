#include <iostream>
#include <iomanip>
using namespace std;
int main(){
int matrix[6][6];

std :: cout<< "Input matrix:"<< std :: endl; //Here we input the elements of the matrix. i is the rows and j is columns. Int the cycle for they are between 0 and 6,because the matrix is 6x6=
for (int i=0;i<6;i++){
    for(int j=0; j<6; j++){
        std::cout<<"matrix["<<i<<"]"<<"["<<j<<"]";
        cin>>matrix[i][j];
    }
       std::cout<< std::endl;

}

std::cout << "Output matrix:" << std::endl; //Output the matrix so the user can see it as a whole and if he want to count his number by himself.
    for(int i=0; i<6; i++) {std::cout<<std::endl;
         for(int j=0; j<6; j++) {


            std::cout << setw(11) << matrix[i][j]; //It is not necessary to be 11, but that way it looks nice :)

        }
    }
std::cout<<std::endl;


            for(int j=0;j<6;j++){

                for(int i=0;i<6;i++){ //this cycle protect the task and matrix from numbers,bigger than 9 and lower than 0
                    if(matrix[i][j]>9 || matrix[i][j]<0){
                         cout<< "The matrix is not simple!"<<endl;
                            return 0;
                         }
                         }
            }
            int M; //this is the number,which the user want to count
            cout<<"Input M:"<< endl;
            cin >>M;
            if(M>=0&& M<=9){ //I made it with some conditions which depend from the Number M.Here is when is 0<=M<=9
            int br=0; //Input counter and make it 0
            for(int j=0;j<6;j++){ //the cycle crawls the matrix and count M
               for(int i=0;i<6;i++){
                if (matrix[i][j]==M){
                    br++;



                }

              }
            }cout<<"The answer is:"<<br<<endl;} // Input the counter
            else if (M>=10 && M<=99) //second option
            {    int br=0; //counter again is 0
                 int a=M/10;//with a and b divides the number M
                 int b=M%10;
                 for(int j=0;j<6;j++){ //crawls the matrix
                    for(int i=0;i<6;i++){
                        if((matrix[i][j]*10+matrix[i+1][j])==M){ //compares if the sum of two adjacent objects from one row makes the M nd if it is true the counter ++
                           br++;
                           }
                        if((matrix[i][j])*10+ matrix[i][j+1]==M){ //makes the same, but for columns
                            br++;
                        }

                    }
                 }
                 for(int j=5;j>=0;j--){ //cycle crawls the matrix,but from the end to the start
                    for (int i=5;i>=0;i--){ //and thats why rows and columns are with the bigger  allowed value and go to the lower
                        if((i+1<6) && (matrix[i][j]==b && matrix[i+1][j]==a)){ //go through the rows
                            br++;
                        }
                        if ((j+1<6) && matrix[i][j]==b && matrix[i][j+1]==a){ // go through the columns
                            br++;
                        }
                    }
                 }
                 cout<<"The answer is:"<<br;
            }
            else if (M>=100 && M<=999) //third option for M
            {    int br=0; //counter again is 0
            int a=M/100;// divides M to 3 different numbers
            int b=M%100/10;
            int c=M%10;
                 for(int j=0;j<6;j++){ //craws the matrix and compare the um of three object
                    for(int i=0;i<6;i++){
                        if((matrix[i][j]*100+matrix[i+1][j]*10+matrix[i+2][j])==M){ //first through rows
                           br++;
                           }
                        if((matrix[i][j]*100+ matrix[i][j+1]*10+matrix[i][j+2])==M){ //and then through columns
                            br++;
                        }

                    }
                 }
                 for(int j=5;j>=0;j--){ //craws the matrix, but from the end to the beginning
                    for(int i=5;i>=0;i--){ //rows and columns are withe the bigger allowed values
                        if((i+2)<6 && matrix[i+2][j]==a && matrix[i+1][j]==b && matrix[i][j]==c){ //if three neighboring objects from one row are equal to the numbs of M
                            br++;
                        }
                        if(((j+2)<6) && matrix[i][j+2]==a && matrix[i][j+1]==b &&matrix[i][j]==c ){ //from one column
                            br++;
                        }
                    }
                 }

                 cout<<"The answer is:"<<br;
            }
           else if(M>=1000 && M<=9999){
                  int br=0;
                  int a=M/1000; //divides M to 4 separate numbers
                  int b=M/100%10;
                  int c=M%100/10;
                  int d=M%10;
                  for(int j=0;j<6;j++){
                    for(int i=0;i<6;i++){
                        if((i+3<6) && (matrix[i][j]*1000+matrix[i+1][j]*100+matrix[i+2][j]*10+matrix[i+3][j]==M)){
                            br++;
                        }
                        if((j+3<6)&& (matrix[i][j]*1000+matrix[i][j+1]*100+matrix[i][j+2]*100+matrix[i][j+3])==M){
                            br++;
                        }
                    }
                  }
                  for(int j=5;j>=0;j--){
                    for(int i=5;i>=0;i--){
                        if((i+3<6)&& matrix[i+3][j]==a && matrix[i+2][j]==b && matrix[i+1][j]==c && matrix[i][j]==d){
                            br++;
                        }
                        if((j+3<6) && matrix[i][j+3]==a && matrix[i][j+2]==b && matrix[i][j+1]==c && matrix[i][j]==d){
                            br++;
                        }
                    }
                  }
                  cout<<"The answer is:"<<br;
           }
           else if(M>=10000&& M<=99999){
            int br=0;
            int a=M/10000; //divides M to 5 different numbers
            int b=M/1000%10;
            int c=M%1000/100;
            int d=M%100/10;
            int e=M%10;
               for(int j=0;j<6;j++){
                for(int i=0;i<6;i++){
                    if((i+4<6)&& matrix[i][j]*10000+matrix[i+1][j]*1000+matrix[i+2][j]*100+matrix[i+3][j]*10+matrix[i+4][j]==M){
                        br++;
                    }
                    if(j+4<6&& matrix[i][j]*10000+matrix[i][j+1]*1000+matrix[i][j+2]*100+matrix[i][j+3]*10+matrix[i][j+4]==M){
                        br++;
                    }
                }
               }
              for (int j=5;j>=0;j--){
                for (int i=5;i>=0;i--){
                    if((i+4<6) && matrix[i][j]==e&& matrix[i+1][j]==d && matrix[i+2][j]==c && matrix[i+3][j]==b && matrix[i+4][j]==a){
                        br++;
                    }
                    if((j+4<6) && matrix[i][j]==e && matrix[i][j+1]==d&& matrix[i][j+2]==c && matrix[i][j+3]==b && matrix[i][j+4]==a){
                        br++;
                    }
                }
              }
            cout<<"The answer is:"<<br;
            }
            else if (M>=100000&& M<=999999){ //the last option. M can not have more than 6 numbers
                int br=0;
                int a=M/100000;
                int b=M/10000%10;
                int c=M%10000/1000;
                int d=M%1000/100;
                int e=M%100/10;
                int f=M%10;
                for (int j=0;j<6;j++){
                    for(int i=0;i<6;i++){
                        if((i+5<6) && (matrix[i][j]*100000+matrix[i+1][j]*10000+matrix[i+2][j]*1000+matrix[i+3][j]*100+matrix[i+4][j]*10+matrix[i+5][j])==M){
                            br++;
                        }
                        if((i+5<6) && (matrix[i][j]*100000+matrix[i][j+1]*10000+matrix[i][j+2]*1000+matrix[i][j+3]*100+matrix[i][j+4]*10+matrix[i][j+5])==M){
                            br++;
                        }
                    }
                }
                for (int j=5;j>=0;j--){
                    for(int i=5;i>=0;i--){
                        if((i+5<6) && matrix[i][j]==f && matrix[i+1][j]==e && matrix[i+2][j]==d && matrix[i+3][j]==c && matrix[i+4][j]==b && matrix[i+5][j]==a){
                            br++;
                        }
                        if((j+5<6) && matrix[i][j]==f && matrix[i][j+1]==e && matrix[i][j+2]==d && matrix[i][j+3]==c && matrix[i][j+4]==b && matrix[i][j+5]==a){
                            br++;
                        }
                    }
                }
                cout<<"The answer is:"<< br;

            }
            else{
                cout<<"The Number is bigger than 999999!";
            }




            return 0;
    }







