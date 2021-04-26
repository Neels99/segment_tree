#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define DELTAS_TYPE map<pair<int, int>, int>

int get_sum(DELTAS_TYPE &deltas, int h, int j);

int set_sum(DELTAS_TYPE &deltas, int h, int j){
    deltas[{h, j}] = get_sum(deltas, h, j - 1) + deltas[{j, j}];
    return deltas[{h, j}];
}

//[h, j)
int get_sum(DELTAS_TYPE &deltas, int h, int j)
{
    if (deltas.find({h, j}) != deltas.end())
    {
        cout << 111 << " " << h << " " << j << ": " << deltas[{h, j}] << endl;
        return deltas[{h, j}];
    }
    else
    {
        // if (h == j - 1)
        {
            cout << 222 << " " << h << " " << j << ": " << deltas[{h, j}] << endl;
            return set_sum(deltas, h, j);
        }
        // else
        // {
        //     cout << 333 << " " << h << " " << j << ": " << deltas[{h, j}] << endl;
        //     return get_sum(deltas, h, j - 1);
        // }
    }
}



int main()
{
    DELTAS_TYPE deltas;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < a.size(); i++)
    {
        deltas[{i, i}] = a[i];
    }

    cout << get_sum(deltas, 2, 6) << endl;
    cout << get_sum(deltas, 3, 5) << endl;
}