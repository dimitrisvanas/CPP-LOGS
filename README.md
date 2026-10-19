# cpp-logs

Small C++20 program that reads `test.log` line by line and counts occurrences of "ERROR".

Demonstrates `std::ifstream`/`std::getline`, `std::string_view` for allocation-free searching, and `std::unique_ptr` for RAII.

## Build and run

    g++ -std=c++20 -Wall -Wextra main.cpp -o app
    ./app
