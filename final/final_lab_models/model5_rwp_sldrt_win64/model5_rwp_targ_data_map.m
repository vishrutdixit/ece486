  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
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
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (model5_rwp_P)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% model5_rwp_P.A
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model5_rwp_P.K
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 16;
	
	  ;% model5_rwp_P.PWMOutput_channels
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 20;
	
	  ;% model5_rwp_P.EncoderInput_channels
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 21;
	
	  ;% model5_rwp_P.PWMOutput_finalOutputs
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 23;
	
	  ;% model5_rwp_P.PWMOutput_initialOutputs
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 24;
	
	  ;% model5_rwp_P.StateSpace_B
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 25;
	
	  ;% model5_rwp_P.StateSpace_C
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 37;
	
	  ;% model5_rwp_P.StateSpace_X0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 53;
	
	  ;% model5_rwp_P.Gain5_Gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 54;
	
	  ;% model5_rwp_P.Gain_Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 55;
	
	  ;% model5_rwp_P.Gain1_Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 56;
	
	  ;% model5_rwp_P.Constant1_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 57;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
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
    ;% Auto data (model5_rwp_B)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% model5_rwp_B.Gain5
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% model5_rwp_B.Sfunction
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% model5_rwp_B.Add
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% model5_rwp_B.Add2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% model5_rwp_B.TmpSignalConversionAtStateSpaceInport1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
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
    nTotSects     = 0;
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
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (model5_rwp_DW)
    ;%
    
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


  targMap.checksum0 = 3252385640;
  targMap.checksum1 = 2585186719;
  targMap.checksum2 = 1725129793;
  targMap.checksum3 = 1849201612;

