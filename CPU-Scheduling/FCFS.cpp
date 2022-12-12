#include <iostream>
#include<vector>
using namespace std;
vector<vector<int>> Table;
int avgTat = 0, avgWt = 0;
void FCFS()
{
    int ct;
    int n = Table.size();
    // finding ct for first
    ct = Table[0][1] + Table[0][2];
    Table[0][3] = ct;
    Table[0][4] = ct-Table[0][1];
    Table[0][5] = Table[0][4]-Table[0][2];
    avgTat += Table[0][4];
    avgWt +=  Table[0][5];
    for(int i=1;i<n;i++){
        if(ct>=Table[i][1]){
            ct += Table[i][2];
        }
        else{
            ct = Table[i][1] + Table[i][2];
        }
        Table[i][3] = ct;
        Table[i][4] = ct-Table[i][1];
        Table[i][5] = Table[i][4] - Table[i][2];

        avgTat += Table[i][4];
        avgWt += Table[i][5];
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
    cout << "Processes are executed via FCFS..." << endl;
    //calling FCFS()
    FCFS();
    cout << "Table is : " << endl;
    cout << "Pro"
         << " "
         << "Arr"
         << " "
         << "BT "
         << " "
         <<"CT"
         <<" "
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