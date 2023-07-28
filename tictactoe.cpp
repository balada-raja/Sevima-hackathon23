#include <iostream>

using namespace std;

char square [10] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

//function to return the game status

int checkwin(){
    if(square[1] == square [2] && square[2] == square[3]){
        return 1;
    }else if(square[4] == square [5] && square[5] == square[6]){
        return 1;
    }else if(square[7] == square [8] && square[8] == square[9]){
        return 1;
    }else if(square[1] == square [4] && square[4] == square[7]){
        return 1;
    }else if(square[2] == square [5] && square[5] == square[8]){
        return 1;
    }else if(square[3] == square [6] && square[6] == square[9]){
        return 1;
    }else if(square[1] == square [5] && square[5] == square[9]){
        return 1;
    }else if(square[7] == square [5] && square[5] == square[3]){
        return 1;
    }else if(square[1] != '1' && square [2] != '2' && square[3] != '3'
            && square[4] != '4' && square [5] != '5' && square[6] != '6'
            && square[7] != '7' && square [8] != '8' && square[9] != '9'){
        return 0;
    }else{
        return -1;
    }
}

void clearScreen() {
    // Use ANSI escape sequence to clear the screen
    cout << "\x1B[2J\x1B[H";
}

//this function will draw rhe board with the player

void board(){
    clearScreen();
    cout << "\n\n Tic Tac Toe Game \n\n";

    cout << "playar 1 (X) and player 2(O)\n" << endl;

    //drawing the board
    cout << "       |       |       " << endl;
    cout << "   " << square[1] << "   |   " << square[2] << "   |   " << square[3] << endl;
    cout << "_______|_______|_______" << endl;

    cout << "       |       |       " << endl;
    cout << "   " << square[4] << "   |   " << square[5] << "   |   " << square[6] << endl;
    cout << "_______|_______|_______" << endl;

    cout << "       |       |        " << endl;
    cout << "   " << square[7] << "   |   " << square[8] << "   |   " << square[9] << endl;
    cout << "       |       |        " << endl;
}

int main(){
    int player  = 1, i, choice;

    char mark;

    int result;
    do {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter the number : ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        // periksa input yang tidak valid
        if (choice < 1 || choice > 9) {
            cout << "Invalid move! Please enter a number between 1 and 9." << endl;
            cin.ignore();
            cin.get();
            continue;
        }

        // periksa apakah posisi sudah diisi sebelumnya
        if (square[choice] != 'X' && square[choice] != 'O') {
            square[choice] = mark;
        } else {
            cout << "Invalid move! That position is already taken." << endl;
            cin.ignore();
            cin.get();
            continue;
        }

        result = checkwin();
        player++;
    } while (result == -1);

    board();
    if (result == 1) {
        // pemain yang menang adalah player sebelumnya
        cout << "\a CONGRATULATION! PLAYER " << player - 1 << " WINS!";
    } else {
        cout << "\a DRAW!";
    }

    cin.ignore();
    cin.get();
    return 0;
}

//     do{
//         board();
//         player = (player%2)?1:2;

//         cout << "player " << player << ", enter the number : ";
//         cin >> choice;

//         mark = (player == 1) ? 'X' : 'O';

//         if(choice == 1 && square [1] == '1'){
//             square[1] = mark;
//         }else if (choice == 2 && square [2] == '2'){
//             square[2] = mark;
//         }else if (choice == 3 && square [3] == '3'){
//             square[3] = mark;
//         }else if (choice == 4 && square [4] == '4'){
//             square[4] = mark;
//         }else if (choice == 5 && square [5] == '5'){
//             square[5] = mark;
//         }else if (choice == 6 && square [6] == '6'){
//             square[6] = mark;
//         }else if (choice == 7 && square [7] == '7'){
//             square[7] = mark;
//         }else if (choice == 8 && square [8] == '8'){
//             square[8] = mark;
//         }else if (choice == 9 && square [9] == '9'){
//             square[9] = mark;
//         }else{
//             cout << "INVALID MOVE!";

//             player--;
//             cin.ignore();
//             cin.get();
//         }

//         i = checkwin();
//         player++;
//     }while (i == -1);
//     board();
//     if( i == 1){
//         cout << "\a CONGRATULATION! PLAYER "<< --player << " WINS!";
//     }else{
//         cout << "\a DRAW!";
//     }

//     cin.ignore();
//     cin.get();
//     return 0;
// }