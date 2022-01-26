// Binary search can be done to sorted arrays
#include<iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    cout<<endl<<"Elements are"<<endl;
    for(i=0;i<arr.length; i++)
    {
       cout<< arr.A[i]<<" ";
    }
}

void Append(struct Array *arr, int x)   // as it is going to modify an array, it should be call by address type
{
    if(arr->length<arr->size)
    {
        arr->A[arr->length++] = x;
    }
}     

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if(index>=0 && index<=arr->length)
    {
        for(i=arr->length; i>index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}
int Delete(struct Array *arr, int index)
{
    int x=0;
    int i;
    if(index>=0 && index<arr->length)
    {
        x = arr->A[index];
        for(i=index; i<arr->length-1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;

        return x;
    }
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(struct Array *arr, int key)
{
    int i;
    for(i=0; i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l=0;
    h= arr.length-1;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
        {
            return mid;
        }
        else if(key<arr.A[mid])
        {
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key)
{
    int mid;
    if(l<=h)
    {
        mid = (l+h)/2;
        if(key==a[mid])
        {
            return mid;
        }
        else if(key < a[mid])
        {
            return RBinSearch(a, l, mid-1, key);
        }
        else{
            return RBinSearch(a, mid+1, h, key);
        }
    }
    return -1;
}
int main()
{
    struct Array arr={{2,3,4,5,6}, 10, 5};

    cout<<RBinSearch(arr.A, 0, arr.length-1, 5);
    // cout<<BinarySearch(arr, 4);

    return 0;
}

// Time complexity is GIF(log (n+1) to base 2)