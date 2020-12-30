import TwinCAT.Ads.*;

%tic
for i=1:1:inf
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
end
%toc
