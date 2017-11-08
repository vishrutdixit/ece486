/*
 * lead_rtwin486_data.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "lead_rtwin486".
 *
 * Model version              : 1.28
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Nov 08 15:50:53 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lead_rtwin486.h"
#include "lead_rtwin486_private.h"

/* Block parameters (auto storage) */
P_lead_rtwin486_T lead_rtwin486_P = {
  3.0,                                 /* Variable: Kc
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.005,                               /* Variable: Tp
                                        * Referenced by: '<Root>/Gain1'
                                        */
  0.1,                                 /* Variable: Tz
                                        * Referenced by: '<Root>/Gain2'
                                        */
  0.0048828125,                        /* Expression: 10/2048
                                        * Referenced by: '<S2>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  0.0048828125                         /* Expression: 10/2048
                                        * Referenced by: '<S2>/Gain3'
                                        */
};
