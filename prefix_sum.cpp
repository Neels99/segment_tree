#include <iostream>
#include <vector>
#include <deque>
#include <map>
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
        for (auto item : a){
            add(item);
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

    void remove(int index)
    {
        if ((sum.size() <= index) && (index < 0))
        {
            throw std::out_of_range("size of sum < index in prefix_sum.remove");
        }
        if (sum.size() - 1 == index)
        {
            sum.pop_back();
        }
        else
        {
            int v;
            if (index-1 < 0){
                v = sum[index];
            } else {
                v = sum[index] - sum[index-1];
            }
            for (auto item = sum.begin() + index + 1; item != sum.end(); item++)
            {
                *item -= v;
            }
            sum.erase(sum.begin() + index);
        }
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


    prefSum.remove(10);
    prefSum.PRINT();
}