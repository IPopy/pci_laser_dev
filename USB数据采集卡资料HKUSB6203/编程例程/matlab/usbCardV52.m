clear;
clc;
loadlibrary('Usb_Daq_V52_Dll','Usb_Daq_V52_Dll.h');
 
x=calllib('Usb_Daq_V52_Dll','openUSB');
 
a =single( 1.0:8.0);%��ʼ��һ��16Ԫ�ص�һά����
pv =libpointer('singlePtr', a);%��libpointer����������ָ�� 
x=calllib('Usb_Daq_V52_Dll','ad_single',0,0,1,pv); %AD_single(int ad_os,int ad_range,float* adResult);
ADsigle = get(pv, 'Value');%ָ��ֵ���Ƶ���һ������������ʾ 
 
   a1=ADsigle(1)
   a2=ADsigle(2)
    a3=ADsigle(3)
     a4=ADsigle(4)
      a5=ADsigle(5)
       a6=ADsigle(6)
        a7=ADsigle(7)
         a8=ADsigle(8)

 
 
  %��10K�Ĳ������������ɼ�1024���㣬����Ϊ0��������0
  NumSamp=1000*8;%���ݸ���������8����������һ��16ͨ����ÿͨ������1000����
  FrqSamp=10000;%����Ƶ����Ϊ10KHz
b=single(zeros(8,1000));%��ʼ��һ��8X1000���������ڱ�������
pv =libpointer('singlePtr', b);%��libpointer����������ָ�� 
x=calllib('Usb_Daq_V52_Dll','ad_continu',0,0,1,FrqSamp,0,0,0,0,NumSamp,pv);%ad_continu(int ad_os,int ad_range,int freq,int trig_sl,int trig_pol,int clk_sl,int ext_clk_pol,int num,float* databuf);
NumBuf=get(pv, 'Value');%��ָ�����ݸ��Ƶ�һ��������
buf=NumBuf(1,:);%��ʾ��һͨ������
plot(buf,'r');
hold on ;
buf=NumBuf(2,:);%��ʾ�ڶ�ͨ������
plot(buf,'b');
%����ֻ��ʾ������ͨ�����飬��ӳ�����԰�16ͨ������ȫ����ʾ

%IO�������
inport=uint16(0);
[x,inport]=calllib('Usb_Daq_V52_Dll','Read_Port_In',0,inport);%��������IO��
x=calllib('Usb_Daq_V52_Dll','Write_Port_Out',0,1);%�����0 ��Ϊ�ߵ�ƽ,������Ϊ0
%DA���
 
x=calllib('Usb_Daq_V52_Dll','Set_DA_Single',0,0,5.6);%1ͨ�����5.6V
x=calllib('Usb_Daq_V52_Dll','Set_DA_Single',0,1,3.8);%2ͨ�����3.8V
calllib('Usb_Daq_V52_Dll','closeUSB'); 
  unloadlibrary( 'Usb_Daq_V52_Dll');