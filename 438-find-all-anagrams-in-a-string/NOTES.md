Character frequency map of Anagrams are same!
1. all letters same
2. count of all letters same
​
Sliding Window Technique-
fixed size
take a pattern vector size 26 to store frequency of each alphabet
make current window vector
if both vector same, anagram choose starting index.
​
on changing window, update the vector- removing first ele of window n adding next
​
TC O(26*n)=O(n)
SC O(1)
​
​