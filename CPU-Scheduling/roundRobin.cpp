/* 
 TODO:Need to fix the bug( Code have a bug)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> Table;
int avgTat = 0, avgWt = 0;

void roundRobin()
{
    int n = Table.size();
    int ct = 0;
    queue<vector<int>> readyQue;
    queue<pair<int, int>> runnQue;
    for (int i = 0; i < n; i++)
    {
        int at = Table[i][1];
        int bt = Table[i][2];
        readyQue.push({at, bt, i});
    }
    int tc; // time contum
    cout << "Input the time Quantum: ";
    cin >> tc;
    while (!readyQue.empty() || !runnQue.empty())
    {
        bool t=false;
        pair<int,int> temp;
        while (!readyQue.empty() && readyQue.front()[0] <= ct)
        {
            cout<<"arrival: "<<readyQue.front()[0]<<endl;
            vector<int> r = readyQue.front();
            readyQue.pop();
            if(!runnQue.empty()){
                 temp = runnQue.front();
                 t=true;
            }
            runnQue.push({r[1], r[2]});
        }
        if(t){
            runnQue.push(temp);
        }
        if (!runnQue.empty())
        {
            pair<int, int> val = runnQue.front();
            runnQue.pop();
            int bt = val.first;
            int id = val.second;

            if (bt <= tc)
            { // process is completed
                cout<<"id"<<id<<endl;
                ct += bt;
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
            { // process is not completed
                ct += tc;
                bt -= tc;
                val.first = bt;
                runnQue.push(val);
            }
        }
        else // CPU remain idle 
        {
            cout<<"c++ mai aaya.."<<endl;
            ct++;
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
    cout << "Processes are executed via Round Robin..." << endl;
    // calling
    roundRobin();
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