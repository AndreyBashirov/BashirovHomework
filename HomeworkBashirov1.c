#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>

/*long long int, сортировка по невозрастанию, методы:пузырёк и быстрая сортировка через рекурсивную реализацию*/
typedef long long int ll;
int bubblecomparisons = 0;
int bubbleswaps = 0;
int quicksortcomparisons = 0;
int quicksortswaps = 0;

void zeros()
{
    bubblecomparisons = 0;
    bubbleswaps = 0;
    quicksortcomparisons = 0;
    quicksortswaps = 0;
}

void randarr(int n, ll* arr)   /*Random elements*/
{
    for(int i = 0; i < n; ++i)
    {
        arr[i] = (ll)rand() * (ll)rand() * (ll)rand();
    }
}

void sorted_arr(int n, ll* arr)    /*Sorted elements*/
{
    BubbleSortWithoutCounters(n, arr);
}

void reversed_sorted_arr(int n, ll* arr)    /*RevSorted elements*/
{
    ReversedBubbleSortWithoutCounters(n, arr);
}
/*
void sorted_arr(int n, ll* arr)
{
    arr = (ll*)realloc(arr, n * sizeof(ll));
    for(int i = 0; i < n; ++i)
    {
        arr[i] = n - i;
    }
}

void reversed_sorted_arr(int n, ll* arr)
{
    arr = (ll*)realloc(arr, n * sizeof(ll));
    for(int i = 0; i < n; ++i)
    {
        arr[i] = i + 1;
    }
}
*/
void bubble_sort(int n, ll* arr)    //BUBBLE SORT
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n - i - 1; ++j)
        {
            bubblecomparisons++;
            if(arr[j] < arr[j + 1])
            {
                bubbleswaps++;
                ll tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void ReversedBubbleSortWithoutCounters(int n, ll* arr)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(arr[j] >= arr[j + 1])
            {
                ll tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void BubbleSortWithoutCounters(int n, ll* arr)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(arr[j] < arr[j + 1])
            {
                ll tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
int partition(ll* arr, int left, int right)     //QUICK SORT MAIN PART
{
    ll pivot = arr[(left + right) / 2];
    while(left <= right){
        while(++quicksortcomparisons, arr[left] > pivot) left++;
        while(++quicksortcomparisons, arr[right] <  pivot) right--;
        if(left <= right){
            if(++quicksortcomparisons, arr[left] < arr[right])
            {
            ++quicksortswaps;
            ll tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            ++left;
            --right;
            }
            else if(arr[left] == arr[right])
            {
                ++left;
                --right;
            }
        }
    }
    return left;
}

void quick_sort(ll* arr, int first, int last)      //RECURSION
{
    if(first >= last) return;
    int pivot = partition(arr, first, last);
    quick_sort(arr, first, pivot - 1);
    quick_sort(arr, pivot, last);
}

void quicksort_final(ll* arr, int n)    //QUICK SORT CALL
{
    quick_sort(arr, 0, n - 1);
}
int main()
{
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    ll* arr1 = (ll*)malloc(n * sizeof(ll));
    randarr(n, arr1);
    ll* arr2 = (ll*)malloc(n * sizeof(ll));
    memcpy(arr2, arr1, n * sizeof(ll));
    sorted_arr(n, arr1);
    sorted_arr(n, arr2);
    bubble_sort(n, arr1);
    quicksort_final(arr2, n);
    printf("Already Sorted Array:\n");
/*
    for(int i = 0; i < n; ++i)
    {
        printf("%lld %lld\n", arr1[i], arr2[i]);
    }
*/
    printf("bubblecomparisons: %lld bubbleswaps: %lld quicksortcomparisons: %lld quicksortswaps: %lld\n", bubblecomparisons, bubbleswaps, quicksortcomparisons, quicksortswaps);
    zeros();
    reversed_sorted_arr(n, arr1);
    reversed_sorted_arr(n, arr2);
    bubble_sort(n, arr1);
    quicksort_final(arr2, n);
    printf("Reversed Sorted Array:\n");
/*
    for(int i = 0; i < n; ++i)
    {
        printf("%lld %lld\n", arr1[i], arr2[i]);
    }
*/
    printf("bubblecomparisons: %lld bubbleswaps: %lld quicksortcomparisons: %lld quicksortswaps: %lld\n", bubblecomparisons, bubbleswaps, quicksortcomparisons, quicksortswaps);
    zeros();
    randarr(n, arr1);
    memcpy(arr2, arr1, n * sizeof(ll));
    bubble_sort(n, arr1);
    quicksort_final(arr2, n);
    printf("Unsorted Array1:\n");
/*
    for(int i = 0; i < n; ++i)
    {
        printf("%lld %lld\n", arr1[i], arr2[i]);
    }
*/
    printf("bubblecomparisons: %lld bubbleswaps: %lld quicksortcomparisons: %lld quicksortswaps: %lld\n", bubblecomparisons, bubbleswaps, quicksortcomparisons, quicksortswaps);
    zeros();
    randarr(n, arr1);
    memcpy(arr2, arr1, n * sizeof(ll));
    bubble_sort(n, arr1);
    quicksort_final(arr2, n);
    printf("Unsorted Array2:\n");
/*
    for(int i = 0; i < n; ++i)
    {
        printf("%lld %lld\n", arr1[i], arr2[i]);
    }
*/
    printf("bubblecomparisons: %lld bubbleswaps: %lld quicksortcomparisons: %lld quicksortswaps: %lld\n", bubblecomparisons, bubbleswaps, quicksortcomparisons, quicksortswaps);
    zeros();
    return 0;
}
