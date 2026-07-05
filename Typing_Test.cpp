#include <iostream>
#include <ctime>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
#include <termios.h>
#include <fstream>
#include <string.h>

void front_screen();
void practice();
void start();
void display_box();
char getch(void);
void logic_box();
void *display_time(void *arr);

std ::string worldBank;
int Time = 0, words = 0, letter = 0, length = 0, Test = 0;

int main()
{
    char input;
    while (1)
    {
        front_screen();
        input = getch();
        if (input == '1')
        {
            Test = 1;
            display_box();
            pthread_t ptid;
            // creating a new thread
            pthread_create(&ptid, NULL, display_time, NULL);
            logic_box();
            pthread_join(ptid, NULL);
            std ::cout << "\nEnter Enter To Continue.";
            getchar();
        }
        else if (input == '2')
        {
            practice();
        }
        else
        {
            break;
        }
        system("clear");
    }
    return 0;
}

void front_screen()
{
    std ::cout << std ::endl;
    for (int i = 0; i <= 20; i++)
    {
        std ::cout << "\t\t\t\t\t";
        for (int j = 0; j <= 35; j++)
        {
            if (i == 0 || i == 20)
            {
                std ::cout << "-";
            }
            else if (j == 0 || j == 35)
            {
                if (i == 7 || i == 6)
                {
                    continue;
                }
                std ::cout << ":";
            }
            else if (i == 3 && j == 25)
            {
                std ::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b"
                           << "TYPING ACHARYA";
            }
            else if (i == 6 && j == 1)
            {
                std ::cout << ":   Press 1 For Typing Test        :";
            }
            else if (i == 7 && j == 1)
            {
                std ::cout << ":   Press 2 For Typing Lecture     :";
            }
            else
            {
                std ::cout << " ";
            }
        }
        std ::cout << "\n";
    }
}
void practice()
{
    int lessonNo = 1;
    std ::string line;
    while (lessonNo <= 15)
    {
        system("clear");
        std ::string fileName = "lesson_" + std ::to_string(lessonNo) + ".txt";
        std ::ifstream lesson(fileName);
        std ::cout << "Lesson " << lessonNo << std ::endl;
        while (lesson.eof() == 0)
        {
            getline(lesson, line);
            std ::cout << line << std ::endl;
        }
        std ::cout << "\nEnter Enter To Move To Next Lesson";
        getchar();

        lessonNo++;
    }
}
void start()
{
    int lineNo = 0, randomLine = 0;
    srand(time(NULL));
    int limit = length + 625;
    while (length < limit)
    {
        std ::ifstream in("WordBank.txt");
        std ::string line;
        randomLine = rand() % 240;
        lineNo = 0;
        while (in.eof() == 0)
        {
            getline(in, line);
            if (lineNo == randomLine)
            {
                worldBank += line + " ";
                length += line.length() + 1;
                break;
            }
            lineNo++;
        }
        in.close();
    }
}
void display_box()
{
    start();
    system("clear");
    int posi = 0, posj = 0;
    while (posj < 94)
    {
        std ::cout << "-";
        posj++;
    }
    std ::cout << std ::endl;
    while (posi < length)
    {
        posj = 0;
        std ::cout << ": ";
        while (posj < 90)
        {
            if (posi >= length)
            {
                std ::cout << " ";
                posj++;
                continue;
            }
            std ::cout << worldBank[posi];
            posi++;
            posj++;
        }
        std ::cout << " :" << std ::endl;
    }
    posj = 0;
    while (posj < 94)
    {
        std ::cout << "-";
        posj++;
    }
    std ::cout << std ::endl;
}
char getch(void)
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}
void logic_box()
{
    int posx = 0, posy = 0;
    char input;
    std ::cout << "Start Typing\n";
    while (Test)
    {
        input = getch();
        if (input == worldBank[posx])
        {
            std ::cout << input;
            if (posy == 90)
            {
                posy = 0;
                std ::cout << "\n";
            }
            if (input == ' ')
                words++;
            else
                letter++;
            posy++;
            posx++;
            if (posx == length)
            {
                display_box();
            }
        }
    }
}
void *display_time(void *arr)
{
    sleep(60);
    Test = 0;
    std ::cout << "\nWords : " << words << " Letter : " << letter << std ::endl;
    return NULL;
}
