NET.addAssembly('C:\TwinCAT\AdsApi\.NET\v4.0.30319\TwinCAT.Ads.dll');
import TwinCAT.Ads.*;
import System.Type

tcClient = TcAdsClient;
tcClient.Connect('', 851);

hVar = tcClient.CreateVariableHandle('MAIN.Value0');
value = logical(tcClient.ReadAny(hVar, Type.GetType('System.Boolean')));
tcClient.DeleteVariableHandle(hVar);

tcClient.Dispose();

disp(value);
