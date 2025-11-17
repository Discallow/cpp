#include "PMerge.hpp"



int main(int ac, char **av) {
/*     int raw[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    int raw[] = {4, 2, 3, 1};
    std::vector<int> v(raw, raw + sizeof(raw) / sizeof(raw[0])); */



    try {
        if (ac != 2)
            throw std::runtime_error("Invalid number of arguments");
        PMergeMe fj(av[1]);
    }
    catch (std::runtime_error &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << "Comparisons: " << comparisons << std::endl;
/*     std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    std::vector<int> sorted = fordJohnson(v, 1);

    std::cout << "After:  ";
    for (size_t i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i] << " ";
    std::cout << std::endl; */

    return 0;
}
