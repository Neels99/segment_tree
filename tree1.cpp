//
//https://e-maxx.ru/algo/segment_tree#24
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MAX_SHARE 1000
#define TREE_SIZE MAX_SHARE * 2 * 4

class SegTree
{
private:
    int tree[TREE_SIZE];
    int n = 0;

private:
    void build(vector<int> a, int v, int l, int r)
    {
        if (l == r)
        {
            tree[v] = a[l];
        }
        else
        {
            int m = (l + r) / 2;
            build(a, v * 2, l, m);
            build(a, v * 2 + 1, m + 1, r);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    int sum(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
        {
            return 0;
            //throw std::invalid_argument("l > r");
        }
        if (l == tl && r == tr)
        {
            return tree[v];
        }
        int m = (tl + tr) / 2;
        return sum(v * 2, tl, m, l, min(r, m)) + sum(v * 2 + 1, m + 1, tr, max(l, m + 1), r);
    }

    void update(int v, int l, int r, int pos, int new_value)
    {
        if (l == r)
        {
            tree[v] = new_value;
        }
        else
        {
            int m = (l + r) / 2;
            if (pos <= m)
            {
                update(v * 2, l, m, pos, new_value);
            }
            else
            {
                update(v * 2 + 1, m + 1, r, pos, new_value);
            }
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

public:
    void init(vector<int> &a)
    {
        build(a, 1, 0, a.size() - 1);
        n = a.size();
    }

    int get_sum(int l, int r)
    {
        return sum(1, 0, n - 1, l, r);
    }

    void change(int pos, int new_value)
    {
        update(1, 0, n - 1, pos, new_value);
    }

    void add(int value)
    {
        //cout << "n: " << n << endl;
        //++n;
        update(1, 0, n - 1, n, value);
        
    }
};

int main()
{
    SegTree tree;
    vector<int> a = {1, 2, 3, 4, 6, 7};
    tree.init(a);
    cout << tree.get_sum(1, 5) << endl;
    tree.change(3, 1000);
    cout << tree.get_sum(1, 5) << endl;
    //tree.add(10000);
    tree.change(5, 8);
    cout << tree.get_sum(1, 5) << endl;
    // tree.change(6, 1);
    tree.add(0);
    cout << tree.get_sum(1, 5) << endl;
    cout << endl;
}