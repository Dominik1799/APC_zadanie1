#include <iostream>
#include <fstream>
#include <string>


bool isPalindrome(std::string& prefix){
    int length = prefix.length();
    if (prefix.length() == 0)
        return false;
    bool isPalindrome = true;
    for (int i = 0; i < length; i++){
        if (prefix[i] != prefix[length-i-1]){
            isPalindrome = false;
            break;
        }
    }
    return isPalindrome;
}


std::string processLine(std::string& line){
    int lineLength = line.length();
    if (lineLength == 0){
        return "bruh\n";
    }
    std::string buffer;
    int palindromeLength = lineLength;
    for (int i = lineLength; i >= 1; i--){
        buffer = line.substr(0,i);
        if (isPalindrome(buffer)){
            break;
        }
        palindromeLength--;
    }
    if (palindromeLength == lineLength)
        return "YES\n";
    else
        return std::to_string(palindromeLength).append("\n");
}


int main(int argc, char* argv[]) {
    if (argc != 3){
        std::cout << "Invalid input (X)\n";
        return 1;
    }
    std::ifstream inputFile(argv[1]);
    std::ofstream  outputFile(argv[2]);
    std::string line;
    while (std::getline(inputFile,line)){
        std::cout << processLine(line);
    }

    return 0;
}
