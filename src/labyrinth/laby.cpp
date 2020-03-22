#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "laby.h"
#include <algorithm>
#include <iomanip>
/*##############  NODE  ############################*/

laby::Node::Node(int _x , int _y) : x_{_x} , y_{_y}{};

int laby::Node::x () const {return x_;}
int laby::Node::y () const {return y_;}
std::vector<int> laby::Laby::finpath() const {return final_path_;}

bool laby::Node:: operator == (const Node& n){
    return (x_ == n.x() && y_ == n.y());
}

/*#################################################*/


/*##############  LABY  ############################*/

laby::Laby::Laby (std::string _f) : fin_{_f}{
    std::size_t pos = fin_.find(".txt");
    fout_ = fin_.substr(0 , pos);
    fout_.append("result.txt");
}

int laby::Laby::rows() const {return rows_;}
int laby::Laby::cols() const {return cols_;}

bool laby::Laby::GetData () {
    std::string line;
    std::ifstream myfile (fin_);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            for (auto i = line.begin() ; i != line.end() ; ++i) {
                if (*i == '#') {
                    data_.push_back(0);
                    s_out << '#';
                }
                else {
                    data_.push_back(1);
                    s_out << '.';
                }
            }

            rows_++;
            s_out << '\n';
        }
        cols_ = line.size();
        myfile.close();
        return true;
    }

    else std::cerr << "Unable to open file"; 

    return false;
}

int laby::Laby::GetEntryLoc () 
{
    int entry_pts = 0; 
    //Check for entry points in zeroth and last row
    for (int i = 0 ; i< cols_ ; ++i){
        //Check for entry points (use i) & ((rows_-1) * cols_ + i)
        if (data_.at(i)){
            paths_.push_back(std::vector<int> {i});
            entry_pts++;
        }
        
        if ( data_.at((rows_- 1) * cols_ + i) ){
            paths_.push_back(std::vector<int> {(rows_- 1) * cols_ + i });
            entry_pts++;
        }
    }

    //Check for entry points in first and last cols
    for (int j = 1 ; j < rows_ - 1 ; ++j){
        
        //Check for entry points (use j*cols) & (j*cols_ + cols_ - 1) 
        if (data_.at(j*cols_)){
            paths_.push_back(std::vector<int> {j*cols_});
            entry_pts++;
        }
        
        if ( data_.at(j*cols_ + cols_ - 1) ){
            paths_.push_back(std::vector<int> {j*cols_ + cols_ - 1 });
            entry_pts++;
        }
    }
    
    // std::vector<int> ce; 
    // for (auto i = paths_.begin() ; i != paths_.end() ; ++i ){
    //     ce = *i;
    //     std::cout << ce [0]/cols_ <<","<< ce[0] - (ce [0]/cols_)*cols_ << " ";
    // }
    // std::cout<<std::endl;

    return entry_pts;
}

std::vector<int> laby::Laby::GetNeighbors (int child , int par)
{
    int n1 = child + 1;
    int n2 = child - 1;
    int n3 = child + cols_;
    int n4 = child - cols_;
    std::vector<int> nhb;
    if ( n1%cols_ && n1 != par && data_[n1] ){
        nhb.push_back(n1);
    }

    if ( n2%cols_!=cols_-1 && n2 != par && data_[n2] ){
        nhb.push_back(n2);
    }

    if ( n3 < rows_*cols_ && n3 != par && data_[n3] ){
        nhb.push_back(n3);
    }

    if ( n4 >= 0 && n4 != par && data_[n4] ){
        nhb.push_back(n4);
    }
    return nhb;
}

bool laby::Laby::GetPath() {
    // auto i = paths_.begin();
    std::vector<std::vector<int>> paths_update;

    std::vector<int> path_ref;
    std::vector<int> nhb_ref;
    std::vector<int> temp;
    
    while (paths_.size())
    {
    
        for (auto i = paths_.begin(); i!= paths_.end() ; ++i)
        {
            path_ref = *i;
            
            if (nhb_ref.size() > 1)
                nhb_ref = GetNeighbors(path_ref.back() , path_ref.end()[-2]);
            else
                nhb_ref = GetNeighbors(path_ref.back() , -1);
                
            //Neighbor Vector Empty
            if (!nhb_ref.size())
            {
                if (path_ref.size() > final_path_.size())
                {
                    final_path_ = path_ref;
                }

                // paths_.erase(i);

            }
            
            //Neighbor Vector Contains One or More Elements
            else{
                for (auto j = nhb_ref.begin() ; j!= nhb_ref.end() ; ++j){
                    
                    if(std::find(path_ref.begin(), path_ref.end(), *j) != path_ref.end()) {
                        if (path_ref.size() > final_path_.size())
                        {
                            final_path_ = path_ref;
                        }
                    } 
                    else {

                        temp = path_ref;
                        temp.push_back(*j);
                        paths_update.push_back(temp);
                    }
                }
            }
        }
        paths_ = paths_update;
        paths_update.clear();
    }
    return true;
}

void laby::Laby::PrintPath() {

    std::ofstream fo_ (fout_);
    std::string op = s_out.str();
    std::vector <int> temp_fp ;
    
    std::cerr <<"----------TEST START----------- "<<std::endl;
    std::cerr << op <<std::endl;

    for (auto i = final_path_.begin() ; i != final_path_.end() ; ++i){
        temp_fp.push_back(*i);
    }

    int f = 1;

    std::cerr << temp_fp.size()<<std::endl;
    
    // fo_ <<  << "\n";
    fo_ << std::left << temp_fp.size() <<"\n"<<std::setw(3);

    std::cerr<<std::left<<std::setw(3);

    for (int i = 0 ; i < rows_ ; ++i)
    {
        for (int j = 0 ; j < cols_ ; ++j)
        {
            f=1;
            for (uint k = 0 ; k <temp_fp.size() ; ++k){
                if (temp_fp [k] == i*(cols_) + j)
                {
                    std::cerr <<std::left << k << std::setw(3);
                    fo_ << std::left << k << std::setw(3);
                    f=0;
                    break;
                }            
            }

            if (f){
                std::cerr <<std::left<< op[i*(cols_+1) + j]<< std::setw(3);
                fo_<<std::left<< op[i*(cols_+1) + j]<< std::setw(3);
            }
        }
        std::cerr <<std::endl;
        fo_ << std::left << "\n" <<std::setw(3);
    }

    std::cerr <<"----------TEST OVER----------- "<<std::endl;
    fo_.close();

}



/*#################################################*/

