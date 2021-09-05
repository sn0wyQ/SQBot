#include "passport_data.h"

PassportData::PassportData(const Json& passport_data)
  : credentials(
      Utils::GetPtr<EncryptedCredentials>(passport_data, "credentials")) {
  // TODO(sn0wyQ): set 'std::vector<EncryptedPassportElement> data'
}
