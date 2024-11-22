#include<bits/stdc++.h>
using namespace std;


int binary_search(vector<int>&arr, int target ){
    int s =0;
    int e = arr.size() -1;
     int mid = (s+e)/2;

     while(s<=e){
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            e = mid -1 ;
        }
        else{
            s = mid + 1;
        }

        mid = (s+e) / 2;
     }

     return -1;
}

int main(){

    vector<int>arr = {1,2,3,4,8,9,45,56,89,98};
    int target = 89;

   

    int index  = binary_search(arr, target);

    if(index == -1){
        cout<<"element is not found"<<endl;
    }
    else{
        cout<<"element found at index "<<index<<endl;
    }

 
return 0;
}