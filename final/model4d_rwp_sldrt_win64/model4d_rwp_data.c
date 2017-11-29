/*
 * model4d_rwp_data.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "model4d_rwp".
 *
 * Model version              : 1.29
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Nov 29 17:13:30 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model4d_rwp.h"
#include "model4d_rwp_private.h"

/* Block parameters (auto storage) */
P_model4d_rwp_T model4d_rwp_P = {
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
  3.1415926535897931,                  /* Expression: pi
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
  23.11,                               /* Expression: 23.11
                                        * Referenced by: '<Root>/Gain3'
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
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S1>/Switch2'
                                        */
  0.0448,                              /* Expression: 0.0448
                                        * Referenced by: '<Root>/Gain4'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -10.0                                /* Expression: -10
                                        * Referenced by: '<Root>/Saturation'
                                        */
};
