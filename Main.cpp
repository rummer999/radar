//Nika.cpp
#include <algorithm>
#include <sys/uio.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <thread>
#include <X11/Xatom.h>
#include <X11/Xft/Xft.h>
#include <random>
#include <fstream>
#include <sys/stat.h>
#include <cctype>
#include <locale>
#include <stdint.h>
#include <iterator>
#include <iomanip>
#include "Vector2D.hpp"
#include "Vector3D.hpp"
#include "Memory.hpp"
#include "Offsets.hpp"
#include "Level.hpp"
#include "Radar.cpp"

int main(int argc, char *argv[]) {
    if (getuid()) { std::cout << "RUN AS SUDO!\n"; return -1; }
    if (Memory::GetPID() == 0) { std::cout << "OPEN THE GAME FIRST!\n"; return -1; }
    MyDisplay* xDisplay = new MyDisplay();
    Level* Map = new Level();
    LocalPlayer* Myself = new LocalPlayer();
    std::vector<Player*>* HumanPlayers = new std::vector<Player*>;
    std::vector<Player*>* Dummies = new std::vector<Player*>;
    std::vector<Player*>* Players = new std::vector<Player*>;
    for (int i = 0; i < 70; i++) HumanPlayers->push_back(new Player(i, Myself));
    for (int i = 0; i < 12000; i++) Dummies->push_back(new Player(i, Myself));
    Radar* radar = new Radar(xDisplay, Map, Myself, Players);

    int counter = 0;

    while (1) {
        Map->Read();
        Myself->Read();

        Players->clear();
        if (Map->IsFiringRange)
            for (int i = 0; i < Dummies->size(); i++) {
                Player* p = Dummies->at(i);
                p->Read();
                if (p->IsValid()) Players->push_back(p);
            }
        else
            for (int i = 0; i < HumanPlayers->size(); i++) {
                Player* p = HumanPlayers->at(i);
                p->Read();
                if (p->IsValid()) Players->push_back(p);
            }

        radar->processEvents(counter);
        radar->repaint();
    }
}

