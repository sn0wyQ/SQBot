#include "game.h"

Game::Game(const Json& game)
  : title(SQBot::Utils::GetValue<std::string>(game, "title")),
    description(SQBot::Utils::GetValue<std::string>(game, "description")),
    photo(SQBot::Utils::GetPtrsArray<PhotoSize>(game, "photo")),
    text(SQBot::Utils::GetValue<std::string>(game, "text")),
    text_entities(SQBot::Utils::GetPtrsArray<MessageEntity>(game, "text_entities")),
    animation(SQBot::Utils::GetPtr<Animation>(game, "animation")) {}
