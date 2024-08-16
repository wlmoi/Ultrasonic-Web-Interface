const express = require('express');
const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');

const app = express();
const port = process.env.PORT || 3000;

// Replace 'COM10' with your correct serial port path
const serialPort = new SerialPort({ path: 'COM10', baudRate: 9600 });
const parser = serialPort.pipe(new ReadlineParser({ delimiter: '\n' }));

let latestDistance = 'No data';

parser.on('data', (data) => {
    console.log('Distance:', data);
    latestDistance = data.trim();
});

app.get('/api/distance', (req, res) => {
    res.json({ distance: latestDistance });
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});
