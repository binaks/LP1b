#include <iostream>
#include <iomanip>
#include <vector>

using std::cout;
using std::endl;
using std::setw;
using std::setfill;

/**!
 *  Print the tables's header to the terminal (std::cout).
 *  @param fields_ Reference to the list of header fields to be printed
 */

void printHeader( const std::vector< std::string > & fields_) {
    cout << "+";

    for (auto i(0u); i < fields_.size(); ++i) {
        auto n(fields_[i].size());
        cout << setw(n+2) << setfill('-') << "";
        cout << "+";
    }

    cout << endl;

    for (auto i(0u); i < fields_.size(); ++i) {
        cout << "| " << fields_[i] << " ";
    }

    cout << "|" << endl;
    
    cout << "+";

    for (auto i(0u); i < fields_.size(); ++i) {
        auto n(fields_[i].size());
        cout << setw(n+2) << setfill('-') << "";
        cout << "+";
    }

    cout << endl;
}

int main() {
    std::vector< std::string > fieldNames = { "ITEM", "QUANTIDADE", "VALOR UNITARIO" };
    printHeader( fieldNames ); // Imprimir cabecalho da tabela.

    return EXIT_SUCCESS;
}
