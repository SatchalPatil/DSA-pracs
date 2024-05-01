#include <iostream>
using namespace std;

void minheap(int arr[],int n,int i){
int small=i;
int left = 2* i + 1;
int right = 2* i +2;

if(n>left && arr[left]<arr[small]){
small = left;
}

if(n>right && arr[right]<arr[small]){
small = right;
}

if(small!=i){
swap(arr[i],arr[small]);
minheap(arr,n,small);
}
}

void maxheap(int arr[],int n,int i){
int large=i;
int left= 2*i+1;
int right=2*i+2;

if(n>left && arr[left]>arr[large]){
large=left;
}

if(n>right && arr[right]>arr[large]){
large=right;
}

if(large!=i){
swap(arr[i],arr[large]);
maxheap(arr,n,large);
}
}


int main()
{
int n;
cout<<"enter the number of students:  ";
cin>>n;
int arr[n];
int i;
for(i=0;i<n;i++){
cout<<"enter the marks of "<<i<<"th student";
cin>>arr[i];
}

for(i=n/2-1;i>=0;i--){
minheap(arr,n,i);
}
cout<<"min score is: "<<arr[0];

for(i=n/2-1;i>=0;i--){
maxheap(arr,n,i);
}
cout<<"max score is: "<<arr[0];
return 0;

}

