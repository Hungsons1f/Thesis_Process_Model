%% Import Ads.dll
dll = NET.addAssembly('C:\TwinCAT\AdsApi\.NET\v4.0.30319\TwinCAT.Ads.dll');
import TwinCAT.Ads.*;
import System.Type;

%% Create TcAdsClient instance and Connect to the right port on the right machine
tcClient = TcAdsClient;
tcClient.Connect('', 851);

%% Create Symbolic Handler
try
    hVar1 = tcClient.CreateVariableHandle('MAIN.Value1');
    hVar2 = tcClient.CreateVariableHandle('MAIN.Value2');
    hVar3 = tcClient.CreateVariableHandle('MAIN.Value3');
    hVar4 = tcClient.CreateVariableHandle('MAIN.Value4');
    hVar5 = tcClient.CreateVariableHandle('MAIN.Value5');
    hVar6 = tcClient.CreateVariableHandle('MAIN.Value6');
catch err
	tcClient.Dispose();
	error(err.message);
end
