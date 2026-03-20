# ESP32S Rotary Encoder Test

### Description

This project demonstrates how to interface a rotary encoder with an ESP32 (NodeMCU-32S) using PlatformIO. The code implements:
-   **Rotational Tracking:** Uses interrupts on the CLK pin to detect movement and determine the direction of rotation (clockwise or anticlockwise).
-   **Serial Feedback:** Outputs the current rotation count and direction to the Serial Monitor at 9600 baud.
-   **Push Button Detection:** Monitors the integrated push button on the rotary encoder, reporting "Pressed" or "Released" states with basic debouncing.
-   **Non-Blocking Logic:** The rotation detection is interrupt-driven for accuracy, while the main loop handles display and button state updates.


### Parts

- NodeMCU-ESP32S (Select NodeMCU-32S on PlatformIO)
- Rotary Encoder Switch

### Rotary Encoder Switch

<img width="697" height="517" alt="image" src="https://github.com/user-attachments/assets/898070ce-cee9-4a60-ac1f-af258750d97f" />

- source: [pixelelectric.com](https://www.pixelelectric.com/potentiometer-module/360-degrees-rotary-encoder-switch/)

**Connections**

- CLK = GPIO 18
- DT = GPIO 19 
- SW = GPIO 21
- (+) = 3V3
- GND = GND
