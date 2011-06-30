#include "pong.h"

int main(int argc, char* argv[]) {
 Pong::Pong game;

 game.init(argc, argv);
 return game.run();
}
