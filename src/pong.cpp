#include <SFML/Window.hpp>
#include "pong.h"

namespace Pong {
  Pong::Pong() : _window(NULL) {
  }

  Pong::~Pong() {
    delete _window;
  }

  void Pong::init(int argc, char *argv[]) {
    int width = 800;
    int height = 600;
    int bpp = 32;

    /* Initialize SFML */
    _window = new sf::Window(sf::VideoMode(width, height, bpp), "Pong!");
  }

  int Pong::run() {
    while(_running) {
      render();
      process();

      sf::Sleep(50);
    }

    return 0;
  }

  void Pong::render() {
    _window->Display();
  }

  void Pong::process() {
    sf::Event event;

    while(_window->PollEvent(event)) {
      if(event.Type == sf::Event::Closed)
        _running = false;
    }
  }
}
