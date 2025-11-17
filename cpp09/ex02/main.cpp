#include "PMerge.hpp"



long getElapsedTime(const timeval& start, const timeval& end)
{
    return ((end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec)); // microseconds
}

int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return (sum);
}

int main(int ac, char **av) {
    try {
        if (ac != 2)
            throw std::runtime_error("Invalid number of arguments");

        timeval start, end;
        double elapsed_us;

        // ---------------- VECTOR ----------------
        PMergeMe<std::vector<int> > fj_vec;
        fj_vec.parseInput(av[1]);
        fj_vec.printBefore();

        gettimeofday(&start, NULL);
        fj_vec.setup();
        gettimeofday(&end, NULL);

        elapsed_us = getElapsedTime(start, end);

        fj_vec.printAfter();
        std::cout << "Time to process " << YELLOW << fj_vec.getNumberOfElements() << RESET
                    << " elements with " << YELLOW << "std::vector" << RESET << ": " 
                    << YELLOW << std::fixed << elapsed_us << " us" << RESET << std::endl;
        comparisons = 0;
        // ---------------- DEQUE ----------------
        PMergeMe<std::deque<int> > fj_deque;
        fj_deque.parseInput(av[1]);

        gettimeofday(&start, NULL);
        fj_deque.setup();
        gettimeofday(&end, NULL);

        elapsed_us = getElapsedTime(start, end);
        std::cout << "Time to process "<< YELLOW << fj_deque.getNumberOfElements() << RESET
                    << " elements with " << YELLOW << "std::deque" << RESET << ": " 
                    << YELLOW << std::fixed << elapsed_us << " us" << RESET << std::endl;
        std::cout << "Maximum number of comparisons allowed for " << fj_deque.getNumberOfElements() << " :" << F(fj_deque.getNumberOfElements()) << std::endl;
        std::cout << "Comparisons made: " << comparisons << std::endl;
        
    } 
    catch (std::runtime_error &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

return 0;
}
