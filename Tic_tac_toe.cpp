#include <graphics.h>
#include <conio.h>
#include <stdio.h>

char board[3][3];  
int player = 1;   


void drawBoard() {
    setcolor(WHITE);
   
    line(200, 100, 200, 400);
    line(300, 100, 300, 400);
    line(100, 200, 400, 200);
    line(100, 300, 400, 300);
}

void drawX(int x, int y) {
    setcolor(RED);
    line(x + 20, y + 20, x + 80, y + 80);
    line(x + 80, y + 20, x + 20, y + 80);
}


void drawO(int x, int y) {
    setcolor(BLUE);
    circle(x + 50, y + 50, 30);
}


void markBoard(int row, int col) {
    int x = 100 + col * 100;
    int y = 100 + row * 100;

    if (player == 1) {
        drawX(x, y);
        board[row][col] = 'X';
    } else {
        drawO(x, y);
        board[row][col] = 'O';
    }

    player = 3 - player;  
}

int checkWin() {
   
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '\0') return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '\0') return 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '\0') return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '\0') return 1;


    return 0;
}


int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '\0') return 0;
        }
    }
    return 1;
}


void gameLoop() {
    int row, col;
    char key;

    while (1) {
        if (checkWin()) {
            outtextxy(150, 450, "Player has won!");
            break;
        }

        if (checkDraw()) {
            outtextxy(150, 450, "It's a Draw!");
            break;
        }

        key = getch();  

       
        switch (key) {
            case '1': row = 2; col = 0; break;
            case '2': row = 2; col = 1; break;
            case '3': row = 2; col = 2; break;
            case '4': row = 1; col = 0; break;
            case '5': row = 1; col = 1; break;
            case '6': row = 1; col = 2; break;
            case '7': row = 0; col = 0; break;
            case '8': row = 0; col = 1; break;
            case '9': row = 0; col = 2; break;
            default: continue;
        }

        if (board[row][col] == '\0') {
            markBoard(row, col);
        }
    }
}

int main() {
    int gd = DETECT, gm;

  
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '\0';
        }
    }

 
    drawBoard();
    gameLoop();

    getch();
    closegraph();
    return 0;
}

