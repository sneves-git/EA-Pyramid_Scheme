/*
    Problema 2
     Sofia Neves - 2019220082
     Tatiana Almeida - 2019219581
*/

#include <bits/stdc++.h>
using namespace std;

string input;
stringstream ss;
vector<int> vector_;

struct Node
{
    int id, cost,
        used_node, used_money,
        unused_node, unused_money;

    vector<int> child;
};
vector<Node> nodes;

void pyramid_scheme(int id)
{
    // I'm a LEAF
    if (nodes[id].child.size() == 0)
    {
        nodes[id].used_node = 1;
        nodes[id].used_money = nodes[id].cost;
        nodes[id].unused_node = 0;
        nodes[id].unused_money = 0;
        return;
    }

    for (long unsigned int i = 0; i < nodes[id].child.size(); ++i)
    {
        pyramid_scheme(nodes[id].child[i]);
    }

    nodes[id].used_node = 1;
    nodes[id].used_money = nodes[id].cost;
    for (long unsigned int i = 0; i < nodes[id].child.size(); ++i)
    {
        nodes[id].unused_node += nodes[nodes[id].child[i]].used_node;
        nodes[id].unused_money += nodes[nodes[id].child[i]].used_money;

        // USE MY SON IS BETTER
        if (nodes[nodes[id].child[i]].used_node < nodes[nodes[id].child[i]].unused_node)
        {
            nodes[id].used_node += nodes[nodes[id].child[i]].used_node;
            nodes[id].used_money += nodes[nodes[id].child[i]].used_money;
        }
        // NOT USE MY SON IS BETTER
        else if (nodes[nodes[id].child[i]].used_node > nodes[nodes[id].child[i]].unused_node)
        {
            nodes[id].used_node += nodes[nodes[id].child[i]].unused_node;
            nodes[id].used_money += nodes[nodes[id].child[i]].unused_money;
        }
        // THE SAME NUMBER OF NODES COUNTER
        else
        {
            if (nodes[nodes[id].child[i]].used_money > nodes[nodes[id].child[i]].unused_money)
            {
                nodes[id].used_node += nodes[nodes[id].child[i]].used_node;
                nodes[id].used_money += nodes[nodes[id].child[i]].used_money;
            }
            else
            {
                nodes[id].used_node += nodes[nodes[id].child[i]].unused_node;
                nodes[id].used_money += nodes[nodes[id].child[i]].unused_money;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    nodes = vector<Node>(100001, {.id = -1, .cost = -1, .used_node = 0, .used_money = 0, .unused_node = 0, .unused_money = 0, .child = vector<int>()});

    string line;
    int number, num;
    while (getline(cin, line))
    {
        stringstream X(line);

        X >> num;

        Node node;
        node.id = num;

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
                    node.cost = vector_[vector_.size() - 1];
                }
                else
                {
                    node.child.push_back(vector_[i]);
                }
            }
            nodes[num] = node;
        }
        else
        {
            pyramid_scheme(0);

            if (nodes[0].used_node < nodes[0].unused_node)
            {
                cout << nodes[0].used_node << " " << nodes[0].used_money << endl;
            }
            else if (nodes[0].used_node > nodes[0].unused_node)
            {
                cout << nodes[0].unused_node << " " << nodes[0].unused_money << endl;
            }
            else
            {
                if (nodes[0].used_money > nodes[0].unused_money)
                {
                    cout << nodes[0].used_node << " " << nodes[0].used_money << endl;
                }
                else
                {
                    cout << nodes[0].unused_node << " " << nodes[0].unused_money << endl;
                }
            }
        }
    }
    return 0;
}