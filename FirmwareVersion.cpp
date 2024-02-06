/**
 * @file FirmwareVersion.cpp
 * @author Cristiano Brudna (cristiano.brudna@gmail.com)
 * @date 2023-05-13
 *
 */

#include "FirmwareVersion.h"

const char *FirmwareVersion::c_TypeToString[] =
{
    "None",
    "Development",
    "Debug",
    "Engineering",
    "ReleaseCandidate",
    "Release",
    "UnitTest",
    "IntegrationTest",
    "Test"
};

FirmwareVersion::FirmwareVersion(String name,
                                 unsigned int major,
                                 unsigned int minor,
                                 Type type)
    : m_name(name),
      m_major(major),
      m_minor(minor),
      m_postfix(""),
      m_type(type)
{
}

FirmwareVersion::FirmwareVersion(String name,
                                 unsigned int major,
                                 unsigned int minor,
                                 String postfix,
                                 Type type)
    : m_name(name),
      m_major(major),
      m_minor(minor),
      m_postfix(postfix),
      m_type(type)
{
}

String FirmwareVersion::getTypeAsString()
{
    String type = c_TypeToString[static_cast<int>(m_type)];

    return type;
}

String FirmwareVersion::timestamp()
{
    return c_DateTime;
}

String FirmwareVersion::version()
{
    String version;

    version = String(m_major) + "." + String(m_minor) + String(m_postfix);

    return version;
}

String FirmwareVersion::name()
{
    return m_name;
}

void FirmwareVersion::serialPrint()
{
    SerialStandard.println();

    SerialStandard.print("FW Name: ");
    SerialStandard.println(name());

    SerialStandard.print("Version: ");
    SerialStandard.println(version());

    SerialStandard.print("Type: ");
    SerialStandard.println(getTypeAsString());

    SerialStandard.print("Build date: ");
    SerialStandard.println(timestamp());

    SerialStandard.println();
}
