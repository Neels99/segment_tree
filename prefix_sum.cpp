#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// class a{
//     p
// };

class PrefSum
{
    const int max_size = 10;
    const int real_max_size = max_size * 2;
    deque<int> sum;

private:
    void resize()
    {
        int delta = sum[max_size - 1];
        for (int i = 0; i < max_size; i++)
        {
            //delta += sum.front();
            sum.pop_front();
        }
        for (auto &item : sum)
        {
            item -= delta;
        }
    }

public:
    PrefSum(vector<int> a)
    {
        int i = 0;
        if (sum.empty())
        {
            sum.push_back(a[i]);
            i++;
        }
        for (; i < a.size(); i++)
        {
            sum.push_back(sum.back() + a[i]);
        }
    }

    void add(int v)
    {
        if (sum.size() >= real_max_size)
        {
            resize();
        }
        if (!sum.empty())
        {
            v += sum.back();
        }
        sum.push_back(v);
    }

public:
    void PRINT()
    {
        for (int i = 0; i < sum.size(); i++)
        {
            cout << sum[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    //vector<int> start = {1, 2, 3, 4, 5, 6};
    vector<int> start;
    start.resize(19, 1);
    PrefSum prefSum(start);
    prefSum.PRINT();

    prefSum.add(100);
    prefSum.PRINT();

    prefSum.add(100);
    prefSum.PRINT();
}