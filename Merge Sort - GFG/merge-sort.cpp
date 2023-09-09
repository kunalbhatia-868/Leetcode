//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        vector<int> temp(r-l+1);
        
        int t1=l;
        int t2=m+1;
        int k=0;
        while(t1<=m && t2<=r)
        {
           if(arr[t1]<arr[t2])
            {
                temp[k]=arr[t1];
                t1++;
            }
            else{
                temp[k]=arr[t2];
                t2++;
            }
            k++;
        }
        while(t2<=r)
        {
            temp[k]=arr[t2];
            t2++;
            k++;
        }
        while(t1<=m)
        {
            temp[k]=arr[t1];
            t1++;
            k++;
        }
         
        for (int i = l, idx = 0; i <= r; i++, idx++)
        {
            arr[i] = temp[idx];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r)
        {
            int m=l+(r-l)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends