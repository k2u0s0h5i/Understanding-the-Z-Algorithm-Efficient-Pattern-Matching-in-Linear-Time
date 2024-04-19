# Understanding the Z-Algorithm Efficient Pattern Matching in Linear Time and Space Complexity

## Efficiency:
The Z algorithm efficiently finds all occurrences of a pattern in a text in linear time, making it suitable for large datasets.
It operates with linear space complexity, which means it doesn't require excessive memory allocation.
* ___Let length of text be n and of pattern be m, then total time taken is O(m + n) with linear space complexity___. Now we can see that both time and space complexity is same as KMP algorithm but this algorithm is Simpler to understand.
## What is Z Array? 
* For a string str[0..n-1], the Z array is a list of length n. Each element Z[i] stores the length of the longest substring starting from str[i] that is also a prefix of str[0..n-1].
* The first entry of the Z array is meaningless as the complete string is always a prefix of itself.
## How is Z array helpful in Searching Pattern in Linear time? 
* The idea is to concatenate pattern and text, and create a string “P$T” where P is pattern, $ is a special character should not be present in pattern and text, and T is text. Build the Z array for concatenated string.
* In Z array, if Z value at any point is equal to pattern length, then pattern is present at that point.
