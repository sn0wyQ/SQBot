#ifndef INCLUDE_SQBOT_UTILS_UTILS_H_
#define INCLUDE_SQBOT_UTILS_UTILS_H_

#include <iostream>
#include <memory>
#include <string>

#include "json.h"

namespace Utils {

template<typename T>
T GetValue(const Json& json, const std::string& key) {
  if (!json.contains(key)) {
    return T();
  }

  try {
    return json.at(key);
  } catch (std::exception& e) {
    throw e;
  }
}

template<typename T>
std::shared_ptr<T> GetPtr(const Json& json, const std::string& key) {
  if (!json.contains(key)) {
    return {};
  }

  try {
    return std::make_shared<T>(json.at(key));
  } catch (std::exception& e) {
    throw e;
  }
}

}  // namespace Utils

#endif  // INCLUDE_SQBOT_UTILS_UTILS_H_
