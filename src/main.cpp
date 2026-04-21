#include "main.hpp"
#include <SFML/Graphics.hpp>

int main() {

  windowHandle windowWrapper;
  assetList assets;

  while (windowWrapper.current().isOpen()) {
    while (const std::optional event{windowWrapper.current().pollEvent()}) {
      if (event->is<sf::Event::Closed>()) {
        windowWrapper.current().close();
      }
      if (event->is<sf::Event::Resized>()) {
        windowWrapper.onWindowResize(event);
        assets.onWindowResize(windowWrapper);
      }
    }

    windowWrapper.current().clear(windowWrapper.bakgroundColor());

    switch (windowWrapper.getCurrentState()) {
    case STATE::MENU:
      break;
    case STATE::PLAY:
      break;
    }

    windowWrapper.current().display();
  }

  return 0;
}
