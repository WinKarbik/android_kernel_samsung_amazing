/*.......................................................................................................
. COPYRIGHT (C)  SAMSUNG Electronics CO., LTD (Suwon, Korea). 2009
. All rights are reserved. Reproduction and redistiribution in whole or
. in part is prohibited without the written consent of the copyright owner.
.
.   Developer:
.   Date:
.   Description:
..........................................................................................................
*/
#if !defined(_CAMACQ_S5K4ECGX_H_)
#define _CAMACQ_S5K4ECGX_H_

/* Include */
#include "camacq_api.h"

/* Global */
#undef GLOBAL

#if !defined(_CAMACQ_API_C_)
#define GLOBAL extern
#else
#define GLOBAL
#endif /* _CAMACQ_API_C_ */

/* Include */
#if defined(WIN32)
#include "cmmfile.h"
#endif /* WIN32 */

/* Definition */
#define __S5K4ECGX_EVT1__         // Option             

#define CAMACQ_MAIN_NAME         "cami2c_main"               // wingi
#define CAMACQ_MAIN_I2C_ID       0x5A                // don't use now.
#define CAMACQ_MAIN_RES_TYPE   	 CAMACQ_SENSOR_MAIN   // main sensor

#define CAMACQ_MAIN_ISPROBED     0
#define CAMACQ_MAIN_CLOCK        0
#define CAMACQ_MAIN_YUVORDER     0
#define CAMACQ_MAIN_V_SYNCPOL    0
#define CAMACQ_MAIN_H_SYNCPOL    0
#define CAMACQ_MAIN_SAMPLE_EDGE  0
#define CAMACQ_MAIN_FULL_RANGE   0

#define CAMACQ_MAIN_RST
#define CAMACQ_MAIN_RST_MUX
#define CAMACQ_MAIN_EN
#define CAMACQ_MAIN_EN_MUX

#define CAMACQ_MAIN_RST_ON          1
#define CAMACQ_MAIN_RST_OFF         0
#define CAMACQ_MAIN_EN_ON           1
#define CAMACQ_MAIN_EN_OFF          0
#define CAMACQ_MAIN_STANDBY_ON      1
#define CAMACQ_MAIN_STANDBY_OFF	    0

#define CAMACQ_MAIN_POWER_CTRL(onoff)

#define CAMACQ_MAIN_2BYTE_SENSOR    0
#define CAMACQ_MAIN_AF              0
#define CAMACQ_MAIN_INT_MODE        1   // 0xAABBCCDD is INT_MODE, 0xAA, 0xBB, 0xCC, 0xDD is ARRAY MODE
#define CAMACQ_MAIN_FS_MODE         0
#define CAMACQ_MAIN_PATH_SET_FILE   "/mnt/sdcard/sensor/%s.dat"

#if (CAMACQ_MAIN_2BYTE_SENSOR)
#define CAMACQ_MAIN_BURST_MODE 1
#define CAMACQ_MAIN_I2C_NUM_OF_BYTE 2//add for burst
#else
#define CAMACQ_MAIN_BURST_MODE 1
#define CAMACQ_MAIN_I2C_NUM_OF_BYTE 4//add for burst
#endif /* CAMACQ_MAIN2BYTE_SENSOR */

#define CAMACQ_MAIN_BURST_I2C_TRACE 0
#define CAMACQ_MAIN_BURST_MAX 100

#define CAMACQ_MAIN_REG_FLAG_BURST 	0x0E//add for burst

#define CAMACQ_MAIN_REG_FLAG_CNTS 	0x0F12
#define CAMACQ_MAIN_REG_DELAY 		0xFEFE
#define CAMACQ_MAIN_BTM_OF_DATA 	0xFFFFFFFF
#define CAMACQ_MAIN_END_MARKER 		0xFF
#define CAMACQ_MAIN_REG_SET_SZ 		1 	// {0xFFFFFFFF} is 1, {0xFFFF,0xFFFF} is 2, {0xFF,0XFF} is 2, {0xFF,0xFF,0xFF,0xFF} is 4, {0xFFFF} is 1
#define CAMACQ_MAIN_REG_DAT_SZ 		4   // {0xFFFFFFFF} is 4, {0xFFFF,0xFFFF} is 2, {0xFF,0XFF} is 1, {0xFF,0xFF,0xFF,0xFF} is 1, {0xFFFF} is 2
#define CAMACQ_MAIN_FRATE_MIN  5
#define CAMACQ_MAIN_FRATE_MAX  30





#define EXT_CFG_AF_CHECK_STATUS		0
#define EXT_CFG_AF_OFF			1
#define EXT_CFG_AF_SET_NORMAL		2
#define EXT_CFG_AF_SET_MACRO		3
#define EXT_CFG_AF_DO			4
#define EXT_CFG_AF_SET_MANUAL	5
#define EXT_CFG_AF_CHECK_2nd_STATUS	6
#define EXT_CFG_AF_SET_AE_FOR_FLASH	7
#define EXT_CFG_AF_BACK_AE_FOR_FLASH	8
#define EXT_CFG_AF_CHECK_AE_STATUS	9
#define EXT_CFG_AF_POWEROFF 	10
#define EXT_CFG_AF_PROGRESS                1
#define EXT_CFG_AF_SUCCESS                 2
#define EXT_CFG_AF_LOWCONF                 3 //Fail
#define EXT_CFG_AF_CANCELED                4
#define EXT_CFG_AF_TIMEOUT                 5
#define EXT_CFG_AE_STABLE               6
#define EXT_CFG_AE_UNSTABLE                 7

#define EXT_CFG_AE_LOCK		0
#define EXT_CFG_AE_UNLOCK		1
#define EXT_CFG_AWB_LOCK		2
#define EXT_CFG_AWB_UNLOCK		3


// MACRO FUNCTIONS BEGIN ////////////////////////////////////////////////////////////
#if (CAMACQ_MAIN_2BYTE_SENSOR)
#define CAMACQ_MAIN_EXT_RD_SZ 1
#else
#define CAMACQ_MAIN_EXT_RD_SZ 2
#endif /* CAMACQ_MAIN_2BYTE_SENSOR */

#if CAMACQ_MAIN_2BYTE_SENSOR
#define CAMACQ_MAIN_EXT_REG_IS_BTM_OF_DATA(A)		(((A[0]==CAMACQ_MAIN_END_MARKER) && (A[1]==CAMACQ_MAIN_END_MARKER))? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_DELAY(A)				((A[0]==CAMACQ_MAIN_REG_DELAY)? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_BURST(A)				(((A[0]==CAMACQ_MAIN_REG_FLAG_BURST) && (A[1]==0x01))? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_BURST_END(A)				(((A[0]==CAMACQ_MAIN_REG_FLAG_BURST) && (A[1]==0x00))? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_CNTS(A)				(((A[0]==CAMACQ_MAIN_REG_FLAG_BURST) && (A[1]==0x01))? 1:0)
//add for burst

#if (CAMACQ_MAIN_FS_MODE==1)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)\
memcpy(dest, &(srce[idx*CAMACQ_MAIN_REG_DAT_SZ*CAMACQ_MAIN_REG_SET_SZ]), CAMACQ_MAIN_REG_DAT_SZ*CAMACQ_MAIN_REG_SET_SZ);
#elif (CAMACQ_MAIN_REG_DAT_SZ==1)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0] = (srce[idx][0] & 0xFF); dest[1] = (srce[idx][1] & 0xFF);
#elif (CAMACQ_MAIN_REG_DAT_SZ==2)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0] = ((U8)(srce[idx] >> 8) & 0xFF); dest[1] = ((U8)(srce[idx]) & 0xFF);
#endif

#else // CAMACQ_MAIN_2BYTE_SENSOR

#define CAMACQ_MAIN_EXT_REG_IS_BTM_OF_DATA(A)		(((A[0]==CAMACQ_MAIN_END_MARKER) && (A[1]==CAMACQ_MAIN_END_MARKER) && \
(A[2]==CAMACQ_MAIN_END_MARKER) && (A[3]==CAMACQ_MAIN_END_MARKER))? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_DELAY(A)				(((A[0]==((CAMACQ_MAIN_REG_DELAY>>8) & 0xFF)) && (A[1]==(CAMACQ_MAIN_REG_DELAY & 0xFF)))? 1:0)
#define CAMACQ_MAIN_EXT_REG_IS_CNTS(A)				(((A[0]==((CAMACQ_MAIN_REG_FLAG_CNTS>>8) & 0xFF)) && (A[1]==(CAMACQ_MAIN_REG_FLAG_CNTS & 0xFF)))? 1:0)

#if (CAMACQ_MAIN_FS_MODE==1)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)\
memcpy(dest, &(srce[idx*CAMACQ_MAIN_REG_DAT_SZ*CAMACQ_MAIN_REG_SET_SZ]), CAMACQ_MAIN_REG_DAT_SZ*CAMACQ_MAIN_REG_SET_SZ);
#elif (CAMACQ_MAIN_REG_DAT_SZ==2)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0]=((srce[idx][0] >> 8) & 0xFF); dest[1]=(srce[idx][0] & 0xFF); \
dest[2]=((srce[idx][1] >> 8) & 0xFF); dest[3]=(srce[idx][1] & 0xFF);
#elif (CAMACQ_MAIN_REG_DAT_SZ==1)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0]=srce[idx][0]; dest[1]=srce[idx][1]; \
dest[2]=srce[idx][2]; dest[3]=srce[idx][3];



#elif (CAMACQ_MAIN_REG_DAT_SZ==4)
#define CAMACQ_MAIN_EXT_REG_GET_DATA(dest,srce,idx)	dest[0] = ((U8)(srce[idx] >> 24) & 0xFF); dest[1] = ((U8)(srce[idx] >> 16) & 0xFF); \
dest[2] = ((U8)(srce[idx] >> 8) & 0xFF); dest[3] = ((U8)(srce[idx]) & 0xFF);
#endif
#endif /* CAMACQ_2BYTE_SENSOR */
// MACRO FUNCTIONS END ///////////////////////////////////////////////////////////


/* DEFINE for sensor regs*/
#if( CAMACQ_MAIN_FS_MODE )
#define CAMACQ_MAIN_REG_INIT            "INIT"
#define CAMACQ_MAIN_REG_PREVIEW         "PREVIEW"
#define CAMACQ_MAIN_REG_SNAPSHOT        "SNAPSHOT"
#define CAMACQ_MAIN_REG_CAMCORDER        "CAMCORDER"

#define CAMACQ_MAIN_REG_WB_AUTO                 "WB_AUTO"
#define CAMACQ_MAIN_REG_WB_DAYLIGHT             "WB_DAYLIGHT"
#define CAMACQ_MAIN_REG_WB_CLOUDY               "WB_CLOUDY"
#define CAMACQ_MAIN_REG_WB_INCANDESCENT         "WB_INCANDESCENT"
#define CAMACQ_MAIN_REG_WB_FLUORESCENT         "WB_FLUORESCENT"

#define CAMACQ_MAIN_REG_SCENE_AUTO              "SCENE_AUTO"
#define CAMACQ_MAIN_REG_SCENE_NIGHT             "SCENE_NIGHT"
#define CAMACQ_MAIN_REG_SCENE_NIGHT_DARK        "SCENE_NIGHT_DARK"
#define CAMACQ_MAIN_REG_SCENE_LANDSCAPE         "SCENE_LANDSCAPE"
#define CAMACQ_MAIN_REG_SCENE_PORTRAIT          "SCENE_PORTRAIT"
#define CAMACQ_MAIN_REG_SCENE_SPORTS            "SCENE_SPORTS"
#define CAMACQ_MAIN_REG_SCENE_INDOOR            "SCENE_INDOOR"
#define CAMACQ_MAIN_REG_SCENE_SUNSET            "SCENE_SUNSET"
#define CAMACQ_MAIN_REG_SCENE_SUNRISE           "SCENE_SUNRISE"    // dawn
#define CAMACQ_MAIN_REG_SCENE_BEACH             "SCENE_BEACH"
#define CAMACQ_MAIN_REG_SCENE_FALLCOLOR         "SCENE_FALLCOLOR"
#define CAMACQ_MAIN_REG_SCENE_FIREWORKS         "SCENE_FIREWORKS"
#define CAMACQ_MAIN_REG_SCENE_CANDLELIGHT       "SCENE_CANDLELIGHT"
#define CAMACQ_MAIN_REG_SCENE_AGAINSTLIGHT      "SCENE_AGAINSTLIGHT"  // backlight

#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_0      "BRIGHTNESS_LEVEL_0"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_1      "BRIGHTNESS_LEVEL_1"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_2      "BRIGHTNESS_LEVEL_2"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_3      "BRIGHTNESS_LEVEL_3"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_4      "BRIGHTNESS_LEVEL_4"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_5      "BRIGHTNESS_LEVEL_5"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_6      "BRIGHTNESS_LEVEL_6"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_7      "BRIGHTNESS_LEVEL_7"
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_8      "BRIGHTNESS_LEVEL_8"


#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_0      "CAMCORDER_BRIGHTNESS_LEVEL_0"
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_1      "CAMCORDER_BRIGHTNESS_LEVEL_1"
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_2      "CAMCORDER_BRIGHTNESS_LEVEL_2"
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_3      "CAMCORDER_BRIGHTNESS_LEVEL_3"
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_4      "CAMCORDER_BRIGHTNESS_LEVEL_4"
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_5      "CAMCORDER_BRIGHTNESS_LEVEL_5"
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_6      "CAMCORDER_BRIGHTNESS_LEVEL_6"
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_7      "CAMCORDER_BRIGHTNESS_LEVEL_7"
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_8      "CAMCORDER_BRIGHTNESS_LEVEL_8"


#define CAMACQ_MAIN_REG_METER_MATRIX            "METER_MATRIX"
#define CAMACQ_MAIN_REG_METER_CW                "METER_CW"
#define CAMACQ_MAIN_REG_METER_SPOT              "METER_SPOT"

#define CAMACQ_MAIN_REG_EFFECT_NONE             "EFFECT_NONE"
#define CAMACQ_MAIN_REG_EFFECT_GRAY             "EFFECT_GRAY" // mono, blackwhite
#define CAMACQ_MAIN_REG_EFFECT_NEGATIVE         "EFFECT_NEGATIVE"
#define CAMACQ_MAIN_REG_EFFECT_SEPIA            "EFFECT_SEPIA"

#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_M2              "CONTRAST_M2"
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_M1              "CONTRAST_M1"
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_DEFAULT         "CONTRAST_DEFAULT"
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_P1              "CONTRAST_P1"
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_P2              "CONTRAST_P2"

#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_M2             "SHARPNESS_M2"
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_M1             "SHARPNESS_M1"
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_DEFAULT        "SHARPNESS_DEFAULT"
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_P1             "SHARPNESS_P1"
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_P2             "SHARPNESS_P2"

#define CAMACQ_MAIN_REG_ADJUST_SATURATION_M2            "SATURATION_M2"
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_M1            "SATURATION_M1"
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_DEFAULT       "SATURATION_DEFAULT"
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_P1            "SATURATION_P1"
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_P2            "SATURATION_P2"

#define CAMACQ_MAIN_REG_JPEG_5M                 "JPEG_5M"
#define CAMACQ_MAIN_REG_JPEG_3M                 "JPEG_3M"
#define CAMACQ_MAIN_REG_JPEG_2M                 "JPEG_2M"
#define CAMACQ_MAIN_REG_JPEG_1M                 "JPEG_1M"

#define CAMACQ_MAIN_REG_PREVIEW_RETURN         "PREVIEWRETURN"

#define CAMACQ_MAIN_AE_LOCK                     "AE_LOCK"
#define CAMACQ_MAIN_AE_UNLOCK                   "AE_UNLOCK"
#define CAMACQ_MAIN_AWB_LOCK                    "AWB_LOCK"
#define CAMACQ_MAIN_AWB_UNLOCK                  "AWB_UNLOCK"
#define CAMACQ_MAIN_REG_SINGLE_AF_START         "SINGLE_AF_START"

#define CAMACQ_MAIN_REG_SET_AF_NORMAL_MODE_1    "SET_AF_NORMAL_MODE1"
#define CAMACQ_MAIN_REG_SET_AF_NORMAL_MODE_2    "SET_AF_NORMAL_MODE2"
#define CAMACQ_MAIN_REG_SET_AF_NORMAL_MODE_3    "SET_AF_NORMAL_MODE3"
#define CAMACQ_MAIN_REG_SET_AF_MACRO_MODE_1     "SET_AF_MACRO_MODE1"
#define CAMACQ_MAIN_REG_SET_AF_MACRO_MODE_2     "SET_AF_MACRO_MODE2"
#define CAMACQ_MAIN_REG_SET_AF_MACRO_MODE_3     "SET_AF_MACRO_MODE3"

#define CAMACQ_MAIN_REG_LOW_CAP_ON					"LOW_CAP_ON"
#define CAMACQ_MAIN_REG_LOW_CAP_OFF					"LOW_CAP_OFF"

#define	CAMACQ_MAIN_REG_4_ZOOM0 	"ZOOM40"
#define	CAMACQ_MAIN_REG_4_ZOOM1 	"ZOOM41"
#define	CAMACQ_MAIN_REG_4_ZOOM2 	"ZOOM42"
#define	CAMACQ_MAIN_REG_4_ZOOM3 	"ZOOM43"
#define	CAMACQ_MAIN_REG_4_ZOOM4 	"ZOOM44"
#define	CAMACQ_MAIN_REG_4_ZOOM5 	"ZOOM45"
#define	CAMACQ_MAIN_REG_4_ZOOM6 	"ZOOM46"
#define	CAMACQ_MAIN_REG_4_ZOOM7 	"ZOOM47"
#define	CAMACQ_MAIN_REG_4_ZOOM8 	"ZOOM48"

#define	CAMACQ_MAIN_REG_2_ZOOM0 	"ZOOM20"
#define	CAMACQ_MAIN_REG_2_ZOOM1 	"ZOOM21"
#define	CAMACQ_MAIN_REG_2_ZOOM2 	"ZOOM22"
#define	CAMACQ_MAIN_REG_2_ZOOM3 	"ZOOM23"
#define	CAMACQ_MAIN_REG_2_ZOOM4 	"ZOOM24"
#define	CAMACQ_MAIN_REG_2_ZOOM5 	"ZOOM25"
#define	CAMACQ_MAIN_REG_2_ZOOM6 	"ZOOM26"
#define	CAMACQ_MAIN_REG_2_ZOOM7 	"ZOOM27"
#define	CAMACQ_MAIN_REG_2_ZOOM8 	"ZOOM28"

#define	CAMACQ_MAIN_REG_1_6_ZOOM0 	"ZOOM160"
#define	CAMACQ_MAIN_REG_1_6_ZOOM1 	"ZOOM161"
#define	CAMACQ_MAIN_REG_1_6_ZOOM2 	"ZOOM162"
#define	CAMACQ_MAIN_REG_1_6_ZOOM3 	"ZOOM163"
#define	CAMACQ_MAIN_REG_1_6_ZOOM4 	"ZOOM164"
#define	CAMACQ_MAIN_REG_1_6_ZOOM5 	"ZOOM165"
#define	CAMACQ_MAIN_REG_1_6_ZOOM6 	"ZOOM166"
#define	CAMACQ_MAIN_REG_1_6_ZOOM7 	"ZOOM167"
#define	CAMACQ_MAIN_REG_1_6_ZOOM8 	"ZOOM168"

#define	CAMACQ_MAIN_REG_1_25_ZOOM0 	"ZOOM1250"
#define	CAMACQ_MAIN_REG_1_25_ZOOM1 	"ZOOM1251"
#define	CAMACQ_MAIN_REG_1_25_ZOOM2 	"ZOOM1252"
#define	CAMACQ_MAIN_REG_1_25_ZOOM3 	"ZOOM1253"
#define	CAMACQ_MAIN_REG_1_25_ZOOM4 	"ZOOM1254"
#define	CAMACQ_MAIN_REG_1_25_ZOOM5 	"ZOOM1255"
#define	CAMACQ_MAIN_REG_1_25_ZOOM6 	"ZOOM1256"
#define	CAMACQ_MAIN_REG_1_25_ZOOM7 	"ZOOM1257"
#define	CAMACQ_MAIN_REG_1_25_ZOOM8 	"ZOOM1258"


#else
#define CAMACQ_MAIN_REG_INIT            reg_main_init
#define CAMACQ_MAIN_REG_PREVIEW         reg_main_preview
#define CAMACQ_MAIN_REG_SNAPSHOT        reg_main_snapshot
#define CAMACQ_MAIN_REG_CAMCORDER      reg_main_camcorder

#define CAMACQ_MAIN_REG_WB_AUTO                 reg_main_wb_auto
#define CAMACQ_MAIN_REG_WB_DAYLIGHT             reg_main_wb_daylight
#define CAMACQ_MAIN_REG_WB_CLOUDY               reg_main_wb_cloudy
#define CAMACQ_MAIN_REG_WB_INCANDESCENT         reg_main_wb_incandescent
#define CAMACQ_MAIN_REG_WB_FLUORESCENT          reg_main_wb_fluorescent


#define CAMACQ_MAIN_REG_SCENE_AUTO              reg_main_scene_auto  // auto, off
#define CAMACQ_MAIN_REG_SCENE_NIGHT             reg_main_scene_night
#define CAMACQ_MAIN_REG_SCENE_NIGHT_DARK        reg_main_scene_night_dark
#define CAMACQ_MAIN_REG_SCENE_LANDSCAPE         reg_main_scene_landscape
#define CAMACQ_MAIN_REG_SCENE_PORTRAIT          reg_main_scene_portrait
#define CAMACQ_MAIN_REG_SCENE_SPORTS            reg_main_scene_sports
#define CAMACQ_MAIN_REG_SCENE_INDOOR            reg_main_scene_indoor
#define CAMACQ_MAIN_REG_SCENE_SUNSET            reg_main_scene_sunset
#define CAMACQ_MAIN_REG_SCENE_SUNRISE           reg_main_scene_sunrise    // dawn
#define CAMACQ_MAIN_REG_SCENE_BEACH             reg_main_scene_beach
#define CAMACQ_MAIN_REG_SCENE_FALLCOLOR         reg_main_scene_fallcolor
#define CAMACQ_MAIN_REG_SCENE_FIREWORKS         reg_main_scene_fireworks
#define CAMACQ_MAIN_REG_SCENE_CANDLELIGHT       reg_main_scene_candlelight
#define CAMACQ_MAIN_REG_SCENE_AGAINSTLIGHT      reg_main_scene_againstlight  // backlight

#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_0      reg_main_brightness_level_0
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_1      reg_main_brightness_level_1
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_2      reg_main_brightness_level_2
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_3      reg_main_brightness_level_3
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_4      reg_main_brightness_level_4
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_5      reg_main_brightness_level_5
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_6      reg_main_brightness_level_6
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_7      reg_main_brightness_level_7
#define CAMACQ_MAIN_REG_BRIGHTNESS_LEVEL_8      reg_main_brightness_level_8

#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_0      reg_main_ccd_brightness_level_0
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_1      reg_main_ccd_brightness_level_1
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_2      reg_main_ccd_brightness_level_2
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_3      reg_main_ccd_brightness_level_3
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_4      reg_main_ccd_brightness_level_4
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_5      reg_main_ccd_brightness_level_5
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_6      reg_main_ccd_brightness_level_6
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_7      reg_main_ccd_brightness_level_7
#define CAMACQ_MAIN_REG_CCD_BRIGHTNESS_LEVEL_8      reg_main_ccd_brightness_level_8


#define CAMACQ_MAIN_REG_METER_MATRIX            reg_main_meter_matrix
#define CAMACQ_MAIN_REG_METER_CW                reg_main_meter_cw
#define CAMACQ_MAIN_REG_METER_SPOT              reg_main_meter_spot

#define CAMACQ_MAIN_REG_EFFECT_NONE             reg_main_effect_none
#define CAMACQ_MAIN_REG_EFFECT_GRAY             reg_main_effect_gray // mono, blackwhite
#define CAMACQ_MAIN_REG_EFFECT_NEGATIVE         reg_main_effect_negative
#define CAMACQ_MAIN_REG_EFFECT_SEPIA            reg_main_effect_sepia

#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_M2              reg_main_adjust_contrast_m2
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_M1              reg_main_adjust_contrast_m1
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_DEFAULT         reg_main_adjust_contrast_default
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_P1              reg_main_adjust_contrast_p1
#define CAMACQ_MAIN_REG_ADJUST_CONTRAST_P2              reg_main_adjust_contrast_p2

#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_M2             reg_main_adjust_sharpness_m2
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_M1             reg_main_adjust_sharpness_m1
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_DEFAULT        reg_main_adjust_sharpness_default
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_P1             reg_main_adjust_sharpness_p1
#define CAMACQ_MAIN_REG_ADJUST_SHARPNESS_P2             reg_main_adjust_sharpness_p2

#define CAMACQ_MAIN_REG_ADJUST_SATURATION_M2            reg_main_adjust_saturation_m2
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_M1            reg_main_adjust_saturation_m1
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_DEFAULT       reg_main_adjust_saturation_default
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_P1            reg_main_adjust_saturation_p1
#define CAMACQ_MAIN_REG_ADJUST_SATURATION_P2            reg_main_adjust_saturation_p2

#define CAMACQ_MAIN_REG_JPEG_5M                 reg_main_jpeg_5m        //2560X1920
#define CAMACQ_MAIN_REG_JPEG_3M                 reg_main_jpeg_3m        // QXGA 2048X1536
#define CAMACQ_MAIN_REG_JPEG_2M                 reg_main_jpeg_2m        // UXGA 1600x1200
#define CAMACQ_MAIN_REG_JPEG_1M                 reg_main_jpeg_1m

#define CAMACQ_MAIN_REG_PREVIEW_RETURN         reg_main_preview_return

#define CAMACQ_MAIN_AE_LOCK                     reg_main_set_ae_lock
#define CAMACQ_MAIN_AE_UNLOCK                   reg_main_set_ae_unlock
#define CAMACQ_MAIN_AWB_LOCK                    reg_main_set_awb_lock
#define CAMACQ_MAIN_AWB_UNLOCK                  reg_main_set_awb_unlock
#define CAMACQ_MAIN_REG_SINGLE_AF_START         reg_main_single_af_start

#define CAMACQ_MAIN_REG_LOW_CAP_ON					reg_main_low_cap_on
#define CAMACQ_MAIN_REG_LOW_CAP_OFF					reg_main_low_cap_off

#define CAMACQ_MAIN_REG_SET_AF_NORMAL_MODE_1    reg_main_set_af_normal_mode_1
#define CAMACQ_MAIN_REG_SET_AF_NORMAL_MODE_2    reg_main_set_af_normal_mode_2
#define CAMACQ_MAIN_REG_SET_AF_NORMAL_MODE_3    reg_main_set_af_normal_mode_3
#define CAMACQ_MAIN_REG_SET_AF_MACRO_MODE_1     reg_main_set_af_macro_mode_1
#define CAMACQ_MAIN_REG_SET_AF_MACRO_MODE_2     reg_main_set_af_macro_mode_2
#define CAMACQ_MAIN_REG_SET_AF_MACRO_MODE_3     reg_main_set_af_macro_mode_3

#define	CAMACQ_MAIN_REG_4_ZOOM0 	reg_main_4_zoom0
#define	CAMACQ_MAIN_REG_4_ZOOM1 	reg_main_4_zoom1
#define	CAMACQ_MAIN_REG_4_ZOOM2 	reg_main_4_zoom2
#define	CAMACQ_MAIN_REG_4_ZOOM3 	reg_main_4_zoom3
#define	CAMACQ_MAIN_REG_4_ZOOM4 	reg_main_4_zoom4
#define	CAMACQ_MAIN_REG_4_ZOOM5 	reg_main_4_zoom5
#define	CAMACQ_MAIN_REG_4_ZOOM6 	reg_main_4_zoom6
#define	CAMACQ_MAIN_REG_4_ZOOM7 	reg_main_4_zoom7
#define	CAMACQ_MAIN_REG_4_ZOOM8 	reg_main_4_zoom8

#define	CAMACQ_MAIN_REG_2_ZOOM0 	reg_main_2_zoom0
#define	CAMACQ_MAIN_REG_2_ZOOM1 	reg_main_2_zoom1
#define	CAMACQ_MAIN_REG_2_ZOOM2 	reg_main_2_zoom2
#define	CAMACQ_MAIN_REG_2_ZOOM3 	reg_main_2_zoom3
#define	CAMACQ_MAIN_REG_2_ZOOM4 	reg_main_2_zoom4
#define	CAMACQ_MAIN_REG_2_ZOOM5 	reg_main_2_zoom5
#define	CAMACQ_MAIN_REG_2_ZOOM6 	reg_main_2_zoom6
#define	CAMACQ_MAIN_REG_2_ZOOM7 	reg_main_2_zoom7
#define	CAMACQ_MAIN_REG_2_ZOOM8 	reg_main_2_zoom8

#define	CAMACQ_MAIN_REG_1_6_ZOOM0 	reg_main_1_6_zoom0
#define	CAMACQ_MAIN_REG_1_6_ZOOM1 	reg_main_1_6_zoom1
#define	CAMACQ_MAIN_REG_1_6_ZOOM2 	reg_main_1_6_zoom2
#define	CAMACQ_MAIN_REG_1_6_ZOOM3 	reg_main_1_6_zoom3
#define	CAMACQ_MAIN_REG_1_6_ZOOM4 	reg_main_1_6_zoom4
#define	CAMACQ_MAIN_REG_1_6_ZOOM5 	reg_main_1_6_zoom5
#define	CAMACQ_MAIN_REG_1_6_ZOOM6 	reg_main_1_6_zoom6
#define	CAMACQ_MAIN_REG_1_6_ZOOM7 	reg_main_1_6_zoom7
#define	CAMACQ_MAIN_REG_1_6_ZOOM8 	reg_main_1_6_zoom8

#define	CAMACQ_MAIN_REG_1_25_ZOOM0 	reg_main_1_25_zoom0
#define	CAMACQ_MAIN_REG_1_25_ZOOM1 	reg_main_1_25_zoom1
#define	CAMACQ_MAIN_REG_1_25_ZOOM2 	reg_main_1_25_zoom2
#define	CAMACQ_MAIN_REG_1_25_ZOOM3 	reg_main_1_25_zoom3
#define	CAMACQ_MAIN_REG_1_25_ZOOM4 	reg_main_1_25_zoom4
#define	CAMACQ_MAIN_REG_1_25_ZOOM5 	reg_main_1_25_zoom5
#define	CAMACQ_MAIN_REG_1_25_ZOOM6 	reg_main_1_25_zoom6
#define	CAMACQ_MAIN_REG_1_25_ZOOM7 	reg_main_1_25_zoom7
#define	CAMACQ_MAIN_REG_1_25_ZOOM8 	reg_main_1_25_zoom8

#endif


#define CAMACQ_MAIN_REG_HIGHLIGHT                reg_main_highlight
#define CAMACQ_MAIN_REG_MIDLIGHT                reg_main_midlight
#define CAMACQ_MAIN_REG_LOWLIGHT                reg_main_lowlight
#define CAMACQ_MAIN_REG_NIGHTSHOT_ON            reg_main_nightshot_on
#define CAMACQ_MAIN_REG_NIGHTSHOT_OFF           reg_main_nightshot_off
#define CAMACQ_MAIN_REG_NIGHTSHOT               reg_main_nightshot

#define CAMACQ_MAIN_REG_WB_TWILIGHT             reg_main_wb_twilight
#define CAMACQ_MAIN_REG_WB_TUNGSTEN             reg_main_wb_tungsten
#define CAMACQ_MAIN_REG_WB_OFF                  reg_main_wb_off
#define CAMACQ_MAIN_REG_WB_HORIZON              reg_main_wb_horizon
#define CAMACQ_MAIN_REG_WB_SHADE                reg_main_wb_shade

#define CAMACQ_MAIN_REG_EFFECT_SOLARIZE         reg_main_effect_solarize
#define CAMACQ_MAIN_REG_EFFECT_POSTERIZE        reg_main_effect_posterize
#define CAMACQ_MAIN_REG_EFFECT_WHITEBOARD       reg_main_effect_whiteboard
#define CAMACQ_MAIN_REG_EFFECT_BLACKBOARD       reg_main_effect_blackboard
#define CAMACQ_MAIN_REG_EFFECT_AQUA             reg_main_effect_aqua
#define CAMACQ_MAIN_REG_EFFECT_SHARPEN          reg_main_effect_sharpen
#define CAMACQ_MAIN_REG_EFFECT_VIVID            reg_main_effect_vivid
#define CAMACQ_MAIN_REG_EFFECT_GREEN            reg_main_effect_green
#define CAMACQ_MAIN_REG_EFFECT_SKETCH           reg_main_effect_sketch


#define CAMACQ_MAIN_REG_FLIP_NONE               reg_main_flip_none
#define CAMACQ_MAIN_REG_FLIP_WATER              reg_main_flip_water
#define CAMACQ_MAIN_REG_FLIP_MIRROR             reg_main_flip_mirror
#define CAMACQ_MAIN_REG_FLIP_WATER_MIRROR       reg_main_flip_water_mirror


#define CAMACQ_MAIN_REG_FPS_FIXED_5             reg_main_fps_fixed_5
#define CAMACQ_MAIN_REG_FPS_FIXED_7             reg_main_fps_fixed_7
#define CAMACQ_MAIN_REG_FPS_FIXED_10            reg_main_fps_fixed_10
#define CAMACQ_MAIN_REG_FPS_FIXED_15            reg_main_fps_fixed_15
#define CAMACQ_MAIN_REG_FPS_FIXED_20            reg_main_fps_fixed_20
#define CAMACQ_MAIN_REG_FPS_FIXED_25            reg_main_fps_fixed_25
#define CAMACQ_MAIN_REG_FPS_VAR_15              reg_main_fps_var_15
#define CAMACQ_MAIN_REG_FPS_FIXED_30            reg_main_fps_fixed_30


#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_0 reg_main_expcompensation_level_0
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_1 reg_main_expcompensation_level_1
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_2 reg_main_expcompensation_level_2
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_3 reg_main_expcompensation_level_3
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_4 reg_main_expcompensation_level_4
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_5 reg_main_expcompensation_level_5
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_6 reg_main_expcompensation_level_6
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_7 reg_main_expcompensation_level_7
#define CAMACQ_MAIN_REG_EXPCOMPENSATION_LEVEL_8 reg_main_expcompensation_level_8


#define CAMACQ_MAIN_REG_SET_AF                  reg_main_set_af  // start af
#define CAMACQ_MAIN_REG_OFF_AF                  reg_main_off_af
#define CAMACQ_MAIN_REG_CHECK_AF                reg_main_check_af
#define CAMACQ_MAIN_REG_RESET_AF                reg_main_reset_af
#define CAMACQ_MAIN_REG_MANUAL_AF               reg_main_manual_af    // normal_af
#define CAMACQ_MAIN_REG_MACRO_AF                reg_main_macro_af
#define CAMACQ_MAIN_REG_RETURN_MANUAL_AF        reg_main_return_manual_af
#define CAMACQ_MAIN_REG_RETURN_MACRO_AF         reg_main_return_macro_af
#define CAMACQ_MAIN_REG_SET_AF_NLUX             reg_main_set_af_nlux
#define CAMACQ_MAIN_REG_SET_AF_LLUX             reg_main_set_af_llux




#define CAMACQ_MAIN_REG_ISO_AUTO                reg_main_iso_auto
#define CAMACQ_MAIN_REG_ISO_50                  reg_main_iso_50
#define CAMACQ_MAIN_REG_ISO_100                 reg_main_iso_100
#define CAMACQ_MAIN_REG_ISO_200                 reg_main_iso_200
#define CAMACQ_MAIN_REG_ISO_400                 reg_main_iso_400
#define CAMACQ_MAIN_REG_ISO_800                 reg_main_iso_800
#define CAMACQ_MAIN_REG_ISO_1600                reg_main_iso_1600
#define CAMACQ_MAIN_REG_ISO_3200                reg_main_iso_3200


#define CAMACQ_MAIN_REG_SCENE_PARTY             reg_main_scene_party
#define CAMACQ_MAIN_REG_SCENE_SNOW              reg_main_scene_snow
#define CAMACQ_MAIN_REG_SCENE_TEXT              reg_main_scene_text

#define CAMACQ_MAIN_REG_QQVGA                   reg_main_qqvga
#define CAMACQ_MAIN_REG_QCIF                    reg_main_qcif
#define CAMACQ_MAIN_REG_QVGA                    reg_main_qvga
#define CAMACQ_MAIN_REG_WQVGA                    reg_main_wqvga
#define CAMACQ_MAIN_REG_CIF                     reg_main_cif
#define CAMACQ_MAIN_REG_VGA                     reg_main_vga
#define CAMACQ_MAIN_REG_WVGA                     reg_main_wvga // 800* 480
#define CAMACQ_MAIN_REG_SVGA                    reg_main_svga
#define CAMACQ_MAIN_REG_SXGA                    reg_main_sxga
#define CAMACQ_MAIN_REG_QXGA                    reg_main_qxga
#define CAMACQ_MAIN_REG_UXGA                    reg_main_uxga
#define CAMACQ_MAIN_REG_FULL_YUV                reg_main_full_yuv
#define CAMACQ_MAIN_REG_CROP_YUV                reg_main_crop_yuv
#define CAMACQ_MAIN_REG_QVGA_V		            reg_main_qvga_v
#define CAMACQ_MAIN_REG_HALF_VGA_V	            reg_main_half_vga_v
#define CAMACQ_MAIN_REG_HALF_VGA		        reg_main_half_vga
#define CAMACQ_MAIN_REG_VGA_V		            reg_main_vga_v
#define CAMACQ_MAIN_REG_5M			            reg_main_5M
#define CAMACQ_MAIN_REG_1080P		            reg_main_1080P
#define CAMACQ_MAIN_REG_720P			        reg_main_720P
#define CAMACQ_MAIN_REG_NOT                     reg_main_not


#define CAMACQ_MAIN_REG_JPEG_W4M                 reg_main_jpeg_w4m      // 2560x1536
#define CAMACQ_MAIN_REG_JPEG_W1_5M               reg_main_jpeg_w1_5m    // 1280x960
#define CAMACQ_MAIN_REG_JPEG_VGA                reg_main_jpeg_vga   //640x480
#define CAMACQ_MAIN_REG_JPEG_WQVGA              reg_main_jpeg_wqvga //420x240
#define CAMACQ_MAIN_REG_JPEG_QVGA               reg_main_jpeg_qvga  //320x240

#define CAMACQ_MAIN_REG_FLICKER_DISABLED        reg_main_flicker_disabled
#define CAMACQ_MAIN_REG_FLICKER_50HZ            reg_main_flicker_50hz
#define CAMACQ_MAIN_REG_FLICKER_60HZ            reg_main_flicker_60hz
#define CAMACQ_MAIN_REG_FLICKER_AUTO            reg_main_flicker_auto

// image quality
#define CAMACQ_MAIN_REG_JPEG_QUALITY_SUPERFINE reg_main_jpeg_quality_superfine
#define CAMACQ_MAIN_REG_JPEG_QUALITY_FINE      reg_main_jpeg_quality_fine
#define CAMACQ_MAIN_REG_JPEG_QUALITY_NORMAL    reg_main_jpeg_quality_normal

// Private Control
#define CAMACQ_MAIN_REG_PRIVCTRL_RETURNPREVIEW  reg_main_priv_ctrl_returnpreview

// Format
#define CAMACQ_MAIN_REG_FMT_YUV422 	            reg_main_fmt_yuv422
#define CAMACQ_MAIN_REG_FMT_JPG		            reg_main_fmt_jpg


// NEW
#define CAMACQ_MAIN_REG_SLEEP                   reg_main_sleep
#define CAMACQ_MAIN_REG_WAKEUP                  reg_main_wakeup

/* Enumeration */

/* Global Value */
GLOBAL const U32 reg_main_sleep[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U32 reg_main_wakeup[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_init[]
#if defined(_CAMACQ_API_C_)
={
//==================================================================================
// 00.History
//==================================================================================
//20100000 : EVT1.1
//20110429 : LSI CSE Standard
//20110728 : Sequence Changed
//20110728 : ESD Check Register Address Change
//20110829 : TnP Changed by S.Y.Lee
//20120104 : init Parm Update sequence changed
//20120201 : Flash시 주변부 Green Noise 개선 setting
//20120229 : Brightness Block 추가 (by J.W.Yoo)

//==================================================================================

//==================================================================================
// 01.Start Setting
//==================================================================================

{0xFCFCD000},	
{0x00100001},	//S/W Reset
{0x10300000},	//contint_host_int
{0x00140001},	//sw_load_complete - Release CORE (Arm) from reset state

{0xFEFE000A}, //p10 //Delay 10ms

//==================================================================================                
//02.ETC Setting                                                                                    
//==================================================================================                
                                                                                                    
{0x0028D000},	//Driving Current                                                                   
{0x002A1082},                                                                                           
{0x0F120155},	//cregs_d0_d4_cd10 //D4[9:8], D3[7:6], D2[5:4], D1[3:2], D0[1:0]                    
{0x002A1084},                                                                                           
{0x0F120155},	//cregs_d5_d9_cd10 //D9[9:8], D8[7:6], D7[5:4], D6[3:2], D5[1:0]    
{0x002A1086},                                                                                           
{0x0F120055},	//gpio_cd10
{0x002A1088},                                                                                           
{0x0F120555},	//cregs_clks_output_cd10 //SDA[11:10], SCL[9:8], PCLK[7:6], VSYNC[3:2], HSYNC[1:0]  
{0x002A100E},
{0x0F120000},	//pclk_delay_r
	                                                                                                                                                                                                                                                                
//==================================================================================
// 03.Analog Setting1 & ASP Control
//==================================================================================
//This register is for FACTORY ONLY. 
//If you change it without prior notification
//YOU are RESPONSIBLE for the FAILURE that will happen in the future

{0x0028D000},
{0x002A007A}, //config_clk_setting
{0x0F120000},	
{0x002AE406},	//[7]f_ladlc_en [6:5]f max [4]fadlc_en [3:2]L max [1]ladlc_en [0]adlc_ch_sel
{0x0F120092},	
{0x002AE410},	
{0x0F123804},	//[15:8]fadlc_filter_co_b, [7:0]fadlc_filter_co_a	
{0x002AE41A},	
{0x0F120010},	//adlc_ptune_total
{0x002AF132},   
{0x0F120200},
{0x002AF142},
{0x0F120200},  //110404 AE haunting - from_LSI
{0x002AE420},	
{0x0F120003},	//adlc_fadlc_filter_refresh 	
{0x0F120060},	//adlc_filter_level_diff_threshold
{0x002AE42E},	
{0x0F120004},	//dithered l-ADLC(4bit)
{0x002AF400},	
{0x0F125A3C},	//[15:8]stx_width, [7:0]dstx_width 
{0x0F120023},	//[14]binning_test [13]gain_mode [11:12]row_id [10]cfpn_test [9]pd_pix [8]teg_en, [7]adc_res, [6]smp_en, [5]ldb_en, [4]ld_en, [3]clp_en [2]srx_en, [1]dshut_en, [0]dcds_en 
{0x0F128080},	//CDS option 
{0x0F1203AF},	//[11:6]rst_mx, [5:0]sig_mx
{0x0F12000A},	//Avg mode
{0x0F12AA54},	//x1~x1.49:No MS, x1.5~x3.99:MS2, x4~x16:MS4
{0x0F120040},	//RMP option [6]1: RES gain
{0x0F12464E},	//[14]msoff_en, [13:8]off_rst, [7:0]adc_sat
{0x0F120240},	//bist_sig_width_e
{0x0F120240},	//bist_sig_width_o
{0x0F120040},	//[9]dbs_bist_en, [8:0]bist_rst_width
{0x0F121000},	//[15]aac_en, [14]GCLK_DIV2_EN, [13:10]dl_cont [9:8]dbs_mode, [7:0]dbs_option
{0x0F1255FF},	//bias [15:12]pix, [11:8]pix_bst [7:4]comp2, [3:0]comp1  	
{0x0F12D000},	//[15:8]clp_lvl, [7:0]ref_option, [5]pix_bst_en
{0x0F120010},	//[7:0]monit
{0x0F120202},	//[15:8]dbr_tune_tgsl, [7:0]dbr_tune_pix
{0x0F120401},	//[15:8]dbr_tune_ntg, [7:0]dbr_tune_rg                                                                       
{0x0F120022},	//[15:8]reg_option, [7:4]rosc_tune_ncp, [3:0]rosc_tune_cp                                                    
{0x0F120088},	//PD [8]inrush_ctrl, [7]fblv, [6]reg_ntg, [5]reg_tgsl, [4]reg_rg, [3]reg_pix, [2]ncp_rosc, [1]cp_rosc, [0]cp 
{0x0F12009F},	//[9]capa_ctrl_en, [8:7]fb_lv, [6:5]dbr_clk_sel, [4:0]cp_capa                                                
{0x0F120000},	//[15:0]blst_en_cintr                                                                                        
{0x0F121800},	//[11]blst_en, [10]rfpn_test, [9]sl_off, [8]tx_off, [7:0]rdv_option                                          
{0x0F120088},	//[15:0]pmg_reg_tune                                                                                         
{0x0F120000},	//[15:1]analog_dummy, [0]pd_reg_test 
{0x0F122428},	//[13:11]srx_gap1, [10:8]srx_gap0, [7:0]stx_gap
{0x0F120000},	//[0]atx_option       
{0x0F1203EE},	//aig_avg_half
{0x0F120000},	//[0]hvs_test_reg     
{0x0F120000},	//[0]dbus_bist_auto   
{0x0F120000},	//[7:0]dbr_option	    
{0x002AF552},	
{0x0F120708},	//[7:0]lat_st, [15:8]lat_width  
{0x0F12080C},	//[7:0]hold_st, [15:8]hold_width
	
//=================================================================================
// 04.Trap and Patch
//=================================================================================
// Start of Patch data

{0x00287000},
{0x002A3AF8},
{0x0F12B5F8},    // 70003AF8
{0x0F124B44},    // 70003AFA
{0x0F124944},    // 70003AFC
{0x0F124845},    // 70003AFE
{0x0F122200},    // 70003B00
{0x0F12C008},    // 70003B02
{0x0F126001},    // 70003B04
{0x0F124944},    // 70003B06
{0x0F124844},    // 70003B08
{0x0F122401},    // 70003B0A
{0x0F12F000},    // 70003B0C
{0x0F12FCA4},    // 70003B0E
{0x0F124943},    // 70003B10
{0x0F124844},    // 70003B12
{0x0F122702},    // 70003B14
{0x0F120022},    // 70003B16
{0x0F12F000},    // 70003B18
{0x0F12FC9E},    // 70003B1A
{0x0F120260},    // 70003B1C
{0x0F124C42},    // 70003B1E
{0x0F128020},    // 70003B20
{0x0F122600},    // 70003B22
{0x0F128066},    // 70003B24
{0x0F124941},    // 70003B26
{0x0F124841},    // 70003B28
{0x0F126041},    // 70003B2A
{0x0F124941},    // 70003B2C
{0x0F124842},    // 70003B2E
{0x0F12003A},    // 70003B30
{0x0F122503},    // 70003B32
{0x0F12F000},    // 70003B34
{0x0F12FC90},    // 70003B36
{0x0F12483D},    // 70003B38
{0x0F124940},    // 70003B3A
{0x0F1230C0},    // 70003B3C
{0x0F1263C1},    // 70003B3E
{0x0F124F3B},    // 70003B40
{0x0F12483F},    // 70003B42
{0x0F123F80},    // 70003B44
{0x0F126438},    // 70003B46
{0x0F12483E},    // 70003B48
{0x0F12493F},    // 70003B4A
{0x0F126388},    // 70003B4C
{0x0F12002A},    // 70003B4E
{0x0F12493E},    // 70003B50
{0x0F12483F},    // 70003B52
{0x0F122504},    // 70003B54
{0x0F12F000},    // 70003B56
{0x0F12FC7F},    // 70003B58
{0x0F12002A},    // 70003B5A
{0x0F12493D},    // 70003B5C
{0x0F12483E},    // 70003B5E
{0x0F122505},    // 70003B60
{0x0F12F000},    // 70003B62
{0x0F12F8A7},    // 70003B64
{0x0F12483C},    // 70003B66
{0x0F12002A},    // 70003B68
{0x0F12493C},    // 70003B6A
{0x0F122506},    // 70003B6C
{0x0F121D80},    // 70003B6E
{0x0F12F000},    // 70003B70
{0x0F12F8A0},    // 70003B72
{0x0F124838},    // 70003B74
{0x0F12002A},    // 70003B76
{0x0F124939},    // 70003B78
{0x0F122507},    // 70003B7A
{0x0F12300C},    // 70003B7C
{0x0F12F000},    // 70003B7E
{0x0F12F899},    // 70003B80
{0x0F124835},    // 70003B82
{0x0F12002A},    // 70003B84
{0x0F124937},    // 70003B86
{0x0F122508},    // 70003B88
{0x0F123010},    // 70003B8A
{0x0F12F000},    // 70003B8C
{0x0F12F892},    // 70003B8E
{0x0F12002A},    // 70003B90
{0x0F124935},    // 70003B92
{0x0F124835},    // 70003B94
{0x0F122509},    // 70003B96
{0x0F12F000},    // 70003B98
{0x0F12FC5E},    // 70003B9A
{0x0F12002A},    // 70003B9C
{0x0F124934},    // 70003B9E
{0x0F124834},    // 70003BA0
{0x0F12250A},    // 70003BA2
{0x0F12F000},    // 70003BA4
{0x0F12FC58},    // 70003BA6
{0x0F12002A},    // 70003BA8
{0x0F124933},    // 70003BAA
{0x0F124833},    // 70003BAC
{0x0F12250B},    // 70003BAE
{0x0F12F000},    // 70003BB0
{0x0F12FC52},    // 70003BB2
{0x0F12002A},    // 70003BB4
{0x0F124932},    // 70003BB6
{0x0F124832},    // 70003BB8
{0x0F12250C},    // 70003BBA
{0x0F12F000},    // 70003BBC
{0x0F12FC4C},    // 70003BBE
{0x0F12002A},    // 70003BC0
{0x0F124931},    // 70003BC2
{0x0F124831},    // 70003BC4
{0x0F12250D},    // 70003BC6
{0x0F12F000},    // 70003BC8
{0x0F12FC46},    // 70003BCA
{0x0F12002A},    // 70003BCC
{0x0F124930},    // 70003BCE
{0x0F124830},    // 70003BD0
{0x0F12250E},    // 70003BD2
{0x0F12F000},    // 70003BD4
{0x0F12FC40},    // 70003BD6
{0x0F12002A},    // 70003BD8
{0x0F12492F},    // 70003BDA
{0x0F12482F},    // 70003BDC
{0x0F12250F},    // 70003BDE
{0x0F12F000},    // 70003BE0
{0x0F12FC3A},    // 70003BE2
{0x0F128626},    // 70003BE4
{0x0F1220FF},    // 70003BE6
{0x0F121C40},    // 70003BE8
{0x0F128660},    // 70003BEA
{0x0F12482C},    // 70003BEC
{0x0F1264F8},    // 70003BEE
{0x0F12492C},    // 70003BF0
{0x0F12482D},    // 70003BF2
{0x0F122410},    // 70003BF4
{0x0F12002A},    // 70003BF6
{0x0F12F000},    // 70003BF8
{0x0F12FC2E},    // 70003BFA
{0x0F12492B},    // 70003BFC
{0x0F12482C},    // 70003BFE
{0x0F120022},    // 70003C00
{0x0F12F000},    // 70003C02
{0x0F12FC29},    // 70003C04
{0x0F12BCF8},    // 70003C06
{0x0F12BC08},    // 70003C08
{0x0F124718},    // 70003C0A
{0x0F12019C},    // 70003C0C
{0x0F124EC2},    // 70003C0E
{0x0F1273FF},    // 70003C10
{0x0F120000},    // 70003C12
{0x0F121F90},    // 70003C14
{0x0F127000},    // 70003C16
{0x0F123CCD},    // 70003C18
{0x0F127000},    // 70003C1A
{0x0F12E38B},    // 70003C1C
{0x0F120000},    // 70003C1E
{0x0F123D05},    // 70003C20
{0x0F127000},    // 70003C22
{0x0F12C3B1},    // 70003C24
{0x0F120000},    // 70003C26
{0x0F124780},    // 70003C28
{0x0F127000},    // 70003C2A
{0x0F123D63},    // 70003C2C
{0x0F127000},    // 70003C2E
{0x0F120080},    // 70003C30
{0x0F127000},    // 70003C32
{0x0F123D9F},    // 70003C34
{0x0F127000},    // 70003C36
{0x0F12B49D},    // 70003C38
{0x0F120000},    // 70003C3A
{0x0F123E4B},    // 70003C3C
{0x0F127000},    // 70003C3E
{0x0F123DFF},    // 70003C40
{0x0F127000},    // 70003C42
{0x0F12FFFF},    // 70003C44
{0x0F1200FF},    // 70003C46
{0x0F1217E0},    // 70003C48
{0x0F127000},    // 70003C4A
{0x0F123FC7},    // 70003C4C
{0x0F127000},    // 70003C4E
{0x0F12053D},    // 70003C50
{0x0F120000},    // 70003C52
{0x0F120000},    // 70003C54
{0x0F120A89},    // 70003C56
{0x0F126CD2},    // 70003C58
{0x0F120000},    // 70003C5A
{0x0F1202C9},    // 70003C5C
{0x0F120000},    // 70003C5E
{0x0F120000},    // 70003C60
{0x0F120A9A},    // 70003C62
{0x0F120000},    // 70003C64
{0x0F1202D2},    // 70003C66
{0x0F124015},    // 70003C68
{0x0F127000},    // 70003C6A
{0x0F129E65},    // 70003C6C
{0x0F120000},    // 70003C6E
{0x0F124089},    // 70003C70
{0x0F127000},    // 70003C72
{0x0F127C49},    // 70003C74
{0x0F120000},    // 70003C76
{0x0F1240FD},    // 70003C78
{0x0F127000},    // 70003C7A
{0x0F127C63},    // 70003C7C
{0x0F120000},    // 70003C7E
{0x0F124119},    // 70003C80
{0x0F127000},    // 70003C82
{0x0F128F01},    // 70003C84
{0x0F120000},    // 70003C86
{0x0F1241BB},    // 70003C88
{0x0F127000},    // 70003C8A
{0x0F127F3F},    // 70003C8C
{0x0F120000},    // 70003C8E
{0x0F124249},    // 70003C90
{0x0F127000},    // 70003C92
{0x0F1298C5},    // 70003C94
{0x0F120000},    // 70003C96
{0x0F1243B5},    // 70003C98
{0x0F127000},    // 70003C9A
{0x0F126099},    // 70003C9C
{0x0F120000},    // 70003C9E
{0x0F12430F},    // 70003CA0
{0x0F127000},    // 70003CA2
{0x0F124365},    // 70003CA4
{0x0F127000},    // 70003CA6
{0x0F12A70B},    // 70003CA8
{0x0F120000},    // 70003CAA
{0x0F124387},    // 70003CAC
{0x0F127000},    // 70003CAE
{0x0F12400D},    // 70003CB0
{0x0F120000},    // 70003CB2
{0x0F12B570},    // 70003CB4
{0x0F12000C},    // 70003CB6
{0x0F120015},    // 70003CB8
{0x0F120029},    // 70003CBA
{0x0F12F000},    // 70003CBC
{0x0F12FBD4},    // 70003CBE
{0x0F1249F8},    // 70003CC0
{0x0F1200A8},    // 70003CC2
{0x0F12500C},    // 70003CC4
{0x0F12BC70},    // 70003CC6
{0x0F12BC08},    // 70003CC8
{0x0F124718},    // 70003CCA
{0x0F126808},    // 70003CCC
{0x0F120400},    // 70003CCE
{0x0F120C00},    // 70003CD0
{0x0F126849},    // 70003CD2
{0x0F120409},    // 70003CD4
{0x0F120C09},    // 70003CD6
{0x0F124AF3},    // 70003CD8
{0x0F128992},    // 70003CDA
{0x0F122A00},    // 70003CDC
{0x0F12D00D},    // 70003CDE
{0x0F122300},    // 70003CE0
{0x0F121A89},    // 70003CE2
{0x0F12D400},    // 70003CE4
{0x0F12000B},    // 70003CE6
{0x0F120419},    // 70003CE8
{0x0F120C09},    // 70003CEA
{0x0F1223FF},    // 70003CEC
{0x0F1233C1},    // 70003CEE
{0x0F121810},    // 70003CF0
{0x0F124298},    // 70003CF2
{0x0F12D800},    // 70003CF4
{0x0F120003},    // 70003CF6
{0x0F120418},    // 70003CF8
{0x0F120C00},    // 70003CFA
{0x0F124AEB},    // 70003CFC
{0x0F128150},    // 70003CFE
{0x0F128191},    // 70003D00
{0x0F124770},    // 70003D02
{0x0F12B5F3},    // 70003D04
{0x0F120004},    // 70003D06
{0x0F12B081},    // 70003D08
{0x0F129802},    // 70003D0A
{0x0F126800},    // 70003D0C
{0x0F120600},    // 70003D0E
{0x0F120E00},    // 70003D10
{0x0F122201},    // 70003D12
{0x0F120015},    // 70003D14
{0x0F120021},    // 70003D16
{0x0F123910},    // 70003D18
{0x0F12408A},    // 70003D1A
{0x0F1240A5},    // 70003D1C
{0x0F124FE4},    // 70003D1E
{0x0F120016},    // 70003D20
{0x0F122C10},    // 70003D22
{0x0F12DA03},    // 70003D24
{0x0F128839},    // 70003D26
{0x0F1243A9},    // 70003D28
{0x0F128039},    // 70003D2A
{0x0F12E002},    // 70003D2C
{0x0F128879},    // 70003D2E
{0x0F1243B1},    // 70003D30
{0x0F128079},    // 70003D32
{0x0F12F000},    // 70003D34
{0x0F12FBA0},    // 70003D36
{0x0F122C10},    // 70003D38
{0x0F12DA03},    // 70003D3A
{0x0F128839},    // 70003D3C
{0x0F124329},    // 70003D3E
{0x0F128039},    // 70003D40
{0x0F12E002},    // 70003D42
{0x0F128879},    // 70003D44
{0x0F124331},    // 70003D46
{0x0F128079},    // 70003D48
{0x0F1249DA},    // 70003D4A
{0x0F128809},    // 70003D4C
{0x0F122900},    // 70003D4E
{0x0F12D102},    // 70003D50
{0x0F12F000},    // 70003D52
{0x0F12FB99},    // 70003D54
{0x0F122000},    // 70003D56
{0x0F129902},    // 70003D58
{0x0F126008},    // 70003D5A
{0x0F12BCFE},    // 70003D5C
{0x0F12BC08},    // 70003D5E
{0x0F124718},    // 70003D60
{0x0F12B538},    // 70003D62
{0x0F129C04},    // 70003D64
{0x0F120015},    // 70003D66
{0x0F12002A},    // 70003D68
{0x0F129400},    // 70003D6A
{0x0F12F000},    // 70003D6C
{0x0F12FB94},    // 70003D6E
{0x0F124AD1},    // 70003D70
{0x0F128811},    // 70003D72
{0x0F122900},    // 70003D74
{0x0F12D00F},    // 70003D76
{0x0F128820},    // 70003D78
{0x0F124281},    // 70003D7A
{0x0F12D20C},    // 70003D7C
{0x0F128861},    // 70003D7E
{0x0F128853},    // 70003D80
{0x0F124299},    // 70003D82
{0x0F12D200},    // 70003D84
{0x0F121E40},    // 70003D86
{0x0F120400},    // 70003D88
{0x0F120C00},    // 70003D8A
{0x0F128020},    // 70003D8C
{0x0F128851},    // 70003D8E
{0x0F128061},    // 70003D90
{0x0F124368},    // 70003D92
{0x0F121840},    // 70003D94
{0x0F126060},    // 70003D96
{0x0F12BC38},    // 70003D98
{0x0F12BC08},    // 70003D9A
{0x0F124718},    // 70003D9C
{0x0F12B5F8},    // 70003D9E
{0x0F120004},    // 70003DA0
{0x0F126808},    // 70003DA2
{0x0F120400},    // 70003DA4
{0x0F120C00},    // 70003DA6
{0x0F122201},    // 70003DA8
{0x0F120015},    // 70003DAA
{0x0F120021},    // 70003DAC
{0x0F123910},    // 70003DAE
{0x0F12408A},    // 70003DB0
{0x0F1240A5},    // 70003DB2
{0x0F124FBE},    // 70003DB4
{0x0F120016},    // 70003DB6
{0x0F122C10},    // 70003DB8
{0x0F12DA03},    // 70003DBA
{0x0F128839},    // 70003DBC
{0x0F1243A9},    // 70003DBE
{0x0F128039},    // 70003DC0
{0x0F12E002},    // 70003DC2
{0x0F128879},    // 70003DC4
{0x0F1243B1},    // 70003DC6
{0x0F128079},    // 70003DC8
{0x0F12F000},    // 70003DCA
{0x0F12FB6D},    // 70003DCC
{0x0F122C10},    // 70003DCE
{0x0F12DA03},    // 70003DD0
{0x0F128838},    // 70003DD2
{0x0F124328},    // 70003DD4
{0x0F128038},    // 70003DD6
{0x0F12E002},    // 70003DD8
{0x0F128878},    // 70003DDA
{0x0F124330},    // 70003DDC
{0x0F128078},    // 70003DDE
{0x0F1248B6},    // 70003DE0
{0x0F128800},    // 70003DE2
{0x0F120400},    // 70003DE4
{0x0F12D507},    // 70003DE6
{0x0F124BB5},    // 70003DE8
{0x0F127819},    // 70003DEA
{0x0F124AB5},    // 70003DEC
{0x0F127810},    // 70003DEE
{0x0F127018},    // 70003DF0
{0x0F127011},    // 70003DF2
{0x0F1249B4},    // 70003DF4
{0x0F128188},    // 70003DF6
{0x0F12BCF8},    // 70003DF8
{0x0F12BC08},    // 70003DFA
{0x0F124718},    // 70003DFC
{0x0F12B538},    // 70003DFE
{0x0F1248B2},    // 70003E00
{0x0F124669},    // 70003E02
{0x0F12F000},    // 70003E04
{0x0F12FB58},    // 70003E06
{0x0F1248B1},    // 70003E08
{0x0F1249B0},    // 70003E0A
{0x0F1269C2},    // 70003E0C
{0x0F122400},    // 70003E0E
{0x0F1231A8},    // 70003E10
{0x0F122A00},    // 70003E12
{0x0F12D008},    // 70003E14
{0x0F1261C4},    // 70003E16
{0x0F12684A},    // 70003E18
{0x0F126242},    // 70003E1A
{0x0F126282},    // 70003E1C
{0x0F12466B},    // 70003E1E
{0x0F12881A},    // 70003E20
{0x0F126302},    // 70003E22
{0x0F12885A},    // 70003E24
{0x0F126342},    // 70003E26
{0x0F126A02},    // 70003E28
{0x0F122A00},    // 70003E2A
{0x0F12D00A},    // 70003E2C
{0x0F126204},    // 70003E2E
{0x0F126849},    // 70003E30
{0x0F126281},    // 70003E32
{0x0F12466B},    // 70003E34
{0x0F128819},    // 70003E36
{0x0F126301},    // 70003E38
{0x0F128859},    // 70003E3A
{0x0F126341},    // 70003E3C
{0x0F1249A5},    // 70003E3E
{0x0F1288C9},    // 70003E40
{0x0F1263C1},    // 70003E42
{0x0F12F000},    // 70003E44
{0x0F12FB40},    // 70003E46
{0x0F12E7A6},    // 70003E48
{0x0F12B5F0},    // 70003E4A
{0x0F12B08B},    // 70003E4C
{0x0F1220FF},    // 70003E4E
{0x0F121C40},    // 70003E50
{0x0F1249A1},    // 70003E52
{0x0F1289CC},    // 70003E54
{0x0F124E9E},    // 70003E56
{0x0F126AB1},    // 70003E58
{0x0F124284},    // 70003E5A
{0x0F12D101},    // 70003E5C
{0x0F12489F},    // 70003E5E
{0x0F126081},    // 70003E60
{0x0F126A70},    // 70003E62
{0x0F120200},    // 70003E64
{0x0F12F000},    // 70003E66
{0x0F12FB37},    // 70003E68
{0x0F120400},    // 70003E6A
{0x0F120C00},    // 70003E6C
{0x0F124A96},    // 70003E6E
{0x0F128A11},    // 70003E70
{0x0F129109},    // 70003E72
{0x0F122101},    // 70003E74
{0x0F120349},    // 70003E76
{0x0F124288},    // 70003E78
{0x0F12D200},    // 70003E7A
{0x0F120001},    // 70003E7C
{0x0F124A92},    // 70003E7E
{0x0F128211},    // 70003E80
{0x0F124D97},    // 70003E82
{0x0F128829},    // 70003E84
{0x0F129108},    // 70003E86
{0x0F124A8B},    // 70003E88
{0x0F122303},    // 70003E8A
{0x0F123222},    // 70003E8C
{0x0F121F91},    // 70003E8E
{0x0F12F000},    // 70003E90
{0x0F12FB28},    // 70003E92
{0x0F128028},    // 70003E94
{0x0F12488E},    // 70003E96
{0x0F124987},    // 70003E98
{0x0F126BC2},    // 70003E9A
{0x0F126AC0},    // 70003E9C
{0x0F124282},    // 70003E9E
{0x0F12D201},    // 70003EA0
{0x0F128CC8},    // 70003EA2
{0x0F128028},    // 70003EA4
{0x0F1288E8},    // 70003EA6
{0x0F129007},    // 70003EA8
{0x0F122240},    // 70003EAA
{0x0F124310},    // 70003EAC
{0x0F1280E8},    // 70003EAE
{0x0F122000},    // 70003EB0
{0x0F120041},    // 70003EB2
{0x0F12194B},    // 70003EB4
{0x0F12001E},    // 70003EB6
{0x0F123680},    // 70003EB8
{0x0F128BB2},    // 70003EBA
{0x0F12AF04},    // 70003EBC
{0x0F12527A},    // 70003EBE
{0x0F124A7D},    // 70003EC0
{0x0F12188A},    // 70003EC2
{0x0F128897},    // 70003EC4
{0x0F1283B7},    // 70003EC6
{0x0F1233A0},    // 70003EC8
{0x0F12891F},    // 70003ECA
{0x0F12AE01},    // 70003ECC
{0x0F125277},    // 70003ECE
{0x0F128A11},    // 70003ED0
{0x0F128119},    // 70003ED2
{0x0F121C40},    // 70003ED4
{0x0F120400},    // 70003ED6
{0x0F120C00},    // 70003ED8
{0x0F122806},    // 70003EDA
{0x0F12D3E9},    // 70003EDC
{0x0F12F000},    // 70003EDE
{0x0F12FB09},    // 70003EE0
{0x0F12F000},    // 70003EE2
{0x0F12FB0F},    // 70003EE4
{0x0F124F79},    // 70003EE6
{0x0F1237A8},    // 70003EE8
{0x0F122800},    // 70003EEA
{0x0F12D10A},    // 70003EEC
{0x0F121FE0},    // 70003EEE
{0x0F1238FD},    // 70003EF0
{0x0F12D001},    // 70003EF2
{0x0F121CC0},    // 70003EF4
{0x0F12D105},    // 70003EF6
{0x0F124874},    // 70003EF8
{0x0F128829},    // 70003EFA
{0x0F123818},    // 70003EFC
{0x0F126840},    // 70003EFE
{0x0F124348},    // 70003F00
{0x0F126078},    // 70003F02
{0x0F124972},    // 70003F04
{0x0F126878},    // 70003F06
{0x0F126B89},    // 70003F08
{0x0F124288},    // 70003F0A
{0x0F12D300},    // 70003F0C
{0x0F120008},    // 70003F0E
{0x0F126078},    // 70003F10
{0x0F122000},    // 70003F12
{0x0F120041},    // 70003F14
{0x0F12AA04},    // 70003F16
{0x0F125A53},    // 70003F18
{0x0F12194A},    // 70003F1A
{0x0F12269C},    // 70003F1C
{0x0F1252B3},    // 70003F1E
{0x0F12AB01},    // 70003F20
{0x0F125A59},    // 70003F22
{0x0F1232A0},    // 70003F24
{0x0F128111},    // 70003F26
{0x0F121C40},    // 70003F28
{0x0F120400},    // 70003F2A
{0x0F120C00},    // 70003F2C
{0x0F122806},    // 70003F2E
{0x0F12D3F0},    // 70003F30
{0x0F124965},    // 70003F32
{0x0F129809},    // 70003F34
{0x0F128208},    // 70003F36
{0x0F129808},    // 70003F38
{0x0F128028},    // 70003F3A
{0x0F129807},    // 70003F3C
{0x0F1280E8},    // 70003F3E
{0x0F121FE0},    // 70003F40
{0x0F1238FD},    // 70003F42
{0x0F12D13B},    // 70003F44
{0x0F124D64},    // 70003F46
{0x0F1289E8},    // 70003F48
{0x0F121FC1},    // 70003F4A
{0x0F1239FF},    // 70003F4C
{0x0F12D136},    // 70003F4E
{0x0F124C5F},    // 70003F50
{0x0F128AE0},    // 70003F52
{0x0F12F000},    // 70003F54
{0x0F12FADE},    // 70003F56
{0x0F120006},    // 70003F58
{0x0F128B20},    // 70003F5A
{0x0F12F000},    // 70003F5C
{0x0F12FAE2},    // 70003F5E
{0x0F129000},    // 70003F60
{0x0F126AA1},    // 70003F62
{0x0F126878},    // 70003F64
{0x0F121809},    // 70003F66
{0x0F120200},    // 70003F68
{0x0F12F000},    // 70003F6A
{0x0F12FAB5},    // 70003F6C
{0x0F120400},    // 70003F6E
{0x0F120C00},    // 70003F70
{0x0F120022},    // 70003F72
{0x0F123246},    // 70003F74
{0x0F120011},    // 70003F76
{0x0F12310A},    // 70003F78
{0x0F122305},    // 70003F7A
{0x0F12F000},    // 70003F7C
{0x0F12FAB2},    // 70003F7E
{0x0F1266E8},    // 70003F80
{0x0F126B23},    // 70003F82
{0x0F120002},    // 70003F84
{0x0F120031},    // 70003F86
{0x0F120018},    // 70003F88
{0x0F12F000},    // 70003F8A
{0x0F12FAD3},    // 70003F8C
{0x0F12466B},    // 70003F8E
{0x0F128518},    // 70003F90
{0x0F126EEA},    // 70003F92
{0x0F126B60},    // 70003F94
{0x0F129900},    // 70003F96
{0x0F12F000},    // 70003F98
{0x0F12FACC},    // 70003F9A
{0x0F12466B},    // 70003F9C
{0x0F128558},    // 70003F9E
{0x0F120029},    // 70003FA0
{0x0F12980A},    // 70003FA2
{0x0F123170},    // 70003FA4
{0x0F12F000},    // 70003FA6
{0x0F12FACD},    // 70003FA8
{0x0F120028},    // 70003FAA
{0x0F123060},    // 70003FAC
{0x0F128A02},    // 70003FAE
{0x0F124946},    // 70003FB0
{0x0F123128},    // 70003FB2
{0x0F12808A},    // 70003FB4
{0x0F128A42},    // 70003FB6
{0x0F1280CA},    // 70003FB8
{0x0F128A80},    // 70003FBA
{0x0F128108},    // 70003FBC
{0x0F12B00B},    // 70003FBE
{0x0F12BCF0},    // 70003FC0
{0x0F12BC08},    // 70003FC2
{0x0F124718},    // 70003FC4
{0x0F12B570},    // 70003FC6
{0x0F122400},    // 70003FC8
{0x0F124D46},    // 70003FCA
{0x0F124846},    // 70003FCC
{0x0F128881},    // 70003FCE
{0x0F124846},    // 70003FD0
{0x0F128041},    // 70003FD2
{0x0F122101},    // 70003FD4
{0x0F128001},    // 70003FD6
{0x0F12F000},    // 70003FD8
{0x0F12FABC},    // 70003FDA
{0x0F124842},    // 70003FDC
{0x0F123820},    // 70003FDE
{0x0F128BC0},    // 70003FE0
{0x0F12F000},    // 70003FE2
{0x0F12FABF},    // 70003FE4
{0x0F124B42},    // 70003FE6
{0x0F12220D},    // 70003FE8
{0x0F120712},    // 70003FEA
{0x0F1218A8},    // 70003FEC
{0x0F128806},    // 70003FEE
{0x0F1200E1},    // 70003FF0
{0x0F1218C9},    // 70003FF2
{0x0F1281CE},    // 70003FF4
{0x0F128846},    // 70003FF6
{0x0F12818E},    // 70003FF8
{0x0F128886},    // 70003FFA
{0x0F12824E},    // 70003FFC
{0x0F1288C0},    // 70003FFE
{0x0F128208},    // 70004000
{0x0F123508},    // 70004002
{0x0F12042D},    // 70004004
{0x0F120C2D},    // 70004006
{0x0F121C64},    // 70004008
{0x0F120424},    // 7000400A
{0x0F120C24},    // 7000400C
{0x0F122C07},    // 7000400E
{0x0F12D3EC},    // 70004010
{0x0F12E658},    // 70004012
{0x0F12B510},    // 70004014
{0x0F124834},    // 70004016
{0x0F124C34},    // 70004018
{0x0F1288C0},    // 7000401A
{0x0F128060},    // 7000401C
{0x0F122001},    // 7000401E
{0x0F128020},    // 70004020
{0x0F124831},    // 70004022
{0x0F123820},    // 70004024
{0x0F128BC0},    // 70004026
{0x0F12F000},    // 70004028
{0x0F12FA9C},    // 7000402A
{0x0F1288E0},    // 7000402C
{0x0F124A31},    // 7000402E
{0x0F122800},    // 70004030
{0x0F12D003},    // 70004032
{0x0F124930},    // 70004034
{0x0F128849},    // 70004036
{0x0F122900},    // 70004038
{0x0F12D009},    // 7000403A
{0x0F122001},    // 7000403C
{0x0F1203C0},    // 7000403E
{0x0F128050},    // 70004040
{0x0F1280D0},    // 70004042
{0x0F122000},    // 70004044
{0x0F128090},    // 70004046
{0x0F128110},    // 70004048
{0x0F12BC10},    // 7000404A
{0x0F12BC08},    // 7000404C
{0x0F124718},    // 7000404E
{0x0F128050},    // 70004050
{0x0F128920},    // 70004052
{0x0F1280D0},    // 70004054
{0x0F128960},    // 70004056
{0x0F120400},    // 70004058
{0x0F121400},    // 7000405A
{0x0F128090},    // 7000405C
{0x0F1289A1},    // 7000405E
{0x0F120409},    // 70004060
{0x0F121409},    // 70004062
{0x0F128111},    // 70004064
{0x0F1289E3},    // 70004066
{0x0F128A24},    // 70004068
{0x0F122B00},    // 7000406A
{0x0F12D104},    // 7000406C
{0x0F1217C3},    // 7000406E
{0x0F120F5B},    // 70004070
{0x0F121818},    // 70004072
{0x0F1210C0},    // 70004074
{0x0F128090},    // 70004076
{0x0F122C00},    // 70004078
{0x0F12D1E6},    // 7000407A
{0x0F1217C8},    // 7000407C
{0x0F120F40},    // 7000407E
{0x0F121840},    // 70004080
{0x0F1210C0},    // 70004082
{0x0F128110},    // 70004084
{0x0F12E7E0},    // 70004086
{0x0F12B510},    // 70004088
{0x0F12000C},    // 7000408A
{0x0F124919},    // 7000408C
{0x0F122204},    // 7000408E
{0x0F126820},    // 70004090
{0x0F125E8A},    // 70004092
{0x0F120140},    // 70004094
{0x0F121A80},    // 70004096
{0x0F120280},    // 70004098
{0x0F128849},    // 7000409A
{0x0F12F000},    // 7000409C
{0x0F12FA6A},    // 7000409E
{0x0F126020},    // 700040A0
{0x0F12E7D2},    // 700040A2
{0x0F1238D4},    // 700040A4
{0x0F127000},    // 700040A6
{0x0F1217D0},    // 700040A8
{0x0F127000},    // 700040AA
{0x0F125000},    // 700040AC
{0x0F12D000},    // 700040AE
{0x0F121100},    // 700040B0
{0x0F12D000},    // 700040B2
{0x0F12171A},    // 700040B4
{0x0F127000},    // 700040B6
{0x0F124780},    // 700040B8
{0x0F127000},    // 700040BA
{0x0F122FCA},    // 700040BC
{0x0F127000},    // 700040BE
{0x0F122FC5},    // 700040C0
{0x0F127000},    // 700040C2
{0x0F122FC6},    // 700040C4
{0x0F127000},    // 700040C6
{0x0F122ED8},    // 700040C8
{0x0F127000},    // 700040CA
{0x0F122BD0},    // 700040CC
{0x0F127000},    // 700040CE
{0x0F1217E0},    // 700040D0
{0x0F127000},    // 700040D2
{0x0F122DE8},    // 700040D4
{0x0F127000},    // 700040D6
{0x0F1237E0},    // 700040D8
{0x0F127000},    // 700040DA
{0x0F12210C},    // 700040DC
{0x0F127000},    // 700040DE
{0x0F121484},    // 700040E0
{0x0F127000},    // 700040E2
{0x0F12A006},    // 700040E4
{0x0F120000},    // 700040E6
{0x0F120724},    // 700040E8
{0x0F127000},    // 700040EA
{0x0F12A000},    // 700040EC
{0x0F12D000},    // 700040EE
{0x0F122270},    // 700040F0
{0x0F127000},    // 700040F2
{0x0F122558},    // 700040F4
{0x0F127000},    // 700040F6
{0x0F12146C},    // 700040F8
{0x0F127000},    // 700040FA
{0x0F12B510},    // 700040FC
{0x0F12000C},    // 700040FE
{0x0F1249C7},    // 70004100
{0x0F122208},    // 70004102
{0x0F126820},    // 70004104
{0x0F125E8A},    // 70004106
{0x0F120140},    // 70004108
{0x0F121A80},    // 7000410A
{0x0F120280},    // 7000410C
{0x0F1288C9},    // 7000410E
{0x0F12F000},    // 70004110
{0x0F12FA30},    // 70004112
{0x0F126020},    // 70004114
{0x0F12E798},    // 70004116
{0x0F12B5FE},    // 70004118
{0x0F12000C},    // 7000411A
{0x0F126825},    // 7000411C
{0x0F126866},    // 7000411E
{0x0F1268A0},    // 70004120
{0x0F129001},    // 70004122
{0x0F1268E7},    // 70004124
{0x0F121BA8},    // 70004126
{0x0F1242B5},    // 70004128
{0x0F12DA00},    // 7000412A
{0x0F121B70},    // 7000412C
{0x0F129000},    // 7000412E
{0x0F1249BB},    // 70004130
{0x0F1248BC},    // 70004132
{0x0F12884A},    // 70004134
{0x0F128843},    // 70004136
{0x0F12435A},    // 70004138
{0x0F122304},    // 7000413A
{0x0F125ECB},    // 7000413C
{0x0F120A92},    // 7000413E
{0x0F1218D2},    // 70004140
{0x0F1202D2},    // 70004142
{0x0F120C12},    // 70004144
{0x0F1288CB},    // 70004146
{0x0F128880},    // 70004148
{0x0F124343},    // 7000414A
{0x0F120A98},    // 7000414C
{0x0F122308},    // 7000414E
{0x0F125ECB},    // 70004150
{0x0F1218C0},    // 70004152
{0x0F1202C0},    // 70004154
{0x0F120C00},    // 70004156
{0x0F120411},    // 70004158
{0x0F120400},    // 7000415A
{0x0F121409},    // 7000415C
{0x0F121400},    // 7000415E
{0x0F121A08},    // 70004160
{0x0F1249B0},    // 70004162
{0x0F1239E0},    // 70004164
{0x0F126148},    // 70004166
{0x0F129801},    // 70004168
{0x0F123040},    // 7000416A
{0x0F127880},    // 7000416C
{0x0F122800},    // 7000416E
{0x0F12D103},    // 70004170
{0x0F129801},    // 70004172
{0x0F120029},    // 70004174
{0x0F12F000},    // 70004176
{0x0F12FA03},    // 70004178
{0x0F128839},    // 7000417A
{0x0F129800},    // 7000417C
{0x0F124281},    // 7000417E
{0x0F12D814},    // 70004180
{0x0F128879},    // 70004182
{0x0F129800},    // 70004184
{0x0F124281},    // 70004186
{0x0F12D20C},    // 70004188
{0x0F129801},    // 7000418A
{0x0F120029},    // 7000418C
{0x0F12F000},    // 7000418E
{0x0F12F9FF},    // 70004190
{0x0F129801},    // 70004192
{0x0F120029},    // 70004194
{0x0F12F000},    // 70004196
{0x0F12F9FB},    // 70004198
{0x0F129801},    // 7000419A
{0x0F120029},    // 7000419C
{0x0F12F000},    // 7000419E
{0x0F12F9F7},    // 700041A0
{0x0F12E003},    // 700041A2
{0x0F129801},    // 700041A4
{0x0F120029},    // 700041A6
{0x0F12F000},    // 700041A8
{0x0F12F9F2},    // 700041AA
{0x0F129801},    // 700041AC
{0x0F120032},    // 700041AE
{0x0F120039},    // 700041B0
{0x0F12F000},    // 700041B2
{0x0F12F9F5},    // 700041B4
{0x0F126020},    // 700041B6
{0x0F12E5D0},    // 700041B8
{0x0F12B57C},    // 700041BA
{0x0F12489A},    // 700041BC
{0x0F12A901},    // 700041BE
{0x0F120004},    // 700041C0
{0x0F12F000},    // 700041C2
{0x0F12F979},    // 700041C4
{0x0F12466B},    // 700041C6
{0x0F1288D9},    // 700041C8
{0x0F128898},    // 700041CA
{0x0F124B95},    // 700041CC
{0x0F123346},    // 700041CE
{0x0F121E9A},    // 700041D0
{0x0F12F000},    // 700041D2
{0x0F12F9ED},    // 700041D4
{0x0F124894},    // 700041D6
{0x0F124992},    // 700041D8
{0x0F123812},    // 700041DA
{0x0F123140},    // 700041DC
{0x0F128A42},    // 700041DE
{0x0F12888B},    // 700041E0
{0x0F1218D2},    // 700041E2
{0x0F128242},    // 700041E4
{0x0F128AC2},    // 700041E6
{0x0F1288C9},    // 700041E8
{0x0F121851},    // 700041EA
{0x0F1282C1},    // 700041EC
{0x0F120020},    // 700041EE
{0x0F124669},    // 700041F0
{0x0F12F000},    // 700041F2
{0x0F12F961},    // 700041F4
{0x0F12488D},    // 700041F6
{0x0F12214D},    // 700041F8
{0x0F128301},    // 700041FA
{0x0F122196},    // 700041FC
{0x0F128381},    // 700041FE
{0x0F12211D},    // 70004200
{0x0F123020},    // 70004202
{0x0F128001},    // 70004204
{0x0F12F000},    // 70004206
{0x0F12F9DB},    // 70004208
{0x0F12F000},    // 7000420A
{0x0F12F9E1},    // 7000420C
{0x0F124888},    // 7000420E
{0x0F124C88},    // 70004210
{0x0F126E00},    // 70004212
{0x0F1260E0},    // 70004214
{0x0F12466B},    // 70004216
{0x0F128818},    // 70004218
{0x0F128859},    // 7000421A
{0x0F120025},    // 7000421C
{0x0F121A40},    // 7000421E
{0x0F123540},    // 70004220
{0x0F1261A8},    // 70004222
{0x0F12487F},    // 70004224
{0x0F129900},    // 70004226
{0x0F123060},    // 70004228
{0x0F12F000},    // 7000422A
{0x0F12F9D9},    // 7000422C
{0x0F12466B},    // 7000422E
{0x0F128819},    // 70004230
{0x0F121DE0},    // 70004232
{0x0F1230F9},    // 70004234
{0x0F128741},    // 70004236
{0x0F128859},    // 70004238
{0x0F128781},    // 7000423A
{0x0F122000},    // 7000423C
{0x0F1271A0},    // 7000423E
{0x0F1274A8},    // 70004240
{0x0F12BC7C},    // 70004242
{0x0F12BC08},    // 70004244
{0x0F124718},    // 70004246
{0x0F12B5F8},    // 70004248
{0x0F120005},    // 7000424A
{0x0F126808},    // 7000424C
{0x0F120400},    // 7000424E
{0x0F120C00},    // 70004250
{0x0F12684A},    // 70004252
{0x0F120412},    // 70004254
{0x0F120C12},    // 70004256
{0x0F12688E},    // 70004258
{0x0F1268CC},    // 7000425A
{0x0F124970},    // 7000425C
{0x0F12884B},    // 7000425E
{0x0F124343},    // 70004260
{0x0F120A98},    // 70004262
{0x0F122304},    // 70004264
{0x0F125ECB},    // 70004266
{0x0F1218C0},    // 70004268
{0x0F1202C0},    // 7000426A
{0x0F120C00},    // 7000426C
{0x0F1288CB},    // 7000426E
{0x0F124353},    // 70004270
{0x0F120A9A},    // 70004272
{0x0F122308},    // 70004274
{0x0F125ECB},    // 70004276
{0x0F1218D1},    // 70004278
{0x0F1202C9},    // 7000427A
{0x0F120C09},    // 7000427C
{0x0F122701},    // 7000427E
{0x0F12003A},    // 70004280
{0x0F1240AA},    // 70004282
{0x0F129200},    // 70004284
{0x0F12002A},    // 70004286
{0x0F123A10},    // 70004288
{0x0F124097},    // 7000428A
{0x0F122D10},    // 7000428C
{0x0F12DA06},    // 7000428E
{0x0F124A69},    // 70004290
{0x0F129B00},    // 70004292
{0x0F128812},    // 70004294
{0x0F12439A},    // 70004296
{0x0F124B67},    // 70004298
{0x0F12801A},    // 7000429A
{0x0F12E003},    // 7000429C
{0x0F124B66},    // 7000429E
{0x0F12885A},    // 700042A0
{0x0F1243BA},    // 700042A2
{0x0F12805A},    // 700042A4
{0x0F120023},    // 700042A6
{0x0F120032},    // 700042A8
{0x0F12F000},    // 700042AA
{0x0F12F981},    // 700042AC
{0x0F122D10},    // 700042AE
{0x0F12DA05},    // 700042B0
{0x0F124961},    // 700042B2
{0x0F129A00},    // 700042B4
{0x0F128808},    // 700042B6
{0x0F124310},    // 700042B8
{0x0F128008},    // 700042BA
{0x0F12E003},    // 700042BC
{0x0F12485E},    // 700042BE
{0x0F128841},    // 700042C0
{0x0F124339},    // 700042C2
{0x0F128041},    // 700042C4
{0x0F124D5B},    // 700042C6
{0x0F122000},    // 700042C8
{0x0F123580},    // 700042CA
{0x0F1288AA},    // 700042CC
{0x0F125E30},    // 700042CE
{0x0F122100},    // 700042D0
{0x0F12F000},    // 700042D2
{0x0F12F98D},    // 700042D4
{0x0F128030},    // 700042D6
{0x0F122000},    // 700042D8
{0x0F1288AA},    // 700042DA
{0x0F125E20},    // 700042DC
{0x0F122100},    // 700042DE
{0x0F12F000},    // 700042E0
{0x0F12F986},    // 700042E2
{0x0F128020},    // 700042E4
{0x0F12E587},    // 700042E6
{0x0F12B510},    // 700042E8
{0x0F12F000},    // 700042EA
{0x0F12F989},    // 700042EC
{0x0F124A53},    // 700042EE
{0x0F128D50},    // 700042F0
{0x0F122800},    // 700042F2
{0x0F12D007},    // 700042F4
{0x0F12494E},    // 700042F6
{0x0F1231C0},    // 700042F8
{0x0F12684B},    // 700042FA
{0x0F124950},    // 700042FC
{0x0F124283},    // 700042FE
{0x0F12D202},    // 70004300
{0x0F128D90},    // 70004302
{0x0F1281C8},    // 70004304
{0x0F12E6A0},    // 70004306
{0x0F128DD0},    // 70004308
{0x0F1281C8},    // 7000430A
{0x0F12E69D},    // 7000430C
{0x0F12B5F8},    // 7000430E
{0x0F12F000},    // 70004310
{0x0F12F97E},    // 70004312
{0x0F124D49},    // 70004314
{0x0F128E28},    // 70004316
{0x0F122800},    // 70004318
{0x0F12D01F},    // 7000431A
{0x0F124E49},    // 7000431C
{0x0F124844},    // 7000431E
{0x0F1268B4},    // 70004320
{0x0F126800},    // 70004322
{0x0F124284},    // 70004324
{0x0F12D903},    // 70004326
{0x0F121A21},    // 70004328
{0x0F120849},    // 7000432A
{0x0F121847},    // 7000432C
{0x0F12E006},    // 7000432E
{0x0F124284},    // 70004330
{0x0F12D203},    // 70004332
{0x0F121B01},    // 70004334
{0x0F120849},    // 70004336
{0x0F121A47},    // 70004338
{0x0F12E000},    // 7000433A
{0x0F120027},    // 7000433C
{0x0F120020},    // 7000433E
{0x0F12493B},    // 70004340
{0x0F123120},    // 70004342
{0x0F127A0C},    // 70004344
{0x0F122C00},    // 70004346
{0x0F12D004},    // 70004348
{0x0F120200},    // 7000434A
{0x0F120039},    // 7000434C
{0x0F12F000},    // 7000434E
{0x0F12F8C3},    // 70004350
{0x0F128668},    // 70004352
{0x0F122C00},    // 70004354
{0x0F12D000},    // 70004356
{0x0F1260B7},    // 70004358
{0x0F12E54D},    // 7000435A
{0x0F1220FF},    // 7000435C
{0x0F121C40},    // 7000435E
{0x0F128668},    // 70004360
{0x0F12E549},    // 70004362
{0x0F12B510},    // 70004364
{0x0F12000C},    // 70004366
{0x0F126820},    // 70004368
{0x0F120400},    // 7000436A
{0x0F120C00},    // 7000436C
{0x0F124933},    // 7000436E
{0x0F128E0A},    // 70004370
{0x0F122A00},    // 70004372
{0x0F12D003},    // 70004374
{0x0F128E49},    // 70004376
{0x0F120200},    // 70004378
{0x0F12F000},    // 7000437A
{0x0F12F8AD},    // 7000437C
{0x0F126020},    // 7000437E
{0x0F120400},    // 70004380
{0x0F120C00},    // 70004382
{0x0F12E661},    // 70004384
{0x0F12B570},    // 70004386
{0x0F12680C},    // 70004388
{0x0F124D2F},    // 7000438A
{0x0F120020},    // 7000438C
{0x0F126F29},    // 7000438E
{0x0F12F000},    // 70004390
{0x0F12F946},    // 70004392
{0x0F126F69},    // 70004394
{0x0F121D20},    // 70004396
{0x0F12F000},    // 70004398
{0x0F12F942},    // 7000439A
{0x0F124827},    // 7000439C
{0x0F128E00},    // 7000439E
{0x0F122800},    // 700043A0
{0x0F12D006},    // 700043A2
{0x0F124922},    // 700043A4
{0x0F122214},    // 700043A6
{0x0F123168},    // 700043A8
{0x0F120008},    // 700043AA
{0x0F12383C},    // 700043AC
{0x0F12F000},    // 700043AE
{0x0F12F93F},    // 700043B0
{0x0F12E488},    // 700043B2
{0x0F12B5F8},    // 700043B4
{0x0F120004},    // 700043B6
{0x0F124D24},    // 700043B8
{0x0F128B68},    // 700043BA
{0x0F122800},    // 700043BC
{0x0F12D012},    // 700043BE
{0x0F124823},    // 700043C0
{0x0F128A00},    // 700043C2
{0x0F1206C0},    // 700043C4
{0x0F12D50E},    // 700043C6
{0x0F124822},    // 700043C8
{0x0F127800},    // 700043CA
{0x0F122800},    // 700043CC
{0x0F12D00A},    // 700043CE
{0x0F12481D},    // 700043D0
{0x0F126FC1},    // 700043D2
{0x0F122000},    // 700043D4
{0x0F12F000},    // 700043D6
{0x0F12F923},    // 700043D8
{0x0F128B28},    // 700043DA
{0x0F122201},    // 700043DC
{0x0F122180},    // 700043DE
{0x0F12F000},    // 700043E0
{0x0F12F92C},    // 700043E2
{0x0F128328},    // 700043E4
{0x0F122101},    // 700043E6
{0x0F12000D},    // 700043E8
{0x0F120020},    // 700043EA
{0x0F123810},    // 700043EC
{0x0F124081},    // 700043EE
{0x0F1240A5},    // 700043F0
{0x0F124F11},    // 700043F2
{0x0F12000E},    // 700043F4
{0x0F122C10},    // 700043F6
{0x0F12DA03},    // 700043F8
{0x0F128838},    // 700043FA
{0x0F1243A8},    // 700043FC
{0x0F128038},    // 700043FE
{0x0F12E002},    // 70004400
{0x0F128878},    // 70004402
{0x0F1243B0},    // 70004404
{0x0F128078},    // 70004406
{0x0F12F000},    // 70004408
{0x0F12F920},    // 7000440A
{0x0F122C10},    // 7000440C
{0x0F12DA03},    // 7000440E
{0x0F128838},    // 70004410
{0x0F124328},    // 70004412
{0x0F128038},    // 70004414
{0x0F12E4EF},    // 70004416
{0x0F128878},    // 70004418
{0x0F124330},    // 7000441A
{0x0F128078},    // 7000441C
{0x0F12E4EB},    // 7000441E
{0x0F122558},    // 70004420
{0x0F127000},    // 70004422
{0x0F122AB8},    // 70004424
{0x0F127000},    // 70004426
{0x0F12145E},    // 70004428
{0x0F127000},    // 7000442A
{0x0F122698},    // 7000442C
{0x0F127000},    // 7000442E
{0x0F122BB8},    // 70004430
{0x0F127000},    // 70004432
{0x0F122998},    // 70004434
{0x0F127000},    // 70004436
{0x0F121100},    // 70004438
{0x0F12D000},    // 7000443A
{0x0F124780},    // 7000443C
{0x0F127000},    // 7000443E
{0x0F12E200},    // 70004440
{0x0F12D000},    // 70004442
{0x0F12210C},    // 70004444
{0x0F127000},    // 70004446
{0x0F120000},    // 70004448
{0x0F127000},    // 7000444A
{0x0F12308C},    // 7000444C
{0x0F127000},    // 7000444E
{0x0F12B040},    // 70004450
{0x0F12D000},    // 70004452
{0x0F123858},    // 70004454
{0x0F127000},    // 70004456
{0x0F124778},    // 70004458
{0x0F1246C0},    // 7000445A
{0x0F12C000},    // 7000445C
{0x0F12E59F},    // 7000445E
{0x0F12FF1C},    // 70004460
{0x0F12E12F},    // 70004462
{0x0F121789},    // 70004464
{0x0F120001},    // 70004466
{0x0F124778},    // 70004468
{0x0F1246C0},    // 7000446A
{0x0F12C000},    // 7000446C
{0x0F12E59F},    // 7000446E
{0x0F12FF1C},    // 70004470
{0x0F12E12F},    // 70004472
{0x0F1216F1},    // 70004474
{0x0F120001},    // 70004476
{0x0F124778},    // 70004478
{0x0F1246C0},    // 7000447A
{0x0F12C000},    // 7000447C
{0x0F12E59F},    // 7000447E
{0x0F12FF1C},    // 70004480
{0x0F12E12F},    // 70004482
{0x0F12C3B1},    // 70004484
{0x0F120000},    // 70004486
{0x0F124778},    // 70004488
{0x0F1246C0},    // 7000448A
{0x0F12C000},    // 7000448C
{0x0F12E59F},    // 7000448E
{0x0F12FF1C},    // 70004490
{0x0F12E12F},    // 70004492
{0x0F12C36D},    // 70004494
{0x0F120000},    // 70004496
{0x0F124778},    // 70004498
{0x0F1246C0},    // 7000449A
{0x0F12C000},    // 7000449C
{0x0F12E59F},    // 7000449E
{0x0F12FF1C},    // 700044A0
{0x0F12E12F},    // 700044A2
{0x0F12F6D7},    // 700044A4
{0x0F120000},    // 700044A6
{0x0F124778},    // 700044A8
{0x0F1246C0},    // 700044AA
{0x0F12C000},    // 700044AC
{0x0F12E59F},    // 700044AE
{0x0F12FF1C},    // 700044B0
{0x0F12E12F},    // 700044B2
{0x0F12B49D},    // 700044B4
{0x0F120000},    // 700044B6
{0x0F124778},    // 700044B8
{0x0F1246C0},    // 700044BA
{0x0F12C000},    // 700044BC
{0x0F12E59F},    // 700044BE
{0x0F12FF1C},    // 700044C0
{0x0F12E12F},    // 700044C2
{0x0F127EDF},    // 700044C4
{0x0F120000},    // 700044C6
{0x0F124778},    // 700044C8
{0x0F1246C0},    // 700044CA
{0x0F12C000},    // 700044CC
{0x0F12E59F},    // 700044CE
{0x0F12FF1C},    // 700044D0
{0x0F12E12F},    // 700044D2
{0x0F12448D},    // 700044D4
{0x0F120000},    // 700044D6
{0x0F124778},    // 700044D8
{0x0F1246C0},    // 700044DA
{0x0F12F004},    // 700044DC
{0x0F12E51F},    // 700044DE
{0x0F1229EC},    // 700044E0
{0x0F120001},    // 700044E2
{0x0F124778},    // 700044E4
{0x0F1246C0},    // 700044E6
{0x0F12C000},    // 700044E8
{0x0F12E59F},    // 700044EA
{0x0F12FF1C},    // 700044EC
{0x0F12E12F},    // 700044EE
{0x0F122EF1},    // 700044F0
{0x0F120000},    // 700044F2
{0x0F124778},    // 700044F4
{0x0F1246C0},    // 700044F6
{0x0F12C000},    // 700044F8
{0x0F12E59F},    // 700044FA
{0x0F12FF1C},    // 700044FC
{0x0F12E12F},    // 700044FE
{0x0F12EE03},    // 70004500
{0x0F120000},    // 70004502
{0x0F124778},    // 70004504
{0x0F1246C0},    // 70004506
{0x0F12C000},    // 70004508
{0x0F12E59F},    // 7000450A
{0x0F12FF1C},    // 7000450C
{0x0F12E12F},    // 7000450E
{0x0F12A58B},    // 70004510
{0x0F120000},    // 70004512
{0x0F124778},    // 70004514
{0x0F1246C0},    // 70004516
{0x0F12C000},    // 70004518
{0x0F12E59F},    // 7000451A
{0x0F12FF1C},    // 7000451C
{0x0F12E12F},    // 7000451E
{0x0F127C49},    // 70004520
{0x0F120000},    // 70004522
{0x0F124778},    // 70004524
{0x0F1246C0},    // 70004526
{0x0F12C000},    // 70004528
{0x0F12E59F},    // 7000452A
{0x0F12FF1C},    // 7000452C
{0x0F12E12F},    // 7000452E
{0x0F127C63},    // 70004530
{0x0F120000},    // 70004532
{0x0F124778},    // 70004534
{0x0F1246C0},    // 70004536
{0x0F12C000},    // 70004538
{0x0F12E59F},    // 7000453A
{0x0F12FF1C},    // 7000453C
{0x0F12E12F},    // 7000453E
{0x0F122DB7},    // 70004540
{0x0F120000},    // 70004542
{0x0F124778},    // 70004544
{0x0F1246C0},    // 70004546
{0x0F12C000},    // 70004548
{0x0F12E59F},    // 7000454A
{0x0F12FF1C},    // 7000454C
{0x0F12E12F},    // 7000454E
{0x0F12EB3D},    // 70004550
{0x0F120000},    // 70004552
{0x0F124778},    // 70004554
{0x0F1246C0},    // 70004556
{0x0F12C000},    // 70004558
{0x0F12E59F},    // 7000455A
{0x0F12FF1C},    // 7000455C
{0x0F12E12F},    // 7000455E
{0x0F12F061},    // 70004560
{0x0F120000},    // 70004562
{0x0F124778},    // 70004564
{0x0F1246C0},    // 70004566
{0x0F12C000},    // 70004568
{0x0F12E59F},    // 7000456A
{0x0F12FF1C},    // 7000456C
{0x0F12E12F},    // 7000456E
{0x0F12F0EF},    // 70004570
{0x0F120000},    // 70004572
{0x0F124778},    // 70004574
{0x0F1246C0},    // 70004576
{0x0F12F004},    // 70004578
{0x0F12E51F},    // 7000457A
{0x0F122824},    // 7000457C
{0x0F120001},    // 7000457E
{0x0F124778},    // 70004580
{0x0F1246C0},    // 70004582
{0x0F12C000},    // 70004584
{0x0F12E59F},    // 70004586
{0x0F12FF1C},    // 70004588
{0x0F12E12F},    // 7000458A
{0x0F128EDD},    // 7000458C
{0x0F120000},    // 7000458E
{0x0F124778},    // 70004590
{0x0F1246C0},    // 70004592
{0x0F12C000},    // 70004594
{0x0F12E59F},    // 70004596
{0x0F12FF1C},    // 70004598
{0x0F12E12F},    // 7000459A
{0x0F128DCB},    // 7000459C
{0x0F120000},    // 7000459E
{0x0F124778},    // 700045A0
{0x0F1246C0},    // 700045A2
{0x0F12C000},    // 700045A4
{0x0F12E59F},    // 700045A6
{0x0F12FF1C},    // 700045A8
{0x0F12E12F},    // 700045AA
{0x0F128E17},    // 700045AC
{0x0F120000},    // 700045AE
{0x0F124778},    // 700045B0
{0x0F1246C0},    // 700045B2
{0x0F12C000},    // 700045B4
{0x0F12E59F},    // 700045B6
{0x0F12FF1C},    // 700045B8
{0x0F12E12F},    // 700045BA
{0x0F1298C5},    // 700045BC
{0x0F120000},    // 700045BE
{0x0F124778},    // 700045C0
{0x0F1246C0},    // 700045C2
{0x0F12C000},    // 700045C4
{0x0F12E59F},    // 700045C6
{0x0F12FF1C},    // 700045C8
{0x0F12E12F},    // 700045CA
{0x0F127C7D},    // 700045CC
{0x0F120000},    // 700045CE
{0x0F124778},    // 700045D0
{0x0F1246C0},    // 700045D2
{0x0F12C000},    // 700045D4
{0x0F12E59F},    // 700045D6
{0x0F12FF1C},    // 700045D8
{0x0F12E12F},    // 700045DA
{0x0F127E31},    // 700045DC
{0x0F120000},    // 700045DE
{0x0F124778},    // 700045E0
{0x0F1246C0},    // 700045E2
{0x0F12C000},    // 700045E4
{0x0F12E59F},    // 700045E6
{0x0F12FF1C},    // 700045E8
{0x0F12E12F},    // 700045EA
{0x0F127EAB},    // 700045EC
{0x0F120000},    // 700045EE
{0x0F124778},    // 700045F0
{0x0F1246C0},    // 700045F2
{0x0F12C000},    // 700045F4
{0x0F12E59F},    // 700045F6
{0x0F12FF1C},    // 700045F8
{0x0F12E12F},    // 700045FA
{0x0F127501},    // 700045FC
{0x0F120000},    // 700045FE
{0x0F124778},    // 70004600
{0x0F1246C0},    // 70004602
{0x0F12C000},    // 70004604
{0x0F12E59F},    // 70004606
{0x0F12FF1C},    // 70004608
{0x0F12E12F},    // 7000460A
{0x0F12F63F},    // 7000460C
{0x0F120000},    // 7000460E
{0x0F124778},    // 70004610
{0x0F1246C0},    // 70004612
{0x0F12C000},    // 70004614
{0x0F12E59F},    // 70004616
{0x0F12FF1C},    // 70004618
{0x0F12E12F},    // 7000461A
{0x0F123D0B},    // 7000461C
{0x0F120000},    // 7000461E
{0x0F124778},    // 70004620
{0x0F1246C0},    // 70004622
{0x0F12C000},    // 70004624
{0x0F12E59F},    // 70004626
{0x0F12FF1C},    // 70004628
{0x0F12E12F},    // 7000462A
{0x0F1229BF},    // 7000462C
{0x0F120001},    // 7000462E
{0x0F124778},    // 70004630
{0x0F1246C0},    // 70004632
{0x0F12F004},    // 70004634
{0x0F12E51F},    // 70004636
{0x0F1226D8},    // 70004638
{0x0F120001},    // 7000463A
{0x0F124778},    // 7000463C
{0x0F1246C0},    // 7000463E
{0x0F12C000},    // 70004640
{0x0F12E59F},    // 70004642
{0x0F12FF1C},    // 70004644
{0x0F12E12F},    // 70004646
{0x0F12306B},    // 70004648
{0x0F120000},    // 7000464A
{0x0F124778},    // 7000464C
{0x0F1246C0},    // 7000464E
{0x0F12C000},    // 70004650
{0x0F12E59F},    // 70004652
{0x0F12FF1C},    // 70004654
{0x0F12E12F},    // 70004656
{0x0F126099},    // 70004658
{0x0F120000},    // 7000465A
// End of Patch Data(Last : 7000465Ah)
// Total Size 2916 (0x0B64)
// Addr : 3AF8 , Size : 2914(B62h)

// TNP_USER_MBCV_CONTROL
// TNP_4EC_MBR_TUNE
// TNP_4EC_FORBIDDEN_TUNE
// TNP_AF_FINESEARCH_DRIVEBACK
// TNP_FLASH_ALG
// TNP_GAS_ALPHA_OTP
// TNP_AWB_MODUL_COMP
// TNP_AWB_INIT_QUEUE
// TNP_AWB_GRID_LOWBR
// TNP_AWB_GRID_MODULECOMP
// TNP_ADLC_TUNE
// TNP_1FRAME_AE
// TNP_TG_OFF_CFG_CHG_IN_SPOOF_MODE

//==================================================================================
// 05.OTP Control 
//==================================================================================

{0x00287000},
{0x002A0722},	
{0x0F120100},	//skl_OTP_usWaitTime This register should be positioned in fornt of D0001000	
{0x002A0726},	
{0x0F120001},	//skl_bUseOTPfunc This is OTP on/off function	
{0x002A08D6},	
{0x0F120001},	//ash_bUseOTPData	
{0x002A146E},	
{0x0F120000},	//awbb_otp_disable	
{0x002A08DC},	
{0x0F120000},	//ash_bUseGasAlphaOTP	

{0x0028D000},
{0x002A1000},
{0x0F120001},

//==================================================================================
// 06.Gas_Anti Shading
//==================================================================================
//===================================================================
// GAS Alpha setting
//===================================================================
// Refer Mon_AWB_RotGain
{0x00287000},         	
{0x002A08B4},	
{0x0F120001},	//wbt_bUseOutdoorASH	
{0x002A08BC},	
{0x0F1200C0},	//TVAR_ash_AwbAshCord_0_ 2300K	
{0x0F1200DF},	//TVAR_ash_AwbAshCord_1_ 2750K	
{0x0F120100},	//TVAR_ash_AwbAshCord_2_ 3300K	
{0x0F120125},	//TVAR_ash_AwbAshCord_3_ 4150K	
{0x0F12015F},	//TVAR_ash_AwbAshCord_4_ 5250K	
{0x0F12017C},	//TVAR_ash_AwbAshCord_5_ 6400K	
{0x0F120194},	//TVAR_ash_AwbAshCord_6_ 7500K	
	
{0x002A08F6},	
{0x0F124000},	//TVAR_ash_GASAlpha_0__0_ R  // 2300K     	
{0x0F124000},	//TVAR_ash_GASAlpha_0__1_ GR          
{0x0F124000},	//TVAR_ash_GASAlpha_0__2_ GB          
{0x0F124000},	//TVAR_ash_GASAlpha_0__3_ B    

{0x0F124000},	//TVAR_ash_GASAlpha_1__0_ R  // 2750K 
{0x0F124000},	//TVAR_ash_GASAlpha_1__1_ GR          
{0x0F124000},	//TVAR_ash_GASAlpha_1__2_ GB  
{0x0F124000},	//TVAR_ash_GASAlpha_1__3_ B   

{0x0F124000},	//TVAR_ash_GASAlpha_2__0_ R  // 3300K 
{0x0F124000},	//TVAR_ash_GASAlpha_2__1_ GR          
{0x0F124000},	//TVAR_ash_GASAlpha_2__2_ GB          
{0x0F124000},	//TVAR_ash_GASAlpha_2__3_ B   

{0x0F123800}, 	//TVAR_ash_GASAlpha_3__0_ R  // 4150K 
{0x0F124000},	//TVAR_ash_GASAlpha_3__1_ GR          
{0x0F124000},	//TVAR_ash_GASAlpha_3__2_ GB          
{0x0F124000},	//TVAR_ash_GASAlpha_3__3_ B    

{0x0F123B00}, 	//TVAR_ash_GASAlpha_4__0_ R  // 5250K 
{0x0F124000},	//TVAR_ash_GASAlpha_4__1_ GR          
{0x0F124000},	//TVAR_ash_GASAlpha_4__2_ GB          
{0x0F124000},	//TVAR_ash_GASAlpha_4__3_ B      

{0x0F124300}, 	//TVAR_ash_GASAlpha_5__0_ R  // 6400K 
{0x0F124000},	//TVAR_ash_GASAlpha_5__1_ GR          
{0x0F124000},	//TVAR_ash_GASAlpha_5__2_ GB          
{0x0F124000},	//TVAR_ash_GASAlpha_5__3_ B        

{0x0F124300},	//TVAR_ash_GASAlpha_6__0_ R  // 7500K 
{0x0F124000},	//TVAR_ash_GASAlpha_6__1_ GR          
{0x0F124000},	//TVAR_ash_GASAlpha_6__2_ GB          
{0x0F124000},	//TVAR_ash_GASAlpha_6__3_ B        

//Outdoor GAS Alpha   
{0x0F124500},  	
{0x0F124000},	
{0x0F124000},	
{0x0F124000},
	
{0x002A08F4},	
{0x0F120001},	//ash_bUseGasAlpha

//==================================================================================
// 07. Analog Setting 2 
//==================================================================================   
//This register is for FACTORY ONLY. 
//If you change it without prior notification
//YOU are RESPONSIBLE for the FAILURE that will happen in the future      
//For subsampling Size	
	
{0x00287000},	
{0x002A18BC},	
{0x0F120004},	
{0x0F1205B6},	
{0x0F120000},	
{0x0F120000},	
{0x0F120001},	
{0x0F1205BA},	
{0x0F120000},	
{0x0F120000},	
{0x0F120007},	
{0x0F1205BA},	
{0x0F120000},	
{0x0F120000},	
{0x0F1201F4},	
{0x0F12024E},	
{0x0F120000},	
{0x0F120000},	
{0x0F1201F4},	
{0x0F1205B6},	
{0x0F120000},	
{0x0F120000},	
{0x0F1201F4},	
{0x0F1205BA},	
{0x0F120000},	
{0x0F120000},	
{0x0F1201F4},	
{0x0F12024F},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120075},	
{0x0F1200CF},	
{0x0F120000},	
{0x0F120000},	
{0x0F120075},	
{0x0F1200D6},	
{0x0F120000},	
{0x0F120000},	
{0x0F120004},	
{0x0F1201F4},	
{0x0F120000},	
{0x0F120000},	
{0x0F1200F0},	
{0x0F1201F4},	
{0x0F12029E},	
{0x0F1205B2},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F1201F8},	
{0x0F120228},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120208},	
{0x0F120238},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120218},	
{0x0F120238},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120001},	
{0x0F120009},	
{0x0F1200DE},	
{0x0F1205C0},	
{0x0F120000},	
{0x0F120000},	
{0x0F1200DF},	
{0x0F1200E4},	
{0x0F1201F8},	
{0x0F1201FD},	
{0x0F1205B6},	
{0x0F1205BB},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F1201F8},	
{0x0F120000},	
{0x0F120000},	
{0x0F120077},	
{0x0F12007E},	
{0x0F12024F},	
{0x0F12025E},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
	
 // For Capture 	
	
{0x0F120004},	
{0x0F1209D1},	
{0x0F120000},	
{0x0F120000},	
{0x0F120001},	
{0x0F1209D5},	
{0x0F120000},	
{0x0F120000},	
{0x0F120008},	
{0x0F1209D5},	
{0x0F120000},	
{0x0F120000},	
{0x0F1202AA},	
{0x0F120326},	
{0x0F120000},	
{0x0F120000},	
{0x0F1202AA},	
{0x0F1209D1},	
{0x0F120000},	
{0x0F120000},	
{0x0F1202AA},	
{0x0F1209D5},	
{0x0F120000},	
{0x0F120000},	
{0x0F1202AA},	
{0x0F120327},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120008},	
{0x0F120084},	
{0x0F120000},	
{0x0F120000},	
{0x0F120008},	
{0x0F12008D},	
{0x0F120000},	
{0x0F120000},	
{0x0F120008},	
{0x0F1202AA},	
{0x0F120000},	
{0x0F120000},	
{0x0F1200AA},	
{0x0F1202AA},	
{0x0F1203AD},	
{0x0F1209CD},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F1202AE},	
{0x0F1202DE},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F1202BE},	
{0x0F1202EE},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F1202CE},	
{0x0F1202EE},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120001},	
{0x0F120009},	
{0x0F120095},	
{0x0F1209DB},	
{0x0F120000},	
{0x0F120000},	
{0x0F120096},	
{0x0F12009B},	
{0x0F1202AE},	
{0x0F1202B3},	
{0x0F1209D1},	
{0x0F1209D6},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F1202AE},	
{0x0F120000},	
{0x0F120000},	
{0x0F120009},	
{0x0F120010},	
{0x0F120327},	
{0x0F120336},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
{0x0F120000},	
	
{0x002A1AF8},	
{0x0F125A3C},	//senHal_TuneStr_AngTuneData1_2_D000F400 register at subsampling
{0x002A1896},	
{0x0F120002},	//senHal_SamplingType	0002 03EE: PLA setting          
{0x0F120000},	//senHal_SamplingMode 0 : 2 PLA / 1 : 4PLA              
{0x0F120003},	//senHal_PLAOption	[0] VPLA enable  [1] HPLA enable

{0x002A1B00},  //Green Noise
{0x0F12F428},
{0x0F12FFFF},
{0x0F120000},

{0x002A189E},	
{0x0F120FB0},	//senHal_ExpMinPixels
{0x002A18AC},	
{0x0F120060},	//senHal_uAddColsBin  
{0x0F120060},	//senHal_uAddColsNoBin
{0x0F1205C0},	//senHal_uMinColsBin  
{0x0F1205C0},	//senHal_uMinColsNoBin
{0x002A1AEA},	
{0x0F128080},	//senHal_SubF404Tune 
{0x0F120080},	//senHal_FullF404Tune
{0x002A1AE0},	                     
{0x0F120000},	//senHal_bSenAAC     
{0x002A1A72},	
{0x0F120000},	//senHal_bSRX	SRX off
{0x002A18A2},	
{0x0F120004},	//senHal_NExpLinesCheckFine extend Forbidden area line       
{0x002A1A6A},	                                                             
{0x0F12009A},	//senHal_usForbiddenRightOfs extend right Forbidden area line
{0x002A385E},	                                                             
{0x0F12024C},	//Mon_Sen_uExpPixelsOfs                                      
{0x002A0EE6},	
{0x0F120000},	//setot_bUseDigitalHbin
{0x002A1B2A},	
{0x0F120300},	//70001B2A //senHal_TuneStr2_usAngTuneGainTh	
{0x0F1200D6},	//70001B2C //senHal_TuneStr2_AngTuneF4CA_0_ 
{0x0F12008D},	//70001B2E //senHal_TuneStr2_AngTuneF4CA_1_ 
{0x0F1200CF},	//70001B30 //senHal_TuneStr2_AngTuneF4C2_0_ 
{0x0F120084},	//70001B32 //senHal_TuneStr2_AngTuneF4C2_1_ 

//==================================================================================
// 08.AF Setting
//==================================================================================

//AF interface setting	
{0x00287000},	
{0x002A01FC},	
{0x0F120001},	//REG_TC_IPRM_LedGpio, for Flash control             
{0x002A01FE},	                                                    
{0x0F120003},	//REG_TC_IPRM_CM_Init_AfModeType, VCM IIC          
{0x0F120000},	//REG_TC_IPRM_CM_Init_PwmConfig1                   
{0x002A0204},	                                                    
{0x0F120061},	//REG_TC_IPRM_CM_Init_GpioConfig1, AF Enable GPIO 6
{0x002A020C},	                                                    
{0x0F122F0C},	//REG_TC_IPRM_CM_Init_Mi2cBit                      
{0x0F120190},	//REG_TC_IPRM_CM_Init_Mi2cRateKhz, IIC Speed       
	
	
//AF Window Settings	
{0x002A0294},	
{0x0F120100},	//REG_TC_AF_FstWinStartX   
{0x0F1200E3},	//REG_TC_AF_FstWinStartY   
{0x0F120200},	//REG_TC_AF_FstWinSizeX    
{0x0F120238},	//REG_TC_AF_FstWinSizeY    
{0x0F1201C6},	//REG_TC_AF_ScndWinStartX  
{0x0F120166},	//REG_TC_AF_ScndWinStartY  
{0x0F120074},	//REG_TC_AF_ScndWinSizeX   
{0x0F120132},	//REG_TC_AF_ScndWinSizeY   
{0x0F120001},	//REG_TC_AF_WinSizesUpdated
	
	
//2nd search setting	
{0x002A070E},	
{0x0F1200C0},	//skl_af_StatOvlpExpFactor 
{0x002A071E},	                            
{0x0F120000},	//skl_af_bAfStatOff        
{0x002A163C},	                            
{0x0F120000},	//af_search_usAeStable     
{0x002A1648},	                            
{0x0F129002},	//af_search_usSingleAfFlags
{0x002A1652},	                            
{0x0F120002},	//af_search_usFinePeakCount
{0x0F120000},	//af_search_usFineMaxScale 
{0x002A15E0},	                            
{0x0F120902},	//af_pos_usFineStepNumSize 
{0x002A1656},	                            
{0x0F120000},	//af_search_usCapturePolicy
	
	
//Peak Threshold	
{0x002A164C},	
{0x0F120003},	//af_search_usMinPeakSamples  
{0x002A163E},	                               
{0x0F1200A0},	//af_search_usPeakThr 	//C0 -> A0 af_search_usPeakThr Full search (E5 90%)        
{0x0F120098},	//af_search_usPeakThrLow  //80->98    //98(60%) -> CC(80%) SEHF_CHECK_IT 
{0x002A47A8},	                               
{0x0F120080},	//TNP, Macro Threshold register
	
	
//Home Pos	
{0x002A15D4},	
{0x0F120000},	//af_pos_usHomePos   
{0x0F12D000},	//af_pos_usLowConfPos
	
	
//AF statistics	
{0x002A169A}, 	
{0x0F12FF95}, 	//af_search_usConfCheckOrder_1_
{0x002A166A}, 	                               
{0x0F120280}, 	//af_search_usConfThr_4_       
{0x002A1676}, 	                               
{0x0F1203A0}, 	//af_search_usConfThr_10_      
{0x0F120320}, 	//af_search_usConfThr_11_      
{0x002A16BC}, 	                               
{0x0F120030}, 	//af_stat_usMinStatVal         
{0x002A16E0}, 	                               
{0x0F120060}, 	//af_scene_usSceneLowNormBrThr 
{0x002A16D4}, 	                               
{0x0F120010}, 	//af_stat_usBpfThresh   
{0x002A1656},
{0x0F120000},	//af_search_usCapturePolicy
{0x002A15E6},
{0x0F12003C},	//af_pos_usCaptureFixedPos      
	
	
//AF Lens Position Table Settings	
{0x002A15E8},	
{0x0F120018},	//10->18 af_pos_usTableLastInd SEHF_CHECK_IT

{0x0F12002A}, //af_pos_usTable
{0x0F120030}, //af_pos_usTable
{0x0F120036}, //af_pos_usTable
{0x0F12003C}, //af_pos_usTable
{0x0F120042}, //af_pos_usTable
{0x0F120048}, //af_pos_usTable
{0x0F12004E}, //af_pos_usTable
{0x0F120054}, //af_pos_usTable
{0x0F12005A}, //af_pos_usTable
{0x0F120060}, //af_pos_usTable
{0x0F120066}, //af_pos_usTable
{0x0F12006C}, //af_pos_usTable
{0x0F120072}, //af_pos_usTable
{0x0F120078}, //af_pos_usTable
{0x0F12007E}, //af_pos_usTable
{0x0F120084}, //af_pos_usTable
{0x0F12008A}, //af_pos_usTable
{0x0F120090}, //af_pos_usTable
{0x0F120096}, //af_pos_usTable
{0x0F12009C}, //af_pos_usTable
{0x0F1200A2}, //af_pos_usTable
{0x0F1200A8}, //af_pos_usTable
{0x0F1200AE}, //af_pos_usTable
{0x0F1200B4}, //af_pos_usTable
{0x0F1200BA}, //af_pos_usTable
            
	
//VCM AF driver with PWM/I2C	
{0x002A1722},	
{0x0F128000},	//afd_usParam[0] I2C power down command                          
{0x0F120006},	//afd_usParam[1] Position Right Shift                            
{0x0F123FF0},	//afd_usParam[2] I2C Data Mask                                   
{0x0F1203E8},	//afd_usParam[3] PWM Period                                      
{0x0F120000},	//afd_usParam[4] PWM Divider                                     
{0x0F120005},	//afd_usParam[5] SlowMotion Delay 4. reduce lens collision noise.delay2 when threshold upper lens moving when moving distance 9 delay 80h 25.6ms delay SEHF_SHIN      
{0x0F120001},	//afd_usParam[6] SlowMotion Threshold 10->1  SEHF_CHECK_IT                            
{0x0F12000A},	//afd_usParam[7] Signal Shaping                                  
{0x0F120080},	//afd_usParam[8] Signal Shaping level                            
{0x0F1200C0},	//afd_usParam[9] Signal Shaping level                            
{0x0F1200E0},	//afd_usParam[10] Signal Shaping level                           
{0x0F120000},	//afd_usParam[11] Signal Shaping level                           
	
{0x002A028C},	
{0x0F120003},	//REG_TC_AF_AfCmd

//==================================================================================
// 09.AWB-BASIC setting
//==================================================================================

// AWB init Start point
{0x002A145E},
{0x0F1205C0},	//0625 awbb_GainsInit_0_
{0x0F120400},	//0400 awbb_GainsInit_1_
{0x0F120700},	//07F2 awbb_GainsInit_2_

// AWB Convergence Speed
{0x002A1464},
{0x0F120008},	//awbb_WpFilterMinThr
{0x0F120190},	//awbb_WpFilterMaxThr
{0x0F1200A0},	//awbb_WpFilterCoef
{0x0F120004},	//awbb_WpFilterSize		
{0x0F120002},	//awbb_GridEnable

{0x002A144E},			
{0x0F12FFE0},	//awbb_RGainOff_edit SEHF	
{0x0F12FFE0},	//awbb_BGainOff_edit SEHF		
{0x0F120000},	//awbb_GGainOff_edit SEHF	 		
{0x0f1200C2},	//awbb_Alpha_Comp_Mode		
{0x0F120002},	//awbb_Rpl_InvalidOutDoor		
{0x0F120001},	//awbb_UseGrThrCorr		
{0x0F120074},	//awbb_Use_Filters     		
{0x0F120001},	//awbb_CorrectMinNumPatches		

// White Locus
{0x002A11F0},
{0x0F120120},	//awbb_IntcR
{0x0F120121},	//awbb_IntcB
{0x0F1202DF},	//awbb_GLocusR(default:0x2DF)		
{0x0F120314},	//awbb_GLocusB(default:0x314)	

{0x002A120E},
{0x0F120000},	//awbb_MovingScale10
{0x0F120771},	//awbb_GamutWidthThr1
{0x0F1203A4},	//awbb_GamutHeightThr1_edit SEHF
{0x0F120036},	//awbb_GamutWidthThr2_edit SEHF
{0x0F12002A},	//awbb_GamutHeightThr2_edit SEHF

{0x002A1278},
{0x0F12FEF7},	//awbb_SCDetectionMap_SEC_StartR_B
{0x0F120021},	//awbb_SCDetectionMap_SEC_StepR_B
{0x0F120AF0},	//awbb_SCDetectionMap_SEC_SunnyNB_edit SEHF
{0x0F120AF0},	//awbb_SCDetectionMap_SEC_StepNB_edit SEHF
{0x0F12018F},	//awbb_SCDetectionMap_SEC_LowTempR_B_edit SEHF
{0x0F120096},	//awbb_SCDetectionMap_SEC_SunnyNBZone
{0x0F12000E},	//awbb_SCDetectionMap_SEC_LowTempR_BZone_edit SEHF

{0x002A1224},
{0x0F120032},	//awbb_LowBr
{0x0F12001E},	//awbb_LowBr_NBzone
{0x0F1200C0},	//awbb_YThreshHigh_edit SEHF
{0x0F120010},	//awbb_YThreshLow_Norm
{0x0F120002},	//awbb_YThreshLow_Low
{0x002A2BA4},
{0x0F120006},	//Mon_AWB_ByPassMode_edit SEHF
				
{0x002A11FC},			
{0x0F12000C},	//awbb_MinNumOfFinalPatches  		

{0x002A1208},  
{0x0F120020},	//awbb_MinNumOfChromaclassifpatches
			
// Indoor Zone
{0x002A101C},
{0x0F12037C},	//awbb_IndoorGrZones_m_BGrid_0__m_left
{0x0F12038E},	//awbb_IndoorGrZones_m_BGrid_0__m_right
{0x0F12033C},	//awbb_IndoorGrZones_m_BGrid_1__m_left
{0x0F120384},	//awbb_IndoorGrZones_m_BGrid_1__m_right
{0x0F1202FE},	//awbb_IndoorGrZones_m_BGrid_2__m_left
{0x0F12036C},	//awbb_IndoorGrZones_m_BGrid_2__m_right
{0x0F1202BA},	//awbb_IndoorGrZones_m_BGrid_3__m_left
{0x0F120352},	//awbb_IndoorGrZones_m_BGrid_3__m_right
{0x0F12028E},	//awbb_IndoorGrZones_m_BGrid_4__m_left
{0x0F120300},	//awbb_IndoorGrZones_m_BGrid_4__m_right
{0x0F12026A},	//awbb_IndoorGrZones_m_BGrid_5__m_left
{0x0F1202C8},	//awbb_IndoorGrZones_m_BGrid_5__m_right
{0x0F120254},	//awbb_IndoorGrZones_m_BGrid_6__m_left
{0x0F1202A8},	//awbb_IndoorGrZones_m_BGrid_6__m_right
{0x0F120242},	//awbb_IndoorGrZones_m_BGrid_7__m_left
{0x0F1202A0},	//awbb_IndoorGrZones_m_BGrid_7__m_right
{0x0F12021A},	//awbb_IndoorGrZones_m_BGrid_8__m_left
{0x0F1202A0},	//awbb_IndoorGrZones_m_BGrid_8__m_right
{0x0F1201F4},	//awbb_IndoorGrZones_m_BGrid_9__m_left
{0x0F120298},	//awbb_IndoorGrZones_m_BGrid_9__m_right
{0x0F1201D4},	//awbb_IndoorGrZones_m_BGrid_10__m_left
{0x0F120290},	//awbb_IndoorGrZones_m_BGrid_10__m_right
{0x0F1201CC},	//awbb_IndoorGrZones_m_BGrid_11__m_left
{0x0F120276},	//awbb_IndoorGrZones_m_BGrid_11__m_right
{0x0F1201D2},	//awbb_IndoorGrZones_m_BGrid_12__m_left
{0x0F120260},	//awbb_IndoorGrZones_m_BGrid_12__m_right
{0x0F1201F6},	//awbb_IndoorGrZones_m_BGrid_13__m_left
{0x0F12023A},	//awbb_IndoorGrZones_m_BGrid_13__m_right
{0x0F120000},	//awbb_IndoorGrZones_m_BGrid_14__m_left
{0x0F120000},	//awbb_IndoorGrZones_m_BGrid_14__m_right
{0x0F120000},	//awbb_IndoorGrZones_m_BGrid_15__m_left
{0x0F120000},	//awbb_IndoorGrZones_m_BGrid_15__m_right
{0x0F120000},	//awbb_IndoorGrZones_m_BGrid_16__m_left
{0x0F120000},	//awbb_IndoorGrZones_m_BGrid_16__m_right
{0x0F120000},	//awbb_IndoorGrZones_m_BGrid_17__m_left
{0x0F120000},	//awbb_IndoorGrZones_m_BGrid_17__m_right
{0x0F120000},	//awbb_IndoorGrZones_m_BGrid_18__m_left
{0x0F120000},	//awbb_IndoorGrZones_m_BGrid_18__m_right
{0x0F120000},	//awbb_IndoorGrZones_m_BGrid_19__m_left
{0x0F120000},	//awbb_IndoorGrZones_m_BGrid_19__m_right

{0x0F120005},	//awbb_IndoorGrZones_m_GridStep
{0x002A1070},
{0x0F12000E},	//awbb_IndoorGrZones_ZInfo_m_GridSz_edit SEHF
{0x002A1074},
{0x0F120126},	//awbb_IndoorGrZones_m_Boffs_edit SEHF

// Outdoor Zone
{0x002A1078},
{0x0F12026A},	//awbb_OutdoorGrZones_m_BGrid_0__m_left
{0x0F120296},	//awbb_OutdoorGrZones_m_BGrid_0__m_right
{0x0F12025E},	//awbb_OutdoorGrZones_m_BGrid_1__m_left
{0x0F1202C2},	//awbb_OutdoorGrZones_m_BGrid_1__m_right
{0x0F120252},	//awbb_OutdoorGrZones_m_BGrid_2__m_left
{0x0F1202CA},	//awbb_OutdoorGrZones_m_BGrid_2__m_right
{0x0F120246},	//awbb_OutdoorGrZones_m_BGrid_3__m_left
{0x0F1202CC},	//awbb_OutdoorGrZones_m_BGrid_3__m_right
{0x0F120238},	//awbb_OutdoorGrZones_m_BGrid_4__m_left
{0x0F1202CC},	//awbb_OutdoorGrZones_m_BGrid_4__m_right
{0x0F12022C},	//awbb_OutdoorGrZones_m_BGrid_5__m_left
{0x0F1202C0},	//awbb_OutdoorGrZones_m_BGrid_5__m_right
{0x0F120224},	//awbb_OutdoorGrZones_m_BGrid_6__m_left
{0x0F1202B4},	//awbb_OutdoorGrZones_m_BGrid_6__m_right
{0x0F120222},	//awbb_OutdoorGrZones_m_BGrid_7__m_left
{0x0F1202AA},	//awbb_OutdoorGrZones_m_BGrid_7__m_right
{0x0F120226},	//awbb_OutdoorGrZones_m_BGrid_8__m_left
{0x0F12029E},	//awbb_OutdoorGrZones_m_BGrid_8__m_right
{0x0F12022E},	//awbb_OutdoorGrZones_m_BGrid_9__m_left
{0x0F12028E},	//awbb_OutdoorGrZones_m_BGrid_9__m_right
{0x0F120246},	//awbb_OutdoorGrZones_m_BGrid_10__m_left
{0x0F120276},	//awbb_OutdoorGrZones_m_BGrid_10__m_right
{0x0F120000},	//awbb_OutdoorGrZones_m_BGrid_11__m_left
{0x0F120000},	//awbb_OutdoorGrZones_m_BGrid_11__m_right
           
{0x0F120004},	//awbb_OutdoorGrZones_m_GridStep
{0x002A10AC},
{0x0F12000B},	//awbb_OutdoorGrZones_ZInfo_m_GridSz_edit SEHF
{0x002A10B0},
{0x0F1201D6},	//awbb_OutdoorGrZones_m_Boffs_edit SEHF
     
// Low Brightness Zone
{0x002A10B4},
{0x0F120350},	//awbb_LowBrGrZones_m_BGrid_0__m_left
{0x0F120422},	//awbb_LowBrGrZones_m_BGrid_0__m_right
{0x0F1202C4},	//awbb_LowBrGrZones_m_BGrid_1__m_left
{0x0F120452},	//awbb_LowBrGrZones_m_BGrid_1__m_right
{0x0F120278},	//awbb_LowBrGrZones_m_BGrid_2__m_left
{0x0F12041C},	//awbb_LowBrGrZones_m_BGrid_2__m_right
{0x0F120230},	//awbb_LowBrGrZones_m_BGrid_3__m_left
{0x0F1203EE},	//awbb_LowBrGrZones_m_BGrid_3__m_right
{0x0F1201F0},	//awbb_LowBrGrZones_m_BGrid_4__m_left
{0x0F120392},	//awbb_LowBrGrZones_m_BGrid_4__m_right
{0x0F1201C0},	//awbb_LowBrGrZones_m_BGrid_5__m_left
{0x0F120340},	//awbb_LowBrGrZones_m_BGrid_5__m_right
{0x0F120194},	//awbb_LowBrGrZones_m_BGrid_6__m_left
{0x0F120302},	//awbb_LowBrGrZones_m_BGrid_6__m_right
{0x0F12016E},	//awbb_LowBrGrZones_m_BGrid_7__m_left
{0x0F1202C2},	//awbb_LowBrGrZones_m_BGrid_7__m_right
{0x0F120148},	//awbb_LowBrGrZones_m_BGrid_8__m_left
{0x0F120286},	//awbb_LowBrGrZones_m_BGrid_8__m_right
{0x0F12018A},	//awbb_LowBrGrZones_m_BGrid_9__m_left
{0x0F120242},	//awbb_LowBrGrZones_m_BGrid_9__m_right
{0x0F120000},	//awbb_LowBrGrZones_m_BGrid_10__m_left
{0x0F120000},	//awbb_LowBrGrZones_m_BGrid_10__m_right
{0x0F120000},	//awbb_LowBrGrZones_m_BGrid_11__m_left
{0x0F120000},	//awbb_LowBrGrZones_m_BGrid_11__m_right

{0x0F120006},	//awbb_LowBrGrZones_m_GridStep
{0x002A10E8},
{0x0F12000A},	//awbb_LowBrGrZones_ZInfo_m_GridSz
{0x002A10EC},
{0x0F120106},	//awbb_LowBrGrZones_m_Boffs_edit SEHF

// Low Temp. Zone
{0x002A10F0},
{0x0F120380}, //_edit SEHF
{0x0F120000},	//awbb_CrclLowT_R_c
{0x0F120168}, //_edit SEHF
{0x0F120000},	//awbb_CrclLowT_B_c
{0x0F122D90}, //_edit SEHF
{0x0F120000},	//awbb_CrclLowT_Rad_c   	
			
//AWB - GridCorrection			
{0x002A1434},
{0x0F1202CE},	//awbb_GridConst_1_0_
{0x0F120347},	//awbb_GridConst_1_1_
{0x0F1203C2},	//awbb_GridConst_1_2_
{0x0F1210A0},	//awbb_GridConst_2_0_
{0x0F1210A1},	//awbb_GridConst_2_1_
{0x0F121185},	//awbb_GridConst_2_2_
{0x0F121186},	//awbb_GridConst_2_3_
{0x0F1211E5},	//awbb_GridConst_2_4_
{0x0F1211E6},	//awbb_GridConst_2_5_
{0x0F1200AB},	//awbb_GridCoeff_R_1
{0x0F1200BF},	//awbb_GridCoeff_B_1
{0x0F1200D2},	//awbb_GridCoeff_R_2
{0x0F120093},	//awbb_GridCoeff_B_2

// Indoor Grid Offset			
{0x002A13A4},
{0x0F120000},	//awbb_GridCorr_R_0__0_
{0x0F12FFE8},	//awbb_GridCorr_R_0__1_
{0x0F12FFE8},	//awbb_GridCorr_R_0__2_
{0x0F12FFD8},	//awbb_GridCorr_R_0__3_
{0x0F12FFD8},	//awbb_GridCorr_R_0__4_
{0x0F12FFD0},	//awbb_GridCorr_R_0__5_

{0x0F120000},	//awbb_GridCorr_R_1__0_
{0x0F12FFE8},	//awbb_GridCorr_R_1__1_
{0x0F12FFE8},	//awbb_GridCorr_R_1__2_
{0x0F12FFD8},	//awbb_GridCorr_R_1__3_
{0x0F12FFD8},	//awbb_GridCorr_R_1__4_
{0x0F12FFD0},	//awbb_GridCorr_R_1__5_

{0x0F120000},	//awbb_GridCorr_R_2__0_
{0x0F12FFE8},	//awbb_GridCorr_R_2__1_
{0x0F12FFE8},	//awbb_GridCorr_R_2__2_
{0x0F12FFD8},	//awbb_GridCorr_R_2__3_
{0x0F12FFD8},	//awbb_GridCorr_R_2__4_
{0x0F12FFD0},	//awbb_GridCorr_R_2__5_

{0x0F12FFEC},	//awbb_GridCorr_B_0__0_
{0x0F12000A},	//awbb_GridCorr_B_0__1_
{0x0F12000A},	//awbb_GridCorr_B_0__2_
{0x0F12FFC4},	//awbb_GridCorr_B_0__3_
{0x0F12FFC4},	//awbb_GridCorr_B_0__4_
{0x0F12FF66},	//awbb_GridCorr_B_0__5_

{0x0F12FFEC},	//awbb_GridCorr_B_1__0_
{0x0F12000A},	//awbb_GridCorr_B_1__1_
{0x0F12000A},	//awbb_GridCorr_B_1__2_
{0x0F12FFC4},	//awbb_GridCorr_B_1__3_
{0x0F12FFC4},	//awbb_GridCorr_B_1__4_
{0x0F12FF66},	//awbb_GridCorr_B_1__5_

{0x0F12FFEC},	//awbb_GridCorr_B_2__0_
{0x0F12000A},	//awbb_GridCorr_B_2__1_
{0x0F12000A},	//awbb_GridCorr_B_2__2_
{0x0F12FFC4},	//awbb_GridCorr_B_2__3_
{0x0F12FFC4},	//awbb_GridCorr_B_2__4_
{0x0F12FF66},	//awbb_GridCorr_B_2__5_

// Outdoor Grid Offset
{0x0F120000},	//awbb_GridCorr_R_Out_0__0_
{0x0F120000},	//awbb_GridCorr_R_Out_0__1_
{0x0F120000},	//awbb_GridCorr_R_Out_0__2_
{0x0F120000},	//awbb_GridCorr_R_Out_0__3_
{0x0F120000},	//awbb_GridCorr_R_Out_0__4_
{0x0F120000},	//awbb_GridCorr_R_Out_0__5_

{0x0F120000},	//awbb_GridCorr_R_Out_1__0_
{0x0F120000},	//awbb_GridCorr_R_Out_1__1_
{0x0F120000},	//awbb_GridCorr_R_Out_1__2_
{0x0F120000},	//awbb_GridCorr_R_Out_1__3_
{0x0F120000},	//awbb_GridCorr_R_Out_1__4_
{0x0F120000},	//awbb_GridCorr_R_Out_1__5_

{0x0F120000},	//awbb_GridCorr_R_Out_2__0_
{0x0F120000},	//awbb_GridCorr_R_Out_2__1_
{0x0F120000},	//awbb_GridCorr_R_Out_2__2_
{0x0F120000},	//awbb_GridCorr_R_Out_2__3_
{0x0F120000},	//awbb_GridCorr_R_Out_2__4_
{0x0F120000},	//awbb_GridCorr_R_Out_2__5_

{0x0F12FFA8},	//awbb_GridCorr_B_Out_0__0_
{0x0F12FFA8},	//awbb_GridCorr_B_Out_0__1_
{0x0F12FFA8},	//awbb_GridCorr_B_Out_0__2_
{0x0F120000},	//awbb_GridCorr_B_Out_0__3_
{0x0F120000},	//awbb_GridCorr_B_Out_0__4_
{0x0F120000},	//awbb_GridCorr_B_Out_0__5_

{0x0F12FFA8},	//awbb_GridCorr_B_Out_1__0_
{0x0F12FFA8},	//awbb_GridCorr_B_Out_1__1_
{0x0F12FFA8},	//awbb_GridCorr_B_Out_1__2_
{0x0F120000},	//awbb_GridCorr_B_Out_1__3_
{0x0F120000},	//awbb_GridCorr_B_Out_1__4_
{0x0F120000},	//awbb_GridCorr_B_Out_1__5_

{0x0F12FFA8},	//awbb_GridCorr_B_Out_2__0_
{0x0F12FFA8},	//awbb_GridCorr_B_Out_2__1_
{0x0F12FFA8},	//awbb_GridCorr_B_Out_2__2_
{0x0F120000},	//awbb_GridCorr_B_Out_2__3_
{0x0F120000},	//awbb_GridCorr_B_Out_2__4_
{0x0F120000},	//awbb_GridCorr_B_Out_2__5_
     
//==================================================================================
// 10.Clock Setting
//==================================================================================

//Input Clock (Mclk)	
{0x002A01F8},	
{0x0F125DC0},	//REG_TC_IPRM_InClockLSBs
{0x002A0212},	                                     
{0x0F120002},	//REG_TC_IPRM_UseNPviClocks          
{0x0F120000},	//REG_TC_IPRM_UseNMipiClocks         
{0x0F120000},	//REG_TC_IPRM_NumberOfMipiLanes
	
//System Clock & Output clock (Pclk)	
	
{0x002A021A},	
{0x0F123A98},	//REG_TC_IPRM_OpClk4KHz_0 
{0x0F124F1A}, 	//REG_TC_IPRM_MinOutRate4KHz_0
{0x0F124F1A}, 	//REG_TC_IPRM_MaxOutRate4KHz_0	
{0x0F124F1A},	//REG_TC_IPRM_OpClk4KHz_1 
{0x0F124F1A}, 	//REG_TC_IPRM_MinOutRate4KHz_1
{0x0F124F1A}, 	//REG_TC_IPRM_MaxOutRate4KHz_1	

//==================================================================================
// 11.Auto Flicker Detection
//==================================================================================

{0x002A0F30}, 	
{0x0F120001},   	//AFC_D_ConvAccelerPower 

// Auto Flicker (60Mhz start)	
{0x002A0F2A},	
{0x0F120000},	//AFC_Default BIT[0] 1:60Hz 0:50Hz
{0x002A04E6},	                                      
{0x0F12077F},	//REG_TC_DBG 7F: 60Hz  5F:50Hz

//==================================================================================
// 12.AE Setting
//==================================================================================

//AE Target	
{0x002A1484},	
{0x0F12003C},   	//TVAR_ae_BrAve

//ae_StatMode bit[3] BLC has to be bypassed to prevent AE weight change especially backlight scene 
{0x002A148A},	
{0x0F12000F},  	 //ae_StatMode

{0x002A0588},
{0x0F120002},	//lt_uInitPostToleranceCnt

//AE_state                	
{0x002A0544},	
{0x0F120111},  	 //lt_uLimitHigh
{0x0F1200EF},  	 //lt_uLimitLow

{0x002A058C},
{0x0F123520},
{0x0F120000},
{0x0F12C350},
{0x0F120000},
{0x0F123520},
{0x0F120000},
{0x0F12C350},
{0x0F120000},
{0x0F120470},
{0x0F120C00},
{0x0F120100},
{0x0F121000},

//AE Concept	
{0x002A0608},                                	
{0x0F120001}, 	//lt_ExpGain_uSubsamplingmode
{0x0F120001},	//lt_ExpGain_uNonSubsampling
	
//Exposure	
{0x002A0610},	//lt_ExpGain_ExpCurveGainMaxStr_0__ulExpIn_0
{0x0F120001},
{0x0F120000},	
{0x0F120A3C},	
{0x0F120000},	
{0x0F120D05},	
{0x0F120000},	
{0x0F124008},	
{0x0F120000},	
{0x0F127000},	
{0x0F120000},	
{0x0F129C00},	
{0x0F120000},	
{0x0F12AD00},	
{0x0F120001},	
{0x0F12F1D4},	
{0x0F120002},	
{0x0F12DC00},	
{0x0F120005},	
{0x0F12DC00},	
{0x0F120005},	
	
{0x002A0638},	//lt_ExpGain_ExpCurveGainMaxStr_0__ulExpOut_0_
{0x0F120001},	
{0x0F120000},	
{0x0F120A3C},	
{0x0F120000},	
{0x0F120D05},	
{0x0F120000},	
{0x0F123408},	
{0x0F120000},	
{0x0F123408},	
{0x0F120000},	
{0x0F126810},	
{0x0F120000},	
{0x0F128214},	
{0x0F120000},	
{0x0F12C350},	
{0x0F120000},	
{0x0F12C350},	
{0x0F120000},	
{0x0F12C350},	
{0x0F120000},	
	
//Gain	
{0x002A060C},	
{0x0F120800},	//lt_ExpGain_ExpCurveGainMaxStr
{0x0F120100},	//lt_ExpGain_ExpCurveGainMaxStr_0__uMaxDigGain
{0x002A05A2},		
{0x0F121000},	//lt_uMaxTotGain
	
// Lei Control	
{0x002A06B8},               	
{0x0F12452C},               	
{0x0F120005},  	 //lt_uMaxLei

//==================================================================================
// 13.AE Weight (Normal)
//==================================================================================
	
{0x002A1492},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120202},
{0x0F120202},
{0x0F120101},
{0x0F120201},
{0x0F120202},
{0x0F120202},
{0x0F120102},
{0x0F120201},
{0x0F120302},
{0x0F120203},
{0x0F120102},
{0x0F120201},
{0x0F120302},
{0x0F120203},
{0x0F120102},
{0x0F120101},
{0x0F120202},
{0x0F120202},
{0x0F120101},
{0x0F120101},
{0x0F120201},
{0x0F120102},
{0x0F120101},
{0x0F120100},
{0x0F120101},
{0x0F120101},
{0x0F120001},

//==================================================================================
// 14.Flash Setting
//==================================================================================

{0x002A0484},	
{0x0F120002},	//capture flash on                         
{0x002A183A},	                                           
{0x0F120001},	//one frame AE                             
{0x002A17F6},	                                           
{0x0F12023C},	//AWB R point                              
{0x0F120248},	//AWB B point                              
{0x002A1840},	                                           
{0x0F120001},	// Fls AE tune start                       
{0x0F120100},	// fls_afl_FlsAFIn  Rin                    
{0x0F120120},	                                           
{0x0F120180},	                                           
{0x0F120200},	                                           
{0x0F120400},	                                           
{0x0F120800},	                                           
{0x0F120A00},	                                           
{0x0F121000},	                                           
{0x0F120100},	// fls_afl_FlsAFOut  Rout                  
{0x0F1200A0},	                                           
{0x0F120090},	                                           
{0x0F120080},	                                           
{0x0F120070},	                                           
{0x0F120045},	                                           
{0x0F120030},	                                           
{0x0F120010},	                                           
{0x002A1884},	                                           
{0x0F120100},	// fls_afl_FlsNBOut  flash NB default      
{0x0F120100},	                                           
{0x0F120100},	                                           
{0x0F120100},	                                           
{0x0F120100},	                                           
{0x0F120100},	                                           
{0x0F120100},	                                           
{0x0F120100},	                                           
{0x002A1826},	                                           
{0x0F120100},	// fls_afl_FlashWP_Weight  flash NB default
{0x0F1200C0},	                                           
{0x0F120080},	                                           
{0x0F12000A},	                                           
{0x0F120000},	                                           
{0x0F120030},	// fls_afl_FlashWP_Weight  flash NB default
{0x0F120040},	
{0x0F120048},	
{0x0F120050},	
{0x0F120060},	
{0x002A4784},	
{0x0F1200A0},	// TNP_Regs_FlsWeightRIn  weight tune start in    
{0x0F1200C0},	     
{0x0F1200D0},	    
{0x0F120100},	      
{0x0F120200},	     
{0x0F120300},	     
{0x0F120088},	// TNP_Regs_FlsWeightROut  weight tune start out  
{0x0F1200B0},	      
{0x0F1200C0},	     
{0x0F120100},	    
{0x0F120200},	  
{0x0F120300},	 
{0x002A479C},	   
{0x0F120120},	//Fls  BRIn
{0x0F120150},	      
{0x0F120200},	     
{0x0F12003C},	// Fls  BROut
{0x0F12003B},	    
{0x0F120026},	//brightness

//==================================================================================
// 15.CCM Setting
//==================================================================================

{0x002A08A6},	
{0x0F1200C0},	//SARR_AwbCcmCord[0]
{0x0F120100},	//SARR_AwbCcmCord[1]
{0x0F120125},	//SARR_AwbCcmCord[2]
{0x0F12015F},	//SARR_AwbCcmCord[3]
{0x0F12017C},	//SARR_AwbCcmCord[4]
{0x0F120194},	//SARR_AwbCcmCord[5]
	
{0x002A0898},	
{0x0F124800},	//TVAR_wbt_pBaseCcms
{0x0F127000},	
{0x002A08A0},	
{0x0F1248D8},	//TVAR_wbt_pOutdoorCcm
{0x0F127000},	
	
//Horizon	
{0x002A4800},	
{0x0F120208},	//TVAR_wbt_pBaseCcms[0]  
{0x0F12FFB5},	//TVAR_wbt_pBaseCcms[1]  
{0x0F12FFE8},	//TVAR_wbt_pBaseCcms[2]  
{0x0F12FF20},	//TVAR_wbt_pBaseCcms[3]  
{0x0F1201BF},	//TVAR_wbt_pBaseCcms[4]  
{0x0F12FF53},	//TVAR_wbt_pBaseCcms[5]  
{0x0F120022},	//TVAR_wbt_pBaseCcms[6]  
{0x0F12FFEA},	//TVAR_wbt_pBaseCcms[7]  
{0x0F1201C2},	//TVAR_wbt_pBaseCcms[8]  
{0x0F1200C6},	//TVAR_wbt_pBaseCcms[9]  
{0x0F120095},	//TVAR_wbt_pBaseCcms[10] 
{0x0F12FEFD},	//TVAR_wbt_pBaseCcms[11] 
{0x0F120206},	//TVAR_wbt_pBaseCcms[12] 
{0x0F12FF7F},	//TVAR_wbt_pBaseCcms[13] 
{0x0F120191},	//TVAR_wbt_pBaseCcms[14] 
{0x0F12FF06},	//TVAR_wbt_pBaseCcms[15] 
{0x0F1201BA},	//TVAR_wbt_pBaseCcms[16] 
{0x0F120108},	//TVAR_wbt_pBaseCcms[17] 
	
// INCA A                               	
{0x0F120208},	//TVAR_wbt_pBaseCcms[18] 
{0x0F12FFB5},	//TVAR_wbt_pBaseCcms[19] 
{0x0F12FFE8},	//TVAR_wbt_pBaseCcms[20] 
{0x0F12FF20},	//TVAR_wbt_pBaseCcms[21] 
{0x0F1201BF},	//TVAR_wbt_pBaseCcms[22] 
{0x0F12FF53},	//TVAR_wbt_pBaseCcms[23] 
{0x0F120022},	//TVAR_wbt_pBaseCcms[24] 
{0x0F12FFEA},	//TVAR_wbt_pBaseCcms[25] 
{0x0F1201C2},	//TVAR_wbt_pBaseCcms[26] 
{0x0F1200C6},	//TVAR_wbt_pBaseCcms[27] 
{0x0F120095},	//TVAR_wbt_pBaseCcms[28] 
{0x0F12FEFD},	//TVAR_wbt_pBaseCcms[29] 
{0x0F120206},	//TVAR_wbt_pBaseCcms[30] 
{0x0F12FF7F},	//TVAR_wbt_pBaseCcms[31] 
{0x0F120191},	//TVAR_wbt_pBaseCcms[32] 
{0x0F12FF06},	//TVAR_wbt_pBaseCcms[33] 
{0x0F1201BA},	//TVAR_wbt_pBaseCcms[34] 
{0x0F120108},	//TVAR_wbt_pBaseCcms[35] 
	
//Warm White                    	
{0x0F120208},	//TVAR_wbt_pBaseCcms[36] 
{0x0F12FFB5},	//TVAR_wbt_pBaseCcms[37] 
{0x0F12FFE8},	//TVAR_wbt_pBaseCcms[38] 
{0x0F12FF20},	//TVAR_wbt_pBaseCcms[39] 
{0x0F1201BF},	//TVAR_wbt_pBaseCcms[40] 
{0x0F12FF53},	//TVAR_wbt_pBaseCcms[41] 
{0x0F120022},	//TVAR_wbt_pBaseCcms[42] 
{0x0F12FFEA},	//TVAR_wbt_pBaseCcms[43] 
{0x0F1201C2},	//TVAR_wbt_pBaseCcms[44] 
{0x0F1200C6},	//TVAR_wbt_pBaseCcms[45] 
{0x0F120095},	//TVAR_wbt_pBaseCcms[46] 
{0x0F12FEFD},	//TVAR_wbt_pBaseCcms[47] 
{0x0F120206},	//TVAR_wbt_pBaseCcms[48] 
{0x0F12FF7F},	//TVAR_wbt_pBaseCcms[49] 
{0x0F120191},	//TVAR_wbt_pBaseCcms[50] 
{0x0F12FF06},	//TVAR_wbt_pBaseCcms[51] 
{0x0F1201BA},	//TVAR_wbt_pBaseCcms[52] 
{0x0F120108},	//TVAR_wbt_pBaseCcms[53] 
         	
//Cool White	
{0x0F120204},	//TVAR_wbt_pBaseCcms[54] 
{0x0F12FFB2},	//TVAR_wbt_pBaseCcms[55] 
{0x0F12FFF5},	//TVAR_wbt_pBaseCcms[56] 
{0x0F12FEF1},	//TVAR_wbt_pBaseCcms[57] 
{0x0F12014E},	//TVAR_wbt_pBaseCcms[58] 
{0x0F12FF18},	//TVAR_wbt_pBaseCcms[59] 
{0x0F12FFE6},	//TVAR_wbt_pBaseCcms[60] 
{0x0F12FFDD},	//TVAR_wbt_pBaseCcms[61] 
{0x0F1201B2},	//TVAR_wbt_pBaseCcms[62] 
{0x0F1200F2},	//TVAR_wbt_pBaseCcms[63] 
{0x0F1200CA},	//TVAR_wbt_pBaseCcms[64] 
{0x0F12FF48},	//TVAR_wbt_pBaseCcms[65] 
{0x0F120151},	//TVAR_wbt_pBaseCcms[66] 
{0x0F12FF50},	//TVAR_wbt_pBaseCcms[67] 
{0x0F120147},	//TVAR_wbt_pBaseCcms[68] 
{0x0F12FF75},	//TVAR_wbt_pBaseCcms[69] 
{0x0F120187},	//TVAR_wbt_pBaseCcms[70] 
{0x0F1201BF},	//TVAR_wbt_pBaseCcms[71] 
         	
//D50	
{0x0F120204},	//TVAR_wbt_pBaseCcms[72]  
{0x0F12FFB2},	//TVAR_wbt_pBaseCcms[73] 
{0x0F12FFF5},	//TVAR_wbt_pBaseCcms[74] 
{0x0F12FEF1},	//TVAR_wbt_pBaseCcms[75] 
{0x0F12014E},	//TVAR_wbt_pBaseCcms[76] 
{0x0F12FF18},	//TVAR_wbt_pBaseCcms[77] 
{0x0F12FFE6},	//TVAR_wbt_pBaseCcms[78] 
{0x0F12FFDD},	//TVAR_wbt_pBaseCcms[79] 
{0x0F1201B2},	//TVAR_wbt_pBaseCcms[80] 
{0x0F1200F2},	//TVAR_wbt_pBaseCcms[81] 
{0x0F1200CA},	//TVAR_wbt_pBaseCcms[82] 
{0x0F12FF48},	//TVAR_wbt_pBaseCcms[83] 
{0x0F120151},	//TVAR_wbt_pBaseCcms[84] 
{0x0F12FF50},	//TVAR_wbt_pBaseCcms[85] 
{0x0F120147},	//TVAR_wbt_pBaseCcms[86] 
{0x0F12FF75},	//TVAR_wbt_pBaseCcms[87] 
{0x0F120187},	//TVAR_wbt_pBaseCcms[88] 
{0x0F1201BF},	//TVAR_wbt_pBaseCcms[89] 
         	
//D65                        	
{0x0F120204},	//TVAR_wbt_pBaseCcms[90]  
{0x0F12FFB2},	//TVAR_wbt_pBaseCcms[91] 
{0x0F12FFF5},	//TVAR_wbt_pBaseCcms[92] 
{0x0F12FEF1},	//TVAR_wbt_pBaseCcms[93] 
{0x0F12014E},	//TVAR_wbt_pBaseCcms[94] 
{0x0F12FF18},	//TVAR_wbt_pBaseCcms[95] 
{0x0F12FFE6},	//TVAR_wbt_pBaseCcms[96] 
{0x0F12FFDD},	//TVAR_wbt_pBaseCcms[97] 
{0x0F1201B2},	//TVAR_wbt_pBaseCcms[98] 
{0x0F1200F2},	//TVAR_wbt_pBaseCcms[99] 
{0x0F1200CA},	//TVAR_wbt_pBaseCcms[100]
{0x0F12FF48},	//TVAR_wbt_pBaseCcms[101]
{0x0F120151},	//TVAR_wbt_pBaseCcms[102]
{0x0F12FF50},	//TVAR_wbt_pBaseCcms[103]
{0x0F120147},	//TVAR_wbt_pBaseCcms[104]
{0x0F12FF75},	//TVAR_wbt_pBaseCcms[105]
{0x0F120187},	//TVAR_wbt_pBaseCcms[106]
{0x0F1201BF},	//TVAR_wbt_pBaseCcms[107]
	
//Outdoor	
{0x002A48D8},	
{0x0F1201E5},	//TVAR_wbt_pOutdoorCcm[0] 
{0x0F12FFA4},	//TVAR_wbt_pOutdoorCcm[1] 
{0x0F12FFDC},	//TVAR_wbt_pOutdoorCcm[2] 
{0x0F12FE90},	//TVAR_wbt_pOutdoorCcm[3] 
{0x0F12013F},	//TVAR_wbt_pOutdoorCcm[4] 
{0x0F12FF1B},	//TVAR_wbt_pOutdoorCcm[5] 
{0x0F12FFD2},	//TVAR_wbt_pOutdoorCcm[6] 
{0x0F12FFDF},	//TVAR_wbt_pOutdoorCcm[7] 
{0x0F120236},	//TVAR_wbt_pOutdoorCcm[8] 
{0x0F1200EC},	//TVAR_wbt_pOutdoorCcm[9] 
{0x0F1200F8},	//TVAR_wbt_pOutdoorCcm[10]
{0x0F12FF34},	//TVAR_wbt_pOutdoorCcm[11]
{0x0F1201CE},	//TVAR_wbt_pOutdoorCcm[12]
{0x0F12FF83},	//TVAR_wbt_pOutdoorCcm[13]
{0x0F120195},	//TVAR_wbt_pOutdoorCcm[14]
{0x0F12FEF3},	//TVAR_wbt_pOutdoorCcm[15]
{0x0F120126},	//TVAR_wbt_pOutdoorCcm[16]
{0x0F120162},	//TVAR_wbt_pOutdoorCcm[17]


//==================================================================================
// 16.GAMMA
//==================================================================================

{0x002A0734},	
{0x0F120000},	//saRR_usDualGammaLutRGBIndoor[0][0] 
{0x0F12000A},	//saRR_usDualGammaLutRGBIndoor[0][1] 
{0x0F120016},	//saRR_usDualGammaLutRGBIndoor[0][2] 
{0x0F120030},	//saRR_usDualGammaLutRGBIndoor[0][3] 
{0x0F120066},	//saRR_usDualGammaLutRGBIndoor[0][4] 
{0x0F1200D5},	//saRR_usDualGammaLutRGBIndoor[0][5] 
{0x0F120138},	//saRR_usDualGammaLutRGBIndoor[0][6] 
{0x0F120163},	//saRR_usDualGammaLutRGBIndoor[0][7] 
{0x0F120189},	//saRR_usDualGammaLutRGBIndoor[0][8] 
{0x0F1201C6},	//saRR_usDualGammaLutRGBIndoor[0][9] 
{0x0F1201F8},	//saRR_usDualGammaLutRGBIndoor[0][10]
{0x0F120222},	//saRR_usDualGammaLutRGBIndoor[0][11]
{0x0F120247},	//saRR_usDualGammaLutRGBIndoor[0][12]
{0x0F120282},	//saRR_usDualGammaLutRGBIndoor[0][13]
{0x0F1202B5},	//saRR_usDualGammaLutRGBIndoor[0][14]
{0x0F12030F},	//saRR_usDualGammaLutRGBIndoor[0][15]
{0x0F12035F},	//saRR_usDualGammaLutRGBIndoor[0][16]
{0x0F1203A2},	//saRR_usDualGammaLutRGBIndoor[0][17]
{0x0F1203D8},	//saRR_usDualGammaLutRGBIndoor[0][18]
{0x0F1203FF},	//saRR_usDualGammaLutRGBIndoor[0][19]
	
{0x0F120000},	//saRR_usDualGammaLutRGBIndoor[1][0] 
{0x0F12000A},	//saRR_usDualGammaLutRGBIndoor[1][1] 
{0x0F120016},	//saRR_usDualGammaLutRGBIndoor[1][2] 
{0x0F120030},	//saRR_usDualGammaLutRGBIndoor[1][3] 
{0x0F120066},	//saRR_usDualGammaLutRGBIndoor[1][4] 
{0x0F1200D5},	//saRR_usDualGammaLutRGBIndoor[1][5] 
{0x0F120138},	//saRR_usDualGammaLutRGBIndoor[1][6] 
{0x0F120163},	//saRR_usDualGammaLutRGBIndoor[1][7] 
{0x0F120189},	//saRR_usDualGammaLutRGBIndoor[1][8] 
{0x0F1201C6},	//saRR_usDualGammaLutRGBIndoor[1][9] 
{0x0F1201F8},	//saRR_usDualGammaLutRGBIndoor[1][10]
{0x0F120222},	//saRR_usDualGammaLutRGBIndoor[1][11]
{0x0F120247},	//saRR_usDualGammaLutRGBIndoor[1][12]
{0x0F120282},	//saRR_usDualGammaLutRGBIndoor[1][13]
{0x0F1202B5},	//saRR_usDualGammaLutRGBIndoor[1][14]
{0x0F12030F},	//saRR_usDualGammaLutRGBIndoor[1][15]
{0x0F12035F},	//saRR_usDualGammaLutRGBIndoor[1][16]
{0x0F1203A2},	//saRR_usDualGammaLutRGBIndoor[1][17]
{0x0F1203D8},	//saRR_usDualGammaLutRGBIndoor[1][18]
{0x0F1203FF},	//saRR_usDualGammaLutRGBIndoor[1][19]
	
{0x0F120000},	//saRR_usDualGammaLutRGBIndoor[2][0] 
{0x0F12000A},	//saRR_usDualGammaLutRGBIndoor[2][1] 
{0x0F120016},	//saRR_usDualGammaLutRGBIndoor[2][2] 
{0x0F120030},	//saRR_usDualGammaLutRGBIndoor[2][3] 
{0x0F120066},	//saRR_usDualGammaLutRGBIndoor[2][4] 
{0x0F1200D5},	//saRR_usDualGammaLutRGBIndoor[2][5] 
{0x0F120138},	//saRR_usDualGammaLutRGBIndoor[2][6] 
{0x0F120163},	//saRR_usDualGammaLutRGBIndoor[2][7] 
{0x0F120189},	//saRR_usDualGammaLutRGBIndoor[2][8] 
{0x0F1201C6},	//saRR_usDualGammaLutRGBIndoor[2][9] 
{0x0F1201F8},	//saRR_usDualGammaLutRGBIndoor[2][10]
{0x0F120222},	//saRR_usDualGammaLutRGBIndoor[2][11]
{0x0F120247},	//saRR_usDualGammaLutRGBIndoor[2][12]
{0x0F120282},	//saRR_usDualGammaLutRGBIndoor[2][13]
{0x0F1202B5},	//saRR_usDualGammaLutRGBIndoor[2][14]
{0x0F12030F},	//saRR_usDualGammaLutRGBIndoor[2][15]
{0x0F12035F},	//saRR_usDualGammaLutRGBIndoor[2][16]
{0x0F1203A2},	//saRR_usDualGammaLutRGBIndoor[2][17]
{0x0F1203D8},	//saRR_usDualGammaLutRGBIndoor[2][18]
{0x0F1203FF},	//saRR_usDualGammaLutRGBIndoor[2][19]
	//RGB Outdoor Gamma
{0x0F120000},	//saRR_usDualGammaLutRGBOutdoor[0][0] 
{0x0F120017},	//saRR_usDualGammaLutRGBOutdoor[0][1] 
{0x0F120028},	//saRR_usDualGammaLutRGBOutdoor[0][2] 
{0x0F120047},	//saRR_usDualGammaLutRGBOutdoor[0][3] 
{0x0F120080},	//saRR_usDualGammaLutRGBOutdoor[0][4] 
{0x0F1200E0},	//saRR_usDualGammaLutRGBOutdoor[0][5] 
{0x0F120134},	//saRR_usDualGammaLutRGBOutdoor[0][6] 
{0x0F120159},	//saRR_usDualGammaLutRGBOutdoor[0][7] 
{0x0F12017B},	//saRR_usDualGammaLutRGBOutdoor[0][8] 
{0x0F1201B4},	//saRR_usDualGammaLutRGBOutdoor[0][9] 
{0x0F1201E5},	//saRR_usDualGammaLutRGBOutdoor[0][10]
{0x0F12020F},	//saRR_usDualGammaLutRGBOutdoor[0][11]
{0x0F120235},	//saRR_usDualGammaLutRGBOutdoor[0][12]
{0x0F120279},	//saRR_usDualGammaLutRGBOutdoor[0][13]
{0x0F1202B6},	//saRR_usDualGammaLutRGBOutdoor[0][14]
{0x0F120312},	//saRR_usDualGammaLutRGBOutdoor[0][15]
{0x0F120358},	//saRR_usDualGammaLutRGBOutdoor[0][16]
{0x0F120393},	//saRR_usDualGammaLutRGBOutdoor[0][17]
{0x0F1203C8},	//saRR_usDualGammaLutRGBOutdoor[0][18]
{0x0F1203FA},	//saRR_usDualGammaLutRGBOutdoor[0][19]
	
{0x0F120000},	//saRR_usDualGammaLutRGBOutdoor[1][0] 
{0x0F120017},	//saRR_usDualGammaLutRGBOutdoor[1][1] 
{0x0F120028},	//saRR_usDualGammaLutRGBOutdoor[1][2] 
{0x0F120047},	//saRR_usDualGammaLutRGBOutdoor[1][3] 
{0x0F120080},	//saRR_usDualGammaLutRGBOutdoor[1][4] 
{0x0F1200E0},	//saRR_usDualGammaLutRGBOutdoor[1][5] 
{0x0F120134},	//saRR_usDualGammaLutRGBOutdoor[1][6] 
{0x0F120159},	//saRR_usDualGammaLutRGBOutdoor[1][7] 
{0x0F12017B},	//saRR_usDualGammaLutRGBOutdoor[1][8] 
{0x0F1201B4},	//saRR_usDualGammaLutRGBOutdoor[1][9] 
{0x0F1201E5},	//saRR_usDualGammaLutRGBOutdoor[1][10]
{0x0F12020F},	//saRR_usDualGammaLutRGBOutdoor[1][11]
{0x0F120235},	//saRR_usDualGammaLutRGBOutdoor[1][12]
{0x0F120279},	//saRR_usDualGammaLutRGBOutdoor[1][13]
{0x0F1202B6},	//saRR_usDualGammaLutRGBOutdoor[1][14]
{0x0F120312},	//saRR_usDualGammaLutRGBOutdoor[1][15]
{0x0F120358},	//saRR_usDualGammaLutRGBOutdoor[1][16]
{0x0F120393},	//saRR_usDualGammaLutRGBOutdoor[1][17]
{0x0F1203C8},	//saRR_usDualGammaLutRGBOutdoor[1][18]
{0x0F1203FA},	//saRR_usDualGammaLutRGBOutdoor[1][19]
	
{0x0F120000},	//saRR_usDualGammaLutRGBOutdoor[2][0] 
{0x0F120017},	//saRR_usDualGammaLutRGBOutdoor[2][1] 
{0x0F120028},	//saRR_usDualGammaLutRGBOutdoor[2][2] 
{0x0F120047},	//saRR_usDualGammaLutRGBOutdoor[2][3] 
{0x0F120080},	//saRR_usDualGammaLutRGBOutdoor[2][4] 
{0x0F1200E0},	//saRR_usDualGammaLutRGBOutdoor[2][5] 
{0x0F120134},	//saRR_usDualGammaLutRGBOutdoor[2][6] 
{0x0F120159},	//saRR_usDualGammaLutRGBOutdoor[2][7] 
{0x0F12017B},	//saRR_usDualGammaLutRGBOutdoor[2][8] 
{0x0F1201B4},	//saRR_usDualGammaLutRGBOutdoor[2][9] 
{0x0F1201E5},	//saRR_usDualGammaLutRGBOutdoor[2][10]
{0x0F12020F},	//saRR_usDualGammaLutRGBOutdoor[2][11]
{0x0F120235},	//saRR_usDualGammaLutRGBOutdoor[2][12]
{0x0F120279},	//saRR_usDualGammaLutRGBOutdoor[2][13]
{0x0F1202B6},	//saRR_usDualGammaLutRGBOutdoor[2][14]
{0x0F120312},	//saRR_usDualGammaLutRGBOutdoor[2][15]
{0x0F120358},	//saRR_usDualGammaLutRGBOutdoor[2][16]
{0x0F120393},	//saRR_usDualGammaLutRGBOutdoor[2][17]
{0x0F1203C8},	//saRR_usDualGammaLutRGBOutdoor[2][18]
{0x0F1203FA},	//saRR_usDualGammaLutRGBOutdoor[2][19]


//==================================================================================
// 17.AFIT
//==================================================================================
{0x002A0944},	
{0x0F12004B},	//afit_uNoiseIndInDoor
{0x0F120092},	//afit_uNoiseIndInDoor
{0x0F120196},	//afit_uNoiseIndInDoor
{0x0F120217},	//afit_uNoiseIndInDoor
{0x0F1202B0},	//afit_uNoiseIndInDoor
	
{0x002A0938},	
{0x0F120000},	// on/off AFIT by NB option
{0x0F120014},	//SARR_uNormBrInDoor
{0x0F1200D2},	//SARR_uNormBrInDoor
{0x0F120384},	//SARR_uNormBrInDoor
{0x0F1207D0},	//SARR_uNormBrInDoor
{0x0F121388},	//SARR_uNormBrInDoor
	
{0x002A0976},	
{0x0F120070},	//afit_usGamutTh       
{0x0F120005},	//afit_usNeargrayOffset
{0x0F120000},	//afit_bUseSenBpr         
{0x0F1201CC},	//afit_usBprThr_0_        
{0x0F1201CC},	//afit_usBprThr_1_        
{0x0F1201CC},	//afit_usBprThr_2_        
{0x0F1201CC},	//afit_usBprThr_3_        
{0x0F1201CC},	//afit_usBprThr_4_        
{0x0F120180},	//afit_NIContrastAFITValue
{0x0F120196},	//afit_NIContrastTh       
	//AFIT 0
{0x002A098C},	
{0x0F120000},	//7000098C//AFIT16_BRIGHTNESS           
{0x0F120000},	//7000098E//AFIT16_CONTRAST                                                        
{0x0F120000},	//70000990//AFIT16_SATURATION                                                      
{0x0F120000},	//70000992//AFIT16_SHARP_BLUR                                                      
{0x0F120000},	//70000994//AFIT16_GLAMOUR                                                         
{0x0F1200C0},	//70000996//AFIT16_bnr_edge_high                                                   
{0x0F120064},	//70000998//AFIT16_postdmsc_iLowBright                                             
{0x0F120384},	//7000099A//AFIT16_postdmsc_iHighBright                                            
{0x0F12005F},	//7000099C//AFIT16_postdmsc_iLowSat                                                
{0x0F1201F4},	//7000099E//AFIT16_postdmsc_iHighSat                                               
{0x0F120070},	//700009A0//AFIT16_postdmsc_iTune                                                  
{0x0F120040},	//700009A2//AFIT16_yuvemix_mNegRanges_0                                            
{0x0F1200A0},	//700009A4//AFIT16_yuvemix_mNegRanges_1                                            
{0x0F120100},	//700009A6//AFIT16_yuvemix_mNegRanges_2                                            
{0x0F120010},	//700009A8//AFIT16_yuvemix_mPosRanges_0                                            
{0x0F120040},	//700009AA//AFIT16_yuvemix_mPosRanges_1                                            
{0x0F1200A0},	//700009AC//AFIT16_yuvemix_mPosRanges_2                                            
{0x0F121430},	//700009AE//AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                        
{0x0F120201},	//700009B0//AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                   
{0x0F120204},	//700009B2//AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh              
{0x0F123604},	//700009B4//AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                  
{0x0F12032A},	//700009B6//AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                 
{0x0F120403},	//700009B8//AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin              
{0x0F121B06},	//700009BA//AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                
{0x0F126015},	//700009BC//AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH           
{0x0F1200C0},	//700009BE//AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune            
{0x0F126080},	//700009C0//AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh          
{0x0F124080},	//700009C2//AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh    
{0x0F120640},	//700009C4//AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed     
{0x0F120306},	//700009C6//AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh       
{0x0F122003},	//700009C8//AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH              
{0x0F12FF01},	//700009CA//AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit         
{0x0F120000},	//700009CC//AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2              
{0x0F120400},	//700009CE//AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                   
{0x0F12365A},	//700009D0//AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                    
{0x0F12102A},	//700009D2//AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                     
{0x0F12000B},	//700009D4//AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                        
{0x0F120600},	//700009D6//AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                        
{0x0F125A0F},	//700009D8//AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                   
{0x0F120505},	//700009DA//AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                
{0x0F121802},	//700009DC//AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                        
{0x0F120000},	//700009DE//AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                  
{0x0F122006},	//700009E0//AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                  
{0x0F123028},	//700009E2//AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                   
{0x0F120418},	//700009E4//AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                         
{0x0F120101},	//700009E6//AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                   
{0x0F120800},	//700009E8//AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                  
{0x0F121804},	//700009EA//AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh               
{0x0F124008},	//700009EC//AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                
{0x0F120540},	//700009EE//AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                
{0x0F128006},	//700009F0//AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                
{0x0F120020},	//700009F2//AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                 
{0x0F120000},	//700009F4//AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh          
{0x0F121800},	//700009F6//AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat              
{0x0F120000},	//700009F8//AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit           
{0x0F121E10},	//700009FA//AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                  
{0x0F12000B},	//700009FC//AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0            
{0x0F120607},	//700009FE//AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2          
{0x0F120005},	//70000A00//AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0          
{0x0F120607},	//70000A02//AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2          
{0x0F120405},	//70000A04//AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY           
{0x0F120205},	//70000A06//AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm            
{0x0F120304},	//70000A08//AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm            
{0x0F120409},	//70000A0A//AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift          
{0x0F120306},	//70000A0C//AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y       
{0x0F120407},	//70000A0E//AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y    
{0x0F121C04},	//70000A10//AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV   
{0x0F120214},	//70000A12//AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y    
{0x0F121002},	//70000A14//AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV     
{0x0F120610},	//70000A16//AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL     
{0x0F121A02},	//70000A18//AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL     
{0x0F124A18},	//70000A1A//AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower     
{0x0F120080},	//70000A1C//AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce         
{0x0F120348},	//70000A1E//AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset             
{0x0F120180},	//70000A20//AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                 
{0x0F120A0A},	//70000A22//AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                  
{0x0F120101},	//70000A24//AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C              
{0x0F122028},	//70000A26//AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh               
{0x0F126024},	//70000A28//AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower               
{0x0F122A36},	//70000A2A//AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                 
{0x0F12FFFF},	//70000A2C//AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp               
{0x0F120808},	//70000A2E//AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope          
{0x0F120A01},	//70000A30//AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin         
{0x0F12010A},	//70000A32//AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin        
{0x0F123601},	//70000A34//AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin       
{0x0F12242A},	//70000A36//AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin       
{0x0F123660},	//70000A38//AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin        
{0x0F12FF2A},	//70000A3A//AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin        
{0x0F1208FF},	//70000A3C//AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin   
{0x0F120008},	//70000A3E//AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                    
{0x0F120001},	//70000A40//AFITB_bnr_nClustLevel_C      [0]  
	//AFIT 1                                     	
{0x0F120000},	//70000A42//AFIT16_BRIGHTNESS           
{0x0F120000},	//70000A44//AFIT16_CONTRAST                                                        
{0x0F120000},	//70000A46//AFIT16_SATURATION                                                      
{0x0F120000},	//70000A48//AFIT16_SHARP_BLUR                                                      
{0x0F120000},	//70000A4A//AFIT16_GLAMOUR                                                         
{0x0F1200C0},	//70000A4C//AFIT16_bnr_edge_high                                                   
{0x0F120064},	//70000A4E//AFIT16_postdmsc_iLowBright                                             
{0x0F120384},	//70000A50//AFIT16_postdmsc_iHighBright                                            
{0x0F120051},	//70000A52//AFIT16_postdmsc_iLowSat                                                
{0x0F1201F4},	//70000A54//AFIT16_postdmsc_iHighSat                                               
{0x0F120070},	//70000A56//AFIT16_postdmsc_iTune                                                  
{0x0F120040},	//70000A58//AFIT16_yuvemix_mNegRanges_0                                            
{0x0F1200A0},	//70000A5A//AFIT16_yuvemix_mNegRanges_1                                            
{0x0F120100},	//70000A5C//AFIT16_yuvemix_mNegRanges_2                                            
{0x0F120010},	//70000A5E//AFIT16_yuvemix_mPosRanges_0                                            
{0x0F120060},	//70000A60//AFIT16_yuvemix_mPosRanges_1                                            
{0x0F120100},	//70000A62//AFIT16_yuvemix_mPosRanges_2                                            
{0x0F121430},	//70000A64//AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                        
{0x0F120201},	//70000A66//AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                   
{0x0F120204},	//70000A68//AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh              
{0x0F122404},	//70000A6A//AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                  
{0x0F12031B},	//70000A6C//AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                 
{0x0F120103},	//70000A6E//AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin              
{0x0F121205},	//70000A70//AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                
{0x0F12400D},	//70000A72//AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH           
{0x0F120080},	//70000A74//AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune            
{0x0F122080},	//70000A76//AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh          
{0x0F123040},	//70000A78//AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh    
{0x0F120630},	//70000A7A//AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed     
{0x0F120306},	//70000A7C//AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh       
{0x0F122003},	//70000A7E//AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH              
{0x0F12FF01},	//70000A80//AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit         
{0x0F120404},	//70000A82//AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2              
{0x0F120300},	//70000A84//AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                   
{0x0F12245A},	//70000A86//AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                    
{0x0F121018},	//70000A88//AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                     
{0x0F12000B},	//70000A8A//AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                        
{0x0F120B00},	//70000A8C//AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                        
{0x0F125A0F},	//70000A8E//AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                   
{0x0F120505},	//70000A90//AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                
{0x0F121802},	//70000A92//AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                        
{0x0F120000},	//70000A94//AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                  
{0x0F122006},	//70000A96//AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                  
{0x0F123428},	//70000A98//AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                   
{0x0F12041C},	//70000A9A//AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                         
{0x0F120101},	//70000A9C//AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                   
{0x0F120800},	//70000A9E//AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                  
{0x0F121004},	//70000AA0//AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh               
{0x0F124008},	//70000AA2//AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                
{0x0F120540},	//70000AA4//AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                
{0x0F128006},	//70000AA6//AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                
{0x0F120020},	//70000AA8//AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                 
{0x0F120000},	//70000AAA//AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh          
{0x0F121800},	//70000AAC//AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat              
{0x0F120000},	//70000AAE//AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit           
{0x0F121E10},	//70000AB0//AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                  
{0x0F12000B},	//70000AB2//AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0            
{0x0F120607},	//70000AB4//AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2          
{0x0F120005},	//70000AB6//AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0          
{0x0F120607},	//70000AB8//AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2          
{0x0F120405},	//70000ABA//AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY           
{0x0F120205},	//70000ABC//AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm            
{0x0F120304},	//70000ABE//AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm            
{0x0F120409},	//70000AC0//AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift          
{0x0F120306},	//70000AC2//AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y       
{0x0F120407},	//70000AC4//AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y    
{0x0F121F04},	//70000AC6//AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV   
{0x0F120218},	//70000AC8//AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y    
{0x0F121102},	//70000ACA//AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV     
{0x0F120611},	//70000ACC//AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL     
{0x0F121A02},	//70000ACE//AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL     
{0x0F128018},	//70000AD0//AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower     
{0x0F120080},	//70000AD2//AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce         
{0x0F120380},	//70000AD4//AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset             
{0x0F120180},	//70000AD6//AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                 
{0x0F120A0A},	//70000AD8//AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                  
{0x0F120101},	//70000ADA//AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C              
{0x0F121B24},	//70000ADC//AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh               
{0x0F126024},	//70000ADE//AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower               
{0x0F121D22},	//70000AE0//AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                 
{0x0F12FFFF},	//70000AE2//AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp               
{0x0F120808},	//70000AE4//AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope          
{0x0F120A01},	//70000AE6//AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin         
{0x0F12010A},	//70000AE8//AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin        
{0x0F122401},	//70000AEA//AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin       
{0x0F12241B},	//70000AEC//AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin       
{0x0F121E60},	//70000AEE//AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin        
{0x0F12FF18},	//70000AF0//AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin        
{0x0F1208FF},	//70000AF2//AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin   
{0x0F120008},	//70000AF4//AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                    
{0x0F120001},	//70000AF6//AFITB_bnr_nClustLevel_C      [0]  
	//AFIT 2                             	
{0x0F120000},	//70000AF8//AFIT16_BRIGHTNESS           
{0x0F120000},	//70000AFA//AFIT16_CONTRAST                                                        
{0x0F120000},	//70000AFC//AFIT16_SATURATION                                                      
{0x0F120000},	//70000AFE//AFIT16_SHARP_BLUR                                                      
{0x0F120000},	//70000B00//AFIT16_GLAMOUR                                                         
{0x0F1200C0},	//70000B02//AFIT16_bnr_edge_high                                                   
{0x0F120064},	//70000B04//AFIT16_postdmsc_iLowBright                                             
{0x0F120384},	//70000B06//AFIT16_postdmsc_iHighBright                                            
{0x0F120043},	//70000B08//AFIT16_postdmsc_iLowSat                                                
{0x0F1201F4},	//70000B0A//AFIT16_postdmsc_iHighSat                                               
{0x0F120070},	//70000B0C//AFIT16_postdmsc_iTune                                                  
{0x0F120040},	//70000B0E//AFIT16_yuvemix_mNegRanges_0                                            
{0x0F1200A0},	//70000B10//AFIT16_yuvemix_mNegRanges_1                                            
{0x0F120100},	//70000B12//AFIT16_yuvemix_mNegRanges_2                                            
{0x0F120010},	//70000B14//AFIT16_yuvemix_mPosRanges_0                                            
{0x0F120060},	//70000B16//AFIT16_yuvemix_mPosRanges_1                                            
{0x0F120100},	//70000B18//AFIT16_yuvemix_mPosRanges_2                                            
{0x0F121430},	//70000B1A//AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                        
{0x0F120201},	//70000B1C//AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                   
{0x0F120204},	//70000B1E//AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh              
{0x0F121B04},	//70000B20//AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                  
{0x0F120312},	//70000B22//AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                 
{0x0F120003},	//70000B24//AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin              
{0x0F120C03},	//70000B26//AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                
{0x0F122806},	//70000B28//AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH           
{0x0F120060},	//70000B2A//AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune            
{0x0F121580},	//70000B2C//AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh          
{0x0F122020},	//70000B2E//AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh    
{0x0F120620},	//70000B30//AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed     
{0x0F120306},	//70000B32//AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh       
{0x0F122003},	//70000B34//AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH              
{0x0F12FF01},	//70000B36//AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit         
{0x0F120404},	//70000B38//AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2              
{0x0F120300},	//70000B3A//AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                   
{0x0F12145A},	//70000B3C//AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                    
{0x0F121010},	//70000B3E//AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                     
{0x0F12000B},	//70000B40//AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                        
{0x0F120E00},	//70000B42//AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                        
{0x0F125A0F},	//70000B44//AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                   
{0x0F120504},	//70000B46//AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                
{0x0F121802},	//70000B48//AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                        
{0x0F120000},	//70000B4A//AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                  
{0x0F122006},	//70000B4C//AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                  
{0x0F123828},	//70000B4E//AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                   
{0x0F120428},	//70000B50//AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                         
{0x0F120101},	//70000B52//AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                   
{0x0F128000},	//70000B54//AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                  
{0x0F120A04},	//70000B56//AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh               
{0x0F124008},	//70000B58//AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                
{0x0F120540},	//70000B5A//AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                
{0x0F128006},	//70000B5C//AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                
{0x0F120020},	//70000B5E//AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                 
{0x0F120000},	//70000B60//AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh          
{0x0F121800},	//70000B62//AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat              
{0x0F120000},	//70000B64//AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit           
{0x0F121E10},	//70000B66//AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                  
{0x0F12000B},	//70000B68//AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0            
{0x0F120607},	//70000B6A//AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2          
{0x0F120005},	//70000B6C//AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0          
{0x0F120607},	//70000B6E//AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2          
{0x0F120405},	//70000B70//AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY           
{0x0F120207},	//70000B72//AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm            
{0x0F120304},	//70000B74//AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm            
{0x0F120409},	//70000B76//AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift          
{0x0F120306},	//70000B78//AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y       
{0x0F120407},	//70000B7A//AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y    
{0x0F122404},	//70000B7C//AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV   
{0x0F120221},	//70000B7E//AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y    
{0x0F121202},	//70000B80//AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV     
{0x0F120613},	//70000B82//AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL     
{0x0F121A02},	//70000B84//AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL     
{0x0F128018},	//70000B86//AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower     
{0x0F120080},	//70000B88//AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce         
{0x0F120080},	//70000B8A//AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset             
{0x0F120180},	//70000B8C//AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                 
{0x0F120A0A},	//70000B8E//AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                  
{0x0F120101},	//70000B90//AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C              
{0x0F12141D},	//70000B92//AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh               
{0x0F126024},	//70000B94//AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower               
{0x0F120C0C},	//70000B96//AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                 
{0x0F12FFFF},	//70000B98//AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp               
{0x0F120808},	//70000B9A//AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope          
{0x0F120A01},	//70000B9C//AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin         
{0x0F12010A},	//70000B9E//AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin        
{0x0F121B01},	//70000BA0//AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin       
{0x0F122412},	//70000BA2//AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin       
{0x0F120C60},	//70000BA4//AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin        
{0x0F12FF0C},	//70000BA6//AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin        
{0x0F1208FF},	//70000BA8//AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin   
{0x0F120008},	//70000BAA//AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                    
{0x0F120001},	//70000BAC//AFITB_bnr_nClustLevel_C      [0]   
	//AFIT 3                                  	
{0x0F120000},	//70000BAE//AFIT16_BRIGHTNESS           
{0x0F120000},	//70000BB0//AFIT16_CONTRAST                                                        
{0x0F120000},	//70000BB2//AFIT16_SATURATION                                                      
{0x0F120000},	//70000BB4//AFIT16_SHARP_BLUR                                                      
{0x0F120000},	//70000BB6//AFIT16_GLAMOUR                                                         
{0x0F1200C0},	//70000BB8//AFIT16_bnr_edge_high                                                   
{0x0F120064},	//70000BBA//AFIT16_postdmsc_iLowBright                                             
{0x0F120384},	//70000BBC//AFIT16_postdmsc_iHighBright                                            
{0x0F120032},	//70000BBE//AFIT16_postdmsc_iLowSat                                                
{0x0F1201F4},	//70000BC0//AFIT16_postdmsc_iHighSat                                               
{0x0F120070},	//70000BC2//AFIT16_postdmsc_iTune                                                  
{0x0F120040},	//70000BC4//AFIT16_yuvemix_mNegRanges_0                                            
{0x0F1200A0},	//70000BC6//AFIT16_yuvemix_mNegRanges_1                                            
{0x0F120100},	//70000BC8//AFIT16_yuvemix_mNegRanges_2                                            
{0x0F120010},	//70000BCA//AFIT16_yuvemix_mPosRanges_0                                            
{0x0F120060},	//70000BCC//AFIT16_yuvemix_mPosRanges_1                                            
{0x0F120100},	//70000BCE//AFIT16_yuvemix_mPosRanges_2                                            
{0x0F121430},	//70000BD0//AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                        
{0x0F120201},	//70000BD2//AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                   
{0x0F120204},	//70000BD4//AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh              
{0x0F121504},	//70000BD6//AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                  
{0x0F12030F},	//70000BD8//AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                 
{0x0F120003},	//70000BDA//AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin              
{0x0F120902},	//70000BDC//AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                
{0x0F122004},	//70000BDE//AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH           
{0x0F120050},	//70000BE0//AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune            
{0x0F121140},	//70000BE2//AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh          
{0x0F12201C},	//70000BE4//AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh    
{0x0F120620},	//70000BE6//AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed     
{0x0F120306},	//70000BE8//AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh       
{0x0F122003},	//70000BEA//AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH              
{0x0F12FF01},	//70000BEC//AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit         
{0x0F120404},	//70000BEE//AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2              
{0x0F120300},	//70000BF0//AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                   
{0x0F12145A},	//70000BF2//AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                    
{0x0F121010},	//70000BF4//AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                     
{0x0F12000B},	//70000BF6//AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                        
{0x0F121000},	//70000BF8//AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                        
{0x0F125A0F},	//70000BFA//AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                   
{0x0F120503},	//70000BFC//AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                
{0x0F121802},	//70000BFE//AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                        
{0x0F120000},	//70000C00//AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                  
{0x0F122006},	//70000C02//AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                  
{0x0F123C28},	//70000C04//AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                   
{0x0F12042C},	//70000C06//AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                         
{0x0F120101},	//70000C08//AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                   
{0x0F12FF00},	//70000C0A//AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                  
{0x0F120904},	//70000C0C//AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh               
{0x0F124008},	//70000C0E//AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                
{0x0F120540},	//70000C10//AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                
{0x0F128006},	//70000C12//AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                
{0x0F120020},	//70000C14//AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                 
{0x0F120000},	//70000C16//AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh          
{0x0F121800},	//70000C18//AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat              
{0x0F120000},	//70000C1A//AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit           
{0x0F121E10},	//70000C1C//AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                  
{0x0F12000B},	//70000C1E//AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0            
{0x0F120607},	//70000C20//AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2          
{0x0F120005},	//70000C22//AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0          
{0x0F120607},	//70000C24//AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2          
{0x0F120405},	//70000C26//AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY           
{0x0F120206},	//70000C28//AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm            
{0x0F120304},	//70000C2A//AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm            
{0x0F120409},	//70000C2C//AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift          
{0x0F120305},	//70000C2E//AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y       
{0x0F120406},	//70000C30//AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y    
{0x0F122804},	//70000C32//AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV   
{0x0F120228},	//70000C34//AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y    
{0x0F121402},	//70000C36//AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV     
{0x0F120618},	//70000C38//AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL     
{0x0F121A02},	//70000C3A//AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL     
{0x0F128018},	//70000C3C//AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower     
{0x0F120080},	//70000C3E//AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce         
{0x0F120080},	//70000C40//AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset             
{0x0F120180},	//70000C42//AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                 
{0x0F120A0A},	//70000C44//AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                  
{0x0F120101},	//70000C46//AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C              
{0x0F121117},	//70000C48//AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh               
{0x0F126024},	//70000C4A//AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower               
{0x0F120A0A},	//70000C4C//AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                 
{0x0F12FFFF},	//70000C4E//AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp               
{0x0F120808},	//70000C50//AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope          
{0x0F120A01},	//70000C52//AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin         
{0x0F12010A},	//70000C54//AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin        
{0x0F121501},	//70000C56//AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin       
{0x0F12240F},	//70000C58//AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin       
{0x0F120A60},	//70000C5A//AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin        
{0x0F12FF0A},	//70000C5C//AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin        
{0x0F1208FF},	//70000C5E//AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin   
{0x0F120008},	//70000C60//AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                    
{0x0F120001},	//70000C62//AFITB_bnr_nClustLevel_C      [0]  
	//AFIT 4                                	
{0x0F120000},	//70000C64//AFIT16_BRIGHTNESS           
{0x0F120000},	//70000C66//AFIT16_CONTRAST                                                        
{0x0F120000},	//70000C68//AFIT16_SATURATION                                                      
{0x0F120000},	//70000C6A//AFIT16_SHARP_BLUR                                                      
{0x0F120000},	//70000C6C//AFIT16_GLAMOUR                                                         
{0x0F1200C0},	//70000C6E//AFIT16_bnr_edge_high                                                   
{0x0F120064},	//70000C70//AFIT16_postdmsc_iLowBright                                             
{0x0F120384},	//70000C72//AFIT16_postdmsc_iHighBright                                            
{0x0F120032},	//70000C74//AFIT16_postdmsc_iLowSat                                                
{0x0F1201F4},	//70000C76//AFIT16_postdmsc_iHighSat                                               
{0x0F120070},	//70000C78//AFIT16_postdmsc_iTune                                                  
{0x0F120040},	//70000C7A//AFIT16_yuvemix_mNegRanges_0                                            
{0x0F1200A0},	//70000C7C//AFIT16_yuvemix_mNegRanges_1                                            
{0x0F120100},	//70000C7E//AFIT16_yuvemix_mNegRanges_2                                            
{0x0F120010},	//70000C80//AFIT16_yuvemix_mPosRanges_0                                            
{0x0F120060},	//70000C82//AFIT16_yuvemix_mPosRanges_1                                            
{0x0F120100},	//70000C84//AFIT16_yuvemix_mPosRanges_2                                            
{0x0F121430},	//70000C86//AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                        
{0x0F120201},	//70000C88//AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                   
{0x0F120204},	//70000C8A//AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh              
{0x0F120F04},	//70000C8C//AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                  
{0x0F12030C},	//70000C8E//AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                 
{0x0F120003},	//70000C90//AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin              
{0x0F120602},	//70000C92//AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                
{0x0F121803},	//70000C94//AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH           
{0x0F120040},	//70000C96//AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune            
{0x0F120E20},	//70000C98//AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh          
{0x0F122018},	//70000C9A//AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh    
{0x0F120620},	//70000C9C//AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed     
{0x0F120306},	//70000C9E//AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh       
{0x0F122003},	//70000CA0//AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH              
{0x0F12FF01},	//70000CA2//AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit         
{0x0F120404},	//70000CA4//AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2              
{0x0F120200},	//70000CA6//AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                   
{0x0F12145A},	//70000CA8//AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                    
{0x0F121010},	//70000CAA//AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                     
{0x0F12000B},	//70000CAC//AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                        
{0x0F121200},	//70000CAE//AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                        
{0x0F125A0F},	//70000CB0//AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                   
{0x0F120502},	//70000CB2//AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                
{0x0F121802},	//70000CB4//AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                        
{0x0F120000},	//70000CB6//AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                  
{0x0F122006},	//70000CB8//AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                  
{0x0F124028},	//70000CBA//AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                   
{0x0F120430},	//70000CBC//AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                         
{0x0F120101},	//70000CBE//AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                   
{0x0F12FF00},	//70000CC0//AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                  
{0x0F120804},	//70000CC2//AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh               
{0x0F124008},	//70000CC4//AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                
{0x0F120540},	//70000CC6//AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                
{0x0F128006},	//70000CC8//AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                
{0x0F120020},	//70000CCA//AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                 
{0x0F120000},	//70000CCC//AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh          
{0x0F121800},	//70000CCE//AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat              
{0x0F120000},	//70000CD0//AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit           
{0x0F121E10},	//70000CD2//AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                  
{0x0F12000B},	//70000CD4//AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0            
{0x0F120607},	//70000CD6//AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2          
{0x0F120005},	//70000CD8//AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0          
{0x0F120607},	//70000CDA//AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2          
{0x0F120405},	//70000CDC//AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY           
{0x0F120205},	//70000CDE//AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm            
{0x0F120304},	//70000CE0//AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm            
{0x0F120409},	//70000CE2//AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift          
{0x0F120306},	//70000CE4//AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y       
{0x0F120407},	//70000CE6//AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y    
{0x0F122C04},	//70000CE8//AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV   
{0x0F12022C},	//70000CEA//AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y    
{0x0F121402},	//70000CEC//AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV     
{0x0F120618},	//70000CEE//AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL     
{0x0F121A02},	//70000CF0//AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL     
{0x0F128018},	//70000CF2//AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower     
{0x0F120080},	//70000CF4//AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce         
{0x0F120080},	//70000CF6//AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset             
{0x0F120180},	//70000CF8//AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                 
{0x0F120A0A},	//70000CFA//AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                  
{0x0F120101},	//70000CFC//AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C              
{0x0F120C0F},	//70000CFE//AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh               
{0x0F126024},	//70000D00//AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower               
{0x0F120808},	//70000D02//AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                 
{0x0F12FFFF},	//70000D04//AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp               
{0x0F120808},	//70000D06//AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope          
{0x0F120A01},	//70000D08//AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin         
{0x0F12010A},	//70000D0A//AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin        
{0x0F120F01},	//70000D0C//AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin       
{0x0F12240C},	//70000D0E//AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin       
{0x0F120860},	//70000D10//AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin        
{0x0F12FF08},	//70000D12//AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin        
{0x0F1208FF},	//70000D14//AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin   
{0x0F120008},	//70000D16//AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                    
{0x0F120001},	//70000D18//AFITB_bnr_nClustLevel_C      [0]                                       
	
{0x0F1223CE},	//70000D19//ConstAfitBaseVals
{0x0F12FDC8},	//70000D1A//ConstAfitBaseVals
{0x0F12112E},	//70000D1B//ConstAfitBaseVals
{0x0F1293A5},	//70000D1C//ConstAfitBaseVals
{0x0F12FE67},	//70000D1D//ConstAfitBaseVals
{0x0F120000},	//70000D1E//ConstAfitBaseVals
	   
//==================================================================================
// 18.JPEG Thumnail Setting
//==================================================================================
	   
{0x002A0478},	
{0x0F12005F},	//REG_TC_BRC_usPrevQuality    
{0x0F12005F},	//REG_TC_BRC_usCaptureQuality 
{0x0F120001},	//REG_TC_THUMB_Thumb_bActive  
{0x0F120280},	//REG_TC_THUMB_Thumb_uWidth   
{0x0F1201E0},	//REG_TC_THUMB_Thumb_uHeight  
{0x0F120005},	//REG_TC_THUMB_Thumb_Format   

{0x002A17DC},	
{0x0F120054},	//jpeg_ManualMBCV                
{0x002A1AE4},	                                 
{0x0F12001C},	//senHal_bExtraAddLine           
{0x002A0284},	                                 
{0x0F120001},	//REG_TC_GP_bBypassScalerJpg     
{0x002A028A},	                                 
{0x0F120000},	//REG_TC_GP_bUse1FrameCaptureMode

{0x002A1CC2},	//DRx_uDRxWeight for AutoCont function  
{0x0F120100},                                           
{0x0F120100},                                           
{0x0F120100},                                           
{0x0F120100},                                           

//==================================================================================
// 19.Input Size Setting
//==================================================================================
//Input Size	
{0x002A0250},                            	
{0x0F120A00},	//REG_TC_GP_PrevReqInputWidth
{0x0F120780},	//REG_TC_GP_PrevReqInputHeight
{0x0F120010},	//REG_TC_GP_PrevInputWidthOfs
{0x0F12000c},	//REG_TC_GP_PrevInputHeightOfs
{0x0F120A00},	//REG_TC_GP_CapReqInputWidth
{0x0F120780},	//REG_TC_GP_CapReqInputHeight
{0x0F120010},	//REG_TC_GP_CapInputWidthOfs
{0x0F12000c},	//REG_TC_GP_CapInputHeightOfs
  
{0x002A0494}, 
{0x0F120A00},	//REG_TC_PZOOM_ZoomInputWidth    
{0x0F120780},	//REG_TC_PZOOM_ZoomInputHeight   
{0x0F120000},	//REG_TC_PZOOM_ZoomInputWidthOfs 
{0x0F120000},	//REG_TC_PZOOM_ZoomInputHeightOfs
{0x0F120A00},	//REG_TC_CZOOM_ZoomInputWidth    
{0x0F120780},	//REG_TC_CZOOM_ZoomInputHeight   
{0x0F120000},	//REG_TC_CZOOM_ZoomInputWidthOfs 
{0x0F120000},	//REG_TC_CZOOM_ZoomInputHeightOfs
                        	
{0x002A0262},                                
{0x0F120001},	//REG_TC_GP_bUseReqInputInPre  
{0x0F120001},	//REG_TC_GP_bUseReqInputInCap  

//==================================================================================
// 20.Preview & Capture Configration Setting
//==================================================================================
//Preview config[0] 640x480  7.5~15fps	
{0x002A02A6},	
{0x0F120280},	//REG_0TC_PCFG_usWidth  //Hsize   : 640		
{0x0F1201E0},	//REG_0TC_PCFG_usHeight//Vsize   : 480  
{0x0F120005},	//REG_0TC_PCFG_Format	  05 : yuv 07: raw 09 : jpeg             
{0x0F124F1A},	//REG_0TC_PCFG_usMaxOut4KHzRate     	
{0x0F124F1A},	//REG_0TC_PCFG_usMinOut4KHzRate     	
{0x0F120100},	//REG_0TC_PCFG_OutClkPerPix88       	
{0x0F120300},	//REG_0TC_PCFG_uBpp88               	
{0x0F120040},	//REG_0TC_PCFG_PVIMask      soc raw : c2 raw 52  //0x0F120042       	
{0x0F120000},	//REG_0TC_PCFG_OIFMask              	
{0x0F1201E0},	//REG_0TC_PCFG_usJpegPacketSize     	
{0x0F120000},	//REG_0TC_PCFG_usJpegTotalPackets   	
{0x0F120000},	//REG_0TC_PCFG_uClockInd            	
{0x0F120000},	//REG_0TC_PCFG_usFrTimeType         	
{0x0F120001},	//REG_0TC_PCFG_FrRateQualityType    	
{0x0F1203E8},	//REG_0TC_PCFG_usMaxFrTimeMsecMult10	
{0x0F12014A},	//REG_0TC_PCFG_usMinFrTimeMsecMult10	
{0x002A02D0},	
{0x0F12000F},	//REG_0TC_PCFG_uPrevMirror
{0x0F12000F},	//REG_0TC_PCFG_uCaptureMirror
{0x0F120000},	//REG_0TC_PCFG_uRotation 	
//Capture Config[0] 2560x1920   7.5~15fps                           	
{0x002A0396},                                     	
{0x0F120000},	//REG_0TC_CCFG_uCaptureMode         
{0x0F120A00},	//REG_0TC_CCFG_usWidth              
{0x0F120780},	//REG_0TC_CCFG_usHeight             
{0x0F120009},	//REG_0TC_CCFG_Format               
{0x0F124F1A},	//REG_0TC_CCFG_usMaxOut4KHzRate     
{0x0F124F1A},	//REG_0TC_CCFG_usMinOut4KHzRate     
{0x0F120100},	//REG_0TC_CCFG_OutClkPerPix88       
{0x0F120300},	//REG_0TC_CCFG_uBpp88               
{0x0F120000},	//REG_0TC_CCFG_PVIMask  //0x0F120002            
{0x0F120070},	//REG_0TC_CCFG_OIFMask              
{0x0F120810},	//REG_0TC_CCFG_usJpegPacketSize     
{0x0F120900},	//REG_0TC_CCFG_usJpegTotalPackets   
{0x0F120001},	//REG_0TC_CCFG_uClockInd            
{0x0F120000},	//REG_0TC_CCFG_usFrTimeType         
{0x0F120002},	//REG_0TC_CCFG_FrRateQualityType    
{0x0F120535},	//REG_0TC_CCFG_usMaxFrTimeMsecMult10
{0x0F12029A},	//REG_0TC_CCFG_usMinFrTimeMsecMult10

{0x002A022C},	
{0x0F120001},	//REG_TC_IPRM_InitParamsUpdated

//==================================================================================
// 21.Select Cofigration Display
//==================================================================================
//PREVIEW                                                                        		
                                 		
{0x00287000},                                		                               		
{0x002A0266},   
{0x0f120000}, //REG_TC_GP_ActivePrevConfig        		
{0x002A026A},	                                         
{0x0F120001},	//REG_TC_GP_PrevOpenAfterChange     		                       		 
{0x002A0268},	                                         
{0x0F120001},	//REG_TC_GP_PrevConfigChanged                             
{0x002A026E},                                          
{0x0f120000},       //REG_TC_GP_ActiveCapConfig          
{0x002A026A},	                                         
{0x0F120001},	//REG_TC_GP_CapOpenAfterChange           
{0x002A0270},	                                         
{0x0F120001},	//REG_TC_GP_CapConfigChanged   
    		
{0x002A024E},	                                     
{0x0F120001},	//REG_TC_GP_NewConfigSync           	
{0x002A023E},
{0x0F120001},	//REG_TC_GP_EnablePreview           	
{0x0F120001},	//REG_TC_GP_EnablePreviewChanged    	 	

//===================================================================================
// 22. ESD Check
//===================================================================================

{0x00287000},	                                                                                    
{0x002A01A8},	//ESD Check                                                                         
{0x0f12AAAA},

//===================================================================================
// 23. Brightness min/Max
//===================================================================================
{0x0028147C},
{0x0F120170}, //bp_uMaxBrightnessFactor	
{0x00281482},
{0x0F1201E0}, //bp_uMinBrightnessFactor	

//===================================================================================
// 24.ISSUE
//===================================================================================
//20110728 : Sequence Changed by image dev. (by J.M.Ahn)
//20110728 : ESD Check Register Address Change
//20110829 : TnP Changed ( by S.Y.Lee)
//20120104 : init Parm Update sequence changed by J.M.Ahn)
//20120201 : Flash시 주변부 Green Noise 개선 setting (by J.M.Ahn)
//20120229 : Brightness Block 추가 (by J.W.Yoo)
CAMACQ_MAIN_BTM_OF_DATA

}

#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_fmt_jpg[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_fmt_yuv422[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA PREVIEW(640*480 / FULL)
//==========================================================
GLOBAL const U32 reg_main_preview[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},

{0x002A0294},
{0x0F120100}, //REG_TC_AF_FstWinStartX
{0x0F1200E3}, //REG_TC_AF_FstWinStartY
{0x0F120200}, //REG_TC_AF_FstWinSizeX
{0x0F120238}, //REG_TC_AF_FstWinSizeY
{0x0F1201C6},  // LSI_Cho AF Window Center from_LSI
{0x0F120166}, //REG_TC_AF_ScndWinStartY
{0x0F120074},  // LSI_Cho AF Fail when Size change from_LSI
{0x0F120132}, //REG_TC_AF_ScndWinSizeY
{0x0F120001}, //REG_TC_AF_WinSizesUpdated

{0x002A05D0},
{0x0F120000},
{0x002A0972},
{0x0F120000},
{0x002A0242},
{0x0F120000},
{0x002A024E},
{0x0F120001},
{0x002A0244},
{0x0F120001},
{0x002A023E},
{0x0F120001},	//	#REG_TC_GP_EnablePreview       	//
{0x0F120001},	//	#REG_TC_GP_EnablePreviewChanged	//
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U32 reg_main_preview_return[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},

{0x002A0294},
{0x0F120100}, //REG_TC_AF_FstWinStartX
{0x0F1200E3}, //REG_TC_AF_FstWinStartY
{0x0F120200}, //REG_TC_AF_FstWinSizeX
{0x0F120238}, //REG_TC_AF_FstWinSizeY
{0x0F1201C6},  // LSI_Cho AF Window Center from_LSI
{0x0F120166}, //REG_TC_AF_ScndWinStartY
{0x0F120074},  // LSI_Cho AF Fail when Size change from_LSI
{0x0F120132}, //REG_TC_AF_ScndWinSizeY
{0x0F120001}, //REG_TC_AF_WinSizesUpdated

{0x002A05D0},
{0x0F120000},
{0x002A0972},
{0x0F120000},
{0x002A0242},
{0x0F120000},
{0x002A024E},
{0x0F120001},
{0x002A0244},
{0x0F120001},
{0x002A023E},
{0x0F120001},	//	#REG_TC_GP_EnablePreview       	//
{0x0F120001},	//	#REG_TC_GP_EnablePreviewChanged	//
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;
//==========================================================
// SNAPSHOT
//==========================================================

GLOBAL const U32 reg_main_snapshot[]
#if defined(_CAMACQ_API_C_)
={

#if 1 //temp_denis

{0xFCFCD000},
{0x00287000},
{0x002A0242},
{0x0F120001},	//REG_TC_GP_EnableCapture
{0x002A024E},
{0x0F120001},	//REG_TC_GP_NewConfigSync
{0x002A0244},
{0x0F120001},	//REG_TC_GP_EnableCaptureChanged
#endif

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U32 reg_main_low_cap_on[]
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A06B8},
{0x0F12502C},
{0x0F120005},   //lt_uMaxLei

{0x002A0608},
{0x0F120001},   ///lt_ExpGain_uSubsamplingmode
{0x0F120001},   ///lt_ExpGain_uNonSubsampling
{0x0F120900},   ///lt_ExpGain_ExpCurveGainMaxStr

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U32 reg_main_low_cap_off[]
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A06B8},
{0x0F12452C},
{0x0F120005},   //lt_uMaxLei

{0x002A0608},
{0x0F120001},   //lt_ExpGain_uSubsamplingmode
{0x0F120001},   //lt_ExpGain_uNonSubsampling
{0x0F120800},   //lt_ExpGain_ExpCurveGainMaxStr

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U32 reg_main_highlight[]
#if defined(_CAMACQ_API_C_)
={
//High_capture
0xFCFCD000,
0x00287000,

0x002A0C7E,
0x0F12032D,	//70000C7E	//AFIT8_sddd8a_iRadialLimit [7:0], AFIT8_sddd8a_iRadialPower [15:8]

0x002A0CC4,
0x0F12210E,	//70000CC4	//AFIT8_sddd8a_iDenThreshHigh[7:0],   AFIT8_Demosaicing_iEdgeDesat [15:8]

0x002A0210,
0x0F120000,	//REG_TC_GP_ActiveCapConfig
0x002A01F4,
0x0F120001,	//REG_TC_GP_NewConfigSync
0x002A0212,
0x0F120001,	//REG_TC_GP_CapConfigChanged
0x002A01E8,
0x0F120001,	//REG_TC_GP_EnableCapture
0x0F120001,	//REG_TC_GP_EnableCaptureChanged

0xFEFE0042, //Dealy 66ms
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// MIDLIGHT SNAPSHOT =======> Flash Low light snapshot
//==========================================================
GLOBAL const U32 reg_main_midlight[]
#if defined(_CAMACQ_API_C_)
={
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// LOWLIGHT SNAPSHOT
//==========================================================
GLOBAL const U32 reg_main_lowlight[]
#if defined(_CAMACQ_API_C_)
={
//Low_capture
0xFCFCD000,
0x00287000,

0x002A085C,
0x0F12004A,	//0049	//#afit_uNoiseIndInDoor_0_
0x0F12004E,	//005F	//#afit_uNoiseIndInDoor_1_


0x002A0210,
0x0F120000,	//REG_TC_GP_ActiveCapConfig
0x002A01F4,
0x0F120001,	//REG_TC_GP_NewConfigSync
0x002A0212,
0x0F120001,	//REG_TC_GP_CapConfigChanged
0x002A01E8,
0x0F120001,	//REG_TC_GP_EnableCapture
0x0F120001,	//REG_TC_GP_EnableCaptureChanged

0xFEFE0082, //Dealy 130ms
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;



/*****************************************************************/
/*********************** N I G H T  M O D E **********************/
/*****************************************************************/

//==========================================================
// CAMERA NIGHTMODE ON
//==========================================================
GLOBAL const U32 reg_main_nightshot_on[]
#if defined(_CAMACQ_API_C_)
={
// ==========================================================
// 	CAMERA_SCENE_NIGHT (Night/Center/Br0/Auto/Sharp0/Sat0)
// ==========================================================
0xFCFCD000,
0x00287000,  

0x002A025A,
0x0F1209C4,	//REG_0TC_PCFG_usMaxFrTimeMsecMult10

0x002A034C,
0x0F121388,	//REG_0TC_CCFG_usMaxFrTimeMsecMult10
0x0F121388,	//REG_0TC_CCFG_usMinFrTimeMsecMult10

0x002A01CC,
0x0F120001,       //REG_TC_IPRM_InitParamsUpdated

0x002A0504,
0x0F123415,		//lt_uMaxExp1		3415h = 13333d =  33.3325ms
0x002A0508,
0x0F12681F,		//lt_uMaxExp2		681Fh = 26655d =  66.6375ms
0x002A050C,
0x0F128227,		//lt_uMaxExp3		8227h = 33319d =  83.2975ms
0x002A0510,
0x0F121A80,		//lt_uMaxExp4		00061A80h = 400000d =  1000ms
0x0F120006,

0x002A0514,
0x0F123415,		//lt_uCapMaxExp1		3415h = 13333d =  33.3325ms
0x002A0518,
0x0F12681F,		//lt_uCapMaxExp2		681Fh = 26655d =  66.6375ms
0x002A051C,
0x0F128227,		//lt_uCapMaxExp3		8227h = 33319d =  83.2975ms
0x002A0520,
0x0F121A80,		//lt_uCapMaxExp4		00061A80h = 400000d =  1000ms
0x0F120006,

0x002A0524,
0x0F1201D0,		//lt_uMaxAnGain1		0180h	= 0384d	= x1.5000
0x0F1201D0,		//lt_uMaxAnGain2		0180h	= 0384d	= x1.5000
0x0F1202C0,		//lt_uMaxAnGain3		0250h	= 0592d	= x2.3125
0x0F120800,		//lt_uMaxAnGain4		0710h	= 1808d	= x7.0625

0x0F120100,		//lt_uMaxDigGain
0x0F128000,		//lt_uMaxTotGain

0x0F1201D0,		//lt_uCapMaxAnGain1		0180h	= 0384d	= x1.5000
0x0F1201D0,		//lt_uCapMaxAnGain2		0180h	= 0384d	= x1.5000
0x0F1202C0,		//lt_uCapMaxAnGain3		0250h	= 0592d	= x2.3125
0x0F120800,		//lt_uCapMaxAnGain4		0710h	= 1808d	= x7.0625

0x0F120100,		//lt_uCapMaxDigGain
0x0F128000,		//lt_uCapMaxTotGain

0x002A08E4,
0x0F120000,	//AFIT16_demsharpmix1_iHystThLow
0x0F120000,	//AFIT16_demsharpmix1_iHystThHigh
0x002A0940,
0x0F121080,	//[15:8] AFIT8_RGB2YUV_iYOffset, [7:0] AFIT8_ccm_oscar_iSaturation

//PREVIEW
0x002A0208,
0x0F120000,	//REG_TC_GP_ActivePrevConfig
0x002A0210,
0x0F120000,	//REG_TC_GP_ActiveCapConfig
0x002A020C,
0x0F120001,	//REG_TC_GP_PrevOpenAfterChange
0x002A01F4,
0x0F120001,	//REG_TC_GP_NewConfigSync
0x002A020A,
0x0F120001,	//REG_TC_GP_PrevConfigChanged
0x002A0212,
0x0F120001,	//REG_TC_GP_CapConfigChanged
0x002A01E8,
0x0F120000,	//REG_TC_GP_EnableCapture
0x0F120001,	//REG_TC_GP_EnableCaptureChanged
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA NIGHTMODE OFF
//==========================================================
GLOBAL const U32 reg_main_nightshot_off[]
#if defined(_CAMACQ_API_C_)
={
// ==========================================================
// 	CAMERA_SCENE_OFF
// ==========================================================
0xFCFCD000,
0x00287000,
0x002A2A62,
0x0F120001,		//Mon_AAIO_bAWB		0: AWB OFF, 1: AWB ON

//	01. Portait / Landscape / Text / Fall Color Off

0x00287000,
0x002A1308,
0x0F120040,  //TVAR_ae_BrAve
0x002A01D0,
0x0F120000,		//REG_TC_UserBrightness
0x002A01D4,
0x0F120000,		//REG_TC_UserSaturation
0x0F120000,		//REG_TC_UserSharpBlur

// metering center

0x002A1316,		//ae_WeightTbl_16

0x0F120000,
0x0F120000,
0x0F120000,
0x0F120000,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120201,
0x0F120102,
0x0F120101,
0x0F120101,
0x0F120202,
0x0F120202,
0x0F120101,
0x0F120101,
0x0F120202,
0x0F120202,
0x0F120101,
0x0F120201,
0x0F120202,
0x0F120202,
0x0F120102,
0x0F120201,
0x0F120202,
0x0F120202,
0x0F120102,
0x0F120101,
0x0F120101,
0x0F120101,
0x0F120101,


//	02. Night / Firework Off

0x00287000,
0x002A025A,
0x0F1203E8,	//REG_0TC_PCFG_usMaxFrTimeMsecMult10
0x0F12014E,	//REG_0TC_PCFG_usMinFrTimeMsecMult10

0x002A034C,
0x0F120535,	//REG_0TC_CCFG_usMaxFrTimeMsecMult10
0x0F12029A,	//REG_0TC_CCFG_usMinFrTimeMsecMult10

0x00287000,
0x002A0504,
0x0F123415,		//lt_uMaxExp1		3415h = 13333d =  33.3325ms
0x002A0508,
0x0F12681F,		//lt_uMaxExp2		681Fh = 26655d =  66.6375ms
0x002A050C,
0x0F128227,		//lt_uMaxExp3		8227h = 33319d =  83.2975ms
0x002A0510,
0x0F12C350,		//lt_uMaxExp4		C350h = 50000d = 125.0000ms
0x0F120000,

0x002A0514,
0x0F123415,		//lt_uCapMaxExp1		3415h = 13333d =  33.3325ms
0x002A0518,
0x0F12681F,		//lt_uCapMaxExp2		681Fh = 26655d =  66.6375ms
0x002A051C,
0x0F128227,		//lt_uCapMaxExp3		8227h = 33319d =  83.2975ms
0x002A0520,
0x0F12C350,		//lt_uCapMaxExp4		C350h = 50000d = 125.0000ms
0x0F120000,

0x002A0524,
0x0F1201D0,		//lt_uMaxAnGain1
0x0F1201D0,		//lt_uMaxAnGain2
0x0F1202C0,		//lt_uMaxAnGain3
0x0F120880,		//lt_uMaxAnGain4

0x0F120100,		//lt_uMaxDigGain
0x0F128000,		//lt_uMaxTotGain

0x0F1201D0,		//lt_uCapMaxAnGain1
0x0F1201D0,		//lt_uCapMaxAnGain2
0x0F1202C0,		//lt_uCapMaxAnGain3
0x0F120710,		//lt_uCapMaxAnGain4

0x0F120100,		//lt_uCapMaxDigGain
0x0F128000,		//lt_uCapMaxTotGain

0x002A08E4,
0x0F120010,		//AFIT16_demsharpmix1_iHystThLow
0x0F120010,		//AFIT16_demsharpmix1_iHystThHigh
0x002A0940,
0x0F120B50,		//[15:8] AFIT8_RGB2YUV_iYOffset, [7:0] AFIT8_ccm_oscar_iSaturation


//	03. ISO Auto

0x002A04A4,
0x0F12067F,		//REG_TC_DBG_AutoAlgEnBits		Auto Algorithm Enable
0x002A048C,
0x0F120001,		//REG_SF_USER_FlickerQuant		0:No AFC, 1:50Hz, 2:60Hz
0x0F120001,		//REG_SF_USER_FlickerQuantChanged

0x002A05EA,
0x0F120100,		//lt_bUseSecISODgain

0x002A0486,
0x0F120000,		//REG_SF_USER_IsoType		0:OFF 3:ISO
0x002A048A,
0x0F120001,		//REG_SF_USER_IsoChanged

0x002A3302,
0x0F120000,		//AFIT by Normalized Brightness Tunning Parameter

//PREVIEW
0x002A0208,
0x0F120000,		//REG_TC_GP_ActivePrevConfig
0x002A0210,
0x0F120000,		//REG_TC_GP_ActiveCapConfig
0x002A020C,
0x0F120001,		//REG_TC_GP_PrevOpenAfterChange
0x002A01F4,
0x0F120001,		//REG_TC_GP_NewConfigSync
0x002A020A,
0x0F120001,		//REG_TC_GP_PrevConfigChanged
0x002A0212,
0x0F120001,		//REG_TC_GP_CapConfigChanged
0x002A01E8,
0x0F120000,	//REG_TC_GP_EnableCapture
0x0F120001,	//REG_TC_GP_EnableCaptureChanged
CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// NIGHT-MODE SNAPSHOT
//==========================================================
GLOBAL const U32 reg_main_nightshot[]
#if defined(_CAMACQ_API_C_)
={
//Night_capture
0xFCFCD000,
0x00287000,

0x002A0210,
0x0F120000,	//REG_TC_GP_ActiveCapConfig
0x002A01F4,
0x0F120001,	//REG_TC_GP_NewConfigSync
0x002A0212,
0x0F120001,	//REG_TC_GP_CapConfigChanged
0x002A01E8,
0x0F120001,	//REG_TC_GP_EnableCapture
0x0F120001,	//REG_TC_GP_EnableCaptureChanged

0xFEFE012C,   //300ms 
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_AUTO (1/10)
//==========================================================
GLOBAL const U32 reg_main_wb_auto[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A2C66},
{0x0F120001},
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_DAYLIGHT (2/10)
//==========================================================
GLOBAL const U32 reg_main_wb_daylight[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},

{0x002A04BA},// R //
{0x0F120620},

{0x002A04BE},// G //
{0x0F1203D0},

{0x002A04C2},// B //
{0x0F120580},

{0x002A04C6},
{0x0F120001},
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_CLOUDY  (3/10)
//==========================================================
GLOBAL const U32 reg_main_wb_cloudy[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},

{0x002A04BA}, // R //
{0x0F120740}, // SEHF_0740

{0x002A04BE}, // G //
{0x0F1203EA},

{0x002A04C2}, // B //
{0x0F1204D0},

{0x002A04C6},
{0x0F120001},
CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_INCANDESCENT (4/10)
//==========================================================
GLOBAL const U32 reg_main_wb_incandescent[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},

{0x002A04BA},
{0x0F1203E0},	//REG_SF_USER_Rgain
{0x002A04BE},
{0x0F120400},	//REG_SF_USER_Ggain
{0x002A04C2},
{0x0F120988},	//REG_SF_USER_Bgain

{0x002A04C6},
{0x0F120001},	//REG_SF_USER_RGBGainChanged
CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (5/10)
//==========================================================
GLOBAL const U32 reg_main_wb_fluorescent[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},

{0x002A04BA},
{0x0F1205A5},	//REG_SF_USER_Rgain
{0x002A04BE},
{0x0F120400},	//REG_SF_USER_Ggain
{0x002A04C2},
{0x0F1208A8},	//REG_SF_USER_Bgain

{0x002A04C6},
{0x0F120001},	//REG_SF_USER_RGBGainChanged
CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (6/10)
//==========================================================
GLOBAL const U32 reg_main_wb_twilight[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (7/10)
//==========================================================
GLOBAL const U32 reg_main_wb_tungsten[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},

{0x002A04BA},
{0x0F1203E0},	//REG_SF_USER_Rgain
{0x002A04BE},
{0x0F120400},	//REG_SF_USER_Ggain
{0x002A04C2},
{0x0F120988},	//REG_SF_USER_Bgain

{0x002A04C6},
{0x0F120001},	//REG_SF_USER_RGBGainChanged

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (8/10)
//==========================================================
GLOBAL const U32 reg_main_wb_off[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (9/10)
//==========================================================
GLOBAL const U32 reg_main_wb_horizon[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_WB_FLUORESCENT (10/10)
//==========================================================
GLOBAL const U32 reg_main_wb_shade[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_EFFECT_OFF (1/13)
//==========================================================
GLOBAL const U32 reg_main_effect_none[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A023C},
{0x0F120000},
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_MONO (2/13)
//==========================================================
GLOBAL const U32 reg_main_effect_gray[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A023C},
{0x0F120001},
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_NEGATIVE (3/13)
//==========================================================
GLOBAL const U32 reg_main_effect_negative[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A023C},
{0x0F120003},
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_SOLARIZE (4/13)
//==========================================================
GLOBAL const U32 reg_main_effect_solarize[]
#if defined(_CAMACQ_API_C_)
={/*swsw empty*/
	{0xFCFCD000},
	{0x00287000},
	{0x002A023C},
	{0x0F120002},
	CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_SEPIA (5/13)
//==========================================================
GLOBAL const U32 reg_main_effect_sepia[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A023C},
{0x0F120004},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_POSTERIZE (6/13)
//==========================================================
GLOBAL const U32 reg_main_effect_posterize[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_WHITEBOARD (7/13)
//==========================================================
GLOBAL const U32 reg_main_effect_whiteboard[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_BLACKBOARD (8/13)
//==========================================================
GLOBAL const U32 reg_main_effect_blackboard[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_AQUA (9/13)
//==========================================================
GLOBAL const U32 reg_main_effect_aqua[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_SHARPEN (10/13)
//==========================================================
GLOBAL const U32 reg_main_effect_sharpen[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_AQUA (11/13)
//==========================================================
GLOBAL const U32 reg_main_effect_vivid[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_GREEN (12/13)
//==========================================================
GLOBAL const U32 reg_main_effect_green[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000, 
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EFFECT_SKETCH (13/13)
//==========================================================
GLOBAL const U32 reg_main_effect_sketch[]
#if defined(_CAMACQ_API_C_)
={
//EF_sketch

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_AEC_MATRIX_METERING (2/2)
//==========================================================
GLOBAL const U32 reg_main_meter_matrix[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1492},
{0x0F120101},	//ae_WeightTbl_16
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},

{0x002A0268},   //REG_TC_GP_PrevConfigChanged
{0x0F120001},
	CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_AEC_CENTERWEIGHTED_METERING (2/2)
//==========================================================
GLOBAL const U32 reg_main_meter_cw[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1492},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120202},
{0x0F120202},
{0x0F120101},
{0x0F120201},
{0x0F120202},
{0x0F120202},
{0x0F120102},
{0x0F120201},
{0x0F120302},
{0x0F120203},
{0x0F120102},
{0x0F120201},
{0x0F120302},
{0x0F120203},
{0x0F120102},
{0x0F120101},
{0x0F120202},
{0x0F120202},
{0x0F120101},
{0x0F120101},
{0x0F120201},
{0x0F120102},
{0x0F120101},
{0x0F120100},
{0x0F120101},
{0x0F120101},
{0x0F120001},

{0x002A0268},   //REG_TC_GP_PrevConfigChanged
{0x0F120001},

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_AEC_SPOT_METERING (1/2)
//==========================================================
GLOBAL const U32 reg_main_meter_spot[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1492},
{0x0F120000},	//ae_WeightTbl_16
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120101},
{0x0F120101},
{0x0F120000},
{0x0F120000},
{0x0F120F01},
{0x0F12010F},
{0x0F120000},
{0x0F120000},
{0x0F120F01},
{0x0F12010F},
{0x0F120000},
{0x0F120000},
{0x0F120101},
{0x0F120101},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},

{0x002A0268},   //REG_TC_GP_PrevConfigChanged
{0x0F120001},

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_AEC_FRAME_AVERAGE (2/2)
//==========================================================
GLOBAL const U32 reg_main_meter_frame[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FLIP_NONE (1/4)
//==========================================================
GLOBAL const U32 reg_main_flip_none[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FLIP_VERTICAL (2/4)
//==========================================================
GLOBAL const U32 reg_main_flip_water[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FLIP_HORIZ (3/4)
//==========================================================
GLOBAL const U32 reg_main_flip_mirror[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_FLIP_SYMMETRIC (4/4)
//==========================================================
GLOBAL const U32 reg_main_flip_water_mirror[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;



//==========================================================
// CAMERA_CAMCORDER
//==========================================================
GLOBAL const U32 reg_main_camcorder[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},

{0x002A18AC},
{0x0F120060},	//senHal_uAddColsBin
{0x0F120060},	//senHal_uAddColsNoBin
{0x0F1205C0},	//senHal_uMinColsBin
{0x0F1205C0},	//senHal_uMinColsNoBin

	// FOR HD CAMCORDER
	// FRAME RATE

	// AE TARGET
{0x002A1484},
{0x0F12002A},	//003C   //TVAR_ae_BrAve p //

	// METERING
{0x002A1492},	// Matrix //
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},


	// SLOW AE
{0x002A1568},
{0x0F120030},	// 0010 ae_GainIn_0_			//						
{0x0F120090},	// 0020	ae_GainIn_1_			//					
{0x0F1200A8},	// 0040	ae_GainIn_2_			//					
{0x0F1200C0},	// 0080	ae_GainIn_3_			//					
{0x0F120100},	// fix 0100	ae_GainIn_4_			//					
{0x0F120140},	// 0200	ae_GainIn_5_			//					
{0x0F120180},	// 0400	ae_GainIn_6_			//					
{0x0F120400},	// 0800	ae_GainIn_7_			//					
{0x0F122000},	// 2000	ae_GainIn_8_			//	

{0x0F120080},	//0050	// 0010	ae_GainOut_0_	p	//						
{0x0F1200D0},	//0070	// 0020	ae_GainOut_1_ p//						
{0x0F1200D8},	//00A0	// 0040	ae_GainOut_2_	p	//						
{0x0F1200F8},	//00D0	// 0080	ae_GainOut_3_	p	//						
{0x0F120100},	// fix 0100	ae_GainOut_4_		//						
{0x0F120103},	// 0200	ae_GainOut_5_		//						
{0x0F120110},	// 0400	ae_GainOut_6_		//						
{0x0F120150},	// 0800	ae_GainOut_7_		//						
{0x0F120400},	// 2000	ae_GainOut_8_		//					

{0x002A0544},
{0x0F120105},	// limit high		//						
{0x0F1200FA},	// limit low		//

{0x002A0588},
{0x0F120001},	// post tolerance cnt		//	

{0x002A0582},
{0x0F1200D0},	// speed		//		

{0x002A47B0},
{0x0F120001},	//TNP_Regs_BUse1FrameAE	(0: off, 1: on)									


	// SLOW AWB
{0x002A139A},	
{0x0F120258}, //0258 awbb_GainsMaxMove//

	//AWB Convergence Speed //
{0x002A1464},
{0x0F120008},
{0x0F12FFFF},	//0190	awbb_WpFilterMaxThr //
{0x0F120010}, //00A0	//awbb_WpFilterCoef p //
{0x0F120020},	//0004 awbb_WpFilterSize //

	// SEHF_HD_Camcorder_AWB	
	//Indoor Grid Offset
{0x002A13A4},
{0x0F120000},  //0000
{0x0F12FFD8},  //FFD8
{0x0F12FFD8},  //FFD8
{0x0F12FFD8},  //FFD8
{0x0F12FFD8},  //FFD8
{0x0F12FFD0},  //FFF6 B
	//    
{0x0F120000},  //0000
{0x0F12FFD8},  //FFD8
{0x0F12FFD8},  //FFD8
{0x0F12FFD8},  //FFD8
{0x0F12FFD8},  //FFD8
{0x0F12FFD0},  //FFF6
	//    
{0x0F120000},  //0000
{0x0F12FFD8},  //FFD8
{0x0F12FFD8},  //FFD8
{0x0F12FFD8},  //FFD8
{0x0F12FFD8},  //FFD8
{0x0F12FFD0},  //FFF6
	//    
{0x0F12FFEC},  //FFEC
{0x0F12000A},  //000A
{0x0F12000A},  //000A
{0x0F12FFC4},  //FFC4
{0x0F12FFC4},  //FFC4
{0x0F12FF66},  //FF56 7
	//    
{0x0F12FFEC},  //FFEC
{0x0F12000A},  //000A
{0x0F12000A},  //000A
{0x0F12FFC4},  //FFC4
{0x0F12FFC4},  //FFC4
{0x0F12FF66},  //FF56
	//    
{0x0F12FFEC},  //FFEC
{0x0F12000A},  //000A
{0x0F12000A},  //000A
{0x0F12FFC4},  //FFC4
{0x0F12FFC4},  //FFC4
{0x0F12FF66},  //FF56

	//Outdoor Grid Offset
{0x0F120000}, 
{0x0F120000},  // LSI_PKC FFD0
{0x0F120000},  // LSI_PKC FFC0
{0x0F120000}, 
{0x0F120000}, 
{0x0F120000}, 

{0x0F120000}, 
{0x0F120000},  // LSI_PKC FFD0
{0x0F120000},  // LSI_PKC FFC0
{0x0F120000}, 
{0x0F120000}, 
{0x0F120000},

{0x0F120000}, 
{0x0F120000},  // LSI_PKC FFD0 
{0x0F120000},  // LSI_PKC FFC0
{0x0F120000}, 
{0x0F120000}, 
{0x0F120000}, 

{0x0F12FFC0}, 
{0x0F12FFC0}, 
{0x0F12FFC0}, 
{0x0F120000}, 
{0x0F120000}, 
{0x0F120000}, 

{0x0F12FFC0}, 
{0x0F12FFC0}, 
{0x0F12FFC0}, 
{0x0F120000}, 
{0x0F120000}, 
{0x0F120000}, 

{0x0F12FFC0}, 
{0x0F12FFC0}, 
{0x0F12FFC0}, 
{0x0F120000}, 
{0x0F120000}, 
{0x0F120000}, 

{0x002A1208},
{0x0F120020},

{0x002A144E},
{0x0F120000},   //awbb_RGainOff
{0x0F12FFE0},   //awbb_BGainOff
{0x0F120000},   //awbb_GGainOff
	// SEHF_HD_Camcorder_AWB
	
  // CCM
{0x002A4800},   // Horizon 
{0x0F120208},
{0x0F12FFB5},
{0x0F12FFE8},
{0x0F12FF20},
{0x0F1201BF},
{0x0F12FF53},
{0x0F120022},
{0x0F12FFEA},
{0x0F1201C2},
{0x0F1200C6},
{0x0F120095},
{0x0F12FEFD},
{0x0F120206},
{0x0F12FF7F},
{0x0F120191},
{0x0F12FF06},
{0x0F1201BA},
{0x0F120108},

{0x0F120208},   // inca A
{0x0F12FFB5}, 
{0x0F12FFE8}, 
{0x0F12FF20}, 
{0x0F1201BF}, 
{0x0F12FF53}, 
{0x0F120022}, 
{0x0F12FFEA}, 
{0x0F1201C2}, 
{0x0F1200C6}, 
{0x0F120095}, 
{0x0F12FEFD}, 
{0x0F120206}, 
{0x0F12FF7F}, 
{0x0F120191}, 
{0x0F12FF06}, 
{0x0F1201BA}, 
{0x0F120108}, 

{0x0F120208},   // WW
{0x0F12FFB5}, 
{0x0F12FFE8}, 
{0x0F12FF20}, 
{0x0F1201BF}, 
{0x0F12FF53}, 
{0x0F120022}, 
{0x0F12FFEA}, 
{0x0F1201C2}, 
{0x0F1200C6}, 
{0x0F120095}, 
{0x0F12FEFD}, 
{0x0F120206}, 
{0x0F12FF7F}, 
{0x0F120191}, 
{0x0F12FF06}, 
{0x0F1201BA}, 
{0x0F120108}, 

{0x0F120209},	//TVAR_wbt_pBaseCcms[54] // CW
{0x0F12FFBD},	//TVAR_wbt_pBaseCcms[55]
{0x0F12FFDF},	//TVAR_wbt_pBaseCcms[56]
{0x0F12FF20},	//TVAR_wbt_pBaseCcms[57]
{0x0F1201BF},	//TVAR_wbt_pBaseCcms[58]
{0x0F12FF53},	//TVAR_wbt_pBaseCcms[59]
{0x0F120022},	//TVAR_wbt_pBaseCcms[60]
{0x0F12FFEA},	//TVAR_wbt_pBaseCcms[61]
{0x0F1201C2},	//TVAR_wbt_pBaseCcms[62]
{0x0F1200CC},	//TVAR_wbt_pBaseCcms[63]
{0x0F12008F},	//TVAR_wbt_pBaseCcms[64]
{0x0F12FEFE},	//TVAR_wbt_pBaseCcms[65]
{0x0F120206},	//TVAR_wbt_pBaseCcms[66]
{0x0F12FF7F},	//TVAR_wbt_pBaseCcms[67]
{0x0F120191},	//TVAR_wbt_pBaseCcms[68]
{0x0F12FF06},	//TVAR_wbt_pBaseCcms[69]
{0x0F1201BA},	//TVAR_wbt_pBaseCcms[70]
{0x0F120108},	//TVAR_wbt_pBaseCcms[71]

{0x0F120209},	//TVAR_wbt_pBaseCcms[72] // D50
{0x0F12FFBD},	//TVAR_wbt_pBaseCcms[73]
{0x0F12FFDF},	//TVAR_wbt_pBaseCcms[74]
{0x0F12FF20},	//TVAR_wbt_pBaseCcms[75]
{0x0F1201BF},	//TVAR_wbt_pBaseCcms[76]
{0x0F12FF53},	//TVAR_wbt_pBaseCcms[77]
{0x0F120022},	//TVAR_wbt_pBaseCcms[78]
{0x0F12FFEA},	//TVAR_wbt_pBaseCcms[79]
{0x0F1201C2},	//TVAR_wbt_pBaseCcms[80]
{0x0F1200CC},	//TVAR_wbt_pBaseCcms[81]
{0x0F12008F},	//TVAR_wbt_pBaseCcms[82]
{0x0F12FEFE},	//TVAR_wbt_pBaseCcms[83]
{0x0F120206},	//TVAR_wbt_pBaseCcms[84]
{0x0F12FF7F},	//TVAR_wbt_pBaseCcms[85]
{0x0F120191},	//TVAR_wbt_pBaseCcms[86]
{0x0F12FF06},	//TVAR_wbt_pBaseCcms[87]
{0x0F1201BA},	//TVAR_wbt_pBaseCcms[88]
{0x0F120108},	//TVAR_wbt_pBaseCcms[89]

{0x0F120209},	//TVAR_wbt_pBaseCcms[90] // D65
{0x0F12FFBD},	//TVAR_wbt_pBaseCcms[91]
{0x0F12FFDF},	//TVAR_wbt_pBaseCcms[92]
{0x0F12FF20},	//TVAR_wbt_pBaseCcms[93]
{0x0F1201BF},	//TVAR_wbt_pBaseCcms[94]
{0x0F12FF53},	//TVAR_wbt_pBaseCcms[95]
{0x0F120022},	//TVAR_wbt_pBaseCcms[96]
{0x0F12FFEA},	//TVAR_wbt_pBaseCcms[97]
{0x0F1201C2},	//TVAR_wbt_pBaseCcms[98]
{0x0F1200CC},	//TVAR_wbt_pBaseCcms[99]
{0x0F12008F},	//TVAR_wbt_pBaseCcms[100]
{0x0F12FEFE},	//TVAR_wbt_pBaseCcms[101]
{0x0F120206},	//TVAR_wbt_pBaseCcms[102]
{0x0F12FF7F},	//TVAR_wbt_pBaseCcms[103]
{0x0F120191},	//TVAR_wbt_pBaseCcms[104]
{0x0F12FF06},	//TVAR_wbt_pBaseCcms[105]
{0x0F1201BA},	//TVAR_wbt_pBaseCcms[106]
{0x0F120108},	//TVAR_wbt_pBaseCcms[107]
  // CCM	

	// SHARPNESS n NOISE
{0x002A0938},
{0x0F120001},	  //afit_bUseNB_Afit on 1  off 0 
{0x0F120014},   //SARR_uNormBrInDoor_0_
{0x0F1200D2},   //SARR_uNormBrInDoor_1_
{0x0F120784},   //SARR_uNormBrInDoor_2_
{0x0F1210D0},   //SARR_uNormBrInDoor_3_
{0x0F121388},   //SARR_uNormBrInDoor_4_

{0x002A098C},   //AFIT 0
{0x0F120000},   //70000C64 AFIT16_BRIGHTNESS    
{0x0F120000},   //70000C66 AFIT16_CONTRAST                                                              	
{0x0F120000},   //70000C68 AFIT16_SATURATION                                                            	
{0x0F120000},   //70000C6A AFIT16_SHARP_BLUR                                                            	
{0x0F120000},   //70000C6C AFIT16_GLAMOUR                                                               	
{0x0F1200C0},   //70000C6E AFIT16_bnr_edge_high                                                         	
{0x0F120064},   //70000C70 AFIT16_postdmsc_iLowBright                                                   	
{0x0F120384},   //70000C72 AFIT16_postdmsc_iHighBright                                                  	
{0x0F120051},   //70000C74 AFIT16_postdmsc_iLowSat                                                      	
{0x0F1201F4},   //70000C76 AFIT16_postdmsc_iHighSat                                                     	
{0x0F120070},   //70000C78 AFIT16_postdmsc_iTune                                                        	
{0x0F120040},   //70000C7A AFIT16_yuvemix_mNegRanges_0                                                  	
{0x0F1200A0},   //70000C7C AFIT16_yuvemix_mNegRanges_1                                                  	
{0x0F120100},   //70000C7E AFIT16_yuvemix_mNegRanges_2                                                  	
{0x0F120010},   //70000C80 AFIT16_yuvemix_mPosRanges_0                                                  	
{0x0F120060},   //70000C82 AFIT16_yuvemix_mPosRanges_1                                                  	
{0x0F120100},   //70000C84 AFIT16_yuvemix_mPosRanges_2                                                  	
{0x0F121430},   //70000C86 AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
{0x0F120201},   //70000C88 AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
{0x0F120204},   //70000C8A AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
{0x0F122404},   //70000C8C AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
{0x0F12031B},   //70000C8E AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
{0x0F120103},   //70000C90 AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
{0x0F121205},   //70000C92 AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
{0x0F12400D},   //70000C94 AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
{0x0F120080},   //70000C96 AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
{0x0F122080},   //70000C98 AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
{0x0F123040},   //70000C9A AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
{0x0F120630},   //70000C9C AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
{0x0F120306},   //70000C9E AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
{0x0F122003},   //70000CA0 AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
{0x0F12FF01},   //70000CA2 AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
{0x0F120404},   //70000CA4 AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
{0x0F120300},   //70000CA6 AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
{0x0F12245A},   //70000CA8 AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
{0x0F121018},   //70000CAA AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
{0x0F12000B},   //70000CAC AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
{0x0F120B00},   //70000CAE AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
{0x0F125A0F},   //70000CB0 AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
{0x0F120505},   //70000CB2 AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
{0x0F121802},   //70000CB4 AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
{0x0F120000},   //70000CB6 AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
{0x0F122006},   //70000CB8 AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
{0x0F123428},   //70000CBA AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
{0x0F12041C},   //70000CBC AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
{0x0F120101},   //70000CBE AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
{0x0F120800},   //70000CC0 AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
{0x0F121004},   //70000CC2 AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
{0x0F124008},   //70000CC4 AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
{0x0F120540},   //70000CC6 AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
{0x0F128006},   //70000CC8 AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
{0x0F120020},   //70000CCA AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
{0x0F120000},   //70000CCC AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
{0x0F121800},   //70000CCE AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
{0x0F120000},   //70000CD0 AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
{0x0F121E10},   //70000CD2 AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
{0x0F12000B},   //70000CD4 AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
{0x0F120607},   //70000CD6 AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
{0x0F120005},   //70000CD8 AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
{0x0F120607},   //70000CDA AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
{0x0F120405},   //70000CDC AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
{0x0F120205},   //70000CDE AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
{0x0F120304},   //70000CE0 AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
{0x0F120409},   //70000CE2 AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
{0x0F120306},   //70000CE4 AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
{0x0F120407},   //70000CE6 AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
{0x0F121804},   //70000CE8 AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
{0x0F120214},   //70000CEA AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
{0x0F121002},   //70000CEC AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
{0x0F120610},   //70000CEE AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
{0x0F121A02},   //70000CF0 AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
{0x0F128018},   //70000CF2 AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
{0x0F1200B0},   //70000CF4 AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
{0x0F121080},   //70000CF6 AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
{0x0F120180},   //70000CF8 AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
{0x0F120A0A},   //70000CFA AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
{0x0F120101},   //70000CFC AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
{0x0F121B24},   //70000CFE AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
{0x0F126024},   //70000D00 AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
{0x0F121D22},   //70000D02 AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
{0x0F12FFFF},   //70000D04 AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
{0x0F120808},   //70000D06 AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
{0x0F120A01},   //70000D08 AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
{0x0F12010A},   //70000D0A AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
{0x0F122401},   //70000D0C AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
{0x0F12241B},   //70000D0E AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
{0x0F121E60},   //70000D10 AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
{0x0F12FF18},   //70000D12 AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
{0x0F1208FF},   //70000D14 AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
{0x0F120008},   //70000D16 AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
{0x0F120001},   //70000D18 AFITB_bnr_nClustLevel_C      [0]   bWideWide[1]    
{0x0F120000},   //70000C64 AFIT16_BRIGHTNESS    
{0x0F120000},   //70000C66 AFIT16_CONTRAST                                                              	
{0x0F120000},   //70000C68 AFIT16_SATURATION                                                            	
{0x0F120000},   //70000C6A AFIT16_SHARP_BLUR                                                            	
{0x0F120000},   //70000C6C AFIT16_GLAMOUR                                                               	
{0x0F1200C0},   //70000C6E AFIT16_bnr_edge_high                                                         	
{0x0F120064},   //70000C70 AFIT16_postdmsc_iLowBright                                                   	
{0x0F120384},   //70000C72 AFIT16_postdmsc_iHighBright                                                  	
{0x0F120051},   //70000C74 AFIT16_postdmsc_iLowSat                                                      	
{0x0F1201F4},   //70000C76 AFIT16_postdmsc_iHighSat                                                     	
{0x0F120070},   //70000C78 AFIT16_postdmsc_iTune                                                        	
{0x0F120040},   //70000C7A AFIT16_yuvemix_mNegRanges_0                                                  	
{0x0F1200A0},   //70000C7C AFIT16_yuvemix_mNegRanges_1                                                  	
{0x0F120100},   //70000C7E AFIT16_yuvemix_mNegRanges_2                                                  	
{0x0F120010},   //70000C80 AFIT16_yuvemix_mPosRanges_0                                                  	
{0x0F120060},   //70000C82 AFIT16_yuvemix_mPosRanges_1                                                  	
{0x0F120100},   //70000C84 AFIT16_yuvemix_mPosRanges_2                                                  	
{0x0F121430},   //70000C86 AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
{0x0F120201},   //70000C88 AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
{0x0F120204},   //70000C8A AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
{0x0F121B04},   //70000C8C AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
{0x0F120312},   //70000C8E AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
{0x0F120003},   //70000C90 AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
{0x0F120C03},   //70000C92 AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
{0x0F122806},   //70000C94 AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
{0x0F120060},   //70000C96 AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
{0x0F121540},   //70000C98 AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
{0x0F12201C},   //70000C9A AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
{0x0F120620},   //70000C9C AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
{0x0F120306},   //70000C9E AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
{0x0F122003},   //70000CA0 AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
{0x0F12FF01},   //70000CA2 AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
{0x0F120404},   //70000CA4 AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
{0x0F120300},   //70000CA6 AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
{0x0F12145A},   //70000CA8 AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
{0x0F121010},   //70000CAA AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
{0x0F12000B},   //70000CAC AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
{0x0F120B00},   //70000CAE AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
{0x0F125A0F},   //70000CB0 AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
{0x0F120503},   //70000CB2 AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
{0x0F121802},   //70000CB4 AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
{0x0F120000},   //70000CB6 AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
{0x0F122006},   //70000CB8 AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
{0x0F123C28},   //70000CBA AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
{0x0F120428},   //70000CBC AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
{0x0F120101},   //70000CBE AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
{0x0F128000},   //70000CC0 AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
{0x0F121004},   //70000CC2 AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
{0x0F124008},   //70000CC4 AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
{0x0F120540},   //70000CC6 AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
{0x0F128006},   //70000CC8 AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
{0x0F120020},   //70000CCA AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
{0x0F120000},   //70000CCC AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
{0x0F121800},   //70000CCE AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
{0x0F120000},   //70000CD0 AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
{0x0F121E10},   //70000CD2 AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
{0x0F12000B},   //70000CD4 AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
{0x0F120607},   //70000CD6 AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
{0x0F120005},   //70000CD8 AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
{0x0F120607},   //70000CDA AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
{0x0F120405},   //70000CDC AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
{0x0F120205},   //70000CDE AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
{0x0F120304},   //70000CE0 AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
{0x0F120409},   //70000CE2 AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
{0x0F120306},   //70000CE4 AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
{0x0F120407},   //70000CE6 AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
{0x0F121804},   //70000CE8 AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
{0x0F120214},   //70000CEA AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
{0x0F121002},   //70000CEC AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
{0x0F120610},   //70000CEE AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
{0x0F121A02},   //70000CF0 AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
{0x0F128018},   //70000CF2 AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
{0x0F1200A0},   //70000CF4 AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
{0x0F121080},   //70000CF6 AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
{0x0F120180},   //70000CF8 AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
{0x0F120A0A},   //70000CFA AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
{0x0F120101},   //70000CFC AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
{0x0F121B24},   //70000CFE AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
{0x0F126024},   //70000D00 AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
{0x0F120C0C},   //70000D02 AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
{0x0F12FFFF},   //70000D04 AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
{0x0F120808},   //70000D06 AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
{0x0F120A01},   //70000D08 AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
{0x0F12010A},   //70000D0A AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
{0x0F121501},   //70000D0C AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
{0x0F12240F},   //70000D0E AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
{0x0F120C60},   //70000D10 AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
{0x0F12FF0C},   //70000D12 AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
{0x0F1208FF},   //70000D14 AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
{0x0F120008},   //70000D16 AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
{0x0F120001},   //70000D18 AFITB_bnr_nClustLevel_C      [0]   bWideWide[1]                                              	
{0x0F120000},   //70000C64 AFIT16_BRIGHTNESS   
{0x0F120000},   //70000C66 AFIT16_CONTRAST                                                              	
{0x0F120000},   //70000C68 AFIT16_SATURATION                                                            	
{0x0F120000},   //70000C6A AFIT16_SHARP_BLUR                                                            	
{0x0F120000},   //70000C6C AFIT16_GLAMOUR                                                               	
{0x0F1200C0},   //70000C6E AFIT16_bnr_edge_high                                                         	
{0x0F120064},   //70000C70 AFIT16_postdmsc_iLowBright                                                   	
{0x0F120384},   //70000C72 AFIT16_postdmsc_iHighBright                                                  	
{0x0F120043},   //70000C74 AFIT16_postdmsc_iLowSat                                                      	
{0x0F1201F4},   //70000C76 AFIT16_postdmsc_iHighSat                                                     	
{0x0F120070},   //70000C78 AFIT16_postdmsc_iTune                                                        	
{0x0F120040},   //70000C7A AFIT16_yuvemix_mNegRanges_0                                                  	
{0x0F1200A0},   //70000C7C AFIT16_yuvemix_mNegRanges_1                                                  	
{0x0F120100},   //70000C7E AFIT16_yuvemix_mNegRanges_2                                                  	
{0x0F120010},   //70000C80 AFIT16_yuvemix_mPosRanges_0                                                  	
{0x0F120060},   //70000C82 AFIT16_yuvemix_mPosRanges_1                                                  	
{0x0F120100},   //70000C84 AFIT16_yuvemix_mPosRanges_2                                                  	
{0x0F121430},   //70000C86 AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
{0x0F120201},   //70000C88 AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
{0x0F120204},   //70000C8A AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
{0x0F121B04},   //70000C8C AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
{0x0F120312},   //70000C8E AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
{0x0F120003},   //70000C90 AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
{0x0F120C03},   //70000C92 AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
{0x0F122806},   //70000C94 AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
{0x0F120060},   //70000C96 AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
{0x0F121540},   //70000C98 AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
{0x0F12201C},   //70000C9A AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
{0x0F120620},   //70000C9C AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
{0x0F120306},   //70000C9E AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
{0x0F122003},   //70000CA0 AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
{0x0F12FF01},   //70000CA2 AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
{0x0F120404},   //70000CA4 AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
{0x0F120300},   //70000CA6 AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
{0x0F12145A},   //70000CA8 AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
{0x0F121010},   //70000CAA AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
{0x0F12000B},   //70000CAC AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
{0x0F120E00},   //70000CAE AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
{0x0F125A0F},   //70000CB0 AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
{0x0F120503},   //70000CB2 AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
{0x0F121802},   //70000CB4 AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
{0x0F120000},   //70000CB6 AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
{0x0F122006},   //70000CB8 AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
{0x0F123C28},   //70000CBA AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
{0x0F120428},   //70000CBC AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
{0x0F120101},   //70000CBE AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
{0x0F128000},   //70000CC0 AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
{0x0F120A04},   //70000CC2 AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
{0x0F124008},   //70000CC4 AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
{0x0F120540},   //70000CC6 AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
{0x0F128006},   //70000CC8 AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
{0x0F120020},   //70000CCA AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
{0x0F120000},   //70000CCC AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
{0x0F121800},   //70000CCE AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
{0x0F120000},   //70000CD0 AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
{0x0F121E10},   //70000CD2 AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
{0x0F12000B},   //70000CD4 AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
{0x0F120607},   //70000CD6 AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
{0x0F120005},   //70000CD8 AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
{0x0F120607},   //70000CDA AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
{0x0F120405},   //70000CDC AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
{0x0F120205},   //70000CDE AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
{0x0F120304},   //70000CE0 AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
{0x0F120409},   //70000CE2 AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
{0x0F120306},   //70000CE4 AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
{0x0F120407},   //70000CE6 AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
{0x0F121804},   //70000CE8 AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
{0x0F120214},   //70000CEA AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
{0x0F121002},   //70000CEC AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
{0x0F120610},   //70000CEE AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
{0x0F121A02},   //70000CF0 AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
{0x0F128018},   //70000CF2 AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
{0x0F120080},   //70000CF4 AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
{0x0F121080},   //70000CF6 AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
{0x0F120180},   //70000CF8 AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
{0x0F120A0A},   //70000CFA AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
{0x0F120101},   //70000CFC AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
{0x0F12141D},   //70000CFE AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
{0x0F126024},   //70000D00 AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
{0x0F120C0C},   //70000D02 AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
{0x0F12FFFF},   //70000D04 AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
{0x0F120808},   //70000D06 AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
{0x0F120A01},   //70000D08 AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
{0x0F12010A},   //70000D0A AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
{0x0F121501},   //70000D0C AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
{0x0F12240F},   //70000D0E AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
{0x0F120C60},   //70000D10 AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
{0x0F12FF0C},   //70000D12 AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
{0x0F1208FF},   //70000D14 AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
{0x0F120008},   //70000D16 AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
{0x0F120001},   //70000D18 AFITB_bnr_nClustLevel_C      [0]   bWideWide[1]                                              	
{0x0F120000},   //70000C64 AFIT16_BRIGHTNESS   
{0x0F120000},   //70000C66 AFIT16_CONTRAST                                                              	
{0x0F120000},   //70000C68 AFIT16_SATURATION                                                            	
{0x0F120000},   //70000C6A AFIT16_SHARP_BLUR                                                            	
{0x0F120000},   //70000C6C AFIT16_GLAMOUR                                                               	
{0x0F1200C0},   //70000C6E AFIT16_bnr_edge_high                                                         	
{0x0F120064},   //70000C70 AFIT16_postdmsc_iLowBright                                                   	
{0x0F120384},   //70000C72 AFIT16_postdmsc_iHighBright                                                  	
{0x0F120032},   //70000C74 AFIT16_postdmsc_iLowSat                                                      	
{0x0F1201F4},   //70000C76 AFIT16_postdmsc_iHighSat                                                     	
{0x0F120070},   //70000C78 AFIT16_postdmsc_iTune                                                        	
{0x0F120040},   //70000C7A AFIT16_yuvemix_mNegRanges_0                                                  	
{0x0F1200A0},   //70000C7C AFIT16_yuvemix_mNegRanges_1                                                  	
{0x0F120100},   //70000C7E AFIT16_yuvemix_mNegRanges_2                                                  	
{0x0F120010},   //70000C80 AFIT16_yuvemix_mPosRanges_0                                                  	
{0x0F120060},   //70000C82 AFIT16_yuvemix_mPosRanges_1                                                  	
{0x0F120100},   //70000C84 AFIT16_yuvemix_mPosRanges_2                                                  	
{0x0F121430},   //70000C86 AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
{0x0F120201},   //70000C88 AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
{0x0F120204},   //70000C8A AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
{0x0F121504},   //70000C8C AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
{0x0F12030F},   //70000C8E AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
{0x0F120003},   //70000C90 AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
{0x0F120902},   //70000C92 AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
{0x0F122004},   //70000C94 AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
{0x0F120050},   //70000C96 AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
{0x0F121140},   //70000C98 AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
{0x0F12201C},   //70000C9A AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
{0x0F120620},   //70000C9C AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
{0x0F120306},   //70000C9E AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
{0x0F122003},   //70000CA0 AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
{0x0F12FF01},   //70000CA2 AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
{0x0F120404},   //70000CA4 AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
{0x0F120300},   //70000CA6 AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
{0x0F12145A},   //70000CA8 AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
{0x0F121010},   //70000CAA AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
{0x0F12000B},   //70000CAC AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
{0x0F121000},   //70000CAE AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
{0x0F125A0F},   //70000CB0 AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
{0x0F120503},   //70000CB2 AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
{0x0F121802},   //70000CB4 AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
{0x0F120000},   //70000CB6 AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
{0x0F122006},   //70000CB8 AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
{0x0F123C28},   //70000CBA AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
{0x0F12042C},   //70000CBC AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
{0x0F120101},   //70000CBE AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
{0x0F128000},   //70000CC0 AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
{0x0F120904},   //70000CC2 AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
{0x0F124008},   //70000CC4 AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
{0x0F120540},   //70000CC6 AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
{0x0F128006},   //70000CC8 AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
{0x0F120020},   //70000CCA AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
{0x0F120000},   //70000CCC AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
{0x0F121800},   //70000CCE AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
{0x0F120000},   //70000CD0 AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
{0x0F121E10},   //70000CD2 AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
{0x0F12000B},   //70000CD4 AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
{0x0F120607},   //70000CD6 AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
{0x0F120005},   //70000CD8 AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
{0x0F120607},   //70000CDA AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
{0x0F120405},   //70000CDC AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
{0x0F120205},   //70000CDE AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
{0x0F120304},   //70000CE0 AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
{0x0F120409},   //70000CE2 AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
{0x0F120306},   //70000CE4 AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
{0x0F120407},   //70000CE6 AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
{0x0F122804},   //70000CE8 AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
{0x0F120228},   //70000CEA AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
{0x0F121402},   //70000CEC AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
{0x0F120618},   //70000CEE AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
{0x0F121A02},   //70000CF0 AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
{0x0F128018},   //70000CF2 AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
{0x0F120080},   //70000CF4 AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
{0x0F121080},   //70000CF6 AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
{0x0F120180},   //70000CF8 AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
{0x0F120A0A},   //70000CFA AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
{0x0F120101},   //70000CFC AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
{0x0F121117},   //70000CFE AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
{0x0F126024},   //70000D00 AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
{0x0F120A0A},   //70000D02 AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
{0x0F12FFFF},   //70000D04 AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
{0x0F120808},   //70000D06 AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
{0x0F120A01},   //70000D08 AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
{0x0F12010A},   //70000D0A AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
{0x0F121501},   //70000D0C AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
{0x0F12240F},   //70000D0E AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
{0x0F120A60},   //70000D10 AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
{0x0F12FF0A},   //70000D12 AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
{0x0F1208FF},   //70000D14 AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
{0x0F120008},   //70000D16 AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
{0x0F120001},   //70000D18 AFITB_bnr_nClustLevel_C      [0]   bWideWide[1]                                                    	
{0x0F120000},   //70000C64 AFIT16_BRIGHTNESS    
{0x0F120000},   //70000C66 AFIT16_CONTRAST                                                              	
{0x0F120000},   //70000C68 AFIT16_SATURATION                                                            	
{0x0F120000},   //70000C6A AFIT16_SHARP_BLUR                                                            	
{0x0F120000},   //70000C6C AFIT16_GLAMOUR                                                               	
{0x0F1200C0},   //70000C6E AFIT16_bnr_edge_high                                                         	
{0x0F120064},   //70000C70 AFIT16_postdmsc_iLowBright                                                   	
{0x0F120384},   //70000C72 AFIT16_postdmsc_iHighBright                                                  	
{0x0F120032},   //70000C74 AFIT16_postdmsc_iLowSat                                                      	
{0x0F1201F4},   //70000C76 AFIT16_postdmsc_iHighSat                                                     	
{0x0F120070},   //70000C78 AFIT16_postdmsc_iTune                                                        	
{0x0F120040},   //70000C7A AFIT16_yuvemix_mNegRanges_0                                                  	
{0x0F1200A0},   //70000C7C AFIT16_yuvemix_mNegRanges_1                                                  	
{0x0F120100},   //70000C7E AFIT16_yuvemix_mNegRanges_2                                                  	
{0x0F120010},   //70000C80 AFIT16_yuvemix_mPosRanges_0                                                  	
{0x0F120060},   //70000C82 AFIT16_yuvemix_mPosRanges_1                                                  	
{0x0F120100},   //70000C84 AFIT16_yuvemix_mPosRanges_2                                                  	
{0x0F121430},   //70000C86 AFIT8_bnr_edge_low  [7:0] AFIT8_bnr_repl_thresh                              	
{0x0F120201},   //70000C88 AFIT8_bnr_repl_force  [7:0] AFIT8_bnr_iHotThreshHigh                         	
{0x0F120204},   //70000C8A AFIT8_bnr_iHotThreshLow   [7:0] AFIT8_bnr_iColdThreshHigh                    	
{0x0F120F04},   //70000C8C AFIT8_bnr_iColdThreshLow   [7:0] AFIT8_bnr_DispTH_Low                        	
{0x0F12030C},   //70000C8E AFIT8_bnr_DispTH_High   [7:0] AFIT8_bnr_DISP_Limit_Low                       	
{0x0F120003},   //70000C90 AFIT8_bnr_DISP_Limit_High   [7:0] AFIT8_bnr_iDistSigmaMin                    	
{0x0F120602},   //70000C92 AFIT8_bnr_iDistSigmaMax   [7:0] AFIT8_bnr_iDiffSigmaLow                      	
{0x0F121803},   //70000C94 AFIT8_bnr_iDiffSigmaHigh   [7:0] AFIT8_bnr_iNormalizedSTD_TH                 	
{0x0F120040},   //70000C96 AFIT8_bnr_iNormalizedSTD_Limit   [7:0] AFIT8_bnr_iDirNRTune                  	
{0x0F120E20},   //70000C98 AFIT8_bnr_iDirMinThres   [7:0] AFIT8_bnr_iDirFltDiffThresHigh                	
{0x0F122018},   //70000C9A AFIT8_bnr_iDirFltDiffThresLow   [7:0] AFIT8_bnr_iDirSmoothPowerHigh          	
{0x0F120620},   //70000C9C AFIT8_bnr_iDirSmoothPowerLow   [7:0] AFIT8_bnr_iLowMaxSlopeAllowed           	
{0x0F120306},   //70000C9E AFIT8_bnr_iHighMaxSlopeAllowed   [7:0] AFIT8_bnr_iLowSlopeThresh             	
{0x0F122003},   //70000CA0 AFIT8_bnr_iHighSlopeThresh   [7:0] AFIT8_bnr_iSlopenessTH                    	
{0x0F12FF01},   //70000CA2 AFIT8_bnr_iSlopeBlurStrength   [7:0] AFIT8_bnr_iSlopenessLimit               	
{0x0F120404},   //70000CA4 AFIT8_bnr_AddNoisePower1   [7:0] AFIT8_bnr_AddNoisePower2                    	
{0x0F120200},   //70000CA6 AFIT8_bnr_iRadialTune   [7:0] AFIT8_bnr_iRadialPower                         	
{0x0F12145A},   //70000CA8 AFIT8_bnr_iRadialLimit   [7:0] AFIT8_ee_iFSMagThLow                          	
{0x0F121010},   //70000CAA AFIT8_ee_iFSMagThHigh   [7:0] AFIT8_ee_iFSVarThLow                           	
{0x0F12000B},   //70000CAC AFIT8_ee_iFSVarThHigh   [7:0] AFIT8_ee_iFSThLow                              	
{0x0F121200},   //70000CAE AFIT8_ee_iFSThHigh   [7:0] AFIT8_ee_iFSmagPower                              	
{0x0F125A0F},   //70000CB0 AFIT8_ee_iFSVarCountTh   [7:0] AFIT8_ee_iRadialLimit                         	
{0x0F120502},   //70000CB2 AFIT8_ee_iRadialPower   [7:0] AFIT8_ee_iSmoothEdgeSlope                      	
{0x0F121802},   //70000CB4 AFIT8_ee_iROADThres   [7:0] AFIT8_ee_iROADMaxNR                              	
{0x0F120000},   //70000CB6 AFIT8_ee_iROADSubMaxNR   [7:0] AFIT8_ee_iROADSubThres                        	
{0x0F122006},   //70000CB8 AFIT8_ee_iROADNeiThres   [7:0] AFIT8_ee_iROADNeiMaxNR                        	
{0x0F124028},   //70000CBA AFIT8_ee_iSmoothEdgeThres   [7:0] AFIT8_ee_iMSharpen                         	
{0x0F120430},   //70000CBC AFIT8_ee_iWSharpen   [7:0] AFIT8_ee_iMShThresh                               	
{0x0F120101},   //70000CBE AFIT8_ee_iWShThresh   [7:0] AFIT8_ee_iReduceNegative                         	
{0x0F12FF00},   //70000CC0 AFIT8_ee_iEmbossCentAdd   [7:0] AFIT8_ee_iShDespeckle                        	
{0x0F120804},   //70000CC2 AFIT8_ee_iReduceEdgeThresh   [7:0] AFIT8_dmsc_iEnhThresh                     	
{0x0F124008},   //70000CC4 AFIT8_dmsc_iDesatThresh   [7:0] AFIT8_dmsc_iDemBlurHigh                      	
{0x0F120540},   //70000CC6 AFIT8_dmsc_iDemBlurLow   [7:0] AFIT8_dmsc_iDemBlurRange                      	
{0x0F128006},   //70000CC8 AFIT8_dmsc_iDecisionThresh   [7:0] AFIT8_dmsc_iCentGrad                      	
{0x0F120020},   //70000CCA AFIT8_dmsc_iMonochrom   [7:0] AFIT8_dmsc_iGBDenoiseVal                       	
{0x0F120000},   //70000CCC AFIT8_dmsc_iGRDenoiseVal   [7:0] AFIT8_dmsc_iEdgeDesatThrHigh                	
{0x0F121800},   //70000CCE AFIT8_dmsc_iEdgeDesatThrLow   [7:0] AFIT8_dmsc_iEdgeDesat                    	
{0x0F120000},   //70000CD0 AFIT8_dmsc_iNearGrayDesat   [7:0] AFIT8_dmsc_iEdgeDesatLimit                 	
{0x0F121E10},   //70000CD2 AFIT8_postdmsc_iBCoeff   [7:0] AFIT8_postdmsc_iGCoeff                        	
{0x0F12000B},   //70000CD4 AFIT8_postdmsc_iWideMult   [7:0] AFIT8_yuvemix_mNegSlopes_0                  	
{0x0F120607},   //70000CD6 AFIT8_yuvemix_mNegSlopes_1   [7:0] AFIT8_yuvemix_mNegSlopes_2                	
{0x0F120005},   //70000CD8 AFIT8_yuvemix_mNegSlopes_3   [7:0] AFIT8_yuvemix_mPosSlopes_0                	
{0x0F120607},   //70000CDA AFIT8_yuvemix_mPosSlopes_1   [7:0] AFIT8_yuvemix_mPosSlopes_2                	
{0x0F120405},   //70000CDC AFIT8_yuvemix_mPosSlopes_3   [7:0] AFIT8_yuviirnr_iXSupportY                 	
{0x0F120205},   //70000CDE AFIT8_yuviirnr_iXSupportUV   [7:0] AFIT8_yuviirnr_iLowYNorm                  	
{0x0F120304},   //70000CE0 AFIT8_yuviirnr_iHighYNorm   [7:0] AFIT8_yuviirnr_iLowUVNorm                  	
{0x0F120409},   //70000CE2 AFIT8_yuviirnr_iHighUVNorm   [7:0] AFIT8_yuviirnr_iYNormShift                	
{0x0F120306},   //70000CE4 AFIT8_yuviirnr_iUVNormShift   [7:0] AFIT8_yuviirnr_iVertLength_Y             	
{0x0F120407},   //70000CE6 AFIT8_yuviirnr_iVertLength_UV   [7:0] AFIT8_yuviirnr_iDiffThreshL_Y          	
{0x0F122C04},   //70000CE8 AFIT8_yuviirnr_iDiffThreshH_Y   [7:0] AFIT8_yuviirnr_iDiffThreshL_UV         	
{0x0F12022C},   //70000CEA AFIT8_yuviirnr_iDiffThreshH_UV   [7:0] AFIT8_yuviirnr_iMaxThreshL_Y          	
{0x0F121402},   //70000CEC AFIT8_yuviirnr_iMaxThreshH_Y   [7:0] AFIT8_yuviirnr_iMaxThreshL_UV           	
{0x0F120618},   //70000CEE AFIT8_yuviirnr_iMaxThreshH_UV   [7:0] AFIT8_yuviirnr_iYNRStrengthL           	
{0x0F121A02},   //70000CF0 AFIT8_yuviirnr_iYNRStrengthH   [7:0] AFIT8_yuviirnr_iUVNRStrengthL           	
{0x0F128018},   //70000CF2 AFIT8_yuviirnr_iUVNRStrengthH   [7:0] AFIT8_byr_gras_iShadingPower           	
{0x0F120080},   //70000CF4 AFIT8_RGBGamma2_iLinearity   [7:0] AFIT8_RGBGamma2_iDarkReduce               	
{0x0F121080},   //70000CF6 AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset                   	
{0x0F120180},   //70000CF8 AFIT8_RGB2YUV_iRGBGain   [7:0] AFIT8_bnr_nClustLevel_H                       	
{0x0F120A0A},   //70000CFA AFIT8_bnr_iClustMulT_H   [7:0] AFIT8_bnr_iClustMulT_C                        	
{0x0F120101},   //70000CFC AFIT8_bnr_iClustThresh_H   [7:0] AFIT8_bnr_iClustThresh_C                    	
{0x0F120C0F},   //70000CFE AFIT8_bnr_iDenThreshLow   [7:0] AFIT8_bnr_iDenThreshHigh                     	
{0x0F126024},   //70000D00 AFIT8_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower                     	
{0x0F120808},   //70000D02 AFIT8_ee_iLowShDenoise   [7:0] AFIT8_ee_iHighShDenoise                       	
{0x0F12FFFF},   //70000D04 AFIT8_ee_iLowSharpClamp   [7:0] AFIT8_ee_iHighSharpClamp                     	
{0x0F120808},   //70000D06 AFIT8_ee_iReduceEdgeMinMult   [7:0] AFIT8_ee_iReduceEdgeSlope                	
{0x0F120A01},   //70000D08 AFIT8_bnr_nClustLevel_H_Bin   [7:0] AFIT8_bnr_iClustMulT_H_Bin               	
{0x0F12010A},   //70000D0A AFIT8_bnr_iClustMulT_C_Bin   [7:0] AFIT8_bnr_iClustThresh_H_Bin              	
{0x0F120F01},   //70000D0C AFIT8_bnr_iClustThresh_C_Bin   [7:0] AFIT8_bnr_iDenThreshLow_Bin             	
{0x0F12240C},   //70000D0E AFIT8_bnr_iDenThreshHigh_Bin   [7:0] AFIT8_ee_iLowSharpPower_Bin             	
{0x0F120860},   //70000D10 AFIT8_ee_iHighSharpPower_Bin   [7:0] AFIT8_ee_iLowShDenoise_Bin              	
{0x0F12FF08},   //70000D12 AFIT8_ee_iHighShDenoise_Bin   [7:0] AFIT8_ee_iLowSharpClamp_Bin              	
{0x0F1208FF},   //70000D14 AFIT8_ee_iHighSharpClamp_Bin   [7:0] AFIT8_ee_iReduceEdgeMinMult_Bin         	
{0x0F120008},   //70000D16 AFIT8_ee_iReduceEdgeSlope_Bin [7:0]                                          	
{0x0F120001},   //70000D18 AFITB_bnr_nClustLevel_C      [0]   bWideWide[1]  

	// FOR HD CAMCORDER

{0x002A0250},
{0x0F120A00},	/* #REG_TC_GP_PrevReqInputWidth */
{0x0F120780},	/* #REG_TC_GP_PrevReqInputHeight */
{0x0F120010},	/* #REG_TC_GP_PrevInputWidthOfs	*/
{0x0F12000C},	/* #REG_TC_GP_PrevInputHeightOfs */
{0x002A0494},
{0x0F120A00},	/* #REG_TC_PZOOM_PrevZoomReqInputWidth */
{0x0F120780},	/* #REG_TC_PZOOM_PrevZoomReqInputHeight	*/
{0x0F120000},	/* #REG_TC_PZOOM_PrevZoomReqInputWidthOfs	*/
{0x0F120000},	/* #REG_TC_PZOOM_PrevZoomReqInputHeightOfs */
{0x002A0262},
{0x0F120001},	/* #REG_TC_GP_bUseReqInputInPre	*/

{0x002A02A6},
{0x0F120280},
{0x0F1201E0},
{0x0F120005},
{0x002A0266},
{0x0F120000},
{0x002A026A},
{0x0F120001},
{0x002A024E},
{0x0F120001},	/* #REG_TC_GP_NewConfigSync */
{0x002A0268},
{0x0F120001},	/* #REG_TC_GP_CapConfigChanged */

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_FRAMERATE_5FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_5[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_FRAMERATE_7FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_7[]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_10FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_10[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_15FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_15[]
#if defined(_CAMACQ_API_C_)
={
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_20FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_20[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_25FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_25[]
#if defined(_CAMACQ_API_C_)
={
    {0xFCFCD000},
    {0x0028D000},
    {0x002AF132},
    {0x0F120406},
    {0x002AF142},
    {0x0F120000},//110404 AE haunting
    {0x00287000},
    {0x002A02B4},
    {0x0F120042},
    {0x002A02BE},
    {0x0F120000},   //REG_0TC_PCFG_usFrTimeType
    {0x0F120001},   //REG_0TC_PCFG_FrRateQualityType
    {0x0F120190}, //REG_0TC_PCFG_usMaxFrTimeMsecMult10 //0190h:25fps
    {0x0F120190}, //REG_0TC_PCFG_usMinFrTimeMsecMult10 //0190h:25fps

    {0x002A0266},
    {0x0F120000},   //REG_TC_GP_ActivePrevConfig
    {0x002A026A},
    {0x0F120001},   //REG_TC_GP_PrevOpenAfterChange
    {0x002A024E},
    {0x0F120001},   //REG_TC_GP_NewConfigSync
    {0x002A0268},
    {0x0F120001},   //REG_TC_GP_PrevConfigChanged
CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_30FPS
//==========================================================
GLOBAL const U32 reg_main_fps_fixed_30[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x0028D000},
{0x002AF132},
{0x0F120406},
{0x002AF142},
{0x0F120000},//110404 AE haunting
{0x00287000},
{0x002A02B4},
{0x0F120042},
{0x002A02BE},
{0x0F120000},	//REG_0TC_PCFG_usFrTimeType
{0x0F120001},	//REG_0TC_PCFG_FrRateQualityType
{0x0F12014E}, //REG_0TC_PCFG_usMaxFrTimeMsecMult10 //014Ah:30fps
{0x0F12014E}, //REG_0TC_PCFG_usMinFrTimeMsecMult10 //014Ah:30fps

{0x002A0266},
{0x0F120000},	//REG_TC_GP_ActivePrevConfig
{0x002A026A},
{0x0F120001},	//REG_TC_GP_PrevOpenAfterChange
{0x002A024E},
{0x0F120001},	//REG_TC_GP_NewConfigSync
{0x002A0268},
{0x0F120001},	//REG_TC_GP_PrevConfigChanged
	CAMACQ_MAIN_BTM_OF_DATA


}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_FRAMERATE_AUTO_MAX15(5~15fps)
//==========================================================
GLOBAL const U32 reg_main_fps_var_15[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_BRIGHTNESS_LEVEL1 (1/9) :
//==========================================================
GLOBAL const U32 reg_main_brightness_level_0[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F120018},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL2 (2/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_1[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F12001E},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL3 (3/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_2[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F120025},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL4 (4/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_3[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F120030},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL5 (5/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_4[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F12003C},	//TVAR_ae_BrAve

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL6 (6/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_5[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F12004E},	//TVAR_ae_BrAve
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL7 (7/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_6[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F120060},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL8 (8/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_7[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F120070},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_BRIGHTNESS_LEVEL9 (9/9)
//==========================================================
GLOBAL const U32 reg_main_brightness_level_8[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F120080},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMCORDER_BRIGHTNESS_LEVEL1 (1/9) :
//==========================================================
GLOBAL const U32 reg_main_ccd_brightness_level_0[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F12000A},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMCORDER_BRIGHTNESS_LEVEL2 (2/9)
//==========================================================
GLOBAL const U32 reg_main_ccd_brightness_level_1[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F120012},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMCORDER_BRIGHTNESS_LEVEL3 (3/9)
//==========================================================
GLOBAL const U32 reg_main_ccd_brightness_level_2[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F12001A},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMCORDER_BRIGHTNESS_LEVEL4 (4/9)
//==========================================================
GLOBAL const U32 reg_main_ccd_brightness_level_3[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F120022},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMCORDER_BRIGHTNESS_LEVEL5 (5/9)
//==========================================================
GLOBAL const U32 reg_main_ccd_brightness_level_4[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F12002A},	//TVAR_ae_BrAve

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMCORDER_BRIGHTNESS_LEVEL6 (6/9)
//==========================================================
GLOBAL const U32 reg_main_ccd_brightness_level_5[]
#if defined(_CAMACQ_API_C_)
={
0xFCFCD000,
0x00287000,
0x002A1484,
0x0F120037,		//REG_TC_UserBrightness 
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMCORDER_BRIGHTNESS_LEVEL7 (7/9)
//==========================================================
GLOBAL const U32 reg_main_ccd_brightness_level_6[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F120044},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMCORDER_BRIGHTNESS_LEVEL8 (8/9)
//==========================================================
GLOBAL const U32 reg_main_ccd_brightness_level_7[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F120051},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMCORDER_BRIGHTNESS_LEVEL9 (9/9)
//==========================================================
GLOBAL const U32 reg_main_ccd_brightness_level_8[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F12005E},	//TVAR_ae_BrAve
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL1 (1/9) :
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_0[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL2 (2/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_1[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL3 (3/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_2[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL4 (4/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_3[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL5 (5/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_4[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL6 (6/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_5[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL7 (7/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_6[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL8 (8/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_7[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_EXPOSURE_COMPENSATION_LEVEL9 (9/9)
//==========================================================
GLOBAL const U32 reg_main_expcompensation_level_8[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_AWB
//==========================================================

GLOBAL const u32 reg_main_set_ae_lock []
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A2C5E},
{0x0F120000},
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const u32 reg_main_set_ae_unlock []
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A2C5E},
{0x0F120001},
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const u32 reg_main_set_awb_lock []
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A2C66},
{0x0F120000},
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const u32 reg_main_set_awb_unlock []
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A2C66},
{0x0F120001},
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;
//==========================================================
// CAMERA_AF
//==========================================================
GLOBAL const U32 reg_main_reset_af []
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_nlux []
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_llux []
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af[] // start_af
#if defined(_CAMACQ_API_C_)
={
/*
{0xfcfc, 0xd000},
{0x0028, 0x7000},
{0x002A, 0x0254},   //Lens position setting
{0x0F12, 0x0000},
{0xffff, 0x0085},   //delay 133ms
{0x002A, 0x0252},   //Lens move
{0x0F12, 0x0004},
{0xffff, 0x00C8},   //delay 200ms
{0x002A, 0x10D4},   //AF Mode
{0x0F12, 0x1000},   //Normal af mode*/
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const u32 reg_main_single_af_start[] 
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A028C},
{0x0F120005},	//REG_TC_AF_AfCmd
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U32 reg_main_off_af[]
#if defined(_CAMACQ_API_C_)
={
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U32 reg_main_check_af[]
#if defined(_CAMACQ_API_C_)
={
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_manual_af[]
#if defined(_CAMACQ_API_C_)
={
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_macro_af[]
#if defined(_CAMACQ_API_C_)
={
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_return_manual_af[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_return_macro_af[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_normal_mode_1[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A028E},
{0x0F120000},	//REG_TC_AF_AfCmdParam

{0x002A0294},
{0x0F120100}, //REG_TC_AF_FstWinStartX
{0x0F1200E3}, //REG_TC_AF_FstWinStartY
{0x0F120200}, //REG_TC_AF_FstWinSizeX
{0x0F120238}, //REG_TC_AF_FstWinSizeY
{0x0F1201C6},  // LSI_Cho AF Window Center from_LSI
{0x0F120166}, //REG_TC_AF_ScndWinStartY
{0x0F120074},  // LSI_Cho AF Fail when Size change from_LSI
{0x0F120132}, //REG_TC_AF_ScndWinSizeY
{0x0F120001}, //REG_TC_AF_WinSizesUpdated


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_normal_mode_2[]
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A028C},
{0x0F120004},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_normal_mode_3[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1648},
{0x0F129002},

{0x002A15E8},
{0x0F120018},   //af_pos_usTableLastInd SEHF_CHECK_IT
{0x0F12002A},
{0x0F120030},
{0x0F120036},
{0x0F12003C},
{0x0F120042},
{0x0F120048},
{0x0F12004E},
{0x0F120054},
{0x0F12005A},
{0x0F120060},
{0x0F120066},
{0x0F12006C},
{0x0F120072},
{0x0F120078},
{0x0F12007E},
{0x0F120084},
{0x0F12008A},
{0x0F120090},
{0x0F120096},
{0x0F12009C},
{0x0F1200A2},
{0x0F1200A8},
{0x0F1200AE},
{0x0F1200B4},
{0x0F1200BA},


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_macro_mode_1[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A028E},
{0x0F1200D0},	//REG_TC_AF_AfCmdParam

{0x002A0294},
{0x0F120100}, //REG_TC_AF_FstWinStartX
{0x0F1200E3}, //REG_TC_AF_FstWinStartY
{0x0F120200}, //REG_TC_AF_FstWinSizeX
{0x0F120238}, //REG_TC_AF_FstWinSizeY
{0x0F1201C6},  // LSI_Cho AF Window Center from_LSI
{0x0F120166}, //REG_TC_AF_ScndWinStartY
{0x0F120074},  // LSI_Cho AF Fail when Size change from_LSI
{0x0F120132}, //REG_TC_AF_ScndWinSizeY
{0x0F120001}, //REG_TC_AF_WinSizesUpdated


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_macro_mode_2[]
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A028C},
{0x0F120004},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_set_af_macro_mode_3[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1648},
{0x0F129042},

{0x002A15E8},
{0x0F120018},   //af_pos_usTableLastInd SEHF_CHECK_IT
{0x0F12002A},
{0x0F120030},
{0x0F120036},
{0x0F12003C},
{0x0F120042},
{0x0F120048},
{0x0F12004E},
{0x0F120054},
{0x0F12005A},
{0x0F120060},
{0x0F120066},
{0x0F12006C},
{0x0F120072},
{0x0F120078},
{0x0F12007E},
{0x0F120084},
{0x0F12008A},
{0x0F120090},
{0x0F120096},
{0x0F12009C},
{0x0F1200A2},
{0x0F1200A8},
{0x0F1200AE},
{0x0F1200B4},
{0x0F1200BA},

{0x002A15DA},
{0x0F121800},   // 16 start number of table 00 End number of table
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ISO_AUTO
//==========================================================
GLOBAL const U32 reg_main_iso_auto[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0938},  /* afit_bUseNB_Afit */
{0x0F120000},
{0x0F120014}, /* SARR_uNormBrInDoor_0_ */
{0x0F1200D2}, /* SARR_uNormBrInDoor_1_ */
{0x0F120384}, /* SARR_uNormBrInDoor_2_ */
{0x0F1207D0}, /* SARR_uNormBrInDoor_3_ */
{0x0F121388}, /* SARR_uNormBrInDoor_4_ */


{0x002A0F2A},   /* AFC_Default60Hz */
{0x0F120000},   /* 00:50Hz 01:60Hz */

{0x002A04D0},
{0x0F120000},
{0x0F120000},
{0x0F120001},

{0x002A06C2},
{0x0F120200}, 

	CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ISO_50
//==========================================================
GLOBAL const U32 reg_main_iso_50[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0938},
{0x0F120001},	//afit_bUseNB_Afit
{0x0F120014},	//SARR_uNormBrInDoor_0_ 
{0x0F1200D2},	//SARR_uNormBrInDoor_1_ 
{0x0F120384},	//SARR_uNormBrInDoor_2_ 
{0x0F1207D0},	//SARR_uNormBrInDoor_3_ 
{0x0F121388},	//SARR_uNormBrInDoor_4_ 

{0x002A04D6},   
{0x0F120000},	//REG_SF_USER_FlickerQuant
{0x0F120001},	//REG_SF_USER_FlickerQuantChanged
    
{0x002A04D0},   
{0x0F120001},	//REG_SF_USER_IsoType
{0x0F120100},	//REG_SF_USER_IsoVal
{0x0F120001},	//REG_SF_USER_IsoChanged
{0x002A06C2},    
{0x0F120100},	//lt_bUseSecISODgain
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ISO_100
//==========================================================
GLOBAL const U32 reg_main_iso_100[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0938},
{0x0F120001},	//afit_bUseNB_Afit
{0x0F120014},	//SARR_uNormBrInDoor_0_ 
{0x0F1200D2},	//SARR_uNormBrInDoor_1_ 
{0x0F120384},	//SARR_uNormBrInDoor_2_ 
{0x0F1207D0},	//SARR_uNormBrInDoor_3_ 
{0x0F121388},	//SARR_uNormBrInDoor_4_ 

{0x002A04D6},   
{0x0F120000},	//REG_SF_USER_FlickerQuant
{0x0F120001},	//REG_SF_USER_FlickerQuantChanged
    
{0x002A04D0},   
{0x0F120001},	//REG_SF_USER_IsoType
{0x0F1201A0},   //REG_SF_USER_IsoVal     
{0x0F120001},	//REG_SF_USER_IsoChanged
{0x002A06C2},    
{0x0F120100},	//lt_bUseSecISODgain
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ISO_200
//==========================================================
GLOBAL const U32 reg_main_iso_200[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0938},
{0x0F120001},	//afit_bUseNB_Afit
{0x0F120114},   //SARR_uNormBrInDoor_0_
{0x0F1203A2},   //SARR_uNormBrInDoor_1_
{0x0F120484},   //SARR_uNormBrInDoor_2_
{0x0F1205D0},   //SARR_uNormBrInDoor_3_
{0x0F121388},	//SARR_uNormBrInDoor_4_ 

{0x002A04D6},
{0x0F120000},	//REG_SF_USER_FlickerQuant
{0x0F120001},	//REG_SF_USER_FlickerQuantChanged
    
{0x002A04D0},   
{0x0F120001},	//REG_SF_USER_IsoType
{0x0F120320},   //REG_SF_USER_IsoVal     
{0x0F120001},	//REG_SF_USER_IsoChanged
{0x002A06C2},    
{0x0F120100},	//lt_bUseSecISODgain
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ISO_400
//==========================================================
GLOBAL const U32 reg_main_iso_400[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0938},
{0x0F120001},	//afit_bUseNB_Afit
{0x0F120114},   /* SARR_uNormBrInDoor_0_  */
{0x0F1204A2},   /* SARR_uNormBrInDoor_1_  */
{0x0F120584},	//SARR_uNormBrInDoor_2_ 
{0x0F1206D0},	//SARR_uNormBrInDoor_3_ 
{0x0F121388},	//SARR_uNormBrInDoor_4_ 

{0x002A04D6},   
{0x0F120000},	//REG_SF_USER_FlickerQuant
{0x0F120001},	//REG_SF_USER_FlickerQuantChanged

{0x002A04D0},  
{0x0F120001},	//REG_SF_USER_IsoType
{0x0F120640},   //REG_SF_USER_IsoVal     
{0x0F120001},	//REG_SF_USER_IsoChanged
{0x002A06C2},  
{0x0F120100},	//lt_bUseSecISODgain
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ISO_800
//==========================================================
GLOBAL const U32 reg_main_iso_800[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ISO_1600
//==========================================================
GLOBAL const U32 reg_main_iso_1600[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ISO_3200
//==========================================================
GLOBAL const U32 reg_main_iso_3200[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_AUTO (OFF)
//==========================================================
GLOBAL const U32 reg_main_scene_auto[]
#if defined(_CAMACQ_API_C_)
={{0xFCFCD000},
{0x00287000}, //scene Backlight landscape
{0x002A1492},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120101},
{0x0F120202},
{0x0F120202},
{0x0F120101},
{0x0F120201},
{0x0F120202},
{0x0F120202},
{0x0F120102},
{0x0F120201},
{0x0F120302},
{0x0F120203},
{0x0F120102},
{0x0F120201},
{0x0F120302},
{0x0F120203},
{0x0F120102},
{0x0F120101},
{0x0F120202},
{0x0F120202},
{0x0F120101},
{0x0F120101},
{0x0F120201},
{0x0F120102},
{0x0F120101},
{0x0F120100},
{0x0F120101},
{0x0F120101},
{0x0F120001},
	//scene Backlight landscape end
{0x002A0F2A},   //AFC_Default60Hz     
{0x0F120000},   //00:50Hz 01:60Hz   

	//Scene_Duskdawn Candle_LightSunset
{0x002A04E6},
{0x0F12077F},
	//Scene_Duskdawn Candle_LightSunset end

	//Beach_Snow
{0x002A1484},
{0x0F12003C},
	//Beach_Snow End

	//NightShot
{0x002A06B8},
{0x0F12452C},
{0x0F120005},

{0x002A0608},
{0x0F120001},
{0x0F120001},

{0x002A058C},
{0x0F123520},
{0x0F120000},
{0x0F12C350},
{0x0F120000},
{0x0F123520},
{0x0F120000},
{0x0F12C350},
{0x0F120000},
{0x0F120470},
{0x0F120C00},
{0x0F120100},
{0x0F121000},

{0x002A02C2}, 
{0x0F1203E8},
{0x0F12014A},

{0x002A0A1E},
{0x0F120348},   //AFIT8_ccm_oscar_iSaturation   [7:0] AFIT8_RGB2YUV_iYOffset
	//Night End

	//Scene portrait landscape Text default
{0x002A0A28},   //Sharpness_Default
{0x0F126024},
{0x002A0ADE},
{0x0F126024},
{0x002A0B94},
{0x0F126024},
{0x002A0C4A},
{0x0F126024},
{0x002A0D00},
{0x0F126024},
	//Scene portrait Text default end

{0x002A0234},   //Saturation_Default
{0x0F120000},
	//Scene landscape party_indoor Fall_Color default end

	//Fireworks
{0x002A03B4},
{0x0F120535},
{0x0F12029A},

//AE Concept	
{0x002A0608},                                	
{0x0F120001}, 	//lt_ExpGain_uSubsamplingmode
{0x0F120001},	//lt_ExpGain_uNonSubsampling
	
//Exposure	
{0x002A0610},	//lt_ExpGain_ExpCurveGainMaxStr_0__ulExpIn_0
{0x0F120001},
{0x0F120000},	
{0x0F120A3C},	
{0x0F120000},	
{0x0F120D05},	
{0x0F120000},	
{0x0F124008},	
{0x0F120000},	
{0x0F127000},	
{0x0F120000},	
{0x0F129C00},	
{0x0F120000},	
{0x0F12AD00},	
{0x0F120001},	
{0x0F12F1D4},	
{0x0F120002},	
{0x0F12DC00},	
{0x0F120005},	
{0x0F12DC00},	
{0x0F120005},	

{0x002A0638}, 
{0x0F120001}, 
{0x0F120000},   //lt_ExpGain_ExpCurveGainMaxStr_0__ulExpOut_0_
{0x0F120A3C}, 
{0x0F120000}, 
{0x0F120D05}, 
{0x0F120000}, 
{0x0F123408}, 
{0x0F120000}, 
{0x0F123408}, 
{0x0F120000}, 
{0x0F126810}, 
{0x0F120000}, 
{0x0F128214}, 
{0x0F120000}, 
{0x0F12C350},
{0x0F120000},
{0x0F12C350},
{0x0F120000},
{0x0F12C350},
{0x0F120000},

	//Party_Indoor Beach_Snow
{0x002A0938},
{0x0F120000},

{0x002A04D0},
{0x0F120000},
{0x0F120000},
{0x0F120001},

{0x002A06C2},                          
{0x0F120200},   //lt_bUseSecISODgain 

{0x002A060C},
{0x0F120800}, // lt_ExpGain_ExpCurveGainMaxStr_0__uMaxAnGain 
	//Party_Indoor Beach_Snow emd
	//Sports mode end


{0x002A023C},   //Effect_Normal
{0x0F120000},

{0x002A0232},   //Contrast_Default
{0x0F120000},

{0x002A1BEA},
{0x0F120001},   //Auto Contrast Off

{0x002A0266},
{0x0F120000},
{0x002A026A},
{0x0F120001},
{0x002A024E},
{0x0F120001},
{0x002A0268},
{0x0F120001},
{0x002A0270},
{0x0F120001},
{0x002A023E},
{0x0F120001},
{0x0F120001},

{0x002A1648},
{0x0F129002},   // 2nd search on when 2nd search lens oppsite direction moving

{0x002A15E8},
{0x0F120018},   //af_pos_usTableLastInd SEHF_CHECK_IT
{0x0F12002A},
{0x0F120030},
{0x0F120036},
{0x0F12003C},
{0x0F120042},
{0x0F120048},
{0x0F12004E},
{0x0F120054},
{0x0F12005A},
{0x0F120060},
{0x0F120066},
{0x0F12006C},
{0x0F120072},
{0x0F120078},
{0x0F12007E},
{0x0F120084},
{0x0F12008A},
{0x0F120090},
{0x0F120096},
{0x0F12009C},
{0x0F1200A2},
{0x0F1200A8},
{0x0F1200AE},
{0x0F1200B4},
{0x0F1200BA},
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_NIGHT
//==========================================================
GLOBAL const U32 reg_main_scene_night[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A06B8},
{0x0F12FFFF},
{0x0F1200FF},

{0x002A0608},
{0x0F120000},
{0x0F120000},

{0x002A058C},
{0x0F12F424},
{0x0F120001},
{0x0F12D090},
{0x0F120007},
{0x0F12F424},
{0x0F120001},
{0x0F12D090},
{0x0F120007},
{0x0F120100},
{0x0F120800},
{0x0F120100},
{0x0F122000},

{0x002A03B4},
{0x0F121388},
{0x0F121388},
{0x002A02C2},
{0x0F1207D0},
{0x0F12014A},
{0x002A0266},
{0x0F120000},
{0x002A026A},
{0x0F120001},
{0x002A024E},
{0x0F120001},
{0x002A0268},
{0x0F120001},
{0x002A0270},
{0x0F120001},
{0x002A023E},
{0x0F120001},
{0x0F120001},

{0x002A0A1E},
{0x0F121580},

{0x002A1648},   //1st scan only
{0x0F129000},

{0x002A15E8},
{0x0F120006},	//#af_pos_usTableLastInd//
{0x0F120036},
{0x0F12003A},
{0x0F120040},
{0x0F120048},
{0x0F120050},
{0x0F120058},
{0x0F120060},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U32 reg_main_scene_night_dark[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
               // 0x002A04E6 S/W Program
               // 0x0F120777
{0x002A04BA},
{0x0F120505},

{0x002A04BE},
{0x0F120400},

{0x002A04C2},
{0x0F120875},

{0x002A04C6},
{0x0F120001},
		CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_LANDSCAPE
//==========================================================
GLOBAL const U32 reg_main_scene_landscape[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A06B8},
{0x0F12FFFF},
{0x0F1200FF},

{0x002A0608},
{0x0F120000},
{0x0F120000},

{0x002A058C},
{0x0F12F424},
{0x0F120001},
{0x0F12D090},
{0x0F120007},
{0x0F12F424},
{0x0F120001},
{0x0F12D090},
{0x0F120007},
{0x0F120100},
{0x0F120800},
{0x0F120100},
{0x0F122000},

{0x002A03B4},
{0x0F121388},
{0x0F121388},
{0x002A02C2},
{0x0F1209C4},
{0x0F12014A},
{0x002A0266},
{0x0F120000},
{0x002A026A},
{0x0F120001},
{0x002A024E},
{0x0F120001},
{0x002A0268},
{0x0F120001},
{0x002A0270},
{0x0F120001},
{0x002A023E},
{0x0F120001},
{0x0F120001},

{0x002A0A1E},
{0x0F121580},

{0x002A1648},   //1st scan only
{0x0F129000},

{0x002A15E8},
{0x0F120006},	//#af_pos_usTableLastInd//
{0x0F120036},
{0x0F12003A},
{0x0F120040},
{0x0F120048},
{0x0F120050},
{0x0F120058},
{0x0F120060},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_SUNSET
//==========================================================
GLOBAL const U32 reg_main_scene_sunset[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A04BA},
{0x0F1205E0},

{0x002A04BE},
{0x0F120400},

{0x002A04C2},
{0x0F120530},

{0x002A04C6},
{0x0F120001},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_PORTRAIT
//==========================================================
GLOBAL const U32 reg_main_scene_portrait[]
#if defined(_CAMACQ_API_C_)
={

{0xFCFCD000},
{0x00287000},
{0x002A0A28},
{0x0F124020},
{0x002A0ADE},
{0x0F124020},
{0x002A0B94},
{0x0F124020},
{0x002A0C4A},
{0x0F124020},
{0x002A0D00},
{0x0F124020},
CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_SUNRISE
//==========================================================
GLOBAL const U32 reg_main_scene_sunrise[]
#if defined(_CAMACQ_API_C_)
={

{0xFCFCD000},
{0x00287000},
{0x002A04BA},
{0x0F120505},

{0x002A04BE},
{0x0F120400},

{0x002A04C2},
{0x0F120875},

{0x002A04C6},
{0x0F120001},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_INDOOR // == PARTY
//==========================================================
GLOBAL const U32 reg_main_scene_indoor[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0938},
{0x0F120001}, //afit_bUseNB_Afit

{0x002A04D6},
{0x0F120000}, //REG_SF_USER_FlickerQuant       
{0x0F120001}, //REG_SF_USER_FlickerQuantChanged

{0x002A04D0},
{0x0F120001}, //REG_SF_USER_IsoType    
{0x0F120340}, //REG_SF_USER_IsoVal     
{0x0F120001}, //REG_SF_USER_IsoChanged 
{0x002A06C2},                          
{0x0F120100}, //lt_bUseSecISODgain  

{0x002A0234},
{0x0F120030},
	CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_PARTY // == INDOOR
//==========================================================
GLOBAL const U32 reg_main_scene_party[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0938},
{0x0F120001}, //afit_bUseNB_Afit

{0x002A04D6},
{0x0F120000}, //REG_SF_USER_FlickerQuant       
{0x0F120001}, //REG_SF_USER_FlickerQuantChanged

{0x002A04D0},
{0x0F120001}, //REG_SF_USER_IsoType    
{0x0F120340}, //REG_SF_USER_IsoVal     
{0x0F120001}, //REG_SF_USER_IsoChanged 
{0x002A06C2},                          
{0x0F120100}, //lt_bUseSecISODgain  

{0x002A0234},
{0x0F120030},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_SPORTS
//==========================================================
GLOBAL const U32 reg_main_scene_sports[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},

{0x002A060C},
{0x0F120200},

{0x002A06B8},
{0x0F126828},
{0x0F120000},

{0x002A0938},
{0x0F120001},	//afit_bUseNB_Afit

{0x002A04D0},
{0x0F120001},	//REG_SF_USER_IsoType
{0x0F120200},	//REG_SF_USER_IsoVal
{0x0F120001},	//REG_SF_USER_IsoChanged
{0x002A06C2},
{0x0F120200},	//lt_bUseSecISODgain
  
{0x002A0266},
{0x0F120000},
{0x002A026A},
{0x0F120001},
{0x002A024E},
{0x0F120001},
{0x002A0268},
{0x0F120001},
{0x002A0270},
{0x0F120001},
{0x002A023E},
{0x0F120001},
{0x0F120001},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_BEACH
//==========================================================
GLOBAL const U32 reg_main_scene_beach[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F120045},   //TVAR_ae_BrAve

{0x002A0938},
{0x0F120001}, //afit_bUseNB_Afit

{0x002A04D6},
{0x0F120000}, //REG_SF_USER_FlickerQuant       
{0x0F120001}, //REG_SF_USER_FlickerQuantChanged

{0x002A04D0},
{0x0F120001}, //REG_SF_USER_IsoType    
{0x0F1200D0}, //REG_SF_USER_IsoVal     
{0x0F120001}, //REG_SF_USER_IsoChanged 
{0x002A06C2},                          
{0x0F120100}, //lt_bUseSecISODgain  

{0x002A0234},
{0x0F120030},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_SNOW
//==========================================================
GLOBAL const U32 reg_main_scene_snow[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1484},
{0x0F120045},   //TVAR_ae_BrAve

{0x002A0938},
{0x0F120001}, //afit_bUseNB_Afit

{0x002A04D6},
{0x0F120000}, //REG_SF_USER_FlickerQuant       
{0x0F120001}, //REG_SF_USER_FlickerQuantChanged

{0x002A04D0},
{0x0F120001}, //REG_SF_USER_IsoType    
{0x0F1200D0}, //REG_SF_USER_IsoVal     
{0x0F120001}, //REG_SF_USER_IsoChanged 
{0x002A06C2},                          
{0x0F120100}, //lt_bUseSecISODgain  

{0x002A0234},
{0x0F120030},

	CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_FALLCOLOR
//==========================================================
GLOBAL const U32 reg_main_scene_fallcolor[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0234},
{0x0F120060},
	CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_FIREWORKS
//==========================================================
GLOBAL const U32 reg_main_scene_fireworks[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0638},
{0x0F120001},
{0x0F120000},
{0x002A063C},
{0x0F121478},
{0x0F120000},
{0x002A0640},
{0x0F121A0A},
{0x0F120000},
{0x002A0644},
{0x0F126810},
{0x0F120000},
{0x002A0648},
{0x0F126810},
{0x0F120000},
{0x002A064C},
{0x0F12D020},
{0x0F120000},
{0x002A0650},
{0x0F120428},
{0x0F120001},
{0x002A0654},
{0x0F121A80},
{0x0F120006},
{0x002A0658},
{0x0F121A80},
{0x0F120006},
{0x002A065C},
{0x0F121A80},
{0x0F120006},

{0x002A03B4},
{0x0F122710},
{0x0F122710},
{0x002A02C2},
{0x0F1203E8},
{0x0F12014A},

{0x002A0266},
{0x0F120000},
{0x002A026A},
{0x0F120001},
{0x002A024E},
{0x0F120001},
{0x002A0268},
{0x0F120001},
{0x002A0270},
{0x0F120001},
{0x002A023E},
{0x0F120001},
{0x0F120001},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_CANDLELIGHT
//==========================================================
GLOBAL const U32 reg_main_scene_candlelight[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A04BA},
{0x0F1205E0},

{0x002A04BE},
{0x0F120400},

{0x002A04C2},
{0x0F120530},

{0x002A04C6},
{0x0F120001},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_AGAINSTLIGHT (BACKLight??)
//==========================================================
GLOBAL const U32 reg_main_scene_againstlight[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1492},
{0x0F120000},	//ae_WeightTbl_16
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120101},
{0x0F120101},
{0x0F120000},
{0x0F120000},
{0x0F120F01},
{0x0F12010F},
{0x0F120000},
{0x0F120000},
{0x0F120F01},
{0x0F12010F},
{0x0F120000},
{0x0F120000},
{0x0F120101},
{0x0F120101},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
{0x0F120000},
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_SCENE_TEXT
//==========================================================
GLOBAL const U32 reg_main_scene_text[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A1648},   //Scna direction macro->inf
{0x0F129042},
{0x002A0A28},
{0x0F12A060},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower
{0x002A0ADE},
{0x0F12A060},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower
{0x002A0B94},
{0x0F12A060},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower
{0x002A0C4A},
{0x0F12A060},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower
{0x002A0D00},
{0x0F12A060},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_M2
//==========================================================
GLOBAL const U32 reg_main_adjust_contrast_m2[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0232},
{0x0F12FFC0},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_M1
//==========================================================
GLOBAL const U32 reg_main_adjust_contrast_m1[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0232},
{0x0F12FFE0},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_DEFAULT
//==========================================================
GLOBAL const U32 reg_main_adjust_contrast_default[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0232},
{0x0F120000},
	CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_P1
//==========================================================
GLOBAL const U32 reg_main_adjust_contrast_p1[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0232},
{0x0F120020},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_CONTRAST_P2
//==========================================================
GLOBAL const U32 reg_main_adjust_contrast_p2[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0232},
{0x0F120040},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SHARPNESS_M2
//==========================================================
GLOBAL const U32 reg_main_adjust_sharpness_m2[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0A28},
{0x0F122010},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0ADE},
{0x0F122010},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0B94},
{0x0F122010},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0C4A},
{0x0F122010},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0D00},
{0x0F122010},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SHARPNESS_M1
//==========================================================
GLOBAL const U32 reg_main_adjust_sharpness_m1[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0A28},
{0x0F124020},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0ADE},
{0x0F124020},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0B94},
{0x0F124020},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0C4A},
{0x0F124020},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0D00},
{0x0F124020},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ADJUST_SHARPNESS_DEFAULT
//==========================================================
GLOBAL const U32 reg_main_adjust_sharpness_default[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0A28},
{0x0F126024},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0ADE},
{0x0F126024},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0B94},
{0x0F126024},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0C4A},
{0x0F126024},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0D00},
{0x0F126024},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ADJUST_SHARPNESS_P1
//==========================================================
GLOBAL const U32 reg_main_adjust_sharpness_p1[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0A28},
{0x0F128040},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0ADE},
{0x0F128040},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0B94},
{0x0F128040},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0C4A},
{0x0F128040},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0D00},
{0x0F128040},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_ADJUST_SHARPNESS_P2
//==========================================================
GLOBAL const U32 reg_main_adjust_sharpness_p2[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A0A28},
{0x0F12A060},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0ADE},
{0x0F12A060},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0B94},
{0x0F12A060},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0C4A},
{0x0F12A060},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
{0x002A0D00},
{0x0F12A060},	//_ee_iLowSharpPower   [7:0] AFIT8_ee_iHighSharpPower 
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_M2
//==========================================================
GLOBAL const U32 reg_main_adjust_saturation_m2[]
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A0234},
{0x0F12FF81},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_M1
//==========================================================
GLOBAL const U32 reg_main_adjust_saturation_m1[]
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A0234},
{0x0F12FFC0},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_DEFAULT
//==========================================================
GLOBAL const U32 reg_main_adjust_saturation_default[]
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A0234},
{0x0F120000},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_P1
//==========================================================
GLOBAL const U32 reg_main_adjust_saturation_p1[]
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A0234},
{0x0F120040},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_ADJUST_SATURATION_P2
//==========================================================
GLOBAL const U32 reg_main_adjust_saturation_p2[]
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A0234},
{0x0F12007F},
	CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_output_qqvga
//==========================================================
GLOBAL const U32 reg_main_qqvga[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_qcif
//==========================================================
GLOBAL const U32 reg_main_qcif[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_qvga
//==========================================================
GLOBAL const U32 reg_main_qvga[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_wqvga
//==========================================================
GLOBAL const U32 reg_main_wqvga[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_cif
//==========================================================
GLOBAL const U32 reg_main_cif[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_vga
//==========================================================
GLOBAL const U32 reg_main_vga[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_wvga 800 * 480
//==========================================================
GLOBAL const U32 reg_main_wvga[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_svga
//==========================================================
GLOBAL const U32 reg_main_svga[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_sxga
//==========================================================
GLOBAL const U32 reg_main_sxga[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_qxga
//==========================================================
GLOBAL const U32 reg_main_qxga[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_qxga
//==========================================================
GLOBAL const U32 reg_main_uxga[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_full_yuv
//==========================================================
GLOBAL const U32 reg_main_full_yuv[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_output_cropped_yuv
//==========================================================
GLOBAL const U8 reg_main_crop_yuv[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;


//==========================================================
// CAMERA_JPEG_output_5M
//==========================================================
GLOBAL const U32 reg_main_jpeg_5m[]
#if defined(_CAMACQ_API_C_)
={

#if 1
{0xFCFCD000},
{0x00287000},
{0x002A0258},
{0x0F120A00},	//REG_TC_GP_CapReqInputWidth //2560
{0x0F120780},	//REG_TC_GP_CapReqInputHeight //1920
{0x0F120010},	//REG_TC_GP_CapInputWidthOfs //(2592-2560)/2
{0x0F12000C},	//REG_TC_GP_CapInputHeightOfs //(1944-1920)/2

{0x002A0264},
{0x0F120001},	//REG_TC_GP_bUseReqInputInCap

{0x002A049C},
{0x0F120A00},	//REG_TC_PZOOM_CapZoomReqInputWidth //2560
{0x0F120780},	//REG_TC_PZOOM_CapZoomReqInputHeight //1920
{0x0F120000},	//REG_TC_PZOOM_CapZoomReqInputWidthOfs
{0x0F120000},	//REG_TC_PZOOM_CapZoomReqInputHeightOfs

{0x002A047C},
{0x0F120001},	//REG_TC_THUMB_Thumb_bActive
{0x0F120280},	//REG_TC_THUMB_Thumb_uWidth //640
{0x0F1201E0},	//REG_TC_THUMB_Thumb_uHeight //480

{0x002A0398},
{0x0F120A00},	//REG_0TC_CCFG_usWidth //2560
{0x0F120780},	//REG_0TC_CCFG_usHeight //1920

{0x002A024E},
{0x0F120001},	//REG_TC_GP_NewConfigSync
{0x002A0270},
{0x0F120001},	//REG_TC_GP_CapConfigChanged
CAMACQ_MAIN_BTM_OF_DATA
#endif
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_4M
//==========================================================
GLOBAL const U32 reg_main_jpeg_w4m[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_3M
//==========================================================
GLOBAL const U32 reg_main_jpeg_3m[]
#if defined(_CAMACQ_API_C_)
={
#if 1
{0xFCFCD000},
{0x00287000},
{0x002A0258},
{0x0F120A00},	//REG_TC_GP_CapReqInputWidth //2560
{0x0F120780},	//REG_TC_GP_CapReqInputHeight //1920
{0x0F120010},	//REG_TC_GP_CapInputWidthOfs //(2592-2560)/2
{0x0F12000C},	//REG_TC_GP_CapInputHeightOfs //(1944-1920)/2

{0x002A0264},
{0x0F120001},	//REG_TC_GP_bUseReqInputInCap

{0x002A049C},
{0x0F120A00},	//REG_TC_PZOOM_CapZoomReqInputWidth //2560
{0x0F120780},	//REG_TC_PZOOM_CapZoomReqInputHeight //1920
{0x0F120000},	//REG_TC_PZOOM_CapZoomReqInputWidthOfs
{0x0F120000},	//REG_TC_PZOOM_CapZoomReqInputHeightOfs

{0x002A047C},
{0x0F120001},	//REG_TC_THUMB_Thumb_bActive
{0x0F120280},	//REG_TC_THUMB_Thumb_uWidth //640
{0x0F1201E0},	//REG_TC_THUMB_Thumb_uHeight //480

{0x002A0398},
{0x0F120800},	//REG_0TC_CCFG_usWidth //2048
{0x0F120600},	//REG_0TC_CCFG_usHeight //1536

{0x002A024E},
{0x0F120001},	//REG_TC_GP_NewConfigSync
{0x002A0270},
{0x0F120001},	//REG_TC_GP_CapConfigChanged

CAMACQ_MAIN_BTM_OF_DATA
#endif
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_2M
//==========================================================
GLOBAL const U32 reg_main_jpeg_2m[]
#if defined(_CAMACQ_API_C_)
={

#if 1
{0xFCFCD000},
{0x00287000},
{0x002A0258},
{0x0F120A00},	//REG_TC_GP_CapReqInputWidth //2560
{0x0F120780},	//REG_TC_GP_CapReqInputHeight //1920
{0x0F120010},	//REG_TC_GP_CapInputWidthOfs //(2592-2560)/2
{0x0F12000C},	//REG_TC_GP_CapInputHeightOfs //(1944-1920)/2

{0x002A0264},
{0x0F120001},	//REG_TC_GP_bUseReqInputInCap

{0x002A049C},
{0x0F120A00},	//REG_TC_PZOOM_CapZoomReqInputWidth //2560
{0x0F120780},	//REG_TC_PZOOM_CapZoomReqInputHeight //1920
{0x0F120000},	//REG_TC_PZOOM_CapZoomReqInputWidthOfs
{0x0F120000},	//REG_TC_PZOOM_CapZoomReqInputHeightOfs

{0x002A047C},
{0x0F120001},	//REG_TC_THUMB_Thumb_bActive
{0x0F120280},	//REG_TC_THUMB_Thumb_uWidth //640
{0x0F1201E0},	//REG_TC_THUMB_Thumb_uHeight //480

{0x002A0398},
{0x0F120640},	//REG_0TC_CCFG_usWidth //1600
{0x0F1204B0},	//REG_0TC_CCFG_usHeight //1200

{0x002A024E},
{0x0F120001},	//REG_TC_GP_NewConfigSync
{0x002A0270},
{0x0F120001},	//REG_TC_GP_CapConfigChanged
CAMACQ_MAIN_BTM_OF_DATA

#endif
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_w1_5M
//==========================================================
GLOBAL const U32 reg_main_jpeg_w1_5m[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_1M
//==========================================================
GLOBAL const U32 reg_main_jpeg_1m[]
#if defined(_CAMACQ_API_C_)
={

#if 1
{0xFCFCD000},
{0x00287000},
{0x002A0258},
{0x0F120A00},	//REG_TC_GP_CapReqInputWidth //2560
{0x0F120780},	//REG_TC_GP_CapReqInputHeight //1920
{0x0F120010},	//REG_TC_GP_CapInputWidthOfs //(2592-2560)/2
{0x0F12000C},	//REG_TC_GP_CapInputHeightOfs //(1944-1920)/2

{0x002A0264},
{0x0F120001},	//REG_TC_GP_bUseReqInputInCap

{0x002A049C},
{0x0F120A00},	//REG_TC_PZOOM_CapZoomReqInputWidth //2560
{0x0F120780},	//REG_TC_PZOOM_CapZoomReqInputHeight //1920
{0x0F120000},	//REG_TC_PZOOM_CapZoomReqInputWidthOfs
{0x0F120000},	//REG_TC_PZOOM_CapZoomReqInputHeightOfs

{0x002A047C},
{0x0F120001},	//REG_TC_THUMB_Thumb_bActive
{0x0F120280},	//REG_TC_THUMB_Thumb_uWidth //640
{0x0F1201E0},	//REG_TC_THUMB_Thumb_uHeight //480

{0x002A0398},
{0x0F120500},	//REG_0TC_CCFG_usWidth //1280
{0x0F1203C0},	//REG_0TC_CCFG_usHeight // 960

{0x002A024E},
{0x0F120001},	//REG_TC_GP_NewConfigSync
{0x002A0270},
{0x0F120001},	//REG_TC_GP_CapConfigChanged


CAMACQ_MAIN_BTM_OF_DATA

#endif
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_VGA
//==========================================================
GLOBAL const U32 reg_main_jpeg_vga[]
#if defined(_CAMACQ_API_C_)
={

#if 1
{0xFCFCD000},
{0x00287000},
{0x002A0258},
{0x0F120A00},	//REG_TC_GP_CapReqInputWidth //2560
{0x0F120780},	//REG_TC_GP_CapReqInputHeight //1920
{0x0F120010},	//REG_TC_GP_CapInputWidthOfs //(2592-2560)/2
{0x0F12000C},	//REG_TC_GP_CapInputHeightOfs //(1944-1920)/2

{0x002A0264},
{0x0F120001},	//REG_TC_GP_bUseReqInputInCap

{0x002A049C},
{0x0F120A00},	//REG_TC_PZOOM_CapZoomReqInputWidth //2560
{0x0F120780},	//REG_TC_PZOOM_CapZoomReqInputHeight //1920
{0x0F120000},	//REG_TC_PZOOM_CapZoomReqInputWidthOfs
{0x0F120000},	//REG_TC_PZOOM_CapZoomReqInputHeightOfs

{0x002A047C},
{0x0F120001},	//REG_TC_THUMB_Thumb_bActive
{0x0F120280},	//REG_TC_THUMB_Thumb_uWidth //640
{0x0F1201E0},	//REG_TC_THUMB_Thumb_uHeight //480

{0x002A0398},
{0x0F120280},	//REG_0TC_CCFG_usWidth //640
{0x0F1201E0},	//REG_0TC_CCFG_usHeight //480

{0x002A024E},
{0x0F120001},	//REG_TC_GP_NewConfigSync
{0x002A0270},
{0x0F120001},	//REG_TC_GP_CapConfigChanged

CAMACQ_MAIN_BTM_OF_DATA

#endif
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_WQVGA
//==========================================================
GLOBAL const U32 reg_main_jpeg_wqvga[]
#if defined(_CAMACQ_API_C_)
={


CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

//==========================================================
// CAMERA_JPEG_output_QVGA
//==========================================================
GLOBAL const U32 reg_main_jpeg_qvga[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_qvga_v[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_half_vga_v[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_half_vga[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_vga_v[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_5M[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1080P[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_720P[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_not[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_flicker_disabled[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_flicker_50hz[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_flicker_60hz[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_flicker_auto[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_jpeg_quality_superfine[]
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A0478},
{0x0F12005F},
{0x0F12005F},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_jpeg_quality_fine[]
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A0478},
{0x0F120059},
{0x0F120059},
CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_jpeg_quality_normal[]
#if defined(_CAMACQ_API_C_)
={
{0x00287000},
{0x002A0478},
{0x0F120052},
{0x0F120052},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_priv_ctrl_returnpreview[]
#if defined(_CAMACQ_API_C_)
={

CAMACQ_MAIN_BTM_OF_DATA

}
#endif /* _CAMACQ_API_C_ */
;

//BYKIM_DTP
GLOBAL const U32 reg_main_dtp_on[]
#if defined(_CAMACQ_API_C_)
={
#if 1

	{0xFCFCD000},
	{0x0028D000},
	{0x002AB054},
	{0x0F120001},
	CAMACQ_MAIN_BTM_OF_DATA

#endif
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_dtp_off[]
#if defined(_CAMACQ_API_C_)
={
#if 1

	{0xFCFCD000},
	{0x0028D000},
	{0x002AB054},
	{0x0F120000},
	CAMACQ_MAIN_BTM_OF_DATA

#endif
}
#endif /* _CAMACQ_API_C_ */
;


GLOBAL const U32 reg_main_4_zoom0[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120100},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_4_zoom1[]
#if defined(_CAMACQ_API_C_)
={

{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120160},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_4_zoom2[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F1201C0},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_4_zoom3[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120220},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_4_zoom4[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120280},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_4_zoom5[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F1202E0},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_4_zoom6[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120340},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_4_zoom7[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F1203A0},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;
GLOBAL const U32 reg_main_4_zoom8[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120400},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_2_zoom0[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120100},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_2_zoom1[]
#if defined(_CAMACQ_API_C_)
={

{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120120},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_2_zoom2[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120140},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_2_zoom3[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120160},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_2_zoom4[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120180},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_2_zoom5[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F1201A0},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_2_zoom6[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F1201C0},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_2_zoom7[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F1201E0},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;
GLOBAL const U32 reg_main_2_zoom8[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120200},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_25_zoom0[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120100},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_25_zoom1[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120108},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_25_zoom2[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120110},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_25_zoom3[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120118},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_25_zoom4[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120120},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_25_zoom5[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120128},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_25_zoom6[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120130},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_25_zoom7[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120138},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_25_zoom8[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120140},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_6_zoom0[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120100},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_6_zoom1[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120113},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_6_zoom2[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120126},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_6_zoom3[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120139},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_6_zoom4[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F12014C},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_6_zoom5[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F12015F},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;
GLOBAL const U32 reg_main_1_6_zoom6[]
#if defined(_CAMACQ_API_C_)	
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120172},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_6_zoom7[]
#if defined(_CAMACQ_API_C_)	
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F120185},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;

GLOBAL const U32 reg_main_1_6_zoom8[]
#if defined(_CAMACQ_API_C_)
={
{0xFCFCD000},
{0x00287000},
{0x002A048E},
{0x0F12019A},
{0x002A04A4},
{0x0F120005},

CAMACQ_MAIN_BTM_OF_DATA
}
#endif /* _CAMACQ_API_C_ */
;



#undef GLOBAL
#endif /* _CAMACQ_SR200PC10_H_ */
