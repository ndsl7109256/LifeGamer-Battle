#include "player.h"

#include <cstring>

Player::Player(QObject *parent):QProcess(parent), mana(5), ready(false)
{
    strcpy(enabled, "111111111000000000100000");
    cmd.clear();
    connect(this, SIGNAL(readyReadStandardOutput()), this, SLOT(readCommand()));
}

bool Player::reg()
{
    char tmp = ' ';
    int buf[8];
    QTextStream sbstream(&cmd);

    /*if(echoCommand) {
        cout << cmd.toStdString();
    }*/
    if(cmd.length() != 16) {
        cout << "\033[1;32;31mDeck registration error: command format error.\033[m" << endl;
        return false;
    }
    for(int i = 0;i < 8;++i) {

        /* get next minion */
        do {
            sbstream >> tmp;
        } while(tmp == ' ');

        /* char to int */
        buf[i] = tmp - '0';

        if(buf[i] < 1 || enabled[buf[i] - 1] != '1') {
            cout << "\033[1;32;31mDeck registration error: no such minion.\033[m" << endl;
            return false;
        }
        for(int j = 0;j < i;j++) {
            if(buf[i] == buf[j]) {
                cout << "\033[1;32;31mDeck registration error: duplicated minion.\033[m" << endl;
                return false;
            }
        }
    }

    for(int i = 0;i < 4;i++) {
        deck[i] = buf[i];
        todraw[i] = buf[i + 4];
    }
    cout << "\033[1;32;32mDeck registration success.\033[m" << endl;
    cmd.clear();
    ready = true;

    return true;
}

void Player::addMana(int amount)
{
    mana += amount;
    if(mana > 10) mana = 10;
}

void Player::readCommand()
{
    cmd += readAllStandardOutput();
}
