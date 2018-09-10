#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

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
    cout << "| ";

    for (auto i(0u); i < ints_.size(); ++i) {
        cout << setw(header_[1].size()) << setfill (' ') << ints_[i];
        cout << " |" << endl;
        
        if (i != (ints_.size() - 1)) {
            cout << "| ";
        }

        cout << endl;
    }
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

    while ( getline (ifs_, line) ) {
        ints.push_back(line);
    }
    
    printTable (fieldNames, ints);

    ifs_.close();

    return 0;
}
