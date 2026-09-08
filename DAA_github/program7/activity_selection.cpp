#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity
{
    int start;
    int finish;
};

bool compare(Activity a, Activity b)
{
    return a.finish < b.finish;
}

int main()
{
    vector<Activity> activities = {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };

    // Sort according to finish time
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected Activities:\n";

    // Select the first activity
    int lastFinish = activities[0].finish;

    cout << "(" << activities[0].start << ", "
         << activities[0].finish << ")\n";

    // Select remaining activities
    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[i].start >= lastFinish)
        {
            cout << "(" << activities[i].start << ", "
                 << activities[i].finish << ")\n";

            lastFinish = activities[i].finish;
        }
    }

    return 0;
}