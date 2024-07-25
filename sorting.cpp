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

void selection_sort(vector<int>&nums){
      int n = nums.size();
        
    for(int i=0;i<n-1;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(nums[j] < nums[min_index]){
                min_index = j;
            }
        }
        swap(nums[i] , nums[min_index]);
        
    }

}

    int partition(vector<int>&nums , int s, int e){
        int pivot = nums[s];
        int i =s + 1;
        int j = e;

        while(i<=j){
            if(nums[i] <= pivot){
                i++;
            }
            else if(nums[j] > pivot){
                j--;
            }
            else{
                swap(nums[i] , nums[j]);
                i++;
                j--;
            }
        }

      

        swap(nums[s] , nums[j]);
        return j;
    }

    void quicksort(vector<int>&nums , int s , int e){
        if(s>= e){
            return ;
        }

        int p = partition(nums , s, e);

        quicksort(nums , s , p-1);
        quicksort(nums , p+ 1, e);
    }



int main(){

    vector<int>arr = { 50,30 ,20,15,56,89,45,23,94};
    // bubble_sort(arr);
    // insertion_sort(arr);
    // selection_sort(arr);
    quicksort(arr , 0 ,arr.size()-1);
    for(auto ele : arr) cout<<ele<<" ";
 
    return 0;
} 