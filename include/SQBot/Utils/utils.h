#ifndef UTILS_H_
#define UTILS_H_

#include "json.h"

namespace Utils {

template<typename T>
bool GetValue(T* receiver, const Json& sender, const std::string& key) {
  if (!sender.contains(key)) {
    *receiver = T();
    return false;
  }

  try {
    *receiver = sender.at(key);
  } catch (std::exception& e) {
    throw e;
  }

  return true;
}

}  // namespace Utils

#endif  // UTILS_H_
