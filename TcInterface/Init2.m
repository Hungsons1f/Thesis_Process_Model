%% Import Ads.dll
dll = NET.addAssembly('C:\TwinCAT\AdsApi\.NET\v4.0.30319\TwinCAT.Ads.dll');
import TwinCAT.Ads.*;

%% Create TcAdsClient instance and Connect to the right port on the right machine
tcClient = TcAdsClient;
tcClient.Connect('', 851);

%% Create Symbolic Handler
try
    hVar = tcClient.CreateVariableHandle('MAIN.dut');
catch err
	tcClient.Dispose();
	error(err.message);
end

%% Create AdsStream instance
