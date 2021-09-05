#include "encrypted_credentials.h"

EncryptedCredentials::EncryptedCredentials(const Json& encrypted_credentials)
  : data(Utils::GetValue<std::string>(encrypted_credentials, "data")),
    hash(Utils::GetValue<std::string>(encrypted_credentials, "hash")),
    secret(Utils::GetValue<std::string>(encrypted_credentials, "secret")) {}
