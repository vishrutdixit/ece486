/*
 * model2b_data.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "model2b".
 *
 * Model version              : 1.30
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Nov 29 15:07:03 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model2b.h"
#include "model2b_private.h"

/* Block parameters (auto storage) */
P_model2b_T model2b_P = {
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
  0.40333333333333332,                 /* Mask Parameter: AsymmetricLinearFriction_intercept1
                                        * Referenced by: '<S1>/Constant'
                                        */
  -0.44666666666666666,                /* Mask Parameter: AsymmetricLinearFriction_intercept2
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0084,                              /* Mask Parameter: AsymmetricLinearFriction_slope1
                                        * Referenced by: '<S1>/B1'
                                        */
  0.0085333333333333337,               /* Mask Parameter: AsymmetricLinearFriction_slope2
                                        * Referenced by: '<S1>/B2'
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
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain7'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Gain2'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/No Compensation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<Root>/Gain4'
                                        */
  -0.0012566370614359172,              /* Expression: -2*pi/5000
                                        * Referenced by: '<Root>/Gain'
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
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  200.0,                               /* Expression: 1/(str2num(get_param(bdroot,'FixedStep')))
                                        * Referenced by: '<Root>/Gain6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/No Compensation1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain5'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */
  0U                                   /* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch2'
                                        */
};
