#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int parent(int i)
{
    return (i-1)/2;
}

int left(int arr[],int i)
{
    return (2*i+1);
}
int right(int arr[],int i)
{
    return (2*i+2);
}
void insert(int arr[],int capacity, int &size, int data)
{
    if(size==capacity)
    {
        cout<<"Overflow\n";
        return;
    }
    size++;
    arr[size-1]=data;
    int i=size-1;
    while(i!=0 && arr[parent(i)]>arr[i])
    {
        swap(arr[parent(i)],arr[i]);
        i=parent(i);
    }
}

void decreaseKey(int arr[], int i, int val)
{
    arr[i]=val;
    while(i!=0 && arr[i]<arr[parent(i)])
    {
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }
}
void heapify(int arr[],int i, int size )
{
    int l=left(arr,i);
    int r=right(arr,i);
    int smallest=i;
    
    if(l<size && arr[l]<arr[smallest])
     smallest=l;
     
     if(r<size && arr[r]<arr[smallest])
     smallest=r;
     
     if(smallest!=i)
     {
      swap(arr[i],arr[smallest]);
      heapify(arr,smallest,size);
     }
}
void extractMin(int arr[],int &size)
{
   if(size==0)
   {
       cout<<"underflow\n";
       return;
   }
   if(size==1)
   {
       size--;
       return;
   }
   int i=size-1;
   //swap(arr[i],arr[0]);
   arr[0]=arr[i];
   size--;
   heapify(arr,0,size);
}
void deleteData(int arr[],int &size, int index)
{
    decreaseKey(arr, index, INT_MIN);
    extractMin(arr,size);
}
int main()
{
    int arr[100];
    int capacity=100;
    int size=0;
    insert(arr,capacity, size, 3);
    insert(arr,capacity, size,2);
    insert(arr, capacity, size, 1);
    insert(arr, capacity, size,67);
    insert(arr,capacity, size,34);
    insert(arr, capacity, size, 16);
    insert(arr, capacity, size, 9);
    insert(arr, capacity, size, 15);
    
    cout<<"Heap is: ";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    //extractMin(arr,size);
    deleteData(arr, size, 3);
    
    cout<<"Heap is: ";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    
    
    
    
    
}
