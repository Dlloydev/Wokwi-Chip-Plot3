# Wokwi-Chip-Analog-Plot3

## Description

Plot up to 3 Analog Signals.

- Plotter `Sample Time μs` range is 50-10000 µs (default 100 µs).
-  Width of plot is 250 samples.
- `AD0 Trigger` modes are Off (`0`) Rising (default) ⬆ and Falling ⬇
- Displays peak volts`Vmax`, and minimum volts `Vmin`
- Displays  Sample Time `us` and Capture Time `ms`



![image](https://user-images.githubusercontent.com/63488701/224561955-53103f1e-b501-42a3-a6c9-01bdd8bda55c.png)

## ![image](https://user-images.githubusercontent.com/63488701/224561845-41bcc7aa-1ae0-464d-a7a4-3c4f9ebc8375.png)

| Name | Description                                        |
| ---- | -------------------------------------------------- |
| AD0  | Input  configured as ANALOG, also the trigger pin. |
| AD1  | Input  configured as ANALOG.                       |
| AD2  | Input  configured as ANALOG.                       |

## Usage

To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
  "dependencies": {
    "chip-analog-plot3": "github:Dlloydev/Wokwi-Chip-Plot3@1.0.2"
  }
```

Then, add the chip to your circuit by adding a `chip-analog-plot3` item to the `parts` section of `diagram.json`:

```json
  "parts": {
    ...,
    { "type": "chip-analog-plot3", "id": "chip-analog-plot3-1" }
  },
```

The actual source code for the chip lives in [src/main.c](https://github.com/Dlloydev/Wokwi-Chip-Plot3/blob/main/src/main.c), and the pins are described in [chip.json](https://github.com/Dlloydev/Wokwi-Chip-Plot3/blob/main/chip.json).

## Example

[![Wokwi_badge](https://user-images.githubusercontent.com/63488701/212449119-a8510897-c860-4545-8c1a-794169547ba1.svg)](https://wokwi.com/projects/359000874041067521) Plot Analog Signals Example

## License

This project is licensed under the MIT license. See the [LICENSE](https://github.com/Dlloydev/Wokwi-Chip-Plot3/blob/main/LICENSE) file for more details.
