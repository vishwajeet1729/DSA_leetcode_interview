// Last updated: 1/17/2026, 12:28:59 PM
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& arr, vector<int>& arr2) {
        int ct=0;
        sort(arr.begin(),arr.end());
        sort(arr2.begin(),arr2.end());
     int i=0,j=0;
     while(j<arr2.size()&&i<arr.size()){
        if(arr[i]<=arr2[j]){
            i++;j++;
            ct++;
        }     
        else j++;
        
     }
     return ct;
    //  cout<<ct<<endl;  
    }
};