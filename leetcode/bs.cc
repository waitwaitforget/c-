#include <iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int target) {
    if (l > r) {return -1;}
    int mid = l + (r - l) / 2;
    if (arr[mid] == target) 
        return target;
    else if (arr[mid] > target) 
        return binarySearch(arr, l, mid - 1, target);
    else 
        return binarySearch(arr, mid+1, r, target);
}

int main() {
    int arr[] = {12,33,42,1,2,23,4,45};
    cout << binarySearch(arr, 0, 7, 23) << endl;
    return 0;
}