# HAN-WIFI-Module
The HAN module is a HAN &lt;-> WIFI adapter designed to be connected externally to Intelligent Measuring Equipment (EMI) of single-phase or three-phase BTN points using the Modbus communication protocol, part of the InovGrid solution developed by E-Redes in Portugal (formerly EDP Distribution) or other similar systems that use the same protocol.

![Install](https://github.com/chaveiro/HAN-WIFI-Module/raw/main/images/instalation.jpeg)

The module comes with the latest version of the opensource Tasmota project, making it highly adaptable, by customizing the Tasmota script, to the needs of your projects. More info at https://tasmota.github.io/docs/Smart-Meter-Interface/


## Technical Characteristics
  | Parameter              | Value
  | :--------------------- |:-------------------- |
  | Voltage                | 5V ±10%
  | Consumption            | 0.5W avg
  | WIFI                   | 802.11 b/g/n 2.4 GHz
  | Power                  | 14±2 dBm @54Mbps
  | Sensitivity            | -70 dBm @54Mbps
  | SOC                    | ESP8266EX RISC 32bits 160Mhz
  | Flash                  | 4096KB
  | Protocols              | IPv4, TCP/UDP, MODBUS RTU
  | Operating environment  | 0°C – 70°C, < 90%RH
  | Software upgrade       | OTA, UART
  | Dimensions             | 20x60x18 mm
  | Communication          | RJ-12 EIA-485 half-duplex
  | Compliance             | ANATEL, CE, FCC, IC, KCC, NCC, SRRC, TELEC
  
## Instructions

### Configure WIFI on first installation
1 - Connect the module to the HAN port of your meter and wait a few seconds until the led starts flashing.

2 - Connect to the access point created by the module with the SSID “HanModule-XXXXXX-XXXX”, visit page 192.168.4.1 in your browser and configure the WIFI network where the module will connect. Ensure the network signal is strong and relocate the device better if necessary.

3 – After successfully connecting to WIFI, the module shows the IP it obtained from the router. Save this IP for later configuration (usually in the form 192.168.1.x).

### General Configuration
1 – Connect to the same WIFI network where the module is connected. Open the module IP obtained in the WIFI configuration in the browser, or check which one has been assigned on your router.

2 – Select the menu “Configuration” -> “Configure Other” and set the options in the table below according to your preference.

  ##### Template => {"NAME":"MODBUS","GPIO":[1,1,320,1,1,1,1,1,1,1,1,1,1,1],"FLAG":0,"BASE ":18}
  ##### Activate => Enabled
  ##### Web Admin => Password Set a password to protect access to module settings (optional)
  ##### HTTP API => Active
  ##### MQTT API =>  Active if you have an MQTT server, configure it in the menu “Configure MQTT”
  ##### Device Name =>  Name the module for easy identification
  ##### Friendly Name =>  Another name


### Script Configuration
1 – Connect to the same WIFI network where the module is connected. Open the module IP obtained in the WIFI configuration in the browser, or check which one has been assigned on your router.

2 – Select the menu “Consoles” -> “Edit Script”.

3 – Place the script related to your counter on the page, activate the “Script enable” option and click “Save”.

4 – Check in the menu “Consoles” -> “Console” if there are no errors, the module is configured.

Note: The script initiation is done with the underlined parameters: +1,3,m,1,9600,EB,1,[…]

### Over The Air Update
1 – Connect to the same WIFI network where the module is connected. Open the module IP obtained in the WIFI configuration in the browser, or check which one has been assigned on your router.

2 – Select the “Firmware Upgrade” menu.

3 – Change the URL address or provide an appropriate upgrade file and click “Start upgrade”.

### Firmware Recovery
1 – Use a USB - RS485 adapter (not supplied) and make a cable that allows you to connect the GND, 5V, A and B pins of the RJ12 plug to the adapter. Alternatively connect the 5V to an external power supply.

2 – With the module off, join the two contacts marked “PROG”, turn on the power supply and then release the contacts. The module is now in UART programming mode.

3 – Execute the programming using the ESP8266 upload.py tool indicating the USB adapter port and the path of the firmware binary file to be uploaded:

upload.py --chip esp8266 --port COM3 --baud 921600 erase_flash --before default_reset --after hard_reset write_flash 0x0 tasmota4M.bin

### Factory reset
1 – Turn off the module for 30 seconds.

2 – Turn on the module for 2 seconds and turn it off. Repeat 7 times, leave on last time.

3 – The parameters have been reset, you can configure the WIFI as in the first installation.
