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
    ifstream input("input.txt");
    // 12 bits on each line
    // want a vector with 12 vectors
    vector<vector<string>> matrix;

    for (string line; getline(input, line);)
    {
        vector<string> row(12);
        for (int col; col < line.length(); col++)
        {
            row.push_back(string(1, line[col]));
            // cout << col << endl;
            // array[row].push_back(col);
            // cout << line[col] << endl;
            // array[col].push_back(line[col]);
            //     array[col][row] = line[col];
            //     cout << line[col] << endl;
        }
        // cout << line << endl;
        matrix.push_back(row);
    }

    // gamma is now mode(array[0]), mode(array[1]), ..., mode(array[11])

    return gammaRate * epsilonRate;
}