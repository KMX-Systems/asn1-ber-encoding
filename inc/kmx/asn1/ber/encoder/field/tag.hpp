// asn1-ber-encoding
// Copyright (c) 2023 KMX Systems. All rights reserved.
#pragma once
#ifndef PCH
    #include <cstring>
    #include <kmx/asn1/ber/encoder/field/base.hpp>
#endif

namespace kmx::asn1::ber::encoder::field
{
    enum constants : byte
    {
        constructed_bit = 0x20u
    };

    class tag: public base<byte>
    {
    public:
        using base_t = base<byte>;

        tag(const byte value) noexcept: base_t(value, sizeof(byte)) {}

        virtual byte* serialize_to(byte* buffer) const noexcept
        {
            if (buffer != nullptr)
            {
                auto val = base_t::value_;
                std::memcpy(buffer, static_cast<const byte*>(&val), sizeof(val));
                buffer += sizeof(val);
            }

            return buffer;
        }
    };
}
