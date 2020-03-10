#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char sentence[200];
    cout << "Type your sentence: ";
    cin.getline(sentence, 201);
    for (int i = 0; i < strlen(sentence); i++)
    {
        if ((int)sentence[i] < 0 || (int)sentence[i] > 127)
        {
            cout << "Wrong input!" << endl;
            return 0;
        }
    }
    int answer = 0;
    int counter = 0;
    for (int i = 0; i < strlen(sentence)+1; i++)
    {
        if ((int)sentence[i] != 32 && sentence[i] != '\t' && (int)sentence[i] != 8 && sentence[i] != '\0')
        {
            if (counter == 0)
            {
                counter++;
            }
        }
        else
        {
            if (i == strlen(sentence)-1 && counter == 0)
            {
                answer = 0;
                break;
            }
            if (counter > 0)
            {
                answer++;
            }
            counter = 0;
        }
    }
    cout<<"The number of words is: "<<answer<<endl;
    return 0;
}
