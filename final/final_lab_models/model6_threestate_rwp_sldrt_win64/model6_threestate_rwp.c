/*
 * model6_threestate_rwp.c
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
#include "model6_threestate_rwp_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.005, 0.0,
};

/* Block signals (auto storage) */
B_model6_threestate_rwp_T model6_threestate_rwp_B;

/* Continuous states */
X_model6_threestate_rwp_T model6_threestate_rwp_X;

/* Block states (auto storage) */
DW_model6_threestate_rwp_T model6_threestate_rwp_DW;

/* Real-time model */
RT_MODEL_model6_threestate_rwp_T model6_threestate_rwp_M_;
RT_MODEL_model6_threestate_rwp_T *const model6_threestate_rwp_M =
  &model6_threestate_rwp_M_;

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
  model6_threestate_rwp_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void model6_threestate_rwp_output(void)
{
  real_T rtb_Switch1_m;
  real_T rtb_Abs;
  if (rtmIsMajorTimeStep(model6_threestate_rwp_M)) {
    /* set solver stop time */
    if (!(model6_threestate_rwp_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&model6_threestate_rwp_M->solverInfo,
                            ((model6_threestate_rwp_M->Timing.clockTickH0 + 1) *
        model6_threestate_rwp_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&model6_threestate_rwp_M->solverInfo,
                            ((model6_threestate_rwp_M->Timing.clockTick0 + 1) *
        model6_threestate_rwp_M->Timing.stepSize0 +
        model6_threestate_rwp_M->Timing.clockTickH0 *
        model6_threestate_rwp_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(model6_threestate_rwp_M)) {
    model6_threestate_rwp_M->Timing.t[0] = rtsiGetT
      (&model6_threestate_rwp_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(model6_threestate_rwp_M)) {
    /* S-Function (c6xen): '<S2>/S-function' */
    /* S-Function Block: <Root>/Encoder Input (c6xen) */
    {
      model6_threestate_rwp_B.Sfunction[0] = C6X_encInput(0x378, (uint_T)
        model6_threestate_rwp_P.EncoderInput_channels[0]);
      model6_threestate_rwp_B.Sfunction[1] = C6X_encInput(0x378, (uint_T)
        model6_threestate_rwp_P.EncoderInput_channels[1]);
    }

    /* Gain: '<Root>/Gain' */
    model6_threestate_rwp_B.Gain = model6_threestate_rwp_P.Gain_Gain *
      model6_threestate_rwp_B.Sfunction[0];

    /* Gain: '<Root>/Gain2' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Sum: '<Root>/Add2'
     */
    model6_threestate_rwp_B.Gain2 = (model6_threestate_rwp_B.Gain -
      model6_threestate_rwp_P.Constant1_Value) *
      model6_threestate_rwp_P.Gain2_Gain;
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  model6_threestate_rwp_B.TransferFcn1 = 0.0;
  model6_threestate_rwp_B.TransferFcn1 += model6_threestate_rwp_P.TransferFcn1_C
    * model6_threestate_rwp_X.TransferFcn1_CSTATE;
  model6_threestate_rwp_B.TransferFcn1 += model6_threestate_rwp_P.TransferFcn1_D
    * model6_threestate_rwp_B.Gain;
  if (rtmIsMajorTimeStep(model6_threestate_rwp_M)) {
    /* Sum: '<Root>/Add' incorporates:
     *  Gain: '<Root>/Gain1'
     */
    model6_threestate_rwp_B.Add = model6_threestate_rwp_P.Gain1_Gain *
      model6_threestate_rwp_B.Sfunction[1] + model6_threestate_rwp_B.Gain;

    /* Gain: '<Root>/Gain5' */
    model6_threestate_rwp_B.Gain5 = model6_threestate_rwp_P.Gain5_Gain *
      model6_threestate_rwp_B.Gain;
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  rtb_Switch1_m = model6_threestate_rwp_P.TransferFcn_C *
    model6_threestate_rwp_X.TransferFcn_CSTATE +
    model6_threestate_rwp_P.TransferFcn_D * model6_threestate_rwp_B.Add;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain4'
   *  Gain: '<Root>/Gain7'
   *  Sum: '<Root>/Add1'
   *  Sum: '<Root>/Add3'
   *  Sum: '<Root>/Add4'
   */
  if (model6_threestate_rwp_B.Gain > model6_threestate_rwp_P.Switch1_Threshold_f)
  {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    if (model6_threestate_rwp_P.ManualSwitch_CurrentSetting == 1) {
      rtb_Abs = model6_threestate_rwp_P.Constant2_Value;
    } else {
      /* Abs: '<S1>/Abs' */
      rtb_Abs = fabs(rtb_Switch1_m);

      /* Switch: '<S1>/Switch2' incorporates:
       *  Constant: '<S1>/Constant2'
       */
      if (rtb_Abs >= model6_threestate_rwp_P.Switch2_Threshold) {
        /* Switch: '<S1>/Switch1' incorporates:
         *  Constant: '<S1>/Constant2'
         */
        if (rtb_Abs >= model6_threestate_rwp_P.Switch1_Threshold) {
          rtb_Abs = rtb_Switch1_m;
        } else {
          rtb_Abs = model6_threestate_rwp_P.Constant2_Value_g;
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
        if (rtb_Abs >= model6_threestate_rwp_P.Switch_Threshold) {
          rtb_Abs = model6_threestate_rwp_P.AsymmetricLinearFriction1_slope1 *
            rtb_Abs +
            model6_threestate_rwp_P.AsymmetricLinearFriction1_intercept1;
        } else {
          rtb_Abs = model6_threestate_rwp_P.AsymmetricLinearFriction1_slope2 *
            rtb_Abs +
            model6_threestate_rwp_P.AsymmetricLinearFriction1_intercept2;
        }

        /* End of Switch: '<S1>/Switch' */
      } else {
        rtb_Abs = model6_threestate_rwp_P.Constant2_Value_g;
      }

      /* End of Switch: '<S1>/Switch2' */
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */
    rtb_Switch1_m = (model6_threestate_rwp_P.Gain3_Gain *
                     model6_threestate_rwp_B.TransferFcn1 +
                     model6_threestate_rwp_B.Gain2) +
      (model6_threestate_rwp_P.Gain4_Gain * rtb_Switch1_m + rtb_Abs);
  } else {
    rtb_Switch1_m = model6_threestate_rwp_P.Gain7_Gain *
      model6_threestate_rwp_B.TransferFcn1 + model6_threestate_rwp_B.Gain5;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Gain: '<Root>/Gain6' */
  model6_threestate_rwp_B.Gain6 = model6_threestate_rwp_P.Gain6_Gain *
    rtb_Switch1_m;
  if (rtmIsMajorTimeStep(model6_threestate_rwp_M)) {
    /* S-Function (c6xpwm): '<S3>/S-function' */
    /* S-Function Block: <Root>/PWM Output (c6xpwm) */
    {
      int16_T value;
      value = C6X_pwmArbUnitsToOutput(model6_threestate_rwp_B.Gain6);
      C6X_pwmOutput(0x378, (uint_T)model6_threestate_rwp_P.PWMOutput_channels,
                    value);
    }
  }
}

/* Model update function */
void model6_threestate_rwp_update(void)
{
  if (rtmIsMajorTimeStep(model6_threestate_rwp_M)) {
    rt_ertODEUpdateContinuousStates(&model6_threestate_rwp_M->solverInfo);
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
  if (!(++model6_threestate_rwp_M->Timing.clockTick0)) {
    ++model6_threestate_rwp_M->Timing.clockTickH0;
  }

  model6_threestate_rwp_M->Timing.t[0] = rtsiGetSolverStopTime
    (&model6_threestate_rwp_M->solverInfo);

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
    if (!(++model6_threestate_rwp_M->Timing.clockTick1)) {
      ++model6_threestate_rwp_M->Timing.clockTickH1;
    }

    model6_threestate_rwp_M->Timing.t[1] =
      model6_threestate_rwp_M->Timing.clockTick1 *
      model6_threestate_rwp_M->Timing.stepSize1 +
      model6_threestate_rwp_M->Timing.clockTickH1 *
      model6_threestate_rwp_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void model6_threestate_rwp_derivatives(void)
{
  XDot_model6_threestate_rwp_T *_rtXdot;
  _rtXdot = ((XDot_model6_threestate_rwp_T *) model6_threestate_rwp_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += model6_threestate_rwp_P.TransferFcn1_A *
    model6_threestate_rwp_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += model6_threestate_rwp_B.Gain;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += model6_threestate_rwp_P.TransferFcn_A *
    model6_threestate_rwp_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += model6_threestate_rwp_B.Add;
}

/* Model initialize function */
void model6_threestate_rwp_initialize(void)
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
    value = C6X_pwmArbUnitsToOutput
      (model6_threestate_rwp_P.PWMOutput_initialOutputs);
    C6X_pwmOutput(0x378, (uint_T)model6_threestate_rwp_P.PWMOutput_channels,
                  value);
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  model6_threestate_rwp_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  model6_threestate_rwp_X.TransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void model6_threestate_rwp_terminate(void)
{
  /* Terminate for S-Function (c6xpwm): '<S3>/S-function' */

  /* S-Function Block: <Root>/PWM Output (c6xpwm) */
  {
    int16_T value;
    value = C6X_pwmArbUnitsToOutput
      (model6_threestate_rwp_P.PWMOutput_finalOutputs);
    C6X_pwmOutput(0x378, (uint_T)model6_threestate_rwp_P.PWMOutput_channels,
                  value);
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
  model6_threestate_rwp_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  model6_threestate_rwp_update();
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
  model6_threestate_rwp_initialize();
}

void MdlTerminate(void)
{
  model6_threestate_rwp_terminate();
}

/* Registration function */
RT_MODEL_model6_threestate_rwp_T *model6_threestate_rwp(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)model6_threestate_rwp_M, 0,
                sizeof(RT_MODEL_model6_threestate_rwp_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&model6_threestate_rwp_M->solverInfo,
                          &model6_threestate_rwp_M->Timing.simTimeStep);
    rtsiSetTPtr(&model6_threestate_rwp_M->solverInfo, &rtmGetTPtr
                (model6_threestate_rwp_M));
    rtsiSetStepSizePtr(&model6_threestate_rwp_M->solverInfo,
                       &model6_threestate_rwp_M->Timing.stepSize0);
    rtsiSetdXPtr(&model6_threestate_rwp_M->solverInfo,
                 &model6_threestate_rwp_M->derivs);
    rtsiSetContStatesPtr(&model6_threestate_rwp_M->solverInfo, (real_T **)
                         &model6_threestate_rwp_M->contStates);
    rtsiSetNumContStatesPtr(&model6_threestate_rwp_M->solverInfo,
      &model6_threestate_rwp_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&model6_threestate_rwp_M->solverInfo,
      &model6_threestate_rwp_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&model6_threestate_rwp_M->solverInfo,
      &model6_threestate_rwp_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&model6_threestate_rwp_M->solverInfo,
      &model6_threestate_rwp_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&model6_threestate_rwp_M->solverInfo,
                          (&rtmGetErrorStatus(model6_threestate_rwp_M)));
    rtsiSetRTModelPtr(&model6_threestate_rwp_M->solverInfo,
                      model6_threestate_rwp_M);
  }

  rtsiSetSimTimeStep(&model6_threestate_rwp_M->solverInfo, MAJOR_TIME_STEP);
  model6_threestate_rwp_M->intgData.f[0] = model6_threestate_rwp_M->odeF[0];
  model6_threestate_rwp_M->contStates = ((real_T *) &model6_threestate_rwp_X);
  rtsiSetSolverData(&model6_threestate_rwp_M->solverInfo, (void *)
                    &model6_threestate_rwp_M->intgData);
  rtsiSetSolverName(&model6_threestate_rwp_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = model6_threestate_rwp_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    model6_threestate_rwp_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    model6_threestate_rwp_M->Timing.sampleTimes =
      (&model6_threestate_rwp_M->Timing.sampleTimesArray[0]);
    model6_threestate_rwp_M->Timing.offsetTimes =
      (&model6_threestate_rwp_M->Timing.offsetTimesArray[0]);

    /* task periods */
    model6_threestate_rwp_M->Timing.sampleTimes[0] = (0.0);
    model6_threestate_rwp_M->Timing.sampleTimes[1] = (0.005);

    /* task offsets */
    model6_threestate_rwp_M->Timing.offsetTimes[0] = (0.0);
    model6_threestate_rwp_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(model6_threestate_rwp_M, &model6_threestate_rwp_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = model6_threestate_rwp_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    model6_threestate_rwp_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(model6_threestate_rwp_M, 1000.0);
  model6_threestate_rwp_M->Timing.stepSize0 = 0.005;
  model6_threestate_rwp_M->Timing.stepSize1 = 0.005;

  /* External mode info */
  model6_threestate_rwp_M->Sizes.checksums[0] = (1423276217U);
  model6_threestate_rwp_M->Sizes.checksums[1] = (1490228107U);
  model6_threestate_rwp_M->Sizes.checksums[2] = (309535836U);
  model6_threestate_rwp_M->Sizes.checksums[3] = (1882289665U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    model6_threestate_rwp_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(model6_threestate_rwp_M->extModeInfo,
      &model6_threestate_rwp_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(model6_threestate_rwp_M->extModeInfo,
                        model6_threestate_rwp_M->Sizes.checksums);
    rteiSetTPtr(model6_threestate_rwp_M->extModeInfo, rtmGetTPtr
                (model6_threestate_rwp_M));
  }

  model6_threestate_rwp_M->solverInfoPtr = (&model6_threestate_rwp_M->solverInfo);
  model6_threestate_rwp_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&model6_threestate_rwp_M->solverInfo, 0.005);
  rtsiSetSolverMode(&model6_threestate_rwp_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  model6_threestate_rwp_M->blockIO = ((void *) &model6_threestate_rwp_B);

  {
    model6_threestate_rwp_B.Sfunction[0] = 0.0;
    model6_threestate_rwp_B.Sfunction[1] = 0.0;
    model6_threestate_rwp_B.Gain = 0.0;
    model6_threestate_rwp_B.Gain2 = 0.0;
    model6_threestate_rwp_B.TransferFcn1 = 0.0;
    model6_threestate_rwp_B.Add = 0.0;
    model6_threestate_rwp_B.Gain5 = 0.0;
    model6_threestate_rwp_B.Gain6 = 0.0;
  }

  /* parameters */
  model6_threestate_rwp_M->defaultParam = ((real_T *)&model6_threestate_rwp_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &model6_threestate_rwp_X;
    model6_threestate_rwp_M->contStates = (x);
    (void) memset((void *)&model6_threestate_rwp_X, 0,
                  sizeof(X_model6_threestate_rwp_T));
  }

  /* states (dwork) */
  model6_threestate_rwp_M->dwork = ((void *) &model6_threestate_rwp_DW);
  (void) memset((void *)&model6_threestate_rwp_DW, 0,
                sizeof(DW_model6_threestate_rwp_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    model6_threestate_rwp_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  model6_threestate_rwp_M->Sizes.numContStates = (2);/* Number of continuous states */
  model6_threestate_rwp_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  model6_threestate_rwp_M->Sizes.numY = (0);/* Number of model outputs */
  model6_threestate_rwp_M->Sizes.numU = (0);/* Number of model inputs */
  model6_threestate_rwp_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  model6_threestate_rwp_M->Sizes.numSampTimes = (2);/* Number of sample times */
  model6_threestate_rwp_M->Sizes.numBlocks = (39);/* Number of blocks */
  model6_threestate_rwp_M->Sizes.numBlockIO = (7);/* Number of block outputs */
  model6_threestate_rwp_M->Sizes.numBlockPrms = (31);/* Sum of parameter "widths" */
  return model6_threestate_rwp_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
