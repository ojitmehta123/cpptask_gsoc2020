# cpptask_gsoc2020
Contains source code for the JDERobot GSOC 2020 cpp task of longest path in a labyrinth

## Labyrinth
Let's imagine you are outside a labyrinth described as walls (#) and holes (.) where you
can not pass through the walls and you can only move to adjacent holes. Diagonal
adjacencies will not be taken into account, only vertical and horizontal.
The application finds the largest pathway moving only between holes, reading
the labyrinth schema from a txt file, using only standard libraries of c++11. All the lines in
the input file will have the same number of elements. The application saves the
schema of the largest detected pathway, overwriting the holes (.) with the order in which
the hole has been visited.

**Note**: The packages have been tested with gtest on Ubuntu 18.04  
To use this repo do:

```bash
git clone https://github.com/cpptask_gsoc2020.git 
cd cpptask_gsoc2020
mkdir build && cd build
make
ctest -VV
```

### Some Tests have been written.

## To write your own tests:
1) Make a test text file in *cpptask_gsoc2020/src/data/mytest.txt* with your schematic.
2) Write your test in directory *cpptask_gsoc2020/tests/laby_test.cpp* with the following basic gtest template:


```cpp
std::string f("/home/ojit/temp/task_g/cpp_task/src/data/mytest.txt");
TEST (test , File_Read)
{
    laby::Laby l{f};
    EXPECT_TRUE (l.GetData());
}

TEST (test , LabyTest)
{
    laby::Laby l{f};
    
    EXPECT_TRUE (l.GetData());
    
    int entry_locs = l.GetEntryLoc(); //where entry_locs is the number of places to enter the maze
    
    EXPECT_TRUE (l.GetPath());

    l.PrintPath();

}
```
