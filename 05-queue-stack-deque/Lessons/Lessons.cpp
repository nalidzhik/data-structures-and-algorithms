#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_CHAR = 256;
void printUniqueIndices(string str)
{
	int size = str.length();
	int count[MAX_CHAR];
	int index[MAX_CHAR];

	for (int i = 0; i < MAX_CHAR; i++)
	{
		count[i] = 0;
		index[i] = size;
	}

	for (int i = 0; i < size; i++)
	{
		char curLesson = str[i];
		count[curLesson]++;

		if (count[curLesson] == 1 && curLesson != ' ')
		{
			index[curLesson] = i;
		}
		if (count[curLesson] == 2)
		{
			index[curLesson] = size;
		}
	}

	sort(index, index + MAX_CHAR);
	for (int i = 0; i < MAX_CHAR && index[i] != size; i++)
	{
		cout << index[i] << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string lessons;
	cin >> lessons;

	printUniqueIndices(lessons);

	return 0;
}
