#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

#ifdef _WIN32
#define CLEAR() system("cls")
#else
#define CLEAR() system("clear")
#endif

// Véletlen egész szám generálása [min, max)
int randInt(int min, int max) {
    return rand() % (max - min) + min;
}

class Board {
public:
    int width, height;
    int ballx, bally;
    int xdir, ydir;

    Board(int w, int h)
        : width(w), height(h), xdir(1), ydir(1)
    {
        // Labda kezdőpozíciójának beállítása:
        ballx = randInt(1, width - 1);
        bally = randInt(1, height - 1);
    }

    void update() {
        if (ballx <= 0 || ballx >= width) xdir = -xdir;
        if (bally <= 0 || bally >= height) ydir = -ydir;
        ballx += xdir;
        bally += ydir;
    }

    void draw() const {
        cout << "Width: " << width << " Height: " << height << "\n";
        cout << " ";
        for (int i = 0; i < width + 2; i++) cout << "-";
        cout << "\n";
        for (int i = 0; i < height + 2; i++) {
            cout << "|";
            for (int j = 0; j < width + 2; j++)
                cout << ((i == bally && j == ballx) ? "O" : " ");
            cout << "|\n";
        }
        cout << " ";
        for (int i = 0; i < width + 2; i++) cout << "-";
        cout << "\n";
    }
};

int main() {
    srand(time(0));

    int w = randInt(5, 100);
    int h = randInt(5, 30);
    Board board(w, h);

    board.draw();
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(100));
        CLEAR();
        board.update();
        board.draw();
    }
}
