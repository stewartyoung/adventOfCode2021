#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// main
// getCountOfBits
// find most common bit in indices
// find least common bit in indices

// bits structure that houses multiple returns from getCountOfBits
struct Bits
{
    vector<int> countOnes;
    int lineCount;
};

// getCountOfBits returns counts of 1 in bits file
// Bits getCountOfOneBits(string inputFile, int colsToGetCountFor);
Bits getCountOfOneBits(string inputFile, int *colsToGetCountFor)
{
    // lineCount is the number of lines in the file
    int lineCount;
    ifstream input(inputFile);

    vector<int> countOnes(colsToGetCountFor[1], 0);
    for (string line; getline(input, line);)
    {
        lineCount += 1;
        for (int col = colsToGetCountFor[0]; col < colsToGetCountFor[1]; col++)
        {
            if (line[col] == '1')
            {
                countOnes[col] += 1;
            }
        }
    }

    Bits bits = {countOnes, lineCount};

    return bits;
}

int main()
{
    // most common bit from each index of all lines
    int gammaRate;
    // least common bit from each index of all rows
    int epsilonRate;
    int colsToGetCountFor[2] = {0, 12};
    Bits bits = getCountOfOneBits("input.txt", colsToGetCountFor);
    vector<int> countOnes = bits.countOnes;
    int lineCount = bits.lineCount;
    std::cout << "lineCount: " << lineCount << std::endl;
    string gammaString(12, '0');
    string epsilonString(12, '1');

    for (int num = 0; num < countOnes.size(); num++)
    {
        if (countOnes[num] > lineCount / 2)
        {
            // most common bit is 1
            gammaString[num] = '1';
            // least common bit is 0
            epsilonString[num] = '0';
        }
    }

    gammaRate = stoi(gammaString, nullptr, 2);
    epsilonRate = stoi(epsilonString, nullptr, 2);
    std::cout << "gammaRate: " << gammaRate << std::endl;
    std::cout << "epsilonRate: " << epsilonRate << std::endl;
    std::cout << "gammaRate x epsilonRate: " << gammaRate * epsilonRate << std::endl;

    return 0;
}