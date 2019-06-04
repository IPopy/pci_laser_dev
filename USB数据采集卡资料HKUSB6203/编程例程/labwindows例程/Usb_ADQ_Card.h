/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2019. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1       /* callback function: quit */
#define  PANEL_TAB                        2       /* control type: tab, callback function: TAB */

     /* tab page panel controls */
#define  AD_Continu_Freq_sample           2       /* control type: numeric, callback function: (none) */
#define  AD_Continu_NUM_sample            3       /* control type: numeric, callback function: (none) */
#define  AD_Continu_GRAPH                 4       /* control type: graph, callback function: (none) */
#define  AD_Continu_start_coun            5       /* control type: command, callback function: start_coun */
#define  AD_Continu_int_ext_triger        6       /* control type: radioButton, callback function: (none) */
#define  AD_Continu_ad_os                 7       /* control type: ring, callback function: (none) */
#define  AD_Continu_ad_range              8       /* control type: ring, callback function: (none) */
#define  AD_Continu_ad_timer              9       /* control type: timer, callback function: ad_timer */

     /* tab page panel controls */
#define  AD_Single_chan_ad_5              2       /* control type: numeric, callback function: (none) */
#define  AD_Single_chan_ad_6              3       /* control type: numeric, callback function: (none) */
#define  AD_Single_chan_ad_7              4       /* control type: numeric, callback function: (none) */
#define  AD_Single_chan_ad_8              5       /* control type: numeric, callback function: (none) */
#define  AD_Single_chan_ad_4              6       /* control type: numeric, callback function: (none) */
#define  AD_Single_chan_ad_3              7       /* control type: numeric, callback function: (none) */
#define  AD_Single_chan_ad_2              8       /* control type: numeric, callback function: (none) */
#define  AD_Single_chan_ad_1              9       /* control type: numeric, callback function: (none) */
#define  AD_Single_NUM_D                  10      /* control type: numeric, callback function: (none) */
#define  AD_Single_TIMER1                 11      /* control type: timer, callback function: TIMER1 */
#define  AD_Single_PICTURE                12      /* control type: picture, callback function: (none) */

     /* tab page panel controls */
#define  DA_out_DA_MUL_2                  2       /* control type: numeric, callback function: (none) */
#define  DA_out_DECORATION_2              3       /* control type: deco, callback function: (none) */
#define  DA_out_DA2_set                   4       /* control type: command, callback function: DA2_set */
#define  DA_out_DA_MUL                    5       /* control type: numeric, callback function: (none) */
#define  DA_out_DECORATION                6       /* control type: deco, callback function: (none) */
#define  DA_out_DA1_set                   7       /* control type: command, callback function: DA1_set */

     /* tab page panel controls */
#define  IO_IN_9                          2       /* control type: LED, callback function: (none) */
#define  IO_IN_10                         3       /* control type: LED, callback function: (none) */
#define  IO_IN_11                         4       /* control type: LED, callback function: (none) */
#define  IO_IN_12                         5       /* control type: LED, callback function: (none) */
#define  IO_IN_13                         6       /* control type: LED, callback function: (none) */
#define  IO_IN_14                         7       /* control type: LED, callback function: (none) */
#define  IO_IN_15                         8       /* control type: LED, callback function: (none) */
#define  IO_IN_16                         9       /* control type: LED, callback function: (none) */
#define  IO_IN_5                          10      /* control type: LED, callback function: (none) */
#define  IO_IN_6                          11      /* control type: LED, callback function: (none) */
#define  IO_IN_7                          12      /* control type: LED, callback function: (none) */
#define  IO_IN_8                          13      /* control type: LED, callback function: (none) */
#define  IO_IN_4                          14      /* control type: LED, callback function: (none) */
#define  IO_IN_3                          15      /* control type: LED, callback function: (none) */
#define  IO_IN_2                          16      /* control type: LED, callback function: (none) */
#define  IO_IN_1                          17      /* control type: LED, callback function: (none) */
#define  IO_OUT_9                         18      /* control type: binary, callback function: OUT_9 */
#define  IO_OUT_10                        19      /* control type: binary, callback function: OUT_10 */
#define  IO_OUT_11                        20      /* control type: binary, callback function: OUT_11 */
#define  IO_OUT_12                        21      /* control type: binary, callback function: OUT_12 */
#define  IO_OUT_13                        22      /* control type: binary, callback function: OUT_13 */
#define  IO_OUT_14                        23      /* control type: binary, callback function: OUT_14 */
#define  IO_OUT_15                        24      /* control type: binary, callback function: OUT_15 */
#define  IO_OUT_16                        25      /* control type: binary, callback function: OUT_16 */
#define  IO_OUT_8                         26      /* control type: binary, callback function: OUT_8 */
#define  IO_OUT_7                         27      /* control type: binary, callback function: OUT_7 */
#define  IO_OUT_6                         28      /* control type: binary, callback function: OUT_6 */
#define  IO_OUT_5                         29      /* control type: binary, callback function: OUT_5 */
#define  IO_OUT_4                         30      /* control type: binary, callback function: OUT_4 */
#define  IO_OUT_3                         31      /* control type: binary, callback function: OUT_3 */
#define  IO_OUT_2                         32      /* control type: binary, callback function: OUT_2 */
#define  IO_OUT_1                         33      /* control type: binary, callback function: OUT_1 */
#define  IO_TIMER3                        34      /* control type: timer, callback function: TIMER3 */
#define  IO_DECORATION                    35      /* control type: deco, callback function: (none) */
#define  IO_DECORATION_2                  36      /* control type: deco, callback function: (none) */

     /* tab page panel controls */
#define  PWM_count_PWMin_freq_2           2       /* control type: numeric, callback function: (none) */
#define  PWM_count_PWMin_duty_2           3       /* control type: numeric, callback function: (none) */
#define  PWM_count_PWMin_freq             4       /* control type: numeric, callback function: (none) */
#define  PWM_count_PWMin_duty             5       /* control type: numeric, callback function: (none) */
#define  PWM_count_DECORATION_3           6       /* control type: deco, callback function: (none) */
#define  PWM_count_PWMOUT_freq_2          7       /* control type: numeric, callback function: (none) */
#define  PWM_count_PWMOUT_duty_2          8       /* control type: numeric, callback function: (none) */
#define  PWM_count_DECORATION_2           9       /* control type: deco, callback function: (none) */
#define  PWM_count_PWMOUT_freq            10      /* control type: numeric, callback function: (none) */
#define  PWM_count_PWMOUT_duty            11      /* control type: numeric, callback function: (none) */
#define  PWM_count_PWMin                  12      /* control type: command, callback function: PWMin */
#define  PWM_count_PWM2out_set            13      /* control type: command, callback function: PWM2out_set */
#define  PWM_count_PWM1out_set            14      /* control type: command, callback function: PWM1out_set */
#define  PWM_count_DECORATION             15      /* control type: deco, callback function: (none) */
#define  PWM_count_TIMER4                 16      /* control type: timer, callback function: TIMER4 */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

#define  MENUBAR                          1
#define  MENUBAR_file                     2
#define  MENUBAR_file_open                3       /* callback function: openfile */
#define  MENUBAR_file_close               4       /* callback function: closefile */


     /* Callback Prototypes: */

int  CVICALLBACK ad_timer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK closefile(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK DA1_set(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DA2_set(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK openfile(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK OUT_1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_10(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_11(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_12(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_13(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_14(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_15(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_16(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_3(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_4(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_5(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_6(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_7(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_8(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OUT_9(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PWM1out_set(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PWM2out_set(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PWMin(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK quit(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK start_coun(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TAB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TIMER1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TIMER3(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TIMER4(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
