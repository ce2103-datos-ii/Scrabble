//
// Created by ivan on 4/1/19.
//

#include "FileReader.h"

bool FileReader::searchWord(string word) {
    ifstream inFile;
    inFile.open("../Server/Words_Sp");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1);
    }
    for (string line; getline(inFile, line);) {
        if (line == word) {
            cout << "searchWord: ";
            cout << word << endl;
            return true;
        }
    } return false;
}
