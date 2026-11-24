# Arduino Uno R3 - Timer Relay Controller (hardware-adapted)

โปรเจกต์นี้ยึด Logic จาก source code ที่คุณอัปโหลด และปรับ Hardware interface ให้ตรงกับ configuration Arduino Uno R3 ที่ใช้ในแชตนี้

## Hardware mapping

| Hardware | Pin / Setting |
|---|---|
| LCD I2C | Address `0x27`, 16 columns x 2 rows |
| LCD SDA | A4 |
| LCD SCL | A5 |
| DS1302 CLK | D12 |
| DS1302 DAT | D11 |
| DS1302 RST | D10 |
| Relay input | D9 |
| Active buzzer | A3 |
| Left button | D7 |
| Right button | D6 |
| Cancel button | D5 |
| OK button | D4 |

### Buttons

โค้ดนี้ตั้งค่าปุ่มเป็น **ACTIVE-HIGH** ตามการต่อวงจรของคุณ:
- ใช้ `pinMode(pin, INPUT)`
- ต่อ pull-down resistor (เช่น 10 kOhm) จากแต่ละขา input ลง GND
- ต่อปุ่มระหว่าง 5V กับ input pin
- เมื่อกดปุ่ม input จะอ่านได้ HIGH

หากวงจรของคุณต่อเป็นแบบ INPUT_PULLUP / Active-LOW ต้องเปลี่ยนทั้งการตั้งค่า pin และเงื่อนไขอ่านปุ่ม ไม่ใช่เปลี่ยนเฉพาะ `Pins.h`

### Relay polarity

ใน `Pins.h`:
```cpp
#define RELAY_ACTIVE_LOW 1
```

ค่าเริ่มต้นนี้ตั้งตามพฤติกรรม Relay active-LOW ในโค้ดเดิมที่คุณเคยส่ง:
- `g_relayState == 1` หมายถึง ON
- `g_relayState == 0` หมายถึง OFF

ถ้า Relay module ของคุณเป็น Active-HIGH ให้เปลี่ยนเป็น:
```cpp
#define RELAY_ACTIVE_LOW 0
```

**ตรวจสอบ Relay โดยไม่มีโหลดอันตรายก่อนใช้งานจริง** และอย่าต่อไฟบ้านกับหน้าสัมผัส Relay ระหว่างการทดสอบบนโต๊ะ

## Libraries

ติดตั้งผ่าน Arduino IDE > Library Manager:
1. **Rtc by Makuna** (ให้ `RtcDS1302.h` และ `ThreeWire.h`)
2. **LiquidCrystal I2C** รุ่นที่รองรับ `LiquidCrystal_I2C(address, columns, rows)`, `init()`, `backlight()`, `noBacklight()`
3. **TimerOne**

`Arduino.h`, `Wire.h` และ `EEPROM.h` มากับ Arduino AVR core

## Arduino IDE

1. แตก ZIP
2. เปิดโฟลเดอร์ `arduino_course_final_project`
3. เปิด `arduino_course_final_project.ino`
4. เลือก Board: Arduino Uno
5. กด Verify ก่อน Upload

## RTC initialization note

โค้ดเรียก `Rtc.Begin()` และตั้งเวลาเป็น compile time เฉพาะเมื่อ RTC รายงานว่า Date/Time ไม่ valid เท่านั้น เพื่อไม่ให้เวลา DS1302 ถูกเขียนทับทุกครั้งที่รีสตาร์ต Arduino

## Scope of changes

ปรับเฉพาะ:
- Parallel LCD `LiquidCrystal` -> I2C `LiquidCrystal_I2C`
- LCD pin wiring -> I2C A4/A5 และ address 0x27
- DS1302 -> Makuna `ThreeWire` บน D12/D11/D10
- LCD initialization / backlight API
- Button mapping -> D7/D6/D5/D4 และ Active-HIGH input logic
- Buzzer pin -> A3
- Relay output adapter เพื่อรองรับ polarity ตาม module
- RTC startup ให้เหมาะกับ DS1302 Makuna

Menu, time editing, EEPROM layout, slot behavior, display text และหลักการตั้งเวลา ยังคงยึด source ที่คุณอัปโหลด ไม่ได้ใช้ logic rewrite จาก ZIP ก่อนหน้า
