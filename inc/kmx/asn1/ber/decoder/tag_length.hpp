// asn1-ber-encoding
// Copyright (c) 2023 KMX Systems. All rights reserved.
#pragma once
#ifndef PCH
    #include <kmx/asn1/ber/decoder/field/length.hpp>
    #include <kmx/asn1/ber/decoder/field/tag.hpp>
    #include <kmx/asn1/ber/decoder/tag_length_base.hpp>
#endif

namespace kmx::asn1::ber::decoder
{
    template <typename LengthType_ = uint16_t>
    using tag_length = tag_length_base<field::tag, field::length<LengthType_>>;
}
