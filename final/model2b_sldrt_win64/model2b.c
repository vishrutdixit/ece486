/*
 * model2b.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "model2b".
 *
 * Model version              : 1.29
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Nov 01 17:01:44 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model2b.h"
#include "model2b_private.h"
#include "model2b_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.005, 0.0,
};

/* Block signals (auto storage) */
B_model2b_T model2b_B;

/* Continuous states */
X_model2b_T model2b_X;

/* Block states (auto storage) */
DW_model2b_T model2b_DW;

/* Real-time model */
RT_MODEL_model2b_T model2b_M_;
RT_MODEL_model2b_T *const model2b_M = &model2b_M_;

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
  model2b_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void model2b_output(void)
{
  real_T rtb_Gain4;
  real_T tmp;
  if (rtmIsMajorTimeStep(model2b_M)) {
    /* set solver stop time */
    if (!(model2b_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&model2b_M->solverInfo,
                            ((model2b_M->Timing.clockTickH0 + 1) *
        model2b_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&model2b_M->solverInfo,
                            ((model2b_M->Timing.clockTick0 + 1) *
        model2b_M->Timing.stepSize0 + model2b_M->Timing.clockTickH0 *
        model2b_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(model2b_M)) {
    model2b_M->Timing.t[0] = rtsiGetT(&model2b_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(model2b_M)) {
    /* S-Function (c6xen): '<S2>/S-function' */
    /* S-Function Block: <Root>/Encoder Input (c6xen) */
    {
      model2b_B.Sfunction[0] = C6X_encInput(0x378, (uint_T)
        model2b_P.EncoderInput_channels[0]);
      model2b_B.Sfunction[1] = C6X_encInput(0x378, (uint_T)
        model2b_P.EncoderInput_channels[1]);
    }

    /* Gain: '<Root>/Gain' */
    model2b_B.Gain = model2b_P.Gain_Gain * model2b_B.Sfunction[0];

    /* Sum: '<Root>/Add' incorporates:
     *  Gain: '<Root>/Gain1'
     */
    model2b_B.Add = model2b_P.Gain1_Gain * model2b_B.Sfunction[1] +
      model2b_B.Gain;

    /* Gain: '<Root>/Gain6' incorporates:
     *  Sum: '<Root>/Add2'
     *  UnitDelay: '<Root>/Unit Delay'
     */
    model2b_B.Gain6 = (model2b_B.Add - model2b_DW.UnitDelay_DSTATE) *
      model2b_P.Gain6_Gain;
  }

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  TransferFcn: '<Root>/Transfer Fcn'
   */
  if (model2b_P.ManualSwitch_CurrentSetting == 1) {
    model2b_B.ManualSwitch = model2b_P.TransferFcn_C *
      model2b_X.TransferFcn_CSTATE + model2b_P.TransferFcn_D * model2b_B.Add;
  } else {
    model2b_B.ManualSwitch = model2b_B.Gain6;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Step: '<Root>/Step' */
  if (model2b_M->Timing.t[0] < model2b_P.Step_Time) {
    tmp = model2b_P.Step_Y0;
  } else {
    tmp = model2b_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Sum: '<Root>/Add1' incorporates:
   *  Gain: '<Root>/Gain4'
   */
  model2b_B.Add1 = model2b_P.Gain4_Gain * tmp - model2b_B.ManualSwitch;

  /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
   *  Constant: '<Root>/No Compensation1'
   */
  if (model2b_P.ManualSwitch2_CurrentSetting == 1) {
    /* Abs: '<S1>/Abs' */
    rtb_Gain4 = fabs(model2b_B.ManualSwitch);

    /* Switch: '<S1>/Switch2' incorporates:
     *  Constant: '<S1>/Constant2'
     */
    if (rtb_Gain4 >= model2b_P.Switch2_Threshold) {
      /* Switch: '<S1>/Switch1' incorporates:
       *  Constant: '<S1>/Constant2'
       */
      if (rtb_Gain4 >= model2b_P.Switch1_Threshold) {
        rtb_Gain4 = model2b_B.ManualSwitch;
      } else {
        rtb_Gain4 = model2b_P.Constant2_Value;
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
      if (rtb_Gain4 >= model2b_P.Switch_Threshold) {
        rtb_Gain4 = model2b_P.AsymmetricLinearFriction_slope1 * rtb_Gain4 +
          model2b_P.AsymmetricLinearFriction_intercept1;
      } else {
        rtb_Gain4 = model2b_P.AsymmetricLinearFriction_slope2 * rtb_Gain4 +
          model2b_P.AsymmetricLinearFriction_intercept2;
      }

      /* End of Switch: '<S1>/Switch' */
    } else {
      rtb_Gain4 = model2b_P.Constant2_Value;
    }

    /* End of Switch: '<S1>/Switch2' */
  } else {
    rtb_Gain4 = model2b_P.NoCompensation1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch2' */

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Constant: '<Root>/No Compensation'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain7'
   *  Integrator: '<Root>/Integrator1'
   *  Sum: '<Root>/Add3'
   */
  if (model2b_P.ManualSwitch1_CurrentSetting == 1) {
    tmp = model2b_P.NoCompensation_Value;
  } else {
    tmp = model2b_P.Gain2_Gain * model2b_B.Add1 + model2b_P.Gain7_Gain *
      model2b_X.Integrator1_CSTATE;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* Sum: '<Root>/Add4' */
  model2b_B.Add4 = tmp + rtb_Gain4;

  /* Gain: '<Root>/Gain5' */
  model2b_B.Gain5 = model2b_P.Gain5_Gain * model2b_B.Add4;
  if (rtmIsMajorTimeStep(model2b_M)) {
    /* S-Function (c6xpwm): '<S3>/S-function' */
    /* S-Function Block: <Root>/PWM Output (c6xpwm) */
    {
      int16_T value;
      value = C6X_pwmArbUnitsToOutput(model2b_B.Gain5);
      C6X_pwmOutput(0x378, (uint_T)model2b_P.PWMOutput_channels, value);
    }
  }
}

/* Model update function */
void model2b_update(void)
{
  if (rtmIsMajorTimeStep(model2b_M)) {
    /* Update for UnitDelay: '<Root>/Unit Delay' */
    model2b_DW.UnitDelay_DSTATE = model2b_B.Add;
  }

  if (rtmIsMajorTimeStep(model2b_M)) {
    rt_ertODEUpdateContinuousStates(&model2b_M->solverInfo);
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
  if (!(++model2b_M->Timing.clockTick0)) {
    ++model2b_M->Timing.clockTickH0;
  }

  model2b_M->Timing.t[0] = rtsiGetSolverStopTime(&model2b_M->solverInfo);

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
    if (!(++model2b_M->Timing.clockTick1)) {
      ++model2b_M->Timing.clockTickH1;
    }

    model2b_M->Timing.t[1] = model2b_M->Timing.clockTick1 *
      model2b_M->Timing.stepSize1 + model2b_M->Timing.clockTickH1 *
      model2b_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void model2b_derivatives(void)
{
  XDot_model2b_T *_rtXdot;
  _rtXdot = ((XDot_model2b_T *) model2b_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += model2b_P.TransferFcn_A *
    model2b_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += model2b_B.Add;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = model2b_B.Add1;
}

/* Model initialize function */
void model2b_initialize(void)
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
    value = C6X_pwmArbUnitsToOutput(model2b_P.PWMOutput_initialOutputs);
    C6X_pwmOutput(0x378, (uint_T)model2b_P.PWMOutput_channels, value);
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  model2b_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  model2b_DW.UnitDelay_DSTATE = model2b_P.UnitDelay_InitialCondition;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  model2b_X.Integrator1_CSTATE = model2b_P.Integrator1_IC;
}

/* Model terminate function */
void model2b_terminate(void)
{
  /* Terminate for S-Function (c6xpwm): '<S3>/S-function' */

  /* S-Function Block: <Root>/PWM Output (c6xpwm) */
  {
    int16_T value;
    value = C6X_pwmArbUnitsToOutput(model2b_P.PWMOutput_finalOutputs);
    C6X_pwmOutput(0x378, (uint_T)model2b_P.PWMOutput_channels, value);
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
  model2b_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  model2b_update();
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
  model2b_initialize();
}

void MdlTerminate(void)
{
  model2b_terminate();
}

/* Registration function */
RT_MODEL_model2b_T *model2b(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)model2b_M, 0,
                sizeof(RT_MODEL_model2b_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&model2b_M->solverInfo, &model2b_M->Timing.simTimeStep);
    rtsiSetTPtr(&model2b_M->solverInfo, &rtmGetTPtr(model2b_M));
    rtsiSetStepSizePtr(&model2b_M->solverInfo, &model2b_M->Timing.stepSize0);
    rtsiSetdXPtr(&model2b_M->solverInfo, &model2b_M->derivs);
    rtsiSetContStatesPtr(&model2b_M->solverInfo, (real_T **)
                         &model2b_M->contStates);
    rtsiSetNumContStatesPtr(&model2b_M->solverInfo,
      &model2b_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&model2b_M->solverInfo,
      &model2b_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&model2b_M->solverInfo,
      &model2b_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&model2b_M->solverInfo,
      &model2b_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&model2b_M->solverInfo, (&rtmGetErrorStatus(model2b_M)));
    rtsiSetRTModelPtr(&model2b_M->solverInfo, model2b_M);
  }

  rtsiSetSimTimeStep(&model2b_M->solverInfo, MAJOR_TIME_STEP);
  model2b_M->intgData.f[0] = model2b_M->odeF[0];
  model2b_M->contStates = ((real_T *) &model2b_X);
  rtsiSetSolverData(&model2b_M->solverInfo, (void *)&model2b_M->intgData);
  rtsiSetSolverName(&model2b_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = model2b_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    model2b_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    model2b_M->Timing.sampleTimes = (&model2b_M->Timing.sampleTimesArray[0]);
    model2b_M->Timing.offsetTimes = (&model2b_M->Timing.offsetTimesArray[0]);

    /* task periods */
    model2b_M->Timing.sampleTimes[0] = (0.0);
    model2b_M->Timing.sampleTimes[1] = (0.005);

    /* task offsets */
    model2b_M->Timing.offsetTimes[0] = (0.0);
    model2b_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(model2b_M, &model2b_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = model2b_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    model2b_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(model2b_M, 100.0);
  model2b_M->Timing.stepSize0 = 0.005;
  model2b_M->Timing.stepSize1 = 0.005;

  /* External mode info */
  model2b_M->Sizes.checksums[0] = (393520639U);
  model2b_M->Sizes.checksums[1] = (2580142356U);
  model2b_M->Sizes.checksums[2] = (785737954U);
  model2b_M->Sizes.checksums[3] = (2261328495U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    model2b_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(model2b_M->extModeInfo,
      &model2b_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(model2b_M->extModeInfo, model2b_M->Sizes.checksums);
    rteiSetTPtr(model2b_M->extModeInfo, rtmGetTPtr(model2b_M));
  }

  model2b_M->solverInfoPtr = (&model2b_M->solverInfo);
  model2b_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&model2b_M->solverInfo, 0.005);
  rtsiSetSolverMode(&model2b_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  model2b_M->blockIO = ((void *) &model2b_B);

  {
    model2b_B.Sfunction[0] = 0.0;
    model2b_B.Sfunction[1] = 0.0;
    model2b_B.Gain = 0.0;
    model2b_B.Add = 0.0;
    model2b_B.Gain6 = 0.0;
    model2b_B.ManualSwitch = 0.0;
    model2b_B.Add1 = 0.0;
    model2b_B.Add4 = 0.0;
    model2b_B.Gain5 = 0.0;
  }

  /* parameters */
  model2b_M->defaultParam = ((real_T *)&model2b_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &model2b_X;
    model2b_M->contStates = (x);
    (void) memset((void *)&model2b_X, 0,
                  sizeof(X_model2b_T));
  }

  /* states (dwork) */
  model2b_M->dwork = ((void *) &model2b_DW);
  (void) memset((void *)&model2b_DW, 0,
                sizeof(DW_model2b_T));
  model2b_DW.UnitDelay_DSTATE = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    model2b_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  model2b_M->Sizes.numContStates = (2);/* Number of continuous states */
  model2b_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  model2b_M->Sizes.numY = (0);         /* Number of model outputs */
  model2b_M->Sizes.numU = (0);         /* Number of model inputs */
  model2b_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  model2b_M->Sizes.numSampTimes = (2); /* Number of sample times */
  model2b_M->Sizes.numBlocks = (44);   /* Number of blocks */
  model2b_M->Sizes.numBlockIO = (8);   /* Number of block outputs */
  model2b_M->Sizes.numBlockPrms = (33);/* Sum of parameter "widths" */
  return model2b_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
