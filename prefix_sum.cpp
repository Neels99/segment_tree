#include <iostream>
#include <vector>
using namespace std;

// class a{
//     p
// };

class PrefSum
{
    vector<int> sum;

public:
    PrefSum(vector<int> a)
    {
        for (auto item : a)
        {
            if (sum.empty())
                sum.push_back(item);
            else
                sum.push_back(sum.back() + item);
        }
    }

public:
    void PRINT()
    {
        for (auto item : sum)
        {
            cout << item << " ";
        }
        cout << "\n";
    }
};

int main()
{
    vector<int> start = {1, 2, 3, 4, 5, 6};
    PrefSum prefSum(start);
    prefSum.PRINT();
}