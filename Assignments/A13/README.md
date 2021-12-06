## 1112 - Mice and Maze
### Taylor Mendez 
### Description:

Give a maze (that is essentially a 
weighted graph) with a given number
of nodes and weighted edges assume 
there is a mouse in each node. Determine
the amount of mice that will be able to 
make it out of the maze in a certain 
amount of given time.

My soultion involves using the bellman
ford algorithm but using it backwards
where a from -> to designation between 
nodes will be to -> from instead.

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   0   | [PDF](./p1112.pdf)         | PDF of the problem                                         |
|   1   | [main.cpp](./main.cpp)     | Solution file                                              |
|   2   | [input](./input.txt)       | Test input file from problem statement                     |
|   3   | [input2](./input2.txt)     | Larger test input from udebug                              |
|   4   | [input3](./input3.txt)     | Larger test input from udebug                              |


### Instructions

- This project was compiled using C++ 11

### Sources
- Source used to understand the bellman ford algorithm
    - https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/
