#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int N, K;
    cin >> N >> K;
    long animalTrios = 0;

    unordered_map<long, long> inputSecondMap;
    unordered_map<long, long> inputThirdMap;

    long kilograms;
    for (int i = 0; i < N; i++)
    {
        cin >> kilograms;

        if (inputThirdMap.count(kilograms) != 0)
        {
            animalTrios += inputThirdMap[kilograms];
        }

        if (inputSecondMap.count(kilograms) != 0)
        {
            inputThirdMap[kilograms * K] += inputSecondMap[kilograms];
        }

        inputSecondMap[kilograms * K]++;
    }

    printf("%ld", animalTrios);

    return 0;
}
