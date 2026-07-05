#include <iostream>
#include <string>

void front_screen(std::string userName = "Guest"){
    std::cout << std::endl;
    for(int i = 0; i <= 20; i++){
        std::cout << "\t\t\t\t\t";
        for(int j = 0; j <= 35; j++){
            if(i == 0 || i == 20){
                std::cout << "-";
            }
            else if(j == 0 || j == 35){
                if(i == 7 || i == 6){
                    continue;
                }
                std::cout << ":";
            }
            else if(i == 3 && j == 18){
                std::cout << "TYPING ACHARYA";
                j += 12; // skip the width taken by the title
            }
            else if(i == 6 && j == 1){
                std::cout << ":   Press 1 For Typing Test        :";
                j = 34;
            }
            else if(i == 7 && j == 1){
                std::cout << ":   Press 2 For Typing Practice    :";
                j = 34;
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

int main(){
    front_screen("Yuvjeet");
    return 0;
}