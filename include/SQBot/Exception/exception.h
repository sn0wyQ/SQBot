#ifndef INCLUDE_SQBOT_EXCEPTION_EXCEPTION_H_
#define INCLUDE_SQBOT_EXCEPTION_EXCEPTION_H_

#include <array>
#include <cassert>
#include <exception>
#include <string>

namespace SQBot {

enum class ExceptionType {
  kCurlError = 0,
  kImpossibleToStopSafely,
  kRequestError,
  kUndefinedBehaviour,

  kNumberOfExceptionTypes
};

const std::array<std::string,
                  static_cast<int32_t>(ExceptionType::kNumberOfExceptionTypes)>
    exception_types_strings {
  "Curl error",
  "Impossible to stop safely",
  "Request error",
  "Undefined behaviour"
};

class Exception : std::exception {
 public:
  Exception(ExceptionType type, const std::string& short_description);

  const char* what() const noexcept override;

 private:
  ExceptionType type_;
  std::string description_;
};

}  // namespace SQBot

#endif  // INCLUDE_SQBOT_EXCEPTION_EXCEPTION_H_
