#include <iostream>
#include <vector>

std::vector<long> output;

void runTest()
{
    // Read in size
    int size;
    std::cin >> size;
    // Read in array, while same sign, take maximum;

    long total = 0;
    long curVal = 0;
    std::cin >> curVal;
    bool neg = (curVal < 0);

    for (int i = 1; i < size; ++i)
    {
        long val;
        std::cin >> val;

        // Check if different si gn
        if (neg != (val < 0))
        {
            neg = !neg;
            // Add to total
    
            total += curVal;
            curVal = val;
        }
        else
            curVal = std::max(val, curVal);
    }
    total += curVal;
    output.push_back(total);
}

int main()
{
    // Read in number of tests
    int n;
    std::cin >> n;

    // For the number of tests, run each one
    for (int i = 0; i < n; ++i)
        runTest();

    for(long v : output)
        std::cout << v << '\n';

}