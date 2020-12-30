%% Info
% Parameter I/O: 
% - AMSNetID: string
% - Port: number
% - PLC variable: string
% - Data type: string
% - Size of variable: number
% - Value: xtype

%% Import Ads.dll
AdsAssembly = NET.addAssembly('C:\TwinCAT\AdsApi\.NET\v4.0.30319\TwinCAT.Ads.dll');
import TwinCAT.Ads.*

%% Create TcAdsClient instance and Connect to the right port on the right machine
tcClient = TcAdsClient;
tcClient.Connect('',851);

%% Create Symbolic Handler
try
	hVar = tcClient.CreateVariableHandle('Main.Value1');
catch err
	tcClient.Dispose();
	msgbox(err.message,'Error creating the variable handle','error');
	error(err.message);
end

%% Do reading task
try
    % Create AdsStream 
    readStream = AdsStream(1*2);
    reader = AdsBinaryReader(readStream);
    readStream.Position = 0;
    % Read Value
    tcClient.Read(hVar, readStream);
    Value = reader.ReadInt16();
    disp(Value);
catch err
	tcClient.Dispose();
	msgbox(err.message,'Error reading array via ADS','error');
	disp(['Error reading array via ADS: ' err.message]);
end

%% Do writing task
try
    value = int16(5);
    % Create AdsStream
    writeStream = AdsStream(1*2);
    writer = AdsBinaryWriter(writeStream);
    % Write value
    writer.Write(value);
    tcClient.Write(hVar, writeStream);
catch err
	tcClient.Dispose();
	msgbox(err.message,'Error reading array via ADS','error');
	disp(['Error reading array via ADS: ' err.message]);
end

%% Delete Symbolic Handler and Dispose ADS client
if ~isempty(hVar)
    tcClient.DeleteVariableHandle(hVar);
end
tcClient.Dispose();