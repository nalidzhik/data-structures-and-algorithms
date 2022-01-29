#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	unsigned int N;
	cin >> N;
	vector<int> fighters;
	int fighter;
	for (int i = 0; i < N; i++)
	{
		cin >> fighter;
		fighters.push_back(fighter);
	}

	deque<int> positives;
	vector<int> result;
	for (int i = 0; i < N; i++)
	{
		if (positives.empty() && fighters[i] < 0)
		{
			result.push_back(fighters[i]);
			continue;
		}

		if (fighters[i] > -1)
		{
			positives.push_back(fighters[i]);
			continue;
		}
		else if (fighters[i] < 0 && !positives.empty())
		{
			if (abs(fighters[i]) > positives.back())
			{
				positives.pop_back();
				i--;
				continue;
			}
			else if (abs(fighters[i]) == positives.back())
			{
				positives.pop_back();
				continue;
			}
			else
			{
				continue;
			}

		}
		else if (fighters[i] < 0 && positives.empty())
		{
			result.push_back(fighters[i]);
		}

	}

	while (!positives.empty())
	{
		result.push_back(positives.front());
		positives.pop_front();
	}

	int size = result.size();
	for (int i = 0; i < size; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}
