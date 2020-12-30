function AdsWriteBulk(u)
import TwinCAT.Ads.*;
import System.Type;
    
    tcClient = evalin('base','tcClient');
    hVar1 = evalin('base','hVar1');
    hVar2 = evalin('base','hVar2');
    hVar3 = evalin('base','hVar3');
    hVar4 = evalin('base','hVar4');
    hVar5 = evalin('base','hVar5');
    hVar6 = evalin('base','hVar6');
    tcClient.WriteAny(hVar1, int16(u));
    tcClient.WriteAny(hVar2, int32(u));
    tcClient.WriteAny(hVar3, int64(u));
    tcClient.WriteAny(hVar4, int8(u));
    tcClient.WriteAny(hVar5, single(u));
    tcClient.WriteAny(hVar6, double(u));
end
