/*
 * three_part_three.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "three_part_three".
 *
 * Model version              : 1.3
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Fri Sep 27 12:15:07 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "three_part_three.h"
#include "three_part_three_private.h"
#include "three_part_three_dt.h"

/* Block signals (auto storage) */
B_three_part_three_T three_part_three_B;

/* Continuous states */
X_three_part_three_T three_part_three_X;

/* Block states (auto storage) */
DW_three_part_three_T three_part_three_DW;

/* Real-time model */
RT_MODEL_three_part_three_T three_part_three_M_;
RT_MODEL_three_part_three_T *const three_part_three_M = &three_part_three_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(three_part_three_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(three_part_three_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (three_part_three_M->Timing.TaskCounters.TID[1] == 0) {
    three_part_three_M->Timing.RateInteraction.TID1_2 =
      (three_part_three_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    three_part_three_M->Timing.perTaskSampleHits[5] =
      three_part_three_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (three_part_three_M->Timing.TaskCounters.TID[2])++;
  if ((three_part_three_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    three_part_three_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  three_part_three_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  three_part_three_output0();
  three_part_three_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  three_part_three_output0();
  three_part_three_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void three_part_three_output0(void)    /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_Ki[2];
  real_T rtb_Backgain;
  real_T rtb_Frontgain;
  real_T tmp[5];
  int32_T i;
  int32_T i_0;
  real_T u0;
  if (rtmIsMajorTimeStep(three_part_three_M)) {
    /* set solver stop time */
    if (!(three_part_three_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&three_part_three_M->solverInfo,
                            ((three_part_three_M->Timing.clockTickH0 + 1) *
        three_part_three_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&three_part_three_M->solverInfo,
                            ((three_part_three_M->Timing.clockTick0 + 1) *
        three_part_three_M->Timing.stepSize0 +
        three_part_three_M->Timing.clockTickH0 *
        three_part_three_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(three_part_three_M)) {
    three_part_three_M->Timing.t[0] = rtsiGetT(&three_part_three_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(three_part_three_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

    /* S-Function Block: three_part_three/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (three_part_three_DW.HILReadEncoderTimebase_Task, 1,
         &three_part_three_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          three_part_three_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          three_part_three_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          three_part_three_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Constant: '<Root>/Constant1' */
    three_part_three_B.Constant1 = three_part_three_P.v_s0;

    /* RateTransition: '<S4>/Rate Transition: x' */
    if (three_part_three_M->Timing.RateInteraction.TID1_2) {
      three_part_three_B.RateTransitionx =
        three_part_three_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: x' */

    /* DeadZone: '<S4>/Dead Zone: x' */
    if (three_part_three_B.RateTransitionx > three_part_three_P.DeadZonex_End) {
      rtb_Backgain = three_part_three_B.RateTransitionx -
        three_part_three_P.DeadZonex_End;
    } else if (three_part_three_B.RateTransitionx >=
               three_part_three_P.DeadZonex_Start) {
      rtb_Backgain = 0.0;
    } else {
      rtb_Backgain = three_part_three_B.RateTransitionx -
        three_part_three_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: x' */

    /* Gain: '<S4>/Joystick_gain_x' incorporates:
     *  Gain: '<S4>/Gain: x'
     */
    three_part_three_B.Joystick_gain_x = three_part_three_P.Gainx_Gain *
      rtb_Backgain * three_part_three_P.Joystick_gain_x;

    /* RateTransition: '<S4>/Rate Transition: y' */
    if (three_part_three_M->Timing.RateInteraction.TID1_2) {
      three_part_three_B.RateTransitiony =
        three_part_three_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: y' */

    /* DeadZone: '<S4>/Dead Zone: y' */
    if (three_part_three_B.RateTransitiony > three_part_three_P.DeadZoney_End) {
      rtb_Backgain = three_part_three_B.RateTransitiony -
        three_part_three_P.DeadZoney_End;
    } else if (three_part_three_B.RateTransitiony >=
               three_part_three_P.DeadZoney_Start) {
      rtb_Backgain = 0.0;
    } else {
      rtb_Backgain = three_part_three_B.RateTransitiony -
        three_part_three_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: y' */

    /* Gain: '<S4>/Joystick_gain_y' incorporates:
     *  Gain: '<S4>/Gain: y'
     */
    three_part_three_B.Joystick_gain_y = three_part_three_P.Gainy_Gain *
      rtb_Backgain * three_part_three_P.Joystick_gain_y;

    /* Gain: '<S6>/Gain' incorporates:
     *  SignalConversion: '<S6>/TmpSignal ConversionAtGainInport1'
     */
    three_part_three_B.Gain[0] = 0.0;
    three_part_three_B.Gain[0] += three_part_three_P.F[0] *
      three_part_three_B.Joystick_gain_x;
    three_part_three_B.Gain[0] += three_part_three_P.F[2] *
      three_part_three_B.Joystick_gain_y;
    three_part_three_B.Gain[1] = 0.0;
    three_part_three_B.Gain[1] += three_part_three_P.F[1] *
      three_part_three_B.Joystick_gain_x;
    three_part_three_B.Gain[1] += three_part_three_P.F[3] *
      three_part_three_B.Joystick_gain_y;

    /* Gain: '<S3>/Pitch: Count to rad' */
    three_part_three_B.PitchCounttorad = three_part_three_P.PitchCounttorad_Gain
      * rtb_HILReadEncoderTimebase_o2;

    /* Sum: '<S3>/Sum1' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    three_part_three_B.Sum1 = three_part_three_B.PitchCounttorad -
      three_part_three_P.Constant1_Value;

    /* Gain: '<S3>/Elevation: Count to rad' */
    three_part_three_B.ElevationCounttorad =
      three_part_three_P.ElevationCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o3;
  }

  /* TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  three_part_three_B.PitchTransferFcn = 0.0;
  three_part_three_B.PitchTransferFcn += three_part_three_P.PitchTransferFcn_C *
    three_part_three_X.PitchTransferFcn_CSTATE;
  three_part_three_B.PitchTransferFcn += three_part_three_P.PitchTransferFcn_D *
    three_part_three_B.PitchCounttorad;

  /* TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  three_part_three_B.ElevationTransferFcn = 0.0;
  three_part_three_B.ElevationTransferFcn +=
    three_part_three_P.ElevationTransferFcn_C *
    three_part_three_X.ElevationTransferFcn_CSTATE;
  three_part_three_B.ElevationTransferFcn +=
    three_part_three_P.ElevationTransferFcn_D *
    three_part_three_B.ElevationCounttorad;

  /* SignalConversion: '<S7>/TmpSignal ConversionAtKiInport1' incorporates:
   *  Integrator: '<S8>/Integrator'
   *  Integrator: '<S8>/Integrator1'
   */
  tmp[0] = three_part_three_B.Sum1;
  tmp[1] = three_part_three_B.PitchTransferFcn;
  tmp[2] = three_part_three_B.ElevationTransferFcn;
  tmp[3] = three_part_three_X.Integrator_CSTATE;
  tmp[4] = three_part_three_X.Integrator1_CSTATE;

  /* Gain: '<S7>/Ki' */
  for (i = 0; i < 2; i++) {
    rtb_Ki[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_Ki[i] += three_part_three_P.Ki[(i_0 << 1) + i] * tmp[i_0];
    }
  }

  /* End of Gain: '<S7>/Ki' */

  /* Sum: '<Root>/Sum1' */
  rtb_Backgain = three_part_three_B.Gain[1] - rtb_Ki[1];

  /* Sum: '<Root>/Sum2' incorporates:
   *  Sum: '<Root>/Sum'
   */
  rtb_Frontgain = (three_part_three_B.Gain[0] - rtb_Ki[0]) +
    three_part_three_B.Constant1;
  if (rtmIsMajorTimeStep(three_part_three_M)) {
    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/Constant'
     */
    three_part_three_B.Sum = three_part_three_B.ElevationCounttorad -
      three_part_three_P.Constant_Value;

    /* Gain: '<S3>/Travel: Count to rad' */
    three_part_three_B.TravelCounttorad =
      three_part_three_P.TravelCounttorad_Gain * rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S3>/Travel: Transfer Fcn' */
  three_part_three_B.TravelTransferFcn = 0.0;
  three_part_three_B.TravelTransferFcn += three_part_three_P.TravelTransferFcn_C
    * three_part_three_X.TravelTransferFcn_CSTATE;
  three_part_three_B.TravelTransferFcn += three_part_three_P.TravelTransferFcn_D
    * three_part_three_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(three_part_three_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  u0 = (rtb_Frontgain - rtb_Backgain) * three_part_three_P.Frontgain_Gain;

  /* Saturate: '<S3>/Front motor: Saturation' */
  if (u0 > three_part_three_P.FrontmotorSaturation_UpperSat) {
    three_part_three_B.FrontmotorSaturation =
      three_part_three_P.FrontmotorSaturation_UpperSat;
  } else if (u0 < three_part_three_P.FrontmotorSaturation_LowerSat) {
    three_part_three_B.FrontmotorSaturation =
      three_part_three_P.FrontmotorSaturation_LowerSat;
  } else {
    three_part_three_B.FrontmotorSaturation = u0;
  }

  /* End of Saturate: '<S3>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  u0 = (rtb_Frontgain + rtb_Backgain) * three_part_three_P.Backgain_Gain;

  /* Saturate: '<S3>/Back motor: Saturation' */
  if (u0 > three_part_three_P.BackmotorSaturation_UpperSat) {
    three_part_three_B.BackmotorSaturation =
      three_part_three_P.BackmotorSaturation_UpperSat;
  } else if (u0 < three_part_three_P.BackmotorSaturation_LowerSat) {
    three_part_three_B.BackmotorSaturation =
      three_part_three_P.BackmotorSaturation_LowerSat;
  } else {
    three_part_three_B.BackmotorSaturation = u0;
  }

  /* End of Saturate: '<S3>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(three_part_three_M)) {
    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: three_part_three/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      three_part_three_DW.HILWriteAnalog_Buffer[0] =
        three_part_three_B.FrontmotorSaturation;
      three_part_three_DW.HILWriteAnalog_Buffer[1] =
        three_part_three_B.BackmotorSaturation;
      result = hil_write_analog(three_part_three_DW.HILInitialize_Card,
        three_part_three_P.HILWriteAnalog_channels, 2,
        &three_part_three_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
      }
    }

    /* Sum: '<S8>/Sum3' */
    three_part_three_B.Sum3 = three_part_three_B.Sum1 -
      three_part_three_B.Joystick_gain_x;
  }

  /* Sum: '<S8>/Sum4' */
  three_part_three_B.Sum4 = three_part_three_B.ElevationTransferFcn -
    three_part_three_B.Joystick_gain_y;

  /* Integrator: '<S9>/Integrator' */
  /* Limited  Integrator  */
  if (three_part_three_X.Integrator_CSTATE_k >=
      three_part_three_P.Integrator_UpperSat) {
    three_part_three_X.Integrator_CSTATE_k =
      three_part_three_P.Integrator_UpperSat;
  } else {
    if (three_part_three_X.Integrator_CSTATE_k <=
        three_part_three_P.Integrator_LowerSat) {
      three_part_three_X.Integrator_CSTATE_k =
        three_part_three_P.Integrator_LowerSat;
    }
  }

  /* End of Integrator: '<S9>/Integrator' */
  if (rtmIsMajorTimeStep(three_part_three_M)) {
    /* Gain: '<S9>/K_ei' incorporates:
     *  Sum: '<S2>/Sum'
     */
    three_part_three_B.K_ei = three_part_three_P.K_ei_Gain * 0.0;

    /* Gain: '<Root>/k_d' */
    three_part_three_B.k_d = three_part_three_P.k_d_Gain * 0.0;

    /* Gain: '<Root>/k_f' */
    three_part_three_B.k_f = three_part_three_P.k_f_Gain * 0.0;
  }
}

/* Model update function for TID0 */
void three_part_three_update0(void)    /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(three_part_three_M)) {
    rt_ertODEUpdateContinuousStates(&three_part_three_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++three_part_three_M->Timing.clockTick0)) {
    ++three_part_three_M->Timing.clockTickH0;
  }

  three_part_three_M->Timing.t[0] = rtsiGetSolverStopTime
    (&three_part_three_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++three_part_three_M->Timing.clockTick1)) {
    ++three_part_three_M->Timing.clockTickH1;
  }

  three_part_three_M->Timing.t[1] = three_part_three_M->Timing.clockTick1 *
    three_part_three_M->Timing.stepSize1 +
    three_part_three_M->Timing.clockTickH1 *
    three_part_three_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void three_part_three_derivatives(void)
{
  boolean_T lsat;
  boolean_T usat;
  XDot_three_part_three_T *_rtXdot;
  _rtXdot = ((XDot_three_part_three_T *) three_part_three_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += three_part_three_P.PitchTransferFcn_A *
    three_part_three_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += three_part_three_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    three_part_three_P.ElevationTransferFcn_A *
    three_part_three_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += three_part_three_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S8>/Integrator' */
  _rtXdot->Integrator_CSTATE = three_part_three_B.Sum3;

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = three_part_three_B.Sum4;

  /* Derivatives for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += three_part_three_P.TravelTransferFcn_A *
    three_part_three_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += three_part_three_B.TravelCounttorad;

  /* Derivatives for Integrator: '<S9>/Integrator' */
  lsat = (three_part_three_X.Integrator_CSTATE_k <=
          three_part_three_P.Integrator_LowerSat);
  usat = (three_part_three_X.Integrator_CSTATE_k >=
          three_part_three_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (three_part_three_B.K_ei > 0.0)) || (usat
       && (three_part_three_B.K_ei < 0.0))) {
    _rtXdot->Integrator_CSTATE_k = three_part_three_B.K_ei;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE_k = 0.0;
  }

  /* End of Derivatives for Integrator: '<S9>/Integrator' */

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = 0.0;
}

/* Model output function for TID2 */
void three_part_three_output2(void)    /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: three_part_three/Joystick/Game Controller (game_controller_block) */
  {
    if (three_part_three_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll
        (three_part_three_DW.GameController_Controller, &state, &new_data);
      if (result == 0) {
        three_part_three_B.GameController_o4 = state.x;
        three_part_three_B.GameController_o5 = state.y;
      }
    } else {
      three_part_three_B.GameController_o4 = 0;
      three_part_three_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void three_part_three_update2(void)    /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S4>/Rate Transition: x' */
  three_part_three_DW.RateTransitionx_Buffer0 =
    three_part_three_B.GameController_o4;

  /* Update for RateTransition: '<S4>/Rate Transition: y' */
  three_part_three_DW.RateTransitiony_Buffer0 =
    three_part_three_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++three_part_three_M->Timing.clockTick2)) {
    ++three_part_three_M->Timing.clockTickH2;
  }

  three_part_three_M->Timing.t[2] = three_part_three_M->Timing.clockTick2 *
    three_part_three_M->Timing.stepSize2 +
    three_part_three_M->Timing.clockTickH2 *
    three_part_three_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void three_part_three_output(int_T tid)
{
  switch (tid) {
   case 0 :
    three_part_three_output0();
    break;

   case 2 :
    three_part_three_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void three_part_three_update(int_T tid)
{
  switch (tid) {
   case 0 :
    three_part_three_update0();
    break;

   case 2 :
    three_part_three_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void three_part_three_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: three_part_three/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &three_part_three_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(three_part_three_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (three_part_three_DW.HILInitialize_Card, "update_rate=normal;decimation=1",
       32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(three_part_three_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(three_part_three_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(three_part_three_M, _rt_error_message);
      return;
    }

    if ((three_part_three_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (three_part_three_P.HILInitialize_set_analog_inpu_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &three_part_three_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = three_part_three_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &three_part_three_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = three_part_three_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges
        (three_part_three_DW.HILInitialize_Card,
         three_part_three_P.HILInitialize_analog_input_chan, 8U,
         &three_part_three_DW.HILInitialize_AIMinimums[0],
         &three_part_three_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
        return;
      }
    }

    if ((three_part_three_P.HILInitialize_set_analog_output && !is_switching) ||
        (three_part_three_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &three_part_three_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = three_part_three_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &three_part_three_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = three_part_three_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges
        (three_part_three_DW.HILInitialize_Card,
         three_part_three_P.HILInitialize_analog_output_cha, 8U,
         &three_part_three_DW.HILInitialize_AOMinimums[0],
         &three_part_three_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
        return;
      }
    }

    if ((three_part_three_P.HILInitialize_set_analog_outp_f && !is_switching) ||
        (three_part_three_P.HILInitialize_set_analog_outp_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &three_part_three_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = three_part_three_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(three_part_three_DW.HILInitialize_Card,
        three_part_three_P.HILInitialize_analog_output_cha, 8U,
        &three_part_three_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
        return;
      }
    }

    if (three_part_three_P.HILInitialize_set_analog_outp_c) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &three_part_three_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = three_part_three_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (three_part_three_DW.HILInitialize_Card,
         three_part_three_P.HILInitialize_analog_output_cha, 8U,
         &three_part_three_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
        return;
      }
    }

    if ((three_part_three_P.HILInitialize_set_encoder_param && !is_switching) ||
        (three_part_three_P.HILInitialize_set_encoder_par_j && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &three_part_three_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = three_part_three_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (three_part_three_DW.HILInitialize_Card,
         three_part_three_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &three_part_three_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
        return;
      }
    }

    if ((three_part_three_P.HILInitialize_set_encoder_count && !is_switching) ||
        (three_part_three_P.HILInitialize_set_encoder_cou_h && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &three_part_three_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            three_part_three_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(three_part_three_DW.HILInitialize_Card,
        three_part_three_P.HILInitialize_encoder_channels, 8U,
        &three_part_three_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
        return;
      }
    }

    if ((three_part_three_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (three_part_three_P.HILInitialize_set_pwm_params__i && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &three_part_three_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = three_part_three_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(three_part_three_DW.HILInitialize_Card,
        three_part_three_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &three_part_three_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          three_part_three_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues =
          &three_part_three_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            three_part_three_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = p_HILInitialize_pwm_channels[i1];
            three_part_three_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = three_part_three_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            three_part_three_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            three_part_three_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              three_part_three_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(three_part_three_DW.HILInitialize_Card,
          &three_part_three_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &three_part_three_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(three_part_three_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(three_part_three_DW.HILInitialize_Card,
          &three_part_three_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &three_part_three_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(three_part_three_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &three_part_three_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            three_part_three_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &three_part_three_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = three_part_three_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &three_part_three_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = three_part_three_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(three_part_three_DW.HILInitialize_Card,
        three_part_three_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &three_part_three_DW.HILInitialize_POModeValues
        [0],
        (t_pwm_alignment *) &three_part_three_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &three_part_three_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &three_part_three_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            three_part_three_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &three_part_three_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = three_part_three_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(three_part_three_DW.HILInitialize_Card,
        three_part_three_P.HILInitialize_pwm_channels, 8U,
        &three_part_three_DW.HILInitialize_POSortedFreqs[0],
        &three_part_three_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
        return;
      }
    }

    if ((three_part_three_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (three_part_three_P.HILInitialize_set_pwm_outputs_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &three_part_three_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = three_part_three_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(three_part_three_DW.HILInitialize_Card,
        three_part_three_P.HILInitialize_pwm_channels, 8U,
        &three_part_three_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
        return;
      }
    }

    if (three_part_three_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &three_part_three_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = three_part_three_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (three_part_three_DW.HILInitialize_Card,
         three_part_three_P.HILInitialize_pwm_channels, 8U,
         &three_part_three_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

  /* S-Function Block: three_part_three/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (three_part_three_DW.HILInitialize_Card,
       three_part_three_P.HILReadEncoderTimebase_samples_,
       three_part_three_P.HILReadEncoderTimebase_channels, 3,
       &three_part_three_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(three_part_three_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S4>/Rate Transition: x' */
  three_part_three_B.RateTransitionx = three_part_three_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S4>/Rate Transition: y' */
  three_part_three_B.RateTransitiony = three_part_three_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: three_part_three/Joystick/Game Controller (game_controller_block) */
  {
    if (three_part_three_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (three_part_three_P.GameController_ControllerNumber,
         three_part_three_P.GameController_BufferSize, deadzone, saturation,
         three_part_three_P.GameController_AutoCenter, 0, 1.0,
         &three_part_three_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(three_part_three_M, _rt_error_message);
      }
    }
  }

  /* InitializeConditions for RateTransition: '<S4>/Rate Transition: x' */
  three_part_three_DW.RateTransitionx_Buffer0 =
    three_part_three_P.RateTransitionx_X0;

  /* InitializeConditions for RateTransition: '<S4>/Rate Transition: y' */
  three_part_three_DW.RateTransitiony_Buffer0 =
    three_part_three_P.RateTransitiony_X0;

  /* InitializeConditions for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  three_part_three_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  three_part_three_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S8>/Integrator' */
  three_part_three_X.Integrator_CSTATE = three_part_three_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  three_part_three_X.Integrator1_CSTATE = three_part_three_P.Integrator1_IC;

  /* InitializeConditions for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  three_part_three_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S9>/Integrator' */
  three_part_three_X.Integrator_CSTATE_k = three_part_three_P.Integrator_IC_p;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  three_part_three_X.Integrator_CSTATE_c = three_part_three_P.Integrator_IC_k;
}

/* Model terminate function */
void three_part_three_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: three_part_three/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(three_part_three_DW.HILInitialize_Card);
    hil_monitor_stop_all(three_part_three_DW.HILInitialize_Card);
    is_switching = false;
    if ((three_part_three_P.HILInitialize_set_analog_outp_b && !is_switching) ||
        (three_part_three_P.HILInitialize_set_analog_outp_l && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &three_part_three_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = three_part_three_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((three_part_three_P.HILInitialize_set_pwm_outputs_e && !is_switching) ||
        (three_part_three_P.HILInitialize_set_pwm_outputs_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &three_part_three_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = three_part_three_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(three_part_three_DW.HILInitialize_Card
                         , three_part_three_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , three_part_three_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &three_part_three_DW.HILInitialize_AOVoltages[0]
                         , &three_part_three_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(three_part_three_DW.HILInitialize_Card,
            three_part_three_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs,
            &three_part_three_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(three_part_three_DW.HILInitialize_Card,
            three_part_three_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &three_part_three_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(three_part_three_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(three_part_three_DW.HILInitialize_Card);
    hil_monitor_delete_all(three_part_three_DW.HILInitialize_Card);
    hil_close(three_part_three_DW.HILInitialize_Card);
    three_part_three_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: three_part_three/Joystick/Game Controller (game_controller_block) */
  {
    if (three_part_three_P.GameController_Enabled) {
      game_controller_close(three_part_three_DW.GameController_Controller);
      three_part_three_DW.GameController_Controller = NULL;
    }
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
  if (tid == 1)
    tid = 0;
  three_part_three_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  three_part_three_update(tid);
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
  three_part_three_initialize();
}

void MdlTerminate(void)
{
  three_part_three_terminate();
}

/* Registration function */
RT_MODEL_three_part_three_T *three_part_three(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  three_part_three_P.Integrator_UpperSat = rtInf;
  three_part_three_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)three_part_three_M, 0,
                sizeof(RT_MODEL_three_part_three_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&three_part_three_M->solverInfo,
                          &three_part_three_M->Timing.simTimeStep);
    rtsiSetTPtr(&three_part_three_M->solverInfo, &rtmGetTPtr(three_part_three_M));
    rtsiSetStepSizePtr(&three_part_three_M->solverInfo,
                       &three_part_three_M->Timing.stepSize0);
    rtsiSetdXPtr(&three_part_three_M->solverInfo,
                 &three_part_three_M->ModelData.derivs);
    rtsiSetContStatesPtr(&three_part_three_M->solverInfo, (real_T **)
                         &three_part_three_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&three_part_three_M->solverInfo,
      &three_part_three_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&three_part_three_M->solverInfo,
      &three_part_three_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&three_part_three_M->solverInfo,
      &three_part_three_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&three_part_three_M->solverInfo,
      &three_part_three_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&three_part_three_M->solverInfo, (&rtmGetErrorStatus
      (three_part_three_M)));
    rtsiSetRTModelPtr(&three_part_three_M->solverInfo, three_part_three_M);
  }

  rtsiSetSimTimeStep(&three_part_three_M->solverInfo, MAJOR_TIME_STEP);
  three_part_three_M->ModelData.intgData.y = three_part_three_M->ModelData.odeY;
  three_part_three_M->ModelData.intgData.f[0] =
    three_part_three_M->ModelData.odeF[0];
  three_part_three_M->ModelData.intgData.f[1] =
    three_part_three_M->ModelData.odeF[1];
  three_part_three_M->ModelData.intgData.f[2] =
    three_part_three_M->ModelData.odeF[2];
  three_part_three_M->ModelData.contStates = ((real_T *) &three_part_three_X);
  rtsiSetSolverData(&three_part_three_M->solverInfo, (void *)
                    &three_part_three_M->ModelData.intgData);
  rtsiSetSolverName(&three_part_three_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = three_part_three_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    three_part_three_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    three_part_three_M->Timing.sampleTimes =
      (&three_part_three_M->Timing.sampleTimesArray[0]);
    three_part_three_M->Timing.offsetTimes =
      (&three_part_three_M->Timing.offsetTimesArray[0]);

    /* task periods */
    three_part_three_M->Timing.sampleTimes[0] = (0.0);
    three_part_three_M->Timing.sampleTimes[1] = (0.002);
    three_part_three_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    three_part_three_M->Timing.offsetTimes[0] = (0.0);
    three_part_three_M->Timing.offsetTimes[1] = (0.0);
    three_part_three_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(three_part_three_M, &three_part_three_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = three_part_three_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      three_part_three_M->Timing.perTaskSampleHitsArray;
    three_part_three_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    three_part_three_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(three_part_three_M, -1);
  three_part_three_M->Timing.stepSize0 = 0.002;
  three_part_three_M->Timing.stepSize1 = 0.002;
  three_part_three_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  three_part_three_M->Sizes.checksums[0] = (3123597158U);
  three_part_three_M->Sizes.checksums[1] = (3147149430U);
  three_part_three_M->Sizes.checksums[2] = (2820147630U);
  three_part_three_M->Sizes.checksums[3] = (3410604857U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    three_part_three_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(three_part_three_M->extModeInfo,
      &three_part_three_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(three_part_three_M->extModeInfo,
                        three_part_three_M->Sizes.checksums);
    rteiSetTPtr(three_part_three_M->extModeInfo, rtmGetTPtr(three_part_three_M));
  }

  three_part_three_M->solverInfoPtr = (&three_part_three_M->solverInfo);
  three_part_three_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&three_part_three_M->solverInfo, 0.002);
  rtsiSetSolverMode(&three_part_three_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  three_part_three_M->ModelData.blockIO = ((void *) &three_part_three_B);
  (void) memset(((void *) &three_part_three_B), 0,
                sizeof(B_three_part_three_T));

  /* parameters */
  three_part_three_M->ModelData.defaultParam = ((real_T *)&three_part_three_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &three_part_three_X;
    three_part_three_M->ModelData.contStates = (x);
    (void) memset((void *)&three_part_three_X, 0,
                  sizeof(X_three_part_three_T));
  }

  /* states (dwork) */
  three_part_three_M->ModelData.dwork = ((void *) &three_part_three_DW);
  (void) memset((void *)&three_part_three_DW, 0,
                sizeof(DW_three_part_three_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    three_part_three_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  three_part_three_M->Sizes.numContStates = (7);/* Number of continuous states */
  three_part_three_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  three_part_three_M->Sizes.numY = (0);/* Number of model outputs */
  three_part_three_M->Sizes.numU = (0);/* Number of model inputs */
  three_part_three_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  three_part_three_M->Sizes.numSampTimes = (3);/* Number of sample times */
  three_part_three_M->Sizes.numBlocks = (56);/* Number of blocks */
  three_part_three_M->Sizes.numBlockIO = (23);/* Number of block outputs */
  three_part_three_M->Sizes.numBlockPrms = (161);/* Sum of parameter "widths" */
  return three_part_three_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
