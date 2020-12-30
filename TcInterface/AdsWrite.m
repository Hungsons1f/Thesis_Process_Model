%% Function: AdsWrite
% Description: Read PLC valuable through ADS
% Parameter: 
% - AMSNetID: string
% - Port: number
% - PLC variable: string
% - Data type: string
% - Size of variable: number
% - Value: value to write

function AdsWrite (AMSNetID, Port, Var, VarType, Value)
%% Import Ads.dll
%NET.addAssembly('C:\TwinCAT\AdsApi\.NET\v4.0.30319\TwinCAT.Ads.dll');
import TwinCAT.Ads.*;
import System.Type;

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
    switch lower(VarType)
        case 'bool'
            value = logical(Value);
        case 'byte'
            value = uint8(Value);
        case 'sbyte'
            value = int8(Value);
        case 'int'
            value = int16(Value);     
        case 'dint'
            value = int32(Value);
        case 'lint'
            value = int64(Value);
        case 'uint'
            value = uint16(Value);     
        case 'udint'
            value = uint32(Value);
        case 'ulint'
            value = uint64(Value);
        case 'real'
            value = single(Value);  
        case 'lreal'
            value = double(Value);  
    end
    tcClient.WriteAny(hVar, value);
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