# IF3130 Computer Network
Distance Vector Protocol simulation implemented with C++.

## How to run
On the root directory, compile program:
```
make
```

To run program with provided test case sample_input.txt:
```
make test
```

To run program with manual input:
```
make run
```

## Input format
Note: texts inside brackets are comments

```
5 4 (5 nodes and 4 edges)
1 2 (node 1 is connected to node 2)
2 3 (node 2 is connected to node 3)
3 4 (node 3 is connected to node 4)
4 5 (node 4 is connected to node 5)
5   (there are 5 scenarios)
1 2 (node 1 sends information to node 2)
2 3 (node 2 sends information to node 3)
2 1 (node 2 sends information to node 1)
3 4 (node 3 sends information to node 4)
4 5 (node 4 sends information to node 5)
```

## Output format
Note: texts inside brackets are comments

```
0 1 (routing table for node 1)
1 2
2 2
-1 -1
-1 -1
1 1 (routing table for node 2)
0 2
1 3
-1 -1
-1 -1
2 2 (routing table for node 3)
1 2
0 3
1 4
-1 -1
3 3 (routing table for node 4)
2 3
1 3
0 4
1 5
4 4 (routing table for node 5)
3 4
2 4
1 4
0 5
```

# Acknowledgement
This project is a requirement to complete the 2nd assignment of IF2130 Computer Network.
