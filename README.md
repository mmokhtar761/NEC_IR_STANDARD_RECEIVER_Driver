# NEC_IR_STANDARD_RECEIVER_Driver
A fully generic educational driver for IR receivers based on NEC standards.
(Repeat code isn't stable yet)
=======
## LOG
- V1.0-> Raw code.
- V1.1-> Raw code. (Algorithm A) Essential tests.
- V02 -> A better optimized code.< all-time timer bug>
- V03 -> Repeat handling  &  data verification edited.< all-time timer bug is handled>
- V3.1-> flag issues fixing & video of first tests <logic bug is there>
- V3.2-> Reduced sysTick time & enabled its interrupt.

## How to install
- Add `NEC_IR_program.c` module to your workspace.
- Assign the needed configuration to `NEC_IR_config.h` file.
- Add `NEC_IR_private.h` ,`NEC_IR_config.h to your` inclusion pass.
- Include `NEC_IR_interface.h` into your app file and all given APIs are yours .. ***enjoy***. 


https://user-images.githubusercontent.com/51722220/157738402-3034431c-4f53-41e0-abb3-71e2bbc2e46e.mp4

*Repeat code* is simply the module response to an all-time press for the transmitter button
