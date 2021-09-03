#ifndef ENCRYPTED_CREDENTIALS_H_
#define ENCRYPTED_CREDENTIALS_H_

#include <string>

#include "json.h"

#include "../../Utils/utils.h"

// Contains data required for decrypting and authenticating
// EncryptedPassportElement. See the Telegram Passport Documentation for a
// complete description of the data decryption and authentication processes:
// https://core.telegram.org/passport#receiving-information
class EncryptedCredentials {
 public:
  EncryptedCredentials() = default;
  explicit EncryptedCredentials(const Json& encrypted_credentials);

  // Base64-encoded encrypted JSON-serialized data with unique user's payload,
  // data hashes and secrets required for EncryptedPassportElement
  // decryption and authentication
  std::string data;

  // Base64-encoded data hash for data authentication
  std::string hash;

  // Base64-encoded secret, encrypted with the bot's public RSA key,
  // required for data decryption
  std::string secret;
};

#endif  // ENCRYPTED_CREDENTIALS_H_
