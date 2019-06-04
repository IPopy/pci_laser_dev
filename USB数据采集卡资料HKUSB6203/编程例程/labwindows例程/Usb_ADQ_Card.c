#include <ansi_c.h>
#include <analysis.h>
#include "radioGroup.h"
#include <cvirte.h>		
#include <userint.h>
#include "Usb_ADQ_Card.h"
#include "Usb_Daq_V52_Dll.h"
 static int usb_open=0; 
 static unsigned char io_out[8];
  int da_scan_out=0; 
 
  

static int panelHandle;
static 	int hmenubar;   
static int TabPanelHandle;
#define PAGE_ZERO 0 
#define PAGE_ONE 1
#define PAGE_TWO 2
#define PAGE_THREE 3
#define PAGE_FOUR 4
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "Usb_ADQ_Card.uir", PANEL)) < 0)
		return -1;
	hmenubar = GetPanelMenuBar (panelHandle);  
	// TODO: Get the panel handle associated with a tab page with GetPanelHandleFromTabPage
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK quit (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
				if(usb_open==1)  
			{	
				if(da_scan_out==1)  
					{
				    da_scan_out=0;
				//	 SetCtrlAttribute (TabPanelHandle, DA_out_TIMER_DA1, ATTR_ENABLED, 0);     
					 SetCtrlAttribute (TabPanelHandle, DA_out_DA1_set, ATTR_LABEL_TEXT, "开始");   
					// Da0_Continu_Stop(); 
					}
		 	closeUSB();
			usb_open=0;
        	SetMenuBarAttribute (hmenubar, MENUBAR_file_open, ATTR_DIMMED, 0);
        	SetMenuBarAttribute (hmenubar, MENUBAR_file_close , ATTR_DIMMED, 1); 
			
				GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_ZERO, &TabPanelHandle);
	SetCtrlAttribute (TabPanelHandle, AD_Single_TIMER1, ATTR_ENABLED, 0);
	
	
	
	GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);
	SetCtrlAttribute (TabPanelHandle, IO_TIMER3 , ATTR_ENABLED, 0);
			}
			QuitUserInterface (0);
			break;
	}
	return 0;
}
									  
int CVICALLBACK TAB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	return 0;
}
      
int CVICALLBACK TIMER1 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			int tab_index; 
			GetCtrlIndex (panelHandle, PANEL_TAB, &tab_index); 
			  if((usb_open==1)&&(tab_index==0))  
			{   GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_ZERO, &TabPanelHandle);
			 
			float ad_v[8];
			     ad_single(0,0,1,ad_v);   //  ad_single(int chan,int ad_mod,int gain,float* ad_value);   
			    SetCtrlVal (TabPanelHandle, AD_Single_chan_ad_1, ad_v[0]);
			 	
			    SetCtrlVal (TabPanelHandle, AD_Single_chan_ad_2, ad_v[1]);
 
			    SetCtrlVal (TabPanelHandle, AD_Single_chan_ad_3, ad_v[2]);

			    SetCtrlVal (TabPanelHandle, AD_Single_chan_ad_4, ad_v[3]);

			    SetCtrlVal (TabPanelHandle, AD_Single_chan_ad_5, ad_v[4]);
				
			    SetCtrlVal (TabPanelHandle, AD_Single_chan_ad_6, ad_v[5]);
				
			    SetCtrlVal (TabPanelHandle, AD_Single_chan_ad_7, ad_v[6]);

			    SetCtrlVal (TabPanelHandle, AD_Single_chan_ad_8, ad_v[7]);

			   
				
			}
			break;
	}
	return 0;
}



int CVICALLBACK DA1_set (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		  if(usb_open==1) 
			{  
				GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_TWO, &TabPanelHandle);
			   	  
				float daResult;
				 
				double da_v;
				 
				GetCtrlVal (TabPanelHandle, DA_out_DA_MUL, &da_v);	
				   daResult=  da_v ;
			 
			 		Set_DA_Single(0,0,daResult);
			}			   
			break;		 
	}
	return 0;
}
 
int CVICALLBACK DA2_set (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 if(usb_open==1) 
			{  
				GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_TWO, &TabPanelHandle);
			   	  
				float daResult;
				 
				double da_v;
				 
				GetCtrlVal (TabPanelHandle, DA_out_DA_MUL_2, &da_v);	
				   daResult=  da_v ;
			 
			 		Set_DA_Single(0,1,daResult);
			}			
			break;
	}
	return 0;
}

int CVICALLBACK PWM2out_set (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(usb_open==1) 
			{	int pwmout_freq;float pwmout_duty ;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_THREE, &TabPanelHandle);
			GetCtrlVal (TabPanelHandle, PWM_count_PWMOUT_freq_2,&pwmout_freq);  
			GetCtrlVal (TabPanelHandle, PWM_count_PWMOUT_duty_2, &pwmout_duty);
		Pwm_Out(0,1,1,pwmout_freq,pwmout_duty);//	PWM_Out(2,pwmout_freq,pwmout_duty,1);
			}
			break;
	}
	return 0;
}

int CVICALLBACK PWM1out_set (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(usb_open==1) 
			{
			int pwmout_freq;float pwmout_duty ;  
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_THREE, &TabPanelHandle);
			GetCtrlVal (TabPanelHandle, PWM_count_PWMOUT_freq,&pwmout_freq);  
			GetCtrlVal (TabPanelHandle, PWM_count_PWMOUT_duty, &pwmout_duty);
			Pwm_Out(0,0,1,pwmout_freq,pwmout_duty);//	PWM_Out(1,pwmout_freq,pwmout_duty,1);
		//	Pulse_Out(0,1000);
			}
			break;
	}
	return 0;
}				  
 



int CVICALLBACK TIMER3 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
				int tab_index; 
			GetCtrlIndex (panelHandle, PANEL_TAB, &tab_index); 
			  if((usb_open==1)&&(tab_index==4))
			{
			unsigned short io_in=0; 
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			
		Read_Port_In(0,&io_in);//	io_in=DI_Soft(); 
				if(io_in&0x1)
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_1,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_1,0);	
				}
				
				if(io_in&(0x1<<1))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_2,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_2,0);	
				}
				
				if(io_in&(0x1<<2))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_3,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_3,0);	
				}
				
				if(io_in&(0x1<<3))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_4,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_4,0);	
				}
				
				if(io_in&(0x1<<4))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_5,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_5,0);	
				}
				
				if(io_in&(0x1<<5))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_6,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_6,0);	
				}
				
				if(io_in&(0x1<<6))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_7,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_7,0);	
				}
				
				if(io_in&(0x1<<7))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_8,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_8,0);	
				}
				
					if(io_in&(0x1<<8))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_9,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_9,0);	
				}
		 
				if(io_in&(0x1<<9))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_10,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_10,0);	
				}
				
				if(io_in&(0x1<<10))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_11,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_11,0);	
				}
				if(io_in&(0x1<<11))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_12,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_12,0);	
				}
				if(io_in&(0x1<<12))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_13,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_13,0);	
				}
				if(io_in&(0x1<<13))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_14,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_14,0);	
				}
				if(io_in&(0x1<<14))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_15,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_15,0);	
				}
				if(io_in&(0x1<<15))
				{
				  SetCtrlVal (TabPanelHandle, IO_IN_16,1);	
				}
				else
				{
				SetCtrlVal (TabPanelHandle, IO_IN_16,0);	
				}
			}
			break;
	}
	return 0;
}
    
void CVICALLBACK openfile (int menuBar, int menuItem, void *callbackData,
		int panel)
{
	if(usb_open==0)
	 {
	  if(0== openUSB())
	  {
	   //unsigned int sernum=Get_SerialNumber();
	    
	  usb_open=1;
   	SetMenuBarAttribute (hmenubar, MENUBAR_file_open, ATTR_DIMMED, 1);
	SetMenuBarAttribute (hmenubar, MENUBAR_file_close , ATTR_DIMMED, 0); 
	
	GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_ZERO, &TabPanelHandle);
	SetCtrlAttribute (TabPanelHandle, AD_Single_TIMER1, ATTR_ENABLED, 1);
	 unsigned int num;
	 num=get_device_num();
	  SetCtrlVal (TabPanelHandle,AD_Single_NUM_D ,num);
	 

	
	GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);
	SetCtrlAttribute (TabPanelHandle, IO_TIMER3 , ATTR_ENABLED, 1);
	   
	  }
	
	 }
}

void CVICALLBACK closefile (int menuBar, int menuItem, void *callbackData,
		int panel)
{
	if(usb_open==1)  
			{	
					if(da_scan_out==1)  
					{
				    da_scan_out=0;
					// SetCtrlAttribute (TabPanelHandle, DA_out_TIMER_DA1, ATTR_ENABLED, 0);     
					 SetCtrlAttribute (TabPanelHandle, DA_out_DA1_set, ATTR_LABEL_TEXT, "开始");   
				//	 Da0_Continu_Stop(); 
					}
		 	closeUSB();
			usb_open=0;
        	SetMenuBarAttribute (hmenubar, MENUBAR_file_open, ATTR_DIMMED, 0);
        	SetMenuBarAttribute (hmenubar, MENUBAR_file_close , ATTR_DIMMED, 1); 
			
				GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_ZERO, &TabPanelHandle);
	SetCtrlAttribute (TabPanelHandle, AD_Single_TIMER1, ATTR_ENABLED, 0);
	
	
	
	GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);
	SetCtrlAttribute (TabPanelHandle, IO_TIMER3 , ATTR_ENABLED, 0);
	
			}
	
}   
   int pwmin=0;
int CVICALLBACK PWMin (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(usb_open==1) 
			{
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_THREE, &TabPanelHandle);	
			if(pwmin==0)
				{
			    pwmin=1;
			    
			    SetCtrlAttribute (TabPanelHandle, PWM_count_PWMin, ATTR_LABEL_TEXT, "停止");
			 Set_Pwm_In(0,0,1);//   PWM_In(1); 
			 Set_Pwm_In(0,1,1);
			 Set_Pwm_In(0,2,1);
			 Set_Pwm_In(0,3,1);
				SetCtrlAttribute (TabPanelHandle, PWM_count_TIMER4, ATTR_ENABLED, 1);
				}
				else
				{
				 pwmin=0;
			     
			    SetCtrlAttribute (TabPanelHandle, PWM_count_PWMin, ATTR_LABEL_TEXT, "运行");
			 Set_Pwm_In(0,0,0);//   PWM_In(1); 
			 Set_Pwm_In(0,1,0);
			 Set_Pwm_In(0,2,0);
			 Set_Pwm_In(0,3,0);
				SetCtrlAttribute (TabPanelHandle, PWM_count_TIMER4, ATTR_ENABLED, 0);
				}
			}
			break;
	}
	return 0;
}

 
int CVICALLBACK TIMER4 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_THREE, &TabPanelHandle);
				if(pwmin==1)
				{
					float   pwmin_duty;
					float  pwmin_freq;
				 Read_Pwm_In(0,0,&pwmin_freq,&pwmin_duty);//			  Read_PWM_In(&pwmin_freq,&pwmin_duty);
	 		     SetCtrlVal (TabPanelHandle, PWM_count_PWMin_freq, pwmin_freq);
	 		     SetCtrlVal (TabPanelHandle, PWM_count_PWMin_duty, pwmin_duty);
				 
				  Read_Pwm_In(0,1,&pwmin_freq,&pwmin_duty);//			  Read_PWM_In(&pwmin_freq,&pwmin_duty);
	 		     SetCtrlVal (TabPanelHandle, PWM_count_PWMin_freq_2, pwmin_freq);
	 		     SetCtrlVal (TabPanelHandle, PWM_count_PWMin_duty_2, pwmin_duty);
			 
			
				}
			 
			break;
	}
	return 0;
}
 
int CVICALLBACK start_coun (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{	 static int ad_scan=0;
	switch (event)
	{
		case EVENT_COMMIT:
		        int tab_index; 
			GetCtrlIndex (panelHandle, PANEL_TAB, &tab_index); 
		
			  if((usb_open==1)&&(tab_index==1))  
			{   GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_ONE, &TabPanelHandle);
			   int ad_os=0,gain_n=0,rate_sample;    		   
			  GetCtrlVal (TabPanelHandle, AD_Continu_ad_os, &ad_os); 
		      GetCtrlVal (TabPanelHandle, AD_Continu_ad_range, &gain_n);
		     GetCtrlVal (TabPanelHandle, AD_Continu_Freq_sample, &rate_sample);
			 if(ad_scan==0)
			 {
			  
			   ad_scan=1;
			   ad_continu_conf(0,ad_os,gain_n,rate_sample,0,0,0,0);
			    SetCtrlAttribute (TabPanelHandle, AD_Continu_start_coun, ATTR_LABEL_TEXT, "停止");
			 	 SetCtrlAttribute (TabPanelHandle, AD_Continu_ad_timer, ATTR_ENABLED, 1);
			 }
			 else
			 {
				 ad_scan=0;
			 	 AD_continu_stop(0);
			 	  SetCtrlAttribute (TabPanelHandle, AD_Continu_start_coun, ATTR_LABEL_TEXT, "开始");
			 	  SetCtrlAttribute (TabPanelHandle, AD_Continu_ad_timer, ATTR_ENABLED, 0); 
			 }
			} 
			break;
	}
	return 0;
}
    
int CVICALLBACK ad_timer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			  	 int tab_index; 
			GetCtrlIndex (panelHandle, PANEL_TAB, &tab_index); 
			  if((usb_open==1)&&(tab_index==1))  
			{   GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_ONE, &TabPanelHandle);
			int num_sample,num;
			 GetCtrlVal (TabPanelHandle, AD_Continu_NUM_sample , &num);  
            num_sample= Get_AdBuf_Size(0)/8;  //-1-- erro 0--buff empt 1--buff  full
			if(num_sample>1)
			{   
				float *data;
				 float *wave;
			  float *wave1; 
			  float *wave2;
			  float *wave3; 
			  float *wave4;
			  float *wave5; 
			  float *wave6;
			  float *wave7; 
			  
			 
		 		 wave=(float *)malloc(num_sample*sizeof(float)); 
			 wave1=(float *)malloc(num_sample*sizeof(float)); 
			 wave2=(float *)malloc(num_sample*sizeof(float)); 
			 wave3=(float *)malloc(num_sample*sizeof(float)); 
			 wave4=(float *)malloc(num_sample*sizeof(float)); 
			 wave5=(float *)malloc(num_sample*sizeof(float)); 
			 wave6=(float *)malloc(num_sample*sizeof(float)); 
			 wave7=(float *)malloc(num_sample*sizeof(float));
			 
		
			  
             data=(float *)malloc(num_sample*8*sizeof(float)); 
			    num_sample= Read_AdBuf(0,data,num_sample*8)/8; 
			  if(num_sample>num)
			  {
				 num_sample=num;
			  }
			   for(int i=0;i<num_sample;i++)
			  {
				  *(wave+i)= (*(data+(i<<3))); // *(data1+i)  =*(data+(i<<1));
				  *(wave1+i)= (*(data+(i<<3)+1)); //*(data2+i)  =*(data+(i<<1)+1);
				  *(wave2+i)= (*(data+(i<<3)+2)); 
				  *(wave3+i)= (*(data+(i<<3)+3)); 
				  *(wave4+i)= (*(data+(i<<3)+4)); 
				  *(wave5+i)= (*(data+(i<<3)+5)); 
				  *(wave6+i)= (*(data+(i<<3)+6)); 
				  *(wave7+i)= (*(data+(i<<3)+7));
				  
				 
			  }
			//	num_sample=80;
			   DeleteGraphPlot (TabPanelHandle, AD_Continu_GRAPH, -1, VAL_IMMEDIATE_DRAW);
			  PlotWaveform (TabPanelHandle, AD_Continu_GRAPH, wave, num_sample,VAL_FLOAT, 1.0, 0.0, 0.0, 1.0, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
			  PlotWaveform (TabPanelHandle, AD_Continu_GRAPH, wave1, num_sample,VAL_FLOAT, 1.0, 0.0, 0.0, 1.0, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_GREEN);
			  PlotWaveform (TabPanelHandle, AD_Continu_GRAPH, wave2, num_sample, VAL_FLOAT, 1.0, 0.0, 0.0, 1.0, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_BLUE);
			  PlotWaveform (TabPanelHandle, AD_Continu_GRAPH, wave3, num_sample, VAL_FLOAT, 1.0, 0.0, 0.0, 1.0, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_CYAN);
			  PlotWaveform (TabPanelHandle, AD_Continu_GRAPH, wave4, num_sample, VAL_FLOAT, 1.0, 0.0, 0.0, 1.0, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_MAGENTA);
			  PlotWaveform (TabPanelHandle, AD_Continu_GRAPH, wave5, num_sample, VAL_FLOAT, 1.0, 0.0, 0.0, 1.0, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							VAL_YELLOW);
			  PlotWaveform (TabPanelHandle, AD_Continu_GRAPH, wave6, num_sample, VAL_FLOAT, 1.0, 0.0, 0.0, 1.0, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_BLACK);
			  PlotWaveform (TabPanelHandle, AD_Continu_GRAPH, wave7, num_sample, VAL_FLOAT, 1.0, 0.0, 0.0, 1.0, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1,
							 VAL_WHITE);
			  
			   free(data);
			   free(wave);
			   free(wave1); 
			   free(wave2);  
			   free(wave3);  
			   free(wave4);  
			   free(wave5);  
			   free(wave6);  
			   free(wave7);  
			     
			  }
			}
			break;
	}
	return 0;
}
	 

 int CVICALLBACK OUT_8 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_8,&ioout); 
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<7);	//io_out[7]=1;
			}
			else
			{
			 Reset_Port_Out(0,(unsigned short)0x1<<7);// io_out[7]=0;	
			}
			break;
	}
	return 0;
}

int CVICALLBACK OUT_7 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_7,&ioout); 
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<6);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<6);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}

int CVICALLBACK OUT_6 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_6,&ioout); 
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<5);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<5);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}

int CVICALLBACK OUT_5 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		   	int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_5,&ioout); 
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<4);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<4);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}

int CVICALLBACK OUT_4 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		   	int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_4,&ioout); 
			Pwm_Out(0,3,0,0,0);   
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<3);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<3);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}

int CVICALLBACK OUT_3 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_3,&ioout); 
			Pwm_Out(0,2,0,0,0);   
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<2);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<2);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}

int CVICALLBACK OUT_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_2,&ioout); 
			Pwm_Out(0,1,0,0,0);   
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<1);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<1);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}

int CVICALLBACK OUT_1 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_1,&ioout); 
			Pwm_Out(0,0,0,0,0);
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}
int CVICALLBACK OUT_9 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			   
			int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_9,&ioout); 
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<8);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<8);	// io_out[6]=0;	
			}
			 
			break;
	}
	return 0;
}

int CVICALLBACK OUT_10 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_10,&ioout); 
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<9);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<9);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}

int CVICALLBACK OUT_11 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_11,&ioout); 
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<10);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<10);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}

int CVICALLBACK OUT_12 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		   	int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_12,&ioout); 
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<11);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<11);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}

int CVICALLBACK OUT_13 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_13,&ioout); 
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<12);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<12);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}

int CVICALLBACK OUT_14 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_14,&ioout); 
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<13);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<13);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}

int CVICALLBACK OUT_15 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
		   	int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_15,&ioout); 
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<14);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<14);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}

int CVICALLBACK OUT_16 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			   	int ioout;
			GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, PAGE_FOUR, &TabPanelHandle);  
			GetCtrlVal (TabPanelHandle, IO_OUT_16,&ioout); 
			if( ioout)
			{
			Set_Port_Out(0,(unsigned short)0x1<<15);	//	io_out[6]=1;
			}
			else
			{
			Reset_Port_Out(0,(unsigned short)0x1<<15);	// io_out[6]=0;	
			}
			break;
	}
	return 0;
}
 

