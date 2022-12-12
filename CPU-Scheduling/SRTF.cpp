#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
vector<vector<int>> Table;
int avgTat = 0, avgWt = 0;
void SRTF()
{
    unordered_map<int, set<pair<int, int>>> mp;
    set<pair<int, int>> runnQue;
    int n = Table.size();
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        int at = Table[i][1];
        int bt = Table[i][2];
        mp[at].insert({bt, i});
    }
    while (!mp[0].empty())
    {
        pair<int, int> val = *(mp[ct].begin());
        mp[ct].erase(val);
        runnQue.insert(val);
    }
    while (!runnQue.empty())
    {
        if (!mp[ct].empty())
        {
            while (!mp[ct].empty())
            {
                pair<int, int> val = *(mp[ct].begin());
                mp[ct].erase(val);
                runnQue.insert(val);
            }
        }
        pair<int, int> p = *(runnQue.begin());
        // erasing because updation will be there
        runnQue.erase(p);
        int rbt = (p.first - 1), id = p.second;
        // incrementing the ct by 1
        ct++;
        // checking the process is finished or not

        if (rbt == 0)
        { // process finsihed
            // ct
            Table[id][3] = ct;
            // tat
            Table[id][4] = ct - Table[id][1];
            avgTat += Table[id][4];
            // wt
            Table[id][5] = Table[id][4] - Table[id][2];
            avgWt += Table[id][5];
        }
        else
        { // not finished move 1 step
            p.first = p.first - 1;
            runnQue.insert(p);
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
    cout << "Processes are executed via SRJF..." << endl;
    // calling SJF()
    SRTF();
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