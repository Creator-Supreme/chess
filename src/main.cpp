#include <SFML/Graphics.hpp>
#include "main.hpp"

int main() {

  window_handler window_handle;

  asset_list assets;

  while (window_handle.current().isOpen()) {
    while (const std::optional event{window_handle.current().pollEvent()}) {
      if (event->is<sf::Event::Closed>()) {
        window_handle.current().close();
      } else if (event->is<sf::Event::Resized>()) {

        sf::FloatRect view(
            {0, 0},
            {static_cast<float>(event->getIf<sf::Event::Resized>()->size.x),
             static_cast<float>(event->getIf<sf::Event::Resized>()->size.y)});
        window_handle.current().setView(sf::View(view));

        sf::Vector2u size{window_handle.current().getSize()};
        assets[BOARD_BLACK_PERSPECTIVE].setPosition(
            {static_cast<float>(size.x) / 2, static_cast<float>(size.y) / 2});
        assets[BOARD_WHITE_PERSPECTIVE].setPosition(
            {static_cast<float>(size.x) / 2, static_cast<float>(size.y) / 2});
      }
    }
    window_handle.current().clear(sf::Color::Cyan);

    window_handle.current().draw(assets[BOARD_BLACK_PERSPECTIVE]);

    window_handle.current().display();
  }

  return 0;
}
