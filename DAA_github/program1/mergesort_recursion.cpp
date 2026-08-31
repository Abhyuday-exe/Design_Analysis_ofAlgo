// Name: ABHYUDAY SINGH
// Rollno.: 25/DA/004

#include <iostream>
using namespace std;
#include <vector>


void merge(vector<int> &arr, int low,int mid, int high){
    vector <int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}



void mergesort(vector<int> &arr, int low, int high){
    if(low>= high) return;
    int mid = (low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main(){
   vector <int> arr ={12,2,4,9,2,0,90,56,13,7};
    mergesort(arr,0,9);
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;

}