#include <iostream>

using namespace std;

unsigned long long int findHighestCube(unsigned long long int number)
{
    unsigned long long int highestCubeRoot = 1;
    unsigned long long int cube = 0;
    for (unsigned long long int i = 1; i < number; i++)
    {
        cube = i * i * i;
        if (cube > number)
        {
            highestCubeRoot = i - 1;
            break;
        }

        if (cube == number)
        {
            highestCubeRoot = i;
            break;
        }
    }

    return highestCubeRoot * highestCubeRoot * highestCubeRoot;
}

int count(unsigned long long int number)
{
    int count = 0;
   
    while (number > 0)
    {
        unsigned long long int highestCube = findHighestCube(number);
        
        count++;
        number -= highestCube;
    }

    return count;
}

int main()
{
    unsigned long long int N;
    cin >> N;
    cout<< count(N);
    return 0;
}
