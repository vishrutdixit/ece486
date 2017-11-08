/*
 * lead_rtwin486.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "lead_rtwin486".
 *
 * Model version              : 1.27
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Nov 08 14:47:40 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lead_rtwin486.h"
#include "lead_rtwin486_private.h"
#include "lead_rtwin486_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.002, 0.0,
};

/* Block signals (auto storage) */
B_lead_rtwin486_T lead_rtwin486_B;

/* Continuous states */
X_lead_rtwin486_T lead_rtwin486_X;

/* Block states (auto storage) */
DW_lead_rtwin486_T lead_rtwin486_DW;

/* Real-time model */
RT_MODEL_lead_rtwin486_T lead_rtwin486_M_;
RT_MODEL_lead_rtwin486_T *const lead_rtwin486_M = &lead_rtwin486_M_;

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
  lead_rtwin486_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void lead_rtwin486_output(void)
{
  if (rtmIsMajorTimeStep(lead_rtwin486_M)) {
    /* set solver stop time */
    if (!(lead_rtwin486_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&lead_rtwin486_M->solverInfo,
                            ((lead_rtwin486_M->Timing.clockTickH0 + 1) *
        lead_rtwin486_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&lead_rtwin486_M->solverInfo,
                            ((lead_rtwin486_M->Timing.clockTick0 + 1) *
        lead_rtwin486_M->Timing.stepSize0 + lead_rtwin486_M->Timing.clockTickH0 *
        lead_rtwin486_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(lead_rtwin486_M)) {
    lead_rtwin486_M->Timing.t[0] = rtsiGetT(&lead_rtwin486_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(lead_rtwin486_M)) {
    /* S-Function (pciint32enc): '<S2>/S-function' */
    /* S-Function Block: <S1>/PCIINT32_DAQ (pciint32enc) */
    {
      int_T values[4];
      PCIINT32_encInput(57072.0, values);
      lead_rtwin486_B.Sfunction[0] = values[0];
      lead_rtwin486_B.Sfunction[1] = values[1];
      lead_rtwin486_B.Sfunction[2] = values[2];
      lead_rtwin486_B.Sfunction[3] = values[3];
    }

    /* S-Function (pciint32adc): '<S2>/S-function1' */
    /* S-Function Block: <S1>/PCIINT32_DAQ (pciint32adc) */
    {
      int_T values[4];
      PCIINT32_adcInput(57072.0, values);
      lead_rtwin486_B.Sfunction1[0] = values[0];
      lead_rtwin486_B.Sfunction1[1] = values[1];
      lead_rtwin486_B.Sfunction1[2] = values[2];
      lead_rtwin486_B.Sfunction1[3] = values[3];
    }

    /* Gain: '<S2>/Gain2' */
    lead_rtwin486_B.Gain2 = lead_rtwin486_P.Gain2_Gain *
      lead_rtwin486_B.Sfunction1[0];

    /* Gain: '<S2>/Gain3' */
    lead_rtwin486_B.Gain3 = lead_rtwin486_P.Gain3_Gain *
      lead_rtwin486_B.Sfunction1[1];

    /* Gain: '<Root>/Gain' incorporates:
     *  Sum: '<Root>/Add2'
     */
    lead_rtwin486_B.Gain = (lead_rtwin486_B.Gain2 - lead_rtwin486_B.Gain3) *
      lead_rtwin486_P.Kc;
  }

  /* Gain: '<Root>/Gain1' incorporates:
   *  Integrator: '<Root>/Integrator'
   *  Sum: '<Root>/Add1'
   */
  lead_rtwin486_B.Gain1 = 1.0 / lead_rtwin486_P.Tp * (lead_rtwin486_B.Gain -
    lead_rtwin486_X.Integrator_CSTATE);

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/Gain2'
   *  Integrator: '<Root>/Integrator1'
   */
  lead_rtwin486_B.Add = lead_rtwin486_P.Tz * lead_rtwin486_B.Gain1 +
    lead_rtwin486_X.Integrator1_CSTATE;
  if (rtmIsMajorTimeStep(lead_rtwin486_M)) {
    /* S-Function (pciint32dac): '<S2>/S-function2' */
    /* S-Function Block: <S1>/PCIINT32_DAQ (pciint32dac) */
    {
      real_T values[4];
      values[0] = lead_rtwin486_B.Add;
      values[1] = 0.0;
      values[2] = 0.0;
      values[3] = 0.0;
      PCIINT32_dacOutput(57072.0, values);
    }
  }
}

/* Model update function */
void lead_rtwin486_update(void)
{
  if (rtmIsMajorTimeStep(lead_rtwin486_M)) {
    rt_ertODEUpdateContinuousStates(&lead_rtwin486_M->solverInfo);
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
  if (!(++lead_rtwin486_M->Timing.clockTick0)) {
    ++lead_rtwin486_M->Timing.clockTickH0;
  }

  lead_rtwin486_M->Timing.t[0] = rtsiGetSolverStopTime
    (&lead_rtwin486_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lead_rtwin486_M->Timing.clockTick1)) {
      ++lead_rtwin486_M->Timing.clockTickH1;
    }

    lead_rtwin486_M->Timing.t[1] = lead_rtwin486_M->Timing.clockTick1 *
      lead_rtwin486_M->Timing.stepSize1 + lead_rtwin486_M->Timing.clockTickH1 *
      lead_rtwin486_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void lead_rtwin486_derivatives(void)
{
  XDot_lead_rtwin486_T *_rtXdot;
  _rtXdot = ((XDot_lead_rtwin486_T *) lead_rtwin486_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = lead_rtwin486_B.Gain1;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = lead_rtwin486_B.Gain1;
}

/* Model initialize function */
void lead_rtwin486_initialize(void)
{
  /* Start for S-Function (pciint32enc): '<S2>/S-function' */
  {
    PCIINT32_encResetAll(57072.0);
  }

  /* Start for S-Function (pciint32adc): '<S2>/S-function1' */
  {
  }

  /* Start for S-Function (pciint32dac): '<S2>/S-function2' */
  {
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  lead_rtwin486_X.Integrator_CSTATE = lead_rtwin486_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  lead_rtwin486_X.Integrator1_CSTATE = lead_rtwin486_P.Integrator1_IC;
}

/* Model terminate function */
void lead_rtwin486_terminate(void)
{
  /* Terminate for S-Function (pciint32dac): '<S2>/S-function2' */

  /* S-Function Block: <S1>/PCIINT32_DAQ (pciint32dac) */
  {
    real_T values[4] = { 0.0, 0.0, 0.0, 0.0 };

    PCIINT32_dacOutput(57072.0, values);
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
  lead_rtwin486_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lead_rtwin486_update();
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
  lead_rtwin486_initialize();
}

void MdlTerminate(void)
{
  lead_rtwin486_terminate();
}

/* Registration function */
RT_MODEL_lead_rtwin486_T *lead_rtwin486(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lead_rtwin486_M, 0,
                sizeof(RT_MODEL_lead_rtwin486_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lead_rtwin486_M->solverInfo,
                          &lead_rtwin486_M->Timing.simTimeStep);
    rtsiSetTPtr(&lead_rtwin486_M->solverInfo, &rtmGetTPtr(lead_rtwin486_M));
    rtsiSetStepSizePtr(&lead_rtwin486_M->solverInfo,
                       &lead_rtwin486_M->Timing.stepSize0);
    rtsiSetdXPtr(&lead_rtwin486_M->solverInfo, &lead_rtwin486_M->derivs);
    rtsiSetContStatesPtr(&lead_rtwin486_M->solverInfo, (real_T **)
                         &lead_rtwin486_M->contStates);
    rtsiSetNumContStatesPtr(&lead_rtwin486_M->solverInfo,
      &lead_rtwin486_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&lead_rtwin486_M->solverInfo,
      &lead_rtwin486_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&lead_rtwin486_M->solverInfo,
      &lead_rtwin486_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&lead_rtwin486_M->solverInfo,
      &lead_rtwin486_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&lead_rtwin486_M->solverInfo, (&rtmGetErrorStatus
      (lead_rtwin486_M)));
    rtsiSetRTModelPtr(&lead_rtwin486_M->solverInfo, lead_rtwin486_M);
  }

  rtsiSetSimTimeStep(&lead_rtwin486_M->solverInfo, MAJOR_TIME_STEP);
  lead_rtwin486_M->intgData.f[0] = lead_rtwin486_M->odeF[0];
  lead_rtwin486_M->contStates = ((real_T *) &lead_rtwin486_X);
  rtsiSetSolverData(&lead_rtwin486_M->solverInfo, (void *)
                    &lead_rtwin486_M->intgData);
  rtsiSetSolverName(&lead_rtwin486_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lead_rtwin486_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    lead_rtwin486_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lead_rtwin486_M->Timing.sampleTimes =
      (&lead_rtwin486_M->Timing.sampleTimesArray[0]);
    lead_rtwin486_M->Timing.offsetTimes =
      (&lead_rtwin486_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lead_rtwin486_M->Timing.sampleTimes[0] = (0.0);
    lead_rtwin486_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    lead_rtwin486_M->Timing.offsetTimes[0] = (0.0);
    lead_rtwin486_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(lead_rtwin486_M, &lead_rtwin486_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lead_rtwin486_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    lead_rtwin486_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lead_rtwin486_M, -1);
  lead_rtwin486_M->Timing.stepSize0 = 0.002;
  lead_rtwin486_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  lead_rtwin486_M->Sizes.checksums[0] = (783397135U);
  lead_rtwin486_M->Sizes.checksums[1] = (1250074504U);
  lead_rtwin486_M->Sizes.checksums[2] = (2618349441U);
  lead_rtwin486_M->Sizes.checksums[3] = (1302838540U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    lead_rtwin486_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lead_rtwin486_M->extModeInfo,
      &lead_rtwin486_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lead_rtwin486_M->extModeInfo,
                        lead_rtwin486_M->Sizes.checksums);
    rteiSetTPtr(lead_rtwin486_M->extModeInfo, rtmGetTPtr(lead_rtwin486_M));
  }

  lead_rtwin486_M->solverInfoPtr = (&lead_rtwin486_M->solverInfo);
  lead_rtwin486_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&lead_rtwin486_M->solverInfo, 0.002);
  rtsiSetSolverMode(&lead_rtwin486_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lead_rtwin486_M->blockIO = ((void *) &lead_rtwin486_B);

  {
    lead_rtwin486_B.Sfunction[0] = 0.0;
    lead_rtwin486_B.Sfunction[1] = 0.0;
    lead_rtwin486_B.Sfunction[2] = 0.0;
    lead_rtwin486_B.Sfunction[3] = 0.0;
    lead_rtwin486_B.Sfunction1[0] = 0.0;
    lead_rtwin486_B.Sfunction1[1] = 0.0;
    lead_rtwin486_B.Sfunction1[2] = 0.0;
    lead_rtwin486_B.Sfunction1[3] = 0.0;
    lead_rtwin486_B.Gain2 = 0.0;
    lead_rtwin486_B.Gain3 = 0.0;
    lead_rtwin486_B.Gain = 0.0;
    lead_rtwin486_B.Gain1 = 0.0;
    lead_rtwin486_B.Add = 0.0;
  }

  /* parameters */
  lead_rtwin486_M->defaultParam = ((real_T *)&lead_rtwin486_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &lead_rtwin486_X;
    lead_rtwin486_M->contStates = (x);
    (void) memset((void *)&lead_rtwin486_X, 0,
                  sizeof(X_lead_rtwin486_T));
  }

  /* states (dwork) */
  lead_rtwin486_M->dwork = ((void *) &lead_rtwin486_DW);
  (void) memset((void *)&lead_rtwin486_DW, 0,
                sizeof(DW_lead_rtwin486_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lead_rtwin486_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  lead_rtwin486_M->Sizes.numContStates = (2);/* Number of continuous states */
  lead_rtwin486_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  lead_rtwin486_M->Sizes.numY = (0);   /* Number of model outputs */
  lead_rtwin486_M->Sizes.numU = (0);   /* Number of model inputs */
  lead_rtwin486_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lead_rtwin486_M->Sizes.numSampTimes = (2);/* Number of sample times */
  lead_rtwin486_M->Sizes.numBlocks = (14);/* Number of blocks */
  lead_rtwin486_M->Sizes.numBlockIO = (7);/* Number of block outputs */
  lead_rtwin486_M->Sizes.numBlockPrms = (7);/* Sum of parameter "widths" */
  return lead_rtwin486_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
