# Brass Thumb Pomodoro Assembly Guide

Welcome to the assembly guide for the Brass Thumb Pomodoro, your steampunk productivity timer. This guide is divided into two parts: 

1. **Preparation**: Assemble smaller components.
2. **Main Assembly**: Combine parts into the final device.

**Prerequisites**: Complete each step sequentially for a smooth assembly.

**Tools needed**: Mini screwdriver, USB power source.

Let's get started!

## Preparation

Before we dive into the main assembly of the Brass Thumb Pomodoro, we'll start by preparing a few smaller components. This step is essential as it will make the final assembly smoother and more efficient. Let's prepare each part carefully.

### Device Top Cover

**Mount Gauge Vent**: Place the `gauge_vent.stl` into the `gauge_cap.stl` as shown. Secure it with two M2x8 screws. 

![Mount Gauge Vent](img/assembly_001.png)

**Mount Gauge Gear**: Insert the `gauge_gear_small.stl` into the designated slot in `gauge_cap.stl`. Use one M2x16 screw to secure it in place.

![Mount Gauge Gear](img/assembly_002.png)

### Thumb Up Popup

Prepare the popup mechanism for the Brass Thumb Pomodoro by following these steps:

Insert the 10mm diameter, 5mm height cylinder magnet into the bay of the `gauge_popup.stl` as shown in the image. The magnet's orientation is not important at this stage.

![Insert Magnet](img/assembly_003.png)

Ensure the magnet fits snugly in the bay. If it’s loose, secure it using adhesive tape on the sides.

### Magnetic Handle
Use the cylinder magnet (D=10mm, h=5mm) as shown below. The orientation of the magnet does not matter at this stage. Place the magnet securely in the bay of `gauge_handle.stl`. If it is loose, use adhesive tape on the sides to tighten it.

![Insert Magnet](img/assembly_004.png)

### Rack Gear

Insert the M2x8 screw through the hole from the bottom side of the rack gear (`gauge_slider.stl`) and tighten it until firmly held in place. This will be used later to mount other elements.

![Rack Gear Assembly](img/assembly_005.png)

![Rack Gear Assembly](img/assembly_006.png)

## Main Assembly of the Device

With all the smaller components prepared, it's time to bring everything together to complete your Brass Thumb Pomodoro. The following steps will guide you through assembling the main parts of the device, connecting the Arduino board and servo, and securing everything into the final, functional timer. Follow each step carefully to ensure all components fit together seamlessly, and your device operates smoothly.

### Install Scale

Align the `gauge_scale_body.stl` with the dovetail joints on the `gauge_case.stl` housing. Carefully slide the `gauge_scale_body.stl` into the joints, ensuring it is placed securely and flush with the main housing. 

![Install Scale Parts](img/assembly_007.png)
![Installed Scale](img/assembly_008.png)

### Add Rack Gear

Insert the previously assembled rack gear (`gauge_slider.stl`) into the guide slot in the main body. Ensure the gear teeth face towards the inner mechanism and the rack gear can move freely sideways.

![Add Rack Gear](img/assembly_009.png)

### Mount Pointer

Use the screw delivered with the servo to attach the pointer (`gauge_pointer.stl`) to the servo. Insert the screw through the center hole of the pointer and secure it into the servo as shown below.

![Mount Pointer](img/assembly_010.png)

Proper pointer positioning is crucial. Follow these steps to ensure accuracy:

1. Set the mode switch to the neutral (central) position.
2. Power up the Arduino. This will cause the servo to move back and forth, eventually stopping at the most left position.

In this position, the pointer should be oriented to point left. Ensure the pointer can move smoothly through 90 degrees (pointing up) and up to 180 degrees (pointing right).

Make sure the servo is oriented correctly with the longer part on the right as illustrated below.

![Pointer Position](img/assembly_011.png)

### Mount Servo

Slide the servo into the housing (`gauge_case.stl`) into the dedicated bay as shown in the image.

![Slide Servo into Housing](img/assembly_012.png)

Make sure the gear on the pointer (`gauge_pointer.stl`) is properly positioned to the rack gear (`gauge_slider.stl`). The gear teeth should fit together perfectly. Ensure that the pointer of the servo is pointing to the left, while the pin mount of the rack gear should be placed to the most right in its slot as displayed in the image below.

![Proper Gear Positioning](img/assembly_013.png)

### Mount Arduino Board

Slide the Arduino board into the housing (`gauge_case.stl`) in the dedicated slot, above the servo.

![Arduino Placement](img/assembly_014.png)

Make sure the Arduino board is securely and properly installed, with the USB port facing outward for easy access.

![Arduino Placement Complete](img/assembly_015.png)

### Mount Switch

Place the three-position mode switch into the mounting hole of `gauge_case.stl`.

![Place Switch](img/assembly_016.png)

Position the mode tag (`gauge_tag.stl`) on the switch with the correct orientation (ensure the heart symbol is at the top). Secure the tag with the screw nut provided.

![Attach Tag](img/assembly_017.png)

Ensure the switch and tag are firmly in place, as shown below.

![Completed Switch Installation](img/assembly_018.png)

### Install Magnetic Handler

### Install Thumb Up Popup

### Install Top Cover

### Install Scale Decors
