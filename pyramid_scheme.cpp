#include <bits/stdc++.h>
using namespace std;

vector<int> vector_, cost, marker;
vector<pair<int, vector<int>>> connections;

string input;
stringstream ss;

void pyramid_scheme(int node)
{
    if (connections[node].second.size() == 0)
    {
        if (marker[connections[node].first] == 0)
        {
            marker[node] = 1;
        }
        return;
    }

    if (marker[connections[node].first] == 0)
    {
        marker[node] = 1;
        for (unsigned long int i = 0; i < connections[node].second.size(); ++i)
        {
            pyramid_scheme(connections[node].second[i]);
        }
        marker[node] = 0;
    }
    else
    {
        marker[node] = 1;
        for (unsigned long int i = 0; i < connections[node].second.size(); ++i)
        {
            pyramid_scheme(connections[node].second[i]);
        }

        marker[node] = 0;
        for (unsigned long int i = 0; i < connections[node].second.size(); ++i)
        {
            pyramid_scheme(connections[node].second[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    connections = vector<pair<int, vector<int>>>(100001, make_pair(-1, vector<int>()));
    cost = vector<int>(100001, 0);
    marker = vector<int>(100001, 0);

    string line;
    int number, num, best = 0;
    while (getline(cin, line))
    {
        stringstream X(line);

        X >> num;

        if (num > best)
        {
            best = num;
        }
        vector_ = vector<int>();

        if (num != -1)
        {
            for (int i = 0; X >> number; ++i)
            {
                vector_.push_back(number);
            }

            for (unsigned long int i = 0; i < vector_.size(); ++i)
            {

                if (i == vector_.size() - 1)
                {
                    cost[num] = vector_[vector_.size() - 1];
                    if (i == 0)
                    {
                        connections[vector_[i]].first = num;
                    }
                }
                else
                {
                    connections[vector_[i]].first = num;
                    (connections[num].second).push_back(vector_[i]);
                }
            }
        }
        else
        {
            /*
            cout << "best: " << best << endl;
            // print connections
            for (int i = 0; i < best + 1; ++i)
            {
                for (unsigned long int j = 0; j < connections[i].second.size(); ++j)
                {
                    cout << "connections[" << i << "][" << j << "] = FIRST: " << connections[i].first << "\tSECOND: " << connections[i].second[j] << " ";
                }
                cout << endl;
            }

            cout << "---------";
            // print cost
            for (int i = 0; i < best + 1; ++i)
            {
                cout << "i: " << i << " cost:" << cost[i] << " " << endl;
            }

            cost = vector<int>();*/

            connections = vector<pair<int, vector<int>>>(100001, make_pair(-1, vector<int>()));
            cost = vector<int>(100001, 0);
            best = 0;
            marker = vector<int>(100001, 0);
        }
    }
    return 0;
}