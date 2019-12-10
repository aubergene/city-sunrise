// I made this so I could log out readings from the BME680 over serial
// and write them to a TSV file for later analysis

const SerialPort = require("serialport");
const Readline = require("@serialport/parser-readline");

const port = new SerialPort("/dev/cu.usbmodem14201", function(err) {
  if (err) {
    return console.log("Error: ", err.message);
  }
});

const parser = port.pipe(new Readline({ delimiter: "\r\n" }));
parser.on("data", d => {
  console.log(new Date() + "\t" + d);
});
