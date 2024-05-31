#include "utils.h"

// Example utility function
void print_vector(const std::vector<int>& data) {
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
