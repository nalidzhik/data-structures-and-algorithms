#include <iostream>
#include <queue> 
#include <algorithm>
#include <set>

using namespace std;

struct Task
{
    unsigned int startTime;
    unsigned int period;
    unsigned int index;

    Task(unsigned int startTime, unsigned int period, unsigned int index)
    {
        this->startTime = startTime;
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
        if (a.startTime == b.startTime)
        {
            return a.period < b.period;
        }

        return a.startTime < b.startTime;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int N;
    cin >> N;

    priority_queue <Task, vector <Task>, ByPeriodComparator> priorityQueue;
    multiset<Task, ByStartTimeComparator> tasks;

    unsigned int startTime, period;
    for (unsigned int i = 0; i < N; i++)
    {
        cin >> startTime >> period;
        Task task = Task(startTime, period, i);
        tasks.insert(task);
    }

    auto itr = tasks.begin();
    printf("%u ", itr->index);
    long  long int curTime = itr->startTime;
    curTime += itr->period;
    tasks.erase(itr);
    itr = tasks.begin();

    while (!tasks.empty())
    {

        while (itr != tasks.end() && itr->startTime <= curTime)
        {
            priorityQueue.push(*itr);
            tasks.erase(itr);
            itr = tasks.begin();
        }

        if (priorityQueue.empty())
        {
            printf("%u ", itr->index);
            curTime = itr->startTime + itr->period;
            tasks.erase(itr);
            itr = tasks.begin();
        }

        else
        {
            printf("%u ", priorityQueue.top().index);
            curTime += priorityQueue.top().period;
            priorityQueue.pop();
        }

    }

    while (!priorityQueue.empty())
    {
        printf("%u ", priorityQueue.top().index);
        priorityQueue.pop();
    }

    return 0;
}
