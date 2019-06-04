 

  int __stdcall  openUSB(void);
  int __stdcall  closeUSB(void);

  int __stdcall  get_device_num(void);
  int __stdcall  Reset_Usb_Device(int dev); 
  int __stdcall  ad_single(int dev,int ad_os,int ad_range,float*  databuf);
  int __stdcall   ad_continu_conf(int dev,int ad_os,int ad_range,int freq,int trig_sl,int trig_pol,int clk_sl,int ext_clk_pol);
  int __stdcall  Get_AdBuf_Size(int dev); 
  int __stdcall  Read_AdBuf(int dev,float* databuf,int num);
  int __stdcall  AD_continu_stop(int dev);
  int __stdcall  ad_continu(int dev,int ad_os,int ad_range,int freq,int trig_sl,int trig_pol,int clk_sl,int ext_clk_pol,int num,float*  databuf);
  int __stdcall  Pwm_Out(int dev,int ch,int en,int freq,float duty);//ch0--3
  int __stdcall  Pulse_Out(int dev,int ch,int pulse);
  int __stdcall  Set_Pwm_In(int dev,int ch,int en);
  int __stdcall  Read_Pwm_In(int dev,int ch,float* freq,float* duty);
 
  int __stdcall  Read_Port_In(int dev,unsigned short* in_port);
  int __stdcall  Read_Port_Out(int dev,unsigned short* out_port);


  int __stdcall  Write_Port_Out(int dev,unsigned short out_port);
  int __stdcall  Set_Port_Out(int dev,unsigned short out_port); 
  int __stdcall  Reset_Port_Out(int dev,unsigned short out_port);
  int __stdcall  Write_Port_OutL(int dev,unsigned char out_port);
  int __stdcall  Write_Port_OutH(int dev,unsigned char out_port);

  int __stdcall  Set_DA_Single(int dev,int ch,float da_value);
 