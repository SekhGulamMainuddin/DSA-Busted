/*
5
1 2 3 4 5 
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
*/

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1,j,c=1;
    while (i<=n)
    {
        j=1;
        while (j<=n)
        {
            cout<<c<<" ";
            c++;
            j++;
        }
        cout<<endl;
        i++;

    }

}