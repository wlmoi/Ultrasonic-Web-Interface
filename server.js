// server.js
const express = require('express');
const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');

const app = express();
const port = process.env.PORT || 3000;

// Set up serial port
const serialPort = new SerialPort({ path: 'COM10', baudRate: 9600 });
const parser = serialPort.pipe(new ReadlineParser({ delimiter: '\n' }));

let latestDistance = 'No data';

parser.on('data', (data) => {
    console.log('Distance:', data);
    latestDistance = data.trim();
});

// Serve static files from the root directory
app.use(express.static(__dirname)); // Serve files from the root

app.get('/api/distance', (req, res) => {
    res.json({ distance: latestDistance });
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});
