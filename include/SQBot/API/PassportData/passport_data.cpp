#include "passport_data.h"

PassportData::PassportData(const Json& passport_data)
  : data(Utils::GetPtrsArray<EncryptedPassportElement>(passport_data, "data")),
    credentials(
      Utils::GetPtr<EncryptedCredentials>(passport_data, "credentials")) {}
