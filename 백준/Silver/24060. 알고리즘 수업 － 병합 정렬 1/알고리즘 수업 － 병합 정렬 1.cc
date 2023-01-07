#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A, k, num, cnt, *nums, *tmp, answer = -1;

// A[p...q]와 A[q+1...r]을 병합하여 A[p...r]을 오름차순 정렬된 상태로 만든다
// A[p...q]와 A[q+1...r]은 이미 오름차순으로 정렬되어 있다
void merge(int* arr, int p, int q, int r)
{
    int i, j, t;
    i = p;
    j = q + 1;
    t = 1;

    // 분할 정렬된 리스트의 병합
    while (i <= q && j <= r)
    {
        if (arr[i] <= arr[j]) tmp[t++] = arr[i++];
        else tmp[t++] = arr[j++];
    }
    // 왼쪽 배열 부분이 남은 경우
    while (i <= q) tmp[t++] = arr[i++];
    // 오른쪽 배열 부분이 남은 경우
    while (j <= r) tmp[t++] = arr[j++];

    i = p; t = 1;
    // 결과를 A[p...r]에 저장
    while (i <= r)
    {
        arr[i++] = tmp[t++];
        cnt++;
        if (cnt == k)
        {
            answer = arr[i - 1];
            break;
        }
    }
}

void merge_sort(int* arr, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2; // 중간지점 정의
        merge_sort(arr, p, q); // 전반부 정렬
        merge_sort(arr, q + 1, r); // 후반부 정렬
        merge(arr, p, q, r); // 병합
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> k;

    nums = new int[A];
    tmp = new int[A];

    for (int i = 0; i < A; i++)
    {
        cin >> num;
        nums[i] = num;
    }

    merge_sort(nums, 0, A - 1);

    cout << answer << '\n';

    delete[] nums;
    delete[] tmp;

    return 0;
}