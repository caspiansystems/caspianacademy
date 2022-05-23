# Low power development for a PIC32 microcontroller
PIC32MM belongs to the eXtreme Low Power (XLP) family of microcontrollers featuring high performance 
MIPS microAptiv™ UC processors. The provided example in this repo covers an important power saving feature 
where the device is put in sleep mode and recovered periodically for doing measurements and communication. 
This is the basic feature requires in many IoT applications for example.
A python script is created to read the serial port, convert the raw data to voltage and print it in the terminal. 
The python script is found here:

```
import serial
import struct

sp = serial.Serial()
sp.port = 'COM7'
sp.baudrate = 115200
sp.bytesize = 8
sp.stopbits = 1
sp.parity = 'N'

try:
    sp.open()
except Exception as err:
    print(err)

rx_byte = 0

while True:
    try:
        rx_byte = sp.read(2)
    except Exception as err:
        print(err)
    rx_unpacked = struct.unpack('!h', rx_byte)
    voltage = rx_unpacked[0] * 3.3 / 1023
    format_voltage = "{:.2f}".format(voltage)
    print(format_voltage)
```
The software is developed in MPLAB X IDE integrated with MPLAB Code Configurator and X32 complier.

https://www.caspiansystems.dk/