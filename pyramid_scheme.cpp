#include <bits/stdc++.h>
using namespace std;

vector<int> vector_, cost;
vector<vector<int>> connections;
char a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num, child;

    connections = vector<vector<int>>(100001, vector<int>());
    cost = vector<int>(100001, 0);
    int best = 0;
    while (cin >> num)
    {
        if (num > best)
        {
            best = num;
        }
        child = 0;
        vector_ = vector<int>();

        if (num != -1)
        {

            while ((a = cin.get()) != '\n')
            {
                cout << "a: " << a << endl;
                if (a != ' ')
                {
                    child = child * 10 + int(a - '0');
                    cout << "child " << child << endl;
                }
                else
                {
                    cout << "else" << endl;
                    vector_.push_back(child);
                    child = 0;
                }
            }

            // Process vector
            for (unsigned long int i = 0; i < vector_.size(); ++i)
            {
                if (i == vector_.size() - 1)
                {
                    cost[vector_[0]] = vector_[vector_.size() - 1];
                }
                else if (i != 0)
                {
                    connections[vector_[0]].push_back(vector_[i]);
                    connections[vector_[i]].push_back(vector_[0]);
                }
            }
        }
        else
        {
            cout << "best: " << best << endl;
            // print connections
            for (int i = 0; i < best + 1; ++i)
            {
                for (unsigned long int j = 0; j < connections[i].size(); ++j)
                {

                    cout << connections[i][j] << " ";
                }
                cout << endl;
            }

            cout << "---------";
            // print cost
            for (int i = 0; i < best + 1; ++i)
            {
                cout << "i: " << i << " cost:" << cost[i] << " ";
            }

            connections = vector<vector<int>>();
            cost = vector<int>();
        }
    }

    return 0;
}