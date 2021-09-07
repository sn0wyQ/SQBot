#include "utils.h"

bool SQBot::Utils::StartsWith(
    const std::string& text, const std::string& prefix) {
  if (text.length() < prefix.length()) {
    return false;
  }

  for (size_t i = 0; i < prefix.length(); ++i) {
    if (text[i] != prefix[i]) {
      return false;
    }
  }

  return true;
}

std::string SQBot::Utils::GetFirstWord(const std::string& text) {
  std::string result;

  for (auto character : text) {
    if (std::isspace(character)) {
      if (!result.empty()) {
        return result;
      }
    } else {
      result += character;
    }
  }

  return result;
}

