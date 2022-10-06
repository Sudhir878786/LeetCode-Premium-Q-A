#include <bits/stdc++.h> 
bool isBSTPreorder(vector<int> &arr) 
{
    // Write your code here.
    stack<int>st;
    int root=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<root){
            return false;
        }
        while(!st.empty() and st.top()<arr[i]){
            root=st.top();
            st.pop();
        }
        st.push(arr[i]);
    }
    return true;
}
