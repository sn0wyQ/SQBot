#include "utils.h"

bool Utils::StartsWith(const std::string& text, const std::string& prefix) {
  if (text.length() < prefix.length()) {
    return false;
  }

  for (int i = 0; i < prefix.length(); ++i) {
    if (text[i] != prefix[i]) {
      return false;
    }
  }

  return true;
}
