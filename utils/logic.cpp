#include<iostream>
#include<ctime>
#include<pthread.h>
#include<cstdlib>
#include<unistd.h>
#include<termios.h>
#include<fstream> 
#include<string.h>

std :: string worldBank;
int Time = 0, words = 0, letter = 0;
void start(){
    int lineNo = 0;
    std :: ifstream in("WordBank.txt");
    std :: string line;
    while(1){
        getline(in, line);
        worldBank += line;
    }
}
char getch(void){
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}
void logic_box(){
    int posx = 0, posy=0;
    int length = worldBank.length();
    char input;
    std :: cout << "Start Typing\n";
    while (1){
        input = getch();
        if(input == worldBank[posx]){
            std :: cout << input;
            if(posy == 90){
                posy = 0;
                std :: cout << "\n";
            }
            if(input == ' ') words++;
            else letter++;
            posy++;
            posx++; 
        }
    }
}
void *display_time(void* arr){
    sleep(60);
    std :: cout << "\nWords : " << words << " Letter : " << letter << std :: endl;
    exit(0);
    return NULL;
}
void display_box(){
    int posi = 0, posj = 0;
    int length = worldBank.length();
    while (posj < 94){
        std :: cout << "-";
        posj++;
    }
    std :: cout << std :: endl;
    while (posi < length){
        posj = 0;
         std :: cout << ": ";
        while (posj < 90){
            if(posi >= length){
                std :: cout << " ";
                posj++;
                continue;
            }
            std :: cout << worldBank[posi];
            posi++;
            posj++;
        }
        std :: cout << " :" << std :: endl;
    }
    posj = 0;
    while (posj < 94){
        std :: cout << "-";
        posj++;
    }
    std :: cout << std :: endl;
}
int main(){
    start();
    display_box();
    pthread_t ptid;
    //creating a new thread
    pthread_create(&ptid,NULL,display_time,NULL);
    logic_box();
    pthread_join(ptid, NULL);


    return 0;
}