#include <iostream>
#include <windows.h>
#include <conio.h>
#include<fstream>

using namespace std;
int global_height;
int global_weight;
void ReadFromFile(){
    fstream file("F:\CodeBlocks\maze\input.txt");
    if (!file.is_open()) {
        cout << "file can`t opened";
        return;
    }
    int height;
    int weight;
    file >> height;
    global_height = height;
    file >> weight;
    global_weight = weight;
    file.close();
}
void printMsg(char* msg) {
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t"<< msg <<"\n\n\n\n\n\n\n\n\n\n\n";
    system("pause");
}
void repeatGame() {
    char answer = 'n';
    cout << "repeat the game (y/n)?";
    cin >> answer;
    if (answer == 'n') {
        Sleep(1000);
        exit(0);
    }
}
void gameOverManagement()
{
    printMsg("Game Over!");
    repeatGame();
}
void gameVictoryManagement()
{
    printMsg("Victory!");
    repeatGame();
}

int dataManagement(int management, int stopGame)
{
if(management == 1)
{
  gameOverManagement();
  stopGame = 1;
}
if(management == 3)
{
  gameVictoryManagement();
  stopGame = 1;
}
management = 2;
return management,stopGame;
}
int main()
{
     cout<< global_height<<endl<<global_weight;
     return 0;}
    /*int mas[24][24] = { {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
                        {1,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0,1,},
                        {1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1,},
                        {1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,},
                        {1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,},
                        {1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,},
                        {1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,},
                        {1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,},
                        {1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,},
                        {1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,},
                        {1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,},
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,},
                        {1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,},
                        {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,},
                        {1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,},
                        {1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,},
                        {1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,},
                        {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,},
                        {1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,},
                        {1,0,1,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,1,},
                        {1,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,},
                        {1,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,},
                        {1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,} };
unsigned short keysArrow; int s1 = 0;
int s2 = 1;
int stopGame(0);
mas[s1][s2] = 2;
do {
  system("cls");
  for (int i = 0; i < 24; i++)
  {
   for (int j = 0; j < 20; j++)
   {
    if (mas[i][j] == 1)
    {

     cout << static_cast<char>(176);

     cout << static_cast<char>(176);
    }
    if (mas[i][j] == 0 || mas[i][j] == 3)
    {
      cout << "  ";
    }
    if (mas[i][j] == 2)
    {
      cout << static_cast<char>(182);
      cout << static_cast<char>(182);
    }
   }
   cout << endl;
  }
  keysArrow = getch();
  keysArrow = getch();   if(keysArrow == 0)
  keysArrow = getch();
  if(keysArrow == 72 || keysArrow == 150 || keysArrow == 230)
  {

   mas[s1][s2] = 1;
   s1--;
   dataManagement(mas[s1][s2],stopGame);
   mas[s1][s2] = 2;
  }
  if(keysArrow == 80 || keysArrow == 155 || keysArrow == 235)
  {

   mas[s1][s2] = 1;
   s1++;
   dataManagement(mas[s1][s2],stopGame);
   mas[s1][s2] = 2;
  }
  if(keysArrow == 77 || keysArrow == 130 || keysArrow == 262)
  {

   mas[s1][s2] = 1;
   s2++;
   dataManagement(mas[s1][s2],stopGame);
   mas[s1][s2] = 2;
  }
  if(keysArrow == 75 || keysArrow == 148 || keysArrow == 235)
  {

   mas[s1][s2] = 1;
   s2--;
   dataManagement(mas[s1][s2],stopGame);
   mas[s1][s2] = 2;
  }
} while(true);

    getch();
    return 0;
}
*/
