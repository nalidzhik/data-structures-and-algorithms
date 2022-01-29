#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 

using namespace std;

int main()
{
	unsigned int numOfTopics, numOfTeams;
	cin >> numOfTopics >> numOfTeams;
	vector<int> topics;
	vector<int> teams;
	for (int i = 0; i < numOfTopics; i++)
	{
		int topic;
		cin >> topic;
		topics.push_back(topic);
	}
	for (int i = 0; i < numOfTeams; i++)
	{
		int team;
		cin >> team;
		teams.push_back(team);
	}

	stable_sort(topics.begin(), topics.end());
	vector<int> chosenTopics;

	for (int i = 0; i < teams.size(); i++)
	{
		bool found = binary_search(topics.begin(), topics.end(), teams[i]);
		if (found)
		{
			chosenTopics.push_back(teams[i]);
		}
		else
		{
			auto low = lower_bound(topics.begin(), topics.end(), teams[i]);
			int startIndexLow = low - topics.begin();
			if (startIndexLow < topics.size())
			{
				if (startIndexLow == 0)
				{
					chosenTopics.push_back(topics[startIndexLow]);
					continue;
				}
				if ((teams[i] - topics[startIndexLow - 1] == topics[startIndexLow] - teams[i])
					|| (teams[i] - topics[startIndexLow - 1] < topics[startIndexLow] - teams[i]))
				{
					chosenTopics.push_back(topics[startIndexLow - 1]);
					continue;
				}
				chosenTopics.push_back(topics[startIndexLow]);
			}
			else
			{
				chosenTopics.push_back(topics[topics.size() - 1]);
			}
		}
	}

	for (int i = 0; i < chosenTopics.size(); i++)
	{
		cout << chosenTopics[i] << endl;
	}

	return 0;
}
