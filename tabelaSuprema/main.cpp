#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

void printHeader( const std::vector< std::string > & fields_) {
    ofstream ofs_;

    ofs_.open("f3");

    cout << "+";
    ofs_ << "+";

    for (auto i(0u); i < fields_.size(); ++i) {
        auto n(fields_[i].size());
        cout << setw(n+2) << setfill('-') << "";
        ofs_ << setw(n+2) << setfill('-') << "";
        cout << "+";
        ofs_ << "+";
    }

    cout << endl;
    ofs_ << endl;

    for (auto i(0u); i < fields_.size(); ++i) {
        cout << "| " << fields_[i] << " ";
        ofs_ << "| " << fields_[i] << " ";
    }

    cout << "|" << endl;
    ofs_ << "|" << endl;
    
    cout << "+";
    ofs_ << "+";

    for (auto i(0u); i < fields_.size(); ++i) {
        auto n(fields_[i].size());
        cout << setw(n+2) << setfill('-') << "";
        ofs_ << setw(n+2) << setfill('-') << "";
        cout << "+";
        ofs_ << "+";
    }

    cout << endl;
    ofs_ << endl;

    ofs_.close();
}

void printTable( const std::vector< std::string > & header_, const std::vector< std::string > & ints_) {
    std::ostringstream oss_;

    for (auto i(0u); i < ints_.size(); ++i) {
        oss_ << "| ";
        oss_ << setw(header_[i].size()) << setfill (' ') << ints_[i];
        oss_ << " ";
        
        if (i % header_.size() == 0 && i != 0 ) {
            oss_ << "|";
            oss_ << '\n';
        }
    }

    oss_ << endl;
    cout << oss_.str();
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        cout << "Entrada invalida. Entre com dois nomes de arquivos." << endl;
        return 1;
    }

    vector<string> fieldNames;
    vector<string> ints;
    string line;
    ifstream ifs_;

    ifs_.open(argv[1]);

    while ( getline (ifs_, line) ) {
        fieldNames.push_back(line);
    }

    ifs_.close();

    printHeader (fieldNames);

    ifs_.open(argv[2]);

    while ( getline (ifs_, line, ' ') ) {
        ints.push_back(line);
    }
    
    printTable (fieldNames, ints);

    ifs_.close();

    return 0;
}
