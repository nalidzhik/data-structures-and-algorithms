#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class DateTime
{
private:
    int hours;
    int minutes;
    int seconds;

    int days;
    int months;
    int years;

public:
    DateTime() : DateTime(0, 0, 0, 0, 0, 0) {}

    DateTime(int hours, int minutes, int seconds, int days, int months, int years)
    {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
        this->days = days;
        this->months = months;
        this->years = years;
    }

    bool operator<(const DateTime& rhs) const
    {
        if (this->years < rhs.years)
        {
            return true;
        }

        if (this->years == rhs.years)
        {
            if (this->months < rhs.months)
            {
                return true;
            }

            if (this->months == rhs.months)
            {
                if (this->days < rhs.days)
                {
                    return true;
                }

                if (this->days == rhs.days)
                {
                    int lhsSeconds = this->seconds + this->minutes * 60 + this->hours * 3600;
                    int rhsSeconds = rhs.seconds + rhs.minutes * 60 + rhs.hours * 3600;

                    if (lhsSeconds < rhsSeconds)
                    {
                        return true;
                    }

                    return false;
                }

                return false;
            }

            return false;
        }

        return false;
    }
};

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    vector<DateTime> timestamps;
    for (int i = 0; i < N; i++)
    {
        string hoursAsString;
        string minutesAsString;
        string secondsAsString;
        string daysAsString;
        string monthsAsString;
        string yearsAsString;

        std::getline(std::cin, hoursAsString, ':');
        std::getline(std::cin, minutesAsString, ':');
        std::getline(std::cin, secondsAsString, ' ');

        std::getline(std::cin, daysAsString, '.');
        std::getline(std::cin, monthsAsString, '.');
        std::getline(std::cin, yearsAsString);

        DateTime dateTime = DateTime(
            stoi(hoursAsString), stoi(minutesAsString), stoi(secondsAsString),
            stoi(daysAsString), stoi(monthsAsString), stoi(yearsAsString)
        );
        timestamps.push_back(dateTime);
    }

    vector<int> indices(timestamps.size(), 0);
    for (int i = 0; i < N; i++)
    {
        indices[i] = i;
    }

    stable_sort(indices.begin(), indices.end(),
        [&](const int& a, const int& b)
        {
            return timestamps[a] < timestamps[b];
        }
    );

    for (int i = 0; i < N; i++)
    {
        cout << ++indices[i] << endl;
    }

    return 0;
}
