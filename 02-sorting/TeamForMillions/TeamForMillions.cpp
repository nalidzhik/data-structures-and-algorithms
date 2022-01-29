#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Sort(string str)
{
    int arr[62];

    for (int i = 0; i < 62; i++)
    {
        arr[i] = 0;
    }

    for (int i = 0; i < str.length(); i++)
    {
        int index = 0;
        if (str[i] >= '0' && str[i] <= '9')
        {
            index = str[i] - '0';
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            index = str[i] - 'a' + 10;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            index = str[i] - 'A' + 36;
        }

        arr[index]++;
    }

    for (int i = 0; i < 62; i++)
    {
        int occurrences = arr[i];
        char ch = '\0';
        if (i >= 0 && i <= 9)
        {
            ch = char(i + '0');
        }
        else if (i >= 10 && i <= 35)
        {
            ch = char(i - 10 + 'a');
        }
        else if (i >= 36 && i <= 61)
        {
            ch = char(i - 36 + 'A');
        }

        cout << string(occurrences, ch);
    }
}

int main()
{
    int N;
    cin >> N;
    string numbersOfPlayers;
    cin >> numbersOfPlayers;

    Sort(numbersOfPlayers);

    return 0;
}
