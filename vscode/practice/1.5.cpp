#include <iostream>
#include <string>
#include <cmath>

bool oneEditReplase(const std::string& s1, const std::string& s2) {
    bool foundDifference = false;
    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] != s2[i]) {
            if(foundDifference) {
                return false;
            }
            foundDifference = true;
        }
    }
    return true;
}

bool oneEditInsert(const std::string& s1, const std::string& s2) {
    int index1 = 0, index2 = 0;
    while (index1 < s1.length() && index2 < s2.length()) {
        if(s1[index1] != s2[index2]) {
            if(index1 != index2) {
                return false;
            }
            index2++;
        } else {
            index1++;
            index2++;
        }
    }
    return true;
}

bool oneEditAway(const std::string& first, const std::string& second) {
    if(std::abs(static_cast<int>(first.length()) - static_cast<int>(second.length())) > 1) {
        return false;
    }
    if (first.length() == second.length()) {
        return oneEditReplase(first, second);
    }

    if(first.length() +1 == second.length()) {
        return oneEditInsert(first, second);
    } else if(first.length() == second.length() + 1) {
        return oneEditInsert(second, first);
    }
    return false;
}
int main() {
   std::string first, second;
    std::cout << "输入第一个字符串: ";
    std::cin >> first;
    std::cout << "输入第二个字符串: ";
    std::cin >> second;

    if (oneEditAway(first, second)) {
        std::cout << "两个字符串只需要一次编辑或零次编辑即可相同" << std::endl;
    } else {
        std::cout << "两个字符串需要超过一次编辑才相同" << std::endl;
    }

    return 0;
}