// Name: ABHYUDAY SINGH
// Rollno.: 25/DA/004

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int value;
};


double fractionalKnapsack(int capacity, vector<Item>& items)
{
   
    sort(items.begin(), items.end(), [](Item a, Item b)
    {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    });

    double totalValue = 0;

    for (Item item : items)
    {
        if (capacity >= item.weight)
        {
            capacity -= item.weight;
            totalValue += item.value;
        }
        else
        {
            totalValue += (double)item.value / item.weight * capacity;
            capacity = 0;
            break;
        }
    }

    return totalValue;
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter weight and value of each item:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].value;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value = " << maxValue << endl;

    return 0;
}

