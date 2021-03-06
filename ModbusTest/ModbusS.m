function ModbusS(block)

setup(block);

function setup(block)

    % Register number of ports
    block.NumInputPorts  = 1;
    block.NumOutputPorts = 1;

    % Setup port properties to be inherited or dynamic
    block.SetPreCompInpPortInfoToDynamic;
    block.SetPreCompOutPortInfoToDynamic;

    % Override input port properties
    block.InputPort(1).Dimensions        = 1;
    block.InputPort(1).DirectFeedthrough = true;

    % Override output port properties
    block.OutputPort(1).Dimensions       = 1;

    % Register parameters
    block.NumDialogPrms     = 0;

    % Register sample times
    block.SampleTimes = [-1 0];

    block.RegBlockMethod('PostPropagationSetup',    @DoPostPropSetup);
    block.RegBlockMethod('InitializeConditions', @InitializeConditions);
    %block.RegBlockMethod('Start', @Start);
    block.RegBlockMethod('Outputs', @Outputs);     % Required
    %block.RegBlockMethod('Update', @Update);

function DoPostPropSetup(block)
    block.NumDworks = 0;

function InitializeConditions(block)

function Outputs(block)
    m = modbus('tcpip','127.0.0.1', 502);
    block.OutputPort(1).Data = read(m,'holdingregs',100,1);
