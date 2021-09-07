#include "encrypted_credentials.h"

EncryptedCredentials::EncryptedCredentials(const Json& encrypted_credentials)
  : data(SQBot::Utils::GetValue<std::string>(encrypted_credentials, "data")),
    hash(SQBot::Utils::GetValue<std::string>(encrypted_credentials, "hash")),
    secret(SQBot::Utils::GetValue<std::string>(
        encrypted_credentials, "secret")) {}
