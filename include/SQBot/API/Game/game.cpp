#include "game.h"

Game::Game(const Json& game)
  : title(Utils::GetValue<std::string>(game, "title")),
    description(Utils::GetValue<std::string>(game, "description")),
    photo(Utils::GetPtrsArray<PhotoSize>(game, "photo")),
    text(Utils::GetValue<std::string>(game, "text")),
    text_entities(Utils::GetPtrsArray<MessageEntity>(game, "text_entities")),
    animation(Utils::GetPtr<Animation>(game, "animation")) {}
