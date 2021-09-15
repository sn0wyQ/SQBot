#include "../../include/SQBot/API/encrypted_passport_element.h"

EncryptedPassportElement::EncryptedPassportElement(
    const Json& encrypted_passport_element)
  : type(SQBot::Utils::GetValue<std::string>(
        encrypted_passport_element, "type")),
    data(SQBot::Utils::GetValue<std::string>(
        encrypted_passport_element, "data")),
    phone_number(SQBot::Utils::GetValue<std::string>(
        encrypted_passport_element, "phone_number")),
    email(SQBot::Utils::GetValue<std::string>(
        encrypted_passport_element, "email")),
    files(SQBot::Utils::GetPtrsArray<PassportFile>(
        encrypted_passport_element, "files")),
    front_side(SQBot::Utils::GetPtr<PassportFile>(
        encrypted_passport_element, "front_side")),
    reverse_side(SQBot::Utils::GetPtr<PassportFile>(
        encrypted_passport_element, "reverse_side")),
    selfie(SQBot::Utils::GetPtr<PassportFile>(
        encrypted_passport_element, "selfie")),
    translation(SQBot::Utils::GetPtrsArray<PassportFile>(
        encrypted_passport_element, "translation")),
    hash(SQBot::Utils::GetValue<std::string>(
        encrypted_passport_element, "hash")) {}
