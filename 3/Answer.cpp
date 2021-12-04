#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    // most common bit from each index of all lines
    int gammaRate;
    // least common bit from each index of all rows
    int epsilonRate;
    // lineCount is the number of lines in the file
    int lineCount;
    ifstream input("input.txt");

    vector<int> countOnes(12, 0);
    for (string line; getline(input, line);)
    {
        lineCount += 1;
        for (int col = 0; col < 12; col++)
        {
            if (line[col] == '1')
            {
                countOnes[col] += 1;
            }
        }
    }
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
    std::cout << "gammaRate x epsilonRate" << gammaRate * epsilonRate << std::endl;

    return 0;
}