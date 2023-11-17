## How to Use the Library

### Understanding the Library - Files on the Programming Guide Folder
- **API Documentation:** Provides details about the library's functions. It's essential to get acquainted with these to effectively utilize the library.
- **Programming Guide:** Explains the design of the library and offers guidance on how to use it. Please read the files in the programming guide section to gain a comprehensive understanding.
- **Changes from the original:** The name of the functions its diferent from the api documentation and programming guide, the only modification its the rtk_ to rtl_ on the start of the function names.

### About This Library
To use include the 'rtl_api.hpp' on your project.

The classes is divided for each function parts, please see the rtl_api.hpp file and each class file for more details.

Example:
```c++
#include "rtl_api.hpp"

// Create a new instance of the class
rtl_api rtl;

// Probe the switch chip and get the chip information
switch_chip_t chip;
rtl.rtlSwitch.rtl_switch_probe(&chip);

// Inicialize the switch chip
rtl.rtlSwitch.rtl_switch_init();

// Read the port information
rtl.port.rtl_port_phyStatus_get([portVariables]);
```

### New functions and features
The clearVlan function was added to the library, it's used to clear all the vlans on the switch, to use call the rtl.vlan.clearVlan('vlanId').

You can also change the sda and scl pins on the library, just call the rtl.changeI2cPins(sdaPin,sclPin).

To change the i2c delay use the rtl.changeI2cDelay(delayMs), the default value is 1ms.

To reset the switch use the rtl.reset() function.