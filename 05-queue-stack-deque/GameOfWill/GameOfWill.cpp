#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int N;
    cin >> N;
    deque<unsigned int> players;
    unsigned int player;
    for (int i = 0; i < N; i++)
    {
        cin >> player;
        players.push_back(player);
    }

    unsigned int days = 0;
    bool isFinal = false;
    while (!isFinal)
    {
        deque<unsigned int> nextDayPlayers;
        nextDayPlayers.push_back(players[0]);

        int playersSize = players.size();
        for (int i = 0; i < playersSize - 1; i++)
        {
            if (players[i] >= players[i + 1])
            {
                nextDayPlayers.push_back(players[i + 1]);

            }
        }

        if (nextDayPlayers.size() == playersSize)
        {
            isFinal = true;
        }
        else
        {
            days++;
            players = nextDayPlayers;
        }
    }

    printf("%u\n", days);

    return 0;
}