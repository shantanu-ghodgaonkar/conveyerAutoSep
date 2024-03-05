# conveyerAutoSep

Automatic Package Separator with Arduino
Abstract:

This project builds an innovative Automatic Package Separator system using Arduino technology. It aims to streamline and enhance the efficiency of package segregation based on their addresses.

<video width="320" height="240" controls autoplay>
  <source src='/IMG_8251.mp4' type='video/mp4'>
  Your browser does not support the video tag.
</video>


Key Components:

Arduino Microcontroller: Manages the system, integrating various components and enabling communication.
1D/2D Barcode Scanner: Uses Waveshare scanner with UART protocol for accurate address reading.
Servo Motors: Control the conveyor system, ensuring precise package movement.
DC Motor: Converts electrical energy into rotational movement for the conveyor.
Ultrasonic Sensor: Measures distances for object detection and avoidance.
LCD Display Module: Provides real-time information.
Operational Overview:

Address Detection: The 2D barcode scanner reads package addresses quickly and accurately.
Conveyor Actuation: Arduino and servo motors control the conveyor. Upon address detection, the motors guide packages towards designated bins.
Segregation Mechanism: Servo motors divert packages to specific bins based on their barcode addresses.
Introduction:

This project addresses the demand for innovative solutions in logistics and supply chain management, specifically focusing on package handling optimization. It introduces an Arduino-driven Automatic Package Separator to revolutionize the process using 1D/2D barcode scanning.

Problem Statement:

Traditional manual sorting processes are time-consuming, error-prone, and resource-intensive. This project aims to automate package segregation based on addresses, mitigating errors and increasing efficiency.

Technological Foundation:

Arduino Uno Microcontroller: The project's core, chosen for its compact size and capabilities.
1D/2D Barcode Scanner (Waveshare): Reads 1D/2D barcodes accurately and efficiently.
Operational Mechanism:

Address Detection: The barcode scanner reads package addresses as they pass through the scanning point.
Arduino Uno Control: The Arduino processes scanned information, interpreting the package's destination.
Conveyor Mechanism: A DC motor, controlled by Arduino, actuates the conveyor. Upon address detection, the Arduino commands servo motors to guide the package towards the designated bin.
Segregation Mechanism: A dual-axis turntable with servo motors rotates along two axes, allowing packages to be directed to specific bins.
Components:

Servo Motors: Two control rotation on each axis.
Turntable Platform: Holds the object being rotated.
Turntable Mount: Holds the servo motors, mounted on the conveyor body.
Base Structure: Supports the turntable platform for stability.
Parallax PING))) Ultrasonic Sensor: Measures distances for object detection.
Relay: An electrically operated switch.
LCD Display Module: Provides real-time information.
Technological Choice:

2D barcode scanning is chosen for its proven simplicity and efficiency, enhancing address detection accuracy.

Project Objectives:

Minimize manual effort.
Decrease sorting errors.
Significantly improve speed and accuracy.
Future Enhancements:

Machine Learning Integration: Optimize sorting algorithms based on data, package types, and destinations.
Robotics Integration: Explore robots for automated package handling.
Cascaded Network of Modules: Integrate multiple systems for multilevel sorting.
This document serves as a comprehensive overview of the Automatic Package Separator project. It details the system design, functionalities, and potential future enhancements.
