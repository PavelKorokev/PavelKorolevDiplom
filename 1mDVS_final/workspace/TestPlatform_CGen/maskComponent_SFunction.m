set_param(gcb, 'FunctionName', 'Component_SFunction');
set_param(gcb,'Mask','on');
labels = [];
labels = [labels, sprintf('disp(''Component_SFunction'')\n')];
labels = [labels, sprintf('port_label(''output'',1,''components.InpOut.Output'')\n')];
labels = [labels, sprintf('port_label(''input'',1,''components.Filter.TsFilter'')\n')];
labels = [labels, sprintf('port_label(''input'',2,''components.PID.PressSet'')\n')];
labels = [labels, sprintf('port_label(''input'',3,''components.PID.qP'')\n')];
labels = [labels, sprintf('port_label(''input'',4,''components.PID.qI'')\n')];
labels = [labels, sprintf('port_label(''input'',5,''components.PID.qD'')\n')];
labels = [labels, sprintf('port_label(''input'',6,''components.PID.TsPID'')\n')];
labels = [labels, sprintf('port_label(''input'',7,''components.InpOut.Input'')\n')];
set_param(gcb,'MaskDisplay',labels);
set_param(gcb,'InitFcn','clear Component_SFunction')
