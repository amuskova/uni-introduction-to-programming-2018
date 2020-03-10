#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int L; //L is the length
    cout<<"Input L=";
    cin>>L;
    if(L>100){//this is in the task
        cout<<"L is too long!";
        return 0;
    }
int arr[L]; //two arrays with same values
int brr[L];

std :: cout<< "Input arr:"<< std :: endl;
for (int i=0;i<L;i++){

        std::cout<<"arr["<<i<<"]";
        cin>>arr[i];
        brr[i]=arr[i];



} std::cout<< std::endl;

std::cout << "Output array:" << std::endl;
    for(int i=0; i<L; i++) {

 std::cout << setw(11) << arr[i];

                  }
    std::cout<<std::endl;
    int M;
    cout<<"Input M:";
    cin>>M;

    std::cout<<std::endl;
    for (int i=0;i<L;i++){
        if(M>=0){

             if(M>L  ){
               cout<<"M>L!";
                return 0;
            }
             else{
                    if((M+1+i)<L){ //if the condition is not here can go outside the array
                        arr[i]=brr[M+1+i]; // we order arr with the values from brr as they are equal
                    }

                    if(M+1+i>=L){ //There are different condition which depend from the position in the array
                        arr[i]=brr[i-M];
                    }
                    cout<<setw(11)<<arr[i];

             }
        }
           else if(M<0){ //when M<0 change the direction for moving to left
                if(M<-L){
                    cout<<"Error!";
                    return 0;
                }

                if(i-M<L && i-M>=0){ //depend of the position in the array. The algorithm depends
                    arr[i]=brr[i-M]; // use i, M and L ti show and give direction to the numbers after moving where they should go
                }
                else if(i-M>=L){  //there is difference if this sum i bigger or lower than the L(length)
                    arr[i]=brr[(i-M)-L];

            }
          cout<<setw(11)<<arr[i];
            }


    }


    return 0;
}
