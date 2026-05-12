
#include <iostream>
using namespace std;
char board[7][7];
void initializeBoard()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printGame()
{
    cout << "\n";
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << " " << board[i][j] << " ";

            if (j < 6)
            {

                cout << "|";
            }
        }

        if (i < 6)
        {
            cout << "\n";
            cout << "---+---+---+---+---+---+---";
        }
        cout << "\n";
    }
}
bool checkWin(char player)
{

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {

            // horizontal
            if (j + 3 < 7 &&
                board[i][j] == player &&
                board[i][j + 1] == player &&
                board[i][j + 2] == player &&
                board[i][j + 3] == player)
            {
                return true;
            }

            // vertical
            if (i + 3 < 7 &&
                board[i][j] == player &&
                board[i + 1][j] == player &&
                board[i + 2][j] == player &&
                board[i + 3][j] == player)
            {
                return true;
            }

            // diognal
            if (i + 3 < 7 && j + 3 < 7 && board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
            {
                return true;
            }

            // diognal
            if (i + 3 < 7 && j - 3 >= 0 &&
                board[i][j] == player &&
                board[i + 1][j - 1] == player &&
                board[i + 2][j - 2] == player &&
                board[i + 3][j - 3] == player)
            {
                return true;
            }
        }
    }

    return false;
}
bool isDraw()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
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
            cout << "Player " << player << " Enter row and cols(0,6): ";
            cin >> row >> col;
            if (row < 0 || row >= 7 || col < 0 || col >= 7 || board[row][col] != ' ')
            {
                cout << "Invalid move! Try again.\n";
                continue;
            }
            board[row][col] = player;
            if (checkWin(player))
            {
                printGame();
                cout << "player " << player << " ia win\n";
                gameOver = true;
            }
            else if (isDraw())
            {
                cout << "it's draw\n";
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