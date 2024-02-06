/**
 * @file FirmwareVersion.h
 * @author Cristiano Brudna (cristiano.brudna@gmail.com)
 * @date 2023-05-13
 *
 */

#pragma once

#include <Arduino.h>

#ifdef ARDUINO_ARCH_SAMD
    #define SerialStandard SerialUSB
#else
    #define SerialStandard Serial
#endif

class FirmwareVersion
{
    public:
        enum class Type
        {
            None = 0,
            Development,
            Debug,
            Engineering,
            ReleaseCandidate,
            Release,
            UnitTest,
            IntegrationTest,
            Test
        };

        FirmwareVersion(String name,
                        unsigned int major,
                        unsigned int minor,
                        Type type = Type::None);

        FirmwareVersion(String name,
                        unsigned int major,
                        unsigned int minor,
                        String postfix = "",
                        Type type = Type::None);

        String timestamp();
        String version();
        void serialPrint();

    private:
        const char *c_DateTime = __TIME__ " " __DATE__;
        static const char * c_TypeToString[];

        String m_name;
        unsigned int m_major = 0;
        unsigned int m_minor = 0;
        String m_postfix;
        Type m_type;

    private:
        String getTypeAsString();
        String name();
};