#include <iostream>
#include <string>
#include <unordered_map>

bool areAnagrams(const std::string& str1, const std::string& str2) {
    if(str1.length() != str2.length()) {
        return false;
    }

    std::unordered_map<char, int> charCount;

    for (char ch : str1){
        charCount[ch]++;
    }

    for(char ch : str2) {
        charCount[ch]--;
        
        if(charCount[ch] < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str1, str2;
    std::cout << "enter first" << std::endl;
    std::cin >> str1;
    std::cout << "enter first" << std::endl;
    std::cin >> str2;

    if(areAnagrams(str1, str2)) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
}