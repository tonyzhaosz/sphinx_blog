
# Security Features in Modern MCU

## Readback Protection

Refer to a Whitepaper published by NCC group `Microcontroller Readback Protection Bypasses and Defenses`.

Many different mechanisms are used by microcontroller vendors to provide data readback protection, including:
* Disabling debugger access completely.
* Preventing debuggers from reading memory-mapped flash addresses while otherwise leaving the debugging capability intact.
* Preventing flash reads by any internal bus master other than the CPU instruction fetch mechanism.
* Disabling flash reads within bootloaders.
* Encrypting the contents of flash.

### Debug Pins Reconfigured for Alternate Functions

The threat here is: attackers are able to read memory via debug interfaces like Jtag if debug pins are not protected/disabled.

* Run-time debug disablement has vulnerability as attackers could attach the debugger at early stage while letting device reset to halt the MCU before run-time disablement starts.
* The root cause of such an issue is normally such debug pins are multiplexed with GPIOs, and some MCU allows run-time debug pin remapping. Sometimes boot mode pins could contribute to bypassing the debug interface remapping.

---

## ESP32

This section lists ESP32 security-related features and known vulnerabilities.

### ESP32 eFuse

Refer to https://github.com/espressif/esptool/wiki/espefuse. Basically, eFuse is one-time-programmable, and it is possible to permanently damage or 'brick' the device.

### CVE items regarding Espressif

After searching in NVD database, here is a list of known vulnerabilities: 
https://nvd.nist.gov/vuln/search/results?form_type=Basic&results_type=overview&query=ESP32&search_type=all. Two items are worth noting:

* https://nvd.nist.gov/vuln/detail/CVE-2019-17391
* https://nvd.nist.gov/vuln/detail/CVE-2019-15894

These issues are related to hardware attacks using fault injection to either bypass secure boot verification or to read encryption and secure boot keys. Espressif has addressed this issue at https://www.espressif.com/en/news/Security_Advisory_Concerning_Fault_Injection_and_eFuse_Protections. The recommended way is to leverage the up-to-date ESP32-D0WD-V3 chip and Secure Boot V2 scheme.


### Chip selection

The module ESP32-WROOM-U32 is based on ESP32-D0WDQ6 chip, and should address Secure Boot V1 scheme (no V2 scheme). Modules with S2 (e.g., ESP32-S2-WROOM) support V2 scheme.

To cover high security requirements, the chip selection depends on the key difference between ESP32, ESP32 ECO3 and ESP32-S2 devices.

* ESP32, module example ESP32-D0WD, (old wafer design) supports only Secure Boot V1.
* ESP32 ECO, module example ESP32-D0WD-V3, supports Secure Boot V2. ECO V3 has a few changes to ECO V1. Refer to https://www.espressif.com/sites/default/files/documentation/ESP32_ECO_V3_User_Guide__EN.pdf. It claims to fix CVE-2019-17391 and CVE-2019-15894.
* ESP32-S2 supports Secure Boot V2. It is a single-core MCU without BLE hardware. The problem is S2 module is not pin-to-pin mapping to ESP32. Since it is new to the market, the price might be higher and it could be more buggy.

Known bugs in ESP32 ECO 1 & 3 could be viewed here: https://www.espressif.com/sites/default/files/documentation/eco_and_workarounds_for_bugs_in_esp32_en.pdf.

`Conclusion:` it's preferable to select ESP32 ECO3 chips due to Secure Boot V2 support, and pin-mapping to the existing PCB designs.


