#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>&nums){
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0 ; j<n-i-1;j++ ){
                if(nums[j] > nums[j+1]){
                    swap(nums[j] , nums[j+1]);
                }
            }
        }
}


int main(){

    vector<int>arr = { 50,30 ,20,15,56,89,45,23,94};
    bubble_sort(arr);
    for(auto ele : arr) cout<<ele<<" ";
 
    return 0;
} 