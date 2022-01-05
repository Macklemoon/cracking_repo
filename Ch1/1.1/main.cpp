#include <iostream>
#include <algorithm>
#include <string>

bool isUnique(std::string input) {
    std::string lowerInput = input;
    std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

    for(int i = lowerInput.size() - 1; i > -1; --i) {
        char curr = lowerInput[i];
        
        for(int j = i - 1; j > -1; --j) {
            if(curr == lowerInput[j]) {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    std::string userInput;

    std::cout << "input a string to check for uniqueness.\n";
    std::cin >> userInput;
    std::cin.ignore();
    std::cout << '\n' << isUnique(userInput);

    return 0;
}