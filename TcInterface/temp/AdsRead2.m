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

function value = AdsRead2 (AMSNetID, Port, Var, Type, Size)
%% Import Ads.dll
%NET.addAssembly('C:\TwinCAT\AdsApi\.NET\v4.0.30319\TwinCAT.Ads.dll');
import TwinCAT.Ads.*;

%% Create TcAdsClient instance and Connect to the right port on the right machine
tcClient = TcAdsClient;
tcClient.Connect(AMSNetID, Port);

%% Create Symbolic Handler
try
	hVar = tcClient.CreateVariableHandle(Var);
catch err
	tcClient.Dispose();
	error(['Error creating Symbolic Handler! ' newline err.message]);
end

%% Do reading task
try
    % Create AdsStream 
    readStream = AdsStream(Size);
    reader = AdsBinaryReader(readStream);
    readStream.Position = 0;
    % Read Value
    tcClient.Read(hVar, readStream);
    switch lower(Type)
        case 'bool'
            value = reader.ReadBoolean();
        case 'byte'
            value = reader.ReadByte();
        case 'sbyte'
            value = reader.ReadSByte();
        case 'int'
            value = reader.ReadInt16();     
        case 'dint'
            value = reader.ReadInt32();
        case 'lint'
            value = reader.ReadInt64();
        case 'uint'
            value = reader.ReadUInt16();     
        case 'udint'
            value = reader.ReadUInt32();
        case 'ulint'
            value = reader.ReadUInt64();
        case 'real'
            value = reader.ReadSingle();  
        case 'lreal'
            value = reader.ReadDouble();  
    end

catch err
	tcClient.Dispose();
	error(['Error reading variable via ADS! ' newline err.message]);
end

%% Delete Symbolic Handler and Dispose ADS client
if ~isempty(hVar)
    tcClient.DeleteVariableHandle(hVar);
end
tcClient.Dispose();
end