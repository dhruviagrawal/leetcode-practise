When there is given minimum or shortest, go for BFS cuz it will give shortest path more early.
take queue, add all nodes initially
queue has {node, {dist curr, mask}}
mask tells all nodes covered or not
nth bit of mask tells nth node covered -> 5 4 3 2 1th node covered or not
0 not covered, 1 covered
when 1111 mask, stop n return dist
​
x<<y (left shift) == x(2^y)
so all= (1<<n)-1
=2^n-1
ex- 5 nodes, 2^5=32=100000-1= 11111 needed!
​