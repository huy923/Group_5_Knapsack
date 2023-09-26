#include <iostream>
#include <vector>

using namespace std;

struct Item
{
    int value; // Value of the item
    int cost;  // Cost of the item
};

double fS = 0;    // Objective function value of S
double costS = 0; // Cost of items in S

vector<int> MarginalRatioThresholding(double alpha, int K, vector<Item> &items)
{
    vector<int> S; // Selected items

    for (Item &item : items)
    {
        double marginalRatio = double(item.value / item.cost);

        if (costS + item.cost <= K and marginalRatio >= alpha)
        {
            S.push_back(item.value);
            costS += item.cost;
            fS += item.value;
        }
    }
    return S;
}

int main()
{
    vector<Item> items = {{3, 2}, {4, 3}, {5, 4}, {7, 5}};
    double alpha = 0.5;
    int K = 10;

    // int n;
    // cout << "Enter number n : ";
    // cin >> n;
    // vector<Item> items;
    // while (n--)
    // {
    //     Item item;
    //     cout << "Enter value: ";
    //     cin >> item.value;
    //     cout << "Enter cost: ";
    //     cin >> item.cost;
    //     items.push_back(item);
    // }

    vector<int> selectedItems = MarginalRatioThresholding(alpha, K, items);

    cout << "Selected items: ";
    for (int item : selectedItems)
    {
        cout << item << " ";
    }
    cout << endl;
    cout << "Function value of S : " << fS << endl;
    cout << "Function cost of S : " << costS << endl;
    return 0;
}