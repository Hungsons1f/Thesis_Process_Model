function [y1, y2, y3, y4, y5, y6] = AdsReadBulk()
import TwinCAT.Ads.*;
import System.Type;
    
    tcClient = evalin('base','tcClient');
    hVar1 = evalin('base','hVar1');
    hVar2 = evalin('base','hVar2');
    hVar3 = evalin('base','hVar3');
    hVar4 = evalin('base','hVar4');
    hVar5 = evalin('base','hVar5');
    hVar6 = evalin('base','hVar6');
    
    y1 = int16(tcClient.ReadAny(hVar1, Type.GetType('System.Int16')));
    y2 = int32(tcClient.ReadAny(hVar2, Type.GetType('System.Int32')));
    y3 = int32(tcClient.ReadAny(hVar3, Type.GetType('System.Int64')));
    y4 = int8(tcClient.ReadAny(hVar4, Type.GetType('System.Byte')));
    y5 = single(tcClient.ReadAny(hVar5, Type.GetType('System.Single')));
    y6 = double(tcClient.ReadAny(hVar6, Type.GetType('System.Double')));

end