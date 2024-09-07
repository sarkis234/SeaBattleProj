#include <iostream>
using namespace std;

void fillGrid(char playerGrid[8][8], char botGrid[8][8], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            playerGrid[i][j] = ' ';
            botGrid[i][j] = ' ';
        }
    }
}
void showPlayerGrid(char playerGrid[8][8], int size) {
    cout << "    1 | 2 | 3 | 4 | 5 | 6 | 7 | 8" << endl;
    for (int i = 0; i < 35; i++) {
        cout << "_";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1;
        for (int j = 0; j < size; j++) {
            cout << " | " << playerGrid[i][j];
        }
        cout << " |";
        cout << endl;
    }
    cout << endl;
}
void showBotGrid(char botGrid[8][8], int size) {
    cout << "    1 | 2 | 3 | 4 | 5 | 6 | 7 | 8" << endl;
    for (int i = 0; i < 35; i++) {
        cout << "_";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1;
        for (int j = 0; j < size; j++) {
            cout << " | ";
            if (botGrid[i][j] != '+') {
                cout << botGrid[i][j];
            }
            else {
                cout << " ";
            }
        }
        cout << " |";
        cout << endl;
    }
    cout << endl;
}
void placeShipsOne(char playerGrid[8][8], int size) {
    cout << "Для начала расставьте четыре однопалубных корабля ";
    int a, b;
    for (int i = 0; i < 4; i++) {
        cin >> a >> b;
        if (a > 8 || a < 1 || b > 8 || b < 1) {
            cout << "Координата должна быть от одного до восьми" << endl;
            cout << "Попробуйте другие координаты ";
            i--;
            continue;
        }
        if (playerGrid[a - 2][b - 1] == '+' || playerGrid[a - 1][b - 2] == '+' && b != 1 || playerGrid[a][b - 1] == '+'
            || playerGrid[a - 1][b] == '+' && b != 8 || playerGrid[a - 1][b - 1] == '+') {
            i--;
            cout << "Вы не можете расположить корабль рядом с другим кораблем" << endl;
            cout << "Попробуйте другие координаты ";
            continue;
        }
        playerGrid[a - 1][b - 1] = '+';
        showPlayerGrid(playerGrid, size);
    }
    system("cls");
}
void placeShipsTwo(char playerGrid[8][8], int size) {
    cout << "Теперь расставьте три двухпалубных корабля ";
    int a, b, c, d;
    for (int i = 0; i < 3; i++) {
        cin >> a >> b >> c >> d;
        if (a > 8 || a < 1 || b > 8 || b < 1 || c > 8 || c < 1 || d > 8 || d < 1) {
            cout << "Координата должна быть от одного до восьми" << endl;
            cout << "Попробуйте другие координаты ";
            i--;
            continue;
        }
        if (c == a && b != d - 1 && b != d + 1 || b == d && a != c - 1 && a != c + 1 || b != d && a != c) {
            i--;
            cout << "Вы не можете расположить корабль таким образом" << endl;
            cout << "Попробуйте другие координаты ";
            continue;
        }
        else if (playerGrid[a - 2][b - 1] == '+' || playerGrid[a - 1][b - 2] == '+' && b != 1 || playerGrid[a][b - 1] == '+' || playerGrid[a - 1][b] == '+' && b != 8 
            || playerGrid[a - 1][b - 1] == '+' || playerGrid[c - 2][d - 1] == '+' || playerGrid[c - 1][d - 2] == '+'  && d != 1 || playerGrid[c][d - 1] == '+' 
            || playerGrid[c - 1][d] == '+' && d != 8 || playerGrid[c - 1][d - 1] == '+') {
            i--;
            cout << "Вы не можете расположить корабль рядом с другим кораблем" << endl;
            cout << "Попробуйте другие координаты ";
            continue;
        }
        else {
            playerGrid[a - 1][b - 1] = '+';
            playerGrid[c - 1][d - 1] = '+';
            showPlayerGrid(playerGrid, size);
        }
    }
    system("cls");
}
void placeShipsThree(char playerGrid[8][8], int size) {
    int a, b, c, d;
    cout << "Теперь поставьте один трех палубный корабль(введите две крайние координаты корабля) ";
    for (int i = 0; i < 1; i++) {
        cin >> a >> b >> c >> d;
        if (a > 8 || a < 1 || b > 8 || b < 1 || c > 8 || c < 1 || d > 8 || d < 1) {
            cout << "Координата должна быть от одного до восьми" << endl;
            cout << "Попробуйте другие координаты ";
            i--;
            continue;
        }
        if (c == a && b != d - 2 && b != d + 2 || b == d && a != c - 2 && a != c + 2 || b != d && a != c) {
            i--;
            cout << "Вы не можете расположить корабль таким образом " << endl;
            cout << "Попробуйте другие координаты ";
            continue;
        }
        else {
            if (a == c) { // горизантально
                if (b > d) swap(b, d);
                if (playerGrid[a - 1][b - 2] == '+' && b != 1 || playerGrid[a - 2][b - 1] == '+' || playerGrid[a][b - 1] == '+' || playerGrid[a - 2][b] == '+' 
                    && b != 8 || playerGrid[a][b] == '+' && b != 8 || playerGrid[a - 1][b - 1] == '+' || playerGrid[c - 1][d - 1] == '+' 
                    || playerGrid[c - 1][d] == '+' && d != 8 || playerGrid[c - 2][d - 1] == '+' || playerGrid[c][d - 1] == '+') {
                    i--;
                    cout << "Вы не можете расположить корабль рядом с другим кораблем " << endl;
                    cout << "Попробуйте другие координаты ";
                    continue;
                }
                else {
                    playerGrid[a - 1][b - 1] = '+';
                    playerGrid[c - 1][d - 1] = '+';
                    if (b > d) swap(b, d);
                    playerGrid[a - 1][b] = '+';
                }
            }
            else {  // вертикально
                if (a > c) swap(a, c);
                if (playerGrid[a - 2][b - 1] == '+' || playerGrid[a - 1][b - 2] == '+' && b != 1 || playerGrid[a - 1][b] == '+' && b != 8 
                    || playerGrid[a][b - 2] == '+' && b != 1 || playerGrid[a][b] == '+' && b != 8 || playerGrid[a - 1][b - 1] == '+' 
                    || playerGrid[c - 1][d - 1] == '+' || playerGrid[c][d - 1] == '+' || playerGrid[c - 1][d - 2] == '+' && d != 1 || playerGrid[c - 1][d] == '+' 
                    && b != 8) {
                    i--;
                    cout << "Вы не можете расположить корабль рядом с другим кораблем " << endl;
                    cout << "Попробуйте другие координаты ";;
                    continue;
                }
                else {
                    playerGrid[a - 1][b - 1] = '+';
                    playerGrid[c - 1][d - 1] = '+';
                    if (a > c) swap(a, c);
                    playerGrid[a][b - 1] = '+';
                }
            }
        }
    }
    system("cls");
}
void placeShipsBotThree(char botGrid[8][8], int size) {
    int a, b;
    int direction;
    for (int i = 0; i < 1; i++) {
        a = rand() % 8;
        b = rand() % 8;
        direction = 1 + rand() % 6;
        switch (direction) {
        case 1: // слева направо
            if (b > 5) {
                i--;
                continue;
            }
            else {
                for (int j = 0; j < 3; j++) {
                    botGrid[a][b + j] = '+';
                }
                break;
            }
        case 2: // справа налево
            if (b < 2) {
                i--;
                continue;
            }
            else {
                for (int j = 2; j >= 0; j--) {
                    botGrid[a][b - j] = '+';
                }
                break;
            }
        case 3: // сверху вниз
            if (a > 5) {
                i--;
                continue;
            }
            else {
                for (int j = 0; j < 3; j++) {
                    botGrid[a + j][b] = '+';
                }
                break;
            }
        case 4: // снизу вверх
            if (a < 2) {
                i--;
                continue;
            }
            else {
                for (int j = 2; j >= 0; j--) {
                    botGrid[a - j][b] = '+';
                }
                break;
            }
        case 5: // горизантально в центре
            if (b == 0 || b == 7) {
                i--;
                continue;
            }
            else {
                for (int j = -1; j < 2; j++) {
                    botGrid[a][b + j] = '+';
                }
                break;
            }
        case 6: // вертикально в центре
            if (a == 0 || a == 7) {
                i--;
                continue;
            }
            else {
                for (int j = -1; j < 2; j++) {
                    botGrid[a + j][b] = '+';
                }
                break;
            }
        }
    }
}
void placeShipsBotTwo(char botGrid[8][8], int size) {
    int a, b;
    int direction;
    for (int i = 0; i < 3; i++) {
        a = rand() % 8;
        b = rand() % 8;
        if (botGrid[a][b] == '+' || botGrid[a + 1][b] == '+' || botGrid[a - 1][b] == '+' || botGrid[a][b + 1] == '+' && b != 7 || botGrid[a][b - 1] == '+') {
            i--;
            continue;
        }
        direction = 1 + rand() % 4;
        switch (direction) {
        case 1: // слева направо
            if (b == 7) {
                i--;
                continue;
            }
            else if (botGrid[a - 1][b + 1] == '+' || botGrid[a + 1][b + 1] == '+' || botGrid[a][b + 2] == '+') {
                i--;
                continue;
            }
            else {
                for (int j = 0; j < 2; j++) {
                    botGrid[a][b + j] = '+';
                }
                break;
            }
        case 2: // справа налево
            if (b == 0) {
                i--;
                continue;
            }
            else if (botGrid[a + 1][b - 1] == '+' || botGrid[a - 1][b - 1] == '+' || botGrid[a][b - 2] == '+') {
                i--;
                continue;
            }
            else {
                for (int j = 1; j >= 0; j--) {
                    botGrid[a][b - j] = '+';
                }
                break;
            }
        case 3: // сверху вниз
            if (a == 7) {
                i--;
                continue;
            }
            else if (botGrid[a + 1][b - 1] == '+' || botGrid[a + 1][b + 1] == '+' && b != 7 || botGrid[a + 2][b] == '+') {
                i--;
                continue;
            }
            else {
                for (int j = 0; j < 2; j++) {
                    botGrid[a + j][b] = '+';
                }
                break;
            }
        case 4: // снизу вверх
            if (a == 0) {
                i--;
                continue;
            }
            else if (botGrid[a - 1][b - 1] == '+' || botGrid[a - 1][b + 1] == '+' && b != 7 || botGrid[a - 2][b] == '+') {
                i--;
                continue;
            }
            else {
                for (int j = 1; j >= 0; j--) {
                    botGrid[a - j][b] = '+';
                }
                break;
            }
        }
    }
}
void placeShipsBotOne(char botGrid[8][8], int size) {
    int a, b;
    for (int i = 0; i < 4; i++) {
        a = rand() % 8;
        b = rand() % 8;
        if (botGrid[a][b] == '+' || botGrid[a + 1][b] == '+' || botGrid[a - 1][b] == '+' || botGrid[a][b + 1] == '+' && b != 7 || botGrid[a][b - 1] == '+') {
            i--;
            continue;
        }
        else {
            botGrid[a][b] = '+';
        }
    }
}
void placeShipsAll(char playerGrid[8][8], int size) {
    placeShipsOne(playerGrid, size);
    showPlayerGrid(playerGrid, size);
    placeShipsTwo(playerGrid, size);
    showPlayerGrid(playerGrid, size);
    placeShipsThree(playerGrid, size);
}
void placeShipsBots(char botGrid[8][8], int size) {
    placeShipsBotThree(botGrid, size);
    placeShipsBotTwo(botGrid, size);
    placeShipsBotOne(botGrid, size);
}
void startGame(char playerGrid[8][8], char botGrid[8][8], int size) {
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    fillGrid(playerGrid, botGrid, size);
    showPlayerGrid(playerGrid, size);
    char automatic;
    cout << "Добро пожаловать в игру морской бой" << endl;
    cout << "Чтобы начать игру, вам нужно расставить ваши корабли(первое введенное число-горизонталь, второе-вертикаль)" << endl;
    cout << "Хотите, чтобы ваши корабли расставились автоматически?(y/n): ";
    cin >> automatic;
    if (automatic == 'y') {
        placeShipsBots(playerGrid, size);
    }
    else {
        placeShipsAll(playerGrid, size);
    }
    placeShipsBots(botGrid, size);
    system("cls");
}
void showBothGrids(char playerGrid[8][8], char botGrid[8][8], int size) {
    cout << "Ваше поле: " << endl;
    showPlayerGrid(playerGrid, size);
    cout << "Поле противника: " << endl;
    showBotGrid(botGrid, size);
}
void checkShip(char Grid[8][8], int a, int b) {
    if (Grid[a][b - 1] == '+' || Grid[a - 1][b] == '+' && b != 8 || Grid[a - 1][b - 2] == '+' && b != 1 || Grid[a - 2][b - 1] == '+') {
        cout << "Попал!" << endl;
    }
    else {
        if (Grid[a][b - 1] == '#' && Grid[a + 1][b - 1] == '+') {
            cout << "Попал!" << endl;
        }
        else if (Grid[a - 1][b] == '#' && Grid[a - 1][b + 1] == '+' && b <= 6) {
            cout << "Попал!" << endl;
        }
        else if (Grid[a - 1][b - 2] == '#' && Grid[a - 1][b - 3] == '+' && b >= 3) {
            cout << "Попал!" << endl;
        }
        else if (Grid[a - 2][b - 1] == '#' && Grid[a - 3][b - 1] == '+') {
            cout << "Попал!" << endl;
        }
        else {
            cout << "Убил!" << endl;
        }
    }
}
void shootShipsPlayer(char botGrid[8][8], int size, int& count, char playerGrid[8][8]) {
    int a, b;
    for (int i = 0; i < 1; i++) {
        showBothGrids(playerGrid, botGrid, size);
        cout << "Выберите координату, в которую хотите выстрелить ";
        cin >> a >> b;
        if (a > 8 || a < 1 || b > 8 || b < 1) {
            cout << "Координата должна быть от одного до восьми" << endl;
            cout << "Попробуйте другие координаты " << endl;
            i--;
            continue;
        }
        if (botGrid[a - 1][b - 1] == '#' || botGrid[a - 1][b - 1] == '-') {
            cout << "Вы уже стреляли по этим координатам!" << endl;
            cout << "Попробуйте другие координаты " << endl;
            i--;
            continue;
        }
        system("cls");

        if (botGrid[a - 1][b - 1] == '+') {
            botGrid[a - 1][b - 1] = '#';
            count++;
            checkShip(botGrid, a, b);
            if (count == 13) {
                break;
            }
            i--;
            continue;
        }
        else {
            cout << "Мимо!" << endl;
            botGrid[a - 1][b - 1] = '-';
        }
    }
    
}
void shootShipsBot(char playerGrid[8][8], int size, int& count) {
    int a = 1, b = 1;
    for (int i = 0; i < 1; i++) {
        a = 1 + rand() % 8, b = 1 + rand() % 8;
        if (playerGrid[a - 1][b - 1] == '#' || playerGrid[a - 1][b - 1] == '-' || playerGrid[a][b - 1] == '#' || playerGrid[a - 1][b] == '#' && b != 8
            || playerGrid[a - 1][b - 2] == '#' && b != 1 || playerGrid[a - 2][b - 1] == '#' && playerGrid[a - 1][b - 1] != '+') {
            i--;
            continue;
        }
        
        cout << "Противник выстрелил в координату " << a << " " << b << endl;
        if (playerGrid[a - 1][b - 1] == '+') {
            playerGrid[a - 1][b - 1] = '#';
            count++;
            checkShip(playerGrid, a, b);
            if (count == 13) {
                break;
            }
            i--;
            continue;
        }
        else {
            cout << "Мимо!" << endl;
            playerGrid[a - 1][b - 1] = '-';
        }
    }
    // Функция для 100% попадания бота
    /*while (playerGrid[a - 1][b - 1] != '+') {
        b++;
        if (b == 9) {
            a++;
            b = 1;
        }
    }
    cout << "Противник выстрелил в координату " << a << " " << b << endl;
    if (playerGrid[a - 1][b - 1] == '+') {
        playerGrid[a - 1][b - 1] = '#';
        count++;
        checkShip(playerGrid, a, b);
    }*/
    
}
void shootShips(char playerGrid[8][8], char botGrid[8][8], int size) {
    int countPlayer = 0, countBot = 0;
    while (true) {
        shootShipsPlayer(botGrid, size, countPlayer, playerGrid);
        if (countPlayer == 13) {
            cout << "Вы выиграли!" << endl;
            cout << "Ваше поле: " << endl;
            showPlayerGrid(playerGrid, size);
            cout << "Поле противника: " << endl;
            showPlayerGrid(botGrid, size);
            break;
        }
        shootShipsBot(playerGrid, size, countBot);
        if (countBot == 13) {
            cout << "Вы проиграли!" << endl;
            cout << "Ваше поле: " << endl;
            showPlayerGrid(playerGrid, size);
            cout << "Поле противника: " << endl;
            showPlayerGrid(botGrid, size);
            break;
        }
    }
}
int main()
{   
    const int SIZE = 8;
    char playerGrid[SIZE][SIZE];
    char botGrid[SIZE][SIZE];
    startGame(playerGrid, botGrid, SIZE);
    shootShips(playerGrid, botGrid, SIZE);
}