#include <iostream>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

const int MAX_SIZE = 26;
int visited[MAX_SIZE]{ 0 };
stack<int> st;
vector<int> graph[MAX_SIZE];

void topologicalSort(int x)
{
	visited[x] = 1;
	for (int i = 0; i < graph[x].size(); i++)
	{
		int j = graph[x][i];
		if (visited[j] == 0)
		{
			topologicalSort(j);
		}
	}

	st.push(x);
}

void makeGraph( vector<string> words)
{
	int wordsSize = words.size();
	for (int i = 0; i < wordsSize - 1; i++)
	{
		string wordOne = words[i];
		string wordTwo = words[i + 1];
		int wordOneSize = wordOne.size();
		int wordTwoSize = wordTwo.size();
		for (int j = 0; j < wordOneSize && j < wordTwoSize; j++)
		{
			if (wordOne[j] != wordTwo[j])
			{
				graph[wordOne[j] - 'a'].push_back(wordTwo[j] - 'a');
				break;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	string str;
	vector<string> words;
	unordered_set<char> chars;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		words.push_back(str);
		for (int j = 0; j < str.size(); j++)
		{
			chars.insert(str[j]);
		}
	}

	makeGraph( words);

	for (int i = MAX_SIZE - 1; i >= 0; i--)
	{
		if (visited[i] == 0)
		{
			topologicalSort(i);
		}
	}

	while (st.size() != 1)
	{
		char ch = st.top() + 'a';
		if (chars.find(ch) != chars.end())
		{
			printf("%c ", ch);
		}
		st.pop();
	}

	char ch = st.top() + 'a';
	if (chars.find(ch) != chars.end())
	{
		printf("%c", ch);
	}

	return 0;
}