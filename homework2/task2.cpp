#include <iostream>
#include <cstring>
#include <string.h>


using namespace std;

int main()
{
    char str1[100], str2[100];
    cout<< "Input main string:"<<endl;  //input the main string
    cin.getline(str1,100);
    cout<< "Input the second string:"<<endl;
    cin.getline(str2,100);
    char str3[100];//use 2 more strings
    strcpy(str3,str2);
    char str4[100];
    strcpy(str4,str2);
    int i=0, j, br=0; // input some parameters used in counting
while(str1[i]!='\0') //check and count if the second string is containing in the first
   {



      j=0; //null it to start from the
      if(str1[i]==str2[0])
      {
         while(str2[j]!='\0')
         {
            //Сравняват се съответните символи
         if(str1[i+j]!=str4[j])break; //compare the respective symbols
           j++;
         }

      }
      /*Броячът се увеличава, ако j е равна на
      индекса на символа ‘\0’ във втория низ*/
      if(str2[j]=='\0')br++; //the counter ++ if j is equal to the index of the symbol "\0" in the second string
      i++;
   }
cout<<br<<endl;;
   if(br==0){    //if the second string do not exist in the first the program end
    cout<<"Error!";
    return 0;
   }




    cout << "String Length 1 = " << strlen(str1)<<endl; //find the length of the first string
    cout <<"String Length 2="<<strlen(str2)<<endl; //find the length of the second string
    if(strlen(str2)>strlen(str1)){ //compare the two lengths if the second is bigger than the first the program end
        cout<<"The second string is longer!/Error";
        return 0;
    }
     int a=strlen(str1)/strlen(str2); //use this parameter to fin out how many times the second string can be in the firs because a is always integer
     cout<<"The private from the two lengths is:"<<a<<endl;


for( a<=strlen(str1);a>1;a--){
    strcat(str2,str3); //use concatenation to find out which is the bigger combination in string 1. concatenate as much lower than a. Than we search it in the string 1.If there is not
    //such thin we remove one. I could not explain and use it right

}
cout<<" The agglutination of the second and third array:  "<<str2;

std::cout<<std::endl;
while(str1[i]!='\0')
   {

//check if string 2 is contained in string 1

      j=0;
      if(str1[i]==str2[0])
      {
         while(str2[j]!='\0')
         {
            //Сравняват се съответните символи
         if(str1[i+j]!=str2[j])break;
           j++;
         }

      }

      if(str2[j]=='\0')br++;
      i++;
   }

   cout<<"Counter is:"<<br<<endl;





   while(br=0){ // while the counter/br=0 try different combinations of concatenation to find out which is the bigger,containing in the string 1

           strcat(str3,str4);
           }
           int counter=0;
           while(str1[i]!='\0')
   {



      j=0;
      if(str1[i]==str3[0])
      {
         while(str3[j]!='\0')
         {

         if(str1[i+j]!=str3[j])break;
           j++;
         }

      }

      if(str3[j]=='\0')counter++;
      i++;
   }

   cout<<"counter:"<<counter<<endl;
   char *p = strstr(str1, str4);
//Find the index
    if (p)
        cout << "'" << str4 << "' is present in \"" << str1 << "\" at position " << p-str1;
    else
        cout << str4 << " is not present \"" << str1 << "\"";
std::cout<<std::endl;











    return 0;
}
