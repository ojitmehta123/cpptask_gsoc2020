#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "laby.h"

int epoints1 = 4 , rows1 = 5 , cols1 = 7;
std::string f1("/home/ojit/temp/task_g/cpp_task/src/data/sample_data.txt");

TEST (test1 , Checkgtest_working) {
    EXPECT_EQ (1,1);
}

TEST (test1 , NodeTest) {
    laby::Node n1{1,2} , n2 {3,4} , n3 {1,4} , n4 {2,3} , n5{1,2};
    EXPECT_EQ (1,n1.x());
    EXPECT_EQ (2,n1.y());
    EXPECT_EQ (true , n1 == n5);
    EXPECT_EQ (false , n1 == n2);
    EXPECT_EQ (false , n1 == n3);
    EXPECT_EQ (false , n1 == n4);
    EXPECT_EQ (false , n2 == n3);
    EXPECT_EQ (true , n1 == n1);
}

TEST (test1 , File_Read) {
    laby::Laby l{f1};
    EXPECT_TRUE (l.GetData());
    EXPECT_EQ ( rows1 , l.rows());
    EXPECT_EQ ( cols1 , l.cols());

}


TEST (test1 , NeighbourTest) {
    laby::Laby l{f1};
    EXPECT_TRUE (l.GetData());
    std::vector<int> temp1 = {16,22};
    std::vector<int> temp2 = {30};
    std::vector<int> temp3;
    EXPECT_TRUE ( temp1 == l.GetNeighbors(15,8) );
    EXPECT_TRUE ( temp2 != l.GetNeighbors(31,24) );
    EXPECT_TRUE ( temp3 == l.GetNeighbors(34,27) );
    EXPECT_TRUE ( temp3 == l.GetNeighbors(2,9) );
}

TEST (test1 , LabyTest) {
    laby::Laby l{f1};
    EXPECT_TRUE (l.GetData());
    EXPECT_EQ (epoints1 , l.GetEntryLoc());
    EXPECT_TRUE (l.GetPath());

    std::vector<int> temp1 = l.finpath();
    
    // for (auto i = temp1.begin() ; i != temp1.end() ; ++i){
    //     std::cerr << *i << "->";
    // }
    // std::cerr<<"Size:"<<temp1.size()<<std::endl;
    
    l.PrintPath();
}





int epoints2 = 2 , rows2 = 5 , cols2 = 7;
std::string f2("/home/ojit/temp/task_g/cpp_task/src/data/test2.txt");

TEST (test2 , File_Read) {
    laby::Laby l{f2};
    EXPECT_TRUE (l.GetData());
    EXPECT_EQ ( rows2 , l.rows());
    EXPECT_EQ ( cols2 , l.cols());

}


TEST (test2 , LabyTest) {
    laby::Laby l{f2};
    EXPECT_TRUE (l.GetData());
    EXPECT_EQ (epoints2 , l.GetEntryLoc());
    EXPECT_TRUE (l.GetPath());

    std::vector<int> temp1 = l.finpath();
    
    // for (auto i = temp1.begin() ; i != temp1.end() ; ++i){
    //     std::cerr << *i << "->";
    // }
    // std::cerr<<"Size:"<<temp1.size()<<std::endl;
    l.PrintPath();

}


int epoints3 = 5 , rows3 = 5 , cols3 = 7;
std::string f3("/home/ojit/temp/task_g/cpp_task/src/data/test3.txt");

TEST (test3 , File_Read) {
    laby::Laby l{f3};
    EXPECT_TRUE (l.GetData());
    EXPECT_EQ ( rows3 , l.rows());
    EXPECT_EQ ( cols3 , l.cols());

}


TEST (test3 , LabyTest) {
    laby::Laby l{f3};
    EXPECT_TRUE (l.GetData());
    EXPECT_EQ (epoints3 , l.GetEntryLoc());
    EXPECT_TRUE (l.GetPath());

    std::vector<int> temp1 = l.finpath();
    
    // for (auto i = temp1.begin() ; i != temp1.end() ; ++i){
    //     std::cerr << *i << "->";
    // }
    // std::cerr<<"Size:"<<temp1.size()<<std::endl;
    l.PrintPath();

}

int epoints4 = 24 , rows4 = 10 , cols4 = 10;
std::string f4("/home/ojit/temp/task_g/cpp_task/src/data/test4.txt");

TEST (test4 , File_Read) {
    laby::Laby l{f4};
    EXPECT_TRUE (l.GetData());
    EXPECT_EQ ( rows4 , l.rows());
    EXPECT_EQ ( cols4 , l.cols());

}

TEST (test4 , LabyTest) {
    laby::Laby l{f4};
    EXPECT_TRUE (l.GetData());
    EXPECT_EQ (epoints4 , l.GetEntryLoc());
    EXPECT_TRUE (l.GetPath());

    std::vector<int> temp1 = l.finpath();
    
    // for (auto i = temp1.begin() ; i != temp1.end() ; ++i){
    //     std::cerr << *i << "->";
    // }
    // std::cerr<<"Size:"<<temp1.size()<<std::endl;
    l.PrintPath();

}
int epoints5 = 16 , rows5 = 4 , cols5 = 6;
std::string f5("/home/ojit/temp/task_g/cpp_task/src/data/test5.txt");

TEST (test5 , File_Read) {
    laby::Laby l{f5};
    EXPECT_TRUE (l.GetData());
    EXPECT_EQ ( rows5 , l.rows());
    EXPECT_EQ ( cols5 , l.cols());

}

TEST (test5 , LabyTest) {
    laby::Laby l{f5};
    EXPECT_TRUE (l.GetData());
    EXPECT_EQ (epoints5 , l.GetEntryLoc());
    EXPECT_TRUE (l.GetPath());

    std::vector<int> temp1 = l.finpath();
    
    // for (auto i = temp1.begin() ; i != temp1.end() ; ++i){
    //     std::cerr << *i << "->";
    // }
    // std::cerr<<"Size:"<<temp1.size()<<std::endl;
    l.PrintPath();

}

int main(int argc , char **argv){
    testing::InitGoogleTest(&argc , argv);
    return RUN_ALL_TESTS();
}

