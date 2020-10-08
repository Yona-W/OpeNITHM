# OpeNITHM

This repository contails files related to the second generation, laser cut case.

## Fasteners

| Part | Link                                    | Qty |
| --- | --- | :---:|
| 25mm M3 Female-Female hex standoffs | [McMaster][1]                                     | 10  |
| 10 or 11mm M3 hex standoffs      |                                          | 8   |
| 20mm M5 screw      |      | 4 |
| M5 hex nuts    |    | 4 |
| 8mm M3 Black-Oxide Alloy Steel Hex Drive Flat Head Screw | [McMaster][2] | 18 |
| 8mm M3 18-8 Stainless Steel Hex Drive Flat Head Screw | [McMaster][3] | 8 |
| 8mm M3 316 Stainless Steel Button Head Hex Drive Screws | [McMaster][4] | 14 |
| M2.5 hex nuts ||2|
| 25mm M2.5 screw ||2|
| Copper Tape, cut into rectangles 95mm x 26mm     |                          | 16  |


[1]: https://www.mcmaster.com/95947A018
[2]: https://www.mcmaster.com/91294A128
[3]: https://www.mcmaster.com/92125A128
[4]: https://www.mcmaster.com/94500A222

## Electronics changes

As opposed to the original design, this design uses 31 LEDS, 60 per meter spacing (instead of 30). https://www.aliexpress.com/item/2036819167.html

Additionally, this has a center mounted usb-c connector, which is simply https://www.adafruit.com/product/4090, with a small microusb connector soldered to it, connected to the teensy.

## Notes

I've listed the acrylic as either 1.5mm, 3mm, or 5.6mm, but 5mm should work fine.
You may have to adjust for kerf, your laser and my laser act differently.
Red lines are always cut, black is always etch.
If you do not make a shield layer and cover it with foil, you may end up with a ton of noise. Capsense is weird. I'm sorry.
