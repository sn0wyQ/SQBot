#include "exception.h"

namespace SQBot {

Exception::Exception(ExceptionType type, const std::string& short_description) {
  assert(type < static_cast<ExceptionType>(0)
         || type > ExceptionType::kNumberOfExceptionTypes);

  type_ = type;
  description_ = "[SQBot] "
      + exception_types_strings[static_cast<int32_t>(type_)]
      + ": " + short_description;
}

const char* Exception::what() const noexcept {
  return description_.c_str();
}

}  // namespace SQBot
