#include <string>
#include <vector>
#include <sstream>

namespace laby {


    class Node {

        public:
    
            Node ( int _x , int _y );        
            int x() const;
            int y() const;

            bool operator == (const Node& n);

        private:
    
            int x_ = -1;
            int y_ = -1;

    };
    

    class Laby {

        public:

            Laby(std::string filename);
            int rows() const;
            int cols() const;
            std::vector<int> finpath() const;

            bool GetData();

            int GetEntryLoc ();

            std::vector<int> GetNeighbors(int child , int par);
            bool GetPath();

            void PrintPath();

        private:
            std::string fin_;
            std::string fout_;
            int rows_ = 0 ;
            int cols_ = 0;
            std::vector<int> data_;
            std::vector<std::vector<int>> paths_;
            std::vector<int> final_path_;
            std::stringstream s_out;
    };   
}