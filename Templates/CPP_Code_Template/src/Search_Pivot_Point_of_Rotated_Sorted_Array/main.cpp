#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int> arr, int low, int high) {
	if(low > high) return -1;
	if(low == high) return low;
	int mid = (low + high) >> 1;
	if(mid < high && arr[mid] > arr[mid + 1]) return mid;
	if(mid > low && arr[mid] < arr[mid - 1]) return mid - 1;
	if(arr[low] >= arr[mid]) return getPivot(arr, low, mid - 1);
	return getPivot(arr, mid + 1, high);
}

int main () {}
