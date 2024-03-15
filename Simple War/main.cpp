#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

#define CKiri 75
#define CKanan 77
#define CBawah 80
#define CAtas 72

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Armi {
private:
    int FX, FY;
public:
    Armi(int x = 40, int y = 23) : FX(x), FY(y) {}
    void Gambar() {
        gotoxy(FX, FY);
        std::cout << (char)153;
        gotoxy(FX + 1, FY);
        std::cout << (char)205;
        gotoxy(FX + 2, FY);
        std::cout << (char)205;

        gotoxy(FX - 1, FY);
        std::cout << (char)205;
        gotoxy(FX - 2, FY);
        std::cout << (char)205;

        gotoxy(FX, FY + 1);
        std::cout << (char)219;
        gotoxy(FX, FY + 2);
        std::cout << (char)215;
        gotoxy(FX, FY + 3);
        std::cout << (char)219;
    }
    void Hapus() {
        gotoxy(FX, FY);
        std::cout << ' ';
        gotoxy(FX + 1, FY);
        std::cout << ' ';
        gotoxy(FX + 2, FY);
        std::cout << ' ';

        gotoxy(FX - 1, FY);
        std::cout << ' ';
        gotoxy(FX - 2, FY);
        std::cout << ' ';

        gotoxy(FX, FY + 1);
        std::cout << ' ';
        gotoxy(FX, FY + 2);
        std::cout << ' ';
        gotoxy(FX, FY + 3);
        std::cout << ' ';
    }
    void GoArahX(int x) {
        Hapus();
        FX += x;
        if (FX < 5) FX = 5;
        if (FX > 75) FX = 75;
        Gambar();
    }
    void GoArahY(int y) {
        Hapus();
        FY += y;
        if (FY < 5) FY = 5;
        if (FY > 75) FY = 75;
        Gambar();
    }
};

int main() {
    Armi armi;
    char c;

    std::cout << "Score : ";

    // Menampilkan objek "Armi" awal
    armi.Gambar();

    while (true) {
        if (_kbhit()) {
            c = _getch();
            if (c == 0 || c == -32) {
                c = _getch();
                switch (c) {
                    case CKiri:  // Tombol panah kiri
                        armi.GoArahX(-1);
                        break;
                    case CKanan:  // Tombol panah kanan
                        armi.GoArahX(1);
                        break;
                    case CAtas:  // Tombol panah Atas
                        armi.GoArahY(-1);
                        break;
                    case CBawah:  // Tombol panah bawah
                        armi.GoArahY(1);
                        break;
                }
            }
        }
    }

    return 0;
}
