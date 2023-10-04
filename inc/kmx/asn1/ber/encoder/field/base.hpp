// asn1-ber-encoding
// Copyright (c) 2023 KMX Systems. All rights reserved.
#pragma once
#ifndef PCH
    #include <cstdint>
    #include <kmx/asn1/ber/types.hpp>
#endif

namespace kmx::asn1::ber::encoder::field
{
    template <typename T>
    class base
    {
    public:
        base(const T value, const byte length) noexcept: value_(value), length_(length) {}

        virtual ~base() = default;

        T value() const noexcept { return value_; }

        byte bytes() const noexcept { return length_; }

        virtual byte* serialize_to(byte* buffer) const noexcept = 0;

        bool operator==(const base& item) const noexcept { return value_ == item.value_; }

        bool operator!=(const base& item) const noexcept { return value_ != item.value_; }

    protected:
        T value_;
        byte length_;
    };
}
