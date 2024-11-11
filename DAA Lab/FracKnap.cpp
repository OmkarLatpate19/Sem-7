#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item
{
public:
    double value;
    double weight;
    double ratio;

    // Constructor to initialize item
    Item(double v, double w)
    {
        value = v;
        weight = w;
        ratio = v / w;
    }
};

// Comparator function to sort items based on value-to-weight ratio
bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

double fracKnap(double capacity, vector<Item> &items)
{
    // Sort items by descending value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double total_value = 0.0;

    for (auto &item : items)
    {
        if (capacity == 0)
            break;

        // Take as much weight as possible from the current item
        double take_weight = min(capacity, item.weight);
        total_value += take_weight * item.ratio;
        capacity -= take_weight;
    }

    return total_value;
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;
    for (int i = 0; i < n; i++)
    {
        double value, weight;
        cout << "Enter the value of item " << i + 1 << ": ";
        cin >> value;
        cout << "Enter the weight of item " << i + 1 << ": ";
        cin >> weight;
        items.push_back(Item(value, weight));
    }

    double capacity;
    cout << "Enter the capacity of the Knapsack: ";
    cin >> capacity;

    double max_value = fracKnap(capacity, items);
    cout << "Maximum value in Knapsack = " << max_value << endl;

    return 0;
}
