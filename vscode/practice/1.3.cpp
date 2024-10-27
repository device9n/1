#include <iostream>
#include <string>

void replaceSpaces(char str[], int trueLength) {
    
    int spaceCount = 0;

    for(int i = 0; i < trueLength; i++){
        if(str[i] == ' '){
            spaceCount++;
        }
    }

    int newLength = trueLength + spaceCount * 2;

    int index = newLength - 1;

    for(int i = trueLength - 1; i >= 0; i--) {
        if(str[i] == ' '){
            str[index] = '0';
            str[index - 1] = '2';
            str[index - 2] = '%';
            index -= 3;
        } else {
            str[index] = str[i];
            index--;
        }
    }
}
int main(){
    char str[100]  = "hello  adsadas  adsd  asd";

    std::cout << sizeof(str) << std::endl;

    int trueLength = 27;

    replaceSpaces(str, trueLength);

    std::cout << trueLength << std::endl;

    std::cout << sizeof(str) << std::endl;

    return 0;
}