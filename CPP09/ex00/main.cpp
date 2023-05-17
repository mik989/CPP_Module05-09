#include <iostream>
#include <fstream>
#include <string>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: btc input_file" << std::endl;
        return 1;
    }

    std::string input_file = argv[1];
    BitcoinExchange bitcoin_exchange("data.csv");
    bitcoin_exchange.readData();
    bitcoin_exchange.getInput(input_file);
    return 0;
}