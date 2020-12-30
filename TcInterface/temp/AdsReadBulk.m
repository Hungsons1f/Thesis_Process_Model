%% Function: AdsRead
% Description: Read PLC valuable through ADS
% Parameter: 
% - AMSNetID: string
% - Port: number
% - PLC variable: string
% - Data type: string
% - Size of variable: number
% Return
% - Value: depend on Data type parameter

function [value0, value1, value2, value3, value4, value5, value6] = AdsReadBulk (AMSNetID, Port)
%% Import Ads.dll
NET.addAssembly('C:\TwinCAT\AdsApi\.NET\v4.0.30319\TwinCAT.Ads.dll');
import TwinCAT.Ads.*;

%% Create TcAdsClient instance and Connect to the right port on the right machine
tcClient = TcAdsClient;
tcClient.Connect(AMSNetID, Port);

%% Create Symbolic Handler
try
	hVar0 = tcClient.CreateVariableHandle('MAIN.Value0');
    hVar1 = tcClient.CreateVariableHandle('MAIN.Value1');
    hVar2 = tcClient.CreateVariableHandle('MAIN.Value2');
    hVar3 = tcClient.CreateVariableHandle('MAIN.Value3');
    hVar4 = tcClient.CreateVariableHandle('MAIN.Value4');
    hVar5 = tcClient.CreateVariableHandle('MAIN.Value5');
    hVar6 = tcClient.CreateVariableHandle('MAIN.Value6');
catch err
	tcClient.Dispose();
	msgbox(err.message,'Error creating the variable handle','error');
	error(err.message);
end

%% Do reading task
try
    % Create AdsStream 
    readStream = AdsStream(28);
    reader = AdsBinaryReader(readStream);
    %readStream.Position = 0;
    % Read Value
    tcClient.Read(hVar0, readStream);
    value0 = double(reader.ReadBoolean());
    tcClient.Read(hVar1, readStream);
    value1 = double(reader.ReadInt16()); 
    tcClient.Read(hVar2, readStream);
    value2 = double(reader.ReadInt32());
    tcClient.Read(hVar3, readStream);
    value3 = double(reader.ReadInt64());
    tcClient.Read(hVar4, readStream);
    value4 = double(reader.ReadByte());
    tcClient.Read(hVar5, readStream);
    value5 = double(reader.ReadSingle());
    tcClient.Read(hVar6, readStream);
    value6 = double(reader.ReadDouble()); 

catch err
	tcClient.Dispose();
	msgbox(err.message,'Error reading array via ADS','error');
	disp(['Error reading array via ADS: ' err.message]);
end

%% Delete Symbolic Handler and Dispose ADS client
if ~isempty(hVar0)
    tcClient.DeleteVariableHandle(hVar0);
end
if ~isempty(hVar1)
    tcClient.DeleteVariableHandle(hVar1);
end
if ~isempty(hVar2)
    tcClient.DeleteVariableHandle(hVar2);
end
if ~isempty(hVar3)
    tcClient.DeleteVariableHandle(hVar3);
end
if ~isempty(hVar4)
    tcClient.DeleteVariableHandle(hVar4);
end
if ~isempty(hVar5)
    tcClient.DeleteVariableHandle(hVar5);
end
if ~isempty(hVar6)
    tcClient.DeleteVariableHandle(hVar6);
end
tcClient.Dispose();
end