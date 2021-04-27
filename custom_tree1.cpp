#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Tree
{

private:
    vector<int> t;

    void build(vector<int> a, int i, int l, int r)
    {
        if (r - l == 1)
        {
            t[i] = a[l];
        }
        else
        {
            int m = (l + r) / 2;
            build(a, 2*i+1, l, m);
            build(a, 2*i+2, m, r);
            t[i] = t[2*i + 1] + t[2*i +2];
        }
    }

public:
    void init(vector<int> a)
    {
        t.resize(4 * a.size(), 0);

        build(a, 0, 0, a.size());
    }
};

int main()
{
    vector<int> a = {1, 2, 3};
    Tree tree;
    tree.init(a);

    cout << "1" << endl;
}