#include <cstddef>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>

struct LogReport {
    std::size_t error_count = 0;
    std::size_t line_count  = 0;
};

int main() {
    std::ifstream file("test.log");
    if (!file) {
        std::cerr << "Could not open test.log\n";
        return 1;
    }

    // Heap-allocated, owned by unique_ptr: no new/delete
    auto report = std::make_unique<LogReport>();

    constexpr std::string_view needle = "ERROR";
    std::string line;

    while (std::getline(file, line)) {
        ++report->line_count;

        std::string_view view{line};   // no copy, no allocation
        std::size_t pos = view.find(needle);
        while (pos != std::string_view::npos) {
            ++report->error_count;
            pos = view.find(needle, pos + needle.size());
        }
    }

    std::cout << "Lines read:   " << report->line_count  << '\n'
              << "ERROR count:  " << report->error_count << '\n';
}
