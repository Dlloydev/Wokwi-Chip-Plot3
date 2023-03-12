# Wokwi-Chip-Plot3

## Description

Plot Analog or Digital Signals.

- Plotter `Sample Time μs` range is 50-10000 µs (default 100 µs).
-  Width of plot is 250 samples.
- `AD0 Trigger` modes are Off (`0`) Rising (default) ⬆ and Falling ⬇
- Displays peak volts`Vmax`, and minimum volts `Vmin`
- Displays  Sample Time `us` and Capture Time `ms`



![image](https://user-images.githubusercontent.com/63488701/224549835-d7a5a515-12ac-4d97-ab6d-1d816757acae.png)

## ![image](https://user-images.githubusercontent.com/63488701/224549568-25d9f3a7-cb3c-4158-8c84-f3cf90f825ad.png)

| Name | Description                                                  |
| ---- | ------------------------------------------------------------ |
| AD0  | Input  configured as ANALOG, also the trigger pin and works with digital signals. |
| AD1  | Input  configured as ANALOG, also works with digital signals. |
| AD2  | Input  configured as ANALOG, also works with digital signals. |

## Usage

To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
  "dependencies": {
    "chip-plot3": "github:Dlloydev/Wokwi-Chip-Plot3@1.0.1"
  }
```

Then, add the chip to your circuit by adding a `chip-plotter` item to the `parts` section of `diagram.json`:

```json
  "parts": {
    ...,
    { "type": "chip-plot3", "id": "chip-plot3-1" }
  },
```

The actual source code for the chip lives in [src/main.c](https://github.com/Dlloydev/Wokwi-Chip-Plot3/blob/main/src/main.c), and the pins are described in [chip.json](https://github.com/Dlloydev/Wokwi-Chip-Plot3/blob/main/chip.json).

## Example

[![Wokwi_badge](https://user-images.githubusercontent.com/63488701/212449119-a8510897-c860-4545-8c1a-794169547ba1.svg)](https://wokwi.com/projects/359000874041067521) Plot Analog or Digital Signals Example

## License

This project is licensed under the MIT license. See the [LICENSE](https://github.com/Dlloydev/Wokwi-Chip-Plot3/blob/main/LICENSE) file for more details.
