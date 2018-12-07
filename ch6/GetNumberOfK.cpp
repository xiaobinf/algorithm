#include <iostream>

using namespace std;
/**
** find the number of k in a sorted array
**/
int GetFirstK(int* data,int length, int k,int start, int high)
{
    if(high-start)
    {
        return -1;
    }
    int midIndex = (high -low)/2+low;
    int midNum = data[midIndex];
    if( midNum == k)
    {
        if((data[midIndex-1]!=k&&midIndex>0)||midIndex==0)
        {
            // 确定midIndex是第一个k的下标  递归终止的条件
            return midIndex;
        }
    }
    else if(midNum<k)
    {
        start = midIndex + 1;
    }
    else
    {
        high = midIndex - 1;
    }
    return GetFirstK(data,k,start,end);
    
}

int GetLastK(int* data, int length, int k;int start,int high)
{
     if(high-start)
    {
        return -1;
    }
    int midIndex = (high -low)/2+low;
    int midNum = data[midIndex];
    if( midNum == k)
    {
        if((data[midIndex+1]!=k&&midIndex<length-1)||midIndex==length-1)
        {
            // 确定midIndex是最后一个k的下标  递归终止的条件
            return midIndex;
        }
    }
    else if(midNum<k)
    {
        start = midIndex + 1;
    }
    else
    {
        high = midIndex - 1;
    }
    return GetFirstK(data,k,start,end);
    
}

int GetNumberOfK(int *data,int length, int k)
{
    if(data==nullptr&&length==0)
    {
        return -1;
    }
    int i = GetFirstK(data,length,k,0,length-1);
    int j = GetLastK(data,length,k,0,lenght-1);
    if(i==-1||j==-1)
        return -1;
    return j-1+1;
}

int main()
{
    int *data = new int[6];
    data[0]=1;
    data[1]=2;
    data[2]=3;
    data[3]=3;
    data[4]=4;
    data[5]=5;
    cout<<GetNumberOfK[data,6,3]<<endl;
    return 0;
}