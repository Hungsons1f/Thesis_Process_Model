  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
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
    ;% Auto data (rtP)
    ;%
      section.nData     = 99;
      section.data(99)  = dumData; %prealloc
      
	  ;% rtP.SliderGain_gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.SliderGain1_gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.Gain3_Gain
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.Switch1_Threshold
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.Gain3_Gain_mhi1gc12x1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.Switch1_Threshold_gztv0arq0y
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.Constant7_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.Gianhithp_A
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.Gianhithp_C
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.Lulngchtlng_A
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.Lulngchtlng_C
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.Gain2_Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.Gain1_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtP.Switch_Threshold
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtP.Gianhitcaop_A
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtP.Gianhitcaop_C
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtP.Gianhitcaop_A_gp1isrh1zt
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtP.Gianhitcaop_C_cuxjfl0bny
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtP.Lulngchtlng_A_lttlvilq1r
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtP.Lulngchtlng_C_byw0yw2g0l
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtP.Gain2_Gain_dt33lrcogy
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtP.Gain1_Gain_ajrshsszpr
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtP.Switch_Threshold_bfiwed5r3a
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtP.Bhm_A
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtP.Bhm_C
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtP.Water_Heat_Absorbing_A
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtP.Water_Heat_Absorbing_C
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtP.psutbmnn_A
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtP.psutbmnn_C
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtP.Constant_Value
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% rtP.Tuabinhp_A
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% rtP.Tuabinhp_C
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% rtP.Tuabinhp_A_p4fqdq0nyf
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% rtP.Tuabinhp_C_iunwv5jncy
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% rtP.Tlcaop_A
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% rtP.Tlcaop_C
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% rtP.Tltrungp_A
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% rtP.Tltrungp_C
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% rtP.Tlhp_A
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% rtP.Tlhp_C
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% rtP.linhittc_Gain
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% rtP.Ngngt_A
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% rtP.Ngngt_C
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% rtP.psutbmnn_A_krrl5senh5
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% rtP.psutbmnn_C_fpy55gg1x5
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% rtP.Constant_Value_gi4rxypddg
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% rtP.Vit_A
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
	  ;% rtP.Vit_C
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 47;
	
	  ;% rtP.Overheated_Pressure_A
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 48;
	
	  ;% rtP.Overheated_Pressure_C
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 49;
	
	  ;% rtP.Gain3_Gain_nyi3yuqbkz
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 50;
	
	  ;% rtP.Motor_A
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 51;
	
	  ;% rtP.Motor_C
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 53;
	
	  ;% rtP.Motor_A_mm1y0efbc2
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 55;
	
	  ;% rtP.Motor_C_bulm522rai
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 57;
	
	  ;% rtP.Condense_Flow_A
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 59;
	
	  ;% rtP.Condense_Flow_C
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 60;
	
	  ;% rtP.Motor_A_d5m4c15oua
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 61;
	
	  ;% rtP.Motor_C_nowl0zxxl1
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 63;
	
	  ;% rtP.Constant2_Value
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 65;
	
	  ;% rtP.Constant3_Value
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 66;
	
	  ;% rtP.Constant4_Value
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 67;
	
	  ;% rtP.Constant5_Value
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 68;
	
	  ;% rtP.Constant6_Value
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 69;
	
	  ;% rtP.Constant8_Value
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 70;
	
	  ;% rtP.Heat_Power_A
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 71;
	
	  ;% rtP.Heat_Power_C
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 72;
	
	  ;% rtP.Motor_A_bv5eyzqlpk
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 73;
	
	  ;% rtP.Motor_C_khazapi3pb
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 75;
	
	  ;% rtP.Heat_Power_A_egs5tnb4gq
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 77;
	
	  ;% rtP.Heat_Power_C_n44yvipdtx
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 78;
	
	  ;% rtP.Motor_A_adem45aw5v
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 79;
	
	  ;% rtP.Motor_C_eszjmj2kpa
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 81;
	
	  ;% rtP.Heat_Power_A_mwhpd1vf2d
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 83;
	
	  ;% rtP.Heat_Power_C_jpuwdm244t
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 84;
	
	  ;% rtP.Motor_A_eeuscavczf
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 85;
	
	  ;% rtP.Motor_C_b3zi30mm3g
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 87;
	
	  ;% rtP.Saturation_UpperSat
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 89;
	
	  ;% rtP.Saturation_LowerSat
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 90;
	
	  ;% rtP.Btisy_A
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 91;
	
	  ;% rtP.Btisy_C
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 92;
	
	  ;% rtP.Tuabincaop_A
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 93;
	
	  ;% rtP.Tuabincaop_C
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 94;
	
	  ;% rtP.Tuabintrungp_A
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 95;
	
	  ;% rtP.Tuabintrungp_C
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 96;
	
	  ;% rtP.Tuabincaop_A_nvs4biyz0y
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 97;
	
	  ;% rtP.Tuabincaop_C_pab1ysi2qy
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 98;
	
	  ;% rtP.Tuabintrungp_A_ir4nhbzr3q
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 99;
	
	  ;% rtP.Tuabintrungp_C_ijxomeac24
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 100;
	
	  ;% rtP.Motor_1_A
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 101;
	
	  ;% rtP.Motor_1_C
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 103;
	
	  ;% rtP.Constant1_Value
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 105;
	
	  ;% rtP.Constant9_Value
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 106;
	
	  ;% rtP.SFunction_P1_Size
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 107;
	
	  ;% rtP.SFunction_P1
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 109;
	
	  ;% rtP.SFunction_P2_Size
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 115;
	
	  ;% rtP.SFunction_P2
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 117;
	
	  ;% rtP.ngcAC_A
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 118;
	
	  ;% rtP.ngcAC_C
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 120;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
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
    nTotSects     = 1;
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
    ;% Auto data (rtB)
    ;%
      section.nData     = 36;
      section.data(36)  = dumData; %prealloc
      
	  ;% rtB.aoca5q4ss2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.htwqr5zjg1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.dbs5szu3hu
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.jnen5c5srs
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.ft5o21avnp
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.b2pbu1n1pm
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.p2bs4tz44d
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.ho5gmcpx2t
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.nruvz0bur4
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtB.on3fvwdnfd
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtB.iesin1c131
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtB.bszztyqh40
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtB.jpo2be3j0l
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtB.icvzkup4wn
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtB.ihxxraqvfh
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtB.ekiqmr4xcv
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtB.fio2xdkn1t
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtB.exaaxqgjgy
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtB.kcbltgbeur
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtB.omytbhyzix
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtB.eoa4dk2j0w
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtB.cchttyvd1o
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtB.fq23gpnbhd
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtB.nnhqtkzwq5
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtB.o2l0ex0xfl
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtB.nqcqxfnc1r
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtB.isyon0iaye
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtB.phn44qhkql
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtB.h0kzcipt5k
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtB.ms0vucqlor
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% rtB.lqhuiqwr05
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% rtB.orrmcemgc5
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% rtB.fyo1xeq1wv
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% rtB.oagbppphto
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% rtB.getjyqkigw
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% rtB.j0mkgu2zq5
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
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
    nTotSects     = 1;
    sectIdxOffset = 1;
    
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
    ;% Auto data (rtDW)
    ;%
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% rtDW.e1t4qyehrf.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.etpmimicw0.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.ji1fugwwrl.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.kovfu253ai.LoggedData
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.f5g5xdl1oy.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.b0zv3wapek.LoggedData
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.o3tyvlszgf.LoggedData
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.bapp2mfa1m.LoggedData
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.galwthsbgm.LoggedData
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.kyctkwcfhr.LoggedData
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.grorg2vqze.LoggedData
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.bywoy3pnfd.LoggedData
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.nfufv2zpqr.LoggedData
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.d2qkeekeuc.LoggedData
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDW.dljstdvhan.LoggedData
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDW.cmcyeswwml.LoggedData
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
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


  targMap.checksum0 = 499643481;
  targMap.checksum1 = 3733294652;
  targMap.checksum2 = 3467698729;
  targMap.checksum3 = 550543215;

