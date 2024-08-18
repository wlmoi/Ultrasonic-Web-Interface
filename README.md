# Ultrasonic-Web-Interface
Uses static web to project the result.
MBC Project 5A -> William Anthony 13223048


### 1. Arduino Code

The `ultrasonic_sensor.ino` file contains the Arduino code that reads distance data from an ultrasonic sensor and sends it over the serial port.

### 2. Frontend Code

The `frontend` directory contains the HTML, JavaScript, and CSS files for the web interface.

### 3. Backend Code

The `server` directory contains the Node.js server that reads data from the Arduino and provides it to the frontend via an API.

### 4. Vercel Deployment

- The frontend is configured to be deployed on Vercel, serving the HTML file from the `frontend` directory.

### 5. Getting Started

RUN "node server.js"

#### Arduino

1. Open `arduino/ultrasonic_sensor.ino` in the Arduino IDE.
2. Upload the code to your Arduino board.

#### Node.js Server

1. Navigate to the `server` directory.
2. Install dependencies:
   ```bash
   npm install
