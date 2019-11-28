void sensorTemp()
{
    display.print(F("Temperature: "));
    display.print(bme.temperature);
    display.print((char)247);
    display.println(F("C"));

    display.print("Pressure: ");
    display.print(bme.pressure / 100.0);
    display.println(" hPa");

    display.print("Humidity: ");
    display.print(bme.humidity);
    display.println(" %");

    display.print("Gas: ");
    display.print(bme.gas_resistance / 1000.0);
    display.println(" KOhms");

    display.display();
}
