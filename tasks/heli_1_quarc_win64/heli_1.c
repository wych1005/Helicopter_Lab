/*
 * heli_1.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_1".
 *
 * Model version              : 1.63
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Fri Nov 08 21:55:54 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_1.h"
#include "heli_1_private.h"
#include "heli_1_dt.h"

/* Block signals (auto storage) */
B_heli_1_T heli_1_B;

/* Continuous states */
X_heli_1_T heli_1_X;

/* Block states (auto storage) */
DW_heli_1_T heli_1_DW;

/* Real-time model */
RT_MODEL_heli_1_T heli_1_M_;
RT_MODEL_heli_1_T *const heli_1_M = &heli_1_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_1_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_1_M, 2);
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
  if (heli_1_M->Timing.TaskCounters.TID[1] == 0) {
    heli_1_M->Timing.RateInteraction.TID1_2 = (heli_1_M->
      Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_1_M->Timing.perTaskSampleHits[5] =
      heli_1_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_1_M->Timing.TaskCounters.TID[2])++;
  if ((heli_1_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_1_M->Timing.TaskCounters.TID[2] = 0;
  }
}

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
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_1_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void heli_1_output0(void)              /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_FrontmotorSaturation;
  real_T rtb_BackmotorSaturation;
  if (rtmIsMajorTimeStep(heli_1_M)) {
    /* set solver stop time */
    if (!(heli_1_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_1_M->solverInfo,
                            ((heli_1_M->Timing.clockTickH0 + 1) *
        heli_1_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_1_M->solverInfo, ((heli_1_M->Timing.clockTick0
        + 1) * heli_1_M->Timing.stepSize0 + heli_1_M->Timing.clockTickH0 *
        heli_1_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_1_M)) {
    heli_1_M->Timing.t[0] = rtsiGetT(&heli_1_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(heli_1_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_1/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(heli_1_DW.HILReadEncoderTimebase_Task, 1,
        &heli_1_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 = heli_1_DW.HILReadEncoderTimebase_Buffer
          [0];
        rtb_FrontmotorSaturation = heli_1_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_BackmotorSaturation = heli_1_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }
  }

  /* Integrator: '<S1>/Integrator1' */
  heli_1_B.Integrator1 = heli_1_X.Integrator1_CSTATE;

  /* Integrator: '<S1>/Integrator' */
  heli_1_B.Integrator = heli_1_X.Integrator_CSTATE;

  /* Integrator: '<S1>/Integrator3' */
  heli_1_B.Integrator3 = heli_1_X.Integrator3_CSTATE;

  /* Integrator: '<S1>/Integrator2' */
  heli_1_B.Integrator2 = heli_1_X.Integrator2_CSTATE;

  /* Integrator: '<S1>/Integrator5' */
  heli_1_B.Integrator5 = heli_1_X.Integrator5_CSTATE;

  /* Integrator: '<S1>/Integrator4' */
  heli_1_B.Integrator4 = heli_1_X.Integrator4_CSTATE;
  if (rtmIsMajorTimeStep(heli_1_M)) {
    /* Gain: '<S3>/Travel: Count to rad' */
    heli_1_B.TravelCounttorad = heli_1_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* Gain: '<S3>/Pitch: Count to rad' */
    heli_1_B.PitchCounttorad = heli_1_P.PitchCounttorad_Gain *
      rtb_FrontmotorSaturation;
  }

  /* TransferFcn: '<S3>/Travel: Transfer Fcn' */
  heli_1_B.TravelTransferFcn = 0.0;
  heli_1_B.TravelTransferFcn += heli_1_P.TravelTransferFcn_C *
    heli_1_X.TravelTransferFcn_CSTATE;
  heli_1_B.TravelTransferFcn += heli_1_P.TravelTransferFcn_D *
    heli_1_B.TravelCounttorad;

  /* TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  heli_1_B.PitchTransferFcn = 0.0;
  heli_1_B.PitchTransferFcn += heli_1_P.PitchTransferFcn_C *
    heli_1_X.PitchTransferFcn_CSTATE;
  heli_1_B.PitchTransferFcn += heli_1_P.PitchTransferFcn_D *
    heli_1_B.PitchCounttorad;
  if (rtmIsMajorTimeStep(heli_1_M)) {
    /* Gain: '<S3>/Elevation: Count to rad' */
    heli_1_B.ElevationCounttorad = heli_1_P.ElevationCounttorad_Gain *
      rtb_BackmotorSaturation;

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/Constant'
     */
    heli_1_B.Sum = heli_1_B.ElevationCounttorad - heli_1_P.Constant_Value;
  }

  /* TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  heli_1_B.ElevationTransferFcn = 0.0;
  heli_1_B.ElevationTransferFcn += heli_1_P.ElevationTransferFcn_C *
    heli_1_X.ElevationTransferFcn_CSTATE;
  heli_1_B.ElevationTransferFcn += heli_1_P.ElevationTransferFcn_D *
    heli_1_B.ElevationCounttorad;

  /* Sum: '<Root>/Sum1' */
  heli_1_B.Sum1[0] = heli_1_B.TravelCounttorad - heli_1_B.Integrator1;
  heli_1_B.Sum1[1] = heli_1_B.TravelTransferFcn - heli_1_B.Integrator;
  heli_1_B.Sum1[2] = heli_1_B.PitchCounttorad - heli_1_B.Integrator3;
  heli_1_B.Sum1[3] = heli_1_B.PitchTransferFcn - heli_1_B.Integrator2;
  heli_1_B.Sum1[4] = heli_1_B.Sum - heli_1_B.Integrator5;
  heli_1_B.Sum1[5] = heli_1_B.ElevationTransferFcn - heli_1_B.Integrator4;
  if (rtmIsMajorTimeStep(heli_1_M)) {
    /* RateTransition: '<S4>/Rate Transition: y' */
    if (heli_1_M->Timing.RateInteraction.TID1_2) {
      heli_1_B.RateTransitiony = heli_1_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: y' */

    /* DeadZone: '<S4>/Dead Zone: y' */
    if (heli_1_B.RateTransitiony > heli_1_P.DeadZoney_End) {
      rtb_BackmotorSaturation = heli_1_B.RateTransitiony -
        heli_1_P.DeadZoney_End;
    } else if (heli_1_B.RateTransitiony >= heli_1_P.DeadZoney_Start) {
      rtb_BackmotorSaturation = 0.0;
    } else {
      rtb_BackmotorSaturation = heli_1_B.RateTransitiony -
        heli_1_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: y' */

    /* Gain: '<S4>/Joystick_gain_y' incorporates:
     *  Gain: '<S4>/Gain: y'
     */
    heli_1_B.Joystick_gain_y = heli_1_P.Gainy_Gain * rtb_BackmotorSaturation *
      heli_1_P.Joystick_gain_y;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/v_s0'
     *  Gain: '<Root>/k_y'
     */
    heli_1_B.Sum_o = heli_1_P.k_y_Gain * heli_1_B.Joystick_gain_y +
      heli_1_P.v_s0;

    /* RateTransition: '<S4>/Rate Transition: x' */
    if (heli_1_M->Timing.RateInteraction.TID1_2) {
      heli_1_B.RateTransitionx = heli_1_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: x' */

    /* DeadZone: '<S4>/Dead Zone: x' */
    if (heli_1_B.RateTransitionx > heli_1_P.DeadZonex_End) {
      rtb_BackmotorSaturation = heli_1_B.RateTransitionx -
        heli_1_P.DeadZonex_End;
    } else if (heli_1_B.RateTransitionx >= heli_1_P.DeadZonex_Start) {
      rtb_BackmotorSaturation = 0.0;
    } else {
      rtb_BackmotorSaturation = heli_1_B.RateTransitionx -
        heli_1_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: x' */

    /* Gain: '<S4>/Joystick_gain_x' incorporates:
     *  Gain: '<S4>/Gain: x'
     */
    heli_1_B.Joystick_gain_x = heli_1_P.Gainx_Gain * rtb_BackmotorSaturation *
      heli_1_P.Joystick_gain_x;

    /* Gain: '<S1>/k_1' */
    heli_1_B.k_1 = heli_1_P.k_1 * heli_1_B.Joystick_gain_x;

    /* Gain: '<S1>/k_2' incorporates:
     *  Constant: '<S1>/Constant'
     *  Sum: '<S1>/Sum'
     */
    heli_1_B.k_2 = (heli_1_B.Sum_o - heli_1_P.v_s0) * heli_1_P.k_2;
  }

  /* Gain: '<S1>/k_3' incorporates:
   *  Product: '<S1>/Product'
   */
  heli_1_B.k_3 = heli_1_B.Sum_o * heli_1_B.Integrator3 * heli_1_P.k_3;
  if (rtmIsMajorTimeStep(heli_1_M)) {
    /* Gain: '<S2>/Back gain' incorporates:
     *  Sum: '<S2>/Subtract'
     */
    rtb_BackmotorSaturation = (heli_1_B.Sum_o + heli_1_B.Joystick_gain_x) *
      heli_1_P.Backgain_Gain;

    /* Gain: '<S2>/Front gain' incorporates:
     *  Sum: '<S2>/Add'
     */
    rtb_FrontmotorSaturation = (heli_1_B.Sum_o - heli_1_B.Joystick_gain_x) *
      heli_1_P.Frontgain_Gain;

    /* Saturate: '<S3>/Front motor: Saturation' */
    if (rtb_FrontmotorSaturation > heli_1_P.FrontmotorSaturation_UpperSat) {
      rtb_FrontmotorSaturation = heli_1_P.FrontmotorSaturation_UpperSat;
    } else {
      if (rtb_FrontmotorSaturation < heli_1_P.FrontmotorSaturation_LowerSat) {
        rtb_FrontmotorSaturation = heli_1_P.FrontmotorSaturation_LowerSat;
      }
    }

    /* End of Saturate: '<S3>/Front motor: Saturation' */

    /* Saturate: '<S3>/Back motor: Saturation' */
    if (rtb_BackmotorSaturation > heli_1_P.BackmotorSaturation_UpperSat) {
      rtb_BackmotorSaturation = heli_1_P.BackmotorSaturation_UpperSat;
    } else {
      if (rtb_BackmotorSaturation < heli_1_P.BackmotorSaturation_LowerSat) {
        rtb_BackmotorSaturation = heli_1_P.BackmotorSaturation_LowerSat;
      }
    }

    /* End of Saturate: '<S3>/Back motor: Saturation' */

    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: heli_1/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_1_DW.HILWriteAnalog_Buffer[0] = rtb_FrontmotorSaturation;
      heli_1_DW.HILWriteAnalog_Buffer[1] = rtb_BackmotorSaturation;
      result = hil_write_analog(heli_1_DW.HILInitialize_Card,
        heli_1_P.HILWriteAnalog_channels, 2, &heli_1_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
      }
    }
  }
}

/* Model update function for TID0 */
void heli_1_update0(void)              /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(heli_1_M)) {
    rt_ertODEUpdateContinuousStates(&heli_1_M->solverInfo);
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
  if (!(++heli_1_M->Timing.clockTick0)) {
    ++heli_1_M->Timing.clockTickH0;
  }

  heli_1_M->Timing.t[0] = rtsiGetSolverStopTime(&heli_1_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_1_M->Timing.clockTick1)) {
    ++heli_1_M->Timing.clockTickH1;
  }

  heli_1_M->Timing.t[1] = heli_1_M->Timing.clockTick1 *
    heli_1_M->Timing.stepSize1 + heli_1_M->Timing.clockTickH1 *
    heli_1_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_1_derivatives(void)
{
  XDot_heli_1_T *_rtXdot;
  _rtXdot = ((XDot_heli_1_T *) heli_1_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = heli_1_B.Integrator;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = heli_1_B.k_3;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = heli_1_B.Integrator2;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = heli_1_B.k_1;

  /* Derivatives for Integrator: '<S1>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = heli_1_B.Integrator4;

  /* Derivatives for Integrator: '<S1>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = heli_1_B.k_2;

  /* Derivatives for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_1_P.TravelTransferFcn_A *
    heli_1_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_1_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_1_P.PitchTransferFcn_A *
    heli_1_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_1_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_1_P.ElevationTransferFcn_A *
    heli_1_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_1_B.ElevationCounttorad;
}

/* Model output function for TID2 */
void heli_1_output2(void)              /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: heli_1/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_1_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_1_DW.GameController_Controller, &state,
        &new_data);
      if (result == 0) {
        heli_1_B.GameController_o4 = state.x;
        heli_1_B.GameController_o5 = state.y;
      }
    } else {
      heli_1_B.GameController_o4 = 0;
      heli_1_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void heli_1_update2(void)              /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S4>/Rate Transition: y' */
  heli_1_DW.RateTransitiony_Buffer0 = heli_1_B.GameController_o5;

  /* Update for RateTransition: '<S4>/Rate Transition: x' */
  heli_1_DW.RateTransitionx_Buffer0 = heli_1_B.GameController_o4;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_1_M->Timing.clockTick2)) {
    ++heli_1_M->Timing.clockTickH2;
  }

  heli_1_M->Timing.t[2] = heli_1_M->Timing.clockTick2 *
    heli_1_M->Timing.stepSize2 + heli_1_M->Timing.clockTickH2 *
    heli_1_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_1_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_1_output0();
    break;

   case 2 :
    heli_1_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_1_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_1_update0();
    break;

   case 2 :
    heli_1_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_1_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_1/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_1_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_1_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_1_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_1_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_1_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_1_M, _rt_error_message);
      return;
    }

    if ((heli_1_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (heli_1_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_1_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = heli_1_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_1_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_1_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(heli_1_DW.HILInitialize_Card,
        heli_1_P.HILInitialize_analog_input_chan, 8U,
        &heli_1_DW.HILInitialize_AIMinimums[0],
        &heli_1_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
        return;
      }
    }

    if ((heli_1_P.HILInitialize_set_analog_output && !is_switching) ||
        (heli_1_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_1_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = heli_1_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_1_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_1_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(heli_1_DW.HILInitialize_Card,
        heli_1_P.HILInitialize_analog_output_cha, 8U,
        &heli_1_DW.HILInitialize_AOMinimums[0],
        &heli_1_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
        return;
      }
    }

    if ((heli_1_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (heli_1_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_1_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_1_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(heli_1_DW.HILInitialize_Card,
        heli_1_P.HILInitialize_analog_output_cha, 8U,
        &heli_1_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
        return;
      }
    }

    if (heli_1_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_1_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_1_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_1_DW.HILInitialize_Card, heli_1_P.HILInitialize_analog_output_cha,
         8U, &heli_1_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
        return;
      }
    }

    if ((heli_1_P.HILInitialize_set_encoder_param && !is_switching) ||
        (heli_1_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &heli_1_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_1_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(heli_1_DW.HILInitialize_Card,
        heli_1_P.HILInitialize_encoder_channels, 8U, (t_encoder_quadrature_mode *)
        &heli_1_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
        return;
      }
    }

    if ((heli_1_P.HILInitialize_set_encoder_count && !is_switching) ||
        (heli_1_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &heli_1_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = heli_1_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(heli_1_DW.HILInitialize_Card,
        heli_1_P.HILInitialize_encoder_channels, 8U,
        &heli_1_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
        return;
      }
    }

    if ((heli_1_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (heli_1_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_1_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_1_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(heli_1_DW.HILInitialize_Card,
        heli_1_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &heli_1_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          heli_1_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &heli_1_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            heli_1_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            heli_1_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              heli_1_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            heli_1_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            heli_1_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              heli_1_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_1_DW.HILInitialize_Card,
          &heli_1_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &heli_1_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_1_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_1_DW.HILInitialize_Card,
          &heli_1_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_1_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_1_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_1_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_1_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &heli_1_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_1_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &heli_1_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_1_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(heli_1_DW.HILInitialize_Card,
        heli_1_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &heli_1_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &heli_1_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_1_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &heli_1_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_1_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_1_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_1_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(heli_1_DW.HILInitialize_Card,
        heli_1_P.HILInitialize_pwm_channels, 8U,
        &heli_1_DW.HILInitialize_POSortedFreqs[0],
        &heli_1_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
        return;
      }
    }

    if ((heli_1_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (heli_1_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_1_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_1_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(heli_1_DW.HILInitialize_Card,
        heli_1_P.HILInitialize_pwm_channels, 8U,
        &heli_1_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
        return;
      }
    }

    if (heli_1_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_1_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_1_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_1_DW.HILInitialize_Card, heli_1_P.HILInitialize_pwm_channels, 8U,
         &heli_1_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_1/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_1_DW.HILInitialize_Card,
      heli_1_P.HILReadEncoderTimebase_samples_,
      heli_1_P.HILReadEncoderTimebase_channels, 3,
      &heli_1_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_1_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S4>/Rate Transition: y' */
  heli_1_B.RateTransitiony = heli_1_P.RateTransitiony_X0;

  /* Start for RateTransition: '<S4>/Rate Transition: x' */
  heli_1_B.RateTransitionx = heli_1_P.RateTransitionx_X0;

  /* Start for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: heli_1/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_1_P.GameController_Enabled) {
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

      result = game_controller_open(heli_1_P.GameController_ControllerNumber,
        heli_1_P.GameController_BufferSize, deadzone, saturation,
        heli_1_P.GameController_AutoCenter, 0, 1.0,
        &heli_1_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_1_M, _rt_error_message);
      }
    }
  }

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  heli_1_X.Integrator1_CSTATE = heli_1_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  heli_1_X.Integrator_CSTATE = heli_1_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  heli_1_X.Integrator3_CSTATE = heli_1_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  heli_1_X.Integrator2_CSTATE = heli_1_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator5' */
  heli_1_X.Integrator5_CSTATE = heli_1_P.Integrator5_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator4' */
  heli_1_X.Integrator4_CSTATE = heli_1_P.Integrator4_IC;

  /* InitializeConditions for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  heli_1_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  heli_1_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  heli_1_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for RateTransition: '<S4>/Rate Transition: y' */
  heli_1_DW.RateTransitiony_Buffer0 = heli_1_P.RateTransitiony_X0;

  /* InitializeConditions for RateTransition: '<S4>/Rate Transition: x' */
  heli_1_DW.RateTransitionx_Buffer0 = heli_1_P.RateTransitionx_X0;
}

/* Model terminate function */
void heli_1_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_1/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_1_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_1_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_1_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (heli_1_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_1_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_1_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((heli_1_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (heli_1_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_1_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_1_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_1_DW.HILInitialize_Card
                         , heli_1_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , heli_1_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_1_DW.HILInitialize_AOVoltages[0]
                         , &heli_1_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_1_DW.HILInitialize_Card,
            heli_1_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
            &heli_1_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_1_DW.HILInitialize_Card,
            heli_1_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &heli_1_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_1_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_1_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_1_DW.HILInitialize_Card);
    hil_close(heli_1_DW.HILInitialize_Card);
    heli_1_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: heli_1/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_1_P.GameController_Enabled) {
      game_controller_close(heli_1_DW.GameController_Controller);
      heli_1_DW.GameController_Controller = NULL;
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
  heli_1_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_1_update(tid);
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
  heli_1_initialize();
}

void MdlTerminate(void)
{
  heli_1_terminate();
}

/* Registration function */
RT_MODEL_heli_1_T *heli_1(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)heli_1_M, 0,
                sizeof(RT_MODEL_heli_1_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_1_M->solverInfo, &heli_1_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_1_M->solverInfo, &rtmGetTPtr(heli_1_M));
    rtsiSetStepSizePtr(&heli_1_M->solverInfo, &heli_1_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_1_M->solverInfo, &heli_1_M->ModelData.derivs);
    rtsiSetContStatesPtr(&heli_1_M->solverInfo, (real_T **)
                         &heli_1_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&heli_1_M->solverInfo,
      &heli_1_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_1_M->solverInfo,
      &heli_1_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_1_M->solverInfo,
      &heli_1_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_1_M->solverInfo,
      &heli_1_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_1_M->solverInfo, (&rtmGetErrorStatus(heli_1_M)));
    rtsiSetRTModelPtr(&heli_1_M->solverInfo, heli_1_M);
  }

  rtsiSetSimTimeStep(&heli_1_M->solverInfo, MAJOR_TIME_STEP);
  heli_1_M->ModelData.intgData.f[0] = heli_1_M->ModelData.odeF[0];
  heli_1_M->ModelData.contStates = ((real_T *) &heli_1_X);
  rtsiSetSolverData(&heli_1_M->solverInfo, (void *)&heli_1_M->ModelData.intgData);
  rtsiSetSolverName(&heli_1_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_1_M->Timing.sampleTimes = (&heli_1_M->Timing.sampleTimesArray[0]);
    heli_1_M->Timing.offsetTimes = (&heli_1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_1_M->Timing.sampleTimes[0] = (0.0);
    heli_1_M->Timing.sampleTimes[1] = (0.002);
    heli_1_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_1_M->Timing.offsetTimes[0] = (0.0);
    heli_1_M->Timing.offsetTimes[1] = (0.0);
    heli_1_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_1_M, &heli_1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_1_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = heli_1_M->Timing.perTaskSampleHitsArray;
    heli_1_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_1_M, -1);
  heli_1_M->Timing.stepSize0 = 0.002;
  heli_1_M->Timing.stepSize1 = 0.002;
  heli_1_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_1_M->Sizes.checksums[0] = (590092459U);
  heli_1_M->Sizes.checksums[1] = (1061258927U);
  heli_1_M->Sizes.checksums[2] = (1082558458U);
  heli_1_M->Sizes.checksums[3] = (3781221635U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    heli_1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(heli_1_M->extModeInfo,
      &heli_1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_1_M->extModeInfo, heli_1_M->Sizes.checksums);
    rteiSetTPtr(heli_1_M->extModeInfo, rtmGetTPtr(heli_1_M));
  }

  heli_1_M->solverInfoPtr = (&heli_1_M->solverInfo);
  heli_1_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_1_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_1_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_1_M->ModelData.blockIO = ((void *) &heli_1_B);

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      heli_1_B.Sum1[i] = 0.0;
    }

    heli_1_B.Integrator1 = 0.0;
    heli_1_B.Integrator = 0.0;
    heli_1_B.Integrator3 = 0.0;
    heli_1_B.Integrator2 = 0.0;
    heli_1_B.Integrator5 = 0.0;
    heli_1_B.Integrator4 = 0.0;
    heli_1_B.TravelCounttorad = 0.0;
    heli_1_B.TravelTransferFcn = 0.0;
    heli_1_B.PitchCounttorad = 0.0;
    heli_1_B.PitchTransferFcn = 0.0;
    heli_1_B.ElevationCounttorad = 0.0;
    heli_1_B.Sum = 0.0;
    heli_1_B.ElevationTransferFcn = 0.0;
    heli_1_B.RateTransitiony = 0.0;
    heli_1_B.Joystick_gain_y = 0.0;
    heli_1_B.Sum_o = 0.0;
    heli_1_B.RateTransitionx = 0.0;
    heli_1_B.Joystick_gain_x = 0.0;
    heli_1_B.k_1 = 0.0;
    heli_1_B.k_2 = 0.0;
    heli_1_B.k_3 = 0.0;
    heli_1_B.GameController_o4 = 0.0;
    heli_1_B.GameController_o5 = 0.0;
  }

  /* parameters */
  heli_1_M->ModelData.defaultParam = ((real_T *)&heli_1_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_1_X;
    heli_1_M->ModelData.contStates = (x);
    (void) memset((void *)&heli_1_X, 0,
                  sizeof(X_heli_1_T));
  }

  /* states (dwork) */
  heli_1_M->ModelData.dwork = ((void *) &heli_1_DW);
  (void) memset((void *)&heli_1_DW, 0,
                sizeof(DW_heli_1_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_1_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_1_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_1_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_1_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_1_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_1_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_1_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_1_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_1_DW.RateTransitiony_Buffer0 = 0.0;
  heli_1_DW.RateTransitionx_Buffer0 = 0.0;
  heli_1_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_1_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_1_M->Sizes.numContStates = (9); /* Number of continuous states */
  heli_1_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  heli_1_M->Sizes.numY = (0);          /* Number of model outputs */
  heli_1_M->Sizes.numU = (0);          /* Number of model inputs */
  heli_1_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_1_M->Sizes.numSampTimes = (3);  /* Number of sample times */
  heli_1_M->Sizes.numBlocks = (53);    /* Number of blocks */
  heli_1_M->Sizes.numBlockIO = (24);   /* Number of block outputs */
  heli_1_M->Sizes.numBlockPrms = (147);/* Sum of parameter "widths" */
  return heli_1_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
