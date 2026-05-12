#include <iostream>
using namespace std;

char board[4][4];

void initializeBoard()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printGame()
{
    cout << "\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << " " << board[i][j] << " ";
            if (j < 3)
            {
                cout << "|";
            }
        }
        if (i < 3)
        {
            cout << "\n";
            cout << "---------------";
        }
        cout << "\n";
    }
}

bool checkWin(char player)
{
    for (int i = 0; i < 4; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player && board[i][3]==player)
        {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player && board[3][i] == player)
        {
            return true;
        }
    }
    for (int j = 0; j < 4; j++)
    {
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player)
        {
            return true;
        }
        if (board[0][3] == player && board[1][2] == player && board[2][1] == player && board[3][0] == player)
        {
            return true;
        }
    }
    return false;
}

bool isDraw()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    char player;
    int row, col;
    while (true)
    {
        initializeBoard();
        player = 'x';
        bool gameOver = false;
        while (!gameOver)
        {
            printGame();
            cout << "Player " << player << " Enter row and cols(0,3): ";
            cin >> row >> col;
            if (row < 0 || row > 3 || col < 0 || col > 3 || board[row][col] != ' ')
            {
                cout << "Invalid move! Try again.\n";
                continue;
            }
            board[row][col] = player;
            if (checkWin(player))
            {
                printGame();
                cout << "Player " << player << " wins!\n";
                gameOver = true;
            }
            else if (isDraw())
            {
                printGame();
                cout << "it's a draw! \n";
                gameOver = true;
            }
            else
            {
                player = (player == 'x') ? 'o' : 'x';
            }
        }
        char choice;
        cout << "Play again? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            continue;
        }
        else if (choice == 'n' || choice == 'N')
        {
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

    }
    return 0;
}