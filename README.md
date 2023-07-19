# UNDOCUMENTED Windows API

Some information on the undocumented Windows API I have discovered.

## DisplayConfigGetDeviceInfo
1. DisplayConfigGetDeviceInfo(-3) or DisplayConfigGetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_TYPE_UNDOC::DISPLAYCONFIG_DEVICE_INFO_GET_DPI_SCALE)
Get DPI scaling information for a display.
  - Minimum DPI scaling
  - Maximum DPI scaling
  - Currently applied DPI scaling value
  - Recommended DPI scaling value

REFER(1): https://github.com/lihas/windows-DPI-scaling-sample/tree/master
REFER(2): https://stackoverflow.com/questions/35233182/how-can-i-change-windows-10-display-scaling-programmatically-using-c-sharp

2. DisplayConfigGetDeviceInfo(-4) or DisplayConfigGetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_TYPE_UNDOC::DISPLAYCONFIG_DEVICE_INFO_SET_DPI_SCALE)
Set current DPI scaling value for a display

REFER(1): https://github.com/lihas/windows-DPI-scaling-sample/tree/master
REFER(2): https://stackoverflow.com/questions/35233182/how-can-i-change-windows-10-display-scaling-programmatically-using-c-sharp

3. DisplayConfigGetDeviceInfo(-7) or DisplayConfigGetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_TYPE_UNDOC::DISPLAYCONFIG_DEVICE_INFO_GET_MONITOR_BRIGHTNESS_INFO)
Get monitor brightness info
  - Brightness range supported in nits
  - min luminance
  - max luminance

REFER: Windows_Graphics!Windows::Devices::Display::DisplayMonitor::RuntimeClassInitialize (Windows.Graphics.dll)


4. DisplayConfigGetDeviceInfo(-7) or DisplayConfigGetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_TYPE_UNDOC::DISPLAYCONFIG_DEVICE_INFO_GET_MONITOR_INTERNAL_INFO)
This is an alias for DISPLAYCONFIG_DEVICE_INFO_GET_MONITOR_BRIGHTNESS_INFO as the API returns info more than just brightness.
Info other than brightness:
  - Display tech
  - Native Height
  - Native Width
  - Physical Width in mm
  - Physical Height in mm

REFER: Windows_Graphics!Windows::Devices::Display::DisplayMonitor::RuntimeClassInitialize (Windows.Graphics.dll)


5. DisplayConfigGetDeviceInfo(-8) or DisplayConfigGetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_TYPE_UNDOC::DISPLAYCONFIG_DEVICE_INFO_GET_MONITOR_EDID)
Get display edid.
  - Edid in 1280 byte buffer
  - Length of returned EDID block in bytes

REFER: Windows_Graphics!Windows::Devices::Display::DisplayMonitor::RuntimeClassInitialize (Windows.Graphics.dll)


6. DisplayConfigGetDeviceInfo(-13) or DisplayConfigGetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_TYPE_UNDOC::DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_INFO)
Get target info.
  - Output technology
  - Usage: Standard, Head mounted, Special use
  - Virtual mode disabled
  - Virtual topology disabled
  - Virtual target mode disabled

REFER: Windows_Graphics!Windows::Devices::Display::DisplayMonitor::RuntimeClassInitialize (Windows.Graphics.dll)

7. DisplayConfigGetDeviceInfo(-15) or DisplayConfigGetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_TYPE_UNDOC::DISPLAYCONFIG_DEVICE_INFO_GET_DISPLAY_ID_DATA)
Get display ID data.
Perhaps this is used in 2 steps, first to get buffer size, and then calling the api by passing buffer
of required length.

REFER: Windows_Graphics!Windows::Devices::Display::DisplayMonitor::RuntimeClassInitialize (Windows.Graphics.dll)