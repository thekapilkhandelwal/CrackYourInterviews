#include<bits/stdc++.h>
using namespace std;

void bubble_recursive_sort(int arr[], int n) {
    if(n == 1) return;
    
    else {
        for(int i=0;i<n-1;i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
        bubble_recursive_sort(arr, n-1);
    }
}


void merge(int arr[], int l, int r, int mid) {
    int n1 = mid-l+1;
    int n2 = r-mid;
    
    int L[n1], R[n2];
    for(int i=0; i<n1; i++) {
        L[i] = arr[l+i]; 
    }
    for(int i=0; i<n2; i++) {
        R[i] = arr[mid+1+i];
    }
    
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) {
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else if(L[i] > R[j]){
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l>=r) return;
        int mid = (l+r-1)/2;
    
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr,l,r, mid);
}

int main() {
    int n; cin>>n;
    int arr[n]; 
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Unsorted: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    
    // Bubble Sort
    // for(int i=0;i<n;i++){
    //     for(int j = 0; j< n-i; j++){
    //         if(arr[j] > arr[j+1]){
    //             swap(arr[j], arr[j+1]);
    //         }
    //     }
    // }
    
    mergeSort(arr,0, n-1);
    
    
    cout<<"\nSorted: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}



