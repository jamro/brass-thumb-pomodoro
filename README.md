# Brass Thumb Pomodoro

## Building and Uploading to Arduino Nano

Follow these detailed instructions to build and upload the Brass Thumb Pomodoro project to your Arduino Nano.

### Step 1: Locate the Arduino Sketch Folder

The Arduino IDE stores sketches (projects) in a predefined location known as the "Sketchbook" folder. To find out where this folder is located on your system:

1. Open the Arduino IDE.
2. Go to `File` -> `Preferences`.
3. In the `Preferences` window, locate the `Sketchbook location:` field. This shows the directory where your sketches are stored.

### Step 2: Create the Project Directory

1. Navigate to the Sketchbook location using your file explorer or terminal.
2. Inside the Sketchbook folder, create a new subfolder named `brass-thumb-pomodoro`.

### Step 3: Move Source Files

1. Copy all contents from the `/src` folder of the Brass Thumb Pomodoro project (e.g., `brass-thumb-pomodoro.ino`, `config.h`, `lib/Clock.h`, `lib/Clock.cpp`, and any other necessary files).
2. Paste these files into the `brass-thumb-pomodoro` folder you just created in your Sketchbook directory.

Your folder structure should look like this:
```
Arduino/Sketchbook/
    └── brass-thumb-pomodoro/
        ├── brass-thumb-pomodoro.ino
        ├── config.h
        └── lib/
            ├── Clock.h
            ├── Clock.cpp
            └── ... (other library files)
```

### Step 4: Open the Project in Arduino IDE

1. In the Arduino IDE, go to `File` -> `Sketchbook`.
2. You should see a list of folders within your Sketchbook directory. Click on `brass-thumb-pomodoro`.

This will open the `brass-thumb-pomodoro.ino` file in the Arduino IDE.

### Step 5: Select Arduino Nano

1. Connect your Arduino Nano to your computer via USB.
2. In the Arduino IDE, go to `Tools` -> `Board` and select `Arduino Nano`.
3. Still under `Tools`, select the appropriate processor. Usually, this is `ATmega328P (Old Bootloader)` or `ATmega328P`, depending on your specific Nano version.
4. Under `Tools` -> `Port`, select the port to which the Arduino Nano is connected (e.g., `COM3` on Windows or `/dev/ttyUSB0` on Linux).

### Step 6: Build and Upload

1. To ensure that all components are compiled correctly, click the checkmark (✓) button in the upper-left corner of the Arduino IDE. This runs a verify/compile check.
   - If there are any errors, review the messages in the console for guidance on fixing them.
2. Once the code compiles without errors, click the right-arrow (→) button (Upload) to upload the code to the Arduino Nano.

### Troubleshooting

- **Compilation Errors**: Ensure that all necessary files are within the `brass-thumb-pomodoro` folder. Missing files can cause compilation issues.
- **Port Issues**: Verify that the correct port is selected under `Tools` -> `Port`. You may need to disconnect and reconnect the USB cable or restart the Arduino IDE to resolve port detection issues.
- **Board Not Detected**: Make sure drivers for the Arduino Nano are correctly installed. Some unofficial Nanos require the installation of additional CH340 drivers.

Congratulations! You have successfully built and uploaded the Brass Thumb Pomodoro project to your Arduino Nano. Enjoy increased productivity with your new steampunk-inspired Pomodoro timer!