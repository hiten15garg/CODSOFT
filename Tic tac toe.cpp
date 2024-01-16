// WAP program to make tic tac toc game.
// Included header files
#include <iostream>
#include <stdlib.h>
// #include <conio.h>
using namespace std;
// class players - toss(), tossReturn(), playerturn(), struTTT, tictactoe(), result(), cleared() functions
class players
{
    int row, column;
    int plchoice;
    char choose, choice[2] = {'O', 'X'};
    char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

public:
    int O = 0, X = 0;
    char turn;
    int draw = 0;
    // Structure of tictactoe
    void struTTT()
    {
        cout << "\n\nTic tac Toe game" << endl;
        cout <<" \t* * * * * * * * * * * * *" << endl;
        cout << "\t*        |     |        *" << endl;
        cout << "\t*     " << arr[0][0] << "  |  " << arr[0][1] << "  |  " << arr[0][2] << "     *" << endl;
        cout << "\t*   _____|_____|_____   *" << endl;
        cout << "\t*        |     |        *" << endl;
        cout << "\t*     " << arr[1][0] << "  |  " << arr[1][1] << "  |  " << arr[1][2] << "     *" << endl;
        cout << "\t*   _____|_____|_____   *" << endl;
        cout << "\t*        |     |        *" << endl;
        cout << "\t*     " << arr[2][0] << "  |  " << arr[2][1] << "  |  " << arr[2][2] << "     *" << endl;
        cout << "\t*        |     |        *" << endl;
        cout <<" \t* * * * * * * * * * * * *" << endl;
        // system("pause");
    } 

    // Starting toss between both players
    void toss()
    {
        cout << "Toss for who will start first :" << endl;
        cout << "Choose Number, Only O or X:" << endl;
        cin >> choose;
        if (choose == choice[1])
        {
            turn = 'X';
            cout << turn << " Turn. " << endl;
        }
        else
        {
            if (choose != choice[0])
            {
                turn = 'O';
                cout << turn << " Turn. " << endl;
            }
        }
        if (choose == choice[0])
        {
            turn = 'O';
            cout << turn << " Turn. " << endl;
        }
        else
        {
            if (choose != choice[1])
            {
                turn = 'X';
                cout << turn << " Turn. " << endl;
            }
        }
    }

    // player input for selecting the box in sturcture
    void tossReturn()
    {
        if (turn == 'X' || turn == 'O')
        {
            cout << turn << " Turn: (Choose only between 1 to 9)" << endl;
            cin >> plchoice;
        }
    }

    // It selected in the playerturn() function
    void playerturn()
    {

        tossReturn();
        switch (plchoice)
        {
        case 1:
            row = 0, column = 0;
            break;
        case 2:
            row = 0, column = 1;
            break;
        case 3:
            row = 0, column = 2;
            break;
        case 4:
            row = 1, column = 0;
            break;
        case 5:
            row = 1, column = 1;
            break;
        case 6:
            row = 1, column = 2;
            break;
        case 7:
            row = 2, column = 0;
            break;
        case 8:
            row = 2, column = 1;
            break;
        case 9:
            row = 2, column = 2;
            break;
        // case 10:
        //     n = 0;
        //     break;
        default:
            cout << "Invalid way!!" << endl;
            break;
        }

        if (turn == 'X' && arr[row][column] != 'X' && arr[row][column] != 'O')
        {
            arr[row][column] = 'X';
            turn = 'O';
        }
        else if (turn == 'O' && arr[row][column] != 'X' && arr[row][column] != 'O')
        {
            arr[row][column] = 'O';
            turn = 'X';
        }
        else
        {
            cout << "Already filled can't fill, try another." << endl << flush;
            system("pause");
        }
    }

    // box is refreshed after a game
    void cleared()
    {
        arr[0][0] = '1';
        arr[0][1] = '2';
        arr[0][2] = '3';
        arr[1][0] = '4';
        arr[1][1] = '5';
        arr[1][2] = '6';
        arr[2][0] = '7';
        arr[2][1] = '8';
        arr[2][2] = '9';
    }

    // whole working of above function
    void tictoctoeg(int f, int play, int playagain)
    {
        if (playagain == 1)
        {
            toss();
        }
        else if (play == 1)
        {
            toss();
        }
        else if (playagain == 2)
        {
            cleared();
        }
        while (f != gameover())
        {
            struTTT();
            playerturn();
            gameover();
            cout <<endl <<endl << endl << endl << endl;
            system("cls");
        }
        struTTT();
        cleared(); // for refreshing
        if (turn == 'X' && draw == 0)
        {
            cout << "Player [O] wins, Congratulations." << endl;
            O++;
        }
        else if (turn == 'O' && draw == 0)
        {
            cout << "Player [X] wins, Congratulations." << endl;
            X++;
        }
        else
        {
            cout << "Match Draw." << endl;
            draw = 0;
        }

        if ((playagain == 2) || (playagain == 0) || (playagain == 1))
        {
            cout << "Score of O:" << O << endl
                 << "Score of X:" << X << endl;
            system("pause");
        }
    }

    // whether the match is over or not - win, draw or still going on
    bool gameover()
    {
        // Win
        for (int i = 0; i < 3; i++)
        {
            if ((arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) || (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]))
            {
                return false;
            }
        }
        if ((arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]))
        {
            return false;
        }

        // going on
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] != 'X' && arr[i][j] != 'O')
                {
                    return true;
                }
            }
        }

        // draw
        draw = 1;

        // Clearing
        // ~gameover();
        return false;
    }

    // result for series matches
    void result(int x, int o, int series)
    {
        if (series > 1)
        {
            if (x > o)
            {
                cout << "Player X win the series of " << series << " matches by " << x << " - " << o << endl;
            }
            else if (o > x)
            {
                cout << "Player O win the series of " << series << " matches by " << o << " - " << x << endl;
            }
            else
            {
                if (o == x)
                {
                    cout << "Series Draw of: " << series << " matches by " << o << " - " << x << endl;
                }
            }
        }
        else
        {
            if (series == 1)
            {
                if (x > o)
                {
                    cout << "Player X with the Match " << endl;
                }
                else if (o > x)
                {
                    cout << "Player O with the Match" << endl;
                }
            }
        }
    }
};

int main()
{
    // important variables
    int playl, playagain, seriesCon, seriesNew = 0;
    bool f = false;
    string n = "e", n1;

    // class call
    players play;

    // Nested switch case
    while (n != "exit")
    {
        int flag = 0;
        cout << "Want to Play:" << endl;
        cout << "Choose 1 for play.\n2 for Exit" << endl;
        cin >> playl;
        switch (playl)
        {
        case 1:
            play.cleared();
            play.tictoctoeg(f, playl, 0);
            n1 = "e";
            while (n1 != "exit")
            {
                // cout << "Choose 1 for single match\n2 for Multiple matchs\n3 for Continue series(including 1st game)\n4 for Exit" << endl;
                cout << "Choose 1 - single match(new match)\n2 - Continue series(including 1st game)\n3 - Multiple matches(New Series)\n4 - Exit" << endl;
                cin >> playagain;
                switch (playagain)
                {
                case 1: // for single match
                    flag = 1;
                    play.O = 0;
                    play.X = 0;
                    play.tictoctoeg(f, 0, playagain);
                    break;
                case 2: // for continuing the game
                    if (flag == 1 || flag == 0)
                    {
                        flag = 2;
                        int n = 0;
                        cout << "Continued Series:" << endl;
                        while (n != 1)
                        {
                            cout << "No. of Matches after including previous match: (Not more than 10 match) :" << endl;
                            cin >> seriesCon;
                            if (seriesCon <= 10)
                            {
                                for (int i = seriesCon; i >= 1; i--)
                                {
                                    cout << "Remaining Matches " << i << ": " << endl;
                                    play.tictoctoeg(f, 0, playagain);
                                }
                                if (seriesNew == 0)
                                {
                                    seriesCon = seriesCon + 1;
                                }
                                play.result(play.X, play.O, seriesCon + seriesNew);
                                n = 1;
                                play.O = 0;
                                play.X = 0;
                            }
                            else
                            {
                                cout << "Invalid! not more than 10 games are allowed" << endl;
                            }
                        }
                    }
                    break;
                case 3: // for series match
                    if (flag == 0 || flag == 1 || flag == 2)
                    {
                        flag = 1;
                        play.O = 0;
                        play.X = 0;
                        cout << "New Series:" << endl;
                        cout << "No. of Matches:" << endl;
                        cin >> seriesNew;
                        // play.tictoctoeg(f, playl, 0);
                        int j = 0;
                        for (int i = 0; i < seriesNew; i++)
                        {
                            cout << "Match " << ++j << ": " << endl;
                            play.tictoctoeg(f, 0, playagain);
                        }
                        play.result(play.X, play.O, seriesNew);
                    }
                    break;
                case 4:
                    flag = 0;
                    play.O = 0;
                    play.X = 0;
                    n1 = "exit";
                    break;
                default:
                    cout << "Invalid choose." << endl;
                    break;
                }
            }
            break;
        case 2:
            n = "exit";
            break;
        default:
            cout << "Invalid choose." << endl;
            break;
        }
    }

    return 0;
}

// toss
// design
// bugs
// description
