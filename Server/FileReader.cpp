//
// Created by ivan on 4/1/19.
//

#include "FileReader.h"

bool FileReader::searchWord(string word) {
    ifstream inFile;
    inFile.open("/home/ivan/CLionProjects/untitled5/Words");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1);
    }
    for (string line; getline(inFile, line);) {
        if (line == word) {
            cout << word << endl;
            return true;
        }
    } return false;
}
