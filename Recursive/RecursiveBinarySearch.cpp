#include <iostream>

using namespace std;

int BSearchRecur(int arr[], int first, int last, int target) {
	int mid;
	mid = (first + last) / 2;
	
	if (first > last)
		return -1;

	if (target == arr[mid])
		return mid;
	else if (target < arr[mid])
		 return BSearchRecur(arr, first, mid - 1, target);
	else
		 return BSearchRecur(arr, mid + 1, last, target);
}
//int main(void)
//{
//	int arr[10] = {3,4,7,9,10,13,15,18,19,21};//정렬되있는 배열에서 찾기 가능
//	int idx;
//	
//	idx = BSearchRecur(arr,0, sizeof(arr)/sizeof(int) - 1, 18);
//	cout << idx;
//	while (1);
//	return 0;
//}