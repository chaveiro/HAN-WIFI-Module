/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is included
#warning **** user_config_override.h: Using Settings from this File ****

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

// -- My custom settings 
#undef  MODULE
#define MODULE          USER_MODULE      // [Module] Select default module from tasmota_template.h

#undef  FALLBACK_MODULE 
#define FALLBACK_MODULE USER_MODULE      // [Module2] Select default module on fast reboot where USER_MODULE is user template
// Default 
//#define USER_TEMPLATE "{\"NAME\":\"Generic\",\"GPIO\":[1,1,1,1,1,1,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":18}"  // [Template] Set JSON template

// MiniHAN v1
//#define USER_TEMPLATE "{\"NAME\":\"MODBUS\",\"GPIO\":[1,1,320,1,1,1,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":18}"

// MiniHAN v2 with I2C
#define USER_TEMPLATE "{\"NAME\":\"MODBUS+I2C\",\"GPIO\":[1,1,320,1,640,608,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":18}"

//#undef  CODE_IMAGE_STR
#define CODE_IMAGE_STR    "MiniHAN v2" //footer string

#undef  PROJECT
#define PROJECT           "HanModule"         // PROJECT is used as the default topic delimiter

#undef  FRIENDLY_NAME
#define FRIENDLY_NAME     "Mini HAN Module"         // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa

#undef  OTA_URL
#define OTA_URL           "http://ota.devices.gtronica.com/fw/" PROJECT ".bin"  // [OtaUrl]

//#define MY_LANGUAGE            pt_PT           // Portuguese in Portugal


// -- Setup your own Wifi settings  ---------------
/*
#undef  STA_SSID1
#define STA_SSID1         ""             // [Ssid1] Wifi SSID
#undef  STA_PASS1
#define STA_PASS1         ""     // [Password1] Wifi password

#undef  STA_SSID2
#define STA_SSID2         ""             // [Ssid1] Wifi SSID
#undef  STA_PASS2
#define STA_PASS2         ""     // [Password1] Wifi password
*/

#ifndef USE_MQTT_TLS 
#define USE_MQTT_TLS                             // Use TLS for MQTT connection (+34.5k code, +7.0k mem and +4.8k additional during connection handshake)

  #undef MQTT_TLS_ENABLED
  #define MQTT_TLS_ENABLED       true             // [SetOption103] Enable TLS mode (requires TLS version)

  //#define USE_MQTT_TLS_CA_CERT                   // Force full CA validation instead of fingerprints, slower, but simpler to use.  (+2.2k code, +1.9k mem during connection handshake)
                                                 // This includes the LetsEncrypt CA in tasmota_ca.ino for verifying server certificates
  //#define USE_MQTT_TLS_FORCE_EC_CIPHER           // Force Elliptic Curve cipher (higher security) required by some servers (automatically enabled with USE_MQTT_AWS_IOT) (+11.4k code, +0.4k mem)

  // Filled with 0x00 = accept any fingerprint and learn it for next time
  // Filled with 0xFF = accept any fingerpring forever
  
  #undef MQTT_FINGERPRINT1
  //#define MQTT_FINGERPRINT1     "1D 6F ED 50 54 7F 7B A9 AE 92 12 B6 F1 29 CE 99 CA 49 9D 1A"  // [MqttFingerprint]  openssl x509 -in server.crt -sha1 -noout -fingerprint
  #define MQTT_FINGERPRINT1     "00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00" // Auto learn fingerprint on 1st connection
  //#define MQTT_FINGERPRINT1     "FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF" // Disable Fingerprint
#endif

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "your.mqtt.server.com" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         8883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "mqttuser"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "mqttpassword"         // [MqttPassword] Optional password


#undef USE_IMPROV                                // Disable support for IMPROV serial protocol as used by esp-web-tools (+2k code)
#undef USE_TASMESH                               // Disable Tasmota Mesh using ESP-NOW (+11k code)
#undef USE_ARDUINO_OTA                           // Disable support for Arduino OTA
#undef USE_INFLUXDB                              // Disable influxdb support (+5k code)
//#undef USE_DOMOTICZ                              // Disable Domoticz
//#undef USE_HOME_ASSISTANT                        // Disable Home Assistant
//#undef USE_TASMOTA_DISCOVERY                     // Disable Tasmota Discovery support (+2k code)
//#undef USE_TELEGRAM                              // Disable support for Telegram protocol (+49k code, +7.0k mem and +4.8k additional during connection handshake)
//#undef USE_MQTT_TLS                              // Disable TLS support won't work as the MQTTHost is not set
#undef USE_KNX                                   // Disable KNX IP Protocol Support
//#undef USE_WEBSERVER                             // Disable Webserver
//#undef USE_ENHANCED_GUI_WIFI_SCAN                // Disable wifi scan output with BSSID (+0k5 code)
//#undef USE_WEBSEND_RESPONSE                      // Disable command WebSend response message (+1k code)
#undef USE_EMULATION                             // Disable Wemo or Hue emulation
#undef USE_EMULATION_HUE                         // Disable Hue Bridge emulation for Alexa (+14k code, +2k mem common)
#undef USE_EMULATION_WEMO                        // Disable Belkin WeMo emulation for Alexa (+6k code, +2k mem common)
//#undef USE_CUSTOM                                // Disable Custom features
//#undef USE_DISCOVERY                             // Disable Discovery services for both MQTT and web server
//#undef USE_TIMERS                                // Disable support for up to 16 timers
//#undef USE_TIMERS_WEB                            // Disable support for timer webpage
//#undef USE_SUNRISE                               // Disable support for Sunrise and sunset tools
#undef USE_PING                                  // Disable Ping command (+2k code)
//#undef USE_UNISHOX_COMPRESSION                   // Disable support for string compression in Rules or Scripts
#undef USE_RULES                                 // Disable support for rules
//#undef USE_SCRIPT                                // Disable support for script

// -- Optional modules ----------------------------
#undef ROTARY_V1                                 // Disable support for MI Desk Lamp
#undef USE_SONOFF_RF                             // Disable support for Sonoff Rf Bridge (+3k2 code)
  #undef USE_RF_FLASH                            // Disable support for flashing the EFM8BB1 chip on the Sonoff RF Bridge. C2CK must be connected to GPIO4, C2D to GPIO5 on the PCB
#undef USE_SONOFF_SC                             // Disable support for Sonoff Sc (+1k1 code)
#undef USE_TUYA_MCU                              // Disable support for Tuya Serial MCU
#undef USE_ARMTRONIX_DIMMERS                     // Disable support for Armtronix Dimmers (+1k4 code)
#undef USE_PS_16_DZ                              // Disable support for PS-16-DZ Dimmer and Sonoff L1 (+2k code)
#undef USE_SONOFF_IFAN                           // Disable support for Sonoff iFan02 and iFan03 (+2k code)
#undef USE_BUZZER                                // Disable support for a buzzer (+0k6 code)
#undef USE_ARILUX_RF                             // Disable support for Arilux RF remote controller
#undef USE_SHUTTER                               // Disable Shutter support for up to 4 shutter with different motortypes (+6k code)
#undef USE_DEEPSLEEP                             // Disable support for deepsleep (+1k code)
#undef USE_EXS_DIMMER                            // Disable support for EX-Store WiFi Dimmer
#undef USE_HOTPLUG                               // Disable support for HotPlug
#undef USE_DEVICE_GROUPS                         // Disable support for device groups (+3k5 code)
#undef USE_PWM_DIMMER                            // Disable support for MJ-SD01/acenx/NTONPOWER PWM dimmers (+4k5 code)
#undef USE_PWM_DIMMER_REMOTE                     // Disbale support for remote switches to PWM Dimmer
#undef USE_KEELOQ                                // Disable support for Jarolift rollers by Keeloq algorithm (+4k5 code)
#undef USE_SONOFF_D1                             // Disable support for Sonoff D1 Dimmer (+0k7 code)
#undef USE_SHELLY_DIMMER                         // Disable support for Shelly Dimmer (+3k code)

// -- Optional light modules ----------------------
#undef USE_LIGHT                                 // Disable support for lights

//#undef USE_COUNTER                               // Disable counters
#define USE_ADC_VCC                              // Display Vcc in Power status. Disable for use as Analog input on selected devices
//#undef USE_DS18x20                               // Disable DS18x20 sensor

//#undef USE_I2C                                   // Disable all I2C sensors and devices
#undef USE_SPI                                   // Disable all SPI devices
#undef USE_DISPLAY                               // Disable Display support

#undef USE_MHZ19                                 // Disable support for MH-Z19 CO2 sensor
#undef USE_SENSEAIR                              // Disable support for SenseAir K30, K70 and S8 CO2 sensor
#undef USE_PMS5003                               // Disable support for PMS5003 and PMS7003 particle concentration sensor
#undef USE_NOVA_SDS                              // Disable support for SDS011 and SDS021 particle concentration sensor
#undef USE_HPMA                                  // Disable support for Honeywell HPMA115S0 particle concentration sensor
#undef USE_SR04                                  // Disable support for HC-SR04 ultrasonic devices (+1k code)
#undef USE_DYP                                   // Disable support for DYP ME-007 ultrasonic distance sensor, serial port version (+0k5 code)
#undef USE_SERIAL_BRIDGE                         // Disable support for software Serial Bridge
//#undef USE_TCP_BRIDGE                            // DIsable support for Serial to TCP bridge (+1.3k code)
#undef USE_MP3_PLAYER                            // Disable DFPlayer Mini MP3 Player RB-DFR-562 commands: play, volume and stop
#undef USE_AZ7798                                // Disable support for AZ-Instrument 7798 CO2 datalogger
#undef USE_PN532_HSU                             // Disable support for PN532 using HSU (Serial) interface (+1k8 code, 140 bytes mem)
#undef USE_ZIGBEE                                // Disable serial communication with Zigbee CC2530 flashed with ZNP
#undef USE_RDM6300                               // Disable support for RDM6300 125kHz RFID Reader (+0k8)
#undef USE_IBEACON                               // Disable support for bluetooth LE passive scan of ibeacon devices (uses HM17 module)
#undef USE_GPS                                   // Disable support for GPS and NTP Server for becoming Stratus 1 Time Source (+ 3.1kb flash, +132 bytes RAM)
#undef USE_HM10                                  // (ESP8266 only) Disable support for HM-10 as a BLE-bridge for the LYWSD03 (+5k1 code)
#undef USE_BLE_ESP32                             // (ESP32 only) Disable support for native BLE on ESP32 - use new driver
#undef USE_MI_ESP32                              // (ESP32 only) Disable support for ESP32 as a BLE-bridge (+9k2 mem, +292k flash)
#undef USE_HRXL                                  // Disable support for MaxBotix HRXL-MaxSonar ultrasonic range finders (+0k7)
#undef USE_TASMOTA_CLIENT                        // Disable support for Arduino Uno/Pro Mini via serial interface including flashing (+2k3 code, 44 mem)
#undef USE_OPENTHERM                             // Disable support for OpenTherm (+15k code)
#undef USE_MIEL_HVAC                             // Disable support for Mitsubishi Electric HVAC serial interface (+5k code)
#undef USE_PROJECTOR_CTRL                        // Disable support for LCD/DLP Projector serial control interface
#undef USE_AS608                                 // Disable support for AS608 optical and R503 capacitive fingerprint sensor (+3k4 code)
#undef USE_TFMINIPLUS                            // Disable support for TFmini Plus (TFmini, TFmini-S) LiDAR modules via UART interface (+0k8)
#undef USE_HRG15                                 // Disable support for Hydreon RG-15 Solid State Rain sensor (+1k5 code)
#undef USE_VINDRIKTNING                          // Disable support for IKEA VINDRIKTNING particle concentration sensor (+0k6 code)

//#undef USE_ENERGY_SENSOR                         // Disable energy sensors

//#undef USE_DHT                                   // Disable support for DHT11, AM2301 (DHT21, DHT22, AM2302, AM2321) and SI7021 Temperature and Humidity sensor
#undef USE_MAX31855                              // Disable MAX31855 K-Type thermocouple sensor using softSPI
#undef USE_MAX31865                              // Disable support for MAX31865 RTD sensors using softSPI
#undef USE_LMT01                                 // Disable support for TI LMT01 temperature sensor, count pulses on single GPIO (+0k5 code)
#undef USE_IR_REMOTE                             // Disable IR driver
#undef USE_TM1638                                // Disable support for TM1638 switches copying Switch1 .. Switch8
#undef USE_HX711                                 // Disable support for HX711 load cell
#undef USE_TX20_WIND_SENSOR                      // Disable support for La Crosse TX20 anemometer
#undef USE_TX23_WIND_SENSOR                      // Disable support for La Crosse TX23 anemometer
#undef USE_WINDMETER                             // Disable support for analog anemometer (+2k2 code)
#undef USE_RC_SWITCH                             // Disable support for RF transceiver using library RcSwitch
#undef USE_RF_SENSOR                             // Disable support for RF sensor receiver (434MHz or 868MHz) (+0k8 code)
#undef USE_HRE                                   // Disable support for Badger HR-E Water Meter (+1k4 code)
#undef USE_A4988_STEPPER                         // Disable support for A4988_Stepper
#undef USE_THERMOSTAT                            // Disable support for Thermostat
#undef USE_PROMETHEUS                            // Disable support for https://prometheus.io/ metrics exporting over HTTP /metrics endpoint
#undef DEBUG_THEO                                // Disable debug code
#undef USE_DEBUG_DRIVER                          // Disable debug code
#undef USE_AC_ZERO_CROSS_DIMMER                  // Disable support for AC_ZERO_CROSS_DIMMER



#undef USE_RULES
#define USE_SCRIPT
#define USE_SML_M
#define USE_SML_SCRIPT_CMD
#define SML_MAX_VARS 50
#define SML_REPLACE_VARS

// tcp

#define USE_TCP_BRIDGE

// misc

#define USE_SCRIPT_WEB_DISPLAY
#define USE_SCRIPT_JSON_EXPORT
#define MAX_METERS 2
#define MAXSVARS 10

//#define SCRIPT_FULL_OPTIONS
#define USE_GOOGLE_CHARTS  // for charts
//#define USE_SCRIPT_I2C


/*
Examples :

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "YourSSID"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "YourWifiPassword"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "your-mqtt-server.com" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "YourMqttUser"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "YourMqttPass"         // [MqttPassword] Optional password

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS     MY_IP                // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY        MY_GW                // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS            MY_DNS               // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

#ifdef MY_DNS2
#undef  WIFI_DNS2
#define WIFI_DNS2           MY_DNS2              // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

// !!! Remember that your changes GOES AT THE BOTTOM OF THIS FILE right before the last #endif !!!
*/





#endif  // _USER_CONFIG_OVERRIDE_H_
