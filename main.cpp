#include <bits/stdc++.h>
#include <conio.h>
const int RIGHTBORDER = 25;
const int UPBORDER = 0;
const int DOWNBORDER = 20;
const int LEFTBORDER = 0;

using namespace std;
char gameArea[1000][1000];
map<char, char> opposite;

void fillGameArea(){
    for(int i = UPBORDER;i <= DOWNBORDER;i++){
        for(int j = LEFTBORDER;j <= RIGHTBORDER;j++){
            gameArea[i][j] = ' ';
        }
    }

    //up border
    for(int j = LEFTBORDER;j <= RIGHTBORDER;j++){
        gameArea[UPBORDER][j] = '*';
    }

    //left border
    for(int i = UPBORDER;i <= DOWNBORDER;i++){
        gameArea[i][LEFTBORDER] = '*';
    }

    //right border
    for(int j = UPBORDER;j <= DOWNBORDER;j++){
        gameArea[j][RIGHTBORDER] = '*';
    }

    //down border
    for(int j = LEFTBORDER;j <= RIGHTBORDER;j++){
        gameArea[DOWNBORDER][j] = '*';
    }
}

void filloppositeArray(){
    opposite['L'] = 'R';
    opposite['R'] = 'L';
    opposite['D'] = 'U';
    opposite['U'] = 'D';
}
void print(){
    for(int i = UPBORDER;i <= DOWNBORDER;i++){
        for(int j = LEFTBORDER;j <= RIGHTBORDER;j++){
            cout << gameArea[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
class snake{
    public:
    snake(){
        a[1] = {12, 12};
        a[2] = {12, 13};
        a[3] = {12, 14};
    }
    pair< int, int > a[100];
    int length = 3;
    char direction = 'R';
    void changeDirection(char newDirection){
        if(newDirection != opposite[direction]){
            direction = newDirection;
        }
    }


    void moveSnake(){
        if(direction == 'U'){
            pair< int, int >head = a[length];
            for(int i = length;i >= 1;i--){
                if(a[i].second == head.second){
                    a[i].first--;
                }
                else{
                    if(a[i].second < head.second){
                        a[i].second++;
                    }
                    else{
                        a[i].second--;
                    }
                }
                ///
                if(a[i].first == UPBORDER){
                    a[i].first = DOWNBORDER-1;
                }
                if(a[i].first == DOWNBORDER){
                    a[i].first = UPBORDER+1;
                }
                if(a[i].second == LEFTBORDER){
                    a[i].second = RIGHTBORDER-1;
                }
                if(a[i].second == RIGHTBORDER){
                    a[i].second = LEFTBORDER+1;
                }
            }
        }

        else if(direction == 'D'){
            pair< int, int >head = a[length];
            for(int i = length;i >= 1;i--){
                if(a[i].second == head.second){
                    a[i].first++;
                }
                else{
                    if(a[i].second < head.second){
                        a[i].second++;
                    }
                    else{
                        a[i].second--;
                    }
                }
                ///
                if(a[i].first == UPBORDER){
                    a[i].first = DOWNBORDER-1;
                }
                if(a[i].first == DOWNBORDER){
                    a[i].first = UPBORDER+1;
                }
                if(a[i].second == LEFTBORDER){
                    a[i].second = RIGHTBORDER-1;
                }
                if(a[i].second == RIGHTBORDER){
                    a[i].second = LEFTBORDER+1;
                }
            }
        }

        else if(direction == 'L'){
            pair< int, int >head = a[length];
            for(int i = length;i >= 1;i--){
                if(a[i].first == head.first){
                    a[i].second--;
                }
                else{
                    if(a[i].first < head.first){
                        a[i].first++;
                    }
                    else{
                        a[i].first--;
                    }
                }
                ///
                if(a[i].first == UPBORDER){
                    a[i].first = DOWNBORDER-1;
                }
                if(a[i].first == DOWNBORDER){
                    a[i].first = UPBORDER+1;
                }
                if(a[i].second == LEFTBORDER){
                    a[i].second = RIGHTBORDER-1;
                }
                if(a[i].second == RIGHTBORDER){
                    a[i].second = LEFTBORDER+1;
                }
            }
        }

        else if(direction == 'R'){
            pair< int, int >head = a[length];
            for(int i = length;i >= 1;i--){
                if(a[i].first == head.first){
                    a[i].second++;
                }
                else{
                    if(a[i].first < head.first){
                        a[i].first++;
                    }
                    else{
                        a[i].first--;
                    }
                }

                ///
                if(a[i].first == UPBORDER){
                    a[i].first = DOWNBORDER-1;
                }
                if(a[i].first == DOWNBORDER){
                    a[i].first = UPBORDER+1;
                }
                if(a[i].second == LEFTBORDER){
                    a[i].second = RIGHTBORDER-1;
                }
                if(a[i].second == RIGHTBORDER){
                    a[i].second = LEFTBORDER+1;
                }
            }
        }

    }
    ///moveSnake End
    void printSnake(){
        for(int i = 1;i <= length;i++){
            gameArea[a[i].first][a[i].second] = '#';
        }
    }

};
int main(){
    filloppositeArray();
    fillGameArea();

    snake mySnake;
    while(1){
        if(kbhit()){
            char key = getch();
            if(key == 'w'){
                key = 'U';
            }
            else if(key == 'a'){
                key = 'L';
            }
            else if(key == 's'){
                key = 'D';
            }
            else if(key == 'd'){
                key = 'R';
            }
            mySnake.changeDirection(key);
        }
        fillGameArea();
        mySnake.moveSnake();
        mySnake.printSnake();
        print();
        system("cls");
    }


}
