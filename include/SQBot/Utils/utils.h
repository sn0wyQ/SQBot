#ifndef INCLUDE_SQBOT_UTILS_UTILS_H_
#define INCLUDE_SQBOT_UTILS_UTILS_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../../nlohmann/json.h"

namespace Utils {

template<typename T>
T GetValue(const Json& json, const std::string& key) {
  if (!json.contains(key)) {
    return T();
  }

  try {
    return json.at(key);
  } catch (const std::exception& e) {
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
  } catch (const std::exception& e) {
    throw e;
  }
}

template<typename T>
std::vector<T> GetValuesArray(const Json& json, const std::string& key) {
  if (!json.contains(key)) {
    return {};
  }

  try {
    std::vector<T> result;
    const auto& array_in_json = json.at(key);
    for (const auto& value : array_in_json) {
      result.push_back(value);
    }
    return result;
  } catch (const std::exception& e) {
    throw e;
  }
}

template<typename T>
std::vector<std::shared_ptr<T>> GetPtrsArray(const Json& json,
                                             const std::string& key) {
  if (!json.contains(key)) {
    return {};
  }

  try {
    std::vector<std::shared_ptr<T>> result;
    const auto& array_in_json = json.at(key);
    for (const auto& object : array_in_json) {
      result.push_back(std::make_shared<T>(object));
    }
    return result;
  } catch (const std::exception& e) {
    throw e;
  }
}

bool StartsWith(const std::string& text, const std::string& prefix);

}  // namespace Utils

#endif  // INCLUDE_SQBOT_UTILS_UTILS_H_
