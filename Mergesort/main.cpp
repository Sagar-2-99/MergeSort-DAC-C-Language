#include <iostream>


void printArray(int b[],int a)
{
    std::cout<<"Elements of array are: ";
    for(int i=0; i<a; i++)
    {
        std::cout<<b[i]<<" ";
    }
    std::cout<<std::endl;
}

void mergeArray(int b[],int a,int mid,int c)
{
//we need to form another array as during sorting the position of mid will change due to which we won't
//be able to resolve the location of the mid and it would be tough so forming a new array

    int d=mid-a+1;
    int e=c-mid;
    int f[d],g[e];
    for(int i=0; i<d; i++)
    {
        f[i]=b[a+i];
    }
    for(int j=0; j<e; j++)
    {
        g[j]=b[mid+j+1];
    }
    int i=0;
    int j=0;
    int k=a;

    while(i<d && j<e)
    {
        if(f[i]<=g[j])
        {
            b[k]=f[i];
            i++;
        }
        else
        {
            b[k]=g[j];
            j++;
        }
        k++;
    }
    while(i<d)
    {
        b[k]=f[i];
        i++;
        k++;
    }
    while(j<e)
    {
        b[k]=g[j];
        j++;
        k++;
    }
}

void mergeSort(int b[],int a,int c)
{
    if(a<c)
    {
        int mid=(a+c)/2;
        mergeSort(b,a,mid);
        mergeSort(b,mid+1,c);
        mergeArray(b,a,mid,c);
    }
}

int main()
{
    std::cout<<"Enter the number of elements you want in array"<<std::endl;
    int a;
    std::cin>>a;
    int b[a];
    for(int i=0; i<a; i++)
    {
        std::cout<<"Enter the data for the index "<<i<<std::endl;
        std::cin>>b[i];
    }
    printArray(b,a);
    mergeSort(b,0,a-1);
    printArray(b,a);
}
