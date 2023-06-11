# EE536 Internet Of Things - Assignment 4
### Objective: NodeMCU Time Client: Retrieving Time from Raspberry Pi Time Server.

### Tasks
- Create a time client program in NodeMCU which behaves as shown below.
  ```
  Press T or t to get the time
  <user presses T or t key>
  Connecting to server...
  Response: Time is now: HH:MM:SS
  ```
- The client connectes to a time server running in Rpi. The connection is via Wifi.
- The time server runs in the Rpi and listens on a specific port. Once a valid message is received, send the time to the client. For other inputs, print an error message.
 
