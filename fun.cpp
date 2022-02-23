#include "header.h"





void fill_peaks(const std::vector<int>& numbers, std::vector<int>& peaks_indx)
{
    for(size_t i = 1; i < numbers.size() - 1; ++i)
    {
        if(numbers[i-1] < numbers[i] && numbers[i] > numbers[i+1])
        {
            peaks_indx.push_back(i);
        }
    }
}

int solution(std::vector<int>& numbers)
{
    if(numbers.size() < 3)
        return 0;

    std::vector<int> peaks_indx;
    fill_peaks(numbers, peaks_indx);

    if(peaks_indx.empty())
        return 0;

    unsigned long long i = peaks_indx.size();

    while(i * i > 1)
    {
        if(numbers.size() % i)
        {
            --i;
            continue;
        }

        int valid_blocks = 0;
        int elements = numbers.size() / i;
        for(size_t l = 0; l < peaks_indx.size(); ++l) // fix this - there might be 2 peaks in 1st block but no peaks in 2nd
        {
            if(peaks_indx[l] < elements * (valid_blocks + 1) && peaks_indx[l]  >= elements * valid_blocks)
                ++valid_blocks;
        }

        if(valid_blocks == i)
            return i;

        --i;
    }

    return 1;
}

