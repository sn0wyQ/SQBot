#include "game.h"

Game::Game(const Json& game)
  : title(Utils::GetValue<std::string>(game, "title")),
    description(Utils::GetValue<std::string>(game, "description")),
    text(Utils::GetValue<std::string>(game, "text")),
    animation(Utils::GetPtr<Animation>(game, "animation")) {
  // TODO(sn0wyQ): set 'std::vector<PhotoSize> photo'
  // TODO(sn0wyQ): set 'std::vector<MessageEntity> text_entities'
}
