#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	unsigned int N;
	cin >> N;
	vector<unsigned int> money;
	unsigned int input;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		money.push_back(input);
	}

	priority_queue<unsigned int> maxMoney;
	priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> minMoney;

	for (int i = 0; i < N; i++)
	{
		maxMoney.push(money[i]);

		if (maxMoney.size() - 1 > minMoney.size())
		{
			minMoney.push(maxMoney.top());
			maxMoney.pop();
		}
		else if (!minMoney.empty() && minMoney.top() < maxMoney.top())
		{
			maxMoney.push(minMoney.top());
			minMoney.pop();
			minMoney.push(maxMoney.top());
			maxMoney.pop();
		}

		if (maxMoney.size() > minMoney.size())
		{
			printf("%u.0\n", maxMoney.top());
		}
		else
		{
			money[i] = maxMoney.top() + minMoney.top();
			unsigned int result = money[i] / 2;
			if (money[i] % 2 == 0)
			{
				printf("%u.%u\n", result, 0);
			}
			else
			{
				printf("%u.%u\n", result, 53);
			}
		}
	}

	return 0;
}

