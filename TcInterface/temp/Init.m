%% Import Ads.dll
dll = NET.addAssembly('C:\TwinCAT\AdsApi\.NET\v4.0.30319\TwinCAT.Ads.dll');
import TwinCAT.Ads.*;

%% Create TcAdsClient instance and Connect to the right port on the right machine
tcClient = TcAdsClient;
tcClient.Connect('', 851);

%% Create Symbolic Handler
try
	hVar = tcClient.CreateVariableHandle('MAIN.Value1');
catch err
	tcClient.Dispose();
	msgbox(err.message,'Error creating the variable handle','error');
	error(err.message);
end

%% Do reading task
    % Create AdsStream 
    readStream = AdsStream(2);
    reader = AdsBinaryReader(readStream);
    readStream.Position = 0;