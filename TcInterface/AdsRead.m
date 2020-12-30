%% Function: AdsRead
% Description: Read PLC valuable through ADS
% Parameter: 
% - AMSNetID: string
% - Port: number
% - PLC variable: string
% - Data type: string
% Return
% - Value: depend on Data type parameter

function value = AdsRead (AMSNetID, Port, Var, VarType)
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
            value = logical(tcClient.ReadAny(hVar, Type.GetType('System.Boolean')));
        case 'byte'
            value = uint8(tcClient.ReadAny(hVar, Type.GetType('System.Byte')));
        case 'sbyte'
            value = int8(tcClient.ReadAny(hVar, Type.GetType('System.SByte')));
        case 'int'
            value = int16(tcClient.ReadAny(hVar, Type.GetType('System.Int16')));   
        case 'dint'
            value = int32(tcClient.ReadAny(hVar, Type.GetType('System.Int32')));   
        case 'lint'
            value = int64(tcClient.ReadAny(hVar, Type.GetType('System.Int64')));   
        case 'uint'
            value = uint16(tcClient.ReadAny(hVar, Type.GetType('System.UInt16')));     
        case 'udint'
            value = uint32(tcClient.ReadAny(hVar, Type.GetType('System.UInt32')));
        case 'ulint'
            value = uint64(tcClient.ReadAny(hVar, Type.GetType('System.UInt64')));
        case 'real'
            value = single(tcClient.ReadAny(hVar, Type.GetType('System.Single')));     
        case 'lreal'
            value = double(tcClient.ReadAny(hVar, Type.GetType('System.Double')));     
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