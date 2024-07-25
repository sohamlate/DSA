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

void insertion_sort(vector<int>&nums){
       int n = nums.size();
        
        for(int i=1;i<n;i++){
            int key = nums[i];
            int j =i-1;
            while(j>=0 && nums[j] > key){
               nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = key;
        }
}


int main(){

    vector<int>arr = { 50,30 ,20,15,56,89,45,23,94};
    // bubble_sort(arr);
    insertion_sort(arr);
    for(auto ele : arr) cout<<ele<<" ";
 
    return 0;
} 