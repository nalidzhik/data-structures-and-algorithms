#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    unsigned int N;
    cin >> N;

    unordered_multiset<unsigned int> um;
    vector<unsigned int> keys;
    vector<unsigned int> doors;
    unsigned int brokenDoors = 0;

    unsigned int key, door;
    for (int i = 0; i < N; i++)
    {
        cin >> key;
        keys.push_back(key);
    }

    for (int i = 0; i < N; i++)
    {
        cin >> door;
        doors.push_back(door);
    }

    for (int i = 0; i < N; i++)
    {
        um.insert(keys[i]);
        unordered_multiset<unsigned int>::const_iterator got = um.find(doors[i]);
        if (got != um.end())
        {
            um.erase(got);
        }
        else
        {
            brokenDoors++;
        }

    }

    printf("%u ", brokenDoors);

    return 0;
}
