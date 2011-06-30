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
    loop();

    return 0;
  }

  void Pong::loop() {
    const int TICKS_PER_SECOND = 25;
    const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
    const int MAX_FRAMESKIP = 5;

    sf::Clock clock;
    int nextGameTick = clock.GetElapsedTime();
    int loopCount;
    float interpolation;

    while(_running) {
      loopCount = 0;
      while(clock.GetElapsedTime() > nextGameTick && loopCount < MAX_FRAMESKIP) {
        update();

        nextGameTick += SKIP_TICKS;
        loopCount++;
      }

      interpolation = float(clock.GetElapsedTime() + SKIP_TICKS - nextGameTick)
                      / float(SKIP_TICKS);
      render(interpolation);
    }
  }

  void Pong::update() {
    process();
  }

  void Pong::render(float interpolation) {
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
