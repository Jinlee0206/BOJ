#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000000];
int b[1000000];

void merge(int a[], int left, int mid, int right)
{
	int i = left;
	int j = mid+1;
	int k = 0;

	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j]) b[k++] = a[i++];
		else b[k++] = a[j++];
	}

	while (i <= mid) b[k++] = a[i++];
	while (j <= right) b[k++] = a[j++];

	k--;

	while (k >= 0)
	{
		a[left + k] = b[k];
		k--;
	}
}

void mergeSort(int a[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;



	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;

}
