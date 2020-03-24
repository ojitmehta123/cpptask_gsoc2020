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
git clone https://github.com/ojitmehta123/cpptask_gsoc2020.git 
cd cpptask_gsoc2020
mkdir build && cd build
cmake ..
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

### Testing:
```bash
ojit@tyjo:~/temp/task_g/cpp_task/build$ ctest -VV
UpdateCTestConfiguration  from :/home/ojit/temp/task_g/cpp_task/build/DartConfiguration.tcl
Parse Config file:/home/ojit/temp/task_g/cpp_task/build/DartConfiguration.tcl
UpdateCTestConfiguration  from :/home/ojit/temp/task_g/cpp_task/build/DartConfiguration.tcl
Parse Config file:/home/ojit/temp/task_g/cpp_task/build/DartConfiguration.tcl
Test project /home/ojit/temp/task_g/cpp_task/build
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: laby_test

1: Test command: /home/ojit/temp/task_g/cpp_task/bin/laby_test
1: Test timeout computed to be: 1500
1: [==========] Running 13 tests from 5 test cases.
1: [----------] Global test environment set-up.
1: [----------] 5 tests from test1
1: [ RUN      ] test1.Checkgtest_working
1: [       OK ] test1.Checkgtest_working (0 ms)
1: [ RUN      ] test1.NodeTest
1: [       OK ] test1.NodeTest (0 ms)
1: [ RUN      ] test1.File_Read
1: [       OK ] test1.File_Read (10 ms)
1: [ RUN      ] test1.NeighbourTest
1: [       OK ] test1.NeighbourTest (0 ms)
1: [ RUN      ] test1.LabyTest
1: ----------TEST START----------- 
1: ##.##.#
1: #..##.#
1: #..####
1: #...##.
1: ######.
1: 
1: 7
1: #  #  0  #  #  .  #  
1: #  2  1  #  #  .  #  
1: #  3  4  #  #  #  #  
1: #  .  5  6  #  #  .  
1: #  #  #  #  #  #  .  
1: ----------TEST OVER----------- 
1: [       OK ] test1.LabyTest (1 ms)
1: [----------] 5 tests from test1 (11 ms total)
1: 
1: [----------] 2 tests from test2
1: [ RUN      ] test2.File_Read
1: [       OK ] test2.File_Read (11 ms)
1: [ RUN      ] test2.LabyTest
1: ----------TEST START----------- 
1: ##.##.#
1: ##.#..#
1: ####..#
1: ##....#
1: #######
1: 
1: 9
1: #  #  .  #  #  0  #  
1: #  #  .  #  2  1  #  
1: #  #  #  #  3  4  #  
1: #  #  8  7  6  5  #  
1: #  #  #  #  #  #  #  
1: ----------TEST OVER----------- 
1: [       OK ] test2.LabyTest (1 ms)
1: [----------] 2 tests from test2 (12 ms total)
1: 
1: [----------] 2 tests from test3
1: [ RUN      ] test3.File_Read
1: [       OK ] test3.File_Read (1 ms)
1: [ RUN      ] test3.LabyTest
1: ----------TEST START----------- 
1: .#.##.#
1: ......#
1: ......#
1: ##....#
1: #######
1: 
1: 18
1: 0  #  .  #  #  17 #  
1: 1  4  5  6  7  16 #  
1: 2  3  10 9  8  15 #  
1: #  #  11 12 13 14 #  
1: #  #  #  #  #  #  #  
1: ----------TEST OVER----------- 
1: [       OK ] test3.LabyTest (9 ms)
1: [----------] 2 tests from test3 (10 ms total)
1: 
1: [----------] 2 tests from test4
1: [ RUN      ] test4.File_Read
1: [       OK ] test4.File_Read (12 ms)
1: [ RUN      ] test4.LabyTest
1: ----------TEST START----------- 
1: ..#..#..#.
1: .#.##.#...
1: .#...#..#.
1: .....#.#..
1: #......#.#
1: .#...#...#
1: ...#...#.#
1: #..#......
1: .##.......
1: ..##..##..
1: 
1: 59
1: 57 58 #  .  .  #  .  .  #  .  
1: 56 #  .  #  #  .  #  37 36 35 
1: 55 #  49 48 47 #  39 38 #  34 
1: 54 53 50 45 46 #  40 #  32 33 
1: #  52 51 44 43 42 41 #  31 #  
1: 0  #  6  7  8  #  28 29 30 #  
1: 1  2  5  #  9  10 27 #  .  #  
1: #  3  4  #  12 11 26 25 24 23 
1: .  #  #  .  13 16 17 18 19 22 
1: .  .  #  #  14 15 #  #  20 21 
1: ----------TEST OVER----------- 
1: [       OK ] test4.LabyTest (6512 ms)
1: [----------] 2 tests from test4 (6524 ms total)
1: 
1: [----------] 2 tests from test5
1: [ RUN      ] test5.File_Read
1: [       OK ] test5.File_Read (24 ms)
1: [ RUN      ] test5.LabyTest
1: ----------TEST START----------- 
1: ......
1: ......
1: ......
1: ......
1: 
1: 24
1: 0  1  2  3  4  5  
1: 11 10 9  8  7  6  
1: 12 13 14 15 16 17 
1: 23 22 21 20 19 18 
1: ----------TEST OVER----------- 
1: [       OK ] test5.LabyTest (235 ms)
1: [----------] 2 tests from test5 (260 ms total)
1: 
1: [----------] Global test environment tear-down
1: [==========] 13 tests from 5 test cases ran. (6817 ms total)
1: [  PASSED  ] 13 tests.
1/1 Test #1: laby_test ........................   Passed    6.87 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   7.04 sec
```
