#include <iostream>
#include <unordered_map>
#include <string>

bool canPermutePalindrome(const std::string& s){
    std::unordered_map<char, int> charCount;

    for(char c : s) {
        if(c != ' ') {
            charCount[c]++;
        }
    }
    int oddCount = 0;
    for (auto& pair : charCount) {
        if(pair.second % 2 == 1) {
            oddCount++;
        }
        if(oddCount > 1) {
            return false;
        }
    }
    return true;
}
int main() {
    std::string str;
    std::cout << "enter a strings";
    std::getline(std::cin, str);

    if(canPermutePalindrome(str)){
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
    return 0;
}