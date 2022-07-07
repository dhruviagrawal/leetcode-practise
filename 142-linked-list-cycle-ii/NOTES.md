Brute-
hashing can be used
if map has node, cycle exists so return the node
else insert the node in map
TC O(N) and SC O(N)
​
**optimal**
​
we use floyd loop detection algo
finding the entry point of loop
SC becomes O(1)
​
when slow==fast found,
slow=head again
now slow 1 step and fast 1 step
so next time slow n fast collide (here slow is called entry), that is entry point of loop.
​
great video for intuition- https://www.youtube.com/watch?v=qsPoOVAHV_I&list=PLPyD8bF-abzuor0yYzO1g7v8y7u6vO-Fe&t=0s