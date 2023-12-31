﻿// asn1-ber-encoding
// Copyright (c) 2023 KMX Systems. All rights reserved.
#include "kmx/asn1/ber/types.hpp"
#include "kmx/asn1/ber/pch.hpp"

namespace kmx::asn1::ber
{

    template <typename T>
    const char* text_of(const T item, const char* const texts[]) noexcept
    {
        auto index = static_cast<byte>(item);
        return index < static_cast<byte>(T::COUNT) ? texts[index] : "<unknown>";
    }

    const char* text_of(const tag_t item) noexcept
    {
        static const char* const texts[] = {"end_of_content",   "boolean",
                                            "integer",          "string_bit",
                                            "string_octet",     "null",
                                            "object_id",        "object_descriptor",
                                            "instance_of",      "real",
                                            "enumerated",       "embedded_pdv",
                                            "string_utf8",      "object_id_relative",
                                            "reserved1",        "reserved2",
                                            "sequence",         "set",
                                            "string_numeric",   "string_printable",
                                            "string_teletex",   "string_videotext",
                                            "string_ia5",       "time_utc",
                                            "time_generalized", "string_graphic",
                                            "string_iso646",    "string_general",
                                            "string_universal", "string_character",
                                            "string_bmp"};

        return text_of(item, texts);
    }

    const char* text_of(const class_t item) noexcept
    {
        static const char* const texts[] = {"universal", "application", "context_specific", "private"};

        return text_of(item, texts);
    }

    const char* text_of(const content_t item) noexcept
    {
        static const char* const texts[] = {"primitive", "constructed"};

        return text_of(item, texts);
    }
}
