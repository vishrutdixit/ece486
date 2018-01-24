/*
 * model5_rwp.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "model5_rwp".
 *
 * Model version              : 1.31
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Dec 06 16:37:41 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model5_rwp.h"
#include "model5_rwp_private.h"
#include "model5_rwp_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.005, 0.0,
};

/* Block signals (auto storage) */
B_model5_rwp_T model5_rwp_B;

/* Continuous states */
X_model5_rwp_T model5_rwp_X;

/* Real-time model */
RT_MODEL_model5_rwp_T model5_rwp_M_;
RT_MODEL_model5_rwp_T *const model5_rwp_M = &model5_rwp_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  model5_rwp_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void model5_rwp_output(void)
{
  int_T iy;
  real_T rtb_Gain;
  real_T rtb_Gain2_0;
  if (rtmIsMajorTimeStep(model5_rwp_M)) {
    /* set solver stop time */
    if (!(model5_rwp_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&model5_rwp_M->solverInfo,
                            ((model5_rwp_M->Timing.clockTickH0 + 1) *
        model5_rwp_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&model5_rwp_M->solverInfo,
                            ((model5_rwp_M->Timing.clockTick0 + 1) *
        model5_rwp_M->Timing.stepSize0 + model5_rwp_M->Timing.clockTickH0 *
        model5_rwp_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(model5_rwp_M)) {
    model5_rwp_M->Timing.t[0] = rtsiGetT(&model5_rwp_M->solverInfo);
  }

  /* Gain: '<Root>/Gain2' */
  rtb_Gain2_0 = 0.0;
  for (iy = 0; iy < 4; iy++) {
    /* StateSpace: '<Root>/State-Space' */
    rtb_Gain = model5_rwp_P.StateSpace_C[12 + iy] *
      model5_rwp_X.StateSpace_CSTATE[3] + (model5_rwp_P.StateSpace_C[8 + iy] *
      model5_rwp_X.StateSpace_CSTATE[2] + (model5_rwp_P.StateSpace_C[4 + iy] *
      model5_rwp_X.StateSpace_CSTATE[1] + model5_rwp_P.StateSpace_C[iy] *
      model5_rwp_X.StateSpace_CSTATE[0]));

    /* Gain: '<Root>/Gain2' */
    rtb_Gain2_0 += -model5_rwp_P.K[iy] * rtb_Gain;
  }

  /* Gain: '<Root>/Gain5' incorporates:
   *  Gain: '<Root>/Gain2'
   */
  model5_rwp_B.Gain5 = model5_rwp_P.Gain5_Gain * rtb_Gain2_0;
  if (rtmIsMajorTimeStep(model5_rwp_M)) {
    /* S-Function (c6xpwm): '<S2>/S-function' */
    /* S-Function Block: <Root>/PWM Output (c6xpwm) */
    {
      int16_T value;
      value = C6X_pwmArbUnitsToOutput(model5_rwp_B.Gain5);
      C6X_pwmOutput(0x378, (uint_T)model5_rwp_P.PWMOutput_channels, value);
    }

    /* S-Function (c6xen): '<S1>/S-function' */
    /* S-Function Block: <Root>/Encoder Input (c6xen) */
    {
      model5_rwp_B.Sfunction[0] = C6X_encInput(0x378, (uint_T)
        model5_rwp_P.EncoderInput_channels[0]);
      model5_rwp_B.Sfunction[1] = C6X_encInput(0x378, (uint_T)
        model5_rwp_P.EncoderInput_channels[1]);
    }

    /* Gain: '<Root>/Gain' */
    rtb_Gain = model5_rwp_P.Gain_Gain * model5_rwp_B.Sfunction[0];

    /* Sum: '<Root>/Add' incorporates:
     *  Gain: '<Root>/Gain1'
     */
    model5_rwp_B.Add = model5_rwp_P.Gain1_Gain * model5_rwp_B.Sfunction[1] +
      rtb_Gain;

    /* Sum: '<Root>/Add2' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    model5_rwp_B.Add2 = rtb_Gain - model5_rwp_P.Constant1_Value;
  }

  /* SignalConversion: '<Root>/TmpSignal ConversionAtState-SpaceInport1' incorporates:
   *  Gain: '<Root>/Gain2'
   */
  model5_rwp_B.TmpSignalConversionAtStateSpaceInport1[0] = rtb_Gain2_0;
  model5_rwp_B.TmpSignalConversionAtStateSpaceInport1[1] = model5_rwp_B.Add2;
  model5_rwp_B.TmpSignalConversionAtStateSpaceInport1[2] = model5_rwp_B.Add;
}

/* Model update function */
void model5_rwp_update(void)
{
  if (rtmIsMajorTimeStep(model5_rwp_M)) {
    rt_ertODEUpdateContinuousStates(&model5_rwp_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++model5_rwp_M->Timing.clockTick0)) {
    ++model5_rwp_M->Timing.clockTickH0;
  }

  model5_rwp_M->Timing.t[0] = rtsiGetSolverStopTime(&model5_rwp_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++model5_rwp_M->Timing.clockTick1)) {
      ++model5_rwp_M->Timing.clockTickH1;
    }

    model5_rwp_M->Timing.t[1] = model5_rwp_M->Timing.clockTick1 *
      model5_rwp_M->Timing.stepSize1 + model5_rwp_M->Timing.clockTickH1 *
      model5_rwp_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void model5_rwp_derivatives(void)
{
  int_T is;
  XDot_model5_rwp_T *_rtXdot;
  _rtXdot = ((XDot_model5_rwp_T *) model5_rwp_M->derivs);

  /* Derivatives for StateSpace: '<Root>/State-Space' */
  for (is = 0; is < 4; is++) {
    _rtXdot->StateSpace_CSTATE[is] = 0.0;
    _rtXdot->StateSpace_CSTATE[is] += (model5_rwp_P.A[is] -
      model5_rwp_ConstP.StateSpace_rtw_collapsed_sub_expr_3[is]) *
      model5_rwp_X.StateSpace_CSTATE[0];
    _rtXdot->StateSpace_CSTATE[is] += (model5_rwp_P.A[4 + is] -
      model5_rwp_ConstP.StateSpace_rtw_collapsed_sub_expr_3[4 + is]) *
      model5_rwp_X.StateSpace_CSTATE[1];
    _rtXdot->StateSpace_CSTATE[is] += (model5_rwp_P.A[8 + is] -
      model5_rwp_ConstP.StateSpace_rtw_collapsed_sub_expr_3[8 + is]) *
      model5_rwp_X.StateSpace_CSTATE[2];
    _rtXdot->StateSpace_CSTATE[is] += (model5_rwp_P.A[12 + is] -
      model5_rwp_ConstP.StateSpace_rtw_collapsed_sub_expr_3[12 + is]) *
      model5_rwp_X.StateSpace_CSTATE[3];
    _rtXdot->StateSpace_CSTATE[is] += model5_rwp_P.StateSpace_B[is] *
      model5_rwp_B.TmpSignalConversionAtStateSpaceInport1[0];
    _rtXdot->StateSpace_CSTATE[is] += model5_rwp_P.StateSpace_B[4 + is] *
      model5_rwp_B.TmpSignalConversionAtStateSpaceInport1[1];
    _rtXdot->StateSpace_CSTATE[is] += model5_rwp_P.StateSpace_B[8 + is] *
      model5_rwp_B.TmpSignalConversionAtStateSpaceInport1[2];
  }

  /* End of Derivatives for StateSpace: '<Root>/State-Space' */
}

/* Model initialize function */
void model5_rwp_initialize(void)
{
  /* Start for S-Function (c6xpwm): '<S2>/S-function' */

  /* S-Function Block: <Root>/PWM Output (c6xpwm) */
  {
    int16_T value;
    value = C6X_pwmArbUnitsToOutput(model5_rwp_P.PWMOutput_initialOutputs);
    C6X_pwmOutput(0x378, (uint_T)model5_rwp_P.PWMOutput_channels, value);
  }

  /* Start for S-Function (c6xen): '<S1>/S-function' */

  /* S-Function Block: <Root>/Encoder Input (c6xen) */
  {
    C6X_encResetAll(0x378);
  }

  /* InitializeConditions for StateSpace: '<Root>/State-Space' */
  model5_rwp_X.StateSpace_CSTATE[0] = model5_rwp_P.StateSpace_X0;
  model5_rwp_X.StateSpace_CSTATE[1] = model5_rwp_P.StateSpace_X0;
  model5_rwp_X.StateSpace_CSTATE[2] = model5_rwp_P.StateSpace_X0;
  model5_rwp_X.StateSpace_CSTATE[3] = model5_rwp_P.StateSpace_X0;
}

/* Model terminate function */
void model5_rwp_terminate(void)
{
  /* Terminate for S-Function (c6xpwm): '<S2>/S-function' */

  /* S-Function Block: <Root>/PWM Output (c6xpwm) */
  {
    int16_T value;
    value = C6X_pwmArbUnitsToOutput(model5_rwp_P.PWMOutput_finalOutputs);
    C6X_pwmOutput(0x378, (uint_T)model5_rwp_P.PWMOutput_channels, value);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  model5_rwp_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  model5_rwp_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  model5_rwp_initialize();
}

void MdlTerminate(void)
{
  model5_rwp_terminate();
}

/* Registration function */
RT_MODEL_model5_rwp_T *model5_rwp(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)model5_rwp_M, 0,
                sizeof(RT_MODEL_model5_rwp_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&model5_rwp_M->solverInfo,
                          &model5_rwp_M->Timing.simTimeStep);
    rtsiSetTPtr(&model5_rwp_M->solverInfo, &rtmGetTPtr(model5_rwp_M));
    rtsiSetStepSizePtr(&model5_rwp_M->solverInfo,
                       &model5_rwp_M->Timing.stepSize0);
    rtsiSetdXPtr(&model5_rwp_M->solverInfo, &model5_rwp_M->derivs);
    rtsiSetContStatesPtr(&model5_rwp_M->solverInfo, (real_T **)
                         &model5_rwp_M->contStates);
    rtsiSetNumContStatesPtr(&model5_rwp_M->solverInfo,
      &model5_rwp_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&model5_rwp_M->solverInfo,
      &model5_rwp_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&model5_rwp_M->solverInfo,
      &model5_rwp_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&model5_rwp_M->solverInfo,
      &model5_rwp_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&model5_rwp_M->solverInfo, (&rtmGetErrorStatus
      (model5_rwp_M)));
    rtsiSetRTModelPtr(&model5_rwp_M->solverInfo, model5_rwp_M);
  }

  rtsiSetSimTimeStep(&model5_rwp_M->solverInfo, MAJOR_TIME_STEP);
  model5_rwp_M->intgData.f[0] = model5_rwp_M->odeF[0];
  model5_rwp_M->contStates = ((real_T *) &model5_rwp_X);
  rtsiSetSolverData(&model5_rwp_M->solverInfo, (void *)&model5_rwp_M->intgData);
  rtsiSetSolverName(&model5_rwp_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = model5_rwp_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    model5_rwp_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    model5_rwp_M->Timing.sampleTimes = (&model5_rwp_M->Timing.sampleTimesArray[0]);
    model5_rwp_M->Timing.offsetTimes = (&model5_rwp_M->Timing.offsetTimesArray[0]);

    /* task periods */
    model5_rwp_M->Timing.sampleTimes[0] = (0.0);
    model5_rwp_M->Timing.sampleTimes[1] = (0.005);

    /* task offsets */
    model5_rwp_M->Timing.offsetTimes[0] = (0.0);
    model5_rwp_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(model5_rwp_M, &model5_rwp_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = model5_rwp_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    model5_rwp_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(model5_rwp_M, 3000.0);
  model5_rwp_M->Timing.stepSize0 = 0.005;
  model5_rwp_M->Timing.stepSize1 = 0.005;

  /* External mode info */
  model5_rwp_M->Sizes.checksums[0] = (3252385640U);
  model5_rwp_M->Sizes.checksums[1] = (2585186719U);
  model5_rwp_M->Sizes.checksums[2] = (1725129793U);
  model5_rwp_M->Sizes.checksums[3] = (1849201612U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    model5_rwp_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(model5_rwp_M->extModeInfo,
      &model5_rwp_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(model5_rwp_M->extModeInfo, model5_rwp_M->Sizes.checksums);
    rteiSetTPtr(model5_rwp_M->extModeInfo, rtmGetTPtr(model5_rwp_M));
  }

  model5_rwp_M->solverInfoPtr = (&model5_rwp_M->solverInfo);
  model5_rwp_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&model5_rwp_M->solverInfo, 0.005);
  rtsiSetSolverMode(&model5_rwp_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  model5_rwp_M->blockIO = ((void *) &model5_rwp_B);

  {
    model5_rwp_B.Gain5 = 0.0;
    model5_rwp_B.Sfunction[0] = 0.0;
    model5_rwp_B.Sfunction[1] = 0.0;
    model5_rwp_B.Add = 0.0;
    model5_rwp_B.Add2 = 0.0;
    model5_rwp_B.TmpSignalConversionAtStateSpaceInport1[0] = 0.0;
    model5_rwp_B.TmpSignalConversionAtStateSpaceInport1[1] = 0.0;
    model5_rwp_B.TmpSignalConversionAtStateSpaceInport1[2] = 0.0;
  }

  /* parameters */
  model5_rwp_M->defaultParam = ((real_T *)&model5_rwp_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &model5_rwp_X;
    model5_rwp_M->contStates = (x);
    (void) memset((void *)&model5_rwp_X, 0,
                  sizeof(X_model5_rwp_T));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    model5_rwp_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  model5_rwp_M->Sizes.numContStates = (4);/* Number of continuous states */
  model5_rwp_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  model5_rwp_M->Sizes.numY = (0);      /* Number of model outputs */
  model5_rwp_M->Sizes.numU = (0);      /* Number of model inputs */
  model5_rwp_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  model5_rwp_M->Sizes.numSampTimes = (2);/* Number of sample times */
  model5_rwp_M->Sizes.numBlocks = (11);/* Number of blocks */
  model5_rwp_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  model5_rwp_M->Sizes.numBlockPrms = (58);/* Sum of parameter "widths" */
  return model5_rwp_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
