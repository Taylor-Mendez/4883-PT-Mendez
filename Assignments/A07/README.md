## 11080 - Place The Guards
### Taylor Mendez 
### Description:

This program will create a graph based on 
given nodes and connections from an input 
file. Then based on the problem statement
will "place a gaurd" at each node so that
every edge will be gaurded and no two gaurds 
will guard the same edge. A guard is able
to gaurd every edge or "wall" connected to a
node.

The program will output the minimum amount of
guards it takes to guard a castle for each given 
scenario but if a castle cannot be guarded without
causing a fight between guards(aka it is not 
possible to place the guards so that no guards are
assigned to the same wall) the the output will be 
-1

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   0   | [PDF](./p11080.pdf)        | PDF of the problem                                         |
|   1   | [main.cpp](./main.cpp)     | Solution file                                              |
|   2   | [input](./input.txt)       | Test input file from problem statement                     |
|   3   | [input2](./input2.txt)     | Larger test input from udebug                              |
|   4   | [input3](./input3.txt)     | Larger test input from udebug                              |
|   5   | [input4](./input4.txt)     | Larger test input from udebug                              |
|   6   | [input5](./input5.txt)     | Larger test input from udebug                              |
|   7   | [input6](./input6.txt)     | Larger test input from udebug                              |
|   8   | [input7](./input7.txt)     | Larger test input from udebug                              |
|   9   | [banner.txt](./banner.txt) | Banner for print out                                       |

### Instructions

- This project was compiled using C++ 11

### Sources
- This source was used to understand bipartite graphs
    - https://www.geeksforgeeks.org/bipartite-graph/