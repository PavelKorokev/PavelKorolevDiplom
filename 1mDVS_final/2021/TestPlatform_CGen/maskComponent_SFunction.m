set_param(gcb, 'FunctionName', 'Component_SFunction', 'parameters','components_Component_PID_instance_cP_Max components_Component_PID_instance_cP_Min components_Component_PID_instance_cI_Max components_Component_PID_instance_cD_Max components_Component_PID_instance_cD_Min components_Component_PID_instance_cI_Min components_Component_RunningAverage_instance_c1 components_Component_FilterBy_instance_K2 components_Component_PID_instance_3_cP_Max components_Component_PID_instance_3_cP_Min components_Component_PID_instance_3_cI_Max components_Component_PID_instance_3_cD_Max components_Component_PID_instance_3_cD_Min components_Component_PID_instance_3_cI_Min');
set_param(gcb,'Mask','on');
labels = [];
labels = [labels, sprintf('disp(''Component_SFunction'')\n')];
labels = [labels, sprintf('port_label(''output'',1,''components.InpOut.P_Out'')\n')];
labels = [labels, sprintf('port_label(''output'',2,''components.InpOut.I_Out'')\n')];
labels = [labels, sprintf('port_label(''output'',3,''components.InpOut.D_Out'')\n')];
labels = [labels, sprintf('port_label(''input'',1,''components.Filter.TsFilter'')\n')];
labels = [labels, sprintf('port_label(''input'',2,''components.Filter.K1'')\n')];
labels = [labels, sprintf('port_label(''input'',3,''components.PID.PressSet'')\n')];
labels = [labels, sprintf('port_label(''input'',4,''components.PID.qP'')\n')];
labels = [labels, sprintf('port_label(''input'',5,''components.PID.qI'')\n')];
labels = [labels, sprintf('port_label(''input'',6,''components.PID.qD'')\n')];
labels = [labels, sprintf('port_label(''input'',7,''components.PID.TsPID'')\n')];
labels = [labels, sprintf('port_label(''input'',8,''components.InpOut.Input'')\n')];
set_param(gcb,'MaskDisplay',labels);
set_param(gcb,'InitFcn','clear Component_SFunction')
