#include <iostream>
#include <ctime>
#include <cstdlib>

// Cross-platform headers
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

using namespace std;

// Cross-platform clear screen
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Cross-platform sleep/pause
void pauseGame() {
    #ifdef _WIN32
        Sleep(1000); 
    #else
        sleep(1);    
    #endif
}

void GetSmartMove(char** arr, int& r, int&c);

void displayGrid(char** arr){
    clearScreen(); // Updated to use the new function
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<" "<<arr[i][j] <<(j!= 2? " | ": "");
        }
        cout<<endl;
        cout<<(i!=2? "______________": "")<<endl;;
    }
}

bool hasWon(char** arr, char ch){
    for(int i=0; i<3; i++){
        if(arr[i][0] == ch && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]){
            return true;
        }
        if(arr[0][i] == ch && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]){
            return true;
        }
    }
    if((arr[0][0] == ch && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || (arr[0][2] == ch && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])){
        return true;
    }
    return false;
}

bool isInBounds(int r, int c){
    if(r<1 || r>3 || c<1 || c>3)
    return false;

    return true;
}

bool isOccupied(char** arr, int r, int c){
    if(arr[r-1][c-1] != ' '){
        return true;
    }
    return false;
}

void Turn(char** arr,char ch){
    bool done = false;
    int r, c;
    if(ch=='X'){
        do{
            cout<<"Enter Row (1/2/3): ";
            cin>>r;
            cout<<"Enter Column (1/2/3): ";
            cin>>c;

            if(!isInBounds(r, c)){
                cout<<"Enter valid coordinates."<<endl;
                continue;
            }
            else if(isOccupied(arr, r, c)){
                cout<<"The cell is occupied."<<endl;
            }
            else{
                arr[r-1][c-1] = ch;
                done = true;
            }
        }while(!done);
    }
    else if(ch=='O'){
        GetSmartMove(arr, r, c);
        arr[r-1][c-1] = 'O';
    }
}

void GetSmartMove(char** arr, int& r, int&c){
    bool found = false;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(isInBounds(i+1, j+1) && !isOccupied(arr, i+1, j+1)){

                arr[i][j] = 'O';
                if(hasWon(arr, 'O')){
                    r = i+1;
                    c = j+1;
                    found = true;
                    break;
                }

                arr[i][j] = ' ';
            }
        }
         if(found) break;
    }

    if(!found){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(isInBounds(i+1, j+1) && !isOccupied(arr, i+1, j+1)){
                    arr[i][j] = 'X';
                    if(hasWon(arr, 'X')){
                        r = i+1;
                        c= j+1;
                        
                        found = true;
                        break;
                    }

                    arr[i][j] = ' ';
                }      
            }
             if(found) break;
        }
    }
    
    if(!found){
        if(!isOccupied(arr, 2, 2)){
            r = 2;
            c = 2;
        }
        else{
            bool done = false;
            do{
                r = rand() % 3 + 1;
                c = rand() % 3 + 1;
                if(!isInBounds(r, c)){
                    continue;
                }
                else if(isOccupied(arr, r, c)){
                    continue;
                }
                else{
                    done = true;
                }
            }while(!done);
        }
    }
}

int main(){
    srand(time(0));

    char** arr = new char*[3];
    for(int i=0; i<3; i++){
        arr[i] = new char[3];
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i][j] =' ';
        }   
    }
    bool is_over=false;
    int turns = 0;


    do{
        displayGrid(arr);
        cout<<"X turn:"<<endl;
            Turn(arr, 'X');
            turns++;
        if(hasWon(arr, 'X' )){
            is_over = true;
            displayGrid(arr);
            cout<<"X has won!!"<<endl;
            break;
        }
        displayGrid(arr);
        if(turns>=9){
            cout<<"It is a draw!!" <<endl;
            break;
        }
        
        cout<<"O turn: "<<endl;
        pauseGame(); // Updated to use the new function
        Turn(arr, 'O');
        turns++;
        if(hasWon(arr, 'O')){
            is_over = true;
            displayGrid(arr);
            cout<<"O has won!!"<<endl;
            break;
        }

        if(turns>=9){
            cout<<"It is a draw!!"<<endl;
            break;
        }
        
    }while(!is_over);


    for(int i=0; i<3; i++){
       delete[] arr[i];
    }
    delete[] arr;
}