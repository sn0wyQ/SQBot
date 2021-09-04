#ifndef INCLUDE_SQBOT_UTILS_UTILS_H_
#define INCLUDE_SQBOT_UTILS_UTILS_H_

#include <memory>
#include <string>

#include "json.h"

namespace Utils {

template<typename T>
T GetValue(const Json& sender, const std::string& key) {
  if (!sender.contains(key)) {
    return T();
  }

  try {
    return sender.at(key);
  } catch (std::exception& e) {
    throw e;
  }
}

template<typename T>
std::shared_ptr<T> Default() {
  return std::make_shared<T>();
}

}  // namespace Utils

#endif  // INCLUDE_SQBOT_UTILS_UTILS_H_
