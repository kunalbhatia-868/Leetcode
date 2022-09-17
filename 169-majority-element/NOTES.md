​
Moore voting algorithm
for O(n) time and O(1) space else  use map
​
algorithm
- Take two variable count as 1 , curr_value as first element
- Now loop on array from 1-n
- if element is same as curr increase count by 1 else decrease by 1
- if count==0 then instead of decreasing more update the curr_value to element and count to 1
- Now after loop just check count of curr_value and if greater than n/2 return curr_value
​
This works as one number is present greater than n/2 time so Occurance of that no is greater than rest , if we increase on that no and decrease on others we will get that no for sure (Increasing and decreaasing preference of that number)