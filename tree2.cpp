#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int SIZE = (1 << 17);
int a[100100]; // исходный массив
int tree[2 * SIZE]; 
int n; // кол-во элементов в исходном массиве

void build_sum_tree(int v, int L, int R)
{
	if (L == R - 1) // Условие выхода
	{
		if (L < n) // Поскольку мы объявляем большую размерность, необходимо следить за границей
		{
			tree[v] = a[L];
		}
		return; // Присвоили, возвращаемся
	}
	int M = (L + R) / 2; // Выбираем середину отрезка [L..R]
	build_sum_tree(2 * v + 1, L, M); // Запускаем сумму для левого потомка
	build_sum_tree(2 * v + 2, M, R); // И для правого
	tree[v] = tree[2 * v + 1] + tree[2 * v + 2]; // Обновляем текущую вершину
}

// Usage:
// build_sum_tree(0, 0, SIZE); Строим дерево от нулевой вершины с границей от 0 до SIZE (можно n)



        
int64_t get_summary(int v, int L, int R, int l, int r) // L, R - обрабатываемые функцией границы, l, r - границы запроса
{
    if (r <= L || R <= l) return 0; // Первое условие
    if (l <= L && R <= r) return tree[v]; // Второе условие
    int M = (L + R) / 2;
    int64_t first_child = get_summary(2 * v + 1, L, M, l, r);
    int64_t second_child = get_summary(2 * v + 2, M, R, l, r);
    return first_child + second_child;
}

// Usage:
// build_sum_tree(0, 0, SIZE);
// int l, r; cin >> l >> r; --l;
// int sum = (get_summary(0, 0, SIZE, l, r));

    


        
void set_in_sum_tree(int v, int L, int R, int i, int x)
{
    if (L == R - 1)
    {
        tree[v] = x;
        a[i] = x;
        return;
    }
    int M = (L + R) / 2;
    if (i < M) set_in_sum_tree(2 * v + 1, L, M, i, x);
    else set_in_sum_tree(2 * v + 2, M, R, i, x);
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

// Usage:
// build_sum_tree(0, 0, SIZE);
// int i, x; cin >> i >> x; --i;
// set_in_sum_tree(0, 0, SIZE, i, x);

    
int main(){
    vector<int> res = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < res.size(); i++){
        a[i] = res[i];
    }
    build_sum_tree(0, 0, SIZE);
    cout << get_summary(0, 0, SIZE, 1, 5);
    //get_summary(0, 0, SIZE, l, r)
}

