/**
 * @file ReleaseVersion.ino
 * @author Cristiano Brudna (cristiano.brudna@gmail.com)
 * @date 2023-05-13
 */

#include <Arduino.h>
#include <FirmwareVersion.h>

#define FIRMWARE_NAME                   "Firmware Version Example"
#define FIRMWARE_VERSION_MAJOR          1
#define FIRMWARE_VERSION_MINOR          2
#define FIRMWARE_VERSION_PATCH          7
#define FIRMWARE_TYPE                   FirmwareVersion::Type::Release

FirmwareVersion appVersion(FIRMWARE_NAME,
                           FIRMWARE_VERSION_MAJOR,
                           FIRMWARE_VERSION_MINOR,
                           FIRMWARE_VERSION_PATCH,
                           FIRMWARE_TYPE);

bool showInfo = true;

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
