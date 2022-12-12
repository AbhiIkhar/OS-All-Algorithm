#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<vector<int>> Table;
int avgTat = 0, avgWt = 0;
void SJF()
{
    map<int, set<pair<int, int>>> mp;
    int n = Table.size();
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        int at = Table[i][1];
        int bt = Table[i][2];
        mp[at].insert({bt, i});
    }
    for (auto it : mp)
    {
        set<pair<int, int>> temp = it.second;
        int at = it.first;
        while (!temp.empty())
        {
            auto pr = *(temp.begin());
            temp.erase(pr);
            int bt = pr.first;
            int ind = pr.second;
            cout<<"ind: "<<ind<<" bt: "<<bt<<" at: "<<at<<endl;
            // finding ct
            if (ct >= at)
            {
                ct += bt;
            }
            else
            {
                ct = at+bt;
            }
            Table[ind][3]=ct;
            Table[ind][4]=ct-at;
            Table[ind][5]=Table[ind][4]-bt;

            avgTat += Table[ind][4];
            avgWt += Table[ind][5];
        }
    }
}
int main()
{
    int n;
    cout << "Enter the number of process wants to execute: ";
    cin >> n;
    Table = vector<vector<int>>(n, vector<int>(6, 0)); // initialize with 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> Table[i][j];
        }
    }
    cout << "Processes are executed via SJF..." << endl;
    // calling SJF()
    SJF();
    cout << "Table is : " << endl;
    cout << "Pro"
         << " "
         << "Arr"
         << " "
         << "BT "
         << " "
         << "CT"
         << " "
         << "TAT"
         << " "
         << "WAT"
         << " " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << Table[i][j] << "   ";
        }
        cout << endl;
    }
    float avgT = (float)avgTat / (float)n;
    float avgW = (float)avgWt / (float)n;
    cout << "Average TAT: " << avgT << endl;
    cout << "Average WAT: " << avgW << endl;
    return 0;
}