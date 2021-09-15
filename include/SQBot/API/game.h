#ifndef INCLUDE_SQBOT_API_GAME_H_
#define INCLUDE_SQBOT_API_GAME_H_

#include <memory>
#include <string>
#include <vector>

#include "../../nlohmann/json.h"

#include "animation.h"
#include "message_entity.h"
#include "photo_size.h"

#include "../Utils/utils.h"

// This object represents a game. Use BotFather to create and edit games,
// their short names will act as unique identifiers
class Game {
 public:
  Game() = default;
  explicit Game(const Json& game);

  // Title of the game
  std::string title;

  // Description of the game
  std::string description;

  // Photo that will be displayed in the game message in chats
  std::vector<PhotoSizePtr> photo;

  // OPTIONAL. Brief description of the game or high scores included
  // in the game message. Can be automatically edited to include current
  // high scores for the game when the bot calls setGameScore,
  // or manually edited using editMessageText. 0-4096 characters.
  std::string text;

  // OPTIONAL. Special entities that appear in text, such as usernames,
  // URLs, bot commands, etc.
  std::vector<MessageEntityPtr> text_entities;

  // OPTIONAL. Animation that will be displayed in the game message in chats.
  // Upload via BotFather
  AnimationPtr animation;
};

using GamePtr = std::shared_ptr<Game>;

#endif  // INCLUDE_SQBOT_API_GAME_H_
