/**
 * @file FirmwareVersion.ino
 * @author Cristiano Brudna (cristiano.brudna@gmail.com)
 * @date 2023-05-13
 */

#include <Arduino.h>
#include <FirmwareVersion.h>

#define FIRMWARE_NAME                   "Firmware Version Demo"
#define FIRMWARE_VERSION_MAJOR          1
#define FIRMWARE_VERSION_MINOR          23
#define FIRMWARE_TYPE                   FirmwareVersion::Type::ReleaseCandidate

FirmwareVersion appVersion(FIRMWARE_NAME,
                           FIRMWARE_VERSION_MAJOR,
                           FIRMWARE_VERSION_MINOR,
                           "-rc",
                           FIRMWARE_TYPE);

bool showInfo = true;

void setup()
{
    SerialStandard.begin(115200);

    while (!SerialStandard)
    {
        delay(10);
    }

    SerialStandard.println(F("Serial ready!"));
}

void loop()
{
    if (showInfo and millis() >= 3000)
    {
        appVersion.serialPrint();
        showInfo = false;
    }

    SerialStandard.println(".");
    delay(10000);
}
