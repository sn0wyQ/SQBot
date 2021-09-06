#ifndef INCLUDE_SQBOT_API_PASSPORTDATA_PASSPORT_DATA_H_
#define INCLUDE_SQBOT_API_PASSPORTDATA_PASSPORT_DATA_H_

#include <memory>
#include <vector>

#include "../../../nlohmann/json.h"

#include "../EncryptedCredentials/encrypted_credentials.h"
#include "../EncryptedPassportElement/encrypted_passport_element.h"

#include "../../Utils/utils.h"

// Contains information about Telegram Passport data
// shared with the bot by the user
class PassportData {
 public:
  PassportData() = default;
  explicit PassportData(const Json& passport_data);

  // Array with information about documents and other Telegram Passport elements
  // that was shared with the bot
  std::vector<std::shared_ptr<EncryptedPassportElement>> data;

  // Encrypted credentials required to decrypt the data
  std::shared_ptr<EncryptedCredentials> credentials;
};

#endif  // INCLUDE_SQBOT_API_PASSPORTDATA_PASSPORT_DATA_H_
