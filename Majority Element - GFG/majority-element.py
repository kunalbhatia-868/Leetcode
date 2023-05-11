#User function template for Python 3

# 3 1 3 3 2

# 1 2 3 3 3

# count=1
# curr=A[0]
# 1->N
# if A[i]==curr:
#     count++
# else:
#     count=1
#     curr=A[i]
# if count>N/2:
#     return curr

class Solution:
    def majorityElement(self, A, N):
        #Your code here
        if N==1:
            return A[0]
        
        A.sort()
        
        count=1
        curr=A[0]
        for idx in range(1,N):
            if A[idx]==curr:
                count+=1
            else:
                count=1
                curr=A[idx]
            
            if count>N/2:
                return curr
            
        
        return -1 
        
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

from sys import stdin


def main():
        T=int(input())
        while(T>0):
            
            N=int(input())

            A=[int(x) for x in input().strip().split()]
            
            
            obj = Solution()
            print(obj.majorityElement(A,N))
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends