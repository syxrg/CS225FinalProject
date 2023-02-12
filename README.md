# BBIS
# Shortest Path Airports Route System

### Group Members
- Serena Gong
- Bob Jiang
- Irina Vyacheslavovna Malyugina 
- Jung Soo (Ben) Park

### Overview

Our project is based on interpreting the Airports Route System from the Openflight Dataset. Our 2 main goals are to find the shortest distance between two airports, and to see if airports are strongly connected, and if so, which components are strongly connected. We will be utilising Breadth First Search to gather an output of airports in traversal order. We will also use Dijkstra's Algorithm to find the shortest distance between 2 airports. To find if airports are strongly connected, and which components are strongly connected, we will be utilising Kosaraju's algorithm. 

### File Structure 
 
`BFS.cpp` is where the implentation of Breadth First Search is

`kosaraju.cpp` is where the implementation of Kosaraju Algorithm is 

`shortestpath.cpp` is where the implementation of Dijkstra's Algorithm is

`main.cpp` is where the program is executed. 

`test.cpp` is where important test cases are that authenticate the implemention of our chosen algorithms

### Run Instructions

To run our project, you can either clone this project by copy and pasting the following: 

```
git clone https://github.com/BobJ-coder/CS-225-Final-Project-BBIS-Fall-2022.git 
```
or, you can pull a zip file of the repo onto your local computer.

Next, run the following in the final project directory of the project:
```
mkdir build
cd build
cmake
```
Finally,
To compile the code:
 ``` 
 make
 ```
 
 To run the program:
 ``` 
 ./main
 ```
 
 To run the test cases:
 ``` 
 ./test
 ```
 
### Example Output
See output.png

 
### Presentation Video 
https://youtu.be/eZJ3kY15v7Y
