/*
 * model6_rwp_private.h
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "model6_rwp".
 *
 * Model version              : 1.32
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Sat Dec 09 18:13:25 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_model6_rwp_private_h_
#define RTW_HEADER_model6_rwp_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "c6xen.h"
#include "c6xpwm.h"

extern real_T rt_modd_snf(real_T u0, real_T u1);

/* private model entry point functions */
extern void model6_rwp_derivatives(void);

#endif                                 /* RTW_HEADER_model6_rwp_private_h_ */
