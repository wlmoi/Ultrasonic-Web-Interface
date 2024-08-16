// server/index.js

const express = require('express');
const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');

const app = express();
const port = 3000;

// COM10 itu portnya yang digunakan dalam laptop aku @wlmoi
const serialPort = new SerialPort('/dev/COM10', { baudRate: 9600 });
const parser = serialPort.pipe(new Readline({ delimiter: '\n' }));

parser.on('data', (data) => {
  console.log('Distance:', data);
});

app.get('/distance', (req, res) => {
  parser.once('data', (data) => {
    res.send(data.trim());
  });
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});

