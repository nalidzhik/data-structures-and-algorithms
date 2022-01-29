#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	unsigned int n;
	cin >> n;
	unsigned int a;
	vector<unsigned int> masks;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		masks.push_back(a);
	}

	set<unsigned int> subMasks;
	subMasks.insert(0);
	for (int i = 0; i < n; i++)
	{
		unsigned int subMask = masks[i];
		while (subMask > 0)
		{
			subMasks.insert(subMask);
			subMask = (subMask - 1) & masks[i];
		}
	}

	cout << subMasks.size();

	return 0;
}
