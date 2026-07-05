#include <iostream>
#include <fstream>

void practice(){
    int lessonNo = 1;
    std :: string line;
    while(lessonNo <= 15){
        std :: string fileName = "lesson_" + std :: to_string(lessonNo) + ".txt";
        std :: ifstream lesson(fileName);
        while (lesson.eof() == 0){
            getline(lesson,line);
            std :: cout << line << std :: endl;   
        }
        std :: cout << "\nEnter Enter To Move To Next Lesson";
        getchar();
        system("clear");
        lessonNo++;
    }
}