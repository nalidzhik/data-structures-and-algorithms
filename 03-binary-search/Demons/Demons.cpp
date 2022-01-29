#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Demon
{
	int attack;
	int defense;

	Demon() : Demon(0, 0) {}

	Demon(int attack, int defense)
	{
		this->attack = attack;
		this->defense = defense;
	}

	bool operator<(const Demon& other)
	{
		return this->attack < other.attack&& this->defense < other.defense;
	}
};

void merge(vector<Demon>& arr, int l, int mid, int r)
{
	vector<Demon> left;
	vector<Demon> right;

	for (int i = l; i <= mid; i++)
	{
		left.push_back(arr[i]);
	}

	for (int i = mid + 1; i <= r; i++)
	{
		right.push_back(arr[i]);
	}

	int i = 0;
	int j = 0;

	int index = l;
	while (i < left.size() && j < right.size())
	{
		if (left[i].attack < right[j].attack)
		{
			arr[index++] = left[i++];
		}
		else {
			arr[index++] = right[j++];
		}
	}

	while (i < left.size())
	{
		arr[index++] = left[i++];
	}

	while (j < right.size())
	{
		arr[index++] = right[j++];
	}
}

void sortByAttack(vector<Demon>& arr, int l, int r)
{
	if (r - l <= 0) 
	{
		return;
	}

	int mid = l + (r - l) / 2;

	sortByAttack(arr, l, mid);
	sortByAttack(arr, mid + 1, r);

	merge(arr, l, mid, r);
}

int findLongestIncreasingSubsequenceLength(vector<Demon> const& demons) {
	int n = demons.size();

	// O(nlogn)
	vector<Demon> result;
	for (int i = 0; i < n; i++)
	{
		auto itterator = lower_bound(result.begin(), result.end(), demons[i]);
		if (itterator == result.end())
		{
			result.push_back(demons[i]);
		}
		else
		{
			*itterator = demons[i];
		}
	}
	return result.size();
}

int main()
{
	unsigned numOfDemons;
	cin >> numOfDemons;
	vector<Demon> demons;
	for (int i = 0; i < numOfDemons; i++)
	{
		int attack, defense;
		cin >> attack >> defense;

		Demon demon = Demon(attack, defense);
		demons.push_back(demon);
	}

	sortByAttack(demons, 0, demons.size() - 1);

	int attack = findLongestIncreasingSubsequenceLength(demons);

	cout << attack << endl;

	return 0;
}

