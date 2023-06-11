# EE536 Internet Of Things - Assignment 2
### Objective: Arduino Board Interconnect - Exploring Serial & Parallel Communication

### Tasks:
- **Task-1**
  - Perform communication two Arduino boards via
    - UART
    - I2C
  - Use SoftwareSerial library for emulate the UART serial port. One board transmits, the other recives, and their roles are
reversed.

- **Task-2**
  - There are six states to be communicated from Arduino board1 to Arduino board2 using parallel communication:
    - Normal
    - Engine Temperature Low
    - Coolant Low
    - Oil Low
    - Tyre Pressure Low
    - Service Error
  - Form an appropriate code and send the message from board1 to board2 via parallel communication.
  - `Case 1`: Generate a random number from 1-6 in board1 and let that be the state to transmit to board2. Display appropriate messages on both serial terminals.
  - `Case 2`: Read a text file having a pre-generated state sequence, using a Python program. The Python code uses pyserial and sends the inputs to board1. Board1 does parallel communication with board2. Verify that the serial monitor of board2 has the same data as in the CSV file.

  ![image](https://github.com/SKundawal/Internet-Of-Things/assets/61798659/1cb1b810-e620-4eb8-8fc4-5672cdbedc82)
  - The code must be modular. In the board2, a function called getInput() reads the inputs. Comment the appropriate part based on Case 1 or Case 2

