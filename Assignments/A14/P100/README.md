## 100 - The 3n + 1 problem
### Taylor Mendez 
### Description:

Given the following algorithm to find cycle
length of an integer:
    1. input n
    2. print n
    3. if n = 1 then STOP
        4. if n is odd then n <- 3n + 1
        5. else n <- n/2
    6. GOTO 2

The program will find the maximum cycle
length over all numbers between (and 
including) two given integers i and j

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   0   | [PDF](./p100.pdf)          | PDF of the problem                                         |
|   1   | [main.cpp](./main.cpp)     | Solution file                                              |
|   2   | [input](./input.txt)       | Test input file from problem statement                     |
|   3   | [input2](./input2.txt)     | Larger test input from udebug                              |

### Instructions

- This project was compiled using C++ 11