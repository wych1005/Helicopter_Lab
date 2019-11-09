  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_6_4_P)
    ;%
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% heli_6_4_P.A_d
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_6_4_P.B_d
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 36;
	
	  ;% heli_6_4_P.C_d
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 48;
	
	  ;% heli_6_4_P.F
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 78;
	
	  ;% heli_6_4_P.Joystick_gain_x
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 82;
	
	  ;% heli_6_4_P.Joystick_gain_y
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 83;
	
	  ;% heli_6_4_P.K
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 84;
	
	  ;% heli_6_4_P.M
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 90;
	
	  ;% heli_6_4_P.P_0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 126;
	
	  ;% heli_6_4_P.Q_d
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 162;
	
	  ;% heli_6_4_P.R_d
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 198;
	
	  ;% heli_6_4_P.v
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 223;
	
	  ;% heli_6_4_P.v_s0
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 229;
	
	  ;% heli_6_4_P.x_0
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 230;
	
	  ;% heli_6_4_P.HILInitialize_analog_input_maxi
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 236;
	
	  ;% heli_6_4_P.HILInitialize_analog_input_mini
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 237;
	
	  ;% heli_6_4_P.HILInitialize_analog_output_max
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 238;
	
	  ;% heli_6_4_P.HILInitialize_analog_output_min
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 239;
	
	  ;% heli_6_4_P.HILInitialize_final_analog_outp
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 240;
	
	  ;% heli_6_4_P.HILInitialize_final_pwm_outputs
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 241;
	
	  ;% heli_6_4_P.HILInitialize_initial_analog_ou
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 242;
	
	  ;% heli_6_4_P.HILInitialize_initial_pwm_outpu
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 243;
	
	  ;% heli_6_4_P.HILInitialize_pwm_frequency
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 244;
	
	  ;% heli_6_4_P.HILInitialize_pwm_leading_deadb
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 245;
	
	  ;% heli_6_4_P.HILInitialize_pwm_trailing_dead
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 246;
	
	  ;% heli_6_4_P.HILInitialize_set_other_outputs
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 247;
	
	  ;% heli_6_4_P.HILInitialize_set_other_outpu_b
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 248;
	
	  ;% heli_6_4_P.HILInitialize_set_other_outpu_n
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 249;
	
	  ;% heli_6_4_P.HILInitialize_set_other_outp_b2
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 250;
	
	  ;% heli_6_4_P.HILInitialize_watchdog_analog_o
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 251;
	
	  ;% heli_6_4_P.HILInitialize_watchdog_pwm_outp
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 252;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% heli_6_4_P.HILReadEncoderTimebase_clock
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_6_4_P.HILInitialize_hardware_clocks
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_6_4_P.HILInitialize_initial_encoder_c
	  section.data(3).logicalSrcIdx = 33;
	  section.data(3).dtTransOffset = 4;
	
	  ;% heli_6_4_P.HILInitialize_pwm_alignment
	  section.data(4).logicalSrcIdx = 34;
	  section.data(4).dtTransOffset = 5;
	
	  ;% heli_6_4_P.HILInitialize_pwm_configuration
	  section.data(5).logicalSrcIdx = 35;
	  section.data(5).dtTransOffset = 6;
	
	  ;% heli_6_4_P.HILInitialize_pwm_modes
	  section.data(6).logicalSrcIdx = 36;
	  section.data(6).dtTransOffset = 7;
	
	  ;% heli_6_4_P.HILInitialize_pwm_polarity
	  section.data(7).logicalSrcIdx = 37;
	  section.data(7).dtTransOffset = 8;
	
	  ;% heli_6_4_P.HILInitialize_watchdog_digital_
	  section.data(8).logicalSrcIdx = 38;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% heli_6_4_P.HILInitialize_analog_input_chan
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_6_4_P.HILInitialize_analog_output_cha
	  section.data(2).logicalSrcIdx = 40;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_6_4_P.HILReadEncoderTimebase_channels
	  section.data(3).logicalSrcIdx = 41;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_6_4_P.HILWriteAnalog_channels
	  section.data(4).logicalSrcIdx = 42;
	  section.data(4).dtTransOffset = 19;
	
	  ;% heli_6_4_P.HILInitialize_encoder_channels
	  section.data(5).logicalSrcIdx = 43;
	  section.data(5).dtTransOffset = 21;
	
	  ;% heli_6_4_P.HILInitialize_pwm_channels
	  section.data(6).logicalSrcIdx = 44;
	  section.data(6).dtTransOffset = 29;
	
	  ;% heli_6_4_P.HILInitialize_quadrature
	  section.data(7).logicalSrcIdx = 45;
	  section.data(7).dtTransOffset = 37;
	
	  ;% heli_6_4_P.HILReadEncoderTimebase_samples_
	  section.data(8).logicalSrcIdx = 46;
	  section.data(8).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% heli_6_4_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_6_4_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_6_4_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_6_4_P.HILInitialize_set_analog_input_
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_6_4_P.HILInitialize_set_analog_inpu_n
	  section.data(5).logicalSrcIdx = 51;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_6_4_P.HILInitialize_set_analog_output
	  section.data(6).logicalSrcIdx = 52;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_6_4_P.HILInitialize_set_analog_outp_f
	  section.data(7).logicalSrcIdx = 53;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_6_4_P.HILInitialize_set_analog_outp_d
	  section.data(8).logicalSrcIdx = 54;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_6_4_P.HILInitialize_set_analog_outp_m
	  section.data(9).logicalSrcIdx = 55;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_6_4_P.HILInitialize_set_analog_outp_j
	  section.data(10).logicalSrcIdx = 56;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_6_4_P.HILInitialize_set_analog_out_jf
	  section.data(11).logicalSrcIdx = 57;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_6_4_P.HILInitialize_set_analog_outp_h
	  section.data(12).logicalSrcIdx = 58;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_6_4_P.HILInitialize_set_clock_frequen
	  section.data(13).logicalSrcIdx = 59;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_6_4_P.HILInitialize_set_clock_frequ_h
	  section.data(14).logicalSrcIdx = 60;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_6_4_P.HILInitialize_set_clock_params_
	  section.data(15).logicalSrcIdx = 61;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_6_4_P.HILInitialize_set_clock_param_a
	  section.data(16).logicalSrcIdx = 62;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_6_4_P.HILInitialize_set_digital_outpu
	  section.data(17).logicalSrcIdx = 63;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_6_4_P.HILInitialize_set_digital_out_p
	  section.data(18).logicalSrcIdx = 64;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_6_4_P.HILInitialize_set_digital_out_l
	  section.data(19).logicalSrcIdx = 65;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_6_4_P.HILInitialize_set_digital_out_f
	  section.data(20).logicalSrcIdx = 66;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_6_4_P.HILInitialize_set_digital_out_e
	  section.data(21).logicalSrcIdx = 67;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_6_4_P.HILInitialize_set_digital_out_j
	  section.data(22).logicalSrcIdx = 68;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_6_4_P.HILInitialize_set_digital_out_h
	  section.data(23).logicalSrcIdx = 69;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_6_4_P.HILInitialize_set_encoder_count
	  section.data(24).logicalSrcIdx = 70;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_6_4_P.HILInitialize_set_encoder_cou_n
	  section.data(25).logicalSrcIdx = 71;
	  section.data(25).dtTransOffset = 24;
	
	  ;% heli_6_4_P.HILInitialize_set_encoder_param
	  section.data(26).logicalSrcIdx = 72;
	  section.data(26).dtTransOffset = 25;
	
	  ;% heli_6_4_P.HILInitialize_set_encoder_par_o
	  section.data(27).logicalSrcIdx = 73;
	  section.data(27).dtTransOffset = 26;
	
	  ;% heli_6_4_P.HILInitialize_set_other_outpu_a
	  section.data(28).logicalSrcIdx = 74;
	  section.data(28).dtTransOffset = 27;
	
	  ;% heli_6_4_P.HILInitialize_set_pwm_outputs_a
	  section.data(29).logicalSrcIdx = 75;
	  section.data(29).dtTransOffset = 28;
	
	  ;% heli_6_4_P.HILInitialize_set_pwm_outputs_k
	  section.data(30).logicalSrcIdx = 76;
	  section.data(30).dtTransOffset = 29;
	
	  ;% heli_6_4_P.HILInitialize_set_pwm_outputs_c
	  section.data(31).logicalSrcIdx = 77;
	  section.data(31).dtTransOffset = 30;
	
	  ;% heli_6_4_P.HILInitialize_set_pwm_outputs_d
	  section.data(32).logicalSrcIdx = 78;
	  section.data(32).dtTransOffset = 31;
	
	  ;% heli_6_4_P.HILInitialize_set_pwm_outputs_o
	  section.data(33).logicalSrcIdx = 79;
	  section.data(33).dtTransOffset = 32;
	
	  ;% heli_6_4_P.HILInitialize_set_pwm_params_at
	  section.data(34).logicalSrcIdx = 80;
	  section.data(34).dtTransOffset = 33;
	
	  ;% heli_6_4_P.HILInitialize_set_pwm_params__o
	  section.data(35).logicalSrcIdx = 81;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% heli_6_4_P.Constant2_Value
	  section.data(1).logicalSrcIdx = 82;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_6_4_P.TravelCounttorad_Gain
	  section.data(2).logicalSrcIdx = 83;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_6_4_P.TravelTransferFcn_A
	  section.data(3).logicalSrcIdx = 84;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_6_4_P.TravelTransferFcn_C
	  section.data(4).logicalSrcIdx = 85;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_6_4_P.TravelTransferFcn_D
	  section.data(5).logicalSrcIdx = 86;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_6_4_P.PitchCounttorad_Gain
	  section.data(6).logicalSrcIdx = 87;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_6_4_P.Constant1_Value
	  section.data(7).logicalSrcIdx = 88;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_6_4_P.PitchTransferFcn_A
	  section.data(8).logicalSrcIdx = 89;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_6_4_P.PitchTransferFcn_C
	  section.data(9).logicalSrcIdx = 90;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_6_4_P.PitchTransferFcn_D
	  section.data(10).logicalSrcIdx = 91;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_6_4_P.Constant_Value
	  section.data(11).logicalSrcIdx = 92;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_6_4_P.ElevationCounttorad_Gain
	  section.data(12).logicalSrcIdx = 93;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_6_4_P.ElevationTransferFcn_A
	  section.data(13).logicalSrcIdx = 94;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_6_4_P.ElevationTransferFcn_C
	  section.data(14).logicalSrcIdx = 95;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_6_4_P.ElevationTransferFcn_D
	  section.data(15).logicalSrcIdx = 96;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_6_4_P.Constant_Value_e
	  section.data(16).logicalSrcIdx = 97;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_6_4_P.Constant1_Value_p
	  section.data(17).logicalSrcIdx = 98;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_6_4_P.RateTransitionx_X0
	  section.data(18).logicalSrcIdx = 99;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_6_4_P.DeadZonex_Start
	  section.data(19).logicalSrcIdx = 100;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_6_4_P.DeadZonex_End
	  section.data(20).logicalSrcIdx = 101;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_6_4_P.Gainx_Gain
	  section.data(21).logicalSrcIdx = 102;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_6_4_P.RateTransitiony_X0
	  section.data(22).logicalSrcIdx = 103;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_6_4_P.DeadZoney_Start
	  section.data(23).logicalSrcIdx = 104;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_6_4_P.DeadZoney_End
	  section.data(24).logicalSrcIdx = 105;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_6_4_P.Gainy_Gain
	  section.data(25).logicalSrcIdx = 106;
	  section.data(25).dtTransOffset = 24;
	
	  ;% heli_6_4_P.Backgain_Gain
	  section.data(26).logicalSrcIdx = 107;
	  section.data(26).dtTransOffset = 25;
	
	  ;% heli_6_4_P.Frontgain_Gain
	  section.data(27).logicalSrcIdx = 108;
	  section.data(27).dtTransOffset = 26;
	
	  ;% heli_6_4_P.Gain1_Gain
	  section.data(28).logicalSrcIdx = 109;
	  section.data(28).dtTransOffset = 27;
	
	  ;% heli_6_4_P.FrontmotorSaturation_UpperSat
	  section.data(29).logicalSrcIdx = 110;
	  section.data(29).dtTransOffset = 36;
	
	  ;% heli_6_4_P.FrontmotorSaturation_LowerSat
	  section.data(30).logicalSrcIdx = 111;
	  section.data(30).dtTransOffset = 37;
	
	  ;% heli_6_4_P.BackmotorSaturation_UpperSat
	  section.data(31).logicalSrcIdx = 112;
	  section.data(31).dtTransOffset = 38;
	
	  ;% heli_6_4_P.BackmotorSaturation_LowerSat
	  section.data(32).logicalSrcIdx = 113;
	  section.data(32).dtTransOffset = 39;
	
	  ;% heli_6_4_P.Gain2_Gain
	  section.data(33).logicalSrcIdx = 114;
	  section.data(33).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% heli_6_4_P.StreamCall1_SendBufferSize
	  section.data(1).logicalSrcIdx = 115;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_6_4_P.StreamCall1_ReceiveBufferSize
	  section.data(2).logicalSrcIdx = 116;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_6_4_P.StreamFormattedWrite_MaxUnits
	  section.data(1).logicalSrcIdx = 117;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_6_4_P.GameController_BufferSize
	  section.data(1).logicalSrcIdx = 118;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% heli_6_4_P.StringConstant_Value
	  section.data(1).logicalSrcIdx = 119;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_6_4_P.StreamCall1_URI
	  section.data(2).logicalSrcIdx = 120;
	  section.data(2).dtTransOffset = 255;
	
	  ;% heli_6_4_P.StreamCall1_Endian
	  section.data(3).logicalSrcIdx = 121;
	  section.data(3).dtTransOffset = 256;
	
	  ;% heli_6_4_P.GameController_ControllerNumber
	  section.data(4).logicalSrcIdx = 122;
	  section.data(4).dtTransOffset = 257;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% heli_6_4_P.HILReadEncoderTimebase_Active
	  section.data(1).logicalSrcIdx = 123;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_6_4_P.StreamCall1_Active
	  section.data(2).logicalSrcIdx = 124;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_6_4_P.HILWriteAnalog_Active
	  section.data(3).logicalSrcIdx = 125;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_6_4_P.GameController_AutoCenter
	  section.data(4).logicalSrcIdx = 126;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_6_4_P.GameController_Enabled
	  section.data(5).logicalSrcIdx = 127;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_6_4_B)
    ;%
      section.nData     = 32;
      section.data(32)  = dumData; %prealloc
      
	  ;% heli_6_4_B.UnitDelay1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_6_4_B.Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 36;
	
	  ;% heli_6_4_B.TravelCounttorad
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 42;
	
	  ;% heli_6_4_B.TravelTransferFcn
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 43;
	
	  ;% heli_6_4_B.PitchCounttorad
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 44;
	
	  ;% heli_6_4_B.Sum1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 45;
	
	  ;% heli_6_4_B.PitchTransferFcn
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 46;
	
	  ;% heli_6_4_B.ElevationCounttorad
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 47;
	
	  ;% heli_6_4_B.Sum
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 48;
	
	  ;% heli_6_4_B.ElevationTransferFcn
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 49;
	
	  ;% heli_6_4_B.UnitDelay
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 50;
	
	  ;% heli_6_4_B.Sum3
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 56;
	
	  ;% heli_6_4_B.Constant1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 62;
	
	  ;% heli_6_4_B.RateTransitionx
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 63;
	
	  ;% heli_6_4_B.Joystick_gain_x
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 64;
	
	  ;% heli_6_4_B.RateTransitiony
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 65;
	
	  ;% heli_6_4_B.Joystick_gain_y
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 66;
	
	  ;% heli_6_4_B.Gain_g
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 67;
	
	  ;% heli_6_4_B.Gain1
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 69;
	
	  ;% heli_6_4_B.FrontmotorSaturation
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 72;
	
	  ;% heli_6_4_B.BackmotorSaturation
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 73;
	
	  ;% heli_6_4_B.GameController_o4
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 74;
	
	  ;% heli_6_4_B.GameController_o5
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 75;
	
	  ;% heli_6_4_B.Constant
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 76;
	
	  ;% heli_6_4_B.Constant1_o
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 112;
	
	  ;% heli_6_4_B.Constant2
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 148;
	
	  ;% heli_6_4_B.Constant3
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 160;
	
	  ;% heli_6_4_B.Constant4
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 190;
	
	  ;% heli_6_4_B.pp
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 215;
	
	  ;% heli_6_4_B.ee
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 216;
	
	  ;% heli_6_4_B.xk1
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 217;
	
	  ;% heli_6_4_B.Pk1
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 223;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_6_4_B.StreamCall1_o2
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_6_4_B.StreamRead1_o3
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_6_4_DW)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% heli_6_4_DW.UnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_6_4_DW.UnitDelay_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 36;
	
	  ;% heli_6_4_DW.HILInitialize_AIMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 42;
	
	  ;% heli_6_4_DW.HILInitialize_AIMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 50;
	
	  ;% heli_6_4_DW.HILInitialize_AOMinimums
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 58;
	
	  ;% heli_6_4_DW.HILInitialize_AOMaximums
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 66;
	
	  ;% heli_6_4_DW.HILInitialize_AOVoltages
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 74;
	
	  ;% heli_6_4_DW.HILInitialize_FilterFrequency
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 82;
	
	  ;% heli_6_4_DW.HILInitialize_POSortedFreqs
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 90;
	
	  ;% heli_6_4_DW.HILInitialize_POValues
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 98;
	
	  ;% heli_6_4_DW.RateTransitionx_Buffer0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 106;
	
	  ;% heli_6_4_DW.RateTransitiony_Buffer0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 107;
	
	  ;% heli_6_4_DW.HILWriteAnalog_Buffer
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 108;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_6_4_DW.StreamCall1_Stream
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_6_4_DW.GameController_Controller
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_6_4_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_6_4_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% heli_6_4_DW.p_diag_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_6_4_DW.diff_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_6_4_DW.e_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_6_4_DW.e_dot_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_6_4_DW.kalman_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_6_4_DW.new_data_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_6_4_DW.p_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_6_4_DW.p_dot_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_6_4_DW.t_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 25;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_6_4_DW.t_dot_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 26;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_6_4_DW.ElevationScoperads_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 27;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_6_4_DW.ElevationScoperad_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 28;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_6_4_DW.PitchScoperad_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 29;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_6_4_DW.PtichrateScoperads_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 30;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_6_4_DW.TravelrateScoperads_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 31;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_6_4_DW.TravelScoperad_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 32;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_6_4_DW.HILWriteAnalog_PWORK
	  section.data(17).logicalSrcIdx = 33;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_6_4_DW.Connected_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 34;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_6_4_DW.XScope_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 35;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_6_4_DW.YScope_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 36;
	  section.data(20).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% heli_6_4_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_6_4_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_6_4_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 11;
	
	  ;% heli_6_4_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 40;
	  section.data(4).dtTransOffset = 19;
	
	  ;% heli_6_4_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 41;
	  section.data(5).dtTransOffset = 27;
	
	  ;% heli_6_4_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 42;
	  section.data(6).dtTransOffset = 35;
	
	  ;% heli_6_4_DW.HILReadEncoderTimebase_Buffer
	  section.data(7).logicalSrcIdx = 43;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_6_4_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_6_4_DW.StreamCall1_State
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3752482428;
  targMap.checksum1 = 3514387721;
  targMap.checksum2 = 629279568;
  targMap.checksum3 = 2329471468;

