#include <stdio.h>
#include <stdbool.h>
// define a fixed Size of the board
#define Size 3

// chars so we can associate players with chars later
char board[Size][Size];


void NewBoard(){ 
    // Since we 1 index on ttt board 
    // & zero index in c language
    int countTiles = 1;
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            board[i][j] = '0' + countTiles;
            countTiles++;
        }
        
    }
}  

void PrintBoard() {
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            printf(" %c ", board[i][j]);
            // We print this beside our board
            if (j < Size - 1) {
                printf("|");}
        }
        // New line to seperate rows from cols
        printf("\n");
        if (i < Size - 1) printf("---+---+---\n");
    }
}
// Method to check if a player has won
bool CheckWin(char player) {
    // Checking linear rows and cols
    for (int i = 0; i <Size; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // Checking the diagonal cols
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}

// Method checking for a draw
bool CheckDraw() {
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            // checks entire board to see if every tiles is occupied
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

// Method responsible for making moves
bool MakeMove(int choice, char player) {
    int row = (choice - 1);
    int col = (choice - 1);

    //checking for invalid moves
    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }

    board[row][col] = player;
    return true;
}

int main() {
    int choice;
    char currentPlayer = 'X';
    bool gameOver = false;
    // Start with a new board
    NewBoard();

    while (!gameOver) {
        PrintBoard();
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        scanf("%d", &choice);

        if (!MakeMove(choice, currentPlayer)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        if (CheckWin(currentPlayer)) {
            PrintBoard();
            printf("Player %c wins!\n", currentPlayer);
            gameOver = true;
        } else if (CheckDraw()) {
            PrintBoard();
            printf("It's a draw!\n");
            gameOver = true;
        } else {
            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}


