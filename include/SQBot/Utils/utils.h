#ifndef UTILS_H_
#define UTILS_H_

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

}  // namespace Utils

#endif  // UTILS_H_
