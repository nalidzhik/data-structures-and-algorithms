#include <iostream>
#include <iterator>
#include <set>
#include <algorithm>  
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	unsigned int Q;
	cin >> Q;

	vector<unsigned int> requests;
	requests.push_back(0);
	unsigned int request;
	for (int i = 0; i < Q; i++)
	{
		cin >> request;
		requests.push_back(request);
	}

	set<unsigned int> currentNumbers;
	currentNumbers.insert(0);

	unsigned int minXor = UINT_MAX;
	for (int i = 1; i < requests.size(); i++)
	{
		
		currentNumbers.insert(requests[i]);

		set<unsigned int>::iterator itr = currentNumbers.find(requests[i]);

		unsigned int currentXor = 0;
		if (itr == currentNumbers.begin())
		{
			unsigned int c = *next(itr, 1);
			currentXor = requests[i] ^ c;
		}
		else if (itr == prev(currentNumbers.end(), 1))
		{
			unsigned int a = *prev(itr, 1);
			currentXor = a ^ requests[i];
		}
		else
		{
			unsigned int a = *prev(itr, 1);
			unsigned int c = *next(itr, 1);
			unsigned int first = a ^ requests[i];
			unsigned int second = requests[i] ^ c;

			currentXor = min(first, second);
		}

		minXor = min(minXor, currentXor);

		printf("%u\n", minXor);
	}

	return 0;
}
