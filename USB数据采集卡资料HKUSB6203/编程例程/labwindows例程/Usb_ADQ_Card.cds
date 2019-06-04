<distribution version="12.0.0" name="Usb_ADQ_Card" type="MSI">
	<prebuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></prebuild>
	<postbuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></postbuild>
	<msi GUID="{97380F61-BBA9-42DA-A1A6-C011E3A4A8E7}">
		<general appName="USB数据采集卡V80" outputLocation="e:\program\adq_card\V80\labwindows例程\USB数据采集卡V80" relOutputLocation="USB数据采集卡V80" outputLocationWithVars="e:\program\adq_card\V80\labwindows例程\%name" relOutputLocationWithVars="%name" upgradeBehavior="2" autoIncrement="false" version="3.0.0">
			<arp company="恒凯电子科技" companyURL="" supportURL="" contact="" phone="" comments=""/>
			<summary title="" subject="" keyWords="" comments="" author=""/></general>
		<userinterface language="Chinese (Simplified)" showPaths="true" readMe="" license="">
			<dlgstrings welcomeTitle="USB数据采集卡--恒凯电子科技" welcomeText=""/></userinterface>
		<dirs appDirID="100">
			<installDir name="[Program Files]" dirID="2" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="USB数据采集卡测试程序" dirID="100" parentID="2" isMSIDir="false" visible="true" unlock="false"/></dirs>
		<files>
			<simpleFile fileID="0" sourcePath="e:\program\adq_card\V80\labwindows例程\Usb_ADQ_Card.uir" relSourcePath="Usb_ADQ_Card.uir" relSourceBase="0" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="1" sourcePath="e:\program\adq_card\V80\labwindows例程\cvibuild.Usb_ADQ_Card\Release\Usb_ADQ_Card.exe" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="2" sourcePath="e:\program\adq_card\V80\labwindows例程\Usb_Daq_V80_Dll.dll" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/></files>
		<fileGroups>
			<projectOutput targetType="0" dirID="100" projectID="0">
				<fileID>1</fileID></projectOutput>
			<projectDependencies dirID="100" projectID="0">
				<fileID>2</fileID></projectDependencies></fileGroups>
		<mergemodules/>
		<runtimeEngine cvirte="true" instrsup="true" lvrt="true" analysis="true" netvarsup="true" dotnetsup="true" activeXsup="true" rtutilsup="true" installToAppDir="false"/><sxsRuntimeEngine>
			<selected>false</selected>
			<doNotAutoSelect>false</doNotAutoSelect></sxsRuntimeEngine>
		<advanced mediaSize="650">
			<launchConditions>
				<condition>MINOS_WINXP</condition>
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
			<Project000 ProjectID="0" ProjectAbsolutePath="e:\program\adq_card\V80\labwindows例程\Usb_ADQ_Card.prj" ProjectRelativePath="Usb_ADQ_Card.prj"/></Projects>
		<buildData progressBarRate="1.444571025181161">
			<progressTimes>
				<Begin>0.000000000000000</Begin>
				<ProductsAdded>0.073275062500000</ProductsAdded>
				<DPConfigured>2.376398312500001</DPConfigured>
				<DPMergeModulesAdded>3.150762437500000</DPMergeModulesAdded>
				<DPClosed>5.725774562500003</DPClosed>
				<DistributionsCopied>6.413284875000001</DistributionsCopied>
				<End>69.224702874999991</End></progressTimes></buildData>
	</msi>
</distribution>
