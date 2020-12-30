%% MatlabAdsSample_ReadArrayByName

%% PLC Program

% ---------------------------------------
% PROGRAM MAIN
% VAR
%   PLCVar : ARRAY [0..99] OF INT;
%   Index: BYTE;
% END_VAR
% ---------------------------------------
% FOR Index := 0 TO 99 DO
%   PLCVar[Index] := 3500 + INDEX;
% END_FOR
% ---------------------------------------

tic
%% Import Ads.dll
AdsAssembly = NET.addAssembly('C:\TwinCAT\AdsApi\.NET\v4.0.30319\TwinCAT.Ads.dll');
import TwinCAT.Ads.*

%% Create TcAdsClient instance
tcClient = TcAdsClient;

%% Connect to ADS port 851 on the local machine
tcClient.Connect(851);

try
	hVar = tcClient.CreateVariableHandle('Main.PLCVar');
catch err
	tcClient.Dispose();
	msgbox(err.message,'Error creating the variable handle','error');
	error(err.message);
end

try
	%% Create AdsStream instance
	dataStream = AdsStream(100 * 2);
	binRead = AdsBinaryReader(dataStream);
    
	%% Read array
	tcClient.Read(hVar,dataStream);
	for i=1:1:100
        value = binRead.ReadInt16;
	%	disp(binRead.ReadInt16)
	end
catch err 
	tcClient.Dispose();
	msgbox(err.message,'Error reading array via ADS','error');
	disp(['Error reading array via ADS: ' err.message]);
end
%% Dispose ADS client
tcClient.Dispose();
toc