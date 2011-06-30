#ifndef PONG_H
#define PONG_H

namespace sf {
  class Window;
}

namespace Pong {
  class Pong {
  public:
    Pong();
    ~Pong();

    void init(int argc, char* argv[]);
    int run();

  private:
    void render();
    void process();

  private:
    sf::Window* _window;
    bool _running;
  };
}

#endif
