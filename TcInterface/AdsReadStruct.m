function [value0, value1, value2, value3, value4, value5, value6] = AdsReadStruct()
import TwinCAT.Ads.*;

    tcClient = evalin('base','tcClient');
    hVar = evalin('base','hVar');

%tic
dataStream = AdsStream(8*7);
dataStream.Position = 0;
binRead = AdsBinaryReader(dataStream);

tcClient.Read(hVar,dataStream);
value0 = binRead.ReadDouble;
value1 = binRead.ReadDouble;
value2 = binRead.ReadDouble;
value3 = binRead.ReadDouble;
value4 = binRead.ReadDouble;
value5 = binRead.ReadDouble;
value6 = binRead.ReadDouble;

%toc
end