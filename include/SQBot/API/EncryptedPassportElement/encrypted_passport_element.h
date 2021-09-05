#ifndef INCLUDE_SQBOT_API_ENCRYPTEDPASSPORTELEMENT_ENCRYPTED_PASSPORT_ELEMENT_H_
#define INCLUDE_SQBOT_API_ENCRYPTEDPASSPORTELEMENT_ENCRYPTED_PASSPORT_ELEMENT_H_

#include <memory>
#include <string>
#include <vector>

#include "json.h"

#include "../PassportFile/passport_file.h"

#include "../../Utils/utils.h"

// Contains information about documents or other Telegram Passport elements
// shared with the bot by the user
class EncryptedPassportElement {
 public:
  EncryptedPassportElement() = default;
  explicit EncryptedPassportElement(const Json& encrypted_passport_element);

  // Element type. One of “personal_details”, “passport”, “driver_license”,
  // “identity_card”, “internal_passport”, “address”, “utility_bill”,
  // “bank_statement”, “rental_agreement”, “passport_registration”,
  // “temporary_registration”, “phone_number”, “email”
  std::string type;

  // OPTIONAL. Base64-encoded encrypted Telegram Passport element data provided
  // by the user, available for “personal_details”, “passport”,
  // “driver_license”, “identity_card”, “internal_passport” and “address” types.
  // Can be decrypted and verified using the accompanying EncryptedCredentials
  std::string data;

  // OPTIONAL. User's verified phone number,
  // available only for “phone_number” type
  std::string phone_number;

  // OPTIONAL. User's verified email address, available only for “email” type
  std::string email;

  // OPTIONAL. Array of encrypted files with documents provided by the user,
  // available for “utility_bill”, “bank_statement”, “rental_agreement”,
  // “passport_registration” and “temporary_registration” types.
  // Files can be decrypted and verified using
  // the accompanyingEncryptedCredentials
  std::vector<PassportFile> files;

  // OPTIONAL. Encrypted file with the front side of the document,
  // provided by the user. Available for “passport”, “driver_license”,
  // “identity_card” and “internal_passport”. The file can be decrypted
  // and verified using the accompanying EncryptedCredentials
  std::shared_ptr<PassportFile> front_side;

  // OPTIONAL. Encrypted file with the reverse side of the document,
  // provided by the user. Available for “driver_license” and “identity_card”.
  // The file can be decrypted and verified using
  // the accompanying EncryptedCredentials.
  std::shared_ptr<PassportFile> reverse_side;

  // OPTIONAL. Encrypted file with the selfie of the user holding a document,
  // provided by the user; available for “passport”, “driver_license”,
  // “identity_card” and “internal_passport”. The file can be decrypted
  // and verified using the accompanying EncryptedCredentials
  std::shared_ptr<PassportFile> selfie;

  // OPTIONAL. Array of encrypted files with translated versions of documents
  // provided by the user. Available if requested for “passport”,
  // “driver_license”, “identity_card”, “internal_passport”, “utility_bill”,
  // “bank_statement”, “rental_agreement”, “passport_registration”
  // and “temporary_registration” types. Files can be decrypted
  // and verified using the accompanying EncryptedCredentials
  std::vector<std::shared_ptr<PassportFile>> translation;

  // Base64-encoded element hash for using in PassportElementErrorUnspecified
  std::string hash;
};

#endif  // INCLUDE_SQBOT_API_ENCRYPTEDPASSPORTELEMENT_ENCRYPTED_PASSPORT_ELEMENT_H_
