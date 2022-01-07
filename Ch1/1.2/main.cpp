#include <iostream>
#include <algorithm>
#include <string>

std::string translate(bool answer) {
    if(answer) {
        return "true";
    }
    return "false";
}

bool permutation(std::string input1, std::string input2) {
    // if both strings are of different sizes, they cannot be permutations.
    if(input1.size() != input2.size()) {
        return false;
    }

    // bypass case sensitivity.
    std::string lowerInput1 = input1;
    std::transform(lowerInput1.begin(), lowerInput1.end(), lowerInput1.begin(), ::tolower);
    std::string lowerInput2 = input2;
    std::transform(lowerInput2.begin(), lowerInput2.end(), lowerInput2.begin(), ::tolower);

    int ascii1 = 0;
    int ascii2 = 0;

    for(int i = lowerInput1.size() - 1; i > -1; --i) {
        ascii1 += int(lowerInput1[i]);
        ascii2 += int(lowerInput2[i]);
    }

    if(ascii1 != ascii2) {
        return false;
    }

    return true;
}

int main()
{
    std::string input1;
    std::string input2;

    std::cout << "input two strings to check if one\nis a permutation of the other.\n";
    std::cin >> input1 >> input2;
    std::cin.ignore();
    std::cout << translate(permutation(input1, input2));

    return 0;
}