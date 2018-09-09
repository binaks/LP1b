#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int getInteger(string msg_) {

    string num;
    int value;

    while (true) {
        cout << msg_;
        getline (cin, num);

        istringstream iss_ (num);
        
        iss_ >> value;

        if (!iss_.fail()) {
            return value;
        }
    }

}

int main () {
    auto val = getInteger("Forneca um inteiro: ");

    cout << val << endl;

    return 0;
}
