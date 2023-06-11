# EE536 Internet Of Things - Assignment 7
### Objective: To simulate a real-time Flight Dashboard using Node-RED.
### Devices Needed:

| Devices | Description |
| --- | --- |
| Arduino Uno | Altitude Sensor A1 |
| Arduino Uno LED | Altitude Indicator A2 |
| NodeMCU | Fuel Sensor M1 |
| NodeMCU LED | Fuel Indicator A1 |
| Raspberry Pi 3B+ | Central Computer |

### Architecture:

| ![image](https://github.com/SKundawal/Internet-Of-Things/assets/61798659/4bb15440-01aa-4cb7-89ea-28ca26354795) |
| :--: |

### Task:
**1. Altitude Part**
  - The altitude sensor `A1` generates the altitude as per *Figure 2*. This is communicated to the Rpi via a serial connection. The altitude values are recorded in a CSV file `alti.csv`.
  -  The Rpi sends the altitude values to the indicator LED in `A2` via a serial connection. When altitude is < 100, the LED A blinks rapidly. When altitude is >= 100, LED A stays on without blinking.

**2. Fuel Part**
  - The fuel sensor `M1` generates the fuel values as per *Figure 2*. This is communicated to Rpi via a wireless link. The fuel values are recorded in a CSV file `fuel.csv`.
  - The Rpi sends the fuel values to the LED in `M2`. When the fuel is above 20, LED F glows without blinking. When the fuel is below 20, LED F blinks rapidly.

**3. Synchronization Part**
  - If the fuel level is below 20 during level flight, the Rpi prints a warning message. For example, fuel consumption represented by `Fuel2` in the plot gives a warning, whereas the consumption represented by `Fuel1` is safe.

### Notes:

|![image](https://github.com/SKundawal/Internet-Of-Things/assets/61798659/7c6dbc46-0d17-4b68-a6a4-5dd14ba036a7)|
| :--: |
| *Figure2. Plot showing altitude and two types of fuel consumption. `R` represents the fuel reserve level.*|

1. Fuel1 can be represented by the line `f = -0.23t+100`, where as Fuel2 is represented by `f = -0.29t+100`, where t is the time.
2. Level flight means the altitude is 100. At other times, the altitude is < 100, and `a = t`, where a is altitude and t is the time (use this to generate the altitude curve.)
3. If the fuel level goes below 20 during level flight, a warning has to be generated at the Rpi.(black arrow in the figure)
4. You must be able to demonstrate simulation of Fuel1 flight or Fuel2 flight (by reloading sensor code as needed.) The demo must finish in less than 2 minutes, so plan accordingly. If needed, other fuel and altitude profiles may also need to be simulated.
5. Once started, the simulation should go without any manual intervention for a complete flight cycle.


