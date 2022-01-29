#include <iostream>
#include <queue> 
#include <set>
#include <climits>
using namespace std;

struct Task
{
	unsigned int deliveredTime;
	unsigned int period;
	unsigned int index;

	Task(unsigned int startTime, unsigned int period, unsigned int index)
	{
		this->deliveredTime = startTime;
		this->period = period;
		this->index = index;
	}
};

struct ByPeriodComparator
{
	bool operator()(const Task& a, const Task& b)
	{
		if (a.period == b.period)
		{
			return a.index > b.index;
		}

		return a.period > b.period;
	}
};

struct ByStartTimeComparator
{
	bool operator()(const Task& a, const Task& b) const
	{
		if (a.deliveredTime == b.deliveredTime)
		{
			return a.period < b.period;
		}

		return a.deliveredTime < b.deliveredTime;
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	unsigned int N;
	cin >> N;

	priority_queue <Task, vector <Task>, ByPeriodComparator> priorityQueue;
	multiset<Task, ByStartTimeComparator> exams;

	unsigned int startTime, period;
	for (unsigned int i = 0; i < N; i++)
	{
		cin >> startTime >> period;
		Task exam = Task(startTime, period, i);
		exams.insert(exam);
	}

	auto itr = exams.begin();
	long int curTime = itr->period + itr->deliveredTime;
	double time = itr->period;
	int previousTime = itr->deliveredTime;
	int previousPeriod = itr->period;
	Task c = *itr;
	exams.erase(itr);

	itr = exams.begin();
	while (!exams.empty())
	{
		while (itr != exams.end() && itr->deliveredTime <= curTime)
		{
			priorityQueue.push(*itr);
			exams.erase(itr);
			itr = exams.begin();
		}

		if (priorityQueue.empty())
		{
			curTime += itr->period;
			time += itr->period;
			previousTime = itr->deliveredTime;
			previousPeriod = itr->period;
			exams.erase(itr);
			itr = exams.begin();
		}
		else
		{
			int toAddToTime = previousTime + previousPeriod;
			toAddToTime -= priorityQueue.top().deliveredTime;
			if (toAddToTime > priorityQueue.top().deliveredTime)
			{
				time += toAddToTime;
			}
			time += priorityQueue.top().period;
			curTime += priorityQueue.top().period;

			if (previousTime == priorityQueue.top().deliveredTime)
			{
				previousPeriod += priorityQueue.top().period;
			}
			c = priorityQueue.top();
			priorityQueue.pop();
		}

	}
	while (!priorityQueue.empty())
	{
		previousPeriod = c.period;
		previousTime = c.deliveredTime;
		int toAddToTime = previousTime + previousPeriod;
		toAddToTime -= priorityQueue.top().deliveredTime;

		time += toAddToTime;

		time += priorityQueue.top().period;
		curTime += priorityQueue.top().period;

		if (previousTime == priorityQueue.top().deliveredTime)
		{
			previousPeriod += priorityQueue.top().period;
		}
		priorityQueue.pop();
	}
	int result = time / N;
	printf("%d ", result);

	return 0;
}
