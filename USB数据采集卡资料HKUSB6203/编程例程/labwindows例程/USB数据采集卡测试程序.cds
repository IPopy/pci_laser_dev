<distribution version="12.0.0" name="USB数据采集卡测试程序" type="MSI">
	<prebuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></prebuild>
	<postbuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></postbuild>
	<msi GUID="{1CC8FF71-9945-454B-96AF-922CF0DC75A3}">
		<general appName="USB数据采集卡测试程序" outputLocation="e:\backup\数据采集卡uSB\USB数据采集卡资料HKUSB6203\例程\labwindows例程\cvidistkit.USB数据采集卡测试程序" relOutputLocation="cvidistkit.USB数据采集卡测试程序" outputLocationWithVars="e:\backup\数据采集卡uSB\USB数据采集卡资料HKUSB6203\例程\labwindows例程\cvidistkit.%name" relOutputLocationWithVars="cvidistkit.%name" upgradeBehavior="1" autoIncrement="true" version="1.0.4">
			<arp company="Microsoft" companyURL="" supportURL="" contact="" phone="" comments=""/>
			<summary title="" subject="" keyWords="" comments="" author=""/></general>
		<userinterface language="Chinese (Simplified)" showPaths="true" readMe="" license="">
			<dlgstrings welcomeTitle="USB数据采集卡测试程序" welcomeText=""/></userinterface>
		<dirs appDirID="100">
			<installDir name="[Program Files]" dirID="2" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="USB数据采集卡测试程序" dirID="100" parentID="2" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="[Start&gt;&gt;Programs]" dirID="7" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="USB数据采集卡测试程序" dirID="101" parentID="7" isMSIDir="false" visible="true" unlock="false"/></dirs>
		<files>
			<simpleFile fileID="0" sourcePath="e:\backup\数据采集卡uSB\USB数据采集卡资料HKUSB6203\例程\labwindows例程\Usb_Daq_V52_Dll.dll" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="1" sourcePath="e:\backup\数据采集卡uSB\USB数据采集卡资料HKUSB6203\例程\labwindows例程\Usb_ADQ_Card.uir" relSourcePath="Usb_ADQ_Card.uir" relSourceBase="0" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="2" sourcePath="e:\backup\数据采集卡uSB\USB数据采集卡资料HKUSB6203\例程\labwindows例程\cvibuild.Usb_ADQ_Card\Release\Usb_ADQ_Card.exe" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/></files>
		<fileGroups>
			<projectOutput targetType="0" dirID="100" projectID="0">
				<fileID>2</fileID></projectOutput>
			<projectDependencies dirID="100" projectID="0">
				<fileID>0</fileID></projectDependencies></fileGroups>
		<shortcuts>
			<shortcut name="USB数据采集卡测试程序" targetFileID="2" destDirID="101" cmdLineArgs="" description="" runStyle="NORMAL"/></shortcuts>
		<mergemodules/>
		<products/>
		<runtimeEngine cvirte="true" instrsup="true" lvrt="true" analysis="true" netvarsup="true" dotnetsup="true" activeXsup="true" rtutilsup="true" installToAppDir="false"/><sxsRuntimeEngine>
			<selected>false</selected>
			<doNotAutoSelect>false</doNotAutoSelect></sxsRuntimeEngine>
		<advanced mediaSize="650">
			<launchConditions>
				<condition>MINOS_WINXP_SP0</condition>
			</launchConditions>
			<includeConfigProducts>true</includeConfigProducts>
			<maxImportVisible>silent</maxImportVisible>
			<maxImportMode>merge</maxImportMode>
			<custMsgFlag>false</custMsgFlag>
			<custMsgPath>c:\program files\national instruments\cvi2012\bin\msgrte.txt</custMsgPath>
			<signExe>false</signExe>
			<certificate></certificate>
			<signTimeURL></signTimeURL>
			<signDescURL></signDescURL></advanced>
		<Projects NumProjects="1">
			<Project000 ProjectID="0" ProjectAbsolutePath="e:\backup\数据采集卡uSB\USB数据采集卡资料HKUSB6203\例程\labwindows例程\Usb_ADQ_Card.prj" ProjectRelativePath="Usb_ADQ_Card.prj"/></Projects>
		<buildData progressBarRate="1.318396514971747">
			<progressTimes>
				<Begin>0.000000000000000</Begin>
				<ProductsAdded>0.102384000000000</ProductsAdded>
				<DPConfigured>2.633633875000000</DPConfigured>
				<DPMergeModulesAdded>3.548007437500000</DPMergeModulesAdded>
				<DPClosed>6.504257062499999</DPClosed>
				<DistributionsCopied>7.104315937500000</DistributionsCopied>
				<End>75.849715062500010</End></progressTimes></buildData>
	</msi>
</distribution>
