
// https://practice.geeksforgeeks.org/problems/unique-partitions1041/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    static bool cmp(int a,int b){

     return a>b;

 }

 

 set<vector<int>> s;

 void solve(vector<int> &temp , int x, int n ){

     if(x==0){

         s.insert(temp);

         return;

     }

     for(int i=n;i>=1;i--){

        if(i<=x){

        if(temp.size()==0 || (temp.size()>0 && i<=temp[temp.size()-1])){

        temp.push_back(i);

        solve(temp,x-i,n);

        temp.pop_back();

        }

        }

        

      }

 }

    vector<vector<int>> UniquePartitions(int n) {

        vector<int> temp;

        

        vector<vector<int>> ans;

        solve(temp,n,n);

        for(auto it : s){

            ans.push_back(it);

        }

        sort(ans.begin(),ans.end(),greater<vector<int>>());

        return ans;

    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends