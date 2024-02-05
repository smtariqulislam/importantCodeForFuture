#include <bits/stdc++.h>
using namespace std;

bool vis[1001][1001];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char** a;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int x, int y, int dest_i, int dest_j)
{
    if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '-' || vis[x][y])
    {
        return;
    }

    vis[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = x + d[i].first;
        int cj = y + d[i].second;

        if (valid(ci, cj) && !vis[ci][cj] && a[ci][cj] == '.')
        {
            dfs(ci, cj, dest_i, dest_j);
        }
    }
}

bool inSameComponent(int source_i, int source_j, int dest_i, int dest_j)
{
    memset(vis, false, sizeof(vis));
    dfs(source_i, source_j, dest_i, dest_j);
    return vis[dest_i][dest_j];
}

int main()
{
    cin >> n >> m;

    // Dynamic memory allocation for 'a'
    a = new char*[n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = new char[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int source_i, source_j, dest_i, dest_j;
    cin >> source_i >> source_j >> dest_i >> dest_j;

    if (inSameComponent(source_i, source_j, dest_i, dest_j))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    // Deallocate memory
    for (int i = 0; i < n; ++i)
    {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}