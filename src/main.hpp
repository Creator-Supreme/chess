#pragma once
#include "../assets/icon.hpp"
#include "../assets/merged.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

enum NAME : char {
  BLACK_BUTTON_NORMAL = 0,
  BLACK_BUTTON_PRESSED = 1,
  BLACK_BUTTON_HOVER = 2,
  WHITE_BUTTON_NORMAL = 3,
  WHITE_BUTTON_PRESSED = 4,
  WHITE_BUTTON_HOVER = 5,
  BOARD_BLACK_PERSPECTIVE = 6,
  WHITE_KING = 7,
  BLACK_KING = 8,
  WHITE_QUEEN = 9,
  BLACK_QUEEN = 10,
  WHITE_BISHOP = 11,
  BLACK_BISHOP = 12,
  WHITE_KNIGHT = 13,
  BLACK_KNIGHT = 14,
  WHITE_ROOK = 15,
  BLACK_ROOK = 16,
  WHITE_PAWN = 17,
  BLACK_PAWN = 18,
  BOARD_WHITE_PERSPECTIVE = 19,
};

class asset_list {
private:
  sf::Texture texture_assets{merged, 36192};
  std::vector<sf::Sprite> assets{
      sf::Sprite{texture_assets, sf::IntRect{{0, 0}, {48, 16}}},
      sf::Sprite{texture_assets, sf::IntRect{{48, 0}, {48, 16}}},
      sf::Sprite{texture_assets, sf::IntRect{{96, 0}, {48, 16}}},
      sf::Sprite{texture_assets, sf::IntRect{{144, 0}, {48, 16}}},
      sf::Sprite{texture_assets, sf::IntRect{{192, 0}, {48, 16}}},
      sf::Sprite{texture_assets, sf::IntRect{{240, 0}, {48, 16}}},
      sf::Sprite{texture_assets, sf::IntRect{{288, 0}, {512, 512}}},
      sf::Sprite{texture_assets, sf::IntRect{{928, 0}, {64, 64}}},
      sf::Sprite{texture_assets, sf::IntRect{{928, 64}, {64, 64}}},
      sf::Sprite{texture_assets, sf::IntRect{{992, 0}, {64, 64}}},
      sf::Sprite{texture_assets, sf::IntRect{{992, 64}, {64, 64}}},
      sf::Sprite{texture_assets, sf::IntRect{{1056, 0}, {64, 64}}},
      sf::Sprite{texture_assets, sf::IntRect{{1056, 64}, {64, 64}}},
      sf::Sprite{texture_assets, sf::IntRect{{1120, 0}, {64, 64}}},
      sf::Sprite{texture_assets, sf::IntRect{{1120, 64}, {64, 64}}},
      sf::Sprite{texture_assets, sf::IntRect{{1184, 0}, {64, 64}}},
      sf::Sprite{texture_assets, sf::IntRect{{1184, 64}, {64, 64}}},
      sf::Sprite{texture_assets, sf::IntRect{{1248, 0}, {64, 64}}},
      sf::Sprite{texture_assets, sf::IntRect{{1248, 64}, {64, 64}}},
      sf::Sprite{texture_assets, sf::IntRect{{1312, 0}, {512, 512}}},
  };

public:
  sf::Sprite &operator[](NAME something) { return this->assets[something]; }
  asset_list() {
    for (sf::Sprite &c : assets) {
      sf::Vector2<float> temp{c.getGlobalBounds().size};
      c.setOrigin({temp.x / 2, temp.y / 2});
    }
  }
};

class window_handler {
private:
  sf::RenderWindow window{sf::VideoMode{{800, 600}}, "Chess"};

public:
  window_handler() {
    sf::VideoMode desktop_size{sf::VideoMode::getDesktopMode()};
    sf::Vector2u window_size{window.getSize()};
    window.setPosition(
        {static_cast<int>((desktop_size.size.x - window_size.x) / 2),
         static_cast<int>((desktop_size.size.y - window_size.y) / 2)});
    window.setFramerateLimit(60);
    window.setIcon(sf::Image{chess_game_sport_svgrepo_com, 884});
  }

  sf::RenderWindow &current() { return window; }
};
