Hardware for the rfbb driver
============================
Latest update 2017-01-30, Joachim Nilsson

Note! A monospaced font might make it easier to read tables below!


RF Transmitter module pinout
----------------------------

A common RF transmitter module like [TX433N][] (433.92 MHz) has the
following pinout:

    Pin    Function
    ---------------
    1      GND
    2      Digital in
    3      VCC
    4      Antenna

Make sure that VCC is able to operate from 5V DC and the Data In
threshold is compatible with 3.3V logic.

The range is often 3 - 12 V DC, but there might be other versions!


RF Receiver module pinout
-------------------------

A common RF receiver module, like [RX433N][] (433.92 MHz) has the
following pinout:

    Pin    Function
    ---------------
    1      GND
    2      Digital Out
    3      Linear Out
    4      VCC
    5      VCC
    6      GND
    7      GND
    8      Antenna

Make sure that VCC is able to operate from 5V DC and the Data Out
threshold is compatible with 3.3V logic.

The range is often 3 - 12 V DC, but there might be other versions!


Raspberry Pi Example
--------------------

    RPI               TX433N/RX433N
    -------------------------------------------------------------
    Pin, function  -  Pin, function
    P1-02, 5V0     -  3, VCC
    P1-06, GND     -  1, GND
    P1-11, GPIO17  -  2, Data in
    P1-13, GPIO27  -  2, Data out
    No connection  -  4/8, Antenna. Connect a 170mm wire as antenna


RF Sockets
----------

There are several compatible 433 MHz remote controllable sockets on the
market using the same base protocol.

- [4teiliges Funk-Schalt-Set 433 MHz](https://www.conrad.de/de/4teiliges-funk-schalt-set-433-mhz-646452.html) (German/Swedish version)
- [Remote Controlled Mains Sockets 5 Pack](http://www.maplin.co.uk/p/remote-controlled-mains-sockets-5-pack-n38hn) (UK version)
- [Fjärrströmbrytare 433 MHz](https://www.kjell.com/se/sortiment/el-verktyg/smarta-hem/433-mhz/fjarrstrombrytare/utanpaliggande-brytare/luxorparts-fjarrstrombrytare-2000-w-3-pack-p50219) (Swedish)


[TX433N]: https://www.kjell.com/se/sortiment/el-verktyg/elektronik/fjarrstyrning/tx433n-sandarmodul-433-mhz-p88901
[RX433N]: https://www.kjell.com/se/sortiment/el-verktyg/elektronik/fjarrstyrning/rx433n-mottagarmodul-433-mhz-p88900
