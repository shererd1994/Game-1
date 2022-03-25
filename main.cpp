#include <iostream>
#include <string>
#include <ctime>
#include <unistd.h>
#include <stdlib.h> 
#include <conio.h>

char Map[40][40];
char go = 'y';
int lives = 3;
int turn = 0;
int score = 0;

int level = 1;
int S = 5;
int b = 0;
int C = 0;
int nc, dist;
std::string name, name2;

class character {
   public:
//    std::string name;
    int x, y, z;
//pos cp;
//    int dir;
    char alive = 'a';

};

//struct pos {int x, y, z}

class item {
   public:
//    std::string name;
    int x, y, z;
    int pickup = 0;
   // char alive = 'a';

};

class trap {
   public:
//    std::string name;
    int x, y, z;
    int pickup = 0;
   // char alive = 'a';

};

void delay(float seconds){
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.
    while(clock() < startClock+secondsAhead);
    return;
  }

void showmap()
{  
  std::cout << std::endl << std::endl;
 for (int y1=0; y1<20; y1++){
    for (int x1=0; x1<20; x1++){
   std::cout << Map[x1][y1];
    }
        if (y1 == 1) std::cout << "     name: " << name;
   else if (y1 == 3) std::cout << "     level: " << level;
   else if (y1 == 5) std::cout << "     score: " << score;
   else if (y1 == 7) std::cout << "     lives: " << lives;
   else if (y1 == 9) std::cout << "     senses: " << S;
  else if (y1 == 11) std::cout << "     Chupos: " << C;
   else if (y1 == 14 && b == 1) std::cout << "   Spirit Compass      - c";
   else if (y1 == 15 && b == 1) std::cout << "   Danger Sense        - d";
   else if (y1 == 16 && b == 1) std::cout << "   Movement            - ijkl ";
   else if (y1 == 17 && b == 1) std::cout << "   Interact            - x";
   else if (y1 == 18 && b == 1) std::cout << "   Suicide            - s";

   
   
   
   std::cout << std::endl;
  }
}

void makemap()
{  
 for (int y=0; y<20; y++){ 
    for (int x=0; x<20; x++){
       Map[x][y] = ',';
      }
      }
}

void pain()
{
switch(lives){
  case 3:{
  std::cout << "Sometimes you gotta learn the hard way" << std::endl; 
  usleep(1000000);
   lives--; 
  break;
    }
  case 2:{
  std::cout << "My leg hurts" << std::endl; 
    usleep(1000000);
   lives--; 
  break;
    }
  case 1:{
  std::cout << "ohh..." << std::endl; 
    usleep(500000);
  std::cout << "feeling woozy..." << std::endl; 
    usleep(500000);
   lives--; 
  break;
    }
}
  }

void randomove(int &m, int &j){
  int o;
  o = rand() % 3*level + 1;
  o -= 2*level;
  m += o;
  if (m>19)m=1;
  else if (m<0)m=19;
  o = rand() % 3*level + 1;
  o -= 2*level;
  j += o;
  if (j>19)j=1;
  else if (j<0)j=19;
  }

void fall(int &fx, int &fy){
std::cout << "You fell" << std::endl; 
         usleep(600000);
std::cout << "Ouch" << std::endl; 
     usleep(600000);
         lives--;
         fx=0;
         fy=19;  
}

int main() {
  
  character player1;
  character baddie1, baddie2;
  int area = 0;
  char ta = 'y';
//  int score = 0;
  item key1, key2, box;
  trap spike1, spike2;
  char keyin = 'a';

  /* initialize random seed: */
  srand (time(NULL));
  
  
  key1.pickup = 1;
  key2.pickup = 1;


  /* generate random number between 1 and 19
    for 2 keys, 2 traps and the treasure box*/
  
  
  
 // makemap();
  
  std::cout << "What is your name?\n";
  std::cin >> name;
  std::cout << "Lets begin!\n";
 // std::cout << "Hello " << player1.name << "\n";
  
   system("cls");

 
  std::cout << "Hello " << name << std::endl << "Welcome to Zenox 3000!\nThe world in which you are the player!\n" << std::endl; 
  std::cout << "The Chupolapas have been captured and put in treasure boxes";
  usleep(2000000);
  std::cout << "....find them\n" << std::endl;  
  usleep(2000000);
  std::cout << "You are an esper, use your powers wisely and set them free....\n" << std::endl;  
//  player1.z=11;
//  std::cout << player1.alivbe << std::endl;
  usleep(1000000);
//  system("clear");
  std::cout << "Press 'b' to show your buttons" << std::endl;
//  std::cin >> keyin;
  usleep(4000000);
while (ta == 'y') {
  lives = 3;
  score = 0;
  level = 1;
  S = 5;
  
if (turn>0){
  std::cout << "Is your name " << name << "?  (y/n)" << std::endl;
  std::cin >> keyin;
  if (keyin == 'n'){
    std::cout << "What is your name?\n";
  std::cin >> name;
  }}
  

  key1.x = rand() % 19 + 1;
  key1.y = rand() % 19 + 1;
  
  key2.x = rand() % 19 + 1;
  key2.y = rand() % 19 + 1;
  
  spike1.x = rand() % 19 + 1;
  spike1.y = rand() % 19 + 1;
  
  spike2.x = rand() % 19 + 1;
  spike2.y = rand() % 19 + 1;

  baddie1.x = rand() % 19 + 1;
  baddie1.y = rand() % 19 + 1;
  
  baddie2.x = rand() % 19 + 1;
  baddie2.y = rand() % 19 + 1;
  
  box.x = rand() % 19 + 1;;
  box.y = rand() % 19 + 1;

  player1.x=0;
  player1.y=19;
  
  while (lives > 0)
    { 

int xdif, ydif, dir, xdis, ydis;
      
     keyin = getch();
     makemap();

  Map[spike1.x][spike1.y] = '^';
    if (level>1)  Map[spike1.x+1][spike1.y] = '^';
    if (level>2)  Map[spike1.x+2][spike1.y] = '^';
    if (level>3)  Map[spike1.x+2][spike1.y-1] = '^';
    if (level>4)  Map[spike1.x+2][spike1.y-1] = '^';
      
      Map[spike2.x][spike2.y] = '^';
    if (level>1)  Map[spike2.x][spike2.y+1] = '^';
    if (level>2)  Map[spike2.x][spike2.y+2] = '^';
    if (level>3)  Map[spike1.x+1][spike1.y+2] = '^';
    if (level>4)  Map[spike1.x+2][spike1.y+1] = '^';
      
      switch(keyin) {

         
      case 'b':{
        if (b==0)b++;
        else if (b==1)b--;    
        break;
        }       

        case 's':{
          system("clear");
          std::cout << std::endl <<  std::endl << std::endl << std::endl <<"Are you sure... (y/n)" << std::endl;
          std::cin >> keyin;
          if (keyin == 'y'){
          lives--;
          lives--;
          lives--;
            }
          break;
        }
        
        case 'c':{       //
        xdif = player1.x-box.x;
        ydif = player1.y-box.y;  
          if (S>0){
            system("clear");
        std::cout << std::endl << "Getting in touch with your emotions... " << std::endl;
         usleep(900000); 
          std::cout << "The treasure is to the ";
          if (ydif>0) std::cout << "N";
            else if (ydif<0) std::cout << "S";
          if (xdif>0) std::cout << "W";
            else if (xdif<0) std::cout << "E";
     //       std::cout << std::endl;
            S--;
           usleep(900000);  
            ydis = abs(ydif);
            xdis = abs(xdif);
            dist = xdis + ydis; 
          std::cout << "   ..." << dist << " spaces";
        break;
            } else { std::cout << "no more sense, wait till next level" << std::endl;
           usleep(300000);
            break;
            }
        } 

        case 'd':{
          if (S>0){
        xdif = player1.x-box.x;
        ydif = player1.y-box.y;  
          system("clear");
        std::cout << std::endl << "Getting in touch with your emotions... " << std::endl;
         usleep(900000); 
          std::cout << "Reveal the baddies ";
          system("clear"); 
      Map[baddie1.x][baddie1.y] = 'B';
      Map[baddie2.x][baddie2.y] = 'B';   
          S--;}
          else { std::cout << "no more sense, wait till next level" << std::endl;
           usleep(300000);
            }
        break;
        }
  /*    case 65:
       std::cout << std::endl << "Up" << std::endl;//key up
      break;
        
      case 66:
    std::cout << std::endl << "Down" << std::endl;   // key down
      break;
        
      case 67:
    std::cout << std::endl << "Right" << std::endl;  // key right
      break;
        
      case 68:
    std::cout << std::endl << "Left" << std::endl;  // key left
      break;
*/
      case 'j':{
/*        Map[player1.y][player1.x]= ' ';  */
        player1.x -= 1;
        randomove(baddie1.x, baddie1.y);
        randomove(baddie2.x, baddie2.y);
        randomove(spike1.x, spike1.y);
        randomove(spike2.x, spike2.y);
  if (Map[player1.x][player1.y] == '^') pain();
    else if (player1.x == baddie1.x && player1.y == baddie1.y) 
      {
        system("clear");
      std::cout << "You've been caught by the baddies, instant death awaits" << std::endl;
        system("clear");
        usleep(10000000);
            lives = 0;
      }
    else if (player1.x == baddie2.x && player1.y == baddie2.y) {     system("clear");
      std::cout << "There aint gonna be nothin left when the baddies are done with ya" << std::endl;
        usleep(1000000);
              lives = 0; }
         else if (player1.x<0){ 
         fall(player1.x, player1.y);          
        }}
         break;
        
       
        case 'l':{
/*        Map[player1.y][player1.x]= ' ';  */
        player1.x += 1;
        randomove(baddie1.x, baddie1.y);
        randomove(baddie2.x, baddie2.y);
        randomove(spike1.x, spike1.y);  
        randomove(spike2.x, spike2.y);
      if (Map[player1.x][player1.y] == '^')  {                         pain(); }
        else if (player1.x == baddie1.x && player1.y == baddie1.y) {
              std::cout << "You've been caught by the baddies, instant death awaits" << std::endl;
          usleep(1000000);
            lives = 1;
            lives--;
          }
        else if (player1.x == baddie2.x && player1.y == baddie2.y) {
              std::cout << "There aint gonna be nothin left when the baddies are done with ya" << std::endl;
          usleep(1000000);
            lives = 1;
            lives--; }
        else if (player1.x>19){  
        fall(player1.x, player1.y);          
        }}
        break; 
        
      case 'i':{
   //     if (player1.y > 1){
   //     Map[player1.y][player1.x]= ' ';  
        player1.y -= 1;
        randomove(baddie1.x, baddie1.y);
        randomove(baddie2.x, baddie2.y);
        randomove(spike1.x, spike1.y);  
        randomove(spike2.x, spike2.y);
        if (Map[player1.x][player1.y] == '^') {                         pain(); }
          else if (player1.x == baddie1.x && player1.y == baddie1.y) {
              std::cout << "You've been caught by the baddies, instant death awaits" << std::endl;
            usleep(1000000);
            lives = 1;
            lives--;}
            else if (player1.x == baddie2.x && player1.y == baddie2.y) {
              std::cout << "There aint gonna be nothin left when the baddies are done with ya" << std::endl;
            usleep(1000000);  
            lives = 1;
            lives--;}
         else if (player1.y<0){           
         fall(player1.x, player1.y);          
        }}
  /*      else { 
         std::cout << 'Entering new area' << std::endl;
          player1.y = 21;} */
        break;
        
      case 'k':{
   /*    if (player1.y < 21){
        Map[player1.y][player1.x]= ' ';  */
        player1.y += 1; 
        randomove(baddie1.x, baddie1.y);
        randomove(baddie2.x, baddie2.y);
        randomove(spike1.x, spike1.y);  
        randomove(spike2.x, spike2.y);
        if (Map[player1.x][player1.y] == '^' )
  //        || Map[player1.x][player1.y] == 'B'  )
        {                         pain(); }
          else if (player1.x == baddie1.x && player1.y == baddie1.y) {  std::cout << "You've been caught by the baddies, instant death awaits" << std::endl;
            usleep(1000000);
            lives = 0; }
            else if (player1.x == baddie2.x && player1.y == baddie2.y) {  std::cout << "There aint gonna be nothin left when the baddies are done with ya" << std::endl;
            usleep(1000000);
            lives = 0; } 
         else if (player1.y>19){           
         fall(player1.x, player1.y);        
        }}
   /*     else { 
          std::cout << 'Entering new area' << std::endl;
          player1.y = 0;} */
        break;
        
      case 'x':{
         if (key1.x == player1.x && key1.y == player1.y)
       {
         std::cout << "Picked up a key" << std::endl;
         score++;
         usleep(600000);
         std::cout << "Nice" << std::endl;
         usleep(600000);
         key1.x = key1.y = 35;
         key1.pickup = 2;
       }
      else if (key2.x == player1.x && key2.y == player1.y)
       {
         std::cout << "Picked up a dusty looking key," << std::endl;
         usleep(1200000);
//         std::cout << " << std::endl;
  //       usleep(400000);
         score++;
         key2.x = key2.y = 35;
         key2.pickup = 2;
       }
      else if (box.x == player1.x && box.y == player1.y && key2.pickup == 2 && key1.pickup == 2) 
      {
          std::cout << "Treasure box opened!" << std::endl;
  
        usleep(600000);
        score += 3;
          std::cout << "Level Complete!" << std::endl;
        usleep(600000);
        level++;
        nc = rand() % 3 + 1;
         std::cout << "Saved " << nc << " Chupos" << std::endl;
        score += nc;
        C += nc;
        
        usleep(600000);
        
        S = 5;
 
  spike1.x = rand() % 19 + 1;
  spike1.y = rand() % 19 + 1;
  
  spike2.x = rand() % 19 + 1;
  spike2.y = rand() % 19 + 1;
        
  key1.x = rand() % 19 + 1;
  key1.y = rand() % 19 + 1;
  
  key2.x = rand() % 19 + 1;
  key2.y = rand() % 19 + 1;

  baddie1.x = rand() % 19 + 1;
  baddie1.y = rand() % 19 + 1;
  
  baddie2.x = rand() % 19 + 1;
  baddie2.y = rand() % 19 + 1;      
    
  box.x = rand() % 19 + 1;;
  box.y = rand() % 19 + 1;

  player1.x=0;
  player1.y=19;
      }
        break;
        } 
        }
   //   usleep(30000);
      
      system("clear");
      
//makemap();  
/*   Map[key3.x][key3.y] = 'k';
      Map[spike1.x][spike1.y] = '^';
    if (level>1)  Map[spike1.x+1][spike1.y] = '^';
    if (level>2)  Map[spike1.x+2][spike1.y] = '^';
    if (level>3)  Map[spike1.x+2][spike1.y-1] = '^';
    if (level>4)  Map[spike1.x+2][spike1.y-1] = '^';
      
      Map[spike2.x][spike2.y] = '^';
    if (level>1)  Map[spike2.x][spike2.y+1] = '^';
    if (level>2)  Map[spike2.x][spike2.y+2] = '^';
    if (level>3)  Map[spike1.x+1][spike1.y+2] = '^';
    if (level>4)  Map[spike1.x+2][spike1.y+1] = '^';
*/   
      Map[key1.x][key1.y] = 'k';
      Map[key2.x][key2.y] = 'k';   
     
//      Map[box.x][box.y] = 'U'; 
      Map[player1.x][player1.y] = 'O';

      
      showmap();
      //std::cout << player1.alive;
      } 
  system("clear");
  std::cout << name << std::endl;
  usleep(500000);
  std::cout << "...you died" << std::endl << std::endl;
  usleep(500000);
  std::cout << "Try again?  (y/n)" << std::endl;
  std::cin >> ta; 
  turn++;
  if (ta == 'y') { lives = 3; --player1.y;}
 }
  }
//usleep(3000000);