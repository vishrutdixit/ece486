/*
 * model6_rwp_data.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "model6_rwp".
 *
 * Model version              : 1.31
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Dec 06 17:28:25 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model6_rwp.h"
#include "model6_rwp_private.h"

/* Block parameters (auto storage) */
P_model6_rwp_T model6_rwp_P = {
  /*  Variable: A
   * Referenced by: '<Root>/State-Space'
   */
  { 0.0, 77.64, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0 },

  /*  Variable: K
   * Referenced by: '<Root>/Gain2'
   */
  { -245.349859883669, -23.1081009193599, 0.0, -0.044790251629964091 },
  0.0,                                 /* Mask Parameter: PWMOutput_channels
                                        * Referenced by: '<S2>/S-function'
                                        */

  /*  Mask Parameter: EncoderInput_channels
   * Referenced by: '<S1>/S-function'
   */
  { 0.0, 1.0 },
  0.0,                                 /* Mask Parameter: PWMOutput_finalOutputs
                                        * Referenced by: '<S2>/S-function'
                                        */
  0.0,                                 /* Mask Parameter: PWMOutput_initialOutputs
                                        * Referenced by: '<S2>/S-function'
                                        */
  3.1235926535897933,                  /* Expression: pi-0.018
                                        * Referenced by: '<Root>/Constant1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<Root>/Constant2'
                                        */

  /*  Expression: [B L]
   * Referenced by: '<Root>/State-Space'
   */
  { 0.0, -0.9278, 0.0, 143.7745, 102.75917690055061, 2715.7839163672515, 0.0,
    0.0, 0.0, 0.0, 102.24082309944191, 2612.2916541014656 },

  /*  Expression: eye(4)
   * Referenced by: '<Root>/State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/State-Space'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain5'
                                        */
  -0.0012566370614359172,              /* Expression: -2*pi/5000
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.0015707963267948967,               /* Expression: 2*pi/4000
                                        * Referenced by: '<Root>/Gain1'
                                        */
  -1.5707963267948966                  /* Expression: -1*pi/2
                                        * Referenced by: '<Root>/Switch'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_model6_rwp_T model6_rwp_ConstP = {
  /* Expression: A-(L*C)
   * Referenced by: '<Root>/State-Space'
   */
  { 102.75917690055061, 2715.7839163672515, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 102.24082309944191, 2612.2916541014656, 0.0, 0.0, 0.0, 0.0 }
};
