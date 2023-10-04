import qbs

Project {
    minimumQbsVersion: "1.7.1"
    property bool usePCH: false

    StaticLibrary {
        name : "ber"
        version: "0.1"
        Depends { name: 'cpp' }
        cpp.includePaths: ["inc"]
        cpp.cxxLanguageVersion: "c++20"
        cpp.enableExceptions: false
        cpp.enableRtti: false
        Group {
            name: "base"
            qbs.install: true
            qbs.installSourceBase: "inc/kmx/asn1/ber/"
            qbs.installDir: "/usr/local/include/kmx/ber/"
            prefix: "inc/kmx/asn1/ber/"
            files: [
                "decoder/tag_length.hpp",
                "decoder/tag_length_base.hpp",
                "types.hpp",
                "encoder/field/base.hpp",
                "encoder/field/length.hpp",
                "encoder/field/tag.hpp",
                "encoder/base.hpp",
                "encoder/structure.hpp",
                "encoder/value.hpp",
                "decoder/field/length.hpp",
                "decoder/field/tag.hpp",
                "decoder/printer.hpp",
            ]
        }
        Group {
            name: "extra"
            files: [
                "src/kmx/asn1/ber/types.cpp",
            ]
        }
        Group {
            name: "pch"
            condition: project.usePCH
            fileTags: ["cpp_pch"]
            files: [
                "inc/kmx/asn1/ber/pch.h",
                "src/kmx/asn1/ber/pch.cpp"
            ]
        }
    }

    CppApplication {
         name : "ber_test"
         version: "0.1"
         Depends { name: "ber" }
         cpp.includePaths: [
             "inc",
             //"../inc",
             "/usr/local/include"
         ]
         cpp.cxxLanguageVersion: "c++20"
         cpp.enableExceptions: false
         cpp.enableRtti: false
         files: [
            "test/enc/encoder_test.cpp",
            "test/dec/decoder_test.cpp",
            "test/tester.hpp",
        ]
     }
}
