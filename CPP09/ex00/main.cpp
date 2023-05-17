#include <iostream>
#include <fstream>
#include <string>
#include "BitcoinExchange.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: btc input_file" << endl;
        return 1;
    }

    string input_file = argv[1];
    BitcoinExchange bitcoin_exchange("data.csv");
    bitcoin_exchange.readData();
    bitcoin_exchange.getInput(input_file);
    return 0;
}