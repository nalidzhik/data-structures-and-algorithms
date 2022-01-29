#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<pair<double,double>> diameterAndTime;
	for (int i = 0; i < N; i++)
	{
		double first, second;
		std::pair <double,double> input;
		cin >> first;
		cin >> second;
		input = std::make_pair(first, second);
		diameterAndTime.push_back(input);
	}

	vector<double> efficiency;
	for (int i = 0; i < N; i++)
	{
		double vol = (diameterAndTime.at(i).first * diameterAndTime.at(i).first ) / diameterAndTime.at(i).second;
		efficiency.push_back(vol);
	}

	vector<int> index(efficiency.size(), 0.0);
	for (int i = 0; i < N ; i++)
	{
		index[i] = i;
	}

	stable_sort(index.begin(), index.end(),
		[&](const int& a, const int& b)
		{
			if (efficiency[a] == efficiency[b])
			{
				if (diameterAndTime[a].first > diameterAndTime[b].first)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			return (efficiency[a] > efficiency[b]);
		}
	);

	for (int i = 0; i < N; i++)
	{
		cout << ++index[i] << " ";
	}

	return 0;
}
