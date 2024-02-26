/**
 * @file RcVersion.ino
 * @author Cristiano Brudna (cristiano.brudna@gmail.com)
 * @date 2023-05-13
 */

#include <Arduino.h>
#include <FirmwareVersion.h>

#define FIRMWARE_NAME                   "Firmware Version Example"
#define FIRMWARE_VERSION_MAJOR          2
#define FIRMWARE_VERSION_MINOR          0
#define FIRMWARE_TYPE                   FirmwareVersion::Type::ReleaseCandidate

FirmwareVersion appVersion(FIRMWARE_NAME,
                           FIRMWARE_VERSION_MAJOR,
                           FIRMWARE_VERSION_MINOR,
                           "-rc",
                           FIRMWARE_TYPE);

void setup()
{
    SerialStandard.begin(115200);

    while (!SerialStandard)
    {
        delay(10);
    }

    SerialStandard.println(F("--- Serial ready! ---"));
}

void loop()
{
    appVersion.serialPrint();
    delay(10000);
}
