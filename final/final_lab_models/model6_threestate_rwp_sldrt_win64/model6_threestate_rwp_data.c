/*
 * model6_threestate_rwp_data.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "model6_threestate_rwp".
 *
 * Model version              : 1.33
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Dec 13 14:52:21 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model6_threestate_rwp.h"
#include "model6_threestate_rwp_private.h"

/* Block parameters (auto storage) */
P_model6_threestate_rwp_T model6_threestate_rwp_P = {
  /*  Mask Parameter: EncoderInput_channels
   * Referenced by: '<S2>/S-function'
   */
  { 0.0, 1.0 },
  0.0,                                 /* Mask Parameter: PWMOutput_channels
                                        * Referenced by: '<S3>/S-function'
                                        */
  0.0,                                 /* Mask Parameter: PWMOutput_finalOutputs
                                        * Referenced by: '<S3>/S-function'
                                        */
  0.0,                                 /* Mask Parameter: PWMOutput_initialOutputs
                                        * Referenced by: '<S3>/S-function'
                                        */
  0.40333333333333332,                 /* Mask Parameter: AsymmetricLinearFriction1_intercept1
                                        * Referenced by: '<S1>/Constant'
                                        */
  -0.44666666666666666,                /* Mask Parameter: AsymmetricLinearFriction1_intercept2
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0084,                              /* Mask Parameter: AsymmetricLinearFriction1_slope1
                                        * Referenced by: '<S1>/B1'
                                        */
  0.0085333333333333337,               /* Mask Parameter: AsymmetricLinearFriction1_slope2
                                        * Referenced by: '<S1>/B2'
                                        */
  23.11,                               /* Expression: 23.11
                                        * Referenced by: '<Root>/Gain7'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S1>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S1>/Switch2'
                                        */
  0.0448,                              /* Expression: 0.0448
                                        * Referenced by: '<Root>/Gain4'
                                        */
  23.11,                               /* Expression: 23.11
                                        * Referenced by: '<Root>/Gain3'
                                        */
  3.1315926535897933,                  /* Expression: pi-0.01
                                        * Referenced by: '<Root>/Constant1'
                                        */
  -0.0012566370614359172,              /* Expression: -2*pi/5000
                                        * Referenced by: '<Root>/Gain'
                                        */
  245.35,                              /* Expression: 245.35
                                        * Referenced by: '<Root>/Gain2'
                                        */
  -50.0,                               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  -2500.0,                             /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  50.0,                                /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  0.0015707963267948967,               /* Expression: 2*pi/4000
                                        * Referenced by: '<Root>/Gain1'
                                        */
  -50.0,                               /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  -2500.0,                             /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  50.0,                                /* Computed Parameter: TransferFcn_D
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  245.35,                              /* Expression: 245.35
                                        * Referenced by: '<Root>/Gain5'
                                        */
  1.5707963267948966,                  /* Expression: pi/2
                                        * Referenced by: '<Root>/Switch1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain6'
                                        */
  1U                                   /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
};
