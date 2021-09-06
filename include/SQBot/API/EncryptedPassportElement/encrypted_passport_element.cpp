#include "encrypted_passport_element.h"

EncryptedPassportElement::EncryptedPassportElement(
    const Json& encrypted_passport_element)
  : type(Utils::GetValue<std::string>(encrypted_passport_element, "type")),
    data(Utils::GetValue<std::string>(encrypted_passport_element, "data")),
    phone_number(Utils::GetValue<std::string>(
        encrypted_passport_element, "phone_number")),
    email(Utils::GetValue<std::string>(encrypted_passport_element, "email")),
    files(Utils::GetPtrsArray<PassportFile>(
        encrypted_passport_element, "files")),
    front_side(Utils::GetPtr<PassportFile>(
        encrypted_passport_element, "front_side")),
    reverse_side(Utils::GetPtr<PassportFile>(
        encrypted_passport_element, "reverse_side")),
    selfie(Utils::GetPtr<PassportFile>(encrypted_passport_element, "selfie")),
    translation(Utils::GetPtrsArray<PassportFile>(
        encrypted_passport_element, "translation")),
    hash(Utils::GetValue<std::string>(encrypted_passport_element, "hash")) {}
