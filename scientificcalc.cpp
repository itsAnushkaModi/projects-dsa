#include <iostream>
#include <cmath>
using namespace std;

void show_calculator()
{
    cout << "----------------------------------------" << endl;
    cout << "----                               -----" << endl;
    cout << "--            SCIENTIFIC              --" << endl;
    cout << "--            CALCULATOR              --" << endl;
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;
    cout << "-   +     |    -       |     *         -" << endl;
    cout << "-  ADD    |   SUB      |   MULTI       -" << endl;
    cout << "----------------------------------------" << endl;
    cout << "-   /     |      m     |    L          -" << endl;
    cout << "-  DIVIDE |     Mod    |   Log         -" << endl;
    cout << "----------------------------------------" << endl;
    cout << "-     S   |      C     |     p         -" << endl;
    cout << "- Square  |     Cube   |   Power       -" << endl;
    cout << "----------------------------------------" << endl;
    cout << "-    s    |     c      |     t         -" << endl;
    cout << "-   sin   |    cos     |     tan       -" << endl;
    cout << "----------------------------------------" << endl;
    cout << "-    r    |      k     |     .         -" << endl;
    cout << "- sq root |     clear  |     close     -" << endl;
    cout << "----------------------------------------" << endl;
}

void display_output(double answer)
{
    cout << "----------------------------------------" << endl;
    cout << "----                         -----------" << endl;
    cout << "--            CURRENT       |      " << endl;
    cout << "--           OUTPUT IS:     |  " << answer << endl;
    cout << "----                         -----------" << endl;
    cout << "----------------------------------------" << endl;
    cout << "-   +     |    -       |     *         -" << endl;
    cout << "-  ADD    |   SUB      |   MULTI       -" << endl;
    cout << "----------------------------------------" << endl;
    cout << "-   /     |      m     |    L          -" << endl;
    cout << "-  DIVIDE |     Mod    |   Log         -" << endl;
    cout << "----------------------------------------" << endl;
    cout << "-     S   |      C     |     p         -" << endl;
    cout << "- Square  |     Cube   |   Power       -" << endl;
    cout << "----------------------------------------" << endl;
    cout << "-    s    |     c      |     t         -" << endl;
    cout << "-   sin   |    cos     |     tan       -" << endl;
    cout << "----------------------------------------" << endl;
    cout << "-    r    |      k     |     .         -" << endl;
    cout << "- sq root |     clear  |     close     -" << endl;
    cout << "----------------------------------------" << endl;
}

int main()
{
    double num1 = 0.0;
    double num2 = 0.0;
    double answer = 0.0;
    char inp = '\n';
    bool converter = false;

    // show_calculator();

    while (inp != '.')
    {
        if (converter == true)
            display_output(answer);

        cout << "Enter an operation: ";
        cin >> inp;

        if (inp == '+' || inp == '-' || inp == '*' || inp == '/' || inp == 'm' || inp == 'L' || inp == 'S' || inp == 'C' || inp == 'p')
        {
            num1 = answer;
            cout << "Enter num2: ";
            cin >> num2;
        }
        else if (inp == 'k' || inp == '.')
        {
            // no input to take
        }
        else
        {
            num1 = answer;
        }

        converter = true;

        switch (inp)
        {
        case '+':
            answer = num1 + num2;
            break;
        case '-':
            answer = num1 - num2;
            break;
        case '*':
            answer = num1 * num2;
            break;
        case '/':
            answer = num1 / num2;
            break;
        case 'm':
            answer = int(num1) % int(num2);
            break;
        case 'L':
            answer = log(num1);
            break;
        case 'S':
            answer = num1 * num1;
            break;
        case 'C':
            answer = num1 * num1 * num1;
            break;
        case 'p':
            answer = pow(num1, num2);
            break;
        case 's':
            answer = sin(num1);
            break;
        case 'c':
            answer = cos(num1);
            break;
        case 't':
            answer = tan(num1);
            break;
        case 'r':
            answer = sqrt(num1);
            break;
        case 'k':
            converter = false;
            break;
        case '.':
            break;
        default:
            cout << "You Entered Invalid Values !" << endl;
        }

        // Clear screen
        system("cls");
    }

    return 0;
}
 