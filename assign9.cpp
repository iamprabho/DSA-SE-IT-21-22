#include<iostream>
using namespace std;
void maxheapify(int a[],int i,int n){
    int j,temp;
    temp=a[i];
    j=2*i;
    while(j<=n){
        if(j<n && a[j+1]>a[j]){
            j=j+1;
        }
        if(temp>a[j])
            break;
        else if(temp<=a[j]){
            a[j/2]=a[j];
            j=2*j;
        }
    }
    a[j/2]=temp;
    return;
}
void minheapify(int a[],int i,int n){
    int j,temp;
    temp=a[i];
    j=2*i;
    while(j<=n){
        if(j<n && a[j+1]<a[j]){
            j=j+1;
        }
        if(temp<a[j])
            break;
        else if(temp>=a[j]){
            a[j/2]=a[j];
            j=2*j;
        }
    }
    a[j/2]=temp;
    return;
}
void build_maxheap(int a[],int n){
    int i;
    for(i=n/2;i>=1;i--){
        maxheapify(a,i,n);
    }
}
void build_minheap(int a[],int n){
    int i;
    for(i=n/2;i>=1;i--){
        minheapify(a,i,n);
    }
}
void maxheapsort(int a[],int n){
    int i,temp;
    for(i=n;i>=2;i--){
        //storing maximum value at the end
        temp=a[i];
        a[i]=a[1];
        a[1]=temp;
        //building max heap of remaining element
        maxheapify(a,1,i-1);
    }
}
void minheapsort(int a[],int n){
    int i,temp;
    for(i=n;i>=2;i--){
        //storing minimum value at the end
        temp=a[i];
        a[i]=a[1];
        a[1]=temp;
        //building min heap of remaining element
        minheapify(a,1,i-1);
    }
}
void print(int arr[],int n){
    cout<<"\nSorted data";
    for(int i=1;i<=n;i++){
        cout<<"->"<<arr[i];
    }
    return;
}
int main(){
    int n,i,ch;
    cout<<"\nEnter the number of data element to be sorted: ";
    cin>>n;
    int arr[n];
    for(i=1;i<=n;i++){
        cout<<"Enter element: "<<i<<": ";
        cin>>arr[i];
    }
    do{
        cout<<"\n1. Heap sort using max heap";
        cout<<"\n2. Heap sort using min heap";
        cout<<"\n0. Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            build_maxheap(arr,n);
            maxheapsort(arr,n);
            print(arr,n);
            break;
        case 2:
            build_minheap(arr,n);
            minheapsort(arr,n);
     print(arr,n);
            break;
        case 0:
            cout<<"Exiting....";
            return 0;
        default:
            cout<<"\nINVALID CHOICE!!! Please enter your choice again."<<endl;
            break;
        }
    }while(ch!=0);
}
