#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main () {
    vector <string> num_;
    string line;    

    ifstream ifs;
    ofstream ofs;

    ifs.open("numbers");

    while ( getline(ifs, line) ) {
        num_.push_back(line);
    }

    ifs.close();

    ofs.open("inverted");

    for (auto i(num_.size()); i > 0; --i) {
        ofs << num_[i - 1] << endl;
    }

    ofs.close();

    return 0;
}
