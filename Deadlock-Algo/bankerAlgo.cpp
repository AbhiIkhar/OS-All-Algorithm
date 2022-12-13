#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> allo;
vector<vector<int>> maxNeed;
vector<vector<int>> remNeed;
vector<int> avail;
vector<int> seq;
bool bankerAlgo(int n,int r){
      queue<int>q; // to add processes sequentially
      bool isDeadlock = false;
      for(int i=0;i<n;i++){
        q.push(i);
      }
      int count=0; // to count the number of process which is not get fullfilled 
      // if count==n in future then deadlock will occur 
    
      while(!q.empty()){
           int node = q.front();
           q.pop();
           bool needFill = true;
           for(int i=0;i<r;i++){
                if(avail[i]<remNeed[node][i]){
                    needFill = false;
                }
           }
           if(needFill){
                seq.push_back(node);
                count=0;
                // increasing availability
                for(int i=0;i<r;i++){
                   avail[i] += allo[node][i];
                }
           }
           else{
               count++;
               q.push(node);
           }
           if(count==n){  // deadlock occured
              isDeadlock = true;
              break;
           }
      }
    return isDeadlock;
}
void input2dArr(vector<vector<int>> &vec){
    int n = vec.size(), m = vec[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];
        }
    }
}
void input1dArr(vector<int> &vec){
    int n = vec.size();
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
}
int main(){
    int n,r;
    cout<<"Enter the number of process and number of resources: ";
    cin>>n>>r;
    cout<<endl;
    allo = vector<vector<int>>(n,vector<int>(r));
    maxNeed = vector<vector<int>>(n,vector<int>(r));
    remNeed = vector<vector<int>>(n,vector<int>(r));
    avail = vector<int>(r);
    cout<<"Enter the allocated resources to each process: "<<endl;
    input2dArr(allo); // alloacated
    cout<<"Enter the max need to each process: "<<endl;
    input2dArr(maxNeed); //maxneed
    cout<<"Enter the availablelity of each resources: "<<endl;
    input1dArr(avail); //available resources
    // Finding the remaining need 
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            remNeed[i][j] = maxNeed[i][j]-allo[i][j]; //remaining Need
        }
    }
    bool isDeadlock = bankerAlgo(n,r);
    if(isDeadlock){
        cout<<"Deadlock is occured so, No safe sequence of process is there "<<endl;
    }
    else{
        cout<<"No Deadlock is occured and safe seq is as follows: "<<endl;
        for(int i=0;i<n;i++){
            cout<<"P"<<seq[i]<<"<-";
        }cout<<endl;
    }
    return 0;    
}