#pragma once
#include <Windows.h>
#include <cinttypes>

namespace WindowsUndocumentedLib {
    //-13
    typedef enum DISPLAYCONFIG_TARGET_USAGE {
        DISPLAYCONFIG_TARGET_USAGE_STANDARD = 0,
        DISPLAYCONFIG_TARGET_USAGE_HEAD_MOUNTED = 1,
        DISPLAYCONFIG_TARGET_USAGE_SPECIAL_USE = 2
    } DISPLAYCONFIG_TARGET_USAGE;


    struct DISPLAYCONFIG_GET_TARGET_INFO_INTERNAL_u_32_s_0 {
        unsigned int IsVirtualModeDisabled : 1;
        unsigned int IsVirtualTopologyDisabled : 1;
        unsigned int IsVirtualTargetModeDisabled : 1;
    };

    union DISPLAYCONFIG_GET_TARGET_INFO_INTERNAL_u_32 {
        struct DISPLAYCONFIG_GET_TARGET_INFO_INTERNAL_u_32_s_0 _s_0;
        unsigned int Value;
    };

    struct DISPLAYCONFIG_GET_TARGET_INFO_INTERNAL {
        struct DISPLAYCONFIG_DEVICE_INFO_HEADER header;
        enum DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY outputTechnology;
        enum DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY baseOutputTechnology;
        enum DISPLAYCONFIG_TARGET_USAGE Usage;
        union DISPLAYCONFIG_GET_TARGET_INFO_INTERNAL_u_32 field4_0x20;
    };

    //-7
    struct _DISPLAYCONFIG_BRIGHTNESS_CAPS_u_312_s_0 {
        unsigned int bLegacySupported : 1;
        unsigned int bNitsSupported : 1;
        unsigned int bCalibrated : 1;
        unsigned int bSmoothBrightnessSupported : 1;
        unsigned int bAdaptiveBrightnessSupported : 1;

    };

    struct _DISPLAYCONFIG_BRIGHTNESS_NIT_RANGE {
        unsigned int MinMillinits;
        unsigned int MaxMillinits;
        unsigned int StepSizeMillinits;
    };

    union _DISPLAYCONFIG_BRIGHTNESS_CAPS_u_312 {
        struct _DISPLAYCONFIG_BRIGHTNESS_CAPS_u_312_s_0 _s_0;
        unsigned int value;
    };

    struct _DISPLAYCONFIG_BRIGHTNESS_CAPS {
        unsigned char LegacyLevels[101];
        unsigned int LegacyLevelCount;
        struct _DISPLAYCONFIG_BRIGHTNESS_NIT_RANGE NitRanges[16];
        unsigned int NormalRangeCount;
        unsigned int TotalRangeCount;
        unsigned int PreferredMaximumBrightness;
        union _DISPLAYCONFIG_BRIGHTNESS_CAPS_u_312 field6_0x138;
    };

    struct _DISPLAYCONFIG_GET_MONITOR_INTERNAL_INFO {
        struct DISPLAYCONFIG_DEVICE_INFO_HEADER header;
        wchar_t monitorUniqueName[260];
        unsigned int RedPrimary[2];
        unsigned int GreenPrimary[2];
        unsigned int BluePrimary[2];
        unsigned int WhitePoint[2];
        unsigned long MinLuminance;
        unsigned long MaxLuminance;
        unsigned long MaxFullFrameLuminance;
        std::int32_t ColorspaceSupport;//4 bytes
        std::int32_t Flags;//4 bytes
        struct _DISPLAYCONFIG_BRIGHTNESS_CAPS BrightnessCaps;
        unsigned int UsageSubClass;
        unsigned int DisplayTech;
        unsigned int NativeWidth;
        unsigned int NativeHeight;
        unsigned int PhysicalWidthInMm;
        unsigned int PhysicalHeightInMm;
        enum DISPLAYCONFIG_ROTATION DockedOrientation;
        enum _DISPLAYCONFIG_HDR_CERTIFICATIONS DisplayHdrCertifications;
    };

    //-3, -4
    static const UINT32 DpiVals[] = { 100,125,150,175,200,225,250,300,350, 400, 450, 500 };

    /*
        * struct DISPLAYCONFIG_SOURCE_DPI_SCALE_GET
        * @brief used to fetch min, max, suggested, and currently applied DPI scaling values.
        * All values are relative to the recommended DPI scaling value
        * Note that DPI scaling is a property of the source, and not of target.
        */
    struct DISPLAYCONFIG_SOURCE_DPI_SCALE_GET
    {
        DISPLAYCONFIG_DEVICE_INFO_HEADER            header;
        /*
        * @brief min value of DPI scaling is always 100, minScaleRel gives no. of steps down from recommended scaling
        * eg. if minScaleRel is -3 => 100 is 3 steps down from recommended scaling => recommended scaling is 175%
        */
        std::int32_t minScaleRel;

        /*
        * @brief currently applied DPI scaling value wrt the recommended value. eg. if recommended value is 175%,
        * => if curScaleRel == 0 the current scaling is 175%, if curScaleRel == -1, then current scale is 150%
        */
        std::int32_t curScaleRel;

        /*
        * @brief maximum supported DPI scaling wrt recommended value
        */
        std::int32_t maxScaleRel;
    };

    /*
       * struct DISPLAYCONFIG_SOURCE_DPI_SCALE_SET
       * @brief set DPI scaling value of a source
       * Note that DPI scaling is a property of the source, and not of target.
       */
    struct DISPLAYCONFIG_SOURCE_DPI_SCALE_SET
    {
        DISPLAYCONFIG_DEVICE_INFO_HEADER            header;
        /*
        * @brief The value we want to set. The value should be relative to the recommended DPI scaling value of source.
        * eg. if scaleRel == 1, and recommended value is 175% => we are trying to set 200% scaling for the source
        */
        int32_t scaleRel;
    };

    enum class DISPLAYCONFIG_DEVICE_INFO_TYPE_UNDOC : int
    {
        DISPLAYCONFIG_DEVICE_INFO_GET_DPI_SCALE = -3, //returns min, max, suggested, and currently applied DPI scaling values.
        DISPLAYCONFIG_DEVICE_INFO_SET_DPI_SCALE = -4, //set current dpi scaling value for a display
        DISPLAYCONFIG_DEVICE_INFO_GET_MONITOR_BRIGHTNESS_INFO = -7, //Get monitor brightness info
        DISPLAYCONFIG_DEVICE_INFO_GET_MONITOR_INTERNAL_INFO = DISPLAYCONFIG_DEVICE_INFO_GET_MONITOR_BRIGHTNESS_INFO, //alias for DISPLAYCONFIG_DEVICE_INFO_GET_MONITOR_BRIGHTNESS_INFO since it returns values other than brightness
        DISPLAYCONFIG_DEVICE_INFO_GET_MONITOR_EDID = -8, //Get monitor EDID
        DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_INFO = -13, //Get target info
        DISPLAYCONFIG_DEVICE_INFO_GET_DISPLAY_ID_DATA = -15, //Get display ID data
    };
}