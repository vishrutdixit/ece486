/*
 * model6_threestate.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "model6_threestate".
 *
 * Model version              : 1.31
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Sat Dec 09 18:47:49 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model6_threestate.h"
#include "model6_threestate_private.h"
#include "model6_threestate_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.005, 0.0,
};

/* Block signals (auto storage) */
B_model6_threestate_T model6_threestate_B;

/* Continuous states */
X_model6_threestate_T model6_threestate_X;

/* Block states (auto storage) */
DW_model6_threestate_T model6_threestate_DW;

/* Real-time model */
RT_MODEL_model6_threestate_T model6_threestate_M_;
RT_MODEL_model6_threestate_T *const model6_threestate_M = &model6_threestate_M_;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  model6_threestate_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  boolean_T yEq;
  real_T q;
  y = u0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    if (u1 != 0.0) {
      y = (rtNaN);
    }
  } else if (u0 == 0.0) {
    y = u1 * 0.0;
  } else {
    if (u1 != 0.0) {
      y = fmod(u0, u1);
      yEq = (y == 0.0);
      if ((!yEq) && (u1 > floor(u1))) {
        q = fabs(u0 / u1);
        yEq = (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q);
      }

      if (yEq) {
        y = u1 * 0.0;
      } else {
        if ((u0 < 0.0) != (u1 < 0.0)) {
          y += u1;
        }
      }
    }
  }

  return y;
}

/* Model output function */
void model6_threestate_output(void)
{
  real_T rtb_TransferFcn;
  real_T rtb_Abs;
  if (rtmIsMajorTimeStep(model6_threestate_M)) {
    /* set solver stop time */
    if (!(model6_threestate_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&model6_threestate_M->solverInfo,
                            ((model6_threestate_M->Timing.clockTickH0 + 1) *
        model6_threestate_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&model6_threestate_M->solverInfo,
                            ((model6_threestate_M->Timing.clockTick0 + 1) *
        model6_threestate_M->Timing.stepSize0 +
        model6_threestate_M->Timing.clockTickH0 *
        model6_threestate_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(model6_threestate_M)) {
    model6_threestate_M->Timing.t[0] = rtsiGetT(&model6_threestate_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(model6_threestate_M)) {
    /* S-Function (c6xen): '<S2>/S-function' */
    /* S-Function Block: <Root>/Encoder Input (c6xen) */
    {
      model6_threestate_B.Sfunction[0] = C6X_encInput(0x378, (uint_T)
        model6_threestate_P.EncoderInput_channels[0]);
      model6_threestate_B.Sfunction[1] = C6X_encInput(0x378, (uint_T)
        model6_threestate_P.EncoderInput_channels[1]);
    }

    /* Gain: '<Root>/Gain' */
    model6_threestate_B.Gain = model6_threestate_P.Gain_Gain *
      model6_threestate_B.Sfunction[0];

    /* Sum: '<Root>/Add2' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Constant3'
     *  Math: '<Root>/Mod'
     */
    model6_threestate_B.Add2 = rt_modd_snf(model6_threestate_B.Gain,
      model6_threestate_P.Constant3_Value) - model6_threestate_P.Constant1_Value;

    /* Gain: '<Root>/Gain2' */
    model6_threestate_B.Gain2 = model6_threestate_P.Gain2_Gain *
      model6_threestate_B.Add2;
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  model6_threestate_B.TransferFcn1 = 0.0;
  model6_threestate_B.TransferFcn1 += model6_threestate_P.TransferFcn1_C *
    model6_threestate_X.TransferFcn1_CSTATE;
  model6_threestate_B.TransferFcn1 += model6_threestate_P.TransferFcn1_D *
    model6_threestate_B.Gain;
  if (rtmIsMajorTimeStep(model6_threestate_M)) {
    /* Sum: '<Root>/Add' incorporates:
     *  Gain: '<Root>/Gain1'
     */
    model6_threestate_B.Add = model6_threestate_P.Gain1_Gain *
      model6_threestate_B.Sfunction[1] + model6_threestate_B.Gain;
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  rtb_TransferFcn = model6_threestate_P.TransferFcn_C *
    model6_threestate_X.TransferFcn_CSTATE + model6_threestate_P.TransferFcn_D *
    model6_threestate_B.Add;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  if (model6_threestate_P.ManualSwitch_CurrentSetting == 1) {
    rtb_Abs = model6_threestate_P.Constant2_Value;
  } else {
    /* Abs: '<S1>/Abs' */
    rtb_Abs = fabs(rtb_TransferFcn);

    /* Switch: '<S1>/Switch2' incorporates:
     *  Constant: '<S1>/Constant2'
     */
    if (rtb_Abs >= model6_threestate_P.Switch2_Threshold) {
      /* Switch: '<S1>/Switch1' incorporates:
       *  Constant: '<S1>/Constant2'
       */
      if (rtb_Abs >= model6_threestate_P.Switch1_Threshold_c) {
        rtb_Abs = rtb_TransferFcn;
      } else {
        rtb_Abs = model6_threestate_P.Constant2_Value_g;
      }

      /* End of Switch: '<S1>/Switch1' */

      /* Switch: '<S1>/Switch' incorporates:
       *  Constant: '<S1>/Constant'
       *  Constant: '<S1>/Constant1'
       *  Gain: '<S1>/B1'
       *  Gain: '<S1>/B2'
       *  Sum: '<S1>/Sum1'
       *  Sum: '<S1>/Sum2'
       */
      if (rtb_Abs >= model6_threestate_P.Switch_Threshold) {
        rtb_Abs = model6_threestate_P.AsymmetricLinearFriction1_slope1 * rtb_Abs
          + model6_threestate_P.AsymmetricLinearFriction1_intercept1;
      } else {
        rtb_Abs = model6_threestate_P.AsymmetricLinearFriction1_slope2 * rtb_Abs
          + model6_threestate_P.AsymmetricLinearFriction1_intercept2;
      }

      /* End of Switch: '<S1>/Switch' */
    } else {
      rtb_Abs = model6_threestate_P.Constant2_Value_g;
    }

    /* End of Switch: '<S1>/Switch2' */
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Sum: '<Root>/Add1' incorporates:
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain4'
   *  Sum: '<Root>/Add3'
   */
  rtb_TransferFcn = (model6_threestate_P.Gain3_Gain *
                     model6_threestate_B.TransferFcn1 +
                     model6_threestate_B.Gain2) +
    (model6_threestate_P.Gain4_Gain * rtb_TransferFcn + rtb_Abs);

  /* Switch: '<Root>/Switch' incorporates:
   *  Gain: '<Root>/Gain6'
   *  Switch: '<Root>/Switch1'
   */
  if (model6_threestate_B.Add2 > model6_threestate_P.Switch_Threshold_k) {
    rtb_TransferFcn *= model6_threestate_P.Gain6_Gain;
  } else {
    if (!(model6_threestate_B.Add2 > model6_threestate_P.Switch1_Threshold)) {
      rtb_TransferFcn *= model6_threestate_P.Gain6_Gain;
    }
  }

  /* End of Switch: '<Root>/Switch' */

  /* Switch: '<Root>/Switch2' incorporates:
   *  Abs: '<Root>/Abs'
   *  Gain: '<Root>/Gain5'
   *  Gain: '<Root>/Gain7'
   */
  if (fabs(model6_threestate_B.TransferFcn1) >
      model6_threestate_P.Switch2_Threshold_f) {
    model6_threestate_B.Switch2 = model6_threestate_P.Gain5_Gain *
      rtb_TransferFcn;
  } else {
    model6_threestate_B.Switch2 = model6_threestate_P.Gain7_Gain *
      rtb_TransferFcn;
  }

  /* End of Switch: '<Root>/Switch2' */
  if (rtmIsMajorTimeStep(model6_threestate_M)) {
    /* S-Function (c6xpwm): '<S3>/S-function' */
    /* S-Function Block: <Root>/PWM Output (c6xpwm) */
    {
      int16_T value;
      value = C6X_pwmArbUnitsToOutput(model6_threestate_B.Switch2);
      C6X_pwmOutput(0x378, (uint_T)model6_threestate_P.PWMOutput_channels, value);
    }
  }
}

/* Model update function */
void model6_threestate_update(void)
{
  if (rtmIsMajorTimeStep(model6_threestate_M)) {
    rt_ertODEUpdateContinuousStates(&model6_threestate_M->solverInfo);
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
  if (!(++model6_threestate_M->Timing.clockTick0)) {
    ++model6_threestate_M->Timing.clockTickH0;
  }

  model6_threestate_M->Timing.t[0] = rtsiGetSolverStopTime
    (&model6_threestate_M->solverInfo);

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
    if (!(++model6_threestate_M->Timing.clockTick1)) {
      ++model6_threestate_M->Timing.clockTickH1;
    }

    model6_threestate_M->Timing.t[1] = model6_threestate_M->Timing.clockTick1 *
      model6_threestate_M->Timing.stepSize1 +
      model6_threestate_M->Timing.clockTickH1 *
      model6_threestate_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void model6_threestate_derivatives(void)
{
  XDot_model6_threestate_T *_rtXdot;
  _rtXdot = ((XDot_model6_threestate_T *) model6_threestate_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += model6_threestate_P.TransferFcn1_A *
    model6_threestate_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += model6_threestate_B.Gain;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += model6_threestate_P.TransferFcn_A *
    model6_threestate_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += model6_threestate_B.Add;
}

/* Model initialize function */
void model6_threestate_initialize(void)
{
  /* Start for S-Function (c6xen): '<S2>/S-function' */

  /* S-Function Block: <Root>/Encoder Input (c6xen) */
  {
    C6X_encResetAll(0x378);
  }

  /* Start for S-Function (c6xpwm): '<S3>/S-function' */

  /* S-Function Block: <Root>/PWM Output (c6xpwm) */
  {
    int16_T value;
    value = C6X_pwmArbUnitsToOutput(model6_threestate_P.PWMOutput_initialOutputs);
    C6X_pwmOutput(0x378, (uint_T)model6_threestate_P.PWMOutput_channels, value);
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  model6_threestate_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  model6_threestate_X.TransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void model6_threestate_terminate(void)
{
  /* Terminate for S-Function (c6xpwm): '<S3>/S-function' */

  /* S-Function Block: <Root>/PWM Output (c6xpwm) */
  {
    int16_T value;
    value = C6X_pwmArbUnitsToOutput(model6_threestate_P.PWMOutput_finalOutputs);
    C6X_pwmOutput(0x378, (uint_T)model6_threestate_P.PWMOutput_channels, value);
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
  model6_threestate_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  model6_threestate_update();
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
  model6_threestate_initialize();
}

void MdlTerminate(void)
{
  model6_threestate_terminate();
}

/* Registration function */
RT_MODEL_model6_threestate_T *model6_threestate(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)model6_threestate_M, 0,
                sizeof(RT_MODEL_model6_threestate_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&model6_threestate_M->solverInfo,
                          &model6_threestate_M->Timing.simTimeStep);
    rtsiSetTPtr(&model6_threestate_M->solverInfo, &rtmGetTPtr
                (model6_threestate_M));
    rtsiSetStepSizePtr(&model6_threestate_M->solverInfo,
                       &model6_threestate_M->Timing.stepSize0);
    rtsiSetdXPtr(&model6_threestate_M->solverInfo, &model6_threestate_M->derivs);
    rtsiSetContStatesPtr(&model6_threestate_M->solverInfo, (real_T **)
                         &model6_threestate_M->contStates);
    rtsiSetNumContStatesPtr(&model6_threestate_M->solverInfo,
      &model6_threestate_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&model6_threestate_M->solverInfo,
      &model6_threestate_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&model6_threestate_M->solverInfo,
      &model6_threestate_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&model6_threestate_M->solverInfo,
      &model6_threestate_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&model6_threestate_M->solverInfo, (&rtmGetErrorStatus
      (model6_threestate_M)));
    rtsiSetRTModelPtr(&model6_threestate_M->solverInfo, model6_threestate_M);
  }

  rtsiSetSimTimeStep(&model6_threestate_M->solverInfo, MAJOR_TIME_STEP);
  model6_threestate_M->intgData.f[0] = model6_threestate_M->odeF[0];
  model6_threestate_M->contStates = ((real_T *) &model6_threestate_X);
  rtsiSetSolverData(&model6_threestate_M->solverInfo, (void *)
                    &model6_threestate_M->intgData);
  rtsiSetSolverName(&model6_threestate_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = model6_threestate_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    model6_threestate_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    model6_threestate_M->Timing.sampleTimes =
      (&model6_threestate_M->Timing.sampleTimesArray[0]);
    model6_threestate_M->Timing.offsetTimes =
      (&model6_threestate_M->Timing.offsetTimesArray[0]);

    /* task periods */
    model6_threestate_M->Timing.sampleTimes[0] = (0.0);
    model6_threestate_M->Timing.sampleTimes[1] = (0.005);

    /* task offsets */
    model6_threestate_M->Timing.offsetTimes[0] = (0.0);
    model6_threestate_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(model6_threestate_M, &model6_threestate_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = model6_threestate_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    model6_threestate_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(model6_threestate_M, 1000.0);
  model6_threestate_M->Timing.stepSize0 = 0.005;
  model6_threestate_M->Timing.stepSize1 = 0.005;

  /* External mode info */
  model6_threestate_M->Sizes.checksums[0] = (2022665566U);
  model6_threestate_M->Sizes.checksums[1] = (1117626049U);
  model6_threestate_M->Sizes.checksums[2] = (2199730814U);
  model6_threestate_M->Sizes.checksums[3] = (1543074069U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    model6_threestate_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(model6_threestate_M->extModeInfo,
      &model6_threestate_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(model6_threestate_M->extModeInfo,
                        model6_threestate_M->Sizes.checksums);
    rteiSetTPtr(model6_threestate_M->extModeInfo, rtmGetTPtr(model6_threestate_M));
  }

  model6_threestate_M->solverInfoPtr = (&model6_threestate_M->solverInfo);
  model6_threestate_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&model6_threestate_M->solverInfo, 0.005);
  rtsiSetSolverMode(&model6_threestate_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  model6_threestate_M->blockIO = ((void *) &model6_threestate_B);

  {
    model6_threestate_B.Sfunction[0] = 0.0;
    model6_threestate_B.Sfunction[1] = 0.0;
    model6_threestate_B.Gain = 0.0;
    model6_threestate_B.Add2 = 0.0;
    model6_threestate_B.Gain2 = 0.0;
    model6_threestate_B.TransferFcn1 = 0.0;
    model6_threestate_B.Add = 0.0;
    model6_threestate_B.Switch2 = 0.0;
  }

  /* parameters */
  model6_threestate_M->defaultParam = ((real_T *)&model6_threestate_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &model6_threestate_X;
    model6_threestate_M->contStates = (x);
    (void) memset((void *)&model6_threestate_X, 0,
                  sizeof(X_model6_threestate_T));
  }

  /* states (dwork) */
  model6_threestate_M->dwork = ((void *) &model6_threestate_DW);
  (void) memset((void *)&model6_threestate_DW, 0,
                sizeof(DW_model6_threestate_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    model6_threestate_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  model6_threestate_M->Sizes.numContStates = (2);/* Number of continuous states */
  model6_threestate_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  model6_threestate_M->Sizes.numY = (0);/* Number of model outputs */
  model6_threestate_M->Sizes.numU = (0);/* Number of model inputs */
  model6_threestate_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  model6_threestate_M->Sizes.numSampTimes = (2);/* Number of sample times */
  model6_threestate_M->Sizes.numBlocks = (44);/* Number of blocks */
  model6_threestate_M->Sizes.numBlockIO = (7);/* Number of block outputs */
  model6_threestate_M->Sizes.numBlockPrms = (34);/* Sum of parameter "widths" */
  return model6_threestate_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
