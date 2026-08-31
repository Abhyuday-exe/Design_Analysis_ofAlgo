// Name: ABHYUDAY SINGH
// Rollno.: 25/DA/004

#include <iostream>
using namespace std;
#include <vector>

int partfunction(vector <int> &arr, int low, int high ){
    int pivot = arr[low];
    int i = low;
    int j= high;
    while(i<j){
        while((arr[i] <= pivot) && (i<= high-1)){
            i++;
        
        }
        while((arr[j]> pivot) && (j>=low)){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;

}

void quicksort(vector <int> &arr, int low, int high){
    if(low<high){
        int partition = partfunction(arr, low, high);
        quicksort(arr, low, partition-1);
        quicksort(arr, partition+1, high);
    }
}

int main(){
    vector <int> arr ={12,2,4,9,2,0,90,56,13,7};
    quicksort(arr,0,9);
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;
}