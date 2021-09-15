#include "../../include/SQBot/API/passport_data.h"

PassportData::PassportData(const Json& passport_data)
  : data(SQBot::Utils::GetPtrsArray<EncryptedPassportElement>(
        passport_data, "data")),
    credentials(SQBot::Utils::GetPtr<EncryptedCredentials>(
        passport_data, "credentials")) {}
